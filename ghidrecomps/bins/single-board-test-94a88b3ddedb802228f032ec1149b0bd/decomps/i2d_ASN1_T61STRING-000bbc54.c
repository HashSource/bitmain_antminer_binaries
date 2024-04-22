
int i2d_ASN1_T61STRING(ASN1_T61STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbc5c);
  return iVar1;
}

