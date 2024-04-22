
int PEM_write_bio_X509_CERT_PAIR(BIO *bp,X509_CERT_PAIR *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(i2d_X509_CERT_PAIR + 1,"CERTIFICATE PAIR",bp,x,(EVP_CIPHER *)0x0,
                             (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

