
int PEM_write_PrivateKey
              (FILE *fp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  BIO *bp;
  int iVar1;
  
  bp = BIO_new_fp(fp,0);
  if (bp != (BIO *)0x0) {
    iVar1 = PEM_write_bio_PrivateKey(bp,x,enc,kstr,klen,cb,u);
    BIO_free(bp);
    return iVar1;
  }
  ERR_put_error(9,0x8b,7,"crypto/pem/pem_pkey.c",0xc4);
  return 0;
}

