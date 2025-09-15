
int i2d_PKCS12_bio(BIO *bp,PKCS12 *p12)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)&PKCS12_it,bp,p12);
  return iVar1;
}

