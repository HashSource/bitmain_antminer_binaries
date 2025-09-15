
undefined4 check_result(int param_1,int param_2)

{
  FILE *pFVar1;
  int iVar2;
  undefined4 uVar3;
  int local_14;
  int local_10;
  int local_c;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: check_result enter\n","board_frq_tuning.c",0x218);
    }
    fclose(pFVar1);
  }
  local_c = 0;
  local_10 = 0;
  for (local_14 = 0; local_14 < 0x54; local_14 = local_14 + 1) {
    local_c = getChainAsicTempBadCoreNum(param_1,local_14);
    if (0xe < local_c) {
      local_10 = local_10 + 1;
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: bad_core_num, bad_chip_num : %d, %d\n","board_frq_tuning.c",0x225,
              local_c,local_10);
    }
    fclose(pFVar1);
  }
  if (local_10 < 5) {
    for (local_14 = 0; local_14 < 0x54; local_14 = local_14 + 1) {
      *(undefined4 *)(last_success_freq + (local_14 + param_1 * 0x100) * 4) =
           *(undefined4 *)(last_freq + (local_14 + param_1 * 0x100) * 4);
    }
    iVar2 = GetBoardRate(param_1);
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: current board [%d] rate : %d, excepted : %d\n","board_frq_tuning.c",
                0x234,param_1,iVar2,param_2);
      }
      fclose(pFVar1);
    }
    if (iVar2 < param_2) {
      uVar3 = 2;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

