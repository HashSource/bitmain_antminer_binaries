
/* WARNING: Unknown calling convention */

void sweep_update_ideal_hash_rate(void)

{
  FILE *pFVar1;
  int max_hash_rate [16];
  FILE *pFile;
  FILE *pFile_1;
  int ideal_hash_rate;
  int chip;
  int chain;
  
  memset(max_hash_rate,0,0x40);
  ideal_hash_rate = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (chip = 0; chip < 0x100; chip = chip + 1) {
        max_hash_rate[chain] =
             max_hash_rate[chain] +
             *(int *)(scanfreq_info.workdataPathPrefix +
                     (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) * 0xd0;
      }
      max_hash_rate[chain] = max_hash_rate[chain] / 1000;
      scanfreq_info.ideal_hashrate[chain] =
           (int)(scanfreq_info.chain_nonce_rate[chain] * (float)(longlong)max_hash_rate[chain]);
      ideal_hash_rate = scanfreq_info.ideal_hashrate[chain] + ideal_hash_rate;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] fixed ideal hashrate:     %d\n","freq_scan.c",0xd30,
                  "sweep_update_ideal_hash_rate",chain,scanfreq_info.ideal_hashrate[chain]);
        }
        fclose(pFVar1);
      }
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: total fixed ideal hashrate:     %d\n","freq_scan.c",0xd32,
              "sweep_update_ideal_hash_rate",ideal_hash_rate);
    }
    fclose(pFVar1);
  }
  return;
}

