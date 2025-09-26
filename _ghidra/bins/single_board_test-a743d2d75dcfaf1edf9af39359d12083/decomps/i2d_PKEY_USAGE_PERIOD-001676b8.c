
int i2d_PKEY_USAGE_PERIOD(PKEY_USAGE_PERIOD *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&PKEY_USAGE_PERIOD_it);
  return iVar1;
}

