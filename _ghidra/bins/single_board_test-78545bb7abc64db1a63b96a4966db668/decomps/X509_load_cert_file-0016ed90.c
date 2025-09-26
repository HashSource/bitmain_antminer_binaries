
int X509_load_cert_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  ulong uVar2;
  int iVar3;
  X509 *x;
  int iVar4;
  int line;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,file), lVar1 < 1)) {
    line = 0x54;
    iVar3 = 2;
  }
  else {
    if (type == 1) {
      iVar4 = 0;
      while (x = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,(undefined1 *)0x0,""), x != (X509 *)0x0) {
        iVar3 = X509_STORE_add_cert(ctx->store_ctx,x);
        if (iVar3 == 0) {
          iVar4 = 0;
          goto LAB_0016edd4;
        }
        iVar4 = iVar4 + 1;
        X509_free(x);
      }
      uVar2 = ERR_peek_last_error();
      if (iVar4 == 0 || (uVar2 & 0xfff) != 0x6c) {
        ERR_put_error(0xb,0x6f,9,"crypto/x509/by_file.c",0x61);
        iVar4 = 0;
      }
      else {
        ERR_clear_error();
      }
      goto LAB_0016edd4;
    }
    if (type == 2) {
      x = d2i_X509_bio(bp,(X509 **)0x0);
      if (x == (X509 *)0x0) {
        ERR_put_error(0xb,0x6f,0xd,"crypto/x509/by_file.c",0x70);
        iVar4 = 0;
      }
      else {
        iVar4 = X509_STORE_add_cert(ctx->store_ctx,x);
      }
      goto LAB_0016edd4;
    }
    line = 0x78;
    iVar3 = 100;
  }
  x = (X509 *)0x0;
  iVar4 = 0;
  ERR_put_error(0xb,0x6f,iVar3,"crypto/x509/by_file.c",line);
LAB_0016edd4:
  X509_free(x);
  BIO_free(bp);
  return iVar4;
}

