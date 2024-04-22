
int i2d_SXNET(SXNET *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000c9a24);
  return iVar1;
}

