
int SSL_CTX_use_certificate_chain_file(SSL_CTX *ctx,char *file)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509 *a;
  int iVar2;
  ulong uVar3;
  X509 *a_00;
  
  ERR_clear_error();
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xdc,7,DAT_000821b8,0x2a5);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xdc,2,DAT_000821b8,0x2aa);
  }
  else {
    a = PEM_read_bio_X509_AUX
                  (bp,(X509 **)0x0,ctx->default_passwd_callback,
                   ctx->default_passwd_callback_userdata);
    if (a != (X509 *)0x0) {
      iVar2 = ssl_cert_inst(&ctx->cert);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xab,0x41,DAT_000821b8,0x176);
        ERR_peek_error();
LAB_000820f2:
        iVar2 = 0;
      }
      else {
        iVar2 = ssl_set_cert(ctx->cert,a);
        uVar3 = ERR_peek_error();
        if ((uVar3 != 0) || (iVar2 == 0)) goto LAB_000820f2;
        SSL_CTX_ctrl(ctx,0x58,0,(void *)0x0);
        do {
          a_00 = PEM_read_bio_X509(bp,(X509 **)0x0,ctx->default_passwd_callback,
                                   ctx->default_passwd_callback_userdata);
          if (a_00 == (X509 *)0x0) {
            uVar3 = ERR_peek_last_error();
            if ((uVar3 >> 0x18 != 9) || ((uVar3 & 0xfff) != 0x6c)) goto LAB_000820f2;
            ERR_clear_error();
            goto LAB_000820f4;
          }
          lVar1 = SSL_CTX_ctrl(ctx,0x59,0,a_00);
        } while (lVar1 != 0);
        X509_free(a_00);
        iVar2 = 0;
      }
LAB_000820f4:
      X509_free(a);
      goto LAB_000820fa;
    }
    ERR_put_error(0x14,0xdc,9,DAT_000821b8,0x2b1);
  }
  iVar2 = 0;
LAB_000820fa:
  BIO_free(bp);
  return iVar2;
}

