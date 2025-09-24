
void ossl_init_engine_rdrand_ossl_(void)

{
  engine_load_rdrand_int();
  ossl_init_engine_rdrand_ossl_ret_ = 1;
  return;
}

