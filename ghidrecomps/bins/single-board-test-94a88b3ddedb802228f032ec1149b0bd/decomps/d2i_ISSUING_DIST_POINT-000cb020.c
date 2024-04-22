
ISSUING_DIST_POINT * d2i_ISSUING_DIST_POINT(ISSUING_DIST_POINT **a,uchar **in,long len)

{
  ISSUING_DIST_POINT *pIVar1;
  
  pIVar1 = (ISSUING_DIST_POINT *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000cb028);
  return pIVar1;
}

