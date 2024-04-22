
/* WARNING: Unknown calling convention */

void sweep_fix_ideal_rate(void)

{
  _Bool _Var1;
  int iVar2;
  FILE *pFVar3;
  int down_count [16];
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int target_rate;
  int step_rate;
  int step;
  int margin;
  int min_down_count;
  int fix_chain;
  int totalRate;
  int chip;
  int chain;
  
  _Var1 = is_T11();
  if (_Var1) {
    step = 5;
    step_rate = 0x3e;
    totalRate = sweep_get_current_ideal_hash_rate();
    iVar2 = fix_hash_rate(totalRate);
    target_rate = iVar2 + 100;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: total rate %d, target rate %d, step rate %d\n","freq_scan.c",0xd5d
                ,"sweep_fix_ideal_rate",totalRate,target_rate,0x3e);
      }
      fclose(pFVar3);
    }
    memset(down_count,0,0x40);
    while (step_rate + target_rate <= totalRate) {
      min_down_count = 1000;
      fix_chain = -1;
      for (chain = 0; chain < 0x10; chain = chain + 1) {
        if ((dev->chain_exist[chain] == 1) && (down_count[chain] < min_down_count)) {
          min_down_count = down_count[chain];
          fix_chain = chain;
        }
      }
      if (fix_chain == -1) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%s:%d:%s: error, can not find a chain to fix\n","freq_scan.c",0xd72,
                    "sweep_fix_ideal_rate");
          }
          fclose(pFVar3);
        }
        break;
      }
      down_count[fix_chain] = down_count[fix_chain] + 1;
      for (chip = 0; chip < 0x3c; chip = chip + 1) {
        *(int *)(scanfreq_info.workdataPathPrefix +
                (int)(&UNK_00011958 + chip + fix_chain * 0x100) * 4 + -0x18) =
             *(int *)(scanfreq_info.workdataPathPrefix +
                     (int)(&UNK_00011958 + chip + fix_chain * 0x100) * 4 + -0x18) - step;
      }
      totalRate = sweep_get_current_ideal_hash_rate();
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,
                  "%s:%d:%s: chain %d down a step of %dM, rate of %dG, current total rate %dG\n",
                  "freq_scan.c",0xd7b,"sweep_fix_ideal_rate",fix_chain,step,step_rate,totalRate);
        }
        fclose(pFVar3);
      }
    }
    sweep_update_ideal_hash_rate();
  }
  return;
}

