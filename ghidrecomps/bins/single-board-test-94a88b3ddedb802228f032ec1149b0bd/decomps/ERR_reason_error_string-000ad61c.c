
char * ERR_reason_error_string(ulong e)

{
  int iVar1;
  uint local_20 [3];
  
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_20[0] = e & 0xff000fff;
  iVar1 = (*(code *)err_fns[2])(local_20);
  if ((iVar1 == 0) && (local_20[0] = e & 0xfff, iVar1 = (*(code *)err_fns[2])(local_20), iVar1 == 0)
     ) {
    return (char *)0x0;
  }
  return *(char **)(iVar1 + 4);
}

