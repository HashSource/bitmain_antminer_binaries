
code * ENGINE_ctrl_constprop_2(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
    ERR_put_error(0x26,0x8e,0x43,DAT_000a6e88,0xb7);
    pcVar1 = (code *)0x0;
  }
  else {
    CRYPTO_lock(9,0x1e,DAT_000a6e88,0xba);
    iVar3 = *(int *)(param_1 + 0x58);
    CRYPTO_lock(10,0x1e,DAT_000a6e88,0xbc);
    pcVar2 = *(code **)(param_1 + 0x40);
    pcVar1 = pcVar2;
    if (pcVar2 != (code *)0x0) {
      pcVar1 = (code *)0x1;
    }
    if (iVar3 < 1) {
      ERR_put_error(0x26,0x8e,0x82,DAT_000a6e88,0xbf);
      pcVar1 = (code *)0x0;
    }
    else if (param_2 != 10) {
      if ((param_2 < 10) || (0x12 < param_2)) {
        if (pcVar1 == (code *)0x0) {
          ERR_put_error(0x26,0x8e,0x78,DAT_000a6e88,0xe1);
          return (code *)0x0;
        }
      }
      else {
        if (pcVar1 == (code *)0x0) {
          ERR_put_error(0x26,0x8e,0x78,DAT_000a6e88,0xd4);
          return (code *)0xffffffff;
        }
        if ((*(uint *)(param_1 + 0x54) & 2) == 0) {
          pcVar1 = (code *)int_ctrl_helper_isra_0(param_1,param_2,param_3);
          return pcVar1;
        }
      }
      pcVar1 = (code *)(*pcVar2)(param_1,param_2,param_3,0,0);
    }
  }
  return pcVar1;
}

