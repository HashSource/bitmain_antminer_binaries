
undefined4 surewarehk_load_pubkey(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_65;
  undefined4 local_64;
  char local_60 [16];
  undefined2 uStack_50;
  undefined1 local_4e;
  undefined1 auStack_4d [49];
  
  local_64 = 0;
  local_65 = 0;
  builtin_strncpy(local_60,"ENGINE_load_pubk",0x10);
  uStack_50 = 0x7965;
  local_4e = 0;
  memset(auStack_4d,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
    uVar2 = 0;
  }
  else {
    iVar1 = (*p_surewarehk_Info_Pubkey)(local_60,param_2,&local_64,&local_65);
    if (iVar1 == 1) {
      uVar2 = sureware_load_public(param_1,param_2,0,local_64,local_65);
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      ERR_add_error_data(1,local_60);
      uVar2 = 0;
    }
  }
  return uVar2;
}

