
int i2d_PKCS7(PKCS7 *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&PKCS7_it);
  return iVar1;
}

