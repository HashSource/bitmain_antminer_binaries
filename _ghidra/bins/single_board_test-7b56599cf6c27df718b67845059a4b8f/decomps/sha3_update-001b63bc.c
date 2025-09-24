
undefined4 sha3_update(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    return 1;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar2 + 0xd0);
  uVar3 = *(uint *)(iVar2 + 200);
  if (iVar1 == 0) {
    if (param_3 < uVar3) {
      iVar1 = 0;
      goto LAB_001b6414;
    }
LAB_001b6432:
    uVar4 = SHA3_absorb(iVar2,param_2,param_3,uVar3);
  }
  else {
    uVar4 = uVar3 - iVar1;
    if (param_3 < uVar4) {
      memcpy((void *)(iVar1 + iVar2 + 0xd4),param_2,param_3);
      *(size_t *)(iVar2 + 0xd0) = param_3 + *(int *)(iVar2 + 0xd0);
      return 1;
    }
    param_3 = param_3 - uVar4;
    memcpy((void *)(iVar1 + iVar2 + 0xd4),param_2,uVar4);
    SHA3_absorb(iVar2,iVar2 + 0xd4,uVar3,uVar3);
    param_2 = (void *)((int)param_2 + uVar4);
    *(undefined4 *)(iVar2 + 0xd0) = 0;
    uVar4 = param_3;
    if (uVar3 <= param_3) goto LAB_001b6432;
  }
  iVar1 = param_3 - uVar4;
  param_3 = uVar4;
  if (uVar4 == 0) {
    return 1;
  }
LAB_001b6414:
  memcpy((void *)(iVar2 + 0xd4),(void *)(iVar1 + (int)param_2),param_3);
  *(size_t *)(iVar2 + 0xd0) = param_3;
  return 1;
}

