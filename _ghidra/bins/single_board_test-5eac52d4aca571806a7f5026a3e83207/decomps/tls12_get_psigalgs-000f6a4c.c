
undefined4 tls12_get_psigalgs(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x404);
  uVar2 = *(uint *)(iVar3 + 0x10) & 0x30000;
  if (uVar2 == 0x20000) {
    *param_3 = 0x1fe49a;
    return 1;
  }
  if (uVar2 != 0x30000) {
    if (uVar2 == 0x10000) {
      uVar1 = 1;
      *param_3 = (int)&suiteb_sigalgs;
    }
    else if ((*(int *)(param_1 + 0x1c) == param_2) && (*(int *)(iVar3 + 0xd8) != 0)) {
      *param_3 = *(int *)(iVar3 + 0xd8);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x404) + 0xdc);
    }
    else {
      if (*(int *)(iVar3 + 0xd0) != 0) {
        *param_3 = *(int *)(iVar3 + 0xd0);
        return *(undefined4 *)(*(int *)(param_1 + 0x404) + 0xd4);
      }
      uVar1 = 0x1a;
      *param_3 = (int)tls12_sigalgs;
    }
    return uVar1;
  }
  *param_3 = (int)&suiteb_sigalgs;
  return 2;
}

