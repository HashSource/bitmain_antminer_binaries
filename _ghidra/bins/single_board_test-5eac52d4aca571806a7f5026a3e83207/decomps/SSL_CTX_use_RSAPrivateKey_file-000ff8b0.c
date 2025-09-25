
int SSL_CTX_use_RSAPrivateKey_file(SSL_CTX *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  RSA *rsa;
  int iVar2;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xb3,7,"ssl/ssl_rsa.c",0x1c1);
    BIO_free((BIO *)0x0);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xb3,2,"ssl/ssl_rsa.c",0x1c6);
  }
  else {
    if (type == 2) {
      rsa = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      iVar2 = 0xd;
    }
    else {
      if (type != 1) {
        ERR_put_error(0x14,0xb3,0x7c,"ssl/ssl_rsa.c",0x1d2);
        goto LAB_000ff8f4;
      }
      rsa = PEM_read_bio_RSAPrivateKey
                      (bp,(RSA **)0x0,(undefined1 *)ctx->default_passwd_callback_userdata,
                       ctx->client_cert_cb);
      iVar2 = 9;
    }
    if (rsa != (RSA *)0x0) {
      iVar2 = SSL_CTX_use_RSAPrivateKey(ctx,rsa);
      RSA_free(rsa);
      BIO_free(bp);
      return iVar2;
    }
    ERR_put_error(0x14,0xb3,iVar2,"ssl/ssl_rsa.c",0x1d6);
  }
LAB_000ff8f4:
  BIO_free(bp);
  return 0;
}

