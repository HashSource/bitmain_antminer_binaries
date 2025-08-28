
undefined4 hwcrhk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *local_420;
  undefined4 local_41c;
  undefined1 auStack_418 [1028];
  
  local_420 = auStack_418;
  local_41c = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6c,0x6a,"e_chil.c",0x45a);
    uVar2 = 0;
  }
  else {
    iVar1 = (*p_hwcrhk_RandomBytes)(hwcrhk_context,param_1,param_2,&local_420);
    if (iVar1 < 0) {
      if (iVar1 == -2) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6c,0x70,"e_chil.c",0x465);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6c,0x6f,"e_chil.c",0x467);
      }
      ERR_add_error_data(1,local_420);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

