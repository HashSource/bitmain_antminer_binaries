
int i2d_ASN1_IA5STRING(ASN1_IA5STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbc8c);
  return iVar1;
}

