
_Bool prepare_eeprom_data_pt1(_Bool pass,uint8_t *eeprom_data,size_t *len_p,size_t *offset_p)

{
  eeprom_data_format_t *peVar1;
  byte bVar2;
  size_t sVar3;
  int iVar4;
  edf_u8_set p_Var5;
  size_t *offset_p_local;
  size_t *len_p_local;
  uint8_t *eeprom_data_local;
  _Bool pass_local;
  char time_stamp [48];
  char tmp1 [256];
  size_t len;
  uint32_t i;
  char buf [256];
  uint32_t frequency;
  uint32_t voltage;
  uint32_t level;
  uint8_t tmp;
  
  i = 0;
  len = 0;
  if (ctx == (eeprom_data_format_t *)0x0) {
    ctx = edf_get_ctx(5);
    if (ctx == (eeprom_data_format_t *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : edf_get_ctx ( %d ) failed\n\n","prepare_eeprom_data_pt1",5);
      snprintf(tmp1,0x100,"edf_get_ctx ( %d ) failed\n",5);
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
  (*ctx->board_sn_set)(ctx,(char *)0xa2a101,&len);
  len = 2;
  (*ctx->chip_die_set)(ctx,(char *)0xa2a090,&len);
  len = 0xd;
  (*ctx->chip_marking_set)(ctx,(char *)0xa2a0a0,&len);
  len = 9;
  (*ctx->ft_version_set)(ctx,(char *)0xa2a0c0,&len);
  len = 2;
  (*ctx->chip_tech_set)(ctx,(char *)0xa2a0e5,&len);
  (*ctx->chip_bin_set)(ctx,qr_code.chip_bin[3] + 0xd0);
  bVar2 = get_sensor_type(&qr_code);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
    (*ctx->pic_sensor_type_set)(ctx,'\0');
  }
  else {
    (*ctx->pic_sensor_type_set)(ctx,bVar2 | 0x80);
    strcpy((Local_Config_Information->Hash_Board).Sensor_Info.Pic_Sensor.Pic_Sensor_Model,
           qr_code.temp_sensor_type);
    tmp = '\0';
    for (i = 0; i < gPic_sensor_num; i = i + 1) {
      tmp = tmp | (byte)(1 << gPic_sensor_low_3_bits_addr[i]);
    }
    (*ctx->pic_sensor_addr_set)(ctx,tmp);
  }
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic == false) {
    (*ctx->asic_sensor_type_set)(ctx,'\0');
  }
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code,3);
  __isoc99_sscanf(buf,&DAT_001e81e0,&i);
  (*ctx->pcb_version_set)(ctx,(uint16_t)i);
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code + 3,2);
  __isoc99_sscanf(buf,&DAT_001e81e0,&i);
  (*ctx->bom_version_set)(ctx,(uint16_t)i);
  memset(buf,0,0x100);
  memcpy(buf,qr_code.hashboard_ctrl_code + 5,2);
  len = 2;
  (*ctx->chip_tech_set)(ctx,buf,&len);
  sVar3 = strlen((Local_Config_Information->Hash_Board).Board_Name);
  len = sVar3 + 1;
  (*ctx->board_name_set)(ctx,(Local_Config_Information->Hash_Board).Board_Name,&len);
  (*ctx->pt1_result_set)(ctx,pass);
  peVar1 = ctx;
  p_Var5 = ctx->pt1_count_set;
  iVar4 = (*ctx->pt1_count_get)(ctx);
  (*p_Var5)(peVar1,(char)iVar4 + '\x01');
  (*ctx->region_1_encode)(ctx,(char *)eeprom_data,len_p,offset_p);
  (*ctx->dump_data)(ctx);
  return true;
}

