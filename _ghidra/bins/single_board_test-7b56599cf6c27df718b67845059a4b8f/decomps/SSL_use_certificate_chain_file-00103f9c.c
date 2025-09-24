
uint SSL_use_certificate_chain_file(SSL *param_1,void *param_2)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509 *x;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  X509 *a;
  _func_3296 *cb;
  SSL_CTX *u;
  
  ERR_clear_error();
  cb = param_1[9].psk_server_callback;
  u = param_1[9].ctx;
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xdc,7,"ssl/ssl_rsa.c",0x24f);
    x = (X509 *)0x0;
    uVar4 = 0;
  }
  else {
    lVar1 = BIO_ctrl(bp,0x6c,3,param_2);
    if (lVar1 < 1) {
      x = (X509 *)0x0;
      ERR_put_error(0x14,0xdc,2,"ssl/ssl_rsa.c",0x254);
      uVar4 = 0;
    }
    else {
      x = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,cb,u);
      if (x == (X509 *)0x0) {
        ERR_put_error(0x14,0xdc,9,"ssl/ssl_rsa.c",0x25b);
        uVar4 = 0;
      }
      else {
        uVar2 = SSL_use_certificate(param_1,x);
        uVar3 = ERR_peek_error();
        uVar4 = (uint)(uVar3 == 0);
        if (uVar2 == 0) {
          uVar4 = 0;
        }
        if ((uVar4 != 0) && (uVar4 = SSL_ctrl(param_1,0x58,0,(void *)0x0), uVar4 != 0)) {
          do {
            a = PEM_read_bio_X509(bp,(X509 **)0x0,cb,u);
            if (a == (X509 *)0x0) {
              uVar3 = ERR_peek_last_error();
              if ((uVar3 >> 0x18 == 9) && ((uVar3 & 0xfff) == 0x6c)) {
                ERR_clear_error();
                uVar4 = uVar2;
              }
              else {
                uVar4 = 0;
              }
              goto LAB_00104010;
            }
            lVar1 = SSL_ctrl(param_1,0x59,0,a);
          } while (lVar1 != 0);
          X509_free(a);
          uVar4 = 0;
        }
      }
    }
  }
LAB_00104010:
  X509_free(x);
  BIO_free(bp);
  return uVar4;
}

