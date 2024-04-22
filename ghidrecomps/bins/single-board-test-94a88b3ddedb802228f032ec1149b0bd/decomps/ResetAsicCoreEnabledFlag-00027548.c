
void ResetAsicCoreEnabledFlag(int param_1)

{
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
      *(undefined4 *)(asic_core_enabled_flag + (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4)
           = 1;
      *(undefined4 *)
       (last_asic_core_enabled_flag + (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4) = 1;
    }
    *(undefined4 *)(chain_badcore_num + (local_c + param_1 * 0x100) * 4) = 0;
  }
  return;
}

