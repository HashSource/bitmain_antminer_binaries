
void ERR_release_err_state_table(lhash_st_ERR_STATE **hash)

{
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  (*(code *)err_fns[6])(hash);
  return;
}

