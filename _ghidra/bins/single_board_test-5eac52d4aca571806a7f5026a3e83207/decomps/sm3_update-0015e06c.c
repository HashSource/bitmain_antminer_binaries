
undefined4 sm3_update(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  void *__s;
  size_t __n;
  
  if (param_3 == 0) {
    return 1;
  }
  uVar3 = *(uint *)(param_1 + 0x20);
  uVar2 = uVar3 + param_3 * 8;
  iVar4 = *(int *)(param_1 + 0x24);
  iVar1 = *(int *)(param_1 + 0x68);
  *(uint *)(param_1 + 0x20) = uVar2;
  if (uVar2 < uVar3) {
    iVar4 = iVar4 + 1;
  }
  *(size_t *)(param_1 + 0x24) = iVar4 + (param_3 >> 0x1d);
  if (iVar1 == 0) {
    uVar2 = param_3 >> 6;
    if (uVar2 == 0) goto LAB_0015e098;
LAB_0015e0f6:
    param_3 = param_3 + uVar2 * -0x40;
    sm3_block_data_order(param_1,param_2,uVar2);
    param_2 = (void *)((int)param_2 + uVar2 * 0x40);
  }
  else {
    __s = (void *)(param_1 + 0x28);
    if ((param_3 < 0x40) && (param_3 + iVar1 < 0x40)) {
      memcpy((void *)(iVar1 + (int)__s),param_2,param_3);
      *(size_t *)(param_1 + 0x68) = param_3 + *(int *)(param_1 + 0x68);
      return 1;
    }
    __n = 0x40 - iVar1;
    memcpy((void *)(iVar1 + (int)__s),param_2,__n);
    param_3 = param_3 - __n;
    sm3_block_data_order(param_1,__s,1);
    *(undefined4 *)(param_1 + 0x68) = 0;
    memset(__s,0,0x40);
    uVar2 = param_3 >> 6;
    param_2 = (void *)((int)param_2 + __n);
    if (uVar2 != 0) goto LAB_0015e0f6;
  }
  if (param_3 == 0) {
    return 1;
  }
LAB_0015e098:
  *(size_t *)(param_1 + 0x68) = param_3;
  memcpy((void *)(param_1 + 0x28),param_2,param_3);
  return 1;
}

