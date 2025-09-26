
undefined4 tls_prepare_client_certificate(SSL *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  BIO *extraout_r3;
  BIO *pBVar3;
  int iVar4;
  X509 *local_18;
  EVP_PKEY *local_14;
  
  local_18 = (X509 *)0x0;
  local_14 = (EVP_PKEY *)0x0;
  if (param_2 == 3) {
    pcVar2 = *(code **)(param_1[2].error + 0xe0);
    if (pcVar2 != (code *)0x0) {
      iVar1 = (*pcVar2)(param_1,*(undefined4 *)(param_1[2].error + 0xe4));
      if (iVar1 < 0) {
        param_1->bbio = (BIO *)&DAT_00000004;
        return 3;
      }
      pBVar3 = extraout_r3;
      if (iVar1 != 0) {
        pBVar3 = (BIO *)0x1;
      }
      if (iVar1 == 0) {
        ossl_statem_fatal(param_1,0x50,0x168,0xea,"ssl/statem/statem_clnt.c",0xd9a);
        return 0;
      }
      param_1->bbio = pBVar3;
    }
    iVar1 = tls_choose_sigalg(param_1,0);
    if (((iVar1 != 0) && (*(int *)(param_1->mac_flags + 0x260) != 0)) &&
       (((*(uint *)(param_1[2].error + 0x10) & 0x30001) == 0 ||
        (iVar1 = tls1_check_chain(param_1,0,0,0,0xfffffffe), iVar1 != 0)))) goto LAB_000fb946;
  }
  else if (param_2 != 4) {
    ossl_statem_fatal(param_1,0x50,0x168,0x44,"ssl/statem/statem_clnt.c",0xdd8);
    return 0;
  }
  iVar1 = ssl_do_client_cert_cb(param_1,&local_18,&local_14);
  if (iVar1 < 0) {
    param_1->bbio = (BIO *)&DAT_00000004;
    return 4;
  }
  param_1->bbio = (BIO *)0x1;
  if (iVar1 == 1) {
    if ((local_14 == (EVP_PKEY *)0x0) || (local_18 == (X509 *)0x0)) {
      ERR_put_error(0x14,0x168,0x6a,"ssl/statem/statem_clnt.c",0xdbc);
    }
    else {
      iVar1 = SSL_use_certificate(param_1,local_18);
      if ((iVar1 != 0) && (iVar1 = SSL_use_PrivateKey(param_1,local_14), iVar1 != 0)) {
        X509_free(local_18);
        EVP_PKEY_free(local_14);
        goto LAB_000fb9e8;
      }
    }
    X509_free(local_18);
    EVP_PKEY_free(local_14);
LAB_000fb992:
    iVar4 = param_1->mac_flags;
  }
  else {
    X509_free(local_18);
    EVP_PKEY_free(local_14);
    if (iVar1 == 0) goto LAB_000fb992;
LAB_000fb9e8:
    iVar1 = tls_choose_sigalg(param_1,0);
    iVar4 = param_1->mac_flags;
    if ((iVar1 != 0) && (*(int *)(iVar4 + 0x260) != 0)) {
      if (((*(uint *)(param_1[2].error + 0x10) & 0x30001) == 0) ||
         (iVar1 = tls1_check_chain(param_1,0,0,0,0xfffffffe), iVar1 != 0)) goto LAB_000fb946;
      goto LAB_000fb992;
    }
  }
  if (param_1->version == 0x300) {
    *(undefined4 *)(iVar4 + 0x218) = 0;
    ssl3_send_alert(param_1,1,0x29);
    return 2;
  }
  *(undefined4 *)(iVar4 + 0x218) = 2;
  iVar1 = ssl3_digest_cached_records(param_1,0);
  if (iVar1 == 0) {
    return 0;
  }
LAB_000fb946:
  if (param_1[3].tlsext_status_type != 4) {
    return 2;
  }
  return 1;
}

