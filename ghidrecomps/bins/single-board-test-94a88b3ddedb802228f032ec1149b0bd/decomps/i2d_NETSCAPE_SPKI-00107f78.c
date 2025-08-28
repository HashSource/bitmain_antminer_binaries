
int i2d_NETSCAPE_SPKI(NETSCAPE_SPKI *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)NETSCAPE_SPKI_it);
  return iVar1;
}

