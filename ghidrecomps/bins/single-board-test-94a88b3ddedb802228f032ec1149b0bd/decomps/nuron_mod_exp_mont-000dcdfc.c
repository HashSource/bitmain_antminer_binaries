
undefined4 nuron_mod_exp_mont(void)

{
  int iVar1;
  undefined4 uVar2;
  int lib;
  
  iVar1 = DAT_000dce2c;
  if (*(int *)(DAT_000dce2c + 8) == 0) {
    lib = *(int *)(DAT_000dce2c + 4);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = lib;
    }
    ERR_put_error(lib,0x67,0x69,DAT_000dce30,0xc1);
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(DAT_000dce2c + 0xc))();
  }
  return uVar2;
}

