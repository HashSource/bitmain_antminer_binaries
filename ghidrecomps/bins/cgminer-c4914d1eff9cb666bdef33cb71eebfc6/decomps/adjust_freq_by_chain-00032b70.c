
void adjust_freq_by_chain(int chain,int freq_scan_times,working_mode_e working_mode)

{
  longlong lVar1;
  FILE *pFVar2;
  float fVar3;
  working_mode_e working_mode_local;
  int freq_scan_times_local;
  int chain_local;
  int bad_core [6];
  FILE *pFile_6;
  FILE *pFile_4;
  FILE *pFile_5;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_8;
  FILE *pFile_7;
  int chip;
  float min_adjust_freq;
  int invalid_region_num;
  int bad_region_num;
  int core;
  int vol_region;
  
  bad_core[0] = 0;
  bad_core[1] = 0;
  bad_core[2] = 0;
  bad_core[3] = 0;
  bad_core[4] = 0;
  bad_core[5] = 0;
  bad_region_num = 0;
  invalid_region_num = 0;
  if (working_mode == MODE1) {
    lVar1 = (longlong)g_sweep_config_eco.sweep_min_freq;
  }
  else {
    lVar1 = (longlong)g_sweep_config_hpf.sweep_min_freq;
  }
  min_adjust_freq = (float)lVar1;
  for (vol_region = 0; vol_region < 6; vol_region = vol_region + 1) {
    bad_core[vol_region] = 0;
    chip = get_physical_chip_no(vol_region,0);
    for (core = 0; core < 0xd0; core = core + 1) {
      if (scanfreq_info.asic_core_nonce_num[chain][chip][core] < scanfreq_info.AsicWorkCount / 0xd0)
      {
        bad_core[vol_region] = bad_core[vol_region] + 1;
      }
    }
    if (0x33 < bad_core[vol_region]) {
      bad_region_num = bad_region_num + 1;
    }
    if ((bad_core[vol_region] != 0) && ((bad_core[vol_region] < 1 || (0x33 < bad_core[vol_region])))
       ) {
      if ((bad_core[vol_region] < 0x34) || (0x67 < bad_core[vol_region])) {
        if ((bad_core[vol_region] < 0x68) || (0x9b < bad_core[vol_region])) {
          if ((bad_core[vol_region] < 0x9c) || (0xd0 < bad_core[vol_region])) {
            if (3 < log_level) {
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fwrite("wrong bad core number!\n",1,0x17,pFVar2);
              }
              fclose(pFVar2);
            }
          }
          else if (min_adjust_freq < freq_adjust_index[chain][vol_region] ==
                   (NAN(min_adjust_freq) || NAN(freq_adjust_index[chain][vol_region]))) {
            if (3 < log_level) {
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fwrite("The freq is low enough,jump!\n",1,0x1d,pFVar2);
              }
              fclose(pFVar2);
            }
            invalid_region_num = invalid_region_num + 1;
          }
          else {
            freq_adjust_index[chain][vol_region] =
                 freq_adjust_index[chain][vol_region] - freq_adjust_step * 3.0;
            fVar3 = freq_adjust_index[chain][vol_region];
            if (min_adjust_freq != fVar3 &&
                min_adjust_freq < fVar3 == (NAN(min_adjust_freq) || NAN(fVar3))) {
              freq_adjust_index[chain][vol_region] = min_adjust_freq;
            }
            if (3 < log_level) {
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fprintf(pFVar2,"chain[%d] domain[%02d] to %f\n",chain,vol_region + 1,
                        (double)freq_adjust_index[chain][vol_region]);
              }
              fclose(pFVar2);
            }
          }
        }
        else if (min_adjust_freq < freq_adjust_index[chain][vol_region] ==
                 (NAN(min_adjust_freq) || NAN(freq_adjust_index[chain][vol_region]))) {
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fwrite("The freq is low enough,jump!\n",1,0x1d,pFVar2);
            }
            fclose(pFVar2);
          }
          invalid_region_num = invalid_region_num + 1;
        }
        else {
          freq_adjust_index[chain][vol_region] =
               freq_adjust_index[chain][vol_region] - (freq_adjust_step + freq_adjust_step);
          fVar3 = freq_adjust_index[chain][vol_region];
          if (min_adjust_freq != fVar3 &&
              min_adjust_freq < fVar3 == (NAN(min_adjust_freq) || NAN(fVar3))) {
            freq_adjust_index[chain][vol_region] = min_adjust_freq;
          }
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"chain[%d] domain[%02d] to %f\n",chain,vol_region + 1,
                      (double)freq_adjust_index[chain][vol_region]);
            }
            fclose(pFVar2);
          }
        }
      }
      else if (min_adjust_freq < freq_adjust_index[chain][vol_region] ==
               (NAN(min_adjust_freq) || NAN(freq_adjust_index[chain][vol_region]))) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fwrite("The freq is low enough,jump!\n",1,0x1d,pFVar2);
          }
          fclose(pFVar2);
        }
        invalid_region_num = invalid_region_num + 1;
      }
      else {
        freq_adjust_index[chain][vol_region] =
             freq_adjust_index[chain][vol_region] - freq_adjust_step;
        fVar3 = freq_adjust_index[chain][vol_region];
        if (min_adjust_freq != fVar3 &&
            min_adjust_freq < fVar3 == (NAN(min_adjust_freq) || NAN(fVar3))) {
          freq_adjust_index[chain][vol_region] = min_adjust_freq;
        }
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"chain[%d] domain[%02d] to %f\n",chain,vol_region + 1,
                    (double)freq_adjust_index[chain][vol_region]);
          }
          fclose(pFVar2);
        }
      }
    }
  }
  if ((bad_region_num != 0) && (bad_region_num == invalid_region_num)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain[%d] early quit ...\n","freq_scan.c",0x6da,
                "adjust_freq_by_chain",chain);
      }
      fclose(pFVar2);
    }
    force_scan_freq_is_finished_by_chain(chain);
    calc_ability_per_chain_recode[chain] = calc_ability_per_chain[freq_scan_times + -1][chain];
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"--record chain[%d] last value :%5.3f THash\n",chain,
                calc_ability_per_chain_recode + chain,
                (double)calc_ability_per_chain_recode[chain] / DAT_00033348);
      }
      fclose(pFVar2);
    }
  }
  return;
}

