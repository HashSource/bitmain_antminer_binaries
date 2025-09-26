
int i2d_POLICYINFO(POLICYINFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&POLICYINFO_it);
  return iVar1;
}

