
int PEM_write_PKCS8PrivateKey_nid
              (FILE *fp,EVP_PKEY *x,int nid,char *kstr,int klen,undefined1 *cb,void *u)

{
  BIO *a;
  int iVar1;
  
  a = BIO_new_fp(fp,0);
  if (a == (BIO *)0x0) {
    ERR_put_error(9,0x7d,7,DAT_0010b1f0,0xe7);
    iVar1 = 0;
  }
  else {
    iVar1 = do_pk8pkey(a,x,0,nid,0,kstr,klen,cb,u);
    BIO_free(a);
  }
  return iVar1;
}

