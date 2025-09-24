
int SSL_CTX_use_PrivateKey_file(SSL_CTX *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  EVP_PKEY *pkey;
  int iVar2;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xb0,7,"ssl/ssl_rsa.c",0x204);
    BIO_free((BIO *)0x0);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xb0,2,"ssl/ssl_rsa.c",0x209);
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey
                       (bp,(EVP_PKEY **)0x0,(undefined1 *)ctx->default_passwd_callback_userdata,
                        ctx->client_cert_cb);
      iVar2 = 9;
    }
    else {
      if (type != 2) {
        ERR_put_error(0x14,0xb0,0x7c,"ssl/ssl_rsa.c",0x215);
        goto LAB_00103d74;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      iVar2 = 0xd;
    }
    if (pkey != (EVP_PKEY *)0x0) {
      iVar2 = SSL_CTX_use_PrivateKey(ctx,pkey);
      EVP_PKEY_free(pkey);
      BIO_free(bp);
      return iVar2;
    }
    ERR_put_error(0x14,0xb0,iVar2,"ssl/ssl_rsa.c",0x219);
  }
LAB_00103d74:
  BIO_free(bp);
  return 0;
}

