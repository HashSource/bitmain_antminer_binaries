
int PEM_write_bio_DSAPrivateKey
              (BIO *bp,DSA *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio((undefined1 *)0xa47fd,"DSA PRIVATE KEY",bp,x,enc,kstr,klen,cb,u);
  return iVar1;
}

