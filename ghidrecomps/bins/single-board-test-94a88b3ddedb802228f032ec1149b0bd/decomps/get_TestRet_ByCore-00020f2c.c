
undefined4 get_TestRet_ByCore(int param_1,int param_2,int param_3)

{
  char cVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0x71 < local_c) {
      return 1;
    }
    if (((*(int *)(asic_core_nonce_num + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4) !=
          param_3 / 0x72) &&
        (0 < *(int *)(asic_core_enabled_flag + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4))
        ) && (cVar1 = isDisabledChipCore(param_1,param_2,local_c), cVar1 != '\x01')) break;
    local_c = local_c + 1;
  }
  return 0;
}

