
int SSL_CTX_use_certificate_chain_file(SSL_CTX *ctx,char *file)

{
  code *pcVar1;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  X509 *x;
  int iVar3;
  ulong uVar4;
  X509 *a;
  int iVar5;
  undefined1 *cb;
  _func_3233 *u;
  
  ERR_clear_error();
  if (ctx == (SSL_CTX *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0x10db28);
    (*pcVar1)();
  }
  cb = (undefined1 *)ctx->default_passwd_callback_userdata;
  u = ctx->client_cert_cb;
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xdc,7,"ssl/ssl_rsa.c",0x24f);
    x = (X509 *)0x0;
    iVar5 = 0;
  }
  else {
    lVar2 = BIO_ctrl(bp,0x6c,3,file);
    if (lVar2 < 1) {
      x = (X509 *)0x0;
      ERR_put_error(0x14,0xdc,2,"ssl/ssl_rsa.c",0x254);
      iVar5 = 0;
    }
    else {
      x = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,cb,u);
      if (x == (X509 *)0x0) {
        ERR_put_error(0x14,0xdc,9,"ssl/ssl_rsa.c",0x25b);
        iVar5 = 0;
      }
      else {
        iVar3 = SSL_CTX_use_certificate(ctx,x);
        uVar4 = ERR_peek_error();
        iVar5 = iVar3;
        if (iVar3 != 0) {
          iVar5 = 1;
        }
        if (uVar4 != 0) {
          iVar5 = 0;
        }
        if ((iVar5 != 0) && (iVar5 = SSL_CTX_ctrl(ctx,0x58,0,(void *)0x0), iVar5 != 0)) {
          do {
            a = PEM_read_bio_X509(bp,(X509 **)0x0,cb,u);
            if (a == (X509 *)0x0) {
              uVar4 = ERR_peek_last_error();
              if ((uVar4 >> 0x18 == 9) && ((uVar4 & 0xfff) == 0x6c)) {
                ERR_clear_error();
                iVar5 = iVar3;
              }
              else {
                iVar5 = 0;
              }
              goto LAB_0010dab6;
            }
            lVar2 = SSL_CTX_ctrl(ctx,0x59,0,a);
          } while (lVar2 != 0);
          X509_free(a);
          iVar5 = 0;
        }
      }
    }
  }
LAB_0010dab6:
  X509_free(x);
  BIO_free(bp);
  return iVar5;
}

