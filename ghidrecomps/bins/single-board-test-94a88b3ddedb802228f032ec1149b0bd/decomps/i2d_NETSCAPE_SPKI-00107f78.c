
int i2d_NETSCAPE_SPKI(NETSCAPE_SPKI *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_00107f80);
  return iVar1;
}

