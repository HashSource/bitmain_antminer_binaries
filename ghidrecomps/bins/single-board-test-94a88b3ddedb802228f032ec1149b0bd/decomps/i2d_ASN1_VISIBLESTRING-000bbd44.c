
int i2d_ASN1_VISIBLESTRING(ASN1_VISIBLESTRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbd4c);
  return iVar1;
}

