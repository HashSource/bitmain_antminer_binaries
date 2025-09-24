
undefined4 OPENSSL_sk_shift(int *param_1)

{
  undefined4 *__dest;
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_1;
  if (iVar1 != 0) {
    __dest = (undefined4 *)param_1[1];
    uVar2 = *__dest;
    if (iVar1 != 1) {
      memmove(__dest,__dest + 1,(iVar1 + -1) * 4);
      iVar1 = *param_1;
    }
    *param_1 = iVar1 + -1;
    return uVar2;
  }
  return 0;
}

