
int i2d_ASN1_GENERALSTRING(ASN1_GENERALSTRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)ASN1_GENERALSTRING_it);
  return iVar1;
}

