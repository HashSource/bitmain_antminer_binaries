
void ossl_init_config_ossl_(void)

{
  ossl_init_config_ossl_ret_ = openssl_config_int(conf_settings);
  return;
}

