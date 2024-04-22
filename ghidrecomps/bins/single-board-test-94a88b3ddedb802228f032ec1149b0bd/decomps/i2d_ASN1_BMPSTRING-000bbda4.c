
int i2d_ASN1_BMPSTRING(ASN1_BMPSTRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbdac);
  return iVar1;
}

