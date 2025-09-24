
_Bool build_eeprom_data_pt2
                (_Bool pass,uint8_t *eeprom_data,size_t *len_p,size_t *offset_p,
                pattern_runtime_ctx *runtime,float *matrix)

{
  int iVar1;
  _Bool _Var2;
  size_t *offset_p_local;
  size_t *len_p_local;
  uint8_t *eeprom_data_local;
  _Bool pass_local;
  char time_stamp [48];
  char tmp1 [256];
  eeprom_data_format_t *eep_ctx;
  size_t offset1;
  size_t len1;
  size_t offset2;
  size_t len2;
  size_t offset_region_3;
  size_t len_region_3;
  size_t level_tmp_len;
  uint8_t level_tmp [128];
  char buf [256];
  _Bool benc_region1;
  size_t len;
  float max;
  float min;
  _Bool temp;
  uint32_t frequency;
  uint32_t voltage;
  uint32_t level;
  uint32_t i;
  eeprom_data_format_t *ctx;
  
  memset(level_tmp,0,0x80);
  level_tmp_len = 0x80;
  len_region_3 = 0x100;
  len2 = 0x100;
  offset2 = 0;
  len1 = 0x100;
  offset1 = 0;
  memset(level_tmp,0,0x80);
  read_eeprom((g_rt.config)->chain,&eep_ctx);
  iVar1 = (*eep_ctx->version_get)(eep_ctx);
  if (iVar1 == 4) {
    ctx = edf_create_ctx(5);
    if (ctx == (eeprom_data_format_t *)0x0) {
      return false;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : copy v4 to v5\n","build_eeprom_data_pt2");
    builtin_strncpy(tmp1,"copy v4 to v",0xc);
    tmp1[0xc] = '5';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
    copy_v4_to_v5(eep_ctx,ctx);
    if (eep_ctx != (eeprom_data_format_t *)0x0) {
      (*eep_ctx->destroy)(eep_ctx);
      eep_ctx = (eeprom_data_format_t *)0x0;
    }
  }
  else {
    iVar1 = (*eep_ctx->version_get)(eep_ctx);
    if (iVar1 != 5) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : can not find eeprom version\n","build_eeprom_data_pt2");
      builtin_strncpy(tmp1,"can not find eeprom version",0x1c);
      log_to_file(tmp1,time_stamp);
      if (eep_ctx != (eeprom_data_format_t *)0x0) {
        (*eep_ctx->destroy)(eep_ctx);
      }
      return false;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : read eeprom is version 5\n","build_eeprom_data_pt2");
    builtin_strncpy(tmp1,"read eeprom is version 5",0x18);
    tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    ctx = eep_ctx;
  }
  iVar1 = match_level(ctx,runtime,matrix);
  if (iVar1 == 0) {
    if (ctx != (eeprom_data_format_t *)0x0) {
      (*ctx->destroy)(ctx);
    }
    _Var2 = true;
  }
  else {
    if (ctx != (eeprom_data_format_t *)0x0) {
      (*ctx->destroy)(ctx);
    }
    _Var2 = false;
  }
  return _Var2;
}

