
undefined *
ssl_add_clienthello_tlsext(SSL *param_1,uchar *param_2,uchar *param_3,undefined4 param_4)

{
  uchar *puVar1;
  size_t sVar2;
  _STACK *p_Var3;
  long lVar4;
  void *pvVar5;
  stack_st_SRTP_PROTECTION_PROFILE *psVar6;
  int iVar7;
  OCSP_RESPID *pOVar8;
  uchar uVar9;
  cert_st *pcVar10;
  int iVar11;
  uchar *puVar12;
  int iVar13;
  uint uVar14;
  SSL_SESSION *pSVar15;
  SSL *pSVar16;
  ushort *__n;
  SSL *pSVar17;
  SSL_SESSION *pSVar18;
  bool bVar19;
  uchar *local_30;
  int local_2c [2];
  
  local_30 = param_2;
  if ((param_1->version < 0x301) && (-1 < *(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c)) {
LAB_000710fe:
    iVar11 = param_1->first_packet;
    bVar19 = false;
    puVar12 = local_30;
  }
  else {
    p_Var3 = &SSL_get_ciphers(param_1)->stack;
    iVar11 = 0;
    do {
      iVar13 = sk_num(p_Var3);
      if (iVar13 <= iVar11) goto LAB_000710fe;
      pvVar5 = sk_value(p_Var3,iVar11);
    } while (((*(uint *)((int)pvVar5 + 0xc) & 0xe0) == 0) &&
            (iVar11 = iVar11 + 1, -1 < *(int *)((int)pvVar5 + 0x10) << 0x19));
    iVar11 = param_1->first_packet;
    bVar19 = true;
    puVar12 = local_30;
  }
  if ((iVar11 == 0x300) && (param_1->s3->send_connection_binding == 0)) {
    return param_2;
  }
  local_30 = puVar12 + 2;
  if (param_3 <= local_30) {
    return (undefined *)0x0;
  }
  if ((char *)param_1->tlsext_debug_arg != (char *)0x0) {
    iVar11 = -9 - (int)local_30;
    if ((int)(param_3 + iVar11) < 0) {
      return (undefined *)0x0;
    }
    puVar1 = (uchar *)strlen((char *)param_1->tlsext_debug_arg);
    if (param_3 + iVar11 < puVar1) {
      return (undefined *)0x0;
    }
    puVar12[2] = '\0';
    uVar9 = (uchar)puVar1;
    local_30[1] = '\0';
    local_30[2] = (uchar)((uint)(puVar1 + 5) >> 8);
    local_30[3] = uVar9 + '\x05';
    local_30[4] = (uchar)((uint)(puVar1 + 3) >> 8);
    local_30[5] = uVar9 + '\x03';
    local_30[6] = '\0';
    local_30[7] = (uchar)((uint)puVar1 >> 8);
    local_30[8] = uVar9;
    local_30 = local_30 + 9;
    memcpy(local_30,param_1->tlsext_debug_arg,(size_t)puVar1);
    local_30 = local_30 + (int)puVar1;
  }
  if (param_1->tlsext_hb_seq == 0) {
LAB_000711be:
    puVar12 = local_30;
    if (param_1[1].rbio != (BIO *)0x0) {
      sVar2 = strlen((char *)param_1[1].rbio);
      if (sVar2 == 0 || 0xff < (int)sVar2) {
        iVar13 = 0x52e;
        goto LAB_00071310;
      }
      if ((int)(param_3 + (-sVar2 - (int)puVar12) + -5) < 0) {
        return (undefined *)0x0;
      }
      *puVar12 = '\0';
      local_30[1] = '\f';
      local_30[2] = (uchar)(sVar2 + 1 >> 8);
      local_30[3] = (uchar)sVar2 + '\x01';
      puVar12 = local_30 + 5;
      local_30[4] = (uchar)sVar2;
      local_30 = puVar12;
      memcpy(puVar12,param_1[1].rbio,sVar2);
      local_30 = local_30 + sVar2;
    }
    if (bVar19) {
      if ((void *)param_1->tlsext_ecpointformatlist_length == (void *)0x0) {
        pvVar5 = DAT_00071934;
        if ((*(uint *)(param_1->cert + 0x38) & 0x30000) == 0) {
          puVar12 = (uchar *)0x3;
        }
        else {
          puVar12 = (uchar *)0x2;
        }
      }
      else {
        puVar12 = (uchar *)param_1->tlsext_ticket_expected;
        pvVar5 = (void *)param_1->tlsext_ecpointformatlist_length;
      }
      if ((int)(param_3 + (-5 - (int)local_30)) < 0) {
        return (undefined *)0x0;
      }
      if (param_3 + (-5 - (int)local_30) < puVar12) {
        return (undefined *)0x0;
      }
      if ((uchar *)0xff < puVar12) {
        iVar13 = 0x554;
        goto LAB_00071310;
      }
      *local_30 = '\0';
      local_30[1] = '\v';
      local_30[2] = (uchar)((uint)(puVar12 + 1) >> 8);
      local_30[3] = (uchar)puVar12 + '\x01';
      puVar1 = local_30 + 5;
      local_30[4] = (uchar)puVar12;
      local_30 = puVar1;
      memcpy(puVar1,pvVar5,(size_t)puVar12);
      local_30 = local_30 + (int)puVar12;
      uVar14 = *(uint *)(param_1->cert + 0x38) & 0x30000;
      if (uVar14 == 0x20000) {
        puVar12 = (uchar *)0x2;
        pvVar5 = DAT_0007160c;
LAB_00071334:
        if ((int)puVar12 << 0x1f < 0) {
          ERR_put_error(0x14,0x152,0x44,DAT_00071940,0x200);
          return (undefined *)0x0;
        }
        uVar14 = (uint)puVar12 >> 1;
      }
      else {
        pvVar5 = DAT_00071938;
        if (uVar14 == 0x30000) {
          puVar12 = (uchar *)0x4;
          goto LAB_00071334;
        }
        if (uVar14 == 0x10000) {
          puVar12 = (uchar *)0x2;
          goto LAB_00071334;
        }
        puVar12 = param_1->tlsext_ecpointformatlist;
        pvVar5 = (void *)param_1->tlsext_ellipticcurvelist_length;
        if ((void *)param_1->tlsext_ellipticcurvelist_length != (void *)0x0) goto LAB_00071334;
        if ((param_1->server == 0) || (*(int *)(param_1->cert + 0x34) != 0)) {
          uVar14 = 0xd;
          pvVar5 = DAT_00071948;
        }
        else {
          uVar14 = 0x1c;
          pvVar5 = DAT_00071328;
        }
      }
      if ((int)(param_3 + (-6 - (int)local_30)) < 0) {
        return (undefined *)0x0;
      }
      if ((uint)(param_3 + (-6 - (int)local_30)) >> 1 < uVar14) {
        return (undefined *)0x0;
      }
      if (0x7ffe < uVar14) {
        iVar13 = 0x56b;
        goto LAB_00071310;
      }
      *local_30 = '\0';
      sVar2 = uVar14 * 2;
      local_30[1] = '\n';
      local_30[2] = (uchar)(sVar2 + 2 >> 8);
      local_30[3] = (uchar)sVar2 + '\x02';
      local_30[4] = (uchar)(sVar2 >> 8);
      local_30[5] = (uchar)sVar2;
      local_30 = local_30 + 6;
      memcpy(local_30,pvVar5,sVar2);
      local_30 = local_30 + sVar2;
    }
    lVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if (-1 < lVar4 << 0x11) {
      pSVar18 = param_1->session;
      if (param_1->new_session == 0) {
        if (pSVar18 == (SSL_SESSION *)0x0) {
LAB_000718bc:
          __n = (ushort *)param_1->tlsext_opaque_prf_input_len;
          if (__n != (ushort *)0x0) {
            if (*(int *)(__n + 2) == 0) goto LAB_00071450;
            __n = (ushort *)0x0;
          }
        }
        else {
          if (*(int *)(pSVar18->krb5_client_princ + 0x54) == 0) goto LAB_000713ce;
          __n = *(ushort **)(pSVar18->krb5_client_princ + 0x58);
LAB_0007140c:
          if (__n == (ushort *)0x0) goto LAB_000718bc;
        }
LAB_00071412:
        if ((int)(param_3 + (-(int)__n - (int)local_30) + -4) < 0) {
          return (undefined *)0x0;
        }
        *local_30 = '\0';
        local_30[1] = '#';
        local_30[2] = (uchar)((uint)__n >> 8);
        local_30[3] = (uchar)__n;
        local_30 = local_30 + 4;
        if (__n != (ushort *)0x0) {
          memcpy(local_30,*(void **)(param_1->session->krb5_client_princ + 0x54),(size_t)__n);
          local_30 = local_30 + (int)__n;
        }
      }
      else {
        if (pSVar18 == (SSL_SESSION *)0x0) goto LAB_000718bc;
LAB_000713ce:
        __n = (ushort *)param_1->tlsext_opaque_prf_input_len;
        if (__n == (ushort *)0x0) goto LAB_00071412;
        if (*(int *)(__n + 2) != 0) {
          __n = (ushort *)(uint)*__n;
          pvVar5 = CRYPTO_malloc((int)__n,DAT_00071610,0x57e);
          pSVar15 = param_1->session;
          *(void **)(pSVar18->krb5_client_princ + 0x54) = pvVar5;
          pvVar5 = *(void **)(pSVar15->krb5_client_princ + 0x54);
          if (pvVar5 == (void *)0x0) {
            return (undefined *)0x0;
          }
          memcpy(pvVar5,*(void **)(param_1->tlsext_opaque_prf_input_len + 4),(size_t)__n);
          *(ushort **)(param_1->session->krb5_client_princ + 0x58) = __n;
          goto LAB_0007140c;
        }
      }
    }
LAB_00071450:
    if (*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1e < 0) {
      pcVar10 = param_1->cert;
      uVar14 = *(uint *)(pcVar10 + 0x38) & 0x30000;
      if (uVar14 == 0x20000) {
        uVar14 = 8;
        sVar2 = 2;
        pvVar5 = DAT_00071944;
      }
      else {
        pvVar5 = DAT_0007193c;
        if (uVar14 == 0x30000) {
          uVar14 = 10;
          sVar2 = 4;
        }
        else if (uVar14 == 0x10000) {
          uVar14 = 8;
          sVar2 = 2;
        }
        else if ((param_1->server == 0) || (*(void **)(pcVar10 + 0x134) == (void *)0x0)) {
          if (*(void **)(pcVar10 + 300) == (void *)0x0) {
            uVar14 = 0x24;
            sVar2 = 0x1e;
            pvVar5 = DAT_0007194c;
          }
          else {
            sVar2 = *(size_t *)(pcVar10 + 0x130);
            uVar14 = sVar2 + 6;
            pvVar5 = *(void **)(pcVar10 + 300);
          }
        }
        else {
          sVar2 = *(size_t *)(pcVar10 + 0x138);
          uVar14 = sVar2 + 6;
          pvVar5 = *(void **)(pcVar10 + 0x134);
        }
      }
      if ((uint)((int)param_3 - (int)local_30) < uVar14) {
        return (undefined *)0x0;
      }
      *local_30 = '\0';
      local_30[1] = '\r';
      local_30[2] = (uchar)(sVar2 + 2 >> 8);
      local_30[3] = (uchar)sVar2 + '\x02';
      local_30[4] = (uchar)(sVar2 >> 8);
      local_30[5] = (uchar)sVar2;
      local_30 = local_30 + 6;
      memcpy(local_30,pvVar5,sVar2);
      local_30 = local_30 + sVar2;
    }
    if (param_1->servername_done == 1) {
      iVar13 = 0;
      iVar11 = 0;
      while( true ) {
        iVar7 = sk_num((_STACK *)param_1->tlsext_status_expected);
        if (iVar7 <= iVar11) break;
        pOVar8 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar11);
        iVar7 = i2d_OCSP_RESPID(pOVar8,(uchar **)0x0);
        iVar13 = iVar13 + iVar7 + 2;
        iVar11 = iVar11 + 1;
        if (iVar7 < 1) {
          return (undefined *)0x0;
        }
      }
      if ((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids == (X509_EXTENSIONS *)0x0) {
        iVar11 = 0;
      }
      else {
        iVar11 = i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,(uchar **)0x0);
        if (iVar11 < 0) {
          return (undefined *)0x0;
        }
      }
      if ((int)(param_3 + (((-7 - (int)local_30) - iVar11) - iVar13)) < 0) {
        return (undefined *)0x0;
      }
      *local_30 = '\0';
      local_30[1] = '\x05';
      if (0xfff0 < iVar11 + iVar13) {
        return (undefined *)0x0;
      }
      local_30[2] = (uchar)((uint)(iVar11 + iVar13 + 5) >> 8);
      local_30[3] = (uchar)iVar13 + '\x05' + (uchar)iVar11;
      local_30[4] = '\x01';
      local_30[5] = (uchar)((uint)iVar13 >> 8);
      local_30[6] = (uchar)iVar13;
      local_30 = local_30 + 7;
      iVar13 = 0;
      while( true ) {
        iVar7 = sk_num((_STACK *)param_1->tlsext_status_expected);
        puVar12 = local_30;
        if (iVar7 <= iVar13) break;
        pOVar8 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar13);
        local_30 = local_30 + 2;
        iVar7 = i2d_OCSP_RESPID(pOVar8,&local_30);
        puVar12[1] = (uchar)iVar7;
        *puVar12 = (uchar)((uint)iVar7 >> 8);
        iVar13 = iVar13 + 1;
      }
      *local_30 = (uchar)((uint)iVar11 >> 8);
      local_30[1] = (uchar)iVar11;
      local_30 = local_30 + 2;
      if (iVar11 != 0) {
        i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,&local_30);
      }
    }
    if ((int)param_3 - (int)local_30 < 5) {
      return (undefined *)0x0;
    }
    *local_30 = '\0';
    uVar9 = '\x01';
    local_30[1] = '\x0f';
    local_30[2] = '\0';
    local_30[3] = '\x01';
    if ((int)param_1->srtp_profile << 0x1d < 0) {
      uVar9 = '\x02';
    }
    puVar12 = local_30 + 5;
    local_30[4] = uVar9;
    if ((*(int *)(param_1->psk_server_callback + 0x1ac) != 0) &&
       ((param_1->s3->tmp).finish_md_len == 0)) {
      if ((int)param_3 - (int)puVar12 < 4) {
        return (undefined *)0x0;
      }
      *puVar12 = '3';
      local_30[6] = 't';
      local_30[7] = '\0';
      local_30[8] = '\0';
      puVar12 = local_30 + 9;
    }
    local_30 = puVar12;
    if ((param_1[1].init_buf != (BUF_MEM *)0x0) && ((param_1->s3->tmp).finish_md_len == 0)) {
      if ((uint)((int)param_3 - (int)local_30) < (int)param_1[1].init_msg + 6U) {
        return (undefined *)0x0;
      }
      *local_30 = '\0';
      local_30[1] = '\x10';
      local_30[2] = (uchar)((uint)((int)param_1[1].init_msg + 2) >> 8);
      local_30[3] = (char)param_1[1].init_msg + '\x02';
      local_30[4] = (uchar)((uint)param_1[1].init_msg >> 8);
      local_30[5] = (uchar)param_1[1].init_msg;
      local_30 = local_30 + 6;
      memcpy(local_30,param_1[1].init_buf,(size_t)param_1[1].init_msg);
      local_30 = local_30 + (int)param_1[1].init_msg;
    }
    if ((*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c < 0) &&
       (psVar6 = SSL_get_srtp_profiles(param_1), psVar6 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0))
    {
      ssl_add_clienthello_use_srtp_ext(param_1,0,local_2c,0);
      if ((int)(param_3 + (-local_2c[0] - (int)local_30) + -4) < 0) {
        return (undefined *)0x0;
      }
      *local_30 = '\0';
      local_30[1] = '\x0e';
      local_30[2] = (uchar)((uint)local_2c[0] >> 8);
      local_30[3] = (uchar)local_2c[0];
      local_30 = local_30 + 4;
      iVar11 = ssl_add_clienthello_use_srtp_ext(param_1,local_30,local_2c,local_2c[0]);
      iVar13 = 0x614;
      if (iVar11 != 0) goto LAB_00071310;
      local_30 = local_30 + local_2c[0];
    }
    custom_ext_init(param_1->cert + 0x15c);
    iVar11 = custom_ext_add(param_1,0,&local_30,param_3,param_4);
    if (iVar11 != 0) {
      if (param_1->references << 0x1b < 0) {
        iVar11 = (int)local_30 - (int)param_1->init_buf->data;
        if (param_1->state == 0x1210) {
          iVar11 = iVar11 + -5;
        }
        if (iVar11 - 0x100U < 0x100) {
          iVar13 = -iVar11 + 0x200;
          *local_30 = '\0';
          bVar19 = -iVar11 + 0x1fd < 0;
          if (3 < iVar13) {
            param_1 = (SSL *)(0x1fc - iVar11);
          }
          if (iVar13 == 3 || bVar19 != SBORROW4(iVar13,3)) {
            pSVar16 = (SSL *)0x0;
            param_1 = pSVar16;
          }
          else {
            pSVar16 = (SSL *)((uint)((int)param_1 << 0x10) >> 0x18);
          }
          local_30[1] = '\x15';
          pSVar17 = param_1;
          if (iVar13 != 3 && bVar19 == SBORROW4(iVar13,3)) {
            pSVar17 = (SSL *)((uint)param_1 & 0xff);
          }
          local_30[2] = (uchar)pSVar16;
          local_30[3] = (uchar)pSVar17;
          puVar12 = local_30 + 4;
          local_30 = local_30 + 2;
          memset(puVar12,0,(size_t)param_1);
          local_30 = puVar12 + (int)param_1;
        }
      }
      puVar12 = local_30 + (-2 - (int)param_2);
      if (puVar12 != (uchar *)0x0) {
        param_2[1] = (uchar)puVar12;
        *param_2 = (uchar)((uint)puVar12 >> 8);
        return local_30;
      }
      return param_2;
    }
  }
  else {
    iVar11 = ssl_add_clienthello_renegotiate_ext(param_1,0,local_2c,0);
    iVar13 = 0x516;
    if (iVar11 != 0) {
      if ((int)(param_3 + (-local_2c[0] - (int)local_30) + -4) < 0) {
        return (undefined *)0x0;
      }
      *local_30 = 0xff;
      local_30[1] = '\x01';
      local_30[2] = (uchar)((uint)local_2c[0] >> 8);
      local_30[3] = (uchar)local_2c[0];
      local_30 = local_30 + 4;
      iVar11 = ssl_add_clienthello_renegotiate_ext(param_1,local_30,local_2c,local_2c[0]);
      iVar13 = 0x521;
      if (iVar11 != 0) {
        local_30 = local_30 + local_2c[0];
        goto LAB_000711be;
      }
    }
LAB_00071310:
    ERR_put_error(0x14,0x115,0x44,DAT_0007132c,iVar13);
  }
  return (undefined *)0x0;
}

