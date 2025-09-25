
int X509_REQ_sign_ctx(X509_REQ *x,EVP_MD_CTX *ctx)

{
  int iVar1;
  
  x->signature = (ASN1_BIT_STRING *)0x1;
  iVar1 = ASN1_item_sign_ctx((ASN1_ITEM *)X509_REQ_INFO_it,(X509_ALGOR *)&x[1].references,
                             (X509_ALGOR *)0x0,(ASN1_BIT_STRING *)x[2].sig_alg,x,ctx);
  return iVar1;
}

