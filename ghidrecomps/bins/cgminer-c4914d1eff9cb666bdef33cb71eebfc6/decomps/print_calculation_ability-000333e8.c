
void print_calculation_ability(int freq_scan_times)

{
  uint32_t uVar1;
  FILE *pFVar2;
  int iVar3;
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
  required_vol_region_nonce = (float)(longlong)scanfreq_info.RequiredChainNonce / 6.0;
  iVar3 = freq_scan_times + -1;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (vol_region = 0; vol_region < 6; vol_region = vol_region + 1) {
        uVar1 = get_vol_region_nonce_number(chain,vol_region);
        nonce_rate[chain][vol_region] = (float)(ulonglong)uVar1 / required_vol_region_nonce;
        calc_ability_per_chain[iVar3][chain] =
             calc_ability_per_chain[iVar3][chain] +
             (float)(((double)(freq_adjust_index[chain][vol_region] * DAT_000337b0 * 10.0) /
                     DAT_000337a8) * (double)nonce_rate[chain][vol_region]);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"chain[%d] calc power:%5.3f THash\n",chain,
                  calc_ability_per_chain[iVar3] + chain,
                  (double)calc_ability_per_chain[iVar3][chain] / DAT_000337a8);
        }
        fclose(pFVar2);
      }
      if (scanfreq_info.test_done[chain] != false) {
        if (calc_ability_per_chain_recode[chain] == 0.0) {
          calc_ability_per_chain_recode[chain] = calc_ability_per_chain[iVar3][chain];
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"--record chain[%d] final :%5.3f THash\n",chain,
                      calc_ability_per_chain_recode + chain,
                      (double)calc_ability_per_chain_recode[chain] / DAT_000337a8);
            }
            fclose(pFVar2);
          }
        }
        else {
          calc_ability_per_chain[iVar3][chain] = calc_ability_per_chain_recode[chain];
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"--replace chain[%d] final: %5.3f THash to calc...\n",chain,
                      calc_ability_per_chain[iVar3] + chain,
                      (double)calc_ability_per_chain[iVar3][chain] / DAT_000337a8);
            }
            fclose(pFVar2);
          }
        }
      }
      calc_ability[iVar3] = calc_ability[iVar3] + calc_ability_per_chain[iVar3][chain];
    }
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"\ntimes[%d]:calc power:%5.3f THash\n",freq_scan_times,calc_ability + iVar3,
              (double)calc_ability[iVar3] / DAT_00033890);
    }
    fclose(pFVar2);
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fputc(10,pFVar2);
    }
    fclose(pFVar2);
  }
  return;
}

