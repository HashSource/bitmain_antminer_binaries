
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_get_ex_data_X509_STORE_CTX_idx(void)

{
  int iVar1;
  
  iVar1 = ssl_x509_store_ctx_idx_19563;
  if (ssl_x509_store_ctx_idx_19563 < 0) {
    CRYPTO_lock(9,0xc,"ssl_cert.c",0x94);
    if (ssl_x509_store_ctx_idx_19563 < 0) {
      ssl_x509_store_ctx_idx_19563 =
           X509_STORE_CTX_get_ex_new_index
                     (0,"SSL for verify callback",(undefined1 *)0x0,(undefined1 *)0x0,
                      (undefined1 *)0x0);
    }
    iVar1 = ssl_x509_store_ctx_idx_19563;
    CRYPTO_lock(10,0xc,"ssl_cert.c",0x9b);
  }
  return iVar1;
}

