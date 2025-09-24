
undefined4 ssl_set_cert(int *param_1,X509 *param_2)

{
  EVP_PKEY *to;
  int iVar1;
  undefined4 uVar2;
  int local_1c [2];
  
  to = (EVP_PKEY *)X509_get0_pubkey(param_2);
  if (to == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xbf,0x10c,"ssl/ssl_rsa.c",0x13a);
    return 0;
  }
  iVar1 = ssl_cert_lookup_by_pkey(to,local_1c);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0xbf,0xf7,"ssl/ssl_rsa.c",0x13f);
    uVar2 = 0;
  }
  else {
    if (local_1c[0] == 3) {
      EVP_PKEY_get0_EC_KEY(to);
      iVar1 = EC_KEY_can_sign();
      if (iVar1 == 0) {
        ERR_put_error(0x14,0xbf,0x13e,"ssl/ssl_rsa.c",0x144);
        return 0;
      }
    }
    iVar1 = local_1c[0] * 4;
    if ((EVP_PKEY *)param_1[local_1c[0] * 5 + 6] != (EVP_PKEY *)0x0) {
      EVP_PKEY_copy_parameters(to,(EVP_PKEY *)param_1[local_1c[0] * 5 + 6]);
      ERR_clear_error();
      iVar1 = X509_check_private_key(param_2,(EVP_PKEY *)param_1[local_1c[0] * 5 + 6]);
      if (iVar1 == 0) {
        EVP_PKEY_free((EVP_PKEY *)param_1[local_1c[0] * 5 + 6]);
        param_1[local_1c[0] * 5 + 6] = 0;
        ERR_clear_error();
      }
      iVar1 = local_1c[0] << 2;
    }
    uVar2 = 1;
    X509_free((X509 *)param_1[local_1c[0] + iVar1 + 5]);
    X509_up_ref(param_2);
    param_1[local_1c[0] * 5 + 5] = (int)param_2;
    *param_1 = (int)(param_1 + local_1c[0] * 5 + 5);
  }
  return uVar2;
}

