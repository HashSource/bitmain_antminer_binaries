
int X509_load_cert_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  int iVar2;
  ulong uVar3;
  X509 *x;
  int iVar4;
  
  if (file == (char *)0x0) {
    iVar4 = 1;
  }
  else {
    type_00 = BIO_s_file();
    bp = BIO_new(type_00);
    if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,file), lVar1 < 1)) {
      ERR_put_error(0xb,0x6f,2,DAT_000c5554,0x89);
      if (bp == (BIO *)0x0) {
        return 0;
      }
      iVar4 = 0;
    }
    else if (type == 1) {
      iVar4 = 0;
      while (x = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0),
            x != (X509 *)0x0) {
        iVar4 = iVar4 + 1;
        iVar2 = X509_STORE_add_cert(ctx->store_ctx,x);
        if (iVar2 == 0) {
          iVar4 = 0;
          goto LAB_000c5528;
        }
        X509_free(x);
      }
      uVar3 = ERR_peek_last_error();
      if (((uVar3 & 0xfff) == 0x6c) && (iVar4 != 0)) {
        ERR_clear_error();
      }
      else {
        ERR_put_error(0xb,0x6f,9,DAT_000c5554,0x96);
        iVar4 = 0;
      }
    }
    else if (type == 2) {
      x = d2i_X509_bio(bp,(X509 **)0x0);
      if (x == (X509 *)0x0) {
        ERR_put_error(0xb,0x6f,0xd,DAT_000c5554,0xa5);
        iVar4 = 0;
      }
      else {
        iVar4 = X509_STORE_add_cert(ctx->store_ctx,x);
LAB_000c5528:
        X509_free(x);
      }
    }
    else {
      iVar4 = 0;
      ERR_put_error(0xb,0x6f,100,DAT_000c5554,0xad);
    }
    BIO_free(bp);
  }
  return iVar4;
}

