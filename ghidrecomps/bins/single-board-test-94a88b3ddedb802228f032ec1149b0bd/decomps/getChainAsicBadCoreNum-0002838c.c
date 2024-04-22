
int getChainAsicBadCoreNum(int param_1,int param_2)

{
  FILE *pFVar1;
  int local_10;
  int local_c;
  
  local_10 = 0;
  if (5 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: chainIndex, asicIndex %d, %d\n","main.c",0xa9c,param_1,param_2);
    }
    fclose(pFVar1);
  }
  if (param_2 < 0x54) {
    for (local_c = 0; local_c < 0x72; local_c = local_c + 1) {
      if (*(int *)(asic_core_enabled_flag + (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4) < 1
         ) {
        local_10 = local_10 + 1;
      }
    }
    if (0xe < local_10) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: Detect a BAD chip=%d on chain[%d]\n","main.c",0xaac,param_2,param_1
                 );
        }
        fclose(pFVar1);
      }
      local_10 = 0xf;
    }
    if (5 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: badcore %d\n","main.c",0xab2,local_10);
      }
      fclose(pFVar1);
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}

