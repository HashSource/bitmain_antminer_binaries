
void ossl_init_engine_dynamic_ossl_(void)

{
  engine_load_dynamic_int();
  ossl_init_engine_dynamic_ossl_ret_ = 1;
  return;
}

