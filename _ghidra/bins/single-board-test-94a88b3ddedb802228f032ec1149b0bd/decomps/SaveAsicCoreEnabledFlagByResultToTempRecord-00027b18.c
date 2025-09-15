
void SaveAsicCoreEnabledFlagByResultToTempRecord(int param_1)

{
  char cVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar2 = *(int *)(chain_PassCount + param_1 * 4);
  for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
      *(undefined4 *)
       (temp_asic_core_enabled_flag + (local_14 + (local_10 + param_1 * 0x100) * 0x100) * 4) = 1;
    }
  }
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    if (*(int *)(asic_nonce_num + (local_c + param_1 * 0x100) * 4) <
        *(int *)(chain_PassCount + param_1 * 4)) {
      for (local_18 = 0; local_18 < 0x72; local_18 = local_18 + 1) {
        if ((*(int *)(asic_core_nonce_num + (local_18 + (local_c + param_1 * 0x100) * 0x100) * 4) <
             iVar2 / 0x72) &&
           (cVar1 = isDisabledChipCore(param_1,local_c,local_18), cVar1 != '\x01')) {
          *(undefined4 *)
           (temp_asic_core_enabled_flag + (local_18 + (local_c + param_1 * 0x100) * 0x100) * 4) = 0;
        }
      }
    }
  }
  return;
}

