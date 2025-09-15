
int freq_tuning_adjust_result_according_to_hash_rate
              (freq_tuning_info *freq_info,int hash_rate_target_MH,_Bool is_rounding_TH)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  FILE *pFVar5;
  int extraout_r1;
  int iVar6;
  _Bool is_rounding_TH_local;
  int hash_rate_target_MH_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile_12;
  FILE *pFile_11;
  FILE *pFile_10;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  int freq_diff_steps;
  int hash_rate_steps;
  int hash_rate_step_MH;
  int freq_store_step;
  int hash_rate_diff_MH;
  FILE *pFile;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  int hash_rate_stable_MH;
  int hash_rate_target_sale_MH;
  int hash_rate_curr_MH;
  int GH;
  int TH;
  int freq_diff_steps_extra;
  int freq_diff;
  int hash_rate_threshold_MH;
  int asic;
  int chain;
  
  freq_diff = 0;
  iVar1 = freq_tuning_get_hash_rate_MH(freq_info);
  hash_rate_threshold_MH = hash_rate_target_MH;
  if (iVar1 <= hash_rate_target_MH) {
    if (!is_rounding_TH) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Hash rate(%dMH) <= target(%dMH), no need adjust\n",
                  "freq_tuning.c",0x863,"freq_tuning_adjust_result_according_to_hash_rate",iVar1,
                  hash_rate_target_MH);
        }
        fclose(pFVar5);
      }
      return 0;
    }
    iVar2 = __aeabi_idiv(hash_rate_target_MH,1000000);
    iVar4 = __aeabi_idiv(iVar1,1000000);
    hash_rate_threshold_MH = iVar4 * 1000000 + 450000;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: hash_rate_stable_MH      = %d\n","freq_tuning.c",0x86a,
                "freq_tuning_adjust_result_according_to_hash_rate",hash_rate_threshold_MH);
      }
      fclose(pFVar5);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: hash_rate_target_sale_MH = %d\n","freq_tuning.c",0x86b,
                "freq_tuning_adjust_result_according_to_hash_rate",iVar2 * 1000000);
      }
      fclose(pFVar5);
    }
    if ((iVar2 * 1000000 <= iVar1) || (iVar1 <= hash_rate_threshold_MH)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Hash rate(%dMH), no need adjust\n","freq_tuning.c",0x873,
                  "freq_tuning_adjust_result_according_to_hash_rate",iVar1);
        }
        fclose(pFVar5);
      }
      return 0;
    }
  }
  iVar2 = eeprom_get_freq_store_step();
  iVar6 = freq_info->asic_num_per_chain * iVar2 * 0x2a0;
  uVar3 = __aeabi_idiv((iVar1 - hash_rate_threshold_MH) + iVar6 + -1,iVar6);
  iVar4 = __aeabi_idiv(uVar3,dev->chain_num);
  __aeabi_idivmod(uVar3,dev->chain_num);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_threshold_MH   = %dMH\n","freq_tuning.c",0x881,
              "freq_tuning_adjust_result_according_to_hash_rate",hash_rate_threshold_MH);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_curr           = %dMH\n","freq_tuning.c",0x882,
              "freq_tuning_adjust_result_according_to_hash_rate",iVar1);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_diff           = %dMH\n","freq_tuning.c",0x883,
              "freq_tuning_adjust_result_according_to_hash_rate",iVar1 - hash_rate_threshold_MH);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_step_MH        = %dMH\n","freq_tuning.c",0x884,
              "freq_tuning_adjust_result_according_to_hash_rate",iVar6);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: freq_store_step          = %dM\n","freq_tuning.c",0x885,
              "freq_tuning_adjust_result_according_to_hash_rate",iVar2);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_steps          = %d\n","freq_tuning.c",0x886,
              "freq_tuning_adjust_result_according_to_hash_rate",uVar3);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: freq_diff_steps          = %d\n","freq_tuning.c",0x887,
              "freq_tuning_adjust_result_according_to_hash_rate",iVar4);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: freq_diff_steps_extra    = %d\n","freq_tuning.c",0x888,
              "freq_tuning_adjust_result_according_to_hash_rate",extraout_r1);
    }
    fclose(pFVar5);
  }
  freq_diff_steps_extra = extraout_r1;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      freq_diff = iVar2 * iVar4;
      if (freq_diff_steps_extra != 0) {
        freq_diff = freq_diff + iVar2;
        freq_diff_steps_extra = freq_diff_steps_extra + -1;
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: Adjust frequency %dM for chain %d.\n","freq_tuning.c",0x898,
                  "freq_tuning_adjust_result_according_to_hash_rate",freq_diff,chain);
        }
        fclose(pFVar5);
      }
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        freq_info->freq_table[chain][asic] = freq_info->freq_table[chain][asic] - freq_diff;
      }
    }
  }
  return freq_diff;
}

