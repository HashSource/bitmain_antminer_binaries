
int i2d_ASN1_VISIBLESTRING(ASN1_VISIBLESTRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)ASN1_VISIBLESTRING_it);
  return iVar1;
}

