
int PEM_write_bio_RSAPrivateKey
              (BIO *bp,RSA *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(i2d_RSAPrivateKey + 1,"RSA PRIVATE KEY",bp,x,enc,kstr,klen,cb,u);
  return iVar1;
}

