
int i2d_NETSCAPE_SPKAC(NETSCAPE_SPKAC *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)&NETSCAPE_SPKAC_it);
  return iVar1;
}

