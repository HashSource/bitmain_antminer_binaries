
void crypto_cleanup_all_ex_data_int(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)ex_data;
  do {
    OPENSSL_sk_pop_free(*puVar1,0x133945);
    puVar2 = puVar1 + 1;
    *puVar1 = 0;
    puVar1 = puVar2;
  } while (puVar2 != &ex_data_init);
  CRYPTO_THREAD_lock_free(ex_data_lock);
  ex_data_lock = 0;
  return;
}

