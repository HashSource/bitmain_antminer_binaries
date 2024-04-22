
undefined4 ssl3_client_hello(SSL *param_1)

{
  int iVar1;
  SSL_METHOD *pSVar2;
  ssl3_enc_method *psVar3;
  undefined4 uVar4;
  stack_st_SSL_CIPHER *psVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  size_t __n;
  SSL_SESSION *pSVar10;
  ssl3_state_st *psVar11;
  uint uVar12;
  char *pcVar13;
  undefined4 uVar14;
  char *pcVar15;
  int iVar16;
  char *pcVar17;
  char *pcVar18;
  undefined4 local_2c [2];
  
  local_2c[0] = 0;
  pcVar18 = param_1->init_buf->data;
  if (param_1->state != 0x1110) goto LAB_00065c90;
  pSVar10 = param_1->session;
  if (((((pSVar10 == (SSL_SESSION *)0x0) || (pSVar10->ssl_version != param_1->version)) ||
       ((pSVar10->session_id_length == 0 && (*(int *)(pSVar10->krb5_client_princ + 0x54) == 0)))) ||
      (*(int *)(pSVar10->krb5_client_princ + 4) != 0)) &&
     (iVar1 = ssl_get_new_session(param_1,0), iVar1 == 0)) goto LAB_00065d28;
  pSVar2 = param_1->method;
  if (pSVar2->version == 0x1ffff) {
    iVar1 = param_1->references;
    if (iVar1 << 4 < 0) {
      if ((*(uint *)(param_1->cert + 0x38) & 0x30000) != 0) {
        ERR_put_error(0x14,0x83,0x183,DAT_00065d9c,0x2c4);
        goto LAB_00065d28;
      }
      if (iVar1 << 5 < 0) {
        ERR_put_error(0x14,0x83,0x10a,DAT_00065d9c,0x2cb);
        goto LAB_00065d28;
      }
      pSVar2 = DTLSv1_client_method();
      iVar1 = 0xfeff;
      param_1->method = pSVar2;
      param_1->version = 0xfeff;
    }
    else {
      if (iVar1 << 5 < 0) {
        pSVar2 = (SSL_METHOD *)DTLSv1_2_client_method();
        param_1->method = pSVar2;
      }
      iVar1 = 0xfefd;
      param_1->version = 0xfefd;
    }
    param_1->first_packet = iVar1;
  }
  psVar3 = pSVar2->ssl3_enc;
  if (*(int *)(psVar3 + 0x38) << 0x1c < 0) {
    iVar1 = 0;
    do {
      iVar6 = iVar1 + 1;
      if (param_1->s3->client_random[iVar1] != '\0') goto LAB_00065b28;
      iVar1 = iVar6;
    } while (iVar6 != 0x20);
  }
  iVar1 = ssl_fill_hello_random(param_1,0,param_1->s3->client_random,0x20);
  if (iVar1 < 1) goto LAB_00065d28;
  psVar3 = param_1->method->ssl3_enc;
LAB_00065b28:
  pcVar9 = param_1->init_buf->data;
  pcVar17 = pcVar9 + *(int *)(psVar3 + 0x3c);
  pcVar9[*(int *)(psVar3 + 0x3c)] = (char)((uint)param_1->first_packet >> 8);
  pcVar17[1] = (char)param_1->first_packet;
  psVar11 = param_1->s3;
  uVar14 = *(undefined4 *)(psVar11->client_random + 4);
  uVar4 = *(undefined4 *)(psVar11->client_random + 8);
  uVar8 = *(undefined4 *)(psVar11->client_random + 0xc);
  *(undefined4 *)(pcVar17 + 2) = *(undefined4 *)psVar11->client_random;
  *(undefined4 *)(pcVar17 + 6) = uVar14;
  *(undefined4 *)(pcVar17 + 10) = uVar4;
  *(undefined4 *)(pcVar17 + 0xe) = uVar8;
  uVar14 = *(undefined4 *)(psVar11->client_random + 0x14);
  uVar4 = *(undefined4 *)(psVar11->client_random + 0x18);
  uVar8 = *(undefined4 *)(psVar11->client_random + 0x1c);
  *(undefined4 *)(pcVar17 + 0x12) = *(undefined4 *)(psVar11->client_random + 0x10);
  *(undefined4 *)(pcVar17 + 0x16) = uVar14;
  *(undefined4 *)(pcVar17 + 0x1a) = uVar4;
  *(undefined4 *)(pcVar17 + 0x1e) = uVar8;
  if (param_1->new_session == 0) {
    pcVar15 = pcVar17 + 0x23;
    __n = param_1->session->session_id_length;
    pcVar17[0x22] = (char)__n;
    pcVar9 = pcVar15;
    if (__n == 0) goto LAB_00065ba8;
    if ((int)__n < 0x21) {
      pcVar9 = pcVar15 + __n;
      memcpy(pcVar15,param_1->session->session_id,__n);
      goto LAB_00065ba8;
    }
    iVar1 = 0x32b;
  }
  else {
    pcVar9 = pcVar17 + 0x23;
    pcVar17[0x22] = '\0';
LAB_00065ba8:
    if (*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c < 0) {
      uVar12 = param_1->d1->cookie_len;
      if (0x100 < uVar12) {
        iVar1 = 0x335;
        goto LAB_00065d36;
      }
      *pcVar9 = (char)uVar12;
      memcpy(pcVar9 + 1,param_1->d1->cookie,param_1->d1->cookie_len);
      pcVar9 = pcVar9 + 1 + param_1->d1->cookie_len;
    }
    pcVar15 = pcVar9 + 2;
    psVar5 = SSL_get_ciphers(param_1);
    iVar1 = ssl_cipher_list_to_bytes(param_1,psVar5,pcVar15,0);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x83,0xb5,DAT_00065d9c,0x340);
      goto LAB_00065d28;
    }
    pcVar9[1] = (char)iVar1;
    pcVar13 = pcVar15 + iVar1;
    *pcVar9 = (char)((uint)iVar1 >> 8);
    if (((param_1->references & 0x20000U) == 0) &&
       (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
      pcVar9 = pcVar13 + 1;
      iVar6 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
      pcVar15[iVar1] = (char)iVar6 + '\x01';
      if (0 < iVar6) {
        iVar1 = 0;
        do {
          iVar16 = iVar1 + 1;
          puVar7 = (undefined4 *)sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar1);
          pcVar13 = pcVar13 + 1;
          *pcVar13 = (char)*puVar7;
          iVar1 = iVar16;
        } while (iVar16 != iVar6);
        pcVar9 = pcVar9 + iVar16;
      }
    }
    else {
      pcVar9 = pcVar13 + 1;
      pcVar15[iVar1] = '\x01';
    }
    *pcVar9 = '\0';
    iVar1 = ssl_prepare_clienthello_tlsext(param_1);
    if (iVar1 < 1) {
      ERR_put_error(0x14,0x83,0xe2,DAT_00065d9c,0x365);
      goto LAB_00065d28;
    }
    iVar1 = ssl_add_clienthello_tlsext(param_1,pcVar9 + 1,pcVar18 + 0x4000,local_2c);
    if (iVar1 != 0) {
      (**(code **)(param_1->method->ssl3_enc + 0x40))(param_1,1,iVar1 - (int)pcVar17);
      param_1->state = 0x1111;
LAB_00065c90:
      uVar4 = (**(code **)(param_1->method->ssl3_enc + 0x44))(param_1);
      return uVar4;
    }
    ssl3_send_alert(param_1,2,local_2c[0]);
    iVar1 = 0x36c;
  }
LAB_00065d36:
  ERR_put_error(0x14,0x83,0x44,DAT_00065d9c,iVar1);
LAB_00065d28:
  param_1->state = 5;
  return 0xffffffff;
}

