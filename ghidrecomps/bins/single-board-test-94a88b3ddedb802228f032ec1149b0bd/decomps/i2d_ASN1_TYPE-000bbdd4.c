
int i2d_ASN1_TYPE(ASN1_TYPE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbddc);
  return iVar1;
}

