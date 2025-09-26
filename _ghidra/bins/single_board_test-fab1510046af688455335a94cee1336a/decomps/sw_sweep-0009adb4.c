
int sw_sweep(float **matrix,uint8_t **state)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float_0_ *pfVar4;
  _Bool reinit_00;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  double dVar9;
  undefined8 uStack_8f8;
  undefined8 uStack_8f0;
  double dStack_8e8;
  float_0_ afStack_8e0 [4];
  undefined1 *local_8dc;
  int local_8d8;
  uint local_8d4;
  int local_8d0;
  uint local_8cc;
  int local_8c8;
  uint local_8c4;
  uint8_t **state_local;
  float **matrix_local;
  char time_stamp [48];
  char tmp42 [256];
  char lcd_info_1 [16];
  char lcd_info [16];
  int trytime;
  float avg_freq;
  float max;
  float min;
  float_0_ *matrix_tmp;
  int local_54;
  float_0_ *succ_matrix;
  int local_4c;
  float_0_ *last_matrix;
  int local_44;
  int len;
  int i;
  _Bool reinit;
  int sweep_res;
  float freq;
  float succ_nonce_rate;
  
  local_8dc = (undefined1 *)&uStack_8f8;
  len = (g_rt.config)->asics_in_domain * (g_rt.config)->domains;
  state_local = state;
  matrix_local = matrix;
  snprintf(tmp42,0x100,"matix len%d",len);
  puts(tmp42);
  local_44 = len + -1;
  local_8c4 = (uint)len >> 0x1b;
  local_8c8 = len << 5;
  local_8cc = (uint)len >> 0x1b;
  local_8d0 = len << 5;
  iVar7 = -(len * 4 + 10U & 0xfffffff8);
  last_matrix = afStack_8e0 + iVar7;
  local_4c = len + -1;
  local_8d4 = (uint)len >> 0x1b;
  local_8d8 = len << 5;
  iVar1 = -(len * 4 + 10U & 0xfffffff8);
  succ_matrix = afStack_8e0 + iVar1 + iVar7;
  local_54 = len + -1;
  iVar2 = -(len * 4 + 10U & 0xfffffff8);
  matrix_tmp = afStack_8e0 + iVar2 + iVar1 + iVar7;
  succ_nonce_rate = 0.0;
  trytime = 0;
  sweep_res = 0;
  reinit = true;
  clear_bad_asic_ids();
  for (i = 0; i < (g_rt.config)->asics; i = i + 1) {
    (*matrix_local)[i] = g_rt.sweep.range_freq[0];
  }
  if (g_rt.sweep.range_freq[0] == 410.0) {
    builtin_strncpy(tmp42,"bm1370 freq 410 no need to do sweep",0x24);
    puts(tmp42);
    g_rt.nonce_rate = 0.995;
    succ_nonce_rate = 0.995;
    memcpy(succ_matrix,*matrix_local,len << 2);
  }
  else {
    memcpy(last_matrix,*matrix_local,len << 2);
    freq = g_rt.sweep.range_freq[0];
    while (freq <= g_rt.sweep.range_freq[1]) {
      if (sw_break != 0) {
        builtin_strncpy(tmp42,"usr stop sweep!",0x10);
        puts(tmp42);
        break;
      }
      snprintf(lcd_info_1,0x10,"%d",(int)freq);
      lcd_common_show("Sweep doing","Test freq",lcd_info_1);
      reinit_00 = reinit;
      pfVar4 = last_matrix;
      uVar3 = tmp42._20_4_;
      sweep_res = 0;
      if ((trytime == 1) && (g_rt.sweep.mode == 1)) {
        trytime = 2;
        online_mode_retry_test((g_rt.config)->chain);
        pfVar4 = last_matrix;
        pfVar5 = *matrix_local;
        *(uint8_t **)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = *state_local;
        sweep_res = sweep_online_mode(pfVar5,(float *)pfVar4,freq,&trytime,true,
                                      *(uint8_t **)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7));
      }
      else if (g_rt.sweep.mode == 0) {
        sweep_res = sweep_over_mode(*matrix_local);
      }
      else {
        if (g_rt.sweep.mode != 1) {
          builtin_strncpy(tmp42,"not support sweep mode",0x17);
          tmp42[0x17] = SUB41(uVar3,3);
          puts(tmp42);
          sweep_end_power_down();
          return -1;
        }
        pfVar5 = *matrix_local;
        *(uint8_t **)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = *state_local;
        sweep_res = sweep_online_mode(pfVar5,(float *)pfVar4,freq,&trytime,reinit_00,
                                      *(uint8_t **)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7));
      }
      if (sweep_res != 0) break;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: current test freq: %f\n","sw_sweep",SUB84((double)freq,0),
             (int)((ulonglong)(double)freq >> 0x20));
      *(double *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = (double)freq;
      snprintf(tmp42,0x800,"current test freq: %f");
      log_to_file(tmp42,time_stamp);
      iVar6 = check_unbalance();
      if ((iVar6 != 0) || (iVar6 = check_nonce_rate(), iVar6 != 0)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        dVar9 = (double)freq;
        *(int *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7 + 4) = trytime;
        *(int *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = g_rt.sweep.mode;
        printf("%s: current freq %f, mode %d, trytime %d\n","sw_sweep",SUB84(dVar9,0),
               (int)((ulonglong)dVar9 >> 0x20));
        dVar9 = (double)freq;
        *(int *)((int)&uStack_8f0 + iVar2 + iVar1 + iVar7 + 4) = trytime;
        *(int *)((int)&uStack_8f0 + iVar2 + iVar1 + iVar7) = g_rt.sweep.mode;
        *(double *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = dVar9;
        snprintf(tmp42,0x800,"current freq %f, mode %d, trytime %d");
        log_to_file(tmp42,time_stamp);
        if (g_rt.sweep.mode == 1) {
          if (trytime == 0) {
            trytime = 1;
            builtin_strncpy(tmp42,"set retest flag",0x10);
            puts(tmp42);
            memcpy(*matrix_local,last_matrix,len << 2);
            g_rt.sweep.sweep_online_time._0_4_ = time((time_t *)0x0);
            g_rt.sweep.sweep_online_time._4_4_ = (time_t)g_rt.sweep.sweep_online_time >> 0x1f;
            g_rt.sweep.sweep_online_min = get_freq_matrix_min(*matrix_local,(g_rt.config)->asics);
            g_rt.sweep.sweep_online_max = get_freq_matrix_max(*matrix_local,(g_rt.config)->asics);
            g_rt.sweep.sweep_online_avg = get_avg_matrix(*matrix_local,(g_rt.config)->asics);
            g_rt.sweep.sweep_online_var = get_var_matrix(*matrix_local,(g_rt.config)->asics);
            g_rt.sweep.sweep_online_nonce_rate = g_rt.nonce_rate;
            break;
          }
          trytime = trytime + 1;
        }
        memcpy(*matrix_local,last_matrix,len << 2);
        break;
      }
      memcpy(last_matrix,*matrix_local,len << 2);
      memset(*state_local,1,len);
      set_matrix_state(state_local);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      iVar6 = ((g_rt.config)->standard).nonce_rate;
      *(double *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = (double)g_rt.nonce_rate;
      printf("%s: g_rt.config->standard.nonce_rate: %d g_rt.nonce_rate %f\n","sw_sweep",iVar6);
      iVar6 = ((g_rt.config)->standard).nonce_rate;
      *(double *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = (double)g_rt.nonce_rate;
      snprintf(tmp42,0x800,"g_rt.config->standard.nonce_rate: %d g_rt.nonce_rate %f",iVar6);
      log_to_file(tmp42,time_stamp);
      if ((float)(longlong)((g_rt.config)->standard).nonce_rate < g_rt.nonce_rate * 10000.0) {
        succ_nonce_rate = g_rt.nonce_rate;
        memcpy(succ_matrix,*matrix_local,len << 2);
        set_asic_nonce_state();
        fVar8 = get_matrix_freq_avg(*matrix_local);
        if ((float)(longlong)((g_rt.config)->tests[0].freq + 0xf) < fVar8) break;
      }
      set_last_nonce_num();
      freq = freq + g_rt.sweep.step;
      set_matrix(freq,matrix_local,state_local);
      reinit = false;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      dVar9 = (double)freq;
      *(double *)((int)&uStack_8f0 + iVar2 + iVar1 + iVar7) = (double)g_rt.sweep.range_freq[1];
      *(double *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = (double)g_rt.sweep.range_freq[0];
      printf("%s: next test freq[%.2f], range_freq0[%.2f], range_freq1[%.2f]\n\n","sw_sweep",
             SUB84(dVar9,0),(int)((ulonglong)dVar9 >> 0x20));
      dVar9 = (double)freq;
      *(double *)((int)&dStack_8e8 + iVar2 + iVar1 + iVar7) = (double)g_rt.sweep.range_freq[1];
      *(double *)((int)&uStack_8f0 + iVar2 + iVar1 + iVar7) = (double)g_rt.sweep.range_freq[0];
      *(double *)((int)&uStack_8f8 + iVar2 + iVar1 + iVar7) = dVar9;
      snprintf(tmp42,0x800,"next test freq[%.2f], range_freq0[%.2f], range_freq1[%.2f]\n");
      log_to_file(tmp42,time_stamp);
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: sweep end\n\n","sw_sweep");
  builtin_strncpy(tmp42,"sweep en",8);
  tmp42[8] = 'd';
  tmp42[9] = '\n';
  tmp42[10] = '\0';
  log_to_file(tmp42,time_stamp);
  sweep_end_power_down();
  if (sweep_res == 0) {
    if (succ_nonce_rate == 0.0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: sweep failed at the beginning, or bad asic existed all the time\n","sw_sweep");
      builtin_strncpy(tmp42,"sweep failed at the beginning, or bad asic existed all the time",0x40);
      log_to_file(tmp42,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: reduce range_freq[0] or check handware error to sweep again\n","sw_sweep");
      builtin_strncpy(tmp42,"reduce range_freq[0] or check handware error to sweep again",0x3c);
      log_to_file(tmp42,time_stamp);
      iVar7 = -1;
    }
    else {
      memcpy(*matrix_local,succ_matrix,len << 2);
      g_rt.nonce_rate = succ_nonce_rate;
      puts("final sweep result");
      dump_matrix_freq(*matrix_local,(g_rt.config)->domains,(g_rt.config)->asics_in_domain);
      g_rt.sweep.sweep_end_time._0_4_ = time((time_t *)0x0);
      g_rt.sweep.sweep_end_time._4_4_ = (time_t)g_rt.sweep.sweep_end_time >> 0x1f;
      min = get_freq_matrix_min(*matrix_local,len);
      max = get_freq_matrix_max(*matrix_local,len);
      avg_freq = get_matrix_freq_avg(*matrix_local);
      if ((int)((uint)(avg_freq < 350.0) << 0x1f) < 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: freq lower than 350M\n","sw_sweep");
        builtin_strncpy(tmp42,"freq lower than 350M",0x14);
        tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
        log_to_file(tmp42,time_stamp);
        iVar7 = -1;
      }
      else {
        snprintf(lcd_info,0x10,"%d",(int)avg_freq);
        lcd_common_show("Sweep end","Sweep freq",lcd_info);
        iVar7 = get_bad_asic_num();
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = -1;
        }
      }
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: sweep run err,exit.\n","sw_sweep");
    builtin_strncpy(tmp42,"sweep run err,exit.",0x14);
    log_to_file(tmp42,time_stamp);
    iVar7 = -1;
  }
  return iVar7;
}

