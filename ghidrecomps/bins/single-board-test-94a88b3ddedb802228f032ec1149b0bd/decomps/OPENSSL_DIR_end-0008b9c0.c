
undefined4 OPENSSL_DIR_end(void **param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != (void **)0x0) && ((DIR **)*param_1 != (DIR **)0x0)) {
                    /* WARNING: Load size is inaccurate */
    iVar1 = closedir(**param_1);
    free(*param_1);
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

