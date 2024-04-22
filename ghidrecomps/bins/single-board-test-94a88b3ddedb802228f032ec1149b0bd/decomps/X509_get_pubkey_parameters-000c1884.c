
int X509_get_pubkey_parameters(EVP_PKEY *pkey,stack_st_X509 *chain)

{
  int iVar1;
  X509 *pXVar2;
  EVP_PKEY *pkey_00;
  int iVar3;
  EVP_PKEY *to;
  
  if ((pkey == (EVP_PKEY *)0x0) || (iVar1 = EVP_PKEY_missing_parameters(pkey), iVar1 != 0)) {
    for (iVar1 = 0; iVar3 = sk_num(&chain->stack), iVar1 < iVar3; iVar1 = iVar1 + 1) {
      pXVar2 = (X509 *)sk_value(&chain->stack,iVar1);
      pkey_00 = X509_get_pubkey(pXVar2);
      if (pkey_00 == (EVP_PKEY *)0x0) {
        ERR_put_error(0xb,0x6e,0x6c,DAT_000c1934,0x797);
        return 0;
      }
      iVar3 = EVP_PKEY_missing_parameters(pkey_00);
      if (iVar3 == 0) {
        iVar1 = iVar1 + -1;
        if (-1 < iVar1) {
          do {
            pXVar2 = (X509 *)sk_value(&chain->stack,iVar1);
            to = X509_get_pubkey(pXVar2);
            iVar1 = iVar1 + -1;
            EVP_PKEY_copy_parameters(to,pkey_00);
            EVP_PKEY_free(to);
          } while (iVar1 != -1);
        }
        if (pkey != (EVP_PKEY *)0x0) {
          EVP_PKEY_copy_parameters(pkey,pkey_00);
        }
        EVP_PKEY_free(pkey_00);
        return 1;
      }
      EVP_PKEY_free(pkey_00);
    }
    ERR_put_error(0xb,0x6e,0x6b,DAT_000c1934,0x7a3);
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

