
void dump_config(config_ctx *ctx)

{
  config_ctx *ctx_local;
  char time_stamp [48];
  char tmp1 [256];
  char *table2;
  char *table1;
  int i_1;
  int i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ========dump config ==============\n","dump_config");
  builtin_strncpy(tmp1,"========dump config ============",0x20);
  tmp1[0x20] = '=';
  tmp1[0x21] = '=';
  tmp1[0x22] = '\0';
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : {\n","dump_config");
  tmp1[0] = '{';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %schain:%d\n","dump_config",&DAT_001ff430,ctx->chain);
  snprintf(tmp1,0x100,"%schain:%d",&DAT_001ff430,ctx->chain);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sasics:%d\n","dump_config",&DAT_001ff430,ctx->asics);
  snprintf(tmp1,0x100,"%sasics:%d",&DAT_001ff430,ctx->asics);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sdomains:%d\n","dump_config",&DAT_001ff430,ctx->domains);
  snprintf(tmp1,0x100,"%sdomains:%d",&DAT_001ff430,ctx->domains);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sasics_in_domain:%d\n","dump_config",&DAT_001ff430,ctx->asics_in_domain);
  snprintf(tmp1,0x100,"%sasics_in_domain:%d",&DAT_001ff430,ctx->asics_in_domain);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sasic_domain_num:%d\n","dump_config",&DAT_001ff430,ctx->asic_domain_num);
  snprintf(tmp1,0x100,"%sasic_domain_num:%d",&DAT_001ff430,ctx->asic_domain_num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sbig_core:%d\n","dump_config",&DAT_001ff430,ctx->big_core);
  snprintf(tmp1,0x100,"%sbig_core:%d",&DAT_001ff430,ctx->big_core);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sasic_small_cores:%d\n","dump_config",&DAT_001ff430,ctx->asic_small_cores);
  snprintf(tmp1,0x100,"%sasic_small_cores:%d",&DAT_001ff430,ctx->asic_small_cores);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %ssamll_core_num_in_big_core:%d\n","dump_config",&DAT_001ff430,
         ctx->samll_core_num_in_big_core);
  snprintf(tmp1,0x100,"%ssamll_core_num_in_big_core:%d",&DAT_001ff430,
           ctx->samll_core_num_in_big_core);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %spatter_num:%d\n","dump_config",&DAT_001ff430,ctx->patter_num);
  snprintf(tmp1,0x100,"%spatter_num:%d",&DAT_001ff430,ctx->patter_num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sabnormal_core:%d\n","dump_config",&DAT_001ff430,ctx->abnormal_core);
  snprintf(tmp1,0x100,"%sabnormal_core:%d",&DAT_001ff430,ctx->abnormal_core);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sinterval:%d\n","dump_config",&DAT_001ff430,ctx->interval);
  snprintf(tmp1,0x100,"%sinterval:%d",&DAT_001ff430,ctx->interval);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s{\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s{",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sccdly_sel:%d\n","dump_config","        ",(ctx->reg).ccdly_sel);
  snprintf(tmp1,0x100,"%sccdly_sel:%d","        ",(ctx->reg).ccdly_sel);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %spwth_sell:%d\n","dump_config","        ",(ctx->reg).pwth_sel);
  snprintf(tmp1,0x100,"%spwth_sell:%d","        ",(ctx->reg).pwth_sel);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sswpf_model:%d\n","dump_config","        ",(ctx->reg).swpf_mode);
  snprintf(tmp1,0x100,"%sswpf_model:%d","        ",(ctx->reg).swpf_mode);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %spulse_mode:%d\n","dump_config","        ",(ctx->reg).pulse_mode);
  snprintf(tmp1,0x100,"%spulse_mode:%d","        ",(ctx->reg).pulse_mode);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sclk_sel:%d\n","dump_config","        ",(ctx->reg).clk_sel);
  snprintf(tmp1,0x100,"%sclk_sel:%d","        ",(ctx->reg).clk_sel);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sro_relay_en:%d\n","dump_config","        ",(ctx->reg).ro_relay_en);
  snprintf(tmp1,0x100,"%sro_relay_en:%d","        ",(ctx->reg).ro_relay_en);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sco_relay_en:%d\n","dump_config","        ",(ctx->reg).co_relay_en);
  snprintf(tmp1,0x100,"%sco_relay_en:%d","        ",(ctx->reg).co_relay_en);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sdiode_vdd_mux_sel:%d\n","dump_config","        ",(ctx->reg).diode_vdd_mux_sel);
  snprintf(tmp1,0x100,"%sdiode_vdd_mux_sel:%d","        ",(ctx->reg).diode_vdd_mux_sel);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s}\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s}",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s{\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s{",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sbaudrate:%d\n","dump_config","        ",(ctx->speed).baudrate);
  snprintf(tmp1,0x100,"%sbaudrate:%d","        ",(ctx->speed).baudrate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %stimeout:%d\n","dump_config","        ",(ctx->speed).timeout);
  snprintf(tmp1,0x100,"%stimeout:%d","        ",(ctx->speed).timeout);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s}\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s}",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s{\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s{",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sasic_type:%s\n","dump_config","        ",&ctx->board);
  snprintf(tmp1,0x100,"%sasic_type:%s","        ",&ctx->board);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %swait_temp:%d\n","dump_config","        ",(ctx->board).wait_temp);
  snprintf(tmp1,0x100,"%swait_temp:%d","        ",(ctx->board).wait_temp);
  log_to_file(tmp1,time_stamp);
  if ((ctx->board).switch_sensor.read_from_switch != false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %ssenor_name:%s\n","dump_config","        ",&(ctx->board).sensor);
    snprintf(tmp1,0x100,"%ssenor_name:%s","        ",&(ctx->board).sensor);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %sswitch addr:0x%x\n","dump_config","        ",
           (uint)(ctx->board).switch_sensor.switch_addr);
    snprintf(tmp1,0x100,"%sswitch addr:0x%x","        ",(uint)(ctx->board).switch_sensor.switch_addr
            );
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %ssenor_num:%d\n","dump_config","        ",
           (uint)(ctx->board).switch_sensor.switch_sensor_num);
    snprintf(tmp1,0x100,"%ssenor_num:%d","        ",
             (uint)(ctx->board).switch_sensor.switch_sensor_num);
    log_to_file(tmp1,time_stamp);
    for (i = 0; i < (int)(uint)(ctx->board).switch_sensor.switch_sensor_num; i = i + 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %ssenor_id_%d,supply_by_ctrl:%d,sensor_addr:0x%x,bind_asic:%d,channel_id:%d\n",
             "dump_config","        ",i,
             (uint)(ctx->board).switch_sensor.switch_sensor_info[i].power_supply_ctrlboard,
             (uint)(ctx->board).switch_sensor.switch_sensor_info[i].sensor_addr,
             (uint)(ctx->board).switch_sensor.switch_sensor_info[i].bind_asic,
             (uint)(ctx->board).switch_sensor.switch_sensor_info[i].channel_id);
      snprintf(tmp1,0x100,
               "%ssenor_id_%d,supply_by_ctrl:%d,sensor_addr:0x%x,bind_asic:%d,channel_id:%d",
               "        ",i,
               (uint)(ctx->board).switch_sensor.switch_sensor_info[i].power_supply_ctrlboard,
               (uint)(ctx->board).switch_sensor.switch_sensor_info[i].sensor_addr,
               (uint)(ctx->board).switch_sensor.switch_sensor_info[i].bind_asic,
               (uint)(ctx->board).switch_sensor.switch_sensor_info[i].channel_id);
      log_to_file(tmp1,time_stamp);
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %ssenor_name:%s\n","dump_config","        ",&(ctx->board).sensor);
  snprintf(tmp1,0x100,"%ssenor_name:%s","        ",&(ctx->board).sensor);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %ssensor_addr:[%d,%d]\n","dump_config","        ",(ctx->board).sensor.sensor_addr[0],
         (ctx->board).sensor.sensor_addr[1]);
  snprintf(tmp1,0x100,"%ssensor_addr:[%d,%d]","        ",(ctx->board).sensor.sensor_addr[0],
           (ctx->board).sensor.sensor_addr[1]);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %ssensor_num:%d\n","dump_config","        ",(ctx->board).sensor.sensor_num);
  snprintf(tmp1,0x100,"%ssensor_num:%d","        ",(ctx->board).sensor.sensor_num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s}\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s}",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s{\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s{",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %stemp_gap:%d\n","dump_config","        ",(ctx->temp).temp_gap);
  snprintf(tmp1,0x100,"%stemp_gap:%d","        ",(ctx->temp).temp_gap);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %swait_cool_time:%d\n","dump_config","        ",(ctx->temp).wait_cool_time);
  snprintf(tmp1,0x100,"%swait_cool_time:%d","        ",(ctx->temp).wait_cool_time);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %scool_board_time:%d\n","dump_config","        ",(ctx->temp).cool_board_time);
  snprintf(tmp1,0x100,"%scool_board_time:%d","        ",(ctx->temp).cool_board_time);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s}\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s}",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s{\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s{",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sfan_speed:%d\n","dump_config","        ",(ctx->fan).fan_speed);
  snprintf(tmp1,0x100,"%sfan_speed:%d","        ",(ctx->fan).fan_speed);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %swork_fan_speed:%d\n","dump_config","        ",(ctx->fan).work_fan_speed);
  snprintf(tmp1,0x100,"%swork_fan_speed:%d","        ",(ctx->fan).work_fan_speed);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s}\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s}",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s{\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s{",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sinvalid_core_num:%d\n","dump_config","        ",(ctx->standard).invalid_core_num);
  snprintf(tmp1,0x100,"%sinvalid_core_num:%d","        ",(ctx->standard).invalid_core_num);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sleast_nonce_per_core:%d\n","dump_config","        ",
         (ctx->standard).least_nonce_per_core);
  snprintf(tmp1,0x100,"%sleast_nonce_per_core:%d","        ",(ctx->standard).least_nonce_per_core);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %sasic_nonce_rate:%d\n","dump_config","        ",(ctx->standard).asic_nonce_rate);
  snprintf(tmp1,0x100,"%sasic_nonce_rate:%d","        ",(ctx->standard).asic_nonce_rate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %snonce_rate:%d\n","dump_config","        ",(ctx->standard).nonce_rate);
  snprintf(tmp1,0x100,"%snonce_rate:%d","        ",(ctx->standard).nonce_rate);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s}\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s}",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s{\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s{",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  for (i_1 = 0; i_1 < 0xb; i_1 = i_1 + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %stests[%d]:\n","dump_config","        ",i_1);
    snprintf(tmp1,0x100,"%stests[%d]:","        ",i_1);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %slevel:%d\n","dump_config","        ",ctx->tests[i_1].level);
    snprintf(tmp1,0x100,"%slevel:%d","        ",ctx->tests[i_1].level);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %spre_open_core_voltage:%d\n","dump_config","        ",
           ctx->tests[i_1].pre_open_core_voltage);
    snprintf(tmp1,0x100,"%spre_open_core_voltage:%d","        ",
             ctx->tests[i_1].pre_open_core_voltage);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %sfreq:%d\n","dump_config","        ",ctx->tests[i_1].freq);
    snprintf(tmp1,0x100,"%sfreq:%d","        ",ctx->tests[i_1].freq);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %svoltage:%d\n","dump_config","        ",ctx->tests[i_1].voltage);
    snprintf(tmp1,0x100,"%svoltage:%d","        ",ctx->tests[i_1].voltage);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s}\n","dump_config",&DAT_001ff430);
  snprintf(tmp1,0x100,"%s}",&DAT_001ff430);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : }\n","dump_config");
  tmp1[0] = '}';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  return;
}

