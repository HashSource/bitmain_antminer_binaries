
int SSL_use_PrivateKey_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  EVP_PKEY *pkey;
  int iVar2;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xcb,7,"ssl/ssl_rsa.c",0xf3);
    BIO_free((BIO *)0x0);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xcb,2,"ssl/ssl_rsa.c",0xf8);
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,ssl[9].psk_server_callback,ssl[9].ctx);
      iVar2 = 9;
    }
    else {
      if (type != 2) {
        ERR_put_error(0x14,0xcb,0x7c,"ssl/ssl_rsa.c",0x104);
        goto LAB_0010d3cc;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      iVar2 = 0xd;
    }
    if (pkey != (EVP_PKEY *)0x0) {
      iVar2 = SSL_use_PrivateKey(ssl,pkey);
      EVP_PKEY_free(pkey);
      BIO_free(bp);
      return iVar2;
    }
    ERR_put_error(0x14,0xcb,iVar2,"ssl/ssl_rsa.c",0x108);
  }
LAB_0010d3cc:
  BIO_free(bp);
  return 0;
}

