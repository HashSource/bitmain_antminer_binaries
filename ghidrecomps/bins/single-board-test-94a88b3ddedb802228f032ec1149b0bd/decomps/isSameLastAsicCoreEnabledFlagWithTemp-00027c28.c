
undefined4 isSameLastAsicCoreEnabledFlagWithTemp(int param_1)

{
  int local_10;
  int local_c;
  
  local_c = 0;
  do {
    if (0x53 < local_c) {
      return 1;
    }
    for (local_10 = 0; local_10 < 0x72; local_10 = local_10 + 1) {
      if (*(int *)(temp_asic_core_enabled_flag +
                  (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4) !=
          *(int *)(last_asic_core_enabled_flag +
                  (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4)) {
        return 0;
      }
    }
    local_c = local_c + 1;
  } while( true );
}

