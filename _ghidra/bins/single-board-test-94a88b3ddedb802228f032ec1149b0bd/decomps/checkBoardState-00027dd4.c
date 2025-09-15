
undefined4 checkBoardState(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  undefined4 uVar3;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = 0;
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    iVar1 = getChainAsicTempBadCoreNum(param_1,local_c);
    if (0xe < iVar1) {
      local_10 = local_10 + 1;
    }
  }
  iVar1 = getBoardRateByTempResult(param_1,param_2);
  if (local_10 < 5) {
    iVar2 = getBoardLowestHashrateByVoltage(*(undefined4 *)(chain_Test_Level + param_1 * 4));
    if (iVar2 <= iVar1) {
      local_14 = 2;
    }
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        uVar3 = getBoardLowestHashrateByVoltage(*(undefined4 *)(chain_Test_Level + param_1 * 4));
        fprintf(__stream,
                "%s:%d: checkBoardState chain[%d] rate=%d bad_chip_num=%d lowest rate=%d ret=%d\n",
                "main.c",0x9dd,param_1,iVar1,local_10,uVar3,local_14);
      }
      fclose(__stream);
    }
  }
  else {
    local_14 = 1;
  }
  return local_14;
}

