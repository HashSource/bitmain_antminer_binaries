
char * ERR_func_error_string(ulong e)

{
  char *pcVar1;
  uint local_18 [3];
  
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_18[0] = e & 0xfffff000;
  pcVar1 = (char *)(*(code *)err_fns[2])(local_18);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = *(char **)(pcVar1 + 4);
  }
  return pcVar1;
}

