
void ossl_init_add_all_ciphers_ossl_(void)

{
  openssl_add_all_ciphers_int();
  ossl_init_add_all_ciphers_ossl_ret_ = 1;
  return;
}

