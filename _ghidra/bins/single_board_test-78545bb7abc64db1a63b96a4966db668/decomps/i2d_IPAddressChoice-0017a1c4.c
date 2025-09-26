
int i2d_IPAddressChoice(IPAddressChoice *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)IPAddressChoice_it);
  return iVar1;
}

