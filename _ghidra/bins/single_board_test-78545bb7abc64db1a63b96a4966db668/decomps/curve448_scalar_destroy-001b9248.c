
void curve448_scalar_destroy(void *param_1)

{
  OPENSSL_cleanse(param_1,0x38);
  return;
}

