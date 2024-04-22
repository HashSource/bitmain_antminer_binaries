
int i2d_PKCS7_SIGN_ENVELOPE(PKCS7_SIGN_ENVELOPE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000cf0e4);
  return iVar1;
}

