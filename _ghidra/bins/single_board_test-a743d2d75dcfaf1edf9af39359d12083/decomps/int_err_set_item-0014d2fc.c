
_LHASH * int_err_set_item(void *param_1)

{
  _LHASH *lh;
  
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  lh = (_LHASH *)(*(code *)*err_fns)(1);
  if (lh != (_LHASH *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x19a);
    lh = (_LHASH *)lh_insert(lh,param_1);
    CRYPTO_lock(10,1,"err.c",0x19c);
  }
  return lh;
}

