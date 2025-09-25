
int i2d_ASIdentifierChoice(ASIdentifierChoice *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)ASIdentifierChoice_it);
  return iVar1;
}

