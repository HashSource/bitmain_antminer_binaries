
int i2d_POLICYQUALINFO(POLICYQUALINFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000ca53c);
  return iVar1;
}

