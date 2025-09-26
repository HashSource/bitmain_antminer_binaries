
int sw_sweep(float **matrix,uint8_t **state)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  _Bool _Var5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  double dVar12;
  float fVar13;
  undefined8 uStack_268;
  undefined8 uStack_260;
  double adStack_258 [2];
  float_0_ afStack_248 [4];
  undefined1 *local_244;
  int local_240;
  uint local_23c;
  int local_238;
  uint local_234;
  int local_230;
  uint local_22c;
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
  int max_print_num_1;
  int max_print_num;
  float result;
  float standard;
  float_0_ *domain_freqs;
  int local_a8;
  float_0_ *succ_matrix;
  int local_a0;
  float_0_ *last_matrix;
  int local_98;
  int len;
  int i_7;
  int i_6;
  int idx_1;
  int k;
  float max_vol;
  float min_vol;
  int i_5;
  int i_4;
  int j;
  int i_3;
  int i_2;
  int idx;
  int i_1;
  int i;
  _Bool small_core_unbalance;
  int bad_asic_count;
  double min_asic_nonce_rate;
  float domain_minf;
  float domain_maxf;
  int sweep_count;
  int sweep_res;
  float freq;
  float succ_nonce_rate;
  
  local_244 = (undefined1 *)&uStack_268;
  len = (g_rt.config)->asics_in_domain * (g_rt.config)->domains;
  state_local = state;
  matrix_local = matrix;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : matix len%d\n","sw_sweep",len);
  snprintf(tmp1,0x100,"matix len%d",len);
  log_to_file(tmp1,time_stamp);
  local_98 = len + -1;
  local_22c = (uint)len >> 0x1b;
  local_230 = len << 5;
  local_234 = (uint)len >> 0x1b;
  local_238 = len << 5;
  iVar8 = -(len * 4 + 10U & 0xfffffff8);
  last_matrix = afStack_248 + iVar8;
  local_a0 = len + -1;
  local_23c = (uint)len >> 0x1b;
  local_240 = len << 5;
  iVar2 = -(len * 4 + 10U & 0xfffffff8);
  succ_matrix = afStack_248 + iVar2 + iVar8;
  succ_nonce_rate = 0.0;
  trytime = 0;
  sweep_res = 0;
  sweep_count = 0;
  local_a8 = (g_rt.config)->domains + -1;
  iVar3 = -((g_rt.config)->domains * 4 + 10U & 0xfffffff8);
  domain_freqs = afStack_248 + iVar3 + iVar2 + iVar8;
  clear_bad_asic_ids();
  min_asic_nonce_rate._0_4_ = 0;
  min_asic_nonce_rate._4_4_ = 0x3ff00000;
  bad_asic_count = 0;
  small_core_unbalance = false;
  memset(g_asic_need_repair_list,0,0x24);
  g_need_repair_asic_count = 0;
  if ((g_rt.config)->test_levels < 2) {
    g_rt.sweep.range_freq[0] = 460.0;
  }
  else {
    g_rt.sweep.range_freq[0] = 420.0;
  }
  for (i = 0; i < (g_rt.config)->asics; i = i + 1) {
    (*matrix_local)[i] = g_rt.sweep.range_freq[0];
  }
  memcpy(last_matrix,*matrix_local,len << 2);
  memset(sw_sweep::every_asic_got_nonce_num,0xff,0x200);
  freq = g_rt.sweep.range_freq[0];
  while( true ) {
    if (g_rt.sweep.range_freq[1] < freq) goto LAB_00063b34;
    if (sw_break != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : usr stop sweep!\n","sw_sweep");
      builtin_strncpy(tmp1,"usr stop sweep!",0x10);
      log_to_file(tmp1,time_stamp);
      goto LAB_00063b34;
    }
    sweep_res = 0;
    if ((trytime == 1) && (g_rt.sweep.mode == 1)) {
      trytime = 2;
      online_mode_retry_test((g_rt.config)->chain);
      g_pwm_enable = true;
      sweep_res = sweep_online_mode(*matrix_local,freq,&trytime,true,*state_local);
    }
    else if (g_rt.sweep.mode == 0) {
      sweep_res = sweep_over_mode(*matrix_local);
    }
    else {
      if (g_rt.sweep.mode != 1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : not support sweep mode\n","sw_sweep");
        builtin_strncpy(tmp1,"not support sweep mode",0x17);
        log_to_file(tmp1,time_stamp);
        sweep_end_power_down();
        return -1;
      }
      sweep_res = sweep_online_mode(*matrix_local,freq,&trytime,false,*state_local);
    }
    if (sweep_res != 0) goto LAB_00063b34;
    sweep_count = sweep_count + 1;
    if ((1 < sweep_count) &&
       (((iVar7 = check_nonce_rate(), iVar7 != 0 || (iVar7 = check_unbalance(), iVar7 != 0)) ||
        (iVar7 = check_env_limit(), iVar7 != 0)))) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      dVar12 = (double)freq;
      *(int *)((int)&uStack_268 + iVar3 + iVar2 + iVar8 + 4) = trytime;
      *(int *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = g_rt.sweep.mode;
      printf("%s : current freq %f, mode %d, trytime %d\n\n","sw_sweep",SUB84(dVar12,0),
             (int)((ulonglong)dVar12 >> 0x20));
      dVar12 = (double)freq;
      *(int *)((int)adStack_258 + iVar3 + iVar2 + iVar8 + -4) = trytime;
      *(int *)((int)&uStack_260 + iVar3 + iVar2 + iVar8) = g_rt.sweep.mode;
      *(double *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = dVar12;
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
          goto LAB_00063b34;
        }
        trytime = trytime + 1;
      }
      memcpy(*matrix_local,last_matrix,len << 2);
      goto LAB_00063b34;
    }
    set_matrix_state(state_local,(float *)last_matrix,matrix_local,
                     sw_sweep::every_asic_got_nonce_num);
    memcpy(sw_sweep::every_asic_got_nonce_num,g_rt.asic_stats.every_asic_got_nonce_num,0x200);
    min_asic_nonce_rate._0_4_ = 0;
    min_asic_nonce_rate._4_4_ = 0x3ff00000;
    bad_asic_count = 0;
    for (i_1 = 0; i_1 < (g_rt.config)->asics; i_1 = i_1 + 1) {
      if (g_rt.asic_stats.every_asic_nonce_rate[i_1] <=
          (double)CONCAT44(min_asic_nonce_rate._4_4_,min_asic_nonce_rate._0_4_)) {
        min_asic_nonce_rate._0_4_ = *(undefined4 *)(g_rt.asic_stats.every_asic_nonce_rate + i_1);
        min_asic_nonce_rate._4_4_ =
             *(undefined4 *)((int)g_rt.asic_stats.every_asic_nonce_rate + i_1 * 8 + 4);
      }
      if ((int)((uint)(g_rt.asic_stats.every_asic_nonce_rate[i_1] < 0.9) << 0x1f) < 0) {
        bad_asic_count = bad_asic_count + 1;
      }
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    *(int *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = bad_asic_count;
    printf("%s : min asic nonce rate %.4f, bad_asic_count %d\n","sw_sweep",min_asic_nonce_rate._0_4_
           ,min_asic_nonce_rate._4_4_);
    *(int *)((int)&uStack_260 + iVar3 + iVar2 + iVar8) = bad_asic_count;
    uVar4 = min_asic_nonce_rate._4_4_;
    *(undefined4 *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = min_asic_nonce_rate._0_4_;
    *(undefined4 *)((int)&uStack_268 + iVar3 + iVar2 + iVar8 + 4) = uVar4;
    snprintf(tmp1,0x100,"min asic nonce rate %.4f, bad_asic_count %d");
    log_to_file(tmp1,time_stamp);
    if ((int)((uint)((double)CONCAT44(min_asic_nonce_rate._4_4_,min_asic_nonce_rate._0_4_) < 0.8) <<
             0x1f) < 0) break;
    iVar7 = check_nonce_rate();
    if (iVar7 == 0) {
      succ_nonce_rate = g_rt.nonce_rate;
      memcpy(succ_matrix,*matrix_local,len << 2);
      set_asic_nonce_state();
      fVar10 = get_matrix_freq_avg(*matrix_local);
      iVar9 = (g_rt.config)->tests[0].freq;
      iVar7 = get_margin();
      if ((float)(longlong)(iVar7 + iVar9 + 4) < fVar10) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : reach highest level,break\n\n","sw_sweep");
        builtin_strncpy(tmp1,"reach highest level,break\n",0x1b);
        log_to_file(tmp1,time_stamp);
        goto LAB_00063b34;
      }
    }
    standard = 0.07;
    memset(domain_freqs,0,(g_rt.config)->domains << 2);
    for (i_3 = 0; i_3 < (g_rt.config)->domains; i_3 = i_3 + 1) {
      for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
        *(float *)(domain_freqs + i_3 * 4) =
             *(float *)(domain_freqs + i_3 * 4) +
             (*matrix_local)[j + i_3 * (g_rt.config)->asics_in_domain];
      }
    }
    domain_maxf = *(float *)domain_freqs;
    domain_minf = *(float *)domain_freqs;
    for (i_4 = 1; i_4 < (g_rt.config)->domains; i_4 = i_4 + 1) {
      if (-1 < (int)((uint)(*(float *)(domain_freqs + i_4 * 4) < domain_maxf) << 0x1f)) {
        domain_maxf = *(float *)(domain_freqs + i_4 * 4);
      }
      if (*(float *)(domain_freqs + i_4 * 4) <= domain_minf) {
        domain_minf = *(float *)(domain_freqs + i_4 * 4);
      }
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    dVar12 = (double)domain_maxf;
    *(double *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = (double)domain_minf;
    printf("%s : max domain freqs : %f , min domain freqs : %f\n","sw_sweep",SUB84(dVar12,0),
           (int)((ulonglong)dVar12 >> 0x20));
    dVar12 = (double)domain_maxf;
    *(double *)((int)&uStack_260 + iVar3 + iVar2 + iVar8) = (double)domain_minf;
    *(double *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = dVar12;
    snprintf(tmp1,0x100,"max domain freqs : %f , min domain freqs : %f");
    log_to_file(tmp1,time_stamp);
    result = (domain_maxf - domain_minf) / domain_minf;
    if (((standard <= result) && (_Var5 = is_ft("F1V02B5C1-2"), _Var5)) &&
       (pcVar6 = strstr((Local_Config_Information->Hash_Board).Board_Name,"70502"),
       pcVar6 != (char *)0x0)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      dVar12 = (double)result;
      *(double *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = (double)standard;
      printf("%s : domain freqs diff %f > %f, break test\n","sw_sweep",SUB84(dVar12,0),
             (int)((ulonglong)dVar12 >> 0x20));
      dVar12 = (double)result;
      *(double *)((int)&uStack_260 + iVar3 + iVar2 + iVar8) = (double)standard;
      *(double *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = dVar12;
      snprintf(tmp1,0x100,"domain freqs diff %f > %f, break test");
      log_to_file(tmp1,time_stamp);
      goto LAB_00063b34;
    }
    memcpy(last_matrix,*matrix_local,len << 2);
    freq = freq + g_rt.sweep.step;
    clear_bad_asic_ids();
    set_matrix(freq,matrix_local,state_local);
    snprintf(lcd_info_1,0x10,"%d",(int)freq);
    lcd_common_show("Test freq",lcd_info_1,(char *)0x0);
  }
  idx = 0;
  max_print_num = 5;
  for (i_2 = 0; i_2 < (g_rt.config)->asics; i_2 = i_2 + 1) {
    if ((int)((uint)(g_rt.asic_stats.every_asic_nonce_rate[i_2] < 0.9) << 0x1f) < 0) {
      iVar7 = i_2 + 0x1f;
      if (-1 < i_2) {
        iVar7 = i_2;
      }
      g_asic_need_repair_list[iVar7 >> 5] =
           g_asic_need_repair_list[iVar7 >> 5] | 1 << (i_2 % 0x20 & 0xffU);
      g_need_repair_asic_count = g_need_repair_asic_count + 1;
      if (idx == 0) {
        printf("bad asic need repair : ");
        builtin_strncpy(sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_2::
                        lexical_block_30_7_2_1::tmp1_6,"bad asic need repair : ",0x18);
        log_to_filex(sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_2::
                     lexical_block_30_7_2_1::tmp1_6,tmp1);
      }
      printf("%d ",i_2);
      snprintf(sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_2::
               lexical_block_30_7_2_2::tmp1_7,0x100,"%d ",i_2);
      log_to_filex(sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_2::
                   lexical_block_30_7_2_2::tmp1_7,tmp1);
      idx = idx + 1;
      if (idx == max_print_num) {
        putchar(10);
        sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_2::lexical_block_30_7_2_3
        ::tmp1_8[0] = '\n';
        sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_2::lexical_block_30_7_2_3
        ::tmp1_8[1] = '\0';
        log_to_filex(sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_2::
                     lexical_block_30_7_2_3::tmp1_8,tmp1);
        idx = 0;
      }
    }
  }
  if ((idx != 0) && (idx < max_print_num)) {
    putchar(10);
    sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_3::tmp1_9[0] = '\n';
    sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_3::tmp1_9[1] = '\0';
    log_to_filex(sw_sweep::lexical_block_30::lexical_block_30_7::lexical_block_30_7_3::tmp1_9,tmp1);
  }
  sweep_res = -1;
  set_sweep_err_state(0xe,false);
LAB_00063b34:
  cancle_pause_recv_nonce();
  print_chain_asic_domain_avg_voltage((uint8_t)(g_rt.config)->chain);
  pause_recv_nonce();
  small_core_unbalance = false;
  for (i_5 = 0; i_5 < (g_rt.config)->asics; i_5 = i_5 + 1) {
    if ((int)((uint)(g_rt.asic_stats.every_asic_nonce_rate[i_5] < 0.8) << 0x1f) < 0) {
      min_vol = 2.0;
      max_vol = 0.0;
      for (k = 0; k < 4; k = k + 1) {
        if (g_asic_vol_domain[(g_rt.config)->chain][i_5][k] <= min_vol) {
          min_vol = g_asic_vol_domain[(g_rt.config)->chain][i_5][k];
        }
        bVar1 = g_asic_vol_domain[(g_rt.config)->chain][i_5][k] < max_vol;
        max_vol = min_vol;
        if (-1 < (int)((uint)bVar1 << 0x1f)) {
          max_vol = g_asic_vol_domain[(g_rt.config)->chain][i_5][k];
        }
      }
      if (0.25 < (max_vol - min_vol) / min_vol) {
        small_core_unbalance = true;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : asic [%d] small core unbalance happened\n","sw_sweep",i_5);
        snprintf(tmp1,0x100,"asic [%d] small core unbalance happened",i_5);
        log_to_file(tmp1,time_stamp);
      }
    }
  }
  if (small_core_unbalance != false) {
    idx_1 = 0;
    max_print_num_1 = 5;
    for (i_6 = 0; i_6 < (g_rt.config)->asics; i_6 = i_6 + 1) {
      if ((int)((uint)(g_rt.asic_stats.every_asic_nonce_rate[i_6] < 0.9) << 0x1f) < 0) {
        iVar7 = i_6 + 0x1f;
        if (-1 < i_6) {
          iVar7 = i_6;
        }
        if ((1 << (i_6 % 0x20 & 0xffU) & ~g_asic_need_repair_list[iVar7 >> 5]) != 0) {
          iVar7 = i_6 + 0x1f;
          if (-1 < i_6) {
            iVar7 = i_6;
          }
          g_asic_need_repair_list[iVar7 >> 5] =
               g_asic_need_repair_list[iVar7 >> 5] | 1 << (i_6 % 0x20 & 0xffU);
          g_need_repair_asic_count = g_need_repair_asic_count + 1;
        }
        if (idx_1 == 0) {
          printf("bad asic need repair : ");
          builtin_strncpy(sw_sweep::lexical_block_32::lexical_block_32_2::lexical_block_32_2_1::
                          tmp1_14,"bad asic need repair : ",0x18);
          log_to_filex(sw_sweep::lexical_block_32::lexical_block_32_2::lexical_block_32_2_1::tmp1_14
                       ,tmp1);
        }
        printf("%d ",i_6);
        snprintf(sw_sweep::lexical_block_32::lexical_block_32_2::lexical_block_32_2_2::tmp1_15,0x100
                 ,"%d ",i_6);
        log_to_filex(sw_sweep::lexical_block_32::lexical_block_32_2::lexical_block_32_2_2::tmp1_15,
                     tmp1);
        idx_1 = idx_1 + 1;
        if (idx_1 == max_print_num_1) {
          putchar(10);
          sw_sweep::lexical_block_32::lexical_block_32_2::lexical_block_32_2_3::tmp1_16[0] = '\n';
          sw_sweep::lexical_block_32::lexical_block_32_2::lexical_block_32_2_3::tmp1_16[1] = '\0';
          log_to_filex(sw_sweep::lexical_block_32::lexical_block_32_2::lexical_block_32_2_3::tmp1_16
                       ,tmp1);
          idx_1 = 0;
        }
      }
    }
    if ((idx_1 != 0) && (idx_1 < max_print_num_1)) {
      putchar(10);
      sw_sweep::lexical_block_32::lexical_block_32_3::tmp1_17[0] = '\n';
      sw_sweep::lexical_block_32::lexical_block_32_3::tmp1_17[1] = '\0';
      log_to_filex(sw_sweep::lexical_block_32::lexical_block_32_3::tmp1_17,tmp1);
    }
    set_sweep_err_state(0x12,false);
    sweep_res = -1;
  }
  if (g_need_repair_asic_count != 0) {
    for (i_7 = 0; i_7 < (g_rt.config)->asics; i_7 = i_7 + 1) {
      iVar7 = i_7 + 0x1f;
      if (-1 < i_7) {
        iVar7 = i_7;
      }
      if ((1 << (i_7 % 0x20 & 0xffU) & g_asic_need_repair_list[iVar7 >> 5]) != 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        fVar13 = g_asic_vol_domain[(g_rt.config)->chain][i_7][0];
        fVar11 = g_asic_vol_domain[(g_rt.config)->chain][i_7][1];
        fVar10 = g_asic_vol_domain[(g_rt.config)->chain][i_7][2];
        *(double *)((int)adStack_258 + iVar3 + iVar2 + iVar8 + 8) =
             (double)g_asic_vol_domain[(g_rt.config)->chain][i_7][3];
        *(double *)((int)adStack_258 + iVar3 + iVar2 + iVar8) = (double)fVar10;
        *(double *)((int)&uStack_260 + iVar3 + iVar2 + iVar8) = (double)fVar11;
        *(double *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = (double)fVar13;
        printf("%s : need repair asic [%d] domain vol %f, %f, %f, %f\n","sw_sweep",i_7);
        fVar13 = g_asic_vol_domain[(g_rt.config)->chain][i_7][0];
        fVar11 = g_asic_vol_domain[(g_rt.config)->chain][i_7][1];
        fVar10 = g_asic_vol_domain[(g_rt.config)->chain][i_7][2];
        *(double *)((int)adStack_258 + iVar3 + iVar2 + iVar8 + 8) =
             (double)g_asic_vol_domain[(g_rt.config)->chain][i_7][3];
        *(double *)((int)adStack_258 + iVar3 + iVar2 + iVar8) = (double)fVar10;
        *(double *)((int)&uStack_260 + iVar3 + iVar2 + iVar8) = (double)fVar11;
        *(double *)((int)&uStack_268 + iVar3 + iVar2 + iVar8) = (double)fVar13;
        snprintf(tmp1,0x100,"need repair asic [%d] domain vol %f, %f, %f, %f",i_7);
        log_to_file(tmp1,time_stamp);
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : sweep end\n","sw_sweep");
  builtin_strncpy(tmp1,"sweep en",8);
  tmp1[8] = 'd';
  tmp1[9] = '\0';
  log_to_file(tmp1,time_stamp);
  sweep_end_power_down();
  if (sweep_res == 0) {
    if (succ_nonce_rate == 0.0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep failed at the beginning, or bad asic existed all the time\n","sw_sweep");
      builtin_strncpy(tmp1,"sweep failed at the beginning, or bad asic existed all the time",0x40);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : reduce range_freq[0] or check handware error to sweep again\n","sw_sweep");
      builtin_strncpy(tmp1,"reduce range_freq[0] or check handware error to sweep again",0x3c);
      log_to_file(tmp1,time_stamp);
      set_sweep_err_state(0xe,false);
      iVar8 = -1;
    }
    else {
      fresh_bad_asic_info(matrix_local,sweep_count);
      if (g_asic_bad_lit.bad_asic_num != 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : %d bad asic exists,sweep err\n\n","sw_sweep",g_asic_bad_lit.bad_asic_num);
        snprintf(tmp1,0x100,"%d bad asic exists,sweep err\n",g_asic_bad_lit.bad_asic_num);
        log_to_file(tmp1,time_stamp);
      }
      memcpy(*matrix_local,succ_matrix,len << 2);
      g_rt.nonce_rate = succ_nonce_rate;
      display_PCBA_result(*matrix_local,(uint8_t)(g_rt.config)->domains,
                          (uint8_t)(g_rt.config)->asics_in_domain,true);
      g_rt.sweep.sweep_end_time._0_4_ = time((time_t *)0x0);
      g_rt.sweep.sweep_end_time._4_4_ = (time_t)g_rt.sweep.sweep_end_time >> 0x1f;
      min = get_freq_matrix_min(*matrix_local,len);
      max = get_freq_matrix_max(*matrix_local,len);
      avg_freq = get_matrix_freq_avg(*matrix_local);
      snprintf(lcd_info,0x10,"%d",(int)avg_freq);
      lcd_common_show("Sweep freq",lcd_info,(char *)0x0);
      iVar8 = 0;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep run err,exit.\n","sw_sweep");
    builtin_strncpy(tmp1,"sweep run err,exit.",0x14);
    log_to_file(tmp1,time_stamp);
    iVar8 = -1;
  }
  return iVar8;
}

