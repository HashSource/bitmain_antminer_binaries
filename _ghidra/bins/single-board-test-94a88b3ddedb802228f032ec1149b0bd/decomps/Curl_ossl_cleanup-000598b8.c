
void Curl_ossl_cleanup(void)

{
  EVP_cleanup();
  ENGINE_cleanup();
  CRYPTO_cleanup_all_ex_data();
  ERR_free_strings();
  ERR_remove_thread_state((CRYPTO_THREADID *)0x0);
  CONF_modules_free();
  return;
}

