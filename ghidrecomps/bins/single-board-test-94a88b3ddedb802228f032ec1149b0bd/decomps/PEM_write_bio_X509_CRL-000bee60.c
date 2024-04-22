
int PEM_write_bio_X509_CRL(BIO *bp,X509_CRL *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(i2d_X509_CRL + 1,"X509 CRL",bp,x,(EVP_CIPHER *)0x0,(uchar *)0x0,0,
                             (undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

