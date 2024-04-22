
int i2d_ASN1_UTF8STRING(ASN1_UTF8STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbbfc);
  return iVar1;
}

