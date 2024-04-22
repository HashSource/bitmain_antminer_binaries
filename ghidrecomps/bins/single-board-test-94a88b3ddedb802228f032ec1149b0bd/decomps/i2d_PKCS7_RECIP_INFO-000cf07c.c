
int i2d_PKCS7_RECIP_INFO(PKCS7_RECIP_INFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,DAT_000cf084);
  return iVar1;
}

