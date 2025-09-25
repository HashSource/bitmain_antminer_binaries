
int i2d_PKCS8PrivateKey_fp
              (FILE *fp,EVP_PKEY *x,EVP_CIPHER *enc,char *kstr,int klen,undefined1 *cb,void *u)

{
  BIO *a;
  int iVar1;
  
  a = BIO_new_fp(fp,0);
  if (a != (BIO *)0x0) {
    iVar1 = do_pk8pkey(a,x,1,0xffffffff,enc,kstr,klen,cb,u);
    BIO_free(a);
    return iVar1;
  }
  ERR_put_error(9,0x7d,7,"crypto/pem/pem_pk8.c",0xb9);
  return 0;
}

