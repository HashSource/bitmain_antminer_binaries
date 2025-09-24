
void SRP_VBASE_free(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != (undefined4 *)0x0) {
    OPENSSL_sk_pop_free(*param_1,0x162b99,&_GLOBAL_OFFSET_TABLE_,0x888,param_4);
    OPENSSL_sk_free(param_1[1]);
    CRYPTO_free((void *)param_1[2]);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

