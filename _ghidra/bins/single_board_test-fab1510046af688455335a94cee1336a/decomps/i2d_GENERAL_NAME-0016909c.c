
int i2d_GENERAL_NAME(GENERAL_NAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&GENERAL_NAME_it);
  return iVar1;
}

