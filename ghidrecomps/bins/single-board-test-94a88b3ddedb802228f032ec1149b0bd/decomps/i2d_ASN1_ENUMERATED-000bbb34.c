
int i2d_ASN1_ENUMERATED(ASN1_ENUMERATED *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)ASN1_ENUMERATED_it);
  return iVar1;
}

