
int i2d_ASN1_SEQUENCE_ANY(ASN1_SEQUENCE_ANY *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000bbe9c);
  return iVar1;
}

