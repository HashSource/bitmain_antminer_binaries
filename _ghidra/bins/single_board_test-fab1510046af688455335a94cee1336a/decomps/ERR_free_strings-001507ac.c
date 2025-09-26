
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_free_strings(void)

{
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  (*(code *)err_fns[1])();
  return;
}

