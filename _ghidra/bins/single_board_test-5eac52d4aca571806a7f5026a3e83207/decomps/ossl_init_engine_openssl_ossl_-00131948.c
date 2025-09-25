
void ossl_init_engine_openssl_ossl_(void)

{
  engine_load_openssl_int();
  ossl_init_engine_openssl_ossl_ret_ = 1;
  return;
}

