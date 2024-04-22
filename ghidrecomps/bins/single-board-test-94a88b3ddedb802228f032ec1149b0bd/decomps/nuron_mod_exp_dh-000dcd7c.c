
undefined4
nuron_mod_exp_dh(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int lib;
  
  iVar1 = DAT_000dcdb4;
  if (*(int *)(DAT_000dcdb4 + 8) == 0) {
    lib = *(int *)(DAT_000dcdb4 + 4);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = lib;
    }
    ERR_put_error(lib,0x67,0x69,DAT_000dcdb8,0xc1);
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(DAT_000dcdb4 + 0xc))(param_2,param_3,param_4,param_5);
  }
  return uVar2;
}

