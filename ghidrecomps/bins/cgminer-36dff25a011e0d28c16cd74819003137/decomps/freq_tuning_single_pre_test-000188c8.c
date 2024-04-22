
_Bool freq_tuning_single_pre_test(freq_tuning_info *freq_info)

{
  freq_tuning_project_conf *pfVar1;
  _Bool _Var2;
  FILE *pFVar3;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  FILE *pFile_1;
  freq_tuning_project_conf *p_conf;
  _Bool is_pass;
  
  pfVar1 = g_BHB91602_proj.conf_list;
  is_pass = false;
  freq_tuning_init_freq_info(freq_info);
  freq_tuning_reset_global_arg();
  freq_tuning_set_vol_all_chain(0);
  increase_freq_slowly
            (init_freq,(float)(longlong)pfVar1->base_freq,(float)(longlong)DAT_00018aa4,All_Chain);
  freq_tuning_set_time_control_by_freq(pfVar1->base_freq);
  freq_tuning_send_work_and_check_result_all_chain(freq_info);
  _Var2 = freq_tuning_check_domain_unbalance();
  if (_Var2) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: Pre-test: unbalance happened.\n","freq_tuning.c",0x6ec,
                "freq_tuning_single_pre_test");
      }
      fclose(pFVar3);
    }
  }
  else {
    is_pass = true;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: Pre-test: already balance.\n","freq_tuning.c",0x6e8,
                "freq_tuning_single_pre_test");
      }
      fclose(pFVar3);
    }
  }
  return is_pass;
}

