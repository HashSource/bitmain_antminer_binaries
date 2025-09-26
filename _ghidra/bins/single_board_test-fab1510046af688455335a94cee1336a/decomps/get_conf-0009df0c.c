
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
  char tmp42 [256];
  Local_Config_Info *info;
  int i_1;
  int i;
  
  if (conf == (void *)0x0) {
    builtin_strncpy(tmp42,"conf is null",0xc);
    tmp42[0xc] = '\n';
    tmp42[0xd] = '\0';
    puts(tmp42);
  }
  else {
    ctx->is_super = *(char *)((int)conf + 0xe9) != '\0';
    ctx->chain = chain;
    ctx->asics = *(int *)((int)conf + 0x40);
    ctx->domains = *(int *)((int)conf + 0x50);
    ctx->asics_in_domain = *(int *)((int)conf + 0x54);
    ctx->asic_domain_num = 4;
    ctx->big_core = *(int *)((int)conf + 0x44);
    ctx->asic_small_cores = *(int *)((int)conf + 0x48);
    ctx->samll_core_num_in_big_core = *(int *)((int)conf + 0x4c);
    ctx->patter_num = *(int *)((int)conf + 0x10c);
    ctx->abnormal_core = 0x4f;
    ctx->interval = 1;
    (ctx->reg).ccdly_sel = *(uint32_t *)((int)conf + 0x1d0);
    (ctx->reg).pwth_sel = *(uint32_t *)((int)conf + 0x1d4);
    (ctx->reg).swpf_mode = *(uint32_t *)((int)conf + 0x1d8);
    (ctx->reg).pulse_mode = *(uint32_t *)((int)conf + 0x1dc);
    (ctx->reg).clk_sel = *(uint32_t *)((int)conf + 0x1e0);
    (ctx->reg).ro_relay_en = *(uint32_t *)((int)conf + 0x1e4);
    (ctx->reg).co_relay_en = *(uint32_t *)((int)conf + 0x1e8);
    (ctx->reg).diode_vdd_mux_sel = *(uint32_t *)((int)conf + 0x1ec);
    (ctx->speed).baudrate = *(uint32_t *)((int)conf + 0x1c8);
    (ctx->speed).timeout = *(uint32_t *)((int)conf + 0x1cc);
    memcpy(&ctx->board,(void *)((int)conf + 0x30),0x10);
    (ctx->board).sensor.sensor_num = 2;
    memcpy(&(ctx->board).sensor,(void *)((int)conf + 0x9c),0x10);
    for (i = 0; i < (ctx->board).sensor.sensor_num; i = i + 1) {
      (ctx->board).sensor.sensor_addr[i] = (uint)gCtrlBoard_sensor_low_3_bits_addr[i];
      snprintf(tmp42,0x100,"sensor[%d],addr[%d]",i,(ctx->board).sensor.sensor_addr[i]);
      puts(tmp42);
    }
    (ctx->temp).cool_board_time = *(uint32_t *)((int)conf + 0x1f8);
    (ctx->temp).temp_gap = *(uint32_t *)((int)conf + 0x1f0);
    (ctx->temp).wait_cool_time = *(uint32_t *)((int)conf + 500);
    (ctx->fan).fan_speed = *(int *)((int)conf + 0x1fc);
    (ctx->fan).work_fan_speed = *(int *)((int)conf + 0x200);
    (ctx->standard).invalid_core_num = *(int *)((int)conf + 0x110);
    (ctx->standard).least_nonce_per_core = *(int *)((int)conf + 0x114);
    if (ctx->is_super == false) {
      (ctx->standard).asic_nonce_rate = 0x26b6;
      (ctx->standard).nonce_rate = 0x26ca;
    }
    else {
      (ctx->standard).asic_nonce_rate = 0x2648;
      (ctx->standard).nonce_rate = 0x2648;
    }
    sweep_info->reuse = (uint)*(byte *)((int)conf + 0xf8);
    sweep_info->bias = (float)(longlong)*(int *)((int)conf + 0xfc) / 100.0;
    iVar2 = *(int *)((int)conf + 0xf4);
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
    snprintf(tmp42,0x100,"pt2_level: %d, test_levels:%d",pt2_level,test_levels);
    puts(tmp42);
    iVar2 = strncmp((char *)conf,"PT3",3);
    if (((iVar2 == 0) || (iVar2 = strncmp((char *)conf,"PT1&PT3",7), iVar2 == 0)) ||
       (*(char *)((int)conf + 0xf9) != '\0')) {
      if (pt2_level < 0) {
        sweep_info->range_freq[0] =
             (float)(*(int *)((int)conf + (test_levels + 1) * 0x10 + 0x114) - 0x14);
        snprintf(tmp42,0x100,"pt2 test fail at last level, sweep level adjust from [%d]-->[%.02f]",
                 *(undefined4 *)((int)conf + (test_levels + 1) * 0x10 + 0x114),
                 (double)sweep_info->range_freq[0]);
        puts(tmp42);
      }
      else if (pt2_level < test_levels) {
        sweep_info->range_freq[0] = (float)*(uint *)((int)conf + (pt2_level + 2) * 0x10 + 0x114);
      }
      else {
        snprintf(tmp42,0x100,"pt2 sweep cfg err!, pt2_level: %d, test_levels: %d",pt2_level,
                 test_levels);
        puts(tmp42);
        sweep_info->range_freq[0] =
             (float)(*(int *)((int)conf + (test_levels + 1) * 0x10 + 0x114) - 0x14);
      }
      sweep_info->range_freq[1] =
           (float)(longlong)(int)(sweep_info->range_freq[0] * (sweep_info->bias + 1.0));
    }
    sweep_info->pre_open_core_voltage = *(uint32_t *)((int)conf + 300);
    if (*(char *)((int)conf + 0x101) != '\0') {
      sweep_info->range_freq[0] = (float)(longlong)*(int *)((int)conf + 0x104);
      sweep_info->range_freq[1] = (float)(longlong)*(int *)((int)conf + 0x108);
    }
    for (i_1 = 0; i_1 < test_levels; i_1 = i_1 + 1) {
      ctx->tests[i_1].voltage = *(int *)((int)conf + (i_1 + 2) * 0x10 + 0x110);
      ctx->tests[i_1].pre_open_core_voltage = *(int *)((int)conf + (i_1 + 0x12) * 0x10 + 0xc);
      ctx->tests[i_1].level = *(int *)((int)conf + (i_1 + 0x12) * 0x10 + 8);
      ctx->tests[i_1].freq = *(int *)((int)conf + (i_1 + 2) * 0x10 + 0x114);
      snprintf(tmp42,0x100,"cfg index[%d],level:[%d],freq:[%d]",i_1,ctx->tests[i_1].level,
               ctx->tests[i_1].freq);
      puts(tmp42);
    }
    ctx->test_levels = test_levels;
    ctx->sweeped_res_index = -1;
    snprintf(tmp42,0x100,"sweep_info:reuse:%d",sweep_info->reuse);
    puts(tmp42);
    snprintf(tmp42,0x100,"sweep_info:bias:%f",tmp42,(double)sweep_info->bias);
    puts(tmp42);
    snprintf(tmp42,0x100,"sweep_info:mode:%d",sweep_info->mode);
    puts(tmp42);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: asic nonce rate: %d / 10000\n","get_conf",(ctx->standard).asic_nonce_rate);
    snprintf(tmp42,0x800,"asic nonce rate: %d / 10000",(ctx->standard).asic_nonce_rate);
    log_to_file(tmp42,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: sweep_info:voltage:%d\n","get_conf",sweep_info->voltage);
    snprintf(tmp42,0x800,"sweep_info:voltage:%d",sweep_info->voltage);
    log_to_file(tmp42,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: sweep_info:range_freq:[%f],[%f]\n","get_conf",
           SUB84((double)sweep_info->range_freq[0],0),
           (int)((ulonglong)(double)sweep_info->range_freq[0] >> 0x20),
           (double)sweep_info->range_freq[1]);
    snprintf(tmp42,0x800,"sweep_info:range_freq:[%f],[%f]",tmp42,(double)sweep_info->range_freq[0],
             (double)sweep_info->range_freq[1]);
    log_to_file(tmp42,time_stamp);
  }
  return;
}

