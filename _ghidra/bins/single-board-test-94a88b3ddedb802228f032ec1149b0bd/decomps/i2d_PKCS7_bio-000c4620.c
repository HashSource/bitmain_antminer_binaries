
int i2d_PKCS7_bio(BIO *bp,PKCS7 *p7)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)&PKCS7_it,bp,p7);
  return iVar1;
}

