
void * ecdsa_check(EC_KEY *param_1)

{
  free_func *free_func;
  void *data;
  void *pvVar1;
  
  free_func = DAT_000ff938;
  data = EC_KEY_get_key_method_data
                   (param_1,DAT_000ff93c,DAT_000ff938,(clear_free_func *)DAT_000ff938);
  if ((data == (void *)0x0) &&
     (data = (void *)ECDSA_DATA_new_method_constprop_0(), data != (void *)0x0)) {
    pvVar1 = EC_KEY_insert_key_method_data
                       (param_1,data,DAT_000ff93c,free_func,(clear_free_func *)free_func);
    if (pvVar1 != (void *)0x0) {
      if (*(ENGINE **)((int)data + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)((int)data + 4));
      }
      CRYPTO_free_ex_data(0xc,data,(CRYPTO_EX_DATA *)((int)data + 0x10));
      OPENSSL_cleanse(data,0x18);
      CRYPTO_free(data);
      data = pvVar1;
    }
  }
  return data;
}

