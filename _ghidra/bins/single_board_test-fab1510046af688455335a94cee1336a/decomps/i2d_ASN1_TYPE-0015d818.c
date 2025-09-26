
int i2d_ASN1_TYPE(ASN1_TYPE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)ASN1_ANY_it);
  return iVar1;
}

