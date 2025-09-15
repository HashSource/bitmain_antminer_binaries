
void CheckRateAndSaveHighestRateRecord(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  
  iVar1 = getBoardRateByHighestRateRecord(param_1);
  iVar2 = getBoardRateByTempResult(param_1,param_2);
  if (iVar1 < iVar2) {
    *(undefined4 *)(highest_rate_freq + param_1 * 4) = param_2;
    *(undefined4 *)(highest_rate_voltage_value + param_1 * 4) =
         *(undefined4 *)(chain_vol_value + param_1 * 4);
    SaveAsicCoreEnabledFlagByResultToHighestRateRecord(param_1);
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: Detect Higher Rate = %d > %d on chain[%d] freq=%s voltage=%d\n",
                "main.c",0xa6a,iVar2,iVar1,param_1,
                *(undefined4 *)(freq_pll_1385 + *(int *)(highest_rate_freq + param_1 * 4) * 0x10),
                *(undefined4 *)(highest_rate_voltage_value + param_1 * 4));
      }
      fclose(__stream);
    }
  }
  return;
}

