
void InitAsicCoreEnabledFlag(void)

{
  int local_14;
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    *(undefined4 *)(disabled_cores_num + local_c * 4) = 0;
    for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
      for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
        *(undefined4 *)
         (asic_core_enabled_flag + (local_14 + (local_10 + local_c * 0x100) * 0x100) * 4) = 1;
        *(undefined4 *)
         (last_asic_core_enabled_flag + (local_14 + (local_10 + local_c * 0x100) * 0x100) * 4) = 1;
      }
      *(undefined4 *)(chain_badcore_num + (local_10 + local_c * 0x100) * 4) = 0;
    }
  }
  return;
}

