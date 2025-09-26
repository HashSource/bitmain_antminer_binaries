
int i2d_ASN1_INTEGER(ASN1_INTEGER *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&ASN1_INTEGER_it);
  return iVar1;
}

