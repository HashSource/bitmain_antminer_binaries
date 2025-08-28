
undefined4 surewarehk_load_privkey(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_69;
  undefined4 local_68;
  undefined4 local_64;
  char local_60 [64];
  
  local_68 = 0;
  local_64 = 0;
  builtin_strncpy(local_60,"ENGINE_load_privkey",0x14);
  local_69 = 0;
  local_60[0x14] = '\0';
  local_60[0x15] = '\0';
  local_60[0x16] = '\0';
  local_60[0x17] = '\0';
  local_60[0x18] = '\0';
  local_60[0x19] = '\0';
  local_60[0x1a] = '\0';
  local_60[0x1b] = '\0';
  local_60[0x1c] = '\0';
  local_60[0x1d] = '\0';
  local_60[0x1e] = '\0';
  local_60[0x1f] = '\0';
  local_60[0x20] = '\0';
  local_60[0x21] = '\0';
  local_60[0x22] = '\0';
  local_60[0x23] = '\0';
  local_60[0x24] = '\0';
  local_60[0x25] = '\0';
  local_60[0x26] = '\0';
  local_60[0x27] = '\0';
  local_60[0x28] = '\0';
  local_60[0x29] = '\0';
  local_60[0x2a] = '\0';
  local_60[0x2b] = '\0';
  local_60[0x2c] = '\0';
  local_60[0x2d] = '\0';
  local_60[0x2e] = '\0';
  local_60[0x2f] = '\0';
  local_60[0x30] = '\0';
  local_60[0x31] = '\0';
  local_60[0x32] = '\0';
  local_60[0x33] = '\0';
  local_60[0x34] = '\0';
  local_60[0x35] = '\0';
  local_60[0x36] = '\0';
  local_60[0x37] = '\0';
  local_60[0x38] = '\0';
  local_60[0x39] = '\0';
  local_60[0x3a] = '\0';
  local_60[0x3b] = '\0';
  local_60[0x3c] = '\0';
  local_60[0x3d] = '\0';
  local_60[0x3e] = '\0';
  local_60[0x3f] = '\0';
  if (p_surewarehk_Load_Privkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x69,0x75,"e_sureware.c",0x33d);
    uVar2 = 0;
  }
  else {
    iVar1 = (*p_surewarehk_Load_Privkey)(local_60,param_2,&local_64,&local_68,&local_69);
    if (iVar1 == 1) {
      uVar2 = sureware_load_public(param_1,param_2,local_64,local_68,local_69);
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x69,0x80,"e_sureware.c",0x342);
      ERR_add_error_data(1,local_60);
      uVar2 = 0;
    }
  }
  return uVar2;
}

