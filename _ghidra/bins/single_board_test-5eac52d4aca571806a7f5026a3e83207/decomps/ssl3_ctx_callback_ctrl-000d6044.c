
undefined4 ssl3_ctx_callback_ctrl(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_2) {
  case 6:
    *(undefined4 *)(*(int *)(param_1 + 0xc0) + 8) = param_3;
    return 1;
  default:
    uVar1 = 0;
    break;
  case 0x35:
    *(undefined4 *)(param_1 + 0x130) = param_3;
    return 1;
  case 0x3f:
    *(undefined4 *)(param_1 + 0x150) = param_3;
    return 1;
  case 0x48:
    *(undefined4 *)(param_1 + 0x14c) = param_3;
    return 1;
  case 0x4b:
    *(undefined4 *)(param_1 + 0x1c4) = param_3;
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x20;
    return 1;
  case 0x4c:
    *(undefined4 *)(param_1 + 0x1c8) = param_3;
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x20;
    return 1;
  case 0x4d:
    *(undefined4 *)(param_1 + 0x1cc) = param_3;
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x20;
    return 1;
  case 0x4f:
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x214) = param_3;
  }
  return uVar1;
}

