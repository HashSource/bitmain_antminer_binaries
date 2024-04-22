
int i2d_PKCS7_ENC_CONTENT(PKCS7_ENC_CONTENT *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000cf0b4);
  return iVar1;
}

