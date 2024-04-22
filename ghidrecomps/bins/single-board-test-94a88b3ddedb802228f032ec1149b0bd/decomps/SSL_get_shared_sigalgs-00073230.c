
undefined4
SSL_get_shared_sigalgs
          (int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
          undefined *param_6,undefined *param_7)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x98) + 0x13c);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else if (param_2 < *(int *)(*(int *)(param_1 + 0x98) + 0x140)) {
    iVar3 = iVar2 + param_2 * 0x10;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(iVar2 + param_2 * 0x10);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(iVar3 + 4);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(iVar3 + 8);
    }
    if (param_6 != (undefined *)0x0) {
      *param_6 = *(undefined *)(iVar3 + 0xc);
    }
    if (param_7 != (undefined *)0x0) {
      *param_7 = *(undefined *)(iVar3 + 0xd);
    }
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x140);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

