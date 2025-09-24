
int X509_load_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  ulong uVar2;
  int iVar3;
  X509_CRL *x;
  int iVar4;
  int line;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,file), lVar1 < 1)) {
    line = 0x8d;
    iVar3 = 2;
  }
  else {
    if (type == 1) {
      iVar4 = 0;
      while (x = PEM_read_bio_X509_CRL(bp,(X509_CRL **)0x0,(undefined1 *)0x0,""),
            x != (X509_CRL *)0x0) {
        iVar3 = X509_STORE_add_crl(ctx->store_ctx,x);
        if (iVar3 == 0) {
          iVar4 = 0;
          goto LAB_0016530c;
        }
        iVar4 = iVar4 + 1;
        X509_CRL_free(x);
      }
      uVar2 = ERR_peek_last_error();
      if (iVar4 == 0 || (uVar2 & 0xfff) != 0x6c) {
        ERR_put_error(0xb,0x70,9,"crypto/x509/by_file.c",0x9a);
        iVar4 = 0;
      }
      else {
        ERR_clear_error();
      }
      goto LAB_0016530c;
    }
    if (type == 2) {
      x = d2i_X509_CRL_bio(bp,(X509_CRL **)0x0);
      if (x == (X509_CRL *)0x0) {
        ERR_put_error(0xb,0x70,0xd,"crypto/x509/by_file.c",0xa9);
        iVar4 = 0;
      }
      else {
        iVar4 = X509_STORE_add_crl(ctx->store_ctx,x);
      }
      goto LAB_0016530c;
    }
    line = 0xb1;
    iVar3 = 100;
  }
  x = (X509_CRL *)0x0;
  iVar4 = 0;
  ERR_put_error(0xb,0x70,iVar3,"crypto/x509/by_file.c",line);
LAB_0016530c:
  X509_CRL_free(x);
  BIO_free(bp);
  return iVar4;
}

