
undefined4
SSL_get_shared_sigalgs
          (int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
          undefined1 *param_6,undefined1 *param_7)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_2 >> 0x1f;
  if (*(int *)(param_1 + 0xf88) == 0) {
    uVar3 = 1;
  }
  if (uVar3 != 0) {
    return 0;
  }
  if ((int)param_2 < *(int *)(param_1 + 0xf8c) && -1 < *(int *)(param_1 + 0xf8c)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xf88) + param_2 * 4);
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(iVar2 + 8);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(iVar2 + 0x10);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(iVar2 + 0x18);
    }
    if (param_6 != (undefined1 *)0x0) {
      *param_6 = (char)*(undefined2 *)(iVar2 + 4);
    }
    if (param_7 != (undefined1 *)0x0) {
      *param_7 = (char)((ushort)*(undefined2 *)(iVar2 + 4) >> 8);
    }
    uVar1 = *(undefined4 *)(param_1 + 0xf8c);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

