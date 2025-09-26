
int i2d_ACCESS_DESCRIPTION(ACCESS_DESCRIPTION *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&ACCESS_DESCRIPTION_it);
  return iVar1;
}

