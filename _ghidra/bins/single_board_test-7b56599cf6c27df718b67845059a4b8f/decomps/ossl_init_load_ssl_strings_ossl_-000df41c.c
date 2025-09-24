
void ossl_init_load_ssl_strings_ossl_(void)

{
  ERR_load_SSL_strings();
  ossl_init_load_ssl_strings_ossl_ret_ = 1;
  return;
}

