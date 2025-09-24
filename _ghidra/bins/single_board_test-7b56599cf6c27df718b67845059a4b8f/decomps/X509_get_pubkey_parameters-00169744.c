
int X509_get_pubkey_parameters(EVP_PKEY *pkey,stack_st_X509 *chain)

{
  int iVar1;
  int iVar2;
  EVP_PKEY *to;
  EVP_PKEY *pkey_00;
  
  if ((pkey == (EVP_PKEY *)0x0) || (iVar1 = EVP_PKEY_missing_parameters(pkey), iVar1 != 0)) {
    pkey_00 = (EVP_PKEY *)0x0;
    for (iVar1 = 0; iVar2 = OPENSSL_sk_num(chain), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      OPENSSL_sk_value(chain,iVar1);
      pkey_00 = (EVP_PKEY *)X509_get0_pubkey();
      if (pkey_00 == (EVP_PKEY *)0x0) {
        ERR_put_error(0xb,0x6e,0x6c,"crypto/x509/x509_vfy.c",0x7a8);
        return 0;
      }
      iVar2 = EVP_PKEY_missing_parameters(pkey_00);
      if (iVar2 == 0) goto LAB_0016977e;
    }
    if (pkey_00 == (EVP_PKEY *)0x0) {
      ERR_put_error(0xb,0x6e,0x6b,"crypto/x509/x509_vfy.c",0x7b0);
      return 0;
    }
LAB_0016977e:
    iVar1 = iVar1 + -1;
    if (-1 < iVar1) {
      do {
        OPENSSL_sk_value(chain,iVar1);
        to = (EVP_PKEY *)X509_get0_pubkey();
        iVar1 = iVar1 + -1;
        EVP_PKEY_copy_parameters(to,pkey_00);
      } while (iVar1 != -1);
    }
    if (pkey != (EVP_PKEY *)0x0) {
      EVP_PKEY_copy_parameters(pkey,pkey_00);
    }
  }
  return 1;
}

