
EVP_PKEY * X509_PUBKEY_get(X509_PUBKEY *key)

{
  EVP_PKEY *pEVar1;
  int iVar2;
  
  pEVar1 = (EVP_PKEY *)X509_PUBKEY_get0(key);
  if ((pEVar1 != (EVP_PKEY *)0x0) && (iVar2 = EVP_PKEY_up_ref(), iVar2 == 0)) {
    ERR_put_error(0xb,0xa1,0x44,"crypto/x509/x_pubkey.c",0xae);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  return pEVar1;
}

