
int EC_KEY_print(BIO *bp,EC_KEY *key,int off)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  pkey = EVP_PKEY_new();
  if ((pkey != (EVP_PKEY *)0x0) && (iVar1 = EVP_PKEY_set1_EC_KEY(pkey,key), iVar1 != 0)) {
    iVar1 = EVP_PKEY_print_private(bp,pkey,off,(ASN1_PCTX *)0x0);
    EVP_PKEY_free(pkey);
    return iVar1;
  }
  return 0;
}

