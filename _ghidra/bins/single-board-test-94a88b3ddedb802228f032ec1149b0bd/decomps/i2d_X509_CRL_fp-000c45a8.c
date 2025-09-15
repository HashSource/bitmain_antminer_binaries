
int i2d_X509_CRL_fp(FILE *fp,X509_CRL *crl)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_fp((ASN1_ITEM *)X509_CRL_it,fp,crl);
  return iVar1;
}

