
undefined4 ENGINE_ctrl_constprop_1(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    ERR_put_error(0x26,0x8e,0x43,DAT_000a6dbc,0xb7);
    uVar1 = 0;
  }
  else {
    CRYPTO_lock(9,0x1e,DAT_000a6dbc,0xba);
    iVar2 = *(int *)(param_1 + 0x58);
    CRYPTO_lock(10,0x1e,DAT_000a6dbc,0xbc);
    if (iVar2 < 1) {
      ERR_put_error(0x26,0x8e,0x82,DAT_000a6dbc,0xbf);
      uVar1 = 0;
    }
    else if (*(code **)(param_1 + 0x40) == (code *)0x0) {
      ERR_put_error(0x26,0x8e,0x78,DAT_000a6dbc,0xd4);
      uVar1 = 0xffffffff;
    }
    else {
      if ((*(uint *)(param_1 + 0x54) & 2) == 0) {
        uVar1 = int_ctrl_helper_isra_0(param_1,0xd,0,param_2);
        return uVar1;
      }
      uVar1 = (**(code **)(param_1 + 0x40))(param_1,0xd,0,param_2,0);
    }
  }
  return uVar1;
}

