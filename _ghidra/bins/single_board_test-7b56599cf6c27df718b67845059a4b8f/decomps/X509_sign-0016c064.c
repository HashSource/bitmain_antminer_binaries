
int X509_sign(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  
  x->crldp = (stack_st_DIST_POINT *)0x1;
  iVar1 = ASN1_item_sign((ASN1_ITEM *)X509_CINF_it,(X509_ALGOR *)&x->name,(X509_ALGOR *)&x->altname,
                         (ASN1_BIT_STRING *)&x->rfc3779_addr,x,pkey,md);
  return iVar1;
}

