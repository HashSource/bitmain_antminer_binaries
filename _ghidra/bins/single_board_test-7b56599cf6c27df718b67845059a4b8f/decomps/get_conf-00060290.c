
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
  int i;
  int max_freq;
  
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
    ctx->chain = chain;
    ctx->asics = *(int *)((int)conf + 0x40);
    ctx->domains = *(int *)((int)conf + 0x50);
    ctx->asics_in_domain = *(int *)((int)conf + 0x54);
    ctx->asic_domain_num = 4;
    ctx->big_core = *(int *)((int)conf + 0x44);
    ctx->asic_small_cores = *(int *)((int)conf + 0x48);
    ctx->samll_core_num_in_big_core = *(int *)((int)conf + 0x4c);
    ctx->patter_num = *(int *)((int)conf + 0x110);
    ctx->abnormal_core = 0x4f;
    ctx->interval = gAddress_interval;
    (ctx->reg).ccdly_sel = *(uint32_t *)((int)conf + 0x450);
    (ctx->reg).pwth_sel = *(uint32_t *)((int)conf + 0x454);
    (ctx->reg).swpf_mode = *(uint32_t *)((int)conf + 0x458);
    (ctx->reg).pulse_mode = *(uint32_t *)((int)conf + 0x45c);
    (ctx->reg).clk_sel = *(uint32_t *)((int)conf + 0x460);
    (ctx->reg).ro_relay_en = *(uint32_t *)((int)conf + 0x464);
    (ctx->reg).co_relay_en = *(uint32_t *)((int)conf + 0x468);
    (ctx->reg).diode_vdd_mux_sel = *(uint32_t *)((int)conf + 0x46c);
    (ctx->speed).baudrate = *(uint32_t *)((int)conf + 0x448);
    (ctx->speed).timeout = *(uint32_t *)((int)conf + 0x44c);
    memcpy(&ctx->board,(void *)((int)conf + 0x30),0x10);
    (ctx->board).sensor.sensor_num = 2;
    memcpy(&(ctx->board).sensor,(void *)((int)conf + 0x7c),0x10);
    (ctx->board).sensor.sensor_addr[0] = *(uint32_t *)((int)conf + 0x8c);
    (ctx->board).sensor.sensor_addr[1] = *(uint32_t *)((int)conf + 0x90);
    (ctx->temp).cool_board_time = *(uint32_t *)((int)conf + 0x478);
    (ctx->temp).temp_gap = *(uint32_t *)((int)conf + 0x470);
    (ctx->temp).wait_cool_time = *(uint32_t *)((int)conf + 0x474);
    (ctx->fan).fan_speed = *(int *)((int)conf + 0x480);
    (ctx->fan).work_fan_speed = *(int *)((int)conf + 0x484);
    (ctx->standard).asic_nonce_rate = *(int *)((int)conf + 0x124);
    (ctx->standard).invalid_core_num = *(int *)((int)conf + 0x114);
    (ctx->standard).least_nonce_per_core = *(int *)((int)conf + 0x118);
    (ctx->standard).nonce_rate = *(int *)((int)conf + 0x11c);
    ctx->freq_flex = *(int *)((int)conf + 0x490);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : freq_flex:%d\n","get_conf",ctx->freq_flex);
    snprintf(tmp1,0x100,"freq_flex:%d",ctx->freq_flex);
    log_to_file(tmp1,time_stamp);
    sweep_info->reuse = (uint)*(byte *)((int)conf + 0xfc);
    sweep_info->bias = (float)(longlong)*(int *)((int)conf + 0x100) / 100.0;
    iVar2 = *(int *)((int)conf + 0xf8);
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
      sweep_info->voltage = *(uint32_t *)((int)conf + 0x130);
      sweep_info->range_freq[0] = (float)*(uint *)((int)conf + (test_levels + 1) * 0x10 + 0x114);
      sweep_info->range_freq[1] =
           (float)(longlong)(int)(sweep_info->range_freq[0] * (sweep_info->bias + 1.0));
    }
    iVar2 = strncmp((char *)conf,"PT3",3);
    if ((iVar2 == 0) || (*(char *)((int)conf + 0xfd) != '\0')) {
      if (pt2_level < 0) {
        sweep_info->range_freq[0] =
             (float)((*(int *)((int)conf + (test_levels + 1) * 0x10 + 0x114) + ctx->freq_flex) -
                    0x19);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : pt2 test fail at last level,sweep level adjust from [%d]-->[%d]\n","get_conf",
               *(undefined4 *)((int)conf + (test_levels + 1) * 0x10 + 0x114),
               *(int *)((int)conf + (test_levels + 1) * 0x10 + 0x114) + -0x19);
        snprintf(tmp1,0x100,"pt2 test fail at last level,sweep level adjust from [%d]-->[%d]",
                 *(undefined4 *)((int)conf + (test_levels + 1) * 0x10 + 0x114),
                 *(int *)((int)conf + (test_levels + 1) * 0x10 + 0x114) + -0x19);
        log_to_file(tmp1,time_stamp);
      }
      else if (pt2_level < test_levels) {
        sweep_info->range_freq[0] =
             (float)(uint)(*(int *)((int)conf + (pt2_level + 2) * 0x10 + 0x114) + ctx->freq_flex);
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : pt2 sweep cfg err!,pt2_level:%d,test_levels:%d\n","get_conf",pt2_level,
               test_levels);
        snprintf(tmp1,0x100,"pt2 sweep cfg err!,pt2_level:%d,test_levels:%d",pt2_level,test_levels);
        log_to_file(tmp1,time_stamp);
        sweep_info->range_freq[0] =
             (float)((*(int *)((int)conf + (test_levels + 1) * 0x10 + 0x114) + ctx->freq_flex) -
                    0x19);
      }
      sweep_info->range_freq[1] =
           (float)(longlong)(int)(sweep_info->range_freq[0] * (sweep_info->bias + 1.0));
    }
    sweep_info->pre_open_core_voltage = *(uint32_t *)((int)conf + (test_levels + 0x11) * 0x10 + 0xc)
    ;
    if (*(char *)((int)conf + 0x105) != '\0') {
      sweep_info->range_freq[0] = (float)(longlong)*(int *)((int)conf + 0x108);
      sweep_info->range_freq[1] = (float)(longlong)*(int *)((int)conf + 0x10c);
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
    for (i = 0; i < test_levels; i = i + 1) {
      ctx->tests[i].voltage = *(int *)((int)conf + (i + 2) * 0x10 + 0x110);
      ctx->tests[i].pre_open_core_voltage = *(int *)((int)conf + (i + 0x12) * 0x10 + 0xc);
      ctx->tests[i].level = *(int *)((int)conf + (i + 0x12) * 0x10 + 8);
      ctx->tests[i].freq = *(int *)((int)conf + (i + 2) * 0x10 + 0x114);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : cfg index[%d],level:[%d],freq:[%d]\n","get_conf",i,ctx->tests[i].level,
             ctx->tests[i].freq);
      snprintf(tmp1,0x100,"cfg index[%d],level:[%d],freq:[%d]",i,ctx->tests[i].level,
               ctx->tests[i].freq);
      log_to_file(tmp1,time_stamp);
      if (max_freq < ctx->tests[i].freq) {
        max_freq = ctx->tests[i].freq;
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

