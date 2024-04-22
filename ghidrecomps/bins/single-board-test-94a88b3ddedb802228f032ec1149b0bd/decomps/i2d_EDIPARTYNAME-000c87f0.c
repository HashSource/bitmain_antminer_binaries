
int i2d_EDIPARTYNAME(EDIPARTYNAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000c87f8);
  return iVar1;
}

