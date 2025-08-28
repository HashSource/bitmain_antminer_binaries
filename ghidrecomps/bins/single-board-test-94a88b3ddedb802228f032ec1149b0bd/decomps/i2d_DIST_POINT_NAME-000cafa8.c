
int i2d_DIST_POINT_NAME(DIST_POINT_NAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)DIST_POINT_NAME_it);
  return iVar1;
}

