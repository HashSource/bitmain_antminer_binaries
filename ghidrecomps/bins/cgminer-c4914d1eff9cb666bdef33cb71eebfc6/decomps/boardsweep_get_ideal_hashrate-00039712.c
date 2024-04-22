
void boardsweep_get_ideal_hashrate(working_mode_e working_mode)

{
  FILE *pFVar1;
  int iVar2;
  working_mode_e working_mode_local;
  int down_count [16];
  int chain_max_ideal_hashrate_index [16];
  int chain_max_ideal_hashrate [16];
  FILE *pFile_1;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_3;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile;
  int margin;
  int target_rate;
  int min_down_count;
  int fix_chain;
  int total_ideal_hashrate;
  int index;
  int chip;
  int chain;
  
  memset(chain_max_ideal_hashrate,0,0x40);
  memset(chain_max_ideal_hashrate_index,0,0x40);
  total_ideal_hashrate = 0;
  memset(down_count,0,0x40);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: \nget ideal hash rate\n","freq_scan.c",0xfd4,
              "boardsweep_get_ideal_hashrate");
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (index = 0; index < scanfreq_info.ideal_hash_rate_index[chain]; index = index + 1) {
        if (chain_max_ideal_hashrate[chain] < scanfreq_info.ideal_hash_rate[chain][index]) {
          chain_max_ideal_hashrate[chain] = scanfreq_info.ideal_hash_rate[chain][index];
          chain_max_ideal_hashrate_index[chain] = index;
        }
      }
    }
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain %d max ideal hash is %d at freq %d\n","freq_scan.c",0xfe9,
                  "boardsweep_get_ideal_hashrate",chain,chain_max_ideal_hashrate[chain],
                  scanfreq_info.ideal_hash_rate_freq[chain][chain_max_ideal_hashrate_index[chain]]);
        }
        fclose(pFVar1);
      }
      total_ideal_hashrate = chain_max_ideal_hashrate[chain] + total_ideal_hashrate;
    }
  }
  iVar2 = fix_hash_rate(total_ideal_hashrate);
  target_rate = iVar2 + 100;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: total ideal hash is %d, target hash is %d\n","freq_scan.c",0xfee,
              "boardsweep_get_ideal_hashrate",total_ideal_hashrate,target_rate);
    }
    fclose(pFVar1);
  }
  memset(down_count,0,0x40);
  do {
    do {
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
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: error, can not find a chain to fix\n","freq_scan.c",0x1003,
                    "boardsweep_get_ideal_hashrate");
          }
          fclose(pFVar1);
        }
        goto LAB_00039daa;
      }
      down_count[fix_chain] = down_count[fix_chain] + 1;
    } while (chain_max_ideal_hashrate_index[fix_chain] < 1);
    index = chain_max_ideal_hashrate_index[fix_chain] + -1;
    chain_max_ideal_hashrate[fix_chain] =
         scanfreq_info.ideal_hash_rate[fix_chain + -1]
         [chain_max_ideal_hashrate_index[fix_chain] + 0x27];
    chain_max_ideal_hashrate_index[fix_chain] = index;
    total_ideal_hashrate = 0;
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] == 1) {
        total_ideal_hashrate = chain_max_ideal_hashrate[chain] + total_ideal_hashrate;
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: chain %d down to %d, total hash is %d\n","freq_scan.c",0x1017,
                "boardsweep_get_ideal_hashrate",fix_chain,
                scanfreq_info.ideal_hash_rate_freq[fix_chain][index],total_ideal_hashrate);
      }
      fclose(pFVar1);
    }
  } while (target_rate <= total_ideal_hashrate);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: reach target hashrate\n","freq_scan.c",0x101b,
              "boardsweep_get_ideal_hashrate");
    }
    fclose(pFVar1);
  }
  chain_max_ideal_hashrate[fix_chain] = scanfreq_info.ideal_hash_rate[fix_chain][index + 1];
  chain_max_ideal_hashrate_index[fix_chain] = index + 1;
LAB_00039daa:
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar2 = chain_max_ideal_hashrate_index[chain];
      scanfreq_info.max_hashrate[chain] =
           (scanfreq_info.ideal_hash_rate_freq[chain][iVar2] * 0x30c0) / 1000;
      scanfreq_info.ideal_hashrate[chain] = chain_max_ideal_hashrate[chain];
      for (chip = 0; chip < 0x3c; chip = chip + 1) {
        *(int *)(scanfreq_info.workdataPathPrefix +
                (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) =
             scanfreq_info.ideal_hash_rate_freq[chain][iVar2];
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] ideal hash freq:       %d\n","freq_scan.c",0x1032,
                  "boardsweep_get_ideal_hashrate",chain,
                  scanfreq_info.ideal_hash_rate_freq[chain][iVar2]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] max hashrate:          %d\n","freq_scan.c",0x1033,
                  "boardsweep_get_ideal_hashrate",chain,scanfreq_info.max_hashrate[chain]);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] ideal hashrate:        %d\n","freq_scan.c",0x1034,
                  "boardsweep_get_ideal_hashrate",chain,scanfreq_info.ideal_hashrate[chain]);
        }
        fclose(pFVar1);
      }
    }
  }
  return;
}

