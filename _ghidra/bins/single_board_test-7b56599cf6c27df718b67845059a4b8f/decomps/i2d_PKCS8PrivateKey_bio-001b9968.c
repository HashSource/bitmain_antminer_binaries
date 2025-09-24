
int i2d_PKCS8PrivateKey_bio
              (BIO *bp,EVP_PKEY *x,EVP_CIPHER *enc,char *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = do_pk8pkey(bp,x,1,0xffffffff,enc,kstr,klen,cb,u);
  return iVar1;
}

