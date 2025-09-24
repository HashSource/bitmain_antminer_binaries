
void OBJ_NAME_cleanup(int type)

{
  undefined4 uVar1;
  
  if (names_lh == 0) {
    return;
  }
  free_type = type;
  uVar1 = OPENSSL_LH_get_down_load();
  OPENSSL_LH_set_down_load(names_lh,0);
  OPENSSL_LH_doall(names_lh,0x1423d9);
  if (-1 < type) {
    OPENSSL_LH_set_down_load(names_lh,uVar1);
    return;
  }
  OPENSSL_LH_free(names_lh);
  OPENSSL_sk_pop_free(name_funcs_stack,0x142011);
  CRYPTO_THREAD_lock_free(obj_lock);
  names_lh = 0;
  name_funcs_stack = 0;
  obj_lock = 0;
  return;
}

