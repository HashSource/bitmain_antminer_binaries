
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_get_ex_data_X509_STORE_CTX_idx(void)

{
  int iVar1;
  
  iVar1 = CRYPTO_THREAD_run_once(&ssl_x509_store_ctx_once,0xdbf5d);
  if ((iVar1 != 0) && (ssl_x509_store_ctx_init_ossl_ret_ != 0)) {
    return ssl_x509_store_ctx_idx;
  }
  return -1;
}

