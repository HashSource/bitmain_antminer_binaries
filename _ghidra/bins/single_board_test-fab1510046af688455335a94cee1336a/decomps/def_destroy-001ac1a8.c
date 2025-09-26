
undefined4 def_destroy(CONF *param_1)

{
  if (param_1 != (CONF *)0x0) {
    _CONF_free_data(param_1);
    CRYPTO_free(param_1);
    return 1;
  }
  return 0;
}

