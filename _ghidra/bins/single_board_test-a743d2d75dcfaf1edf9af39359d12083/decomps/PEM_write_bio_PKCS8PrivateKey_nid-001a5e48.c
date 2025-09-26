
int PEM_write_bio_PKCS8PrivateKey_nid
              (BIO *bp,EVP_PKEY *x,int nid,char *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = do_pk8pkey(bp,x,0,nid,0,kstr,klen,cb,u);
  return iVar1;
}

