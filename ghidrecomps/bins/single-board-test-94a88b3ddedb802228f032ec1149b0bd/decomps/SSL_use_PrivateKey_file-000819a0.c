
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
    ERR_put_error(0x14,0xcb,7,DAT_00081a88,0x13b);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xcb,2,DAT_00081a88,0x140);
    iVar2 = 0;
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey
                       (bp,(EVP_PKEY **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                        *(void **)(ssl->psk_server_callback + 0x70));
      iVar2 = 9;
    }
    else {
      if (type != 2) {
        iVar2 = 0;
        ERR_put_error(0x14,0xcb,0x7c,DAT_00081a88,0x14d);
        goto LAB_000819e2;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      iVar2 = 0xd;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xcb,iVar2,DAT_00081a88,0x151);
      iVar2 = 0;
    }
    else {
      iVar2 = ssl_cert_inst(&ssl->cert);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xc9,0x41,DAT_00081a88,299);
        iVar2 = 0;
      }
      else {
        iVar2 = ssl_set_pkey(ssl->cert,pkey);
      }
      EVP_PKEY_free(pkey);
    }
  }
LAB_000819e2:
  BIO_free(bp);
  return iVar2;
}

