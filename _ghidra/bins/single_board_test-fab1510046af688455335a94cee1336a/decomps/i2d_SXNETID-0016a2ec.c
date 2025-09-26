
int i2d_SXNETID(SXNETID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&SXNETID_it);
  return iVar1;
}

