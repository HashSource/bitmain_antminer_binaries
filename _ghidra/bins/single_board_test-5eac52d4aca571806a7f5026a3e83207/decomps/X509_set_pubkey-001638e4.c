
int X509_set_pubkey(X509 *x,EVP_PKEY *pkey)

{
  int iVar1;
  
  if (x != (X509 *)0x0) {
    iVar1 = X509_PUBKEY_set((X509_PUBKEY **)&x->ex_kusage,pkey);
    return iVar1;
  }
  return 0;
}

