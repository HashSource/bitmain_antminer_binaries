
void surewarehk_ex_free(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int lib;
  
  iVar1 = DAT_000dd1a0;
  if (*(code **)(DAT_000dd1a0 + 8) != (code *)0x0) {
    (**(code **)(DAT_000dd1a0 + 8))(param_2,0);
    return;
  }
  lib = *(int *)(DAT_000dd1a0 + 4);
  if (lib == 0) {
    lib = ERR_get_next_error_library();
    *(int *)(iVar1 + 4) = lib;
  }
  ERR_put_error(lib,0x66,0x75,DAT_000dd1a4,0x36d);
  return;
}

