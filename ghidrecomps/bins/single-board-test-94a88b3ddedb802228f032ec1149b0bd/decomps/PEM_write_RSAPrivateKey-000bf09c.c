
int PEM_write_RSAPrivateKey
              (FILE *fp,RSA *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(i2d_RSAPrivateKey + 1,"RSA PRIVATE KEY",fp,x,enc,kstr,klen,cb,u);
  return iVar1;
}

