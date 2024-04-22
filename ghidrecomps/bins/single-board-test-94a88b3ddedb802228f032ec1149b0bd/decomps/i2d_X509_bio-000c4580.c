
int i2d_X509_bio(BIO *bp,X509 *x509)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)X509_it,bp,x509);
  return iVar1;
}

