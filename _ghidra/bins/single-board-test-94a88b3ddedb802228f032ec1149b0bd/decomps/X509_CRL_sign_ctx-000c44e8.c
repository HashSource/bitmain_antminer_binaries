
int X509_CRL_sign_ctx(X509_CRL *x,EVP_MD_CTX *ctx)

{
  int iVar1;
  X509_ALGOR *algor2;
  ASN1_BIT_STRING *signature;
  X509_CRL_INFO *asn;
  X509_ALGOR *algor1;
  
  asn = x->crl;
  algor2 = x->sig_alg;
  algor1 = asn->sig_alg;
  signature = x->signature;
  (asn->enc).modified = 1;
  iVar1 = ASN1_item_sign_ctx((ASN1_ITEM *)&X509_CRL_INFO_it,algor1,algor2,signature,asn,ctx);
  return iVar1;
}

