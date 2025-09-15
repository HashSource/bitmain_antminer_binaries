
void gost_param_free(void)

{
  if (gost_params != (void *)0x0) {
    CRYPTO_free(gost_params);
    gost_params = (void *)0x0;
  }
  return;
}

