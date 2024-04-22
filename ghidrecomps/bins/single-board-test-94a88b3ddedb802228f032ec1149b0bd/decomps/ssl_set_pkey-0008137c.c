
undefined4 ssl_set_pkey(int *param_1,EVP_PKEY *param_2)

{
  int iVar1;
  EVP_PKEY *to;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2->type != 0x1c) {
    iVar1 = ssl_cert_type(0);
    goto LAB_00081394;
  }
  if ((X509 *)param_1[0x24] == (X509 *)0x0) {
LAB_00081426:
    if ((X509 *)param_1[0x2b] != (X509 *)0x0) {
      iVar1 = 4;
      iVar2 = X509_check_private_key((X509 *)param_1[0x2b],param_2);
      if (iVar2 != 0) goto LAB_00081420;
    }
    iVar1 = -1;
    ERR_clear_error();
  }
  else {
    iVar2 = X509_check_private_key((X509 *)param_1[0x24],param_2);
    iVar1 = 3;
    if (iVar2 == 0) goto LAB_00081426;
LAB_00081420:
    ERR_clear_error();
  }
LAB_00081394:
  if (iVar1 < 0) {
    ERR_put_error(0x14,0xc1,0xf7,DAT_00081474,0xbf);
    uVar3 = 0;
  }
  else {
    if ((X509 *)param_1[iVar1 * 7 + 0xf] != (X509 *)0x0) {
      to = X509_get_pubkey((X509 *)param_1[iVar1 * 7 + 0xf]);
      EVP_PKEY_copy_parameters(to,param_2);
      EVP_PKEY_free(to);
      ERR_clear_error();
      if (((param_2->type != 6) || (iVar2 = RSA_flags((param_2->pkey).rsa), -1 < iVar2 << 0x1f)) &&
         (iVar2 = X509_check_private_key((X509 *)param_1[iVar1 * 7 + 0xf],param_2), iVar2 == 0)) {
        X509_free((X509 *)param_1[iVar1 * 7 + 0xf]);
        param_1[iVar1 * 7 + 0xf] = 0;
        return 0;
      }
    }
    if ((EVP_PKEY *)param_1[iVar1 * 7 + 0x10] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)param_1[iVar1 * 7 + 0x10]);
    }
    CRYPTO_add_lock(&param_2->references,1,10,DAT_00081474,0xdc);
    uVar3 = 1;
    param_1[iVar1 * 7 + 0x10] = (int)param_2;
    *param_1 = (int)(param_1 + iVar1 * 7 + 0xf);
    param_1[1] = 0;
  }
  return uVar3;
}

