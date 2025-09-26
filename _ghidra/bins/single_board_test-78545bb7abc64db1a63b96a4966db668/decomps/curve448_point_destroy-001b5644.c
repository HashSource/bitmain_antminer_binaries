
void curve448_point_destroy(void *param_1)

{
  OPENSSL_cleanse(param_1,0x100);
  return;
}

