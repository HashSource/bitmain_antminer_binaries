
void freq_tuning_get_ideal_hash_rate(freq_tuning_info *freq_info,int sub_proj_index)

{
  uint uVar1;
  FILE *pFVar2;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  FILE *pFile_1;
  int ideal_hash_rate;
  int total_hash_rate;
  double hash_rate;
  int min_freq;
  int asic;
  int chain;
  
  min_freq = 0xffff;
  total_hash_rate = 0;
  freq_tuning_reset_global_arg();
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      freq_info->test_done[chain] = false;
      chain_ValidNonce[chain] = 0x7e00;
    }
  }
  freq_tuning_pre_open_core(freq_info);
  freq_tuning_hash_board_init(freq_info);
  freq_tuning_set_vol_all_chain(sub_proj_index);
  freq_tuning_increase_final_freq_slowly(freq_info,(int)init_freq,(int)freq_step);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        if (freq_info->freq_table[chain][asic] < min_freq) {
          min_freq = freq_info->freq_table[chain][asic];
        }
      }
    }
  }
  freq_tuning_set_time_control_by_freq(min_freq);
  if (gBegin_get_nonce != true) {
    uVar1 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar1 | 0x10000);
    gBegin_get_nonce = true;
  }
  freq_tuning_send_work(freq_info);
  freq_tuning_wait_recv_nonce(freq_info);
  gBegin_get_nonce = false;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      hash_rate = 0.0;
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        hash_rate = hash_rate +
                    (double)(longlong)
                            ((asic_nonce_num[chain][asic] * freq_info->freq_table[chain][asic]) /
                            1000);
      }
      freq_info->ideal_hash_rate[chain] = (int)(longlong)hash_rate;
      total_hash_rate = total_hash_rate + (int)(longlong)hash_rate;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: CH[%d] ideal_hash_rate = %d\n","freq_tuning.c",0x7ac,
                  "freq_tuning_get_ideal_hash_rate",chain,freq_info->ideal_hash_rate[chain]);
        }
        fclose(pFVar2);
      }
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Ideal total hash rate = %d\n","freq_tuning.c",0x7af,
              "freq_tuning_get_ideal_hash_rate",total_hash_rate);
    }
    fclose(pFVar2);
  }
  return;
}

