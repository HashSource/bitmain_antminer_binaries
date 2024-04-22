
int SSL_use_RSAPrivateKey_file(SSL *ssl,char *file,int type)

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
    ERR_put_error(0x14,0xce,7,DAT_000818a8,0xee);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xce,2,DAT_000818a8,0xf3);
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
        ERR_put_error(0x14,0xce,0x7c,DAT_000818a8,0x100);
        goto LAB_000817d0;
      }
      r = PEM_read_bio_RSAPrivateKey
                    (bp,(RSA **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                     *(void **)(ssl->psk_server_callback + 0x70));
      iVar2 = 9;
    }
    if (r == (RSA *)0x0) {
      ERR_put_error(0x14,0xce,iVar2,DAT_000818a8,0x104);
      iVar2 = 0;
    }
    else {
      iVar2 = ssl_cert_inst(&ssl->cert);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xcc,0x41,DAT_000818a8,0x9a);
        iVar2 = 0;
      }
      else {
        pkey = EVP_PKEY_new();
        if (pkey == (EVP_PKEY *)0x0) {
          ERR_put_error(0x14,0xcc,6,DAT_000818a8,0x9e);
          iVar2 = 0;
        }
        else {
          RSA_up_ref(r);
          EVP_PKEY_assign(pkey,6,r);
          iVar2 = ssl_set_pkey(ssl->cert,pkey);
          EVP_PKEY_free(pkey);
        }
      }
      RSA_free(r);
    }
  }
LAB_000817d0:
  BIO_free(bp);
  return iVar2;
}

