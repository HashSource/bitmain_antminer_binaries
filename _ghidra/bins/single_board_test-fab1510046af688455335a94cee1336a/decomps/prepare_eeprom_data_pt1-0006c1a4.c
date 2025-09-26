
_Bool prepare_eeprom_data_pt1(_Bool pass,uint8_t *eeprom_data,size_t *len_p,size_t *offset_p)

{
  eeprom_data_format_t *peVar1;
  size_t sVar2;
  int iVar3;
  edf_u8_set p_Var4;
  size_t *offset_p_local;
  size_t *len_p_local;
  uint8_t *eeprom_data_local;
  _Bool pass_local;
  char time_stamp [48];
  char tmp1 [2048];
  size_t len;
  uint32_t i;
  char buf [256];
  uint8_t tmp;
  uint32_t frequency;
  uint32_t voltage;
  uint32_t level;
  
  i = 0;
  len = 0;
  if (ctx == (eeprom_data_format_t *)0x0) {
    printf("prepare_eeprom_data_pt1 %d  \n",0x1788);
    ctx = edf_get_ctx(6);
    if (ctx == (eeprom_data_format_t *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: edf_get_ctx ( %d ) failed\n\n","prepare_eeprom_data_pt1",6);
      snprintf(tmp1,0x800,"edf_get_ctx ( %d ) failed\n",6);
      log_to_file(tmp1,time_stamp);
      return true;
    }
    (*ctx->pt1_count_set)(ctx,'\0');
  }
  (*ctx->enc_algorithm_set)(ctx,'\x01');
  (*ctx->enc_key_version_set)(ctx,'\x01');
  len = 0x20;
  (*ctx->factory_job_set)(ctx,qr_code.factory_job,&len);
  len = 0x20;
  (*ctx->board_sn_set)(ctx,(char *)0x101b665,&len);
  len = 2;
  (*ctx->chip_die_set)(ctx,(char *)0x101b5e0,&len);
  len = 0xd;
  (*ctx->chip_marking_set)(ctx,(char *)0x101b5f0,&len);
  len = 9;
  (*ctx->ft_version_set)(ctx,(char *)0x101b610,&len);
  if (qr_code.chip_ftversion[5] == 'M') {
    (*ctx->chip_bin_set)(ctx,qr_code.chip_bin[4] + (qr_code.chip_bin[3] + -0x30) * '\n' + 0xd0);
  }
  else {
    (*ctx->chip_bin_set)(ctx,qr_code.chip_bin[3] + 0xd0);
  }
  len = 5;
  (*ctx->sensor_offset_set)(ctx,gSensor_Offset,&len);
  get_sensor_type(&qr_code);
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code,3);
  __isoc99_sscanf(buf,&DAT_001dd9e4,&i);
  (*ctx->pcb_version_set)(ctx,(uint16_t)i);
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code + 3,2);
  __isoc99_sscanf(buf,&DAT_001dd9e4,&i);
  (*ctx->bom_version_set)(ctx,(uint16_t)i);
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code + 5,2);
  len = 2;
  (*ctx->chip_tech_set)(ctx,buf,&len);
  memset(buf,0,0x100);
  i = 0;
  while ((sVar2 = strlen((Local_Config_Information->Hash_Board).Board_Name), i < sVar2 &&
         ((Local_Config_Information->Hash_Board).Board_Name[i] != '-'))) {
    i = i + 1;
  }
  memcpy(buf,(Local_Config_Information->Hash_Board).Board_Name,i);
  sVar2 = strlen(buf);
  len = sVar2 + 1;
  (*ctx->board_name_set)(ctx,buf,&len);
  (*ctx->pt1_result_set)(ctx,pass);
  peVar1 = ctx;
  p_Var4 = ctx->pt1_count_set;
  iVar3 = (*ctx->pt1_count_get)(ctx);
  (*p_Var4)(peVar1,(char)iVar3 + '\x01');
  (*ctx->region_1_encode)(ctx,(char *)eeprom_data,len_p,offset_p);
  (*ctx->dump_data)(ctx);
  return true;
}

