
void OPENSSL_cleanup(void)

{
  undefined4 *ptr;
  int *ptr_00;
  undefined4 *puVar1;
  undefined4 local_14;
  
  if (base_inited == 0) {
    return;
  }
  if (stopped != 0) {
    return;
  }
  stopped = 1;
  ptr_00 = (int *)CRYPTO_THREAD_get_local(&destructor_key);
  CRYPTO_THREAD_set_local(&destructor_key,0);
  ptr = stop_handlers;
  if (ptr_00 != (int *)0x0) {
    if (*ptr_00 != 0) {
      async_delete_thread_state();
    }
    if (ptr_00[1] != 0) {
      err_delete_thread_state();
    }
    if (ptr_00[2] != 0) {
      drbg_delete_thread_state();
    }
    CRYPTO_free(ptr_00);
    ptr = stop_handlers;
  }
  while (ptr != (undefined4 *)0x0) {
    (*(code *)*ptr)();
    puVar1 = (undefined4 *)ptr[1];
    CRYPTO_free(ptr);
    ptr = puVar1;
  }
  stop_handlers = (undefined4 *)0x0;
  CRYPTO_THREAD_lock_free(init_lock);
  init_lock = 0;
  if (zlib_inited != 0) {
    comp_zlib_cleanup_int();
  }
  if (async_inited != 0) {
    async_deinit();
  }
  local_14 = destructor_key;
  destructor_key = 0xffffffff;
  CRYPTO_THREAD_cleanup_local(&local_14);
  rand_cleanup_int();
  rand_drbg_cleanup_int();
  conf_modules_free_int();
  engine_cleanup_int();
  ossl_store_cleanup_int();
  crypto_cleanup_all_ex_data_int();
  bio_cleanup();
  evp_cleanup_int();
  obj_cleanup_int();
  err_cleanup();
  CRYPTO_secure_malloc_done();
  base_inited = 0;
  return;
}

