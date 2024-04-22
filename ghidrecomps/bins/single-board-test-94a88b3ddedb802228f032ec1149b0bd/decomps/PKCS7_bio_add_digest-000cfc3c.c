
undefined4 PKCS7_bio_add_digest(BIO **param_1,ASN1_OBJECT **param_2)

{
  BIO_METHOD *type;
  BIO *bp;
  int n;
  char *name;
  EVP_MD *parg;
  BIO *pBVar1;
  
  type = BIO_f_md();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x21,0x7d,0x20,DAT_000cfcc4,0x6d);
    return 0;
  }
  n = OBJ_obj2nid(*param_2);
  name = OBJ_nid2sn(n);
  parg = EVP_get_digestbyname(name);
  if (parg == (EVP_MD *)0x0) {
    ERR_put_error(0x21,0x7d,0x6d,DAT_000cfcc4,0x73);
  }
  else {
    BIO_ctrl(bp,0x6f,0,parg);
    if (*param_1 == (BIO *)0x0) {
      *param_1 = bp;
      return 1;
    }
    pBVar1 = BIO_push(*param_1,bp);
    if (pBVar1 != (BIO *)0x0) {
      return 1;
    }
    ERR_put_error(0x21,0x7d,0x20,DAT_000cfcc4,0x7b);
  }
  BIO_free(bp);
  return 0;
}

