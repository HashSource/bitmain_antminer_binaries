
undefined1 *
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
  undefined3 *__src;
  undefined1 *puVar10;
  cert_st *pcVar11;
  int iVar12;
  uchar *puVar13;
  int iVar14;
  uint uVar15;
  SSL_SESSION *pSVar16;
  SSL *pSVar17;
  ushort *__n;
  SSL *pSVar18;
  SSL_SESSION *pSVar19;
  bool bVar20;
  uchar *local_30;
  int local_2c [2];
  
  local_30 = param_2;
  if ((param_1->version < 0x301) && (-1 < *(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c)) {
LAB_000710fe:
    iVar12 = param_1->first_packet;
    bVar20 = false;
    puVar13 = local_30;
  }
  else {
    p_Var3 = &SSL_get_ciphers(param_1)->stack;
    iVar12 = 0;
    do {
      iVar14 = sk_num(p_Var3);
      if (iVar14 <= iVar12) goto LAB_000710fe;
      pvVar5 = sk_value(p_Var3,iVar12);
    } while (((*(uint *)((int)pvVar5 + 0xc) & 0xe0) == 0) &&
            (iVar12 = iVar12 + 1, -1 < *(int *)((int)pvVar5 + 0x10) << 0x19));
    iVar12 = param_1->first_packet;
    bVar20 = true;
    puVar13 = local_30;
  }
  if ((iVar12 == 0x300) && (param_1->s3->send_connection_binding == 0)) {
    return param_2;
  }
  local_30 = puVar13 + 2;
  if (param_3 <= local_30) {
    return (undefined1 *)0x0;
  }
  if ((char *)param_1->tlsext_debug_arg != (char *)0x0) {
    iVar12 = -9 - (int)local_30;
    if ((int)(param_3 + iVar12) < 0) {
      return (undefined1 *)0x0;
    }
    puVar1 = (uchar *)strlen((char *)param_1->tlsext_debug_arg);
    if (param_3 + iVar12 < puVar1) {
      return (undefined1 *)0x0;
    }
    puVar13[2] = '\0';
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
    puVar13 = local_30;
    if (param_1[1].rbio != (BIO *)0x0) {
      sVar2 = strlen((char *)param_1[1].rbio);
      if (sVar2 == 0 || 0xff < (int)sVar2) {
        iVar14 = 0x52e;
        goto LAB_00071310;
      }
      if ((int)(param_3 + (-sVar2 - (int)puVar13) + -5) < 0) {
        return (undefined1 *)0x0;
      }
      *puVar13 = '\0';
      local_30[1] = '\f';
      local_30[2] = (uchar)(sVar2 + 1 >> 8);
      local_30[3] = (uchar)sVar2 + '\x01';
      puVar13 = local_30 + 5;
      local_30[4] = (uchar)sVar2;
      local_30 = puVar13;
      memcpy(puVar13,param_1[1].rbio,sVar2);
      local_30 = local_30 + sVar2;
    }
    if (bVar20) {
      __src = (undefined3 *)param_1->tlsext_ecpointformatlist_length;
      if (__src == (undefined3 *)0x0) {
        __src = &ecformats_default;
        if ((*(uint *)(param_1->cert + 0x38) & 0x30000) == 0) {
          puVar13 = (uchar *)0x3;
        }
        else {
          puVar13 = (uchar *)0x2;
        }
      }
      else {
        puVar13 = (uchar *)param_1->tlsext_ticket_expected;
      }
      if ((int)(param_3 + (-5 - (int)local_30)) < 0) {
        return (undefined1 *)0x0;
      }
      if (param_3 + (-5 - (int)local_30) < puVar13) {
        return (undefined1 *)0x0;
      }
      if ((uchar *)0xff < puVar13) {
        iVar14 = 0x554;
        goto LAB_00071310;
      }
      *local_30 = '\0';
      local_30[1] = '\v';
      local_30[2] = (uchar)((uint)(puVar13 + 1) >> 8);
      local_30[3] = (uchar)puVar13 + '\x01';
      puVar1 = local_30 + 5;
      local_30[4] = (uchar)puVar13;
      local_30 = puVar1;
      memcpy(puVar1,__src,(size_t)puVar13);
      local_30 = local_30 + (int)puVar13;
      uVar15 = *(uint *)(param_1->cert + 0x38) & 0x30000;
      if (uVar15 == 0x20000) {
        puVar10 = (undefined1 *)((int)&suiteb_curves + 2);
        puVar13 = (uchar *)0x2;
LAB_00071334:
        if ((int)puVar13 << 0x1f < 0) {
          ERR_put_error(0x14,0x152,0x44,"t1_lib.c",0x200);
          return (undefined1 *)0x0;
        }
        uVar15 = (uint)puVar13 >> 1;
      }
      else {
        if (uVar15 == 0x30000) {
          puVar10 = (undefined1 *)&suiteb_curves;
          puVar13 = (uchar *)0x4;
          goto LAB_00071334;
        }
        if (uVar15 == 0x10000) {
          puVar10 = (undefined1 *)&suiteb_curves;
          puVar13 = (uchar *)0x2;
          goto LAB_00071334;
        }
        puVar10 = (undefined1 *)param_1->tlsext_ellipticcurvelist_length;
        puVar13 = param_1->tlsext_ecpointformatlist;
        if ((undefined4 *)puVar10 != (undefined4 *)0x0) goto LAB_00071334;
        if ((param_1->server == 0) || (*(int *)(param_1->cert + 0x34) != 0)) {
          uVar15 = 0xd;
          puVar10 = eccurves_auto;
        }
        else {
          uVar15 = 0x1c;
          puVar10 = eccurves_all;
        }
      }
      if ((int)(param_3 + (-6 - (int)local_30)) < 0) {
        return (undefined1 *)0x0;
      }
      if ((uint)(param_3 + (-6 - (int)local_30)) >> 1 < uVar15) {
        return (undefined1 *)0x0;
      }
      if (0x7ffe < uVar15) {
        iVar14 = 0x56b;
        goto LAB_00071310;
      }
      *local_30 = '\0';
      sVar2 = uVar15 * 2;
      local_30[1] = '\n';
      local_30[2] = (uchar)(sVar2 + 2 >> 8);
      local_30[3] = (uchar)sVar2 + '\x02';
      local_30[4] = (uchar)(sVar2 >> 8);
      local_30[5] = (uchar)sVar2;
      local_30 = local_30 + 6;
      memcpy(local_30,puVar10,sVar2);
      local_30 = local_30 + sVar2;
    }
    lVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if (-1 < lVar4 << 0x11) {
      pSVar19 = param_1->session;
      if (param_1->new_session == 0) {
        if (pSVar19 == (SSL_SESSION *)0x0) {
LAB_000718bc:
          __n = (ushort *)param_1->tlsext_opaque_prf_input_len;
          if (__n != (ushort *)0x0) {
            if (*(int *)(__n + 2) == 0) goto LAB_00071450;
            __n = (ushort *)0x0;
          }
        }
        else {
          if (*(int *)(pSVar19->krb5_client_princ + 0x54) == 0) goto LAB_000713ce;
          __n = *(ushort **)(pSVar19->krb5_client_princ + 0x58);
LAB_0007140c:
          if (__n == (ushort *)0x0) goto LAB_000718bc;
        }
LAB_00071412:
        if ((int)(param_3 + (-(int)__n - (int)local_30) + -4) < 0) {
          return (undefined1 *)0x0;
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
        if (pSVar19 == (SSL_SESSION *)0x0) goto LAB_000718bc;
LAB_000713ce:
        __n = (ushort *)param_1->tlsext_opaque_prf_input_len;
        if (__n == (ushort *)0x0) goto LAB_00071412;
        if (*(int *)(__n + 2) != 0) {
          __n = (ushort *)(uint)*__n;
          pvVar5 = CRYPTO_malloc((int)__n,"t1_lib.c",0x57e);
          pSVar16 = param_1->session;
          *(void **)(pSVar19->krb5_client_princ + 0x54) = pvVar5;
          pvVar5 = *(void **)(pSVar16->krb5_client_princ + 0x54);
          if (pvVar5 == (void *)0x0) {
            return (undefined1 *)0x0;
          }
          memcpy(pvVar5,*(void **)(param_1->tlsext_opaque_prf_input_len + 4),(size_t)__n);
          *(ushort **)(param_1->session->krb5_client_princ + 0x58) = __n;
          goto LAB_0007140c;
        }
      }
    }
LAB_00071450:
    if (*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1e < 0) {
      pcVar11 = param_1->cert;
      uVar15 = *(uint *)(pcVar11 + 0x38) & 0x30000;
      if (uVar15 == 0x20000) {
        uVar15 = 8;
        puVar10 = (undefined1 *)((int)&suiteb_sigalgs + 2);
        sVar2 = 2;
      }
      else if (uVar15 == 0x30000) {
        uVar15 = 10;
        puVar10 = (undefined1 *)&suiteb_sigalgs;
        sVar2 = 4;
      }
      else if (uVar15 == 0x10000) {
        uVar15 = 8;
        puVar10 = (undefined1 *)&suiteb_sigalgs;
        sVar2 = 2;
      }
      else if ((param_1->server == 0) ||
              (puVar10 = *(undefined1 **)(pcVar11 + 0x134),
              (undefined4 *)puVar10 == (undefined4 *)0x0)) {
        puVar10 = *(undefined1 **)(pcVar11 + 300);
        if ((undefined4 *)puVar10 == (undefined4 *)0x0) {
          puVar10 = tls12_sigalgs;
          uVar15 = 0x24;
          sVar2 = 0x1e;
        }
        else {
          sVar2 = *(size_t *)(pcVar11 + 0x130);
          uVar15 = sVar2 + 6;
        }
      }
      else {
        sVar2 = *(size_t *)(pcVar11 + 0x138);
        uVar15 = sVar2 + 6;
      }
      if ((uint)((int)param_3 - (int)local_30) < uVar15) {
        return (undefined1 *)0x0;
      }
      *local_30 = '\0';
      local_30[1] = '\r';
      local_30[2] = (uchar)(sVar2 + 2 >> 8);
      local_30[3] = (uchar)sVar2 + '\x02';
      local_30[4] = (uchar)(sVar2 >> 8);
      local_30[5] = (uchar)sVar2;
      local_30 = local_30 + 6;
      memcpy(local_30,puVar10,sVar2);
      local_30 = local_30 + sVar2;
    }
    if (param_1->servername_done == 1) {
      iVar14 = 0;
      iVar12 = 0;
      while( true ) {
        iVar7 = sk_num((_STACK *)param_1->tlsext_status_expected);
        if (iVar7 <= iVar12) break;
        pOVar8 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar12);
        iVar7 = i2d_OCSP_RESPID(pOVar8,(uchar **)0x0);
        iVar14 = iVar14 + iVar7 + 2;
        iVar12 = iVar12 + 1;
        if (iVar7 < 1) {
          return (undefined1 *)0x0;
        }
      }
      if ((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids == (X509_EXTENSIONS *)0x0) {
        iVar12 = 0;
      }
      else {
        iVar12 = i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,(uchar **)0x0);
        if (iVar12 < 0) {
          return (undefined1 *)0x0;
        }
      }
      if ((int)(param_3 + (((-7 - (int)local_30) - iVar12) - iVar14)) < 0) {
        return (undefined1 *)0x0;
      }
      *local_30 = '\0';
      local_30[1] = '\x05';
      if (0xfff0 < iVar12 + iVar14) {
        return (undefined1 *)0x0;
      }
      local_30[2] = (uchar)((uint)(iVar12 + iVar14 + 5) >> 8);
      local_30[3] = (uchar)iVar14 + '\x05' + (uchar)iVar12;
      local_30[4] = '\x01';
      local_30[5] = (uchar)((uint)iVar14 >> 8);
      local_30[6] = (uchar)iVar14;
      local_30 = local_30 + 7;
      iVar14 = 0;
      while( true ) {
        iVar7 = sk_num((_STACK *)param_1->tlsext_status_expected);
        puVar13 = local_30;
        if (iVar7 <= iVar14) break;
        pOVar8 = (OCSP_RESPID *)sk_value((_STACK *)param_1->tlsext_status_expected,iVar14);
        local_30 = local_30 + 2;
        iVar7 = i2d_OCSP_RESPID(pOVar8,&local_30);
        puVar13[1] = (uchar)iVar7;
        *puVar13 = (uchar)((uint)iVar7 >> 8);
        iVar14 = iVar14 + 1;
      }
      *local_30 = (uchar)((uint)iVar12 >> 8);
      local_30[1] = (uchar)iVar12;
      local_30 = local_30 + 2;
      if (iVar12 != 0) {
        i2d_X509_EXTENSIONS((X509_EXTENSIONS *)param_1->tlsext_ocsp_ids,&local_30);
      }
    }
    if ((int)param_3 - (int)local_30 < 5) {
      return (undefined1 *)0x0;
    }
    *local_30 = '\0';
    uVar9 = '\x01';
    local_30[1] = '\x0f';
    local_30[2] = '\0';
    local_30[3] = '\x01';
    if ((int)param_1->srtp_profile << 0x1d < 0) {
      uVar9 = '\x02';
    }
    puVar13 = local_30 + 5;
    local_30[4] = uVar9;
    if ((*(int *)(param_1->psk_server_callback + 0x1ac) != 0) &&
       ((param_1->s3->tmp).finish_md_len == 0)) {
      if ((int)param_3 - (int)puVar13 < 4) {
        return (undefined1 *)0x0;
      }
      *puVar13 = '3';
      local_30[6] = 't';
      local_30[7] = '\0';
      local_30[8] = '\0';
      puVar13 = local_30 + 9;
    }
    local_30 = puVar13;
    if ((param_1[1].init_buf != (BUF_MEM *)0x0) && ((param_1->s3->tmp).finish_md_len == 0)) {
      if ((uint)((int)param_3 - (int)local_30) < (int)param_1[1].init_msg + 6U) {
        return (undefined1 *)0x0;
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
        return (undefined1 *)0x0;
      }
      *local_30 = '\0';
      local_30[1] = '\x0e';
      local_30[2] = (uchar)((uint)local_2c[0] >> 8);
      local_30[3] = (uchar)local_2c[0];
      local_30 = local_30 + 4;
      iVar12 = ssl_add_clienthello_use_srtp_ext(param_1,local_30,local_2c,local_2c[0]);
      iVar14 = 0x614;
      if (iVar12 != 0) goto LAB_00071310;
      local_30 = local_30 + local_2c[0];
    }
    custom_ext_init(param_1->cert + 0x15c);
    iVar12 = custom_ext_add(param_1,0,&local_30,param_3,param_4);
    if (iVar12 != 0) {
      if (param_1->references << 0x1b < 0) {
        iVar12 = (int)local_30 - (int)param_1->init_buf->data;
        if (param_1->state == 0x1210) {
          iVar12 = iVar12 + -5;
        }
        if (iVar12 - 0x100U < 0x100) {
          iVar14 = -iVar12 + 0x200;
          *local_30 = '\0';
          bVar20 = -iVar12 + 0x1fd < 0;
          if (3 < iVar14) {
            param_1 = (SSL *)(0x1fc - iVar12);
          }
          if (iVar14 == 3 || bVar20 != SBORROW4(iVar14,3)) {
            pSVar17 = (SSL *)0x0;
            param_1 = pSVar17;
          }
          else {
            pSVar17 = (SSL *)((uint)((int)param_1 << 0x10) >> 0x18);
          }
          local_30[1] = '\x15';
          pSVar18 = param_1;
          if (iVar14 != 3 && bVar20 == SBORROW4(iVar14,3)) {
            pSVar18 = (SSL *)((uint)param_1 & 0xff);
          }
          local_30[2] = (uchar)pSVar17;
          local_30[3] = (uchar)pSVar18;
          puVar13 = local_30 + 4;
          local_30 = local_30 + 2;
          memset(puVar13,0,(size_t)param_1);
          local_30 = puVar13 + (int)param_1;
        }
      }
      puVar13 = local_30 + (-2 - (int)param_2);
      if (puVar13 != (uchar *)0x0) {
        param_2[1] = (uchar)puVar13;
        *param_2 = (uchar)((uint)puVar13 >> 8);
        return local_30;
      }
      return param_2;
    }
  }
  else {
    iVar12 = ssl_add_clienthello_renegotiate_ext(param_1,0,local_2c,0);
    iVar14 = 0x516;
    if (iVar12 != 0) {
      if ((int)(param_3 + (-local_2c[0] - (int)local_30) + -4) < 0) {
        return (undefined1 *)0x0;
      }
      *local_30 = 0xff;
      local_30[1] = '\x01';
      local_30[2] = (uchar)((uint)local_2c[0] >> 8);
      local_30[3] = (uchar)local_2c[0];
      local_30 = local_30 + 4;
      iVar12 = ssl_add_clienthello_renegotiate_ext(param_1,local_30,local_2c,local_2c[0]);
      iVar14 = 0x521;
      if (iVar12 != 0) {
        local_30 = local_30 + local_2c[0];
        goto LAB_000711be;
      }
    }
LAB_00071310:
    ERR_put_error(0x14,0x115,0x44,"t1_lib.c",iVar14);
  }
  return (undefined1 *)0x0;
}

