
int SSL_use_PrivateKey(SSL *ssl,EVP_PKEY *pkey)

{
  int iVar1;
  
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xc9,0x43,DAT_0008199c,0x127);
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 != 0) {
      iVar1 = ssl_set_pkey(ssl->cert,pkey);
      return iVar1;
    }
    ERR_put_error(0x14,0xc9,0x41,DAT_0008199c,299);
  }
  return 0;
}

