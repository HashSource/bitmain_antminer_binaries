
undefined4 OPENSSL_DIR_end(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != (undefined4 *)0x0) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    iVar1 = closedir(*(DIR **)*param_1);
    free((void *)*param_1);
    if (iVar1 == -1) {
      return 0;
    }
    if (iVar1 == 0) {
      return 1;
    }
  }
  piVar2 = __errno_location();
  *piVar2 = 0x16;
  return 0;
}

