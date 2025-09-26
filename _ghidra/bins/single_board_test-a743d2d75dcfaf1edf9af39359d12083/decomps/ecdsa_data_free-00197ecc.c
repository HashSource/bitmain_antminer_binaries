
void ecdsa_data_free(void *param_1)

{
  if (*(ENGINE **)((int)param_1 + 4) != (ENGINE *)0x0) {
    ENGINE_finish(*(ENGINE **)((int)param_1 + 4));
  }
  CRYPTO_free_ex_data(0xc,param_1,(CRYPTO_EX_DATA *)((int)param_1 + 0x10));
  OPENSSL_cleanse(param_1,0x18);
  CRYPTO_free(param_1);
  return;
}

