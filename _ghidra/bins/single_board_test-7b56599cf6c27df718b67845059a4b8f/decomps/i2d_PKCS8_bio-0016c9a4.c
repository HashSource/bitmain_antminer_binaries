
int i2d_PKCS8_bio(BIO *bp,X509_SIG *p8)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio((undefined1 *)0x186d2d,bp,(uchar *)p8);
  return iVar1;
}

