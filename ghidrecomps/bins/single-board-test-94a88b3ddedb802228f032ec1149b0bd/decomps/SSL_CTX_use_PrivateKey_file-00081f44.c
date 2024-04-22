
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
    ERR_put_error(0x14,0xb0,7,DAT_00082028,0x261);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xb0,2,DAT_00082028,0x266);
    iVar2 = 0;
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey
                       (bp,(EVP_PKEY **)0x0,ctx->default_passwd_callback,
                        ctx->default_passwd_callback_userdata);
      iVar2 = 9;
    }
    else {
      if (type != 2) {
        iVar2 = 0;
        ERR_put_error(0x14,0xb0,0x7c,DAT_00082028,0x272);
        goto LAB_00081f86;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      iVar2 = 0xd;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xb0,iVar2,DAT_00082028,0x276);
      iVar2 = 0;
    }
    else {
      iVar2 = ssl_cert_inst(&ctx->cert);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xae,0x41,DAT_00082028,0x252);
        iVar2 = 0;
      }
      else {
        iVar2 = ssl_set_pkey(ctx->cert,pkey);
      }
      EVP_PKEY_free(pkey);
    }
  }
LAB_00081f86:
  BIO_free(bp);
  return iVar2;
}

