
int i2d_PKCS7_SIGNER_INFO(PKCS7_SIGNER_INFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PKCS7_SIGNER_INFO_it);
  return iVar1;
}

