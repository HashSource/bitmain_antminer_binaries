
_Bool build_eeprom_data_pt2(_Bool pass,pattern_runtime_ctx *runtime,float *matrix)

{
  eeprom_v1 *peVar1;
  eeprom_v1 *peVar2;
  int iVar3;
  _Bool _Var4;
  float fVar5;
  float fVar6;
  uint16_t local_360;
  float *matrix_local;
  pattern_runtime_ctx *runtime_local;
  _Bool pass_local;
  char time_stamp [48];
  char tmp1 [256];
  eeprom_v1 *ctx;
  uint16_t freqs [256];
  float max;
  float min;
  uint8_t i;
  
  memset(freqs,0,0x200);
  memset(freqs,0,0x200);
  ctx = (eeprom_v1 *)0x0;
  read_eeprom((g_rt.config)->chain,&ctx);
  if (ctx == (eeprom_v1 *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : read_eeprom failed\n","build_eeprom_data_pt2");
    builtin_strncpy(tmp1,"read_eeprom fail",0x10);
    tmp1[0x10] = 'e';
    tmp1[0x11] = 'd';
    tmp1[0x12] = '\0';
    log_to_file(tmp1,time_stamp);
    _Var4 = false;
  }
  else if ((ctx->data).version == '\x01') {
    iVar3 = match_level(ctx,runtime,matrix);
    if (iVar3 == 0) {
      fVar5 = get_freq_matrix_min(matrix,runtime->config->asics);
      fVar6 = get_freq_matrix_max(matrix,runtime->config->asics);
      for (i = '\0'; (int)(uint)i < runtime->config->asics; i = i + '\x01') {
        local_360 = (ushort)(0.0 < matrix[i]) * (short)(int)matrix[i];
        freqs[i] = local_360;
        printf("asic[%d] freq[%d]",(uint)i,(uint)freqs[i]);
        snprintf(build_eeprom_data_pt2::lexical_block_11::lexical_block_11_1::tmp1_2,0x100,
                 "asic[%d] freq[%d]",(uint)i,(uint)freqs[i]);
        log_to_filex(build_eeprom_data_pt2::lexical_block_11::lexical_block_11_1::tmp1_2,tmp1);
        if ((i != '\0') && ((uint)i % 10 == 0)) {
          putchar(10);
          build_eeprom_data_pt2::lexical_block_11::lexical_block_11_2::tmp1_3[0] = '\n';
          build_eeprom_data_pt2::lexical_block_11::lexical_block_11_2::tmp1_3[1] = '\0';
          log_to_filex(build_eeprom_data_pt2::lexical_block_11::lexical_block_11_2::tmp1_3,tmp1);
        }
      }
      (*ctx->set_sweep_freq)(ctx,freqs,(uint8_t)runtime->config->asics);
      (runtime->sweep).eeprom_freq_step = (uint)(ctx->data).field_2.raw[0x66];
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : reset min=%f,max=%f, eeprom_freq_step =%d\n\n","build_eeprom_data_pt2",
             SUB84((double)fVar5,0),(int)((ulonglong)(double)fVar5 >> 0x20),(double)fVar6,
             (runtime->sweep).eeprom_freq_step);
      iVar3 = (runtime->sweep).eeprom_freq_step;
      snprintf(tmp1,0x100,"reset min=%f,max=%f, eeprom_freq_step =%d\n",iVar3,(double)fVar5,
               (double)fVar6,iVar3);
      log_to_file(tmp1,time_stamp);
      peVar1 = ctx;
      if (g_droplevel != false) {
        (ctx->data).field_2.format_v1.sweep.sweep_hashrate = 0x2b67;
      }
      fVar5 = runtime->nonce_rate * 10000.0;
      local_360 = (ushort)(0.0 < fVar5) * (short)(int)fVar5;
      (ctx->data).field_2.format_v1.pt2.nonce_rate = local_360;
      iVar3 = pf_get_min_value(runtime->tempval,(runtime->config->board).sensor.sensor_num);
      peVar2 = ctx;
      (peVar1->data).field_2.raw[0x57] = (uint8_t)iVar3;
      iVar3 = pf_get_max_value(runtime->tempval,(runtime->config->board).sensor.sensor_num);
      (peVar2->data).field_2.raw[0x58] = (uint8_t)iVar3;
      (ctx->data).field_2.raw[0x5b] = '\0';
      (ctx->data).field_2.raw[0x5c] = '\x01';
      (ctx->data).field_2.raw[0x59] = pass;
      (ctx->data).field_2.raw[0xe7] = pass;
      (ctx->data).field_2.raw[0x5a] = (ctx->data).field_2.raw[0x5a] + '\x01';
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : base: %d, step:%d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.format_v1.sweep.sweep_freq_base,
             (uint)(ctx->data).field_2.raw[0x66]);
      snprintf(tmp1,0x100,"base: %d, step:%d",
               (uint)(ctx->data).field_2.format_v1.sweep.sweep_freq_base,
               (uint)(ctx->data).field_2.raw[0x66]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom version: %d\n","build_eeprom_data_pt2",(uint)(ctx->data).version);
      snprintf(tmp1,0x100,"pt2 eeprom version: %d",(uint)(ctx->data).version);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom board_name: %s\n","build_eeprom_data_pt2",(ctx->data).board_name);
      snprintf(tmp1,0x100,"pt2 eeprom board_name: %s",(ctx->data).board_name);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom voltage: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.format_v1.pt2.voltage);
      snprintf(tmp1,0x100,"pt2 eeprom voltage: %d",(uint)(ctx->data).field_2.format_v1.pt2.voltage);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom frequency: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.format_v1.pt2.frequency);
      snprintf(tmp1,0x100,"pt2 eeprom frequency: %d",
               (uint)(ctx->data).field_2.format_v1.pt2.frequency);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom nonce_rate: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.format_v1.pt2.nonce_rate);
      snprintf(tmp1,0x100,"pt2 eeprom nonce_rate: %d",
               (uint)(ctx->data).field_2.format_v1.pt2.nonce_rate);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom pcb_temp_in: %d\n","build_eeprom_data_pt2",
             (int)(char)(ctx->data).field_2.raw[0x57]);
      snprintf(tmp1,0x100,"pt2 eeprom pcb_temp_in: %d",(int)(char)(ctx->data).field_2.raw[0x57]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom pcb_temp_out: %d\n","build_eeprom_data_pt2",
             (int)(char)(ctx->data).field_2.raw[0x58]);
      snprintf(tmp1,0x100,"pt2 eeprom pcb_temp_out: %d",(int)(char)(ctx->data).field_2.raw[0x58]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom pt2_result: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.raw[0x59]);
      snprintf(tmp1,0x100,"pt2 eeprom pt2_result: %d",(uint)(ctx->data).field_2.raw[0x59]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom pt2_count: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.raw[0x5a]);
      snprintf(tmp1,0x100,"pt2 eeprom pt2_count: %d",(uint)(ctx->data).field_2.raw[0x5a]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom test_version: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.raw[0x5b]);
      snprintf(tmp1,0x100,"pt2 eeprom test_version: %d",(uint)(ctx->data).field_2.raw[0x5b]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 eeprom test_standard: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.raw[0x5c]);
      snprintf(tmp1,0x100,"pt2 eeprom test_standard: %d",(uint)(ctx->data).field_2.raw[0x5c]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep eeprom sweep_hashrate: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.format_v1.sweep.sweep_hashrate);
      snprintf(tmp1,0x100,"sweep eeprom sweep_hashrate: %d",
               (uint)(ctx->data).field_2.format_v1.sweep.sweep_hashrate);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep eeprom sweep_freq_base: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.format_v1.sweep.sweep_freq_base);
      snprintf(tmp1,0x100,"sweep eeprom sweep_freq_base: %d",
               (uint)(ctx->data).field_2.format_v1.sweep.sweep_freq_base);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep eeprom sweep_freq_step: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.raw[0x66]);
      snprintf(tmp1,0x100,"sweep eeprom sweep_freq_step: %d",(uint)(ctx->data).field_2.raw[0x66]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep eeprom sweep_result: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.raw[0xe7]);
      snprintf(tmp1,0x100,"sweep eeprom sweep_result: %d",(uint)(ctx->data).field_2.raw[0xe7]);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep eeprom sweep_count: %d\n","build_eeprom_data_pt2",
             (uint)(ctx->data).field_2.raw[0xe8]);
      snprintf(tmp1,0x100,"sweep eeprom sweep_count: %d",(uint)(ctx->data).field_2.raw[0xe8]);
      log_to_file(tmp1,time_stamp);
      iVar3 = (*ctx->pt2_store)(ctx);
      if (iVar3 == 0) {
        iVar3 = (*ctx->sweep_store)(ctx);
        if (iVar3 == 0) {
          _Var4 = true;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : stroe sweep failed\n","build_eeprom_data_pt2");
          builtin_strncpy(tmp1,"stroe sweep fail",0x10);
          tmp1[0x10] = 'e';
          tmp1[0x11] = 'd';
          tmp1[0x12] = '\0';
          log_to_file(tmp1,time_stamp);
          _Var4 = false;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : store pt2 failed\n","build_eeprom_data_pt2");
        builtin_strncpy(tmp1,"store pt2 failed",0x10);
        tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        _Var4 = false;
      }
    }
    else {
      _Var4 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : can not find eeprom version\n","build_eeprom_data_pt2");
    builtin_strncpy(tmp1,"can not find eeprom version",0x1c);
    log_to_file(tmp1,time_stamp);
    _Var4 = false;
  }
  return _Var4;
}

