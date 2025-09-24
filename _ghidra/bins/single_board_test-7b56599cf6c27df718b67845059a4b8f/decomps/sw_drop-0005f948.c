
int sw_drop(float **matrix,uint8_t **state)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int aiStack_5b8 [2];
  uint8_t **state_local;
  float **matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  char lcd_info [16];
  sweep_result_t sr;
  eeprom_data_format_t *eep_ctx;
  int dropfreq;
  float avg_freq;
  float max;
  float min;
  int sweep_res;
  int trytime;
  int freq;
  float_0_ *last_matrix;
  int local_34;
  int len;
  int i_1;
  int k;
  int i;
  
  len = (g_rt.config)->asics_in_domain * (g_rt.config)->domains;
  state_local = state;
  matrix_local = matrix;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matix len%d\n","sw_drop",len);
  snprintf(tmp1,0x100,"matix len%d",len);
  log_to_file(tmp1,time_stamp);
  local_34 = len + -1;
  iVar3 = -(len * 4 + 10U & 0xfffffff8);
  last_matrix = (float_0_ *)((int)&state_local + iVar3);
  freq = 0;
  dropfreq = 0;
  trytime = 0;
  sweep_res = 0;
  clear_bad_asic_ids();
  read_eeprom((g_rt.config)->chain,&eep_ctx);
  if (eep_ctx == (eeprom_data_format_t *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : eeprom data read ERR!\n","sw_drop");
    builtin_strncpy(tmp1,"eeprom data read ERR!",0x16);
    log_to_file(tmp1,time_stamp);
    set_sweep_err_state(2,false);
    iVar3 = 2;
  }
  else {
    iVar1 = (*eep_ctx->pt2_result_get)(eep_ctx);
    if (iVar1 == 1) {
      iVar1 = (*eep_ctx->sweep_hashrate_get)(eep_ctx);
      if (iVar1 == 0x2b67) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : has drop down once, can not drop down!!!\n","sw_drop");
        builtin_strncpy(tmp1,"has drop down once, can not drop down!!!",0x28);
        tmp1[0x28] = '\0';
        log_to_file(tmp1,time_stamp);
        set_sweep_err_state(0x11,false);
        iVar3 = 0x11;
      }
      else {
        memset(&sr,0,0x40c);
        eeprom_get_sweep_result(&sr,eep_ctx);
        for (i = 0; i < len; i = i + 1) {
          (*matrix_local)[i] = (float)sr.freqs[i];
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : dump read eeporm freq matrix\n","sw_drop");
        builtin_strncpy(tmp1,"dump read eeporm freq matrix",0x1c);
        tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        dump_matrix_freq(*matrix_local,(g_rt.config)->domains,(g_rt.config)->asics_in_domain);
        freq = (*eep_ctx->frequency_get)(eep_ctx);
        iVar1 = level_down_freq(freq,&dropfreq);
        if (iVar1 == 0) {
          for (k = 0; k < (g_rt.config)->test_levels; k = k + 1) {
            if ((g_rt.config)->tests[k].freq <= dropfreq) {
              (g_rt.config)->sweeped_res_index = k;
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              iVar2 = (g_rt.config)->sweeped_res_index;
              iVar1 = (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].level;
              *(int *)((int)aiStack_5b8 + iVar3) =
                   (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].freq;
              printf("%s : dorp matched index:[%d] level:%d,freq:%d\n","sw_drop",iVar2,iVar1);
              iVar2 = (g_rt.config)->sweeped_res_index;
              iVar1 = (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].level;
              *(int *)((int)aiStack_5b8 + iVar3 + 4) =
                   (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].freq;
              *(int *)((int)aiStack_5b8 + iVar3) = iVar1;
              snprintf(tmp1,0x100,"dorp matched index:[%d] level:%d,freq:%d",iVar2);
              log_to_file(tmp1,time_stamp);
              break;
            }
          }
          for (i_1 = 0; i_1 < len; i_1 = i_1 + 1) {
            if ((float)(longlong)dropfreq < (*matrix_local)[i_1]) {
              if ((*matrix_local)[i_1] - (float)(longlong)dropfreq <= 5.0) {
                if ((*matrix_local)[i_1] - (float)(longlong)dropfreq <= 2.0) {
                  (*matrix_local)[i_1] =
                       (float)(longlong)dropfreq + (float)(longlong)(g_rt.config)->freq_flex;
                }
                else {
                  (*matrix_local)[i_1] =
                       (float)(longlong)(dropfreq + 2) + (float)(longlong)(g_rt.config)->freq_flex;
                }
              }
              else {
                (*matrix_local)[i_1] =
                     (float)(longlong)(dropfreq + 5) + (float)(longlong)(g_rt.config)->freq_flex;
              }
            }
          }
          free(eep_ctx);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : drop end\n","sw_drop");
          builtin_strncpy(tmp1,"drop end",8);
          tmp1._8_4_ = tmp1._8_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          sweep_end_power_down();
          dump_matrix_freq(*matrix_local,(g_rt.config)->domains,(g_rt.config)->asics_in_domain);
          g_rt.nonce_rate = 0.995;
          g_rt.recv_nonce = 0;
          g_rt.sweep.sweep_end_time._0_4_ = time((time_t *)0x0);
          g_rt.sweep.sweep_end_time._4_4_ = (time_t)g_rt.sweep.sweep_end_time >> 0x1f;
          min = get_freq_matrix_min(*matrix_local,len);
          max = get_freq_matrix_max(*matrix_local,len);
          avg_freq = get_matrix_freq_avg(*matrix_local);
          snprintf(lcd_info,0x10,"%d",(int)avg_freq);
          lcd_common_show("Drop freq",lcd_info,(char *)0x0);
          iVar3 = 0;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : is lowest level,can not to drop level!\n","sw_drop");
          builtin_strncpy(tmp1,"is lowest level,can not to drop level!",0x27);
          log_to_file(tmp1,time_stamp);
          set_sweep_err_state(0x11,false);
          free(eep_ctx);
          iVar3 = 0x11;
        }
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : not do pt2!\n","sw_drop");
      builtin_strncpy(tmp1,"not do pt2!",0xc);
      log_to_file(tmp1,time_stamp);
      set_sweep_err_state(1,false);
      free(eep_ctx);
      iVar3 = 1;
    }
  }
  return iVar3;
}

