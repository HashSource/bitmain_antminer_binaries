
void engine_cleanup_cb_free(code **param_1)

{
  (**param_1)();
  CRYPTO_free(param_1);
  return;
}

