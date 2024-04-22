
void ERR_GOST_error(int param_1,int param_2,char *param_3,int param_4)

{
  int *piVar1;
  int lib;
  
  piVar1 = DAT_00111e48;
  lib = *DAT_00111e48;
  if (lib == 0) {
    lib = ERR_get_next_error_library();
    *piVar1 = lib;
  }
  ERR_put_error(lib,param_1,param_2,param_3,param_4);
  return;
}

