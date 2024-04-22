
/* WARNING: Unknown calling convention */

void freq_tuning_test_based_voltage_domain(void)

{
  pthread_t nonce_receive_id;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  freq_tuning_info *freq_info;
  _Bool reset_after_unbalance;
  _Bool is_need_read_temp;
  int sub_proj_index;
  
  is_need_read_temp = true;
  reset_after_unbalance = false;
  freq_info = freq_tuning_create_info();
  if (freq_info != (freq_tuning_info *)0x0) {
    pthread_create(&nonce_receive_id,(pthread_attr_t *)0x0,freq_tuning_recv_nonce_and_register,
                   freq_info);
    pthread_detach(nonce_receive_id);
    freq_tuning_config_dump();
    memset(g_chain_unbalance,0,0x10);
    reset_after_unbalance = false;
    while( true ) {
      freq_tuning_env_init(is_need_read_temp,freq_info);
      is_need_read_temp = false;
      freq_tuning_init_freq_info(freq_info);
      sub_proj_index = 0;
      while( true ) {
        if (g_BHB91602_proj.sub_proj_count <= sub_proj_index) goto DONE;
        g_init_freq = (int)init_freq;
        set_pwm((uchar)g_BHB91602_proj.conf_list[sub_proj_index].fan_pwm);
        freq_tuning_pattern_test(freq_info,sub_proj_index);
        if (freq_info->is_unbalance_happened != false) break;
        if (freq_info->is_pass != true) {
          g_BHB91602_proj.conf_list[sub_proj_index].base_voltage =
               g_BHB91602_proj.conf_list[sub_proj_index].base_voltage + 0x14;
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFile_2 = (FILE *)fopen(log_file,"a+");
            if (pFile_2 != (FILE *)0x0) {
              fprintf((FILE *)pFile_2,
                      "%s:%d:%s: Frequency tuning: not pass, will try again, voltage change to %d.\n"
                      ,"freq_tuning.c",0xb07,"freq_tuning_test_based_voltage_domain",
                      g_BHB91602_proj.conf_list[sub_proj_index].base_voltage);
            }
            fclose((FILE *)pFile_2);
          }
          sub_proj_index = sub_proj_index + -1;
        }
        if (sub_proj_index != g_BHB91602_proj.sub_proj_count + -1) {
          freq_tuning_init_freq_info(freq_info);
          freq_tuning_hash_board_init(freq_info);
        }
        sub_proj_index = sub_proj_index + 1;
      }
      if (reset_after_unbalance == true) break;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          fprintf((FILE *)pFile,"%s:%d:%s: [Note] first unbalance happened, will enter re-init!!!\n"
                  ,"freq_tuning.c",0xaf5,"freq_tuning_test_based_voltage_domain");
        }
        fclose((FILE *)pFile);
      }
      reset_after_unbalance = true;
      freq_tuning_init_freq_info(freq_info);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile_1 = (FILE *)fopen(log_file,"a+");
      if (pFile_1 != (FILE *)0x0) {
        fprintf((FILE *)pFile_1,
                "%s:%d:%s: [Note] second unbalance happened, save unbalance result and exit freq tuning!!!\n"
                ,"freq_tuning.c",0xafc,"freq_tuning_test_based_voltage_domain");
      }
      fclose((FILE *)pFile_1);
    }
    freq_tuning_mark_unbalance_chain(freq_info);
DONE:
    eeprom_flush();
    freq_tuning_done_mark();
    free(freq_info);
    freq_info = (freq_tuning_info *)0x0;
    pthread_cancel(nonce_receive_id);
  }
  return;
}

