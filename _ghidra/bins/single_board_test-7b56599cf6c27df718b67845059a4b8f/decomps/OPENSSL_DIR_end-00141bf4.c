
undefined4 OPENSSL_DIR_end(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if ((param_1 != (undefined4 *)0x0) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    iVar1 = closedir(*(DIR **)*param_1);
    free((void *)*param_1);
    if (iVar1 == -1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
      if (iVar1 != 0) goto LAB_00141c1c;
    }
    return uVar3;
  }
LAB_00141c1c:
  piVar2 = __errno_location();
  *piVar2 = 0x16;
  return 0;
}

