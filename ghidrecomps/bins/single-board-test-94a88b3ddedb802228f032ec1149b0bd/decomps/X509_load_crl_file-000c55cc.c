
int X509_load_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  int iVar2;
  ulong uVar3;
  X509_CRL *x;
  int iVar4;
  
  if (file == (char *)0x0) {
    iVar4 = 1;
  }
  else {
    type_00 = BIO_s_file();
    bp = BIO_new(type_00);
    if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,file), lVar1 < 1)) {
      ERR_put_error(0xb,0x70,2,DAT_000c56c4,0xc4);
      if (bp == (BIO *)0x0) {
        return 0;
      }
      iVar4 = 0;
    }
    else if (type == 1) {
      iVar4 = 0;
      while (x = PEM_read_bio_X509_CRL(bp,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0),
            x != (X509_CRL *)0x0) {
        iVar4 = iVar4 + 1;
        iVar2 = X509_STORE_add_crl(ctx->store_ctx,x);
        if (iVar2 == 0) {
          iVar4 = 0;
          goto LAB_000c5698;
        }
        X509_CRL_free(x);
      }
      uVar3 = ERR_peek_last_error();
      if (((uVar3 & 0xfff) == 0x6c) && (iVar4 != 0)) {
        ERR_clear_error();
      }
      else {
        ERR_put_error(0xb,0x70,9,DAT_000c56c4,0xd1);
        iVar4 = 0;
      }
    }
    else if (type == 2) {
      x = d2i_X509_CRL_bio(bp,(X509_CRL **)0x0);
      if (x == (X509_CRL *)0x0) {
        ERR_put_error(0xb,0x70,0xd,DAT_000c56c4,0xe0);
        iVar4 = 0;
      }
      else {
        iVar4 = X509_STORE_add_crl(ctx->store_ctx,x);
LAB_000c5698:
        X509_CRL_free(x);
      }
    }
    else {
      iVar4 = 0;
      ERR_put_error(0xb,0x70,100,DAT_000c56c4,0xe8);
    }
    BIO_free(bp);
  }
  return iVar4;
}

