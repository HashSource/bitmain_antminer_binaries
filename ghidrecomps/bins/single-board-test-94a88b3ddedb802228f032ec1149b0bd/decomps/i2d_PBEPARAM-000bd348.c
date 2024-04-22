
int i2d_PBEPARAM(PBEPARAM *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&PBEPARAM_it);
  return iVar1;
}

