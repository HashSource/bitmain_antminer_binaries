
int match_level(eeprom_data_format_t *ctx,pattern_runtime_ctx *runtime,float *matrix)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  double dVar4;
  float *matrix_local;
  pattern_runtime_ctx *runtime_local;
  eeprom_data_format_t *ctx_local;
  char time_stamp [48];
  char tmp1 [2048];
  int diff;
  int avg;
  int i;
  int k;
  int x;
  uint32_t diff_margin;
  uint32_t margin;
  uint32_t matched_vol;
  uint32_t matched_freq;
  
  matched_freq = 0;
  matched_vol._0_2_ = 0;
  diff_margin = 5;
  fVar3 = get_avg_matrix(matrix,runtime->config->asics);
  dVar4 = floor((double)fVar3);
  uVar1 = (uint)(longlong)dVar4;
  if ((g_rt.config)->is_super == false) {
    if (g_rt.sweep.sweep_online_nonce_rate * 10000.0 <= 9950.0) {
      margin = 0x19;
    }
    else {
      margin = 0xf;
    }
  }
  else if (g_rt.nonce_rate * 10000.0 <= 9900.0) {
    margin = 10;
    diff_margin = 5;
  }
  else {
    margin = 5;
    diff_margin = 0;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: margin is: %d nonce rate %f\n","match_level",margin,0x1070df4,
         (double)(g_rt.nonce_rate * 10000.0));
  snprintf(tmp1,0x800,"margin is: %d nonce rate %f",margin,(double)(g_rt.nonce_rate * 10000.0));
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: sweep get matrix avg: %d\n","match_level",uVar1);
  snprintf(tmp1,0x800,"sweep get matrix avg: %d",uVar1);
  log_to_file(tmp1,time_stamp);
  snprintf(tmp1,0x100,"test levels:%d",runtime->config->test_levels);
  puts(tmp1);
  for (x = 0; x < runtime->config->test_levels; x = x + 1) {
    snprintf(tmp1,0x100,"cfg index[%d],level:[%d],freq:[%d]",x,runtime->config->tests[x].level,
             runtime->config->tests[x].freq);
    puts(tmp1);
  }
  k = 0;
  do {
    if (runtime->config->test_levels <= k) {
LAB_000957ac:
      if (matched_freq == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: fail match freq\n","match_level");
        builtin_strncpy(tmp1,"fail match freq",0x10);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: the hashboard can not match lowest level even by sweeping\n","match_level");
        builtin_strncpy(tmp1,"the hashboard can not match lowest level even by sweepin",0x38);
        tmp1[0x38] = 'g';
        tmp1[0x39] = '\0';
        log_to_file(tmp1,time_stamp);
        iVar2 = -1;
      }
      else {
        iVar2 = uVar1 - matched_freq;
        if ((iVar2 < 0) || (0x78 < iVar2)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: match failed margin < 0 or too big\n","match_level");
          builtin_strncpy(tmp1,"match failed margin < 0 or too big",0x23);
          log_to_file(tmp1,time_stamp);
          iVar2 = -1;
        }
        else {
          for (i = 0; i < runtime->config->asics; i = i + 1) {
            matrix[i] = matrix[i] - (float)(iVar2 - diff_margin);
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: pt2 matched sweep result\n\n","match_level");
          builtin_strncpy(tmp1,"pt2 matched sweep result\n",0x1a);
          log_to_file(tmp1,time_stamp);
          dump_matrix_freq(matrix,runtime->config->domains,runtime->config->asics_in_domain);
          (*ctx->voltage_set)(ctx,(uint16_t)matched_vol);
          (*ctx->frequency_set)(ctx,(uint16_t)matched_freq);
          iVar2 = 0;
        }
      }
      return iVar2;
    }
    if (runtime->config->tests[k].freq + margin <= uVar1) {
      matched_freq = runtime->config->tests[k].freq;
      matched_vol._0_2_ = (uint16_t)runtime->config->tests[k].voltage;
      runtime->config->sweeped_res_index = k;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: matched index:[%d] level:%d,freq:%d\n","match_level",
             runtime->config->sweeped_res_index,
             runtime->config->tests[runtime->config->sweeped_res_index].level,
             runtime->config->tests[runtime->config->sweeped_res_index].freq);
      snprintf(tmp1,0x800,"matched index:[%d] level:%d,freq:%d",runtime->config->sweeped_res_index,
               runtime->config->tests[runtime->config->sweeped_res_index].level,
               runtime->config->tests[runtime->config->sweeped_res_index].freq);
      log_to_file(tmp1,time_stamp);
      goto LAB_000957ac;
    }
    k = k + 1;
  } while( true );
}

