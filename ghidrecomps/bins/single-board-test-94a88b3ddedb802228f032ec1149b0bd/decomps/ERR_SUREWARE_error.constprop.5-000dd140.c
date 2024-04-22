
void ERR_SUREWARE_error_constprop_5(int param_1,int param_2,int param_3)

{
  int iVar1;
  int lib;
  
  iVar1 = DAT_000dd168;
  lib = *(int *)(DAT_000dd168 + 4);
  if (lib == 0) {
    lib = ERR_get_next_error_library();
    *(int *)(iVar1 + 4) = lib;
  }
  ERR_put_error(lib,param_1,param_2,DAT_000dd16c,param_3);
  return;
}

