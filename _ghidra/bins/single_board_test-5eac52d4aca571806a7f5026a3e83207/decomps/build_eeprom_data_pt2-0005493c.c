
_Bool build_eeprom_data_pt2(_Bool pass,pattern_runtime_ctx *runtime,float *matrix)

{
  int iVar1;
  _Bool _Var2;
  float *matrix_local;
  pattern_runtime_ctx *runtime_local;
  _Bool pass_local;
  char time_stamp [48];
  char tmp1 [256];
  eeprom_v1 *ctx;
  uint16_t freqs [256];
  float max;
  float min;
  
  memset(freqs,0,0x200);
  memset(freqs,0,0x200);
  ctx = (eeprom_v1 *)0x0;
  read_eeprom((g_rt.config)->chain,&ctx);
  if ((ctx->data).version == '\x01') {
    iVar1 = match_level(ctx,runtime,matrix);
    if (iVar1 == 0) {
      _Var2 = true;
    }
    else {
      _Var2 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : can not find eeprom version\n","build_eeprom_data_pt2");
    builtin_strncpy(tmp1,"can not find eeprom version",0x1c);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}

