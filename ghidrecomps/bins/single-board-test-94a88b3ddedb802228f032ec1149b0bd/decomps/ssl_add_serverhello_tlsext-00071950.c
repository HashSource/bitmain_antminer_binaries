
undefined4 *
ssl_add_serverhello_tlsext(SSL *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  undefined uVar5;
  ssl3_state_st *psVar6;
  void *pvVar7;
  undefined4 uVar8;
  SSL_CIPHER *pSVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int line;
  undefined *puVar13;
  undefined *puVar14;
  undefined4 uVar15;
  size_t __n;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  code *pcVar19;
  undefined4 *puVar20;
  undefined4 *local_50;
  void *local_4c;
  size_t local_48;
  undefined4 local_44 [8];
  undefined4 uStack_24;
  
  psVar6 = param_1->s3;
  pSVar9 = (psVar6->tmp).new_cipher;
  if (((pSVar9->algorithm_mkey & 0xe0) == 0) && ((pSVar9->algorithm_auth & 0x40) == 0)) {
    iVar10 = param_1->version;
    iVar12 = 0;
  }
  else {
    iVar10 = param_1->version;
    iVar12 = *(int *)(param_1->session->krb5_client_princ + 0x48);
    if (iVar12 != 0) {
      iVar12 = 1;
    }
  }
  if ((iVar10 == 0x300) && (psVar6->send_connection_binding == 0)) {
    return param_2;
  }
  local_50 = (undefined4 *)((int)param_2 + 2);
  if (param_3 <= local_50) {
    return (undefined4 *)0x0;
  }
  if (((param_1->hit == 0) && (param_1->tlsext_hostname == (char *)0x1)) &&
     (*(int *)(param_1->session->krb5_client_princ + 0x40) != 0)) {
    if ((int)param_3 - (int)local_50 < 4) {
      return (undefined4 *)0x0;
    }
    local_50 = (undefined4 *)((int)param_2 + 6);
    *(undefined *)((int)param_2 + 2) = 0;
    *(undefined *)((int)param_2 + 3) = 0;
    *(undefined *)(param_2 + 1) = 0;
    *(undefined *)((int)param_2 + 5) = 0;
    psVar6 = param_1->s3;
  }
  if (psVar6->send_connection_binding == 0) {
joined_r0x00071c54:
    if (iVar12 == 0) {
      iVar12 = param_1->tlsext_ocsp_resplen;
    }
    else {
      if ((void *)param_1->tlsext_ecpointformatlist_length == (void *)0x0) {
        pvVar7 = DAT_00071e00;
        if ((*(uint *)(param_1->cert + 0x38) & 0x30000) == 0) {
          puVar13 = (undefined *)0x3;
        }
        else {
          puVar13 = (undefined *)0x2;
        }
      }
      else {
        puVar13 = (undefined *)param_1->tlsext_ticket_expected;
        pvVar7 = (void *)param_1->tlsext_ecpointformatlist_length;
      }
      puVar14 = (undefined *)((int)param_3 + (-5 - (int)local_50));
      if ((int)puVar14 < 0) {
        return (undefined4 *)0x0;
      }
      if (puVar14 < puVar13) {
        return (undefined4 *)0x0;
      }
      if ((undefined *)0xff < puVar13) {
        ERR_put_error(0x14,0x116,0x44,DAT_00071dfc,0x68b);
        return (undefined4 *)0x0;
      }
      *(undefined *)local_50 = 0;
      *(undefined *)((int)local_50 + 1) = 0xb;
      *(char *)((int)local_50 + 2) = (char)((uint)(puVar13 + 1) >> 8);
      *(char *)((int)local_50 + 3) = (char)puVar13 + '\x01';
      puVar16 = (undefined4 *)((int)local_50 + 5);
      *(char *)(local_50 + 1) = (char)puVar13;
      local_50 = puVar16;
      memcpy(puVar16,pvVar7,(size_t)puVar13);
      local_50 = (undefined4 *)((int)local_50 + (int)puVar13);
      iVar12 = param_1->tlsext_ocsp_resplen;
    }
    if ((iVar12 != 0) && (uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar2 & 0x4000) == 0)) {
      if ((int)param_3 - (int)local_50 < 4) {
        return (undefined4 *)0x0;
      }
      *(undefined *)local_50 = 0;
      *(undefined *)((int)local_50 + 1) = 0x23;
      *(undefined *)((int)local_50 + 2) = 0;
      *(undefined *)((int)local_50 + 3) = 0;
      local_50 = local_50 + 1;
    }
    if (param_1->tlsext_status_type != 0) {
      if ((int)param_3 - (int)local_50 < 4) {
        return (undefined4 *)0x0;
      }
      *(undefined *)local_50 = 0;
      *(undefined *)((int)local_50 + 1) = 5;
      *(undefined *)((int)local_50 + 2) = 0;
      *(undefined *)((int)local_50 + 3) = 0;
      local_50 = local_50 + 1;
    }
    if ((*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c < 0) &&
       (param_1->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
      ssl_add_serverhello_use_srtp_ext(param_1,0,&local_48,0);
      if ((int)((int)param_3 + (-local_48 - (int)local_50) + -4) < 0) {
        return (undefined4 *)0x0;
      }
      *(undefined *)local_50 = 0;
      *(undefined *)((int)local_50 + 1) = 0xe;
      *(char *)((int)local_50 + 2) = (char)(local_48 >> 8);
      *(char *)((int)local_50 + 3) = (char)local_48;
      local_50 = local_50 + 1;
      iVar12 = ssl_add_serverhello_use_srtp_ext(param_1,local_50,&local_48,local_48);
      line = 0x6c7;
      if (iVar12 != 0) goto LAB_00071d06;
      local_50 = (undefined4 *)((int)local_50 + local_48);
    }
    if ((*(ushort *)&((param_1->s3->tmp).new_cipher)->id - 0x80 < 2) &&
       (lVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar3 < 0)) {
      puVar16 = local_44;
      puVar18 = DAT_00071e04;
      do {
        uVar4 = *puVar18;
        uVar8 = puVar18[1];
        puVar17 = puVar16 + 4;
        uVar11 = puVar18[2];
        uVar15 = puVar18[3];
        puVar18 = puVar18 + 4;
        *puVar16 = uVar4;
        puVar16[1] = uVar8;
        puVar16[2] = uVar11;
        puVar16[3] = uVar15;
        puVar16 = puVar17;
      } while (puVar18 != DAT_00071e04 + 8);
      *puVar17 = *puVar18;
      if ((int)param_3 - (int)local_50 < 0x24) {
        return (undefined4 *)0x0;
      }
      puVar16 = local_50;
      puVar18 = local_44;
      do {
        puVar17 = puVar18 + 4;
        uVar4 = puVar18[1];
        uVar8 = puVar18[2];
        uVar11 = puVar18[3];
        puVar20 = puVar18 + 4;
        *puVar16 = *puVar18;
        puVar16[1] = uVar4;
        puVar16[2] = uVar8;
        puVar16[3] = uVar11;
        puVar16 = puVar16 + 4;
        puVar18 = puVar17;
      } while (puVar20 != &uStack_24);
      *puVar16 = *puVar17;
      local_50 = local_50 + 9;
    }
    if ((int)param_1->srtp_profile << 0x1f < 0) {
      if ((int)param_3 - (int)local_50 < 5) {
        return (undefined4 *)0x0;
      }
      *(undefined *)local_50 = 0;
      uVar5 = 1;
      *(undefined *)((int)local_50 + 1) = 0xf;
      *(undefined *)((int)local_50 + 2) = 0;
      *(undefined *)((int)local_50 + 3) = 1;
      if ((int)param_1->srtp_profile << 0x1d < 0) {
        uVar5 = 2;
      }
      *(undefined *)(local_50 + 1) = uVar5;
      local_50 = (undefined4 *)((int)local_50 + 5);
    }
    iVar12 = param_1->s3->next_proto_neg_seen;
    param_1->s3->next_proto_neg_seen = 0;
    if (iVar12 != 0) {
      pcVar19 = *(code **)(param_1->psk_server_callback + 0x1a4);
      if ((pcVar19 != (code *)0x0) &&
         (iVar12 = (*pcVar19)(param_1,&local_4c,&local_48,
                              *(undefined4 *)(param_1->psk_server_callback + 0x1a8)), iVar12 == 0))
      {
        if ((int)((int)param_3 + ((-4 - local_48) - (int)local_50)) < 0) {
          return (undefined4 *)0x0;
        }
        *(undefined *)local_50 = 0x33;
        *(undefined *)((int)local_50 + 1) = 0x74;
        *(char *)((int)local_50 + 2) = (char)(local_48 >> 8);
        *(char *)((int)local_50 + 3) = (char)local_48;
        local_50 = local_50 + 1;
        memcpy(local_50,local_4c,local_48);
        local_50 = (undefined4 *)((int)local_50 + local_48);
        param_1->s3->next_proto_neg_seen = 1;
      }
    }
    iVar12 = custom_ext_add(param_1,1,&local_50,param_3,param_4);
    if (iVar12 != 0) {
      pvVar7 = (void *)param_1->s3[1].delay_buf_pop_ret;
      if (pvVar7 != (void *)0x0) {
        __n = *(size_t *)param_1->s3[1].read_sequence;
        if ((int)((int)param_3 + ((-7 - __n) - (int)local_50)) < 0) {
          return (undefined4 *)0x0;
        }
        *(undefined *)local_50 = 0;
        cVar1 = (char)__n;
        *(undefined *)((int)local_50 + 1) = 0x10;
        *(char *)((int)local_50 + 2) = (char)(__n + 3 >> 8);
        *(char *)((int)local_50 + 3) = cVar1 + '\x03';
        *(char *)(local_50 + 1) = (char)(__n + 1 >> 8);
        *(char *)((int)local_50 + 5) = cVar1 + '\x01';
        puVar16 = (undefined4 *)((int)local_50 + 7);
        *(char *)((int)local_50 + 6) = cVar1;
        local_50 = puVar16;
        memcpy(puVar16,pvVar7,__n);
        local_50 = (undefined4 *)((int)local_50 + __n);
      }
      puVar13 = (undefined *)((int)local_50 + (-2 - (int)param_2));
      if (puVar13 != (undefined *)0x0) {
        *(char *)((int)param_2 + 1) = (char)puVar13;
        *(char *)param_2 = (char)((uint)puVar13 >> 8);
        return local_50;
      }
      return param_2;
    }
  }
  else {
    iVar10 = ssl_add_serverhello_renegotiate_ext(param_1,0,&local_48,0);
    line = 0x66a;
    if (iVar10 != 0) {
      if ((int)((int)param_3 + (-local_48 - (int)local_50) + -4) < 0) {
        return (undefined4 *)0x0;
      }
      *(undefined *)local_50 = 0xff;
      *(undefined *)((int)local_50 + 1) = 1;
      *(char *)((int)local_50 + 2) = (char)(local_48 >> 8);
      *(char *)((int)local_50 + 3) = (char)local_48;
      local_50 = local_50 + 1;
      iVar10 = ssl_add_serverhello_renegotiate_ext(param_1,local_50,&local_48,local_48);
      if (iVar10 != 0) {
        local_50 = (undefined4 *)((int)local_50 + local_48);
        goto joined_r0x00071c54;
      }
      line = 0x675;
    }
LAB_00071d06:
    ERR_put_error(0x14,0x116,0x44,DAT_00071dfc,line);
  }
  return (undefined4 *)0x0;
}

