
undefined4 *
ssl_add_serverhello_tlsext(SSL *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  ssl3_state_st *psVar6;
  void *__src;
  undefined3 *__src_00;
  undefined4 uVar7;
  SSL_CIPHER *pSVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int line;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined4 uVar14;
  size_t __n;
  undefined4 *puVar15;
  undefined4 *puVar16;
  code *pcVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined4 *local_50;
  void *local_4c;
  size_t local_48;
  undefined4 local_44 [8];
  undefined4 local_24;
  
  psVar6 = param_1->s3;
  pSVar8 = (psVar6->tmp).new_cipher;
  if (((pSVar8->algorithm_mkey & 0xe0) == 0) && ((pSVar8->algorithm_auth & 0x40) == 0)) {
    iVar9 = param_1->version;
    iVar11 = 0;
  }
  else {
    iVar9 = param_1->version;
    iVar11 = *(int *)(param_1->session->krb5_client_princ + 0x48);
    if (iVar11 != 0) {
      iVar11 = 1;
    }
  }
  if ((iVar9 == 0x300) && (psVar6->send_connection_binding == 0)) {
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
    *(undefined1 *)((int)param_2 + 2) = 0;
    *(undefined1 *)((int)param_2 + 3) = 0;
    *(undefined1 *)(param_2 + 1) = 0;
    *(undefined1 *)((int)param_2 + 5) = 0;
    psVar6 = param_1->s3;
  }
  if (psVar6->send_connection_binding == 0) {
joined_r0x00071c54:
    if (iVar11 == 0) {
      iVar11 = param_1->tlsext_ocsp_resplen;
    }
    else {
      __src_00 = (undefined3 *)param_1->tlsext_ecpointformatlist_length;
      if (__src_00 == (undefined3 *)0x0) {
        __src_00 = &ecformats_default;
        if ((*(uint *)(param_1->cert + 0x38) & 0x30000) == 0) {
          puVar12 = (undefined1 *)0x3;
        }
        else {
          puVar12 = (undefined1 *)0x2;
        }
      }
      else {
        puVar12 = (undefined1 *)param_1->tlsext_ticket_expected;
      }
      puVar13 = (undefined1 *)((int)param_3 + (-5 - (int)local_50));
      if ((int)puVar13 < 0) {
        return (undefined4 *)0x0;
      }
      if (puVar13 < puVar12) {
        return (undefined4 *)0x0;
      }
      if ((undefined1 *)0xff < puVar12) {
        ERR_put_error(0x14,0x116,0x44,"t1_lib.c",0x68b);
        return (undefined4 *)0x0;
      }
      *(undefined1 *)local_50 = 0;
      *(undefined1 *)((int)local_50 + 1) = 0xb;
      *(char *)((int)local_50 + 2) = (char)((uint)(puVar12 + 1) >> 8);
      *(char *)((int)local_50 + 3) = (char)puVar12 + '\x01';
      puVar15 = (undefined4 *)((int)local_50 + 5);
      *(char *)(local_50 + 1) = (char)puVar12;
      local_50 = puVar15;
      memcpy(puVar15,__src_00,(size_t)puVar12);
      local_50 = (undefined4 *)((int)local_50 + (int)puVar12);
      iVar11 = param_1->tlsext_ocsp_resplen;
    }
    if ((iVar11 != 0) && (uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar2 & 0x4000) == 0)) {
      if ((int)param_3 - (int)local_50 < 4) {
        return (undefined4 *)0x0;
      }
      *(undefined1 *)local_50 = 0;
      *(undefined1 *)((int)local_50 + 1) = 0x23;
      *(undefined1 *)((int)local_50 + 2) = 0;
      *(undefined1 *)((int)local_50 + 3) = 0;
      local_50 = local_50 + 1;
    }
    if (param_1->tlsext_status_type != 0) {
      if ((int)param_3 - (int)local_50 < 4) {
        return (undefined4 *)0x0;
      }
      *(undefined1 *)local_50 = 0;
      *(undefined1 *)((int)local_50 + 1) = 5;
      *(undefined1 *)((int)local_50 + 2) = 0;
      *(undefined1 *)((int)local_50 + 3) = 0;
      local_50 = local_50 + 1;
    }
    if ((*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c < 0) &&
       (param_1->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
      ssl_add_serverhello_use_srtp_ext(param_1,0,&local_48,0);
      if ((int)((int)param_3 + (-local_48 - (int)local_50) + -4) < 0) {
        return (undefined4 *)0x0;
      }
      *(undefined1 *)local_50 = 0;
      *(undefined1 *)((int)local_50 + 1) = 0xe;
      *(char *)((int)local_50 + 2) = (char)(local_48 >> 8);
      *(char *)((int)local_50 + 3) = (char)local_48;
      local_50 = local_50 + 1;
      iVar11 = ssl_add_serverhello_use_srtp_ext(param_1,local_50,&local_48,local_48);
      line = 0x6c7;
      if (iVar11 != 0) goto LAB_00071d06;
      local_50 = (undefined4 *)((int)local_50 + local_48);
    }
    if (((ushort)((param_1->s3->tmp).new_cipher)->id - 0x80 < 2) &&
       (lVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar3 < 0)) {
      puVar18 = &DAT_001414f4;
      puVar15 = local_44;
      do {
        uVar4 = *puVar18;
        uVar7 = puVar18[1];
        puVar16 = puVar15 + 4;
        uVar10 = puVar18[2];
        uVar14 = puVar18[3];
        puVar18 = puVar18 + 4;
        *puVar15 = uVar4;
        puVar15[1] = uVar7;
        puVar15[2] = uVar10;
        puVar15[3] = uVar14;
        puVar15 = puVar16;
      } while (puVar18 != &DAT_00141514);
      *puVar16 = 0x17020203;
      if ((int)param_3 - (int)local_50 < 0x24) {
        return (undefined4 *)0x0;
      }
      puVar15 = local_50;
      puVar18 = local_44;
      do {
        puVar16 = puVar18 + 4;
        uVar4 = puVar18[1];
        uVar7 = puVar18[2];
        uVar10 = puVar18[3];
        puVar19 = puVar18 + 4;
        *puVar15 = *puVar18;
        puVar15[1] = uVar4;
        puVar15[2] = uVar7;
        puVar15[3] = uVar10;
        puVar15 = puVar15 + 4;
        puVar18 = puVar16;
      } while (puVar19 != &local_24);
      *puVar15 = *puVar16;
      local_50 = local_50 + 9;
    }
    if ((int)param_1->srtp_profile << 0x1f < 0) {
      if ((int)param_3 - (int)local_50 < 5) {
        return (undefined4 *)0x0;
      }
      *(undefined1 *)local_50 = 0;
      uVar5 = 1;
      *(undefined1 *)((int)local_50 + 1) = 0xf;
      *(undefined1 *)((int)local_50 + 2) = 0;
      *(undefined1 *)((int)local_50 + 3) = 1;
      if ((int)param_1->srtp_profile << 0x1d < 0) {
        uVar5 = 2;
      }
      *(undefined1 *)(local_50 + 1) = uVar5;
      local_50 = (undefined4 *)((int)local_50 + 5);
    }
    iVar11 = param_1->s3->next_proto_neg_seen;
    param_1->s3->next_proto_neg_seen = 0;
    if (iVar11 != 0) {
      pcVar17 = *(code **)(param_1->psk_server_callback + 0x1a4);
      if ((pcVar17 != (code *)0x0) &&
         (iVar11 = (*pcVar17)(param_1,&local_4c,&local_48,
                              *(undefined4 *)(param_1->psk_server_callback + 0x1a8)), iVar11 == 0))
      {
        if ((int)((int)param_3 + ((-4 - local_48) - (int)local_50)) < 0) {
          return (undefined4 *)0x0;
        }
        *(undefined1 *)local_50 = 0x33;
        *(undefined1 *)((int)local_50 + 1) = 0x74;
        *(char *)((int)local_50 + 2) = (char)(local_48 >> 8);
        *(char *)((int)local_50 + 3) = (char)local_48;
        local_50 = local_50 + 1;
        memcpy(local_50,local_4c,local_48);
        local_50 = (undefined4 *)((int)local_50 + local_48);
        param_1->s3->next_proto_neg_seen = 1;
      }
    }
    iVar11 = custom_ext_add(param_1,1,&local_50,param_3,param_4);
    if (iVar11 != 0) {
      __src = (void *)param_1->s3[1].delay_buf_pop_ret;
      if (__src != (void *)0x0) {
        __n = *(size_t *)param_1->s3[1].read_sequence;
        if ((int)((int)param_3 + ((-7 - __n) - (int)local_50)) < 0) {
          return (undefined4 *)0x0;
        }
        *(undefined1 *)local_50 = 0;
        cVar1 = (char)__n;
        *(undefined1 *)((int)local_50 + 1) = 0x10;
        *(char *)((int)local_50 + 2) = (char)(__n + 3 >> 8);
        *(char *)((int)local_50 + 3) = cVar1 + '\x03';
        *(char *)(local_50 + 1) = (char)(__n + 1 >> 8);
        *(char *)((int)local_50 + 5) = cVar1 + '\x01';
        puVar15 = (undefined4 *)((int)local_50 + 7);
        *(char *)((int)local_50 + 6) = cVar1;
        local_50 = puVar15;
        memcpy(puVar15,__src,__n);
        local_50 = (undefined4 *)((int)local_50 + __n);
      }
      puVar12 = (undefined1 *)((int)local_50 + (-2 - (int)param_2));
      if (puVar12 != (undefined1 *)0x0) {
        *(char *)((int)param_2 + 1) = (char)puVar12;
        *(char *)param_2 = (char)((uint)puVar12 >> 8);
        return local_50;
      }
      return param_2;
    }
  }
  else {
    iVar9 = ssl_add_serverhello_renegotiate_ext(param_1,0,&local_48,0);
    line = 0x66a;
    if (iVar9 != 0) {
      if ((int)((int)param_3 + (-local_48 - (int)local_50) + -4) < 0) {
        return (undefined4 *)0x0;
      }
      *(undefined1 *)local_50 = 0xff;
      *(undefined1 *)((int)local_50 + 1) = 1;
      *(char *)((int)local_50 + 2) = (char)(local_48 >> 8);
      *(char *)((int)local_50 + 3) = (char)local_48;
      local_50 = local_50 + 1;
      iVar9 = ssl_add_serverhello_renegotiate_ext(param_1,local_50,&local_48,local_48);
      if (iVar9 != 0) {
        local_50 = (undefined4 *)((int)local_50 + local_48);
        goto joined_r0x00071c54;
      }
      line = 0x675;
    }
LAB_00071d06:
    ERR_put_error(0x14,0x116,0x44,"t1_lib.c",line);
  }
  return (undefined4 *)0x0;
}

