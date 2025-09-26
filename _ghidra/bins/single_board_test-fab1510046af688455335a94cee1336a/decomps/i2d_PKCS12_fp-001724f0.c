
int i2d_PKCS12_fp(FILE *fp,PKCS12 *p12)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_fp((ASN1_ITEM *)&PKCS12_it,fp,p12);
  return iVar1;
}

