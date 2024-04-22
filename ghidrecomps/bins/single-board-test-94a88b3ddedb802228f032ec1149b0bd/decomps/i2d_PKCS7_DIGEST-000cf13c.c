
int i2d_PKCS7_DIGEST(PKCS7_DIGEST *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000cf144);
  return iVar1;
}

