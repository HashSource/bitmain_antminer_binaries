
int i2d_DIST_POINT(DIST_POINT *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000cafe0);
  return iVar1;
}

