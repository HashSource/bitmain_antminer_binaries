
int match_level(eeprom_v1 *ctx,pattern_runtime_ctx *runtime,float *matrix)

{
  int iVar1;
  float fVar2;
  double dVar3;
  float *matrix_local;
  pattern_runtime_ctx *runtime_local;
  eeprom_v1 *ctx_local;
  char time_stamp [48];
  char tmp1 [256];
  int asic_low_freq [12];
  int avg;
  uint32_t matched_vol;
  uint32_t matched_freq;
  
  fVar2 = get_avg_matrix(matrix,runtime->config->asics);
  dVar3 = floor((double)fVar2);
  iVar1 = set_special_avg_matrix(runtime,(int)(longlong)dVar3);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : sweep get matrix avg:%d\n","match_level",iVar1);
  snprintf(tmp1,0x100,"sweep get matrix avg:%d",iVar1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : test level:%d\n","match_level",runtime->config->test_levels);
  snprintf(tmp1,0x100,"test level:%d",runtime->config->test_levels);
  log_to_file(tmp1,time_stamp);
  if (iVar1 < (int)(uint)(ctx->data).field_2.format_v1.pt2.frequency) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : repair mode test failed\n","match_level");
    builtin_strncpy(tmp1,"repair mode test failed",0x18);
    log_to_file(tmp1,time_stamp);
    iVar1 = -1;
  }
  else {
    runtime->config->sweeped_res_index = 0;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : repair mode test ok,reset sweeeped_res_index as 0\n","match_level");
    builtin_strncpy(tmp1,"repair mode test ok,reset sweeeped_res_index as ",0x30);
    tmp1[0x30] = '0';
    tmp1[0x31] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar1 = 0;
  }
  return iVar1;
}

