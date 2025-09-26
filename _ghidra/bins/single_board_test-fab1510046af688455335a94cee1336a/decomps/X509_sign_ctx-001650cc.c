
int X509_sign_ctx(X509 *x,EVP_MD_CTX *ctx)

{
  int iVar1;
  X509_ALGOR *algor2;
  ASN1_BIT_STRING *signature;
  X509_CINF *asn;
  
  asn = x->cert_info;
  algor2 = x->sig_alg;
  signature = x->signature;
  (asn->enc).modified = 1;
  iVar1 = ASN1_item_sign_ctx((ASN1_ITEM *)&X509_CINF_it,asn->signature,algor2,signature,asn,ctx);
  return iVar1;
}

