
bool surewarehk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  char local_58 [16];
  undefined2 local_48;
  undefined1 auStack_46 [46];
  
  builtin_strncpy(local_58,"ENGINE_rand_byte",0x10);
  local_48 = 0x73;
  memset(auStack_46,0,0x2e);
  if (p_surewarehk_Rand_Bytes == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6c,0x75,"e_sureware.c",0x293);
    bVar2 = false;
  }
  else {
    iVar1 = (*p_surewarehk_Rand_Bytes)(local_58,param_1,param_2);
    surewarehk_error_handling(local_58,0x6c,iVar1);
    bVar2 = iVar1 == 1;
  }
  return bVar2;
}

