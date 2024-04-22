
void * EC_KEY_insert_key_method_data
                 (EC_KEY *key,void *data,dup_func *dup_func,free_func *free_func,
                 clear_free_func *clear_free_func)

{
  void *pvVar1;
  
  CRYPTO_lock(9,0x21,DAT_000a38cc,0x209);
  pvVar1 = (void *)EC_EX_DATA_get_data(*(undefined4 *)(key + 0x20),dup_func,free_func,
                                       clear_free_func);
  if (pvVar1 == (void *)0x0) {
    EC_EX_DATA_set_data(key + 0x20,data,dup_func,free_func,clear_free_func);
  }
  CRYPTO_lock(10,0x21,DAT_000a38cc,0x210);
  return pvVar1;
}

