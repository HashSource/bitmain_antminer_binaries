
void o_names_init_ossl_(void)

{
  int iVar1;
  
  CRYPTO_mem_ctrl(3);
  names_lh = 0;
  obj_lock = CRYPTO_THREAD_lock_new();
  if (obj_lock != 0) {
    names_lh = OPENSSL_LH_new(0x141f65,0x142059);
  }
  iVar1 = names_lh;
  if (names_lh == 0) {
    CRYPTO_THREAD_lock_free(obj_lock);
    obj_lock = iVar1;
  }
  CRYPTO_mem_ctrl(2);
  o_names_init_ossl_ret_ = names_lh;
  if ((names_lh != 0) && (o_names_init_ossl_ret_ = obj_lock, obj_lock != 0)) {
    o_names_init_ossl_ret_ = 1;
  }
  return;
}

