
int i2d_OTHERNAME(OTHERNAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)OTHERNAME_it);
  return iVar1;
}

