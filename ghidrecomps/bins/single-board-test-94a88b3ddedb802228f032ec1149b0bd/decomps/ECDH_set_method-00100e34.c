
int ECDH_set_method(EC_KEY *param_1,ECDH_METHOD *param_2)

{
  free_func *free_func;
  void *data;
  void *pvVar1;
  
  free_func = DAT_00100eac;
  data = EC_KEY_get_key_method_data
                   (param_1,DAT_00100eb0,DAT_00100eac,(clear_free_func *)DAT_00100eac);
  if (data == (void *)0x0) {
    data = (void *)ECDH_DATA_new_method_constprop_0();
    if (data == (void *)0x0) {
      return 0;
    }
    pvVar1 = EC_KEY_insert_key_method_data
                       (param_1,data,DAT_00100eb0,free_func,(clear_free_func *)free_func);
    if (pvVar1 != (void *)0x0) {
      if (*(ENGINE **)((int)data + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)((int)data + 4));
      }
      CRYPTO_free_ex_data(0xd,data,(CRYPTO_EX_DATA *)((int)data + 0x10));
      OPENSSL_cleanse(data,0x18);
      CRYPTO_free(data);
      data = pvVar1;
    }
  }
  if (*(ENGINE **)((int)data + 4) != (ENGINE *)0x0) {
    ENGINE_finish(*(ENGINE **)((int)data + 4));
    *(undefined4 *)((int)data + 4) = 0;
  }
  *(ECDH_METHOD **)((int)data + 0xc) = param_2;
  return 1;
}

