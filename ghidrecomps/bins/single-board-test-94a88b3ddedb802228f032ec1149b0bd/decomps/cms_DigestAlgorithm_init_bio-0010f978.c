
BIO * cms_DigestAlgorithm_init_bio(X509_ALGOR *param_1)

{
  int n;
  char *name;
  EVP_MD *parg;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  ASN1_OBJECT *local_14 [2];
  
  X509_ALGOR_get0(local_14,(int *)0x0,(void **)0x0,param_1);
  n = OBJ_obj2nid(local_14[0]);
  name = OBJ_nid2sn(n);
  parg = EVP_get_digestbyname(name);
  if (parg == (EVP_MD *)0x0) {
    ERR_put_error(0x2e,0x74,0x95,DAT_0010fa00,0x16a);
    bp = (BIO *)0x0;
  }
  else {
    type = BIO_f_md();
    bp = BIO_new(type);
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x2e,0x74,0x77,DAT_0010fa00,0x16f);
    }
    else {
      lVar1 = BIO_ctrl(bp,0x6f,0,parg);
      if (lVar1 == 0) {
        ERR_put_error(0x2e,0x74,0x77,DAT_0010fa00,0x16f);
        BIO_free(bp);
        bp = (BIO *)0x0;
      }
    }
  }
  return bp;
}

