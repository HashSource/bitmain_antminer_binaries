
int i2d_EXTENDED_KEY_USAGE(EXTENDED_KEY_USAGE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&EXTENDED_KEY_USAGE_it);
  return iVar1;
}

