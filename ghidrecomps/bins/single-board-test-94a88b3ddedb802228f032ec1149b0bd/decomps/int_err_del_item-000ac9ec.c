
_LHASH * int_err_del_item(void *param_1)

{
  _LHASH *lh;
  
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  lh = (_LHASH *)(*(code *)*err_fns)(0);
  if (lh != (_LHASH *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x1ab);
    lh = (_LHASH *)lh_delete(lh,param_1);
    CRYPTO_lock(10,1,"err.c",0x1ad);
  }
  return lh;
}

