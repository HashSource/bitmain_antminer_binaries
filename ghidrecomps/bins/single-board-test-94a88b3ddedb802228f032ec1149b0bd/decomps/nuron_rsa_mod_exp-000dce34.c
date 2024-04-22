
undefined4 nuron_rsa_mod_exp(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int lib;
  
  iVar1 = DAT_000dce68;
  if (*(int *)(DAT_000dce68 + 8) == 0) {
    lib = *(int *)(DAT_000dce68 + 4);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = lib;
    }
    ERR_put_error(lib,0x67,0x69,DAT_000dce6c,0xc1);
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(DAT_000dce68 + 0xc))
                      (param_1,param_2,*(undefined4 *)(param_3 + 0x18),
                       *(undefined4 *)(param_3 + 0x10));
  }
  return uVar2;
}

