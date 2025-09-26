
int ECDH_set_ex_data(EC_KEY *d,int idx,void *arg)

{
  void *data;
  int iVar1;
  void *pvVar2;
  
  data = EC_KEY_get_key_method_data
                   (d,(dup_func *)0x199569,(free_func *)0x1994a9,(clear_free_func *)0x1994a9);
  if (data == (void *)0x0) {
    data = (void *)ECDH_DATA_new_method_constprop_0();
    if (data == (void *)0x0) {
      return 0;
    }
    pvVar2 = EC_KEY_insert_key_method_data
                       (d,data,(dup_func *)0x199569,(free_func *)0x1994a9,
                        (clear_free_func *)0x1994a9);
    if (pvVar2 != (void *)0x0) {
      if (*(ENGINE **)((int)data + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)((int)data + 4));
      }
      CRYPTO_free_ex_data(0xd,data,(CRYPTO_EX_DATA *)((int)data + 0x10));
      OPENSSL_cleanse(data,0x18);
      CRYPTO_free(data);
      data = pvVar2;
    }
  }
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)((int)data + 0x10),idx,arg);
  return iVar1;
}

