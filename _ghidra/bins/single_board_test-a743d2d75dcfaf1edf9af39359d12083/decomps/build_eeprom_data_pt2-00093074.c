
_Bool build_eeprom_data_pt2
                (_Bool pass,uint8_t *eeprom_data,size_t *len_p,size_t *offset_p,
                pattern_runtime_ctx *runtime,float *matrix)

{
  bool bVar1;
  int8_t iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int extraout_r1_01;
  byte bVar5;
  _Bool _Var6;
  uint uVar7;
  edf_i8_set p_Var8;
  edf_u8_set p_Var9;
  float fVar10;
  float fVar11;
  size_t *offset_p_local;
  size_t *len_p_local;
  uint8_t *eeprom_data_local;
  _Bool pass_local;
  char tmp42 [256];
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
  size_t len;
  float max;
  float min;
  _Bool temp;
  uint32_t frequency;
  uint32_t voltage;
  uint32_t i;
  int i_1;
  eeprom_data_format_t *ctx;
  _Bool benc_region1;
  uint32_t level;
  
  memset(level_tmp,0,0x80);
  level_tmp_len = 0x80;
  len_region_3 = 0x100;
  len2 = 0x100;
  offset2 = 0;
  len1 = 0x100;
  offset1 = 0;
  bVar1 = false;
  memset(level_tmp,0,0x80);
  read_eeprom((g_rt.config)->chain,&eep_ctx);
  iVar3 = (*eep_ctx->version_get)(eep_ctx);
  if (iVar3 == 4) {
    ctx = edf_create_ctx(5);
    if (ctx == (eeprom_data_format_t *)0x0) {
      return false;
    }
    builtin_strncpy(tmp42,"copy v4 to v",0xc);
    tmp42[0xc] = '5';
    tmp42[0xd] = '\0';
    puts(tmp42);
    copy_v4_to_v5(eep_ctx,ctx);
    bVar1 = true;
    if (eep_ctx != (eeprom_data_format_t *)0x0) {
      (*eep_ctx->destroy)(eep_ctx);
      eep_ctx = (eeprom_data_format_t *)0x0;
    }
  }
  else {
    iVar3 = (*eep_ctx->version_get)(eep_ctx);
    if (iVar3 == 5) {
      builtin_strncpy(tmp42,"read eeprom is version 5",0x18);
      tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
      puts(tmp42);
      ctx = eep_ctx;
    }
    else {
      iVar3 = (*eep_ctx->version_get)(eep_ctx);
      if (iVar3 != 6) {
        builtin_strncpy(tmp42,"can not find eeprom version",0x1c);
        puts(tmp42);
        if (eep_ctx != (eeprom_data_format_t *)0x0) {
          (*eep_ctx->destroy)(eep_ctx);
        }
        return false;
      }
      builtin_strncpy(tmp42,"read eeprom is version 6",0x18);
      tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
      puts(tmp42);
      ctx = eep_ctx;
    }
  }
  iVar3 = match_level(ctx,runtime,matrix);
  if (iVar3 == 0) {
    fVar10 = get_freq_matrix_min(matrix,runtime->config->asics);
    fVar11 = get_freq_matrix_max(matrix,runtime->config->asics);
    (*ctx->sweep_freq_base_set)(ctx,(ushort)(0.0 < fVar10) * (short)(int)fVar10);
    (runtime->sweep).eeprom_freq_step = (int)((fVar11 - fVar10) / 15.0 + 1.0);
    printf("reset min=%f,max=%f, eeprom_freq_step =%d\n",extraout_r1,SUB84((double)fVar10,0),
           (int)((ulonglong)(double)fVar10 >> 0x20),(double)fVar11,(runtime->sweep).eeprom_freq_step
          );
    (*ctx->sweep_freq_step_set)(ctx,(uint8_t)(runtime->sweep).eeprom_freq_step);
    printf("dump level_temp:%f\n",extraout_r1_00,SUB84((double)fVar10,0),
           (int)((ulonglong)(double)fVar10 >> 0x20));
    for (i_1 = 0; i_1 < runtime->config->asics; i_1 = i_1 + 1) {
      fVar11 = (matrix[i_1] - fVar10) / (float)(longlong)(runtime->sweep).eeprom_freq_step;
      level = (uint)(0.0 < fVar11) * (int)fVar11;
      if (0xe < level) {
        level = 0xf;
      }
      if ((i_1 & 1U) == 0) {
        bVar5 = (byte)level & 0xf;
      }
      else {
        bVar5 = (byte)((level & 0xff) << 4);
      }
      level_tmp[i_1 / 2] = bVar5 | level_tmp[i_1 / 2];
      if ((i_1 & 1U) == 0) {
        uVar7 = level_tmp[i_1 / 2] & 0xf;
      }
      else {
        uVar7 = (uint)(level_tmp[i_1 / 2] >> 4);
      }
      printf("%d-(%d) ",level,uVar7);
      __aeabi_idivmod(i_1,runtime->config->asics_in_domain);
      if ((extraout_r1_01 == 0) && (i_1 != 0)) {
        putchar(10);
      }
    }
    putchar(10);
    (*ctx->sweep_level_set)(ctx,level_tmp,&level_tmp_len);
    fVar10 = runtime->nonce_rate * 10000.0;
    (*ctx->sweep_hashrate_set)(ctx,(ushort)(0.0 < fVar10) * (short)(int)fVar10);
    p_Var8 = ctx->pcb_temp_in_set;
    iVar2 = pf_get_min_value((int8_t *)runtime->tempval,
                             (uint8_t)(runtime->config->board).sensor.sensor_num);
    (*p_Var8)(ctx,iVar2);
    p_Var8 = ctx->pcb_temp_out_set;
    iVar2 = pf_get_max_value((int8_t *)runtime->tempval,
                             (uint8_t)(runtime->config->board).sensor.sensor_num);
    (*p_Var8)(ctx,iVar2);
    (*ctx->test_version_set)(ctx,'\0');
    (*ctx->test_standard_set)(ctx,'\x01');
    (*ctx->pt2_result_set)(ctx,pass);
    (*ctx->sweep_result_set)(ctx,pass);
    p_Var9 = ctx->pt2_count_set;
    iVar3 = (*ctx->pt2_count_get)(ctx);
    (*p_Var9)(ctx,(char)iVar3 + '\x01');
    if (bVar1) {
      (*ctx->region_1_encode)(ctx,(char *)eeprom_data,&len1,&offset1);
      snprintf(tmp42,0x100,"region1 len=%d, offset1=%d",len1,offset1);
      puts(tmp42);
    }
    else {
      len1 = 0;
      offset1 = 0;
    }
    (*ctx->region_2_encode)(ctx,(char *)(eeprom_data + len1),&len2,&offset2);
    snprintf(tmp42,0x100,"region2 len=%d offset2=%d",len2,offset2);
    puts(tmp42);
    (*ctx->region_3_encode)(ctx,(char *)(eeprom_data + len2 + len1),&len_region_3,&offset_region_3);
    *len_p = len1 + len2 + len_region_3;
    snprintf(tmp42,0x100,"region3 len=%d offset3=%d",len_region_3,offset_region_3);
    puts(tmp42);
    snprintf(tmp42,0x100,"all region len = %d",*len_p);
    puts(tmp42);
    if (bVar1) {
      *offset_p = 0;
    }
    else {
      *offset_p = offset2;
    }
    iVar3 = (*ctx->sweep_freq_base_get)(ctx);
    iVar4 = (*ctx->sweep_freq_step_get)(ctx);
    snprintf(tmp42,0x100,"base: %d, step:%d",iVar3,iVar4);
    puts(tmp42);
    (*ctx->dump_data)(ctx);
    if (ctx != (eeprom_data_format_t *)0x0) {
      (*ctx->destroy)(ctx);
    }
    _Var6 = true;
  }
  else {
    if (ctx != (eeprom_data_format_t *)0x0) {
      (*ctx->destroy)(ctx);
    }
    _Var6 = false;
  }
  return _Var6;
}

