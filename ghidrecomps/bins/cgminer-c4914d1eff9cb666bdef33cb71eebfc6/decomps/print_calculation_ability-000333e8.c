
void print_calculation_ability(int freq_scan_times)

{
  longlong lVar1;
  uint32_t uVar2;
  FILE *pFVar3;
  int iVar4;
  int freq_scan_times_local;
  float nonce_rate [16] [6];
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  FILE *pFile_4;
  FILE *pFile_3;
  float required_vol_region_nonce;
  float tmp;
  uint32_t vol_region;
  uint32_t chain;
  
  memset(nonce_rate,0,0x180);
  lVar1 = (longlong)scanfreq_info.RequiredChainNonce;
  iVar4 = freq_scan_times + -1;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (vol_region = 0; vol_region < 6; vol_region = vol_region + 1) {
        uVar2 = get_vol_region_nonce_number(chain,vol_region);
        nonce_rate[chain][vol_region] = (float)uVar2 / ((float)lVar1 / 6.0);
        calc_ability_per_chain[iVar4][chain] =
             calc_ability_per_chain[iVar4][chain] +
             ((freq_adjust_index[chain][vol_region] * 208.0 * 10.0) / 1000.0) *
             nonce_rate[chain][vol_region];
      }
      if (3 < log_level) {
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"chain[%d] calc power:%5.3f THash\n",chain,
                  calc_ability_per_chain[iVar4] + chain,
                  (double)calc_ability_per_chain[iVar4][chain] / 1000.0);
        }
        fclose(pFVar3);
      }
      if (scanfreq_info.test_done[chain] != false) {
        if (calc_ability_per_chain_recode[chain] == 0.0) {
          calc_ability_per_chain_recode[chain] = calc_ability_per_chain[iVar4][chain];
          if (3 < log_level) {
            pFVar3 = fopen(log_file,"a+");
            if (pFVar3 != (FILE *)0x0) {
              fprintf(pFVar3,"--record chain[%d] final :%5.3f THash\n",chain,
                      calc_ability_per_chain_recode + chain,
                      (double)calc_ability_per_chain_recode[chain] / 1000.0);
            }
            fclose(pFVar3);
          }
        }
        else {
          calc_ability_per_chain[iVar4][chain] = calc_ability_per_chain_recode[chain];
          if (3 < log_level) {
            pFVar3 = fopen(log_file,"a+");
            if (pFVar3 != (FILE *)0x0) {
              fprintf(pFVar3,"--replace chain[%d] final: %5.3f THash to calc...\n",chain,
                      calc_ability_per_chain[iVar4] + chain,
                      (double)calc_ability_per_chain[iVar4][chain] / 1000.0);
            }
            fclose(pFVar3);
          }
        }
      }
      calc_ability[iVar4] = calc_ability[iVar4] + calc_ability_per_chain[iVar4][chain];
    }
  }
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"\ntimes[%d]:calc power:%5.3f THash\n",freq_scan_times,calc_ability + iVar4,
              (double)calc_ability[iVar4] / 1000.0);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fputc(10,pFVar3);
    }
    fclose(pFVar3);
  }
  return;
}

