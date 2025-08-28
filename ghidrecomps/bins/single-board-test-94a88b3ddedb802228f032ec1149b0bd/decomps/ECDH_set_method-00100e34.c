
int ECDH_set_method(EC_KEY *param_1,ECDH_METHOD *param_2)

{
  void *data;
  void *pvVar1;
  
  data = EC_KEY_get_key_method_data
                   (param_1,(dup_func *)0x100e09,(free_func *)0x100d49,(clear_free_func *)0x100d49);
  if (data == (void *)0x0) {
    data = (void *)ECDH_DATA_new_method_constprop_0();
    if (data == (void *)0x0) {
      return 0;
    }
    pvVar1 = EC_KEY_insert_key_method_data
                       (param_1,data,(dup_func *)0x100e09,(free_func *)0x100d49,
                        (clear_free_func *)0x100d49);
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

