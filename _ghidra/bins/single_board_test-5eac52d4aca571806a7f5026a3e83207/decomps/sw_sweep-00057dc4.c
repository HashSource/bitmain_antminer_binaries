
int sw_sweep(float **matrix,uint8_t **state)

{
  int iVar1;
  int iVar2;
  double dVar3;
  undefined8 uStack_1b0;
  int aiStack_1a8 [2];
  uint8_t **state_local;
  float **matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  char lcd_info_1 [16];
  char lcd_info [16];
  int trytime;
  float avg_freq;
  float max;
  float min;
  float_0_ *last_matrix;
  int local_30;
  int len;
  int sweep_res;
  float freq;
  
  len = (g_rt.config)->asics_in_domain * (g_rt.config)->domains;
  state_local = state;
  matrix_local = matrix;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matix len%d\n","sw_sweep",len);
  snprintf(tmp1,0x100,"matix len%d",len);
  log_to_file(tmp1,time_stamp);
  local_30 = len + -1;
  iVar2 = -(len * 4 + 10U & 0xfffffff8);
  last_matrix = (float_0_ *)((int)&state_local + iVar2);
  trytime = 0;
  sweep_res = 0;
  clear_bad_asic_ids();
  memcpy(last_matrix,*matrix_local,len << 2);
  freq = g_rt.sweep.range_freq[0];
  do {
    if (g_rt.sweep.range_freq[1] < freq) {
LAB_000583fe:
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep end\n","sw_sweep");
      builtin_strncpy(tmp1,"sweep en",8);
      tmp1[8] = 'd';
      tmp1[9] = '\0';
      log_to_file(tmp1,time_stamp);
      sweep_end_power_down();
      if (sweep_res == 0) {
        if ((int)((uint)(g_rt.nonce_rate < 0.98) << 0x1f) < 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : test over but not nonce rate err,nonce_rate:%f\n","sw_sweep",
                 SUB84((double)g_rt.nonce_rate,0),(int)((ulonglong)(double)g_rt.nonce_rate >> 0x20))
          ;
          *(double *)((int)&uStack_1b0 + iVar2) = (double)g_rt.nonce_rate;
          snprintf(tmp1,0x100,"test over but not nonce rate err,nonce_rate:%f");
          log_to_file(tmp1,time_stamp);
          set_sweep_err_state(0xe,false);
          iVar2 = -1;
        }
        else {
          dump_matrix_freq(*matrix_local,(g_rt.config)->domains,(g_rt.config)->asics_in_domain);
          g_rt.sweep.sweep_end_time._0_4_ = time((time_t *)0x0);
          g_rt.sweep.sweep_end_time._4_4_ = (time_t)g_rt.sweep.sweep_end_time >> 0x1f;
          min = get_freq_matrix_min(*matrix_local,len);
          max = get_freq_matrix_max(*matrix_local,len);
          avg_freq = get_matrix_freq_avg(*matrix_local);
          snprintf(lcd_info,0x10,"%d",(int)avg_freq);
          lcd_common_show("Sweep freq",lcd_info,(char *)0x0);
          iVar2 = 0;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : sweep run err,exit.\n","sw_sweep");
        builtin_strncpy(tmp1,"sweep run err,exit.",0x14);
        log_to_file(tmp1,time_stamp);
        iVar2 = -1;
      }
      return iVar2;
    }
    if (sw_break != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : usr stop sweep!\n","sw_sweep");
      builtin_strncpy(tmp1,"usr stop sweep!",0x10);
      log_to_file(tmp1,time_stamp);
      goto LAB_000583fe;
    }
    sweep_res = 0;
    if ((trytime == 1) && (g_rt.sweep.mode == 1)) {
      trytime = 2;
      online_mode_retry_test((g_rt.config)->chain);
      g_pwm_enable = true;
      sweep_res = sweep_online_mode((float *)last_matrix,freq,&trytime,true,*state_local);
    }
    else if (g_rt.sweep.mode == 0) {
      sweep_res = sweep_over_mode(*matrix_local);
    }
    else {
      if (g_rt.sweep.mode != 1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : not support sweep mode\n","sw_sweep");
        builtin_strncpy(tmp1,"not support sweep mo",0x14);
        tmp1[0x14] = 'd';
        tmp1[0x15] = 'e';
        tmp1[0x16] = '\0';
        log_to_file(tmp1,time_stamp);
        sweep_end_power_down();
        return -1;
      }
      sweep_res = sweep_online_mode((float *)last_matrix,freq,&trytime,false,*state_local);
    }
    if (sweep_res != 0) goto LAB_000583fe;
    iVar1 = check_nonce_rate();
    if (((iVar1 != 0) || (iVar1 = check_unbalance(), iVar1 != 0)) ||
       (iVar1 = check_env_limit(), iVar1 != 0)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      dVar3 = (double)freq;
      *(int *)((int)aiStack_1a8 + iVar2 + -4) = trytime;
      *(int *)((int)&uStack_1b0 + iVar2) = g_rt.sweep.mode;
      printf("%s : current freq %f, mode %d, trytime %d\n\n","sw_sweep",SUB84(dVar3,0),
             (int)((ulonglong)dVar3 >> 0x20));
      dVar3 = (double)freq;
      *(int *)((int)aiStack_1a8 + iVar2 + 4) = trytime;
      *(int *)((int)aiStack_1a8 + iVar2) = g_rt.sweep.mode;
      *(double *)((int)&uStack_1b0 + iVar2) = dVar3;
      snprintf(tmp1,0x100,"current freq %f, mode %d, trytime %d\n");
      log_to_file(tmp1,time_stamp);
      if (g_rt.sweep.mode == 1) {
        if (trytime == 0) {
          trytime = 1;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : set retest flag\n","sw_sweep");
          builtin_strncpy(tmp1,"set retest flag",0x10);
          log_to_file(tmp1,time_stamp);
          memcpy(*matrix_local,last_matrix,len << 2);
          g_rt.sweep.sweep_online_time._0_4_ = time((time_t *)0x0);
          g_rt.sweep.sweep_online_time._4_4_ = (time_t)g_rt.sweep.sweep_online_time >> 0x1f;
          g_rt.sweep.sweep_online_min = get_freq_matrix_min(*matrix_local,(g_rt.config)->asics);
          g_rt.sweep.sweep_online_max = get_freq_matrix_max(*matrix_local,(g_rt.config)->asics);
          g_rt.sweep.sweep_online_avg = get_avg_matrix(*matrix_local,(g_rt.config)->asics);
          g_rt.sweep.sweep_online_var = get_var_matrix(*matrix_local,(g_rt.config)->asics);
          g_rt.sweep.sweep_online_nonce_rate = g_rt.nonce_rate;
          goto LAB_000583fe;
        }
        trytime = trytime + 1;
      }
      memcpy(*matrix_local,last_matrix,len << 2);
      goto LAB_000583fe;
    }
    set_matrix_state(state_local,(float *)last_matrix,matrix_local);
    set_succ_asic_nonce_state(*state_local);
    memcpy(last_matrix,*matrix_local,len << 2);
    freq = freq + g_rt.sweep.step;
    set_matrix(freq,matrix_local,state_local);
    snprintf(lcd_info_1,0x10,"%d",(int)freq);
    lcd_common_show("Test freq",lcd_info_1,(char *)0x0);
  } while( true );
}

