
int i2d_ISSUING_DIST_POINT(ISSUING_DIST_POINT *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000cb034);
  return iVar1;
}

