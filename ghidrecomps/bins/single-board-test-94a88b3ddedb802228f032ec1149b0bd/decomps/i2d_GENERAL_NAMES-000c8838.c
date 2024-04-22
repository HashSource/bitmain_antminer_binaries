
int i2d_GENERAL_NAMES(GENERAL_NAMES *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000c8840);
  return iVar1;
}

