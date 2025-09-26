
int X509_sign(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  ASN1_BIT_STRING *signature;
  X509_CINF *data;
  X509_ALGOR *algor2;
  
  data = x->cert_info;
  algor2 = x->sig_alg;
  signature = x->signature;
  (data->enc).modified = 1;
  iVar1 = ASN1_item_sign((ASN1_ITEM *)&X509_CINF_it,data->signature,algor2,signature,data,pkey,md);
  return iVar1;
}

