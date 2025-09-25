
uint extension_is_relevant(int *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  if ((param_3 & 0x800) == 0) {
    if ((*(uint *)(((int *)param_1[1])[0x19] + 0x30) & 8) != 0) {
      bVar3 = true;
      if ((int)(param_2 << 0x1d) < 0) {
        return 0;
      }
      bVar1 = false;
      goto LAB_000e2da6;
    }
    iVar5 = *(int *)param_1[1];
    iVar4 = iVar5 + -0x10000;
    if (iVar4 != 0) {
      iVar4 = 1;
    }
    if (iVar5 < 0x304) {
      iVar4 = 0;
    }
    if (iVar4 != 0) goto LAB_000e2dee;
    if (*param_1 == 0x300) {
      bVar3 = true;
      bVar1 = false;
      goto LAB_000e2e2a;
    }
    bVar3 = true;
LAB_000e2db0:
    if ((int)(param_2 << 0x1a) < 0) {
      if ((param_3 & 0x80) == 0) {
        return 0;
      }
      if (param_1[7] == 0) {
        bVar3 = false;
      }
      if (bVar3) {
        return 0;
      }
    }
  }
  else {
    if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
LAB_000e2dee:
      bVar3 = false;
      if (*param_1 == 0x300) {
        bVar1 = true;
        if ((param_2 & 8) == 0) {
          return 0;
        }
        goto LAB_000e2dae;
      }
    }
    else {
      bVar3 = false;
      bVar1 = true;
      if ((int)(param_2 << 0x1d) < 0) {
        return 0;
      }
LAB_000e2da6:
      if (*param_1 == 0x300) {
LAB_000e2e2a:
        if ((param_2 & 8) == 0) {
          return 0;
        }
      }
LAB_000e2dae:
      if (!bVar1) goto LAB_000e2db0;
    }
    if ((int)(param_2 << 0x1b) < 0) {
      return 0;
    }
  }
  uVar2 = 1;
  if (param_1[0x23] != 0) {
    uVar2 = ((param_2 ^ 0x40) << 0x19) >> 0x1f;
  }
  return uVar2;
}

