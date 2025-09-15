
void * int_thread_set_item(void *param_1)

{
  void *pvVar1;
  _LHASH *local_14;
  
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_14 = (_LHASH *)(*(code *)err_fns[5])(1);
  if (local_14 == (_LHASH *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    CRYPTO_lock(9,1,"err.c",0x205);
    pvVar1 = lh_insert(local_14,param_1);
    CRYPTO_lock(10,1,"err.c",0x207);
    (*(code *)err_fns[6])(&local_14);
  }
  return pvVar1;
}

