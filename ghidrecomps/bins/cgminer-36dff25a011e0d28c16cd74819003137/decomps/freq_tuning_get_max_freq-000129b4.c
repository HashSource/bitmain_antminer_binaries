
_Bool freq_tuning_get_max_freq(int *p_max_freq)

{
  FILE *pFVar1;
  _Bool _Var2;
  int *p_max_freq_local;
  FILE *pFile;
  FILE *pFile_1;
  freq_tuning_project_conf *p_proj_conf;
  int proj_sub_type;
  int sub_proj_index;
  uint32_t max_freq_tmp;
  
  max_freq_tmp = (uint)(0.0 < init_freq) * (int)init_freq;
  freq_tuning_get_proj_type();
  if (g_BHB91602_proj.proj_type == 3) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Fail to get freq tuning max freq!\n","freq_tuning.c",0x11b,
                "freq_tuning_get_max_freq");
      }
      fclose(pFVar1);
    }
    _Var2 = false;
  }
  else {
    proj_sub_type = (int)(opt_bitmain_economic_mode == false);
    for (sub_proj_index = 0; sub_proj_index < g_BHB91602_proj.sub_proj_count;
        sub_proj_index = sub_proj_index + 1) {
      if (proj_sub_type == g_BHB91602_proj.conf_list[sub_proj_index].proj_sub_type) {
        max_freq_tmp = g_BHB91602_proj.conf_list[sub_proj_index].base_freq +
                       g_BHB91602_proj.conf_list[sub_proj_index].freq_step * 7;
        break;
      }
    }
    if ((p_max_freq != (int *)0x0) && (*p_max_freq = max_freq_tmp, 3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Max freq of tuning is %d\n","freq_tuning.c",0x135,
                "freq_tuning_get_max_freq",max_freq_tmp);
      }
      fclose(pFVar1);
    }
    _Var2 = true;
  }
  return _Var2;
}

