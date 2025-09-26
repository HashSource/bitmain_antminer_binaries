
int i2d_X509_CRL_bio(BIO *bp,X509_CRL *crl)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)X509_CRL_it,bp,crl);
  return iVar1;
}

