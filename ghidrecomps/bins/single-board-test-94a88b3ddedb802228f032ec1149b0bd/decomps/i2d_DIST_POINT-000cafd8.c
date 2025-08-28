
int i2d_DIST_POINT(DIST_POINT *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)DIST_POINT_it);
  return iVar1;
}

