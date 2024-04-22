
int i2d_DISPLAYTEXT(ASN1_STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbe3c);
  return iVar1;
}

