
int i2d_PKCS7_SIGNER_INFO(PKCS7_SIGNER_INFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000ceff4);
  return iVar1;
}

