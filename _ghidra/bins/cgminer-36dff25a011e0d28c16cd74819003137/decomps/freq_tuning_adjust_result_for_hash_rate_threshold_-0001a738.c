
void freq_tuning_adjust_result_for_hash_rate_threshold_S15_H
               (freq_tuning_info *freq_info,int sub_proj_index)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  FILE *pFVar5;
  int extraout_r1;
  int iVar6;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  int freq_diff_extra_S15_H [16];
  FILE *pFile_10;
  int freq_diff;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  int freq_diff_steps_extra;
  int freq_diff_steps;
  int hash_rate_steps;
  int hash_rate_step_MH;
  int freq_store_step;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int hash_rate_stable_MH;
  int hash_rate_target_sale_MH;
  int hash_rate_curr_MH;
  int hash_rate_max_MH;
  int GH;
  int TH;
  int hash_rate_threshold_MH;
  int asic;
  int chain;
  
  hash_rate_threshold_MH = g_BHB91602_proj.conf_list[sub_proj_index].max_hash_rate * 1000;
  iVar1 = freq_tuning_get_hash_rate_MH(freq_info);
  if (iVar1 <= hash_rate_threshold_MH) {
    iVar2 = __aeabi_idiv(hash_rate_threshold_MH,1000000);
    iVar4 = __aeabi_idiv(iVar1,1000000);
    hash_rate_threshold_MH = iVar4 * 1000000 + 450000;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: hash_rate_stable_MH      = %d\n","freq_tuning.c",0x91d,
                "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",hash_rate_threshold_MH);
      }
      fclose(pFVar5);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: hash_rate_target_sale_MH = %d\n","freq_tuning.c",0x91e,
                "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",iVar2 * 1000000);
      }
      fclose(pFVar5);
    }
    if ((iVar2 * 1000000 <= iVar1) || (iVar1 <= hash_rate_threshold_MH)) {
      if (log_level < 4) {
        return;
      }
      print_crt_time_to_file(log_file,3);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: Hash rate = %dMH, no need adjust\n","freq_tuning.c",0x926,
                "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",iVar1);
      }
      fclose(pFVar5);
      return;
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
      fprintf(pFVar5,"%s:%d:%s: hash_rate_curr_MH        = %d\n","freq_tuning.c",0x931,
              "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",iVar1);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_threshold_MH   = %d\n","freq_tuning.c",0x932,
              "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",hash_rate_threshold_MH);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: freq_store_step          = %d\n","freq_tuning.c",0x933,
              "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",iVar2);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_step_MH        = %d\n","freq_tuning.c",0x934,
              "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",iVar6);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: hash_rate_steps          = %d\n","freq_tuning.c",0x935,
              "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",uVar3);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: freq_diff_steps          = %d\n","freq_tuning.c",0x936,
              "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",iVar4);
    }
    fclose(pFVar5);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: freq_diff_steps_extra    = %d\n","freq_tuning.c",0x937,
              "freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",extraout_r1);
    }
    fclose(pFVar5);
  }
  memset(freq_diff_extra_S15_H,0,0x40);
  if (extraout_r1 == 2) {
LAB_0001aeb8:
    freq_diff_extra_S15_H[1] = 1;
  }
  else {
    if (extraout_r1 == 3) {
      freq_diff_extra_S15_H[0] = 1;
      goto LAB_0001aeb8;
    }
    if (extraout_r1 != 1) goto LAB_0001aecc;
  }
  freq_diff_extra_S15_H[2] = 1;
LAB_0001aecc:
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar1 = (freq_diff_extra_S15_H[chain] + iVar4) * iVar2;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,
                  "%s:%d:%s: Adjust frequency %dM for chain %d due to hash rate excceed target too much.\n"
                  ,"freq_tuning.c",0x950,"freq_tuning_adjust_result_for_hash_rate_threshold_S15_H",
                  iVar1,chain);
        }
        fclose(pFVar5);
      }
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        freq_info->freq_table[chain][asic] = freq_info->freq_table[chain][asic] - iVar1;
      }
    }
  }
  return;
}

