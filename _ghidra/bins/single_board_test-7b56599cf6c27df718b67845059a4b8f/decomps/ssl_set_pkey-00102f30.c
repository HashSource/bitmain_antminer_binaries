
undefined4 ssl_set_pkey(int *param_1,EVP_PKEY *param_2)

{
  int iVar1;
  EVP_PKEY *to;
  int iVar2;
  undefined4 uVar3;
  int local_14;
  
  iVar1 = ssl_cert_lookup_by_pkey(param_2,&local_14);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0xc1,0xf7,"ssl/ssl_rsa.c",0x85);
    uVar3 = 0;
  }
  else {
    iVar1 = local_14 * 4;
    if (param_1[local_14 * 5 + 5] != 0) {
      to = (EVP_PKEY *)X509_get0_pubkey();
      if (to == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xc1,0x41,"ssl/ssl_rsa.c",0x8d);
        return 0;
      }
      EVP_PKEY_copy_parameters(to,param_2);
      ERR_clear_error();
      iVar2 = X509_check_private_key((X509 *)param_1[local_14 * 5 + 5],param_2);
      iVar1 = local_14 << 2;
      if (iVar2 == 0) {
        X509_free((X509 *)param_1[local_14 * 5 + 5]);
        param_1[local_14 * 5 + 5] = 0;
        return 0;
      }
    }
    uVar3 = 1;
    EVP_PKEY_free((EVP_PKEY *)param_1[local_14 + iVar1 + 6]);
    EVP_PKEY_up_ref(param_2);
    param_1[local_14 * 5 + 6] = (int)param_2;
    *param_1 = (int)(param_1 + local_14 * 5 + 5);
  }
  return uVar3;
}

