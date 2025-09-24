
undefined4 ecx_get_priv_key(int param_1,void *param_2,size_t *param_3)

{
  size_t sVar1;
  int iVar2;
  void *__src;
  uint uVar3;
  
  if (param_2 == (void *)0x0) {
    iVar2 = **(int **)(param_1 + 0xc);
    if (iVar2 == 0x40a || iVar2 == 0x43f) {
      sVar1 = 0x20;
    }
    else if (iVar2 == 0x40b) {
      sVar1 = 0x38;
    }
    else {
      sVar1 = 0x39;
    }
    *param_3 = sVar1;
    return 1;
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    __src = *(void **)(*(int *)(param_1 + 0x18) + 0x3c);
    if (__src == (void *)0x0) {
      return 0;
    }
    uVar3 = *param_3;
    iVar2 = **(int **)(param_1 + 0xc);
    if (iVar2 == 0x40a || iVar2 == 0x43f) {
      if (uVar3 < 0x20) {
        return 0;
      }
      sVar1 = 0x20;
    }
    else if (iVar2 == 0x40b) {
      if (uVar3 < 0x38) {
        return 0;
      }
      sVar1 = 0x38;
    }
    else {
      if (uVar3 < 0x39) {
        return 0;
      }
      sVar1 = 0x39;
    }
    *param_3 = sVar1;
    memcpy(param_2,__src,sVar1);
    return 1;
  }
  return 0;
}

