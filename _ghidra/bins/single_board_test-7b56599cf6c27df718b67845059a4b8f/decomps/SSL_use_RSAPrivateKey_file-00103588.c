
int SSL_use_RSAPrivateKey_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  RSA *rsa;
  int iVar2;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xce,7,"ssl/ssl_rsa.c",0xae);
    BIO_free((BIO *)0x0);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xce,2,"ssl/ssl_rsa.c",0xb3);
  }
  else {
    if (type == 2) {
      rsa = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      iVar2 = 0xd;
    }
    else {
      if (type != 1) {
        ERR_put_error(0x14,0xce,0x7c,"ssl/ssl_rsa.c",0xbf);
        goto LAB_001035ca;
      }
      rsa = PEM_read_bio_RSAPrivateKey(bp,(RSA **)0x0,ssl[9].psk_server_callback,ssl[9].ctx);
      iVar2 = 9;
    }
    if (rsa != (RSA *)0x0) {
      iVar2 = SSL_use_RSAPrivateKey(ssl,rsa);
      RSA_free(rsa);
      BIO_free(bp);
      return iVar2;
    }
    ERR_put_error(0x14,0xce,iVar2,"ssl/ssl_rsa.c",0xc3);
  }
LAB_001035ca:
  BIO_free(bp);
  return 0;
}

