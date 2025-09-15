
void UpdateSingleAsicCoreEnabledFlagByResult(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  iVar2 = *(int *)(chain_PassCount + param_1 * 4);
  for (local_10 = 0; local_10 < 0x100; local_10 = local_10 + 1) {
    *(undefined4 *)(asic_core_enabled_flag + (local_10 + (param_2 + param_1 * 0x100) * 0x100) * 4) =
         1;
  }
  if (*(int *)(asic_nonce_num + (param_2 + param_1 * 0x100) * 4) <
      *(int *)(chain_PassCount + param_1 * 4)) {
    for (local_c = 0; local_c < 0x72; local_c = local_c + 1) {
      if ((*(int *)(asic_core_nonce_num + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4) <
           iVar2 / 0x72) && (cVar1 = isDisabledChipCore(param_1,param_2,local_c), cVar1 != '\x01'))
      {
        *(undefined4 *)
         (asic_core_enabled_flag + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4) = 0;
      }
    }
  }
  return;
}

