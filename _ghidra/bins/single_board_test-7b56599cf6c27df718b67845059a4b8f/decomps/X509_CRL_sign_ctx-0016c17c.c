
int X509_CRL_sign_ctx(X509_CRL *x,EVP_MD_CTX *ctx)

{
  int iVar1;
  
  x->base_crl_number = (ASN1_INTEGER *)0x1;
  iVar1 = ASN1_item_sign_ctx((ASN1_ITEM *)X509_CRL_INFO_it,(X509_ALGOR *)&x->sig_alg,
                             (X509_ALGOR *)x->sha1_hash,(ASN1_BIT_STRING *)(x->sha1_hash + 8),x,ctx)
  ;
  return iVar1;
}

