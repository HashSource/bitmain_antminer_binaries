
int i2d_X509_fp(FILE *fp,X509 *x509)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_fp((ASN1_ITEM *)X509_it,fp,x509);
  return iVar1;
}

