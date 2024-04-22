
int i2d_USERNOTICE(USERNOTICE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000ca56c);
  return iVar1;
}

