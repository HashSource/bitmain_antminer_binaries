
undefined4 get_next_level_vol_and_frq(int param_1,undefined4 *param_2,uint *param_3)

{
  FILE *pFVar1;
  int iVar2;
  uint local_14;
  
  if (1 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: get_next_level_vol_and_frq enter. *freq_index = %d\n",
              "board_frq_tuning.c",0x193,*param_3);
    }
    fclose(pFVar1);
  }
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (uint *)0x0)) {
    if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: invalid parameter.","board_frq_tuning.c",0x197);
      }
      fclose(pFVar1);
    }
  }
  else {
    local_14 = *param_3 + 1;
    if (5 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: freq_pll_1385_num = %d\n","board_frq_tuning.c",0x19c,
                lenghth_of_freq_pll_1385);
      }
      fclose(pFVar1);
    }
    for (; local_14 < lenghth_of_freq_pll_1385; local_14 = local_14 + 1) {
      iVar2 = atoi(*(char **)(freq_pll_1385 + local_14 * 0x10));
      iVar2 = (iVar2 * 0x2568) / 1000;
      if (param_1 <= iVar2) {
        *param_3 = local_14;
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d: next board vol, feq : %d, %s\n","board_frq_tuning.c",0x1a4,
                    *param_2,*(undefined4 *)(freq_pll_1385 + *param_3 * 0x10));
          }
          fclose(pFVar1);
        }
        return 1;
      }
      if (5 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: rate = %d\n","board_frq_tuning.c",0x1a7,iVar2);
        }
        fclose(pFVar1);
      }
    }
    if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: fail to get avalible feq.\n","board_frq_tuning.c",0x1aa);
      }
      fclose(pFVar1);
    }
  }
  return 0;
}

