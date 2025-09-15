
int X509_REQ_sign(X509_REQ *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  
  iVar1 = ASN1_item_sign((ASN1_ITEM *)&X509_REQ_INFO_it,x->sig_alg,(X509_ALGOR *)0x0,x->signature,
                         x->req_info,pkey,md);
  return iVar1;
}

