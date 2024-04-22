
int i2d_PKCS8_bio(BIO *bp,X509_SIG *p8)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio(i2d_X509_SIG + 1,bp,(uchar *)p8);
  return iVar1;
}

