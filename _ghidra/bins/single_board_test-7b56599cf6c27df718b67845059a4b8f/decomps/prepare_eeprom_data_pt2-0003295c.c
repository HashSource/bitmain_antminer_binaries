
_Bool prepare_eeprom_data_pt2
                (uint32_t test_loop_index,_Bool pass,uint8_t *eeprom_data,size_t *len_p,
                size_t *offset_p)

{
  eeprom_data_format_t *peVar1;
  int8_t iVar2;
  int iVar3;
  char *pcVar4;
  edf_i8_set p_Var5;
  edf_u8_set p_Var6;
  double dVar7;
  size_t *len_p_local;
  uint8_t *eeprom_data_local;
  _Bool pass_local;
  uint32_t test_loop_index_local;
  char time_stamp [48];
  char tmp1 [256];
  char buf [256];
  size_t len;
  uint32_t frequency;
  uint32_t voltage;
  uint32_t level;
  _Bool temp;
  uint32_t i;
  
  temp = true;
  if (ctx == (eeprom_data_format_t *)0x0) {
    ctx = edf_get_ctx(5);
    if ((ctx == (eeprom_data_format_t *)0x0) &&
       (ctx = edf_get_ctx(4), ctx == (eeprom_data_format_t *)0x0)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : edf_get_ctx ( %d ) failed\n\n","prepare_eeprom_data_pt2",4);
      snprintf(tmp1,0x100,"edf_get_ctx ( %d ) failed\n",4);
      log_to_file(tmp1,time_stamp);
      return true;
    }
    (*ctx->pt2_count_set)(ctx,'\0');
  }
  if (ctx == (eeprom_data_format_t *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : edf ctx should not be NULL\n\n","prepare_eeprom_data_pt2");
    builtin_strncpy(tmp1,"edf ctx should not be NULL\n",0x1c);
    log_to_file(tmp1,time_stamp);
  }
  else {
    (*ctx->voltage_set)(ctx,(uint16_t)gHistory_Result[test_loop_index].voltage);
    (*ctx->frequency_set)(ctx,(uint16_t)gHistory_Result[test_loop_index].frequence);
    dVar7 = gHistory_Result[test_loop_index].nonce_rate * 10000.0;
    (*ctx->nonce_rate_set)(ctx,(ushort)(0.0 < dVar7) * (short)(longlong)dVar7);
    peVar1 = ctx;
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
      for (i = 0; i < gPic_sensor_num; i = i + 1) {
        temp = (gHistory_Result[test_loop_index].pic_sensor_OK[i] & temp) != 0;
      }
      if (temp == false) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : %d PIC sensors are not all ok. They are: \n","prepare_eeprom_data_pt2",
               gPic_sensor_num);
        snprintf(tmp1,0x100,"%d PIC sensors are not all ok. They are: ",gPic_sensor_num);
        log_to_file(tmp1,time_stamp);
        for (i = 0; i < gPic_sensor_num; i = i + 1) {
          if (gHistory_Result[test_loop_index].pic_sensor_OK[i] == false) {
            pcVar4 = "false";
          }
          else {
            pcVar4 = "true";
          }
          printf("%s ",pcVar4);
        }
        putchar(10);
        return true;
      }
      p_Var5 = ctx->pcb_temp_in_set;
      iVar2 = get_min_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_pic,
                            (uint8_t)gPic_sensor_num);
      (*p_Var5)(peVar1,iVar2);
      peVar1 = ctx;
      p_Var5 = ctx->pcb_temp_out_set;
      iVar2 = get_max_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_pic,
                            (uint8_t)gPic_sensor_num);
      (*p_Var5)(peVar1,iVar2);
    }
    peVar1 = ctx;
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false)
    {
      for (i = 0; i < gCtrlBoard_sensor_num; i = i + 1) {
        temp = (gHistory_Result[test_loop_index].ctrlboard_sensor_OK[i] & temp) != 0;
      }
      if (temp == false) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : %d PIC sensors are not all ok. They are: \n","prepare_eeprom_data_pt2",
               gCtrlBoard_sensor_num);
        snprintf(tmp1,0x100,"%d PIC sensors are not all ok. They are: ",gCtrlBoard_sensor_num);
        log_to_file(tmp1,time_stamp);
        for (i = 0; i < gPic_sensor_num; i = i + 1) {
          if (gHistory_Result[test_loop_index].ctrlboard_sensor_OK[i] == false) {
            pcVar4 = "false";
          }
          else {
            pcVar4 = "true";
          }
          printf("%s ",pcVar4);
        }
        putchar(10);
        return true;
      }
      p_Var5 = ctx->pcb_temp_in_set;
      iVar2 = get_min_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_ctrlboard
                            ,(uint8_t)gCtrlBoard_sensor_num);
      (*p_Var5)(peVar1,iVar2);
      peVar1 = ctx;
      p_Var5 = ctx->pcb_temp_out_set;
      iVar2 = get_max_value(gHistory_Result[test_loop_index].sensor_local_temperature_from_ctrlboard
                            ,(uint8_t)gCtrlBoard_sensor_num);
      (*p_Var5)(peVar1,iVar2);
    }
    peVar1 = ctx;
    p_Var6 = ctx->test_version_set;
    iVar3 = atoi((Local_Config_Information->Test_Info).Test_Config_Data_Version);
    (*p_Var6)(peVar1,(uint8_t)iVar3);
    (*ctx->test_standard_set)(ctx,gHistory_Result[test_loop_index].test_standard);
    (*ctx->pt2_result_set)(ctx,pass);
    peVar1 = ctx;
    p_Var6 = ctx->pt2_count_set;
    iVar3 = (*ctx->pt2_count_get)(ctx);
    (*p_Var6)(peVar1,(char)iVar3 + '\x01');
    (*ctx->region_2_encode)(ctx,(char *)eeprom_data,len_p,offset_p);
    (*ctx->dump_data)(ctx);
  }
  return true;
}

