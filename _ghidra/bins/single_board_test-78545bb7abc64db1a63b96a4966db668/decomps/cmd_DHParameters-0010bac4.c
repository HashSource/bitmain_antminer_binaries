
bool cmd_DHParameters(int param_1,void *param_2)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  DH *dh;
  SSL_CTX *ctx;
  bool bVar2;
  
  if ((*(int *)(param_1 + 0xc) == 0) && (*(int *)(param_1 + 0x10) == 0)) {
    bVar2 = true;
  }
  else {
    type = BIO_s_file();
    bp = BIO_new(type);
    if ((bp == (BIO *)0x0) ||
       ((lVar1 = BIO_ctrl(bp,0x6c,3,param_2), lVar1 < 1 ||
        (dh = PEM_read_bio_DHparams(bp,(DH **)0x0,(undefined1 *)0x0,(void *)0x0), dh == (DH *)0x0)))
       ) {
      bVar2 = false;
      dh = (DH *)0x0;
    }
    else {
      ctx = *(SSL_CTX **)(param_1 + 0xc);
      if (ctx != (SSL_CTX *)0x0) {
        ctx = (SSL_CTX *)SSL_CTX_ctrl(ctx,3,0,dh);
      }
      if (*(SSL **)(param_1 + 0x10) != (SSL *)0x0) {
        ctx = (SSL_CTX *)SSL_ctrl(*(SSL **)(param_1 + 0x10),3,0,dh);
      }
      bVar2 = 0 < (int)ctx;
    }
    DH_free(dh);
    BIO_free(bp);
  }
  return bVar2;
}

