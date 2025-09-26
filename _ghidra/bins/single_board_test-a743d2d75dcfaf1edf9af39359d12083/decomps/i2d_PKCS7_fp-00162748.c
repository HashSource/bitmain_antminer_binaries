
int i2d_PKCS7_fp(FILE *fp,PKCS7 *p7)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_fp((ASN1_ITEM *)&PKCS7_it,fp,p7);
  return iVar1;
}

