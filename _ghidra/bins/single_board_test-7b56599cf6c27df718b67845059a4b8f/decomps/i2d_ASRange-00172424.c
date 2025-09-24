
int i2d_ASRange(ASRange *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)ASRange_it);
  return iVar1;
}

