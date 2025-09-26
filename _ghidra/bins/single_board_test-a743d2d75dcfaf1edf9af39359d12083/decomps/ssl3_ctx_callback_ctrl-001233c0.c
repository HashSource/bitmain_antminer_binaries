
undefined4 ssl3_ctx_callback_ctrl(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xb0);
  switch(param_2) {
  case 5:
    *(undefined4 *)(iVar1 + 0x20) = param_3;
    uVar2 = 1;
    break;
  case 6:
    *(undefined4 *)(iVar1 + 0x28) = param_3;
    uVar2 = 1;
    break;
  case 7:
    *(undefined4 *)(iVar1 + 0x30) = param_3;
    uVar2 = 1;
    break;
  default:
    uVar2 = 0;
    break;
  case 0x35:
    *(undefined4 *)(param_1 + 0x100) = param_3;
    uVar2 = 1;
    break;
  case 0x3f:
    *(undefined4 *)(param_1 + 0x13c) = param_3;
    uVar2 = 1;
    break;
  case 0x48:
    *(undefined4 *)(param_1 + 0x138) = param_3;
    uVar2 = 1;
    break;
  case 0x4b:
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x168) = param_3;
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    break;
  case 0x4c:
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x16c) = param_3;
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    break;
  case 0x4d:
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x170) = param_3;
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
  }
  return uVar2;
}

