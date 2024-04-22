
undefined4 aes_ccm_ctrl(int param_1,undefined4 param_2,size_t param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x60);
  switch(param_2) {
  case 0:
    *(undefined4 *)(iVar2 + 0xf8) = 0;
    *(undefined4 *)(iVar2 + 0xfc) = 0;
    *(undefined4 *)(iVar2 + 0x100) = 0;
    *(undefined4 *)(iVar2 + 0x104) = 0;
    *(undefined4 *)(iVar2 + 0x108) = 8;
    *(undefined4 *)(iVar2 + 0x10c) = 0xc;
    return 1;
  default:
    return 0xffffffff;
  case 8:
    if (*(int *)(iVar2 + 0x13c) == 0) {
      return 1;
    }
    if (*(int *)(iVar2 + 0x13c) == iVar2) {
      *(int *)(*(int *)((int)param_4 + 0x60) + 0x13c) = *(int *)((int)param_4 + 0x60);
      return 1;
    }
    break;
  case 9:
    param_3 = 0xf - param_3;
  case 0x14:
    if (param_3 - 2 < 7) {
      *(size_t *)(iVar2 + 0x108) = param_3;
      return 1;
    }
    break;
  case 0x10:
    if (((*(int *)(param_1 + 8) != 0) && (*(int *)(iVar2 + 0x100) != 0)) &&
       (iVar1 = CRYPTO_ccm128_tag(iVar2 + 0x110,param_4,param_3,param_4,param_4), iVar1 != 0)) {
      *(undefined4 *)(iVar2 + 0x100) = 0;
      *(undefined4 *)(iVar2 + 0xfc) = 0;
      *(undefined4 *)(iVar2 + 0x104) = 0;
      return 1;
    }
    break;
  case 0x11:
    if ((-1 < (int)(param_3 << 0x1f)) && (param_3 - 4 < 0xd)) {
      if (*(int *)(param_1 + 8) == 0) {
        if (param_4 != (void *)0x0) {
          *(undefined4 *)(iVar2 + 0x100) = 1;
          memcpy((void *)(param_1 + 0x30),param_4,param_3);
          goto LAB_000b08ce;
        }
      }
      else if (param_4 == (void *)0x0) {
LAB_000b08ce:
        *(size_t *)(iVar2 + 0x10c) = param_3;
        return 1;
      }
    }
  }
  return 0;
}

