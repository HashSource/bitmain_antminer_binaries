
void ossl_init_add_all_digests_ossl_(void)

{
  openssl_add_all_digests_int();
  ossl_init_add_all_digests_ossl_ret_ = 1;
  return;
}

