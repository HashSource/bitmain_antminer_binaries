
void * ECDSA_get_ex_data(EC_KEY *d,int idx)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = EC_KEY_get_key_method_data
                     (d,(dup_func *)0x19aacd,(free_func *)0x19aa0d,(clear_free_func *)0x19aa0d);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)ECDSA_DATA_new_method_constprop_0();
    if (pvVar1 == (void *)0x0) {
      return (void *)0x0;
    }
    pvVar2 = EC_KEY_insert_key_method_data
                       (d,pvVar1,(dup_func *)0x19aacd,(free_func *)0x19aa0d,
                        (clear_free_func *)0x19aa0d);
    if (pvVar2 != (void *)0x0) {
      if (*(ENGINE **)((int)pvVar1 + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)((int)pvVar1 + 4));
      }
      CRYPTO_free_ex_data(0xc,pvVar1,(CRYPTO_EX_DATA *)((int)pvVar1 + 0x10));
      OPENSSL_cleanse(pvVar1,0x18);
      CRYPTO_free(pvVar1);
      pvVar1 = pvVar2;
    }
  }
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)((int)pvVar1 + 0x10),idx);
  return pvVar1;
}

