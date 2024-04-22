
int i2d_ASN1_OCTET_STRING(ASN1_OCTET_STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbb9c);
  return iVar1;
}

