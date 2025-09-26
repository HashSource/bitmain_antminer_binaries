
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STATE * ERR_get_err_state_table(void)

{
  lhash_st_ERR_STATE *plVar1;
  
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  plVar1 = (lhash_st_ERR_STATE *)(*(code *)err_fns[5])(0);
  return plVar1;
}

