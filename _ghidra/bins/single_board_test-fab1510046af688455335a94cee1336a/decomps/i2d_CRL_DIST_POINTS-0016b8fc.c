
int i2d_CRL_DIST_POINTS(CRL_DIST_POINTS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)CRL_DIST_POINTS_it);
  return iVar1;
}

