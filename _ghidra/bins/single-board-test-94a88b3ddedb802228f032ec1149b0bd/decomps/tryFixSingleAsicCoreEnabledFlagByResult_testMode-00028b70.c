
undefined4 tryFixSingleAsicCoreEnabledFlagByResult_testMode(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
    *(undefined4 *)
     (temp_asic_core_enabled_flag + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4) =
         *(undefined4 *)
          (asic_core_enabled_flag + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4);
  }
  UpdateSingleAsicCoreEnabledFlagByResult(param_1,param_2);
  iVar1 = isChainSingleAsicBadCoreCanAccepted(param_1,param_2);
  if (iVar1 == 0) {
    for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
      *(undefined4 *)(asic_core_enabled_flag + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4)
           = *(undefined4 *)
              (temp_asic_core_enabled_flag + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

