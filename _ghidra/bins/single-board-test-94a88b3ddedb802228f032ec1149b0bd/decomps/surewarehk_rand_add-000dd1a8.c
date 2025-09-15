
void surewarehk_rand_add(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char local_58 [17];
  undefined1 auStack_47 [47];
  
  builtin_strncpy(local_58,"ENGINE_rand_seed",0x10);
  local_58[0x10] = 0;
  memset(auStack_47,0,0x2f);
  if (p_surewarehk_Rand_Seed == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6d,0x75,"e_sureware.c",0x2a1);
  }
  else {
    uVar1 = (*p_surewarehk_Rand_Seed)(local_58,param_1,param_2);
    surewarehk_error_handling(local_58,0x6d,uVar1);
  }
  return;
}

