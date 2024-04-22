
undefined4 updatewindow(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  void *__dest;
  uint uVar1;
  uint uVar2;
  int iVar3;
  size_t __n;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  __dest = *(void **)(iVar3 + 0x34);
  if (__dest == (void *)0x0) {
    __dest = (void *)(**(code **)(param_1 + 0x20))
                               (*(undefined4 *)(param_1 + 0x28),
                                1 << (*(uint *)(iVar3 + 0x24) & 0xff),1,*(code **)(param_1 + 0x20),
                                param_4);
    *(void **)(iVar3 + 0x34) = __dest;
    if (__dest == (void *)0x0) {
      return 1;
    }
  }
  uVar1 = *(uint *)(iVar3 + 0x28);
  if (uVar1 == 0) {
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    uVar1 = 1 << (*(uint *)(iVar3 + 0x24) & 0xff);
    *(uint *)(iVar3 + 0x28) = uVar1;
  }
  if (uVar1 <= param_3) {
    memcpy(__dest,(void *)(param_2 - uVar1),uVar1);
    *(undefined4 *)(iVar3 + 0x30) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0x28);
    return 0;
  }
  uVar1 = uVar1 - *(int *)(iVar3 + 0x30);
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  memcpy((void *)((int)__dest + *(int *)(iVar3 + 0x30)),(void *)(param_2 - param_3),uVar1);
  __n = param_3 - uVar1;
  if (__n != 0) {
    memcpy(*(void **)(iVar3 + 0x34),(void *)(param_2 - __n),__n);
    *(size_t *)(iVar3 + 0x30) = __n;
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0x28);
    return 0;
  }
  uVar2 = uVar1 + *(int *)(iVar3 + 0x30);
  *(uint *)(iVar3 + 0x30) = uVar2;
  if (uVar2 == *(uint *)(iVar3 + 0x28)) {
    *(undefined4 *)(iVar3 + 0x30) = 0;
  }
  if (*(uint *)(iVar3 + 0x28) <= *(uint *)(iVar3 + 0x2c)) {
    return 0;
  }
  *(uint *)(iVar3 + 0x2c) = uVar1 + *(uint *)(iVar3 + 0x2c);
  return 0;
}

