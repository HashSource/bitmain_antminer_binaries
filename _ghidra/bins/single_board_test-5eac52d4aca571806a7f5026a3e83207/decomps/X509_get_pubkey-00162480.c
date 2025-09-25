
EVP_PKEY * X509_get_pubkey(X509 *x)

{
  EVP_PKEY *pEVar1;
  
  if (x != (X509 *)0x0) {
    pEVar1 = X509_PUBKEY_get((X509_PUBKEY *)x->ex_kusage);
    return pEVar1;
  }
  return (EVP_PKEY *)0x0;
}

