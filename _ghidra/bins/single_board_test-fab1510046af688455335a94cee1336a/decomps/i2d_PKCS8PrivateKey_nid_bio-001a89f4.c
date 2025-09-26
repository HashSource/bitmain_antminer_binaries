
int i2d_PKCS8PrivateKey_nid_bio
              (BIO *bp,EVP_PKEY *x,int nid,char *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = do_pk8pkey(bp,x,1,nid,0,kstr,klen,cb,u);
  return iVar1;
}

