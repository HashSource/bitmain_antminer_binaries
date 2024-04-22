
int i2d_PKCS7_SIGNED(PKCS7_SIGNED *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000cefc4);
  return iVar1;
}

