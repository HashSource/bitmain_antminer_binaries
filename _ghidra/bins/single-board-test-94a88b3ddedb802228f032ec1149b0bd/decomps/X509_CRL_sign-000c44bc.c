
int X509_CRL_sign(X509_CRL *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  ASN1_BIT_STRING *signature;
  X509_CRL_INFO *data;
  X509_ALGOR *algor2;
  X509_ALGOR *algor1;
  
  data = x->crl;
  algor2 = x->sig_alg;
  algor1 = data->sig_alg;
  signature = x->signature;
  (data->enc).modified = 1;
  iVar1 = ASN1_item_sign((ASN1_ITEM *)&X509_CRL_INFO_it,algor1,algor2,signature,data,pkey,md);
  return iVar1;
}

