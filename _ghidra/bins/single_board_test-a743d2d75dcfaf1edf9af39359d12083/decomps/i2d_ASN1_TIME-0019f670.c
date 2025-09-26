
int i2d_ASN1_TIME(ASN1_TIME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&ASN1_TIME_it);
  return iVar1;
}

