
int SSL_CTX_use_RSAPrivateKey_file(SSL_CTX *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  RSA *r;
  EVP_PKEY *pkey;
  int iVar2;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xb3,7,DAT_00081e48,0x217);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xb3,2,DAT_00081e48,0x21c);
    iVar2 = 0;
  }
  else {
    if (type == 2) {
      r = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      iVar2 = 0xd;
    }
    else {
      if (type != 1) {
        iVar2 = 0;
        ERR_put_error(0x14,0xb3,0x7c,DAT_00081e48,0x228);
        goto LAB_00081d6c;
      }
      r = PEM_read_bio_RSAPrivateKey
                    (bp,(RSA **)0x0,ctx->default_passwd_callback,
                     ctx->default_passwd_callback_userdata);
      iVar2 = 9;
    }
    if (r == (RSA *)0x0) {
      ERR_put_error(0x14,0xb3,iVar2,DAT_00081e48,0x22c);
      iVar2 = 0;
    }
    else {
      iVar2 = ssl_cert_inst(&ctx->cert);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xb1,0x41,DAT_00081e48,0x1fe);
        iVar2 = 0;
      }
      else {
        pkey = EVP_PKEY_new();
        if (pkey == (EVP_PKEY *)0x0) {
          ERR_put_error(0x14,0xb1,6,DAT_00081e48,0x202);
          iVar2 = 0;
        }
        else {
          RSA_up_ref(r);
          EVP_PKEY_assign(pkey,6,r);
          iVar2 = ssl_set_pkey(ctx->cert,pkey);
          EVP_PKEY_free(pkey);
        }
      }
      RSA_free(r);
    }
  }
LAB_00081d6c:
  BIO_free(bp);
  return iVar2;
}

