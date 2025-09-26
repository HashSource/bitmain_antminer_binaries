
void get_conf(void *conf,sweep_ctx *sweep_info,int test_levels,int pt2_level,int chain,
             config_ctx *ctx,_Bool re_write_sweep_cfg)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  int pt2_level_local;
  int test_levels_local;
  sweep_ctx *sweep_info_local;
  void *conf_local;
  char time_stamp [48];
  char tmp1 [256];
  Local_Config_Info *info;
  int i_1;
  int max_freq;
  int i;
  
  if (conf == (void *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : conf is null\n\n","get_conf");
    builtin_strncpy(tmp1,"conf is null",0xc);
    tmp1[0xc] = '\n';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    ctx->is_super = *(char *)((int)conf + 0x1b5) != '\0';
    ctx->chain = chain;
    ctx->asics = *(int *)((int)conf + 0x40);
    ctx->domains = *(int *)((int)conf + 0x50);
    ctx->asics_in_domain = *(int *)((int)conf + 0x54);
    ctx->asic_domain_num = 4;
    ctx->big_core = *(int *)((int)conf + 0x44);
    ctx->asic_small_cores = *(int *)((int)conf + 0x48);
    ctx->samll_core_num_in_big_core = *(int *)((int)conf + 0x4c);
    ctx->patter_num = *(int *)((int)conf + 0x1d8);
    ctx->abnormal_core = 0x4f;
    ctx->interval = gAddress_interval;
    (ctx->reg).ccdly_sel = *(uint32_t *)((int)conf + 0x5bc);
    (ctx->reg).pwth_sel = *(uint32_t *)((int)conf + 0x5c0);
    (ctx->reg).swpf_mode = *(uint32_t *)((int)conf + 0x5c4);
    (ctx->reg).pulse_mode = *(uint32_t *)((int)conf + 0x5c8);
    (ctx->reg).clk_sel = *(uint32_t *)((int)conf + 0x5cc);
    (ctx->reg).ro_relay_en = *(uint32_t *)((int)conf + 0x5d0);
    (ctx->reg).co_relay_en = *(uint32_t *)((int)conf + 0x5d4);
    (ctx->reg).diode_vdd_mux_sel = *(uint32_t *)((int)conf + 0x5d8);
    (ctx->speed).baudrate = *(uint32_t *)((int)conf + 0x5b4);
    (ctx->speed).timeout = *(uint32_t *)((int)conf + 0x5b8);
    memcpy(&ctx->board,(void *)((int)conf + 0x30),0x10);
    (ctx->board).switch_sensor.read_from_switch = false;
    if (*(char *)((int)conf + 0x5b) == '\0') {
      (ctx->board).sensor.sensor_num = 2;
      memcpy(&(ctx->board).sensor,(void *)((int)conf + 0x7c),0x10);
      (ctx->board).sensor.sensor_addr[0] = *(uint32_t *)((int)conf + 0x8c);
      (ctx->board).sensor.sensor_addr[1] = *(uint32_t *)((int)conf + 0x90);
    }
    else {
      (ctx->board).switch_sensor.read_from_switch = true;
      (ctx->board).switch_sensor.switch_addr = (uint8_t)*(undefined4 *)((int)conf + 0xa4);
      (ctx->board).switch_sensor.switch_sensor_num = *(uint8_t *)((int)conf + 0xa8);
      (ctx->board).sensor.sensor_num = (uint)*(byte *)((int)conf + 0xa8);
      for (i = 0; i < (int)(uint)(ctx->board).switch_sensor.switch_sensor_num; i = i + 1) {
        (ctx->board).switch_sensor.switch_sensor_info[i].channel_id =
             *(uint8_t *)((int)conf + i * 0x16 + 0xaa);
        (ctx->board).switch_sensor.switch_sensor_info[i].power_supply_ctrlboard =
             *(_Bool *)((int)conf + i * 0x16 + 0xab);
        (ctx->board).switch_sensor.switch_sensor_info[i].sensor_addr =
             (uint8_t)*(undefined2 *)((int)conf + i * 0x16 + 0xbc);
        (ctx->board).switch_sensor.switch_sensor_info[i].bind_asic =
             (uint8_t)*(undefined2 *)((int)conf + i * 0x16 + 0xbe);
      }
    }
    (ctx->temp).cool_board_time = *(uint32_t *)((int)conf + 0x5e4);
    (ctx->temp).temp_gap = *(uint32_t *)((int)conf + 0x5dc);
    (ctx->temp).wait_cool_time = *(uint32_t *)((int)conf + 0x5e0);
    (ctx->fan).fan_speed = *(int *)((int)conf + 0x5ec);
    (ctx->fan).work_fan_speed = *(int *)((int)conf + 0x5f0);
    (ctx->standard).asic_nonce_rate = *(int *)((int)conf + 0x1f0);
    (ctx->standard).invalid_core_num = *(int *)((int)conf + 0x1dc);
    (ctx->standard).least_nonce_per_core = *(int *)((int)conf + 0x1e0);
    (ctx->standard).nonce_rate = *(int *)((int)conf + 0x1e4);
    ctx->freq_flex = *(int *)((int)conf + 0x5fc);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : freq_flex:%d\n","get_conf",ctx->freq_flex);
    snprintf(tmp1,0x100,"freq_flex:%d",ctx->freq_flex);
    log_to_file(tmp1,time_stamp);
    sweep_info->reuse = (uint)*(byte *)((int)conf + 0x1c4);
    sweep_info->bias = (float)(longlong)*(int *)((int)conf + 0x1c8) / 100.0;
    iVar2 = *(int *)((int)conf + 0x1c0);
    bVar3 = iVar2 == 0;
    if (bVar3) {
      iVar2 = 1;
    }
    bVar1 = (byte)iVar2;
    if (!bVar3) {
      bVar1 = 0;
    }
    sweep_info->mode = (uint)bVar1;
    if ((sweep_info->reuse == 0) || (re_write_sweep_cfg)) {
      sweep_info->voltage = *(uint32_t *)((int)conf + 0x1fc);
      sweep_info->range_freq[0] = (float)*(uint *)((int)conf + (test_levels + 0x1e) * 0x10 + 0x10);
      sweep_info->range_freq[1] =
           (float)(longlong)(int)(sweep_info->range_freq[0] * (sweep_info->bias + 1.0));
    }
    iVar2 = strncmp((char *)conf,"PT3",3);
    if ((iVar2 == 0) || (*(char *)((int)conf + 0x1c5) != '\0')) {
      if (pt2_level < 0) {
        sweep_info->range_freq[0] =
             (float)((*(int *)((int)conf + (test_levels + 0x1e) * 0x10 + 0x10) + ctx->freq_flex) -
                    0x19);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : pt2 test fail at last level,sweep level adjust from [%d]-->[%d]\n","get_conf",
               *(undefined4 *)((int)conf + (test_levels + 0x1e) * 0x10 + 0x10),
               *(int *)((int)conf + (test_levels + 0x1e) * 0x10 + 0x10) + -0x19);
        snprintf(tmp1,0x100,"pt2 test fail at last level,sweep level adjust from [%d]-->[%d]",
                 *(undefined4 *)((int)conf + (test_levels + 0x1e) * 0x10 + 0x10),
                 *(int *)((int)conf + (test_levels + 0x1e) * 0x10 + 0x10) + -0x19);
        log_to_file(tmp1,time_stamp);
      }
      else if (pt2_level < test_levels) {
        sweep_info->range_freq[0] =
             (float)(uint)(*(int *)((int)conf + (pt2_level + 0x1f) * 0x10 + 0x10) + ctx->freq_flex);
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : pt2 sweep cfg err!,pt2_level:%d,test_levels:%d\n","get_conf",pt2_level,
               test_levels);
        snprintf(tmp1,0x100,"pt2 sweep cfg err!,pt2_level:%d,test_levels:%d",pt2_level,test_levels);
        log_to_file(tmp1,time_stamp);
        sweep_info->range_freq[0] =
             (float)((*(int *)((int)conf + (test_levels + 0x1e) * 0x10 + 0x10) + ctx->freq_flex) -
                    0x19);
      }
      sweep_info->range_freq[1] =
           (float)(longlong)(int)(sweep_info->range_freq[0] * (sweep_info->bias + 1.0));
    }
    sweep_info->pre_open_core_voltage = *(uint32_t *)((int)conf + (test_levels + 3) * 0x10 + 0x1b8);
    if (*(char *)((int)conf + 0x1cd) != '\0') {
      sweep_info->range_freq[0] = (float)(longlong)*(int *)((int)conf + 0x1d0);
      sweep_info->range_freq[1] = (float)(longlong)*(int *)((int)conf + 0x1d4);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : forece reset freq from [%.0f] to [%.0f]\n","get_conf",
             SUB84((double)sweep_info->range_freq[0],0),
             (int)((ulonglong)(double)sweep_info->range_freq[0] >> 0x20),
             (double)sweep_info->range_freq[1]);
      snprintf(tmp1,0x100,"forece reset freq from [%.0f] to [%.0f]",tmp1,
               (double)sweep_info->range_freq[0],(double)sweep_info->range_freq[1]);
      log_to_file(tmp1,time_stamp);
    }
    max_freq = 0;
    for (i_1 = 0; i_1 < test_levels; i_1 = i_1 + 1) {
      ctx->tests[i_1].voltage = *(int *)((int)conf + (i_1 + 0x1f) * 0x10 + 0xc);
      ctx->tests[i_1].pre_open_core_voltage = *(int *)((int)conf + (i_1 + 4) * 0x10 + 0x1b8);
      ctx->tests[i_1].level = *(int *)((int)conf + (i_1 + 4) * 0x10 + 0x1b4);
      ctx->tests[i_1].freq = *(int *)((int)conf + (i_1 + 0x1f) * 0x10 + 0x10);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : cfg index[%d],level:[%d],freq:[%d]\n","get_conf",i_1,ctx->tests[i_1].level,
             ctx->tests[i_1].freq);
      snprintf(tmp1,0x100,"cfg index[%d],level:[%d],freq:[%d]",i_1,ctx->tests[i_1].level,
               ctx->tests[i_1].freq);
      log_to_file(tmp1,time_stamp);
      if (max_freq < ctx->tests[i_1].freq) {
        max_freq = ctx->tests[i_1].freq;
      }
    }
    if ((int)((uint)(sweep_info->range_freq[1] < (float)(longlong)(max_freq + ctx->freq_flex + 0x19)
                    ) << 0x1f) < 0) {
      sweep_info->range_freq[1] = (float)(longlong)(max_freq + ctx->freq_flex + 0x19);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : reset range[1]:%.2f\n","get_conf",SUB84((double)sweep_info->range_freq[1],0),
             (int)((ulonglong)(double)sweep_info->range_freq[1] >> 0x20));
      snprintf(tmp1,0x100,"reset range[1]:%.2f",tmp1,(double)sweep_info->range_freq[1]);
      log_to_file(tmp1,time_stamp);
    }
    ctx->test_levels = test_levels;
    ctx->sweeped_res_index = -1;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep_info:reuse:%d\n","get_conf",sweep_info->reuse);
    snprintf(tmp1,0x100,"sweep_info:reuse:%d",sweep_info->reuse);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep_info:bias:%f\n","get_conf",SUB84((double)sweep_info->bias,0),
           (int)((ulonglong)(double)sweep_info->bias >> 0x20));
    snprintf(tmp1,0x100,"sweep_info:bias:%f",tmp1,(double)sweep_info->bias);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep_info:mode:%d\n","get_conf",sweep_info->mode);
    snprintf(tmp1,0x100,"sweep_info:mode:%d",sweep_info->mode);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep_info:voltage:%d\n","get_conf",sweep_info->voltage);
    snprintf(tmp1,0x100,"sweep_info:voltage:%d",sweep_info->voltage);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sweep_info:range_freq:[%f],[%f]\n","get_conf",
           SUB84((double)sweep_info->range_freq[0],0),
           (int)((ulonglong)(double)sweep_info->range_freq[0] >> 0x20),
           (double)sweep_info->range_freq[1]);
    snprintf(tmp1,0x100,"sweep_info:range_freq:[%f],[%f]",tmp1,(double)sweep_info->range_freq[0],
             (double)sweep_info->range_freq[1]);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

