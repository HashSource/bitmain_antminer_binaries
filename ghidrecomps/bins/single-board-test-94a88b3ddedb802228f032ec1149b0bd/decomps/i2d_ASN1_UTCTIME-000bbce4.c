
int i2d_ASN1_UTCTIME(ASN1_UTCTIME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbcec);
  return iVar1;
}

