
int SSL_CTX_use_certificate_file(SSL_CTX *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  int reason;
  X509 *x;
  int iVar2;
  int line;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xad,7,"ssl/ssl_rsa.c",0x16e);
    x = (X509 *)0x0;
    iVar2 = 0;
    goto LAB_000ff748;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    line = 0x173;
    reason = 2;
LAB_000ff73c:
    x = (X509 *)0x0;
    iVar2 = 0;
    ERR_put_error(0x14,0xad,reason,"ssl/ssl_rsa.c",line);
  }
  else {
    if (type == 2) {
      x = d2i_X509_bio(bp,(X509 **)0x0);
      iVar2 = 0xd;
    }
    else {
      if (type != 1) {
        line = 0x17e;
        reason = 0x7c;
        goto LAB_000ff73c;
      }
      x = PEM_read_bio_X509(bp,(X509 **)0x0,(undefined1 *)ctx->default_passwd_callback_userdata,
                            ctx->client_cert_cb);
      iVar2 = 9;
    }
    if (x == (X509 *)0x0) {
      ERR_put_error(0x14,0xad,iVar2,"ssl/ssl_rsa.c",0x183);
      iVar2 = 0;
    }
    else {
      iVar2 = SSL_CTX_use_certificate(ctx,x);
    }
  }
LAB_000ff748:
  X509_free(x);
  BIO_free(bp);
  return iVar2;
}

