
/* WARNING: Unknown calling convention */

int sweep_get_current_ideal_hash_rate(void)

{
  int max_hash_rate [16];
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
      ideal_hash_rate =
           (int)((float)(longlong)ideal_hash_rate +
                scanfreq_info.chain_nonce_rate[chain] * (float)(longlong)max_hash_rate[chain]);
    }
  }
  return ideal_hash_rate;
}

