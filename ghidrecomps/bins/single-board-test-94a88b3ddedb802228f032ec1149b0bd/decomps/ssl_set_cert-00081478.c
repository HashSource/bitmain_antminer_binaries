
undefined4 ssl_set_cert(int *param_1,X509 *param_2)

{
  EVP_PKEY *pkey;
  int iVar1;
  int iVar2;
  EVP_PKEY *pkey_00;
  
  pkey = X509_get_pubkey(param_2);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xbf,0x10c,DAT_00081570,0x183);
    return 0;
  }
  iVar1 = ssl_cert_type(param_2,pkey);
  if (iVar1 < 0) {
    ERR_put_error(0x14,0xbf,0xf7,DAT_00081570,0x189);
    EVP_PKEY_free(pkey);
    return 0;
  }
  if ((EVP_PKEY *)param_1[iVar1 * 7 + 0x10] != (EVP_PKEY *)0x0) {
    EVP_PKEY_copy_parameters(pkey,(EVP_PKEY *)param_1[iVar1 * 7 + 0x10]);
    ERR_clear_error();
    pkey_00 = (EVP_PKEY *)param_1[iVar1 * 7 + 0x10];
    if (pkey_00->type == 6) {
      iVar2 = RSA_flags((pkey_00->pkey).rsa);
      if (iVar2 << 0x1f < 0) goto LAB_000814cc;
      pkey_00 = (EVP_PKEY *)param_1[iVar1 * 7 + 0x10];
    }
    iVar2 = X509_check_private_key(param_2,pkey_00);
    if (iVar2 == 0) {
      EVP_PKEY_free((EVP_PKEY *)param_1[iVar1 * 7 + 0x10]);
      param_1[iVar1 * 7 + 0x10] = 0;
      ERR_clear_error();
    }
  }
LAB_000814cc:
  EVP_PKEY_free(pkey);
  if ((X509 *)param_1[iVar1 * 7 + 0xf] != (X509 *)0x0) {
    X509_free((X509 *)param_1[iVar1 * 7 + 0xf]);
  }
  CRYPTO_add_lock(&param_2->references,1,3,DAT_00081570,0x1ad);
  param_1[iVar1 * 7 + 0xf] = (int)param_2;
  *param_1 = (int)(param_1 + iVar1 * 7 + 0xf);
  param_1[1] = 0;
  return 1;
}

