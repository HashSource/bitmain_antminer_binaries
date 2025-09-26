
int ssl_get_algorithm2(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x7c) != 0) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210), iVar2 != 0)) {
    iVar1 = *(int *)(iVar2 + 0x34);
    if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1d) {
      if (iVar1 == 0x505 && (*(uint *)(iVar2 + 0x10) & 0x1c8) != 0) {
        iVar1 = 0x909;
      }
      return iVar1;
    }
    if (iVar1 == 0x909) {
      iVar1 = 0x404;
    }
    return iVar1;
  }
  return -1;
}

