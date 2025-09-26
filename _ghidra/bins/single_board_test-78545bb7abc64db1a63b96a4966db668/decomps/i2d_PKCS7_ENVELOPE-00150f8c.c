
int i2d_PKCS7_ENVELOPE(PKCS7_ENVELOPE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PKCS7_ENVELOPE_it);
  return iVar1;
}

