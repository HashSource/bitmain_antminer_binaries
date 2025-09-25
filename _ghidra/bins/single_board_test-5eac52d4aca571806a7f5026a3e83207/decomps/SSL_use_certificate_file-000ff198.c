
int SSL_use_certificate_file(SSL *ssl,char *file,int type)

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
    ERR_put_error(0x14,200,7,"ssl/ssl_rsa.c",0x34);
    x = (X509 *)0x0;
    iVar2 = 0;
    goto LAB_000ff1da;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    line = 0x39;
    reason = 2;
LAB_000ff1ce:
    x = (X509 *)0x0;
    iVar2 = 0;
    ERR_put_error(0x14,200,reason,"ssl/ssl_rsa.c",line);
  }
  else {
    if (type == 2) {
      x = d2i_X509_bio(bp,(X509 **)0x0);
      iVar2 = 0xd;
    }
    else {
      if (type != 1) {
        line = 0x44;
        reason = 0x7c;
        goto LAB_000ff1ce;
      }
      x = PEM_read_bio_X509(bp,(X509 **)0x0,ssl[9].psk_server_callback,ssl[9].ctx);
      iVar2 = 9;
    }
    if (x == (X509 *)0x0) {
      ERR_put_error(0x14,200,iVar2,"ssl/ssl_rsa.c",0x49);
      iVar2 = 0;
    }
    else {
      iVar2 = SSL_use_certificate(ssl,x);
    }
  }
LAB_000ff1da:
  X509_free(x);
  BIO_free(bp);
  return iVar2;
}

