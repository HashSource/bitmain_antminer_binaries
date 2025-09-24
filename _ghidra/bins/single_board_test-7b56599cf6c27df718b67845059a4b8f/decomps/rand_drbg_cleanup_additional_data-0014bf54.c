
void rand_drbg_cleanup_additional_data(undefined4 *param_1,void *param_2)

{
  *param_1 = param_2;
  OPENSSL_cleanse(param_2,param_1[1]);
  param_1[1] = 0;
  return;
}

