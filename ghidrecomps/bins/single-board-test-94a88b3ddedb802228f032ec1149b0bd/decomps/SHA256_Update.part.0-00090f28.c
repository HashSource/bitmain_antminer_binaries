
void SHA256_Update_part_0(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *__s;
  size_t __n;
  
  uVar4 = *(uint *)(param_1 + 0x20);
  iVar2 = *(int *)(param_1 + 0x24);
  uVar3 = uVar4 + param_3 * 8;
  iVar1 = *(int *)(param_1 + 0x68);
  *(uint *)(param_1 + 0x20) = uVar3;
  if (uVar3 < uVar4) {
    iVar2 = iVar2 + 1;
  }
  *(uint *)(param_1 + 0x24) = iVar2 + (param_3 >> 0x1d);
  if (iVar1 != 0) {
    __s = (void *)(param_1 + 0x28);
    if ((param_3 < 0x40) && (param_3 + iVar1 < 0x40)) {
      memcpy((void *)((int)__s + iVar1),param_2,param_3);
      *(uint *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + param_3;
      return;
    }
    __n = 0x40 - iVar1;
    memcpy((void *)((int)__s + iVar1),param_2,__n);
    param_3 = param_3 - __n;
    sha256_block_data_order(param_1,__s,1);
    *(undefined4 *)(param_1 + 0x68) = 0;
    param_2 = (void *)((int)param_2 + __n);
    memset(__s,0,0x40);
  }
  uVar3 = param_3 >> 6;
  if (uVar3 != 0) {
    uVar4 = param_3 & 0xffffffc0;
    param_3 = param_3 - uVar4;
    sha256_block_data_order(param_1,param_2,uVar3);
    param_2 = (void *)((int)param_2 + uVar4);
  }
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x68) = param_3;
    (*(code *)PTR_memcpy_00194250)(param_1 + 0x28,param_2,param_3);
    return;
  }
  return;
}

