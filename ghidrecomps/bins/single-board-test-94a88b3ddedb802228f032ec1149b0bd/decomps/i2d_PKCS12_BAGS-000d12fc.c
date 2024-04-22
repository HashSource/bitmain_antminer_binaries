
int i2d_PKCS12_BAGS(PKCS12_BAGS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000d1304);
  return iVar1;
}

