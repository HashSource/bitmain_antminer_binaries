
int i2d_BASIC_CONSTRAINTS(BASIC_CONSTRAINTS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&BASIC_CONSTRAINTS_it);
  return iVar1;
}

