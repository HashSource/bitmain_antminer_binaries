
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

_Bool read_board_info_from_eeprom(void)

{
  undefined2 uVar1;
  int32_t iVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  uint32_t uVar6;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t len;
  uint8_t eeprom_data [256];
  char data [40];
  int tmp;
  int i;
  char *errmsg;
  
  memset(eeprom_data,0,0x100);
  eeprom_data[0] = 0xff;
  len = gEEPROM_length;
  if ((Local_Config_Information->Repair_Mode).Enable_Repair != false) {
    gScanCodeGun_data_ready = '\x03';
    builtin_strncpy(sn.board_sn,"12345678901234567",0x12);
    builtin_strncpy(qr_code.factory_job,"20200320003(YZ)",0x10);
    qr_code.chip_die[0] = 'E';
    qr_code.chip_die[1] = 'D';
    qr_code.chip_die[2] = '\0';
    builtin_strncpy(qr_code.chip_marking,"S13020AH01",0xb);
    builtin_strncpy(qr_code.chip_bin,"BIN1",5);
    builtin_strncpy(qr_code.chip_ftversion,"F1V01B4C1",10);
    builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
    qr_code.temp_sensor_type[4] = '5';
    qr_code.temp_sensor_type[5] = 'A';
    qr_code.temp_sensor_type[6] = '\0';
    builtin_strncpy(qr_code.hashboard_ctrl_code,"10010BB",8);
    builtin_strncpy(qr_code.hashboard_index,"0123",5);
  }
  memset(eeprom_data,0xff,gEEPROM_length);
  iVar2 = eeprom_read(gChain,'\0',eeprom_data,len);
  if (iVar2 == 0) {
    ctx = edf_load(eeprom_data,len);
    if (ctx == (eeprom_data_format_t *)0x0) {
      errmsg = load_board_info_from_format_v3((char *)eeprom_data,len);
      if (errmsg == (char *)0x0) {
LAB_0002965e:
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : sn %s\n","read_board_info_from_eeprom",0xa2a101);
        snprintf(tmp1,0x100,"sn %s",0xa2a101);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : BIN %s\n","read_board_info_from_eeprom",0xa2a0b0);
        snprintf(tmp1,0x100,"BIN %s",0xa2a0b0);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : DIE %s\n","read_board_info_from_eeprom",0xa2a090);
        snprintf(tmp1,0x100,"DIE %s",0xa2a090);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : FT %s\n","read_board_info_from_eeprom",0xa2a0c0);
        snprintf(tmp1,0x100,"FT %s",0xa2a0c0);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : marking %s\n","read_board_info_from_eeprom",0xa2a0a0);
        snprintf(tmp1,0x100,"marking %s",0xa2a0a0);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : factory_job %s\n","read_board_info_from_eeprom",&qr_code);
        snprintf(tmp1,0x100,"factory_job %s",&qr_code);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : hashboard_ctrl_code %s\n","read_board_info_from_eeprom",0xa2a0e0);
        snprintf(tmp1,0x100,"hashboard_ctrl_code %s",0xa2a0e0);
        log_to_file(tmp1,time_stamp);
        if (ctx != (eeprom_data_format_t *)0x0) {
          (*ctx->destroy)(ctx);
          ctx = (eeprom_data_format_t *)0x0;
        }
        return true;
      }
    }
    else {
      (*ctx->dump_data)(ctx);
      memset(&qr_code,0,0x20);
      len = 0x20;
      iVar3 = (*ctx->factory_job_get)(ctx,qr_code.factory_job,&len);
      if (iVar3 < 0) {
        errmsg = "factory job";
      }
      else {
        len = 0x20;
        memset(sn.board_sn,0,0x20);
        iVar3 = (*ctx->board_sn_get)(ctx,(char *)0xa2a101,&len);
        if (iVar3 < 0) {
          errmsg = "BOARD SN";
        }
        else {
          sVar4 = strlen(sn.board_sn);
          sn.sn_len = (char)sVar4;
          memset(qr_code.chip_die,0,0x10);
          len = 0x10;
          iVar3 = (*ctx->chip_die_get)(ctx,(char *)0xa2a090,&len);
          if (iVar3 < 0) {
            errmsg = "CHIP DIE";
          }
          else {
            memset(qr_code.chip_marking,0,0x10);
            len = 0x10;
            iVar3 = (*ctx->chip_marking_get)(ctx,(char *)0xa2a0a0,&len);
            if (iVar3 < 0) {
              errmsg = "MARKING";
            }
            else {
              memset(qr_code.chip_ftversion,0,0x10);
              len = 0x10;
              iVar3 = (*ctx->ft_version_get)(ctx,(char *)0xa2a0c0,&len);
              if (iVar3 < 0) {
                errmsg = "FT VERSION";
              }
              else {
                strncpy(qr_code.chip_bin,"BIN0",0x10);
                iVar3 = (*ctx->chip_bin_get)(ctx);
                if ((iVar3 < 1) || (9 < iVar3)) {
                  errmsg = "CHIP BIN";
                }
                else {
                  qr_code.chip_bin[3] = (char)iVar3 + '0';
                  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic
                      == false) {
                    if ((Local_Config_Information->Hash_Board).Sensor_Info.
                        Read_Temperature_From_Asic != false) {
                      uVar5 = (*ctx->asic_sensor_type_get)(ctx);
                      uVar1 = qr_code.temp_sensor_type._6_2_;
                      switch(uVar5 & 0xffffff7f) {
                      case 1:
                        builtin_strncpy(qr_code.temp_sensor_type,"TMP4",4);
                        qr_code.temp_sensor_type[4] = '5';
                        qr_code.temp_sensor_type[5] = '1';
                        qr_code.temp_sensor_type[6] = '\0';
                        break;
                      default:
                        errmsg = "SENSOR TYPE";
                        goto LAB_000298f2;
                      case 5:
                        builtin_strncpy(qr_code.temp_sensor_type,"NCT2",4);
                        qr_code.temp_sensor_type[4] = '1';
                        qr_code.temp_sensor_type[5] = '8';
                        qr_code.temp_sensor_type[6] = '\0';
                        break;
                      case 10:
                        builtin_strncpy(qr_code.temp_sensor_type,"LM75",4);
                        qr_code.temp_sensor_type[4] = 'A';
                        qr_code.temp_sensor_type[5] = '\0';
                        qr_code.temp_sensor_type._4_4_ =
                             CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                        break;
                      case 0xb:
                        builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
                        qr_code.temp_sensor_type[4] = '5';
                        qr_code.temp_sensor_type[5] = 'A';
                        qr_code.temp_sensor_type[6] = '\0';
                        break;
                      case 0xc:
                        builtin_strncpy(qr_code.temp_sensor_type,"DS75",4);
                        qr_code.temp_sensor_type[4] = 'S';
                        qr_code.temp_sensor_type[5] = '\0';
                        qr_code.temp_sensor_type._4_4_ =
                             CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                        break;
                      case 0xd:
                        builtin_strncpy(qr_code.temp_sensor_type,"GM45",4);
                        qr_code.temp_sensor_type[4] = '2';
                        qr_code.temp_sensor_type[5] = '\0';
                        qr_code.temp_sensor_type._4_4_ =
                             CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                        break;
                      case 0xe:
                        builtin_strncpy(qr_code.temp_sensor_type,"CT75",4);
                        qr_code.temp_sensor_type._4_4_ = qr_code.temp_sensor_type._4_4_ & 0xffffff00
                        ;
                        break;
                      case 0xf:
                        builtin_strncpy(qr_code.temp_sensor_type,"DS75SPlus",10);
                        break;
                      case 0x10:
                        builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
                        qr_code.temp_sensor_type[4] = '5';
                        qr_code.temp_sensor_type[5] = '\0';
                        qr_code.temp_sensor_type._4_4_ =
                             CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                        break;
                      case 0x11:
                        builtin_strncpy(qr_code.temp_sensor_type,"SD17",4);
                        qr_code.temp_sensor_type[4] = '7';
                        qr_code.temp_sensor_type[5] = '\0';
                        qr_code.temp_sensor_type._4_4_ =
                             CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                        break;
                      case 0x12:
                        builtin_strncpy(qr_code.temp_sensor_type,"GX21",4);
                        qr_code.temp_sensor_type[4] = 'M';
                        qr_code.temp_sensor_type[5] = '\0';
                        qr_code.temp_sensor_type._4_4_ =
                             CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                        break;
                      case 0x13:
                        builtin_strncpy(qr_code.temp_sensor_type,"NT17",4);
                        qr_code.temp_sensor_type[4] = '5';
                        qr_code.temp_sensor_type[5] = '\0';
                        qr_code.temp_sensor_type._4_4_ =
                             CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                      }
                    }
                  }
                  else {
                    uVar5 = (*ctx->pic_sensor_type_get)(ctx);
                    uVar1 = qr_code.temp_sensor_type._6_2_;
                    switch(uVar5 & 0xffffff7f) {
                    case 1:
                      builtin_strncpy(qr_code.temp_sensor_type,"TMP4",4);
                      qr_code.temp_sensor_type[4] = '5';
                      qr_code.temp_sensor_type[5] = '1';
                      qr_code.temp_sensor_type[6] = '\0';
                      break;
                    default:
                      errmsg = "SENSOR TYPE";
                      goto LAB_000298f2;
                    case 5:
                      builtin_strncpy(qr_code.temp_sensor_type,"NCT2",4);
                      qr_code.temp_sensor_type[4] = '1';
                      qr_code.temp_sensor_type[5] = '8';
                      qr_code.temp_sensor_type[6] = '\0';
                      break;
                    case 10:
                      builtin_strncpy(qr_code.temp_sensor_type,"LM75",4);
                      qr_code.temp_sensor_type[4] = 'A';
                      qr_code.temp_sensor_type[5] = '\0';
                      qr_code.temp_sensor_type._4_4_ =
                           CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                      break;
                    case 0xb:
                      builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
                      qr_code.temp_sensor_type[4] = '5';
                      qr_code.temp_sensor_type[5] = 'A';
                      qr_code.temp_sensor_type[6] = '\0';
                      break;
                    case 0xc:
                      builtin_strncpy(qr_code.temp_sensor_type,"DS75",4);
                      qr_code.temp_sensor_type[4] = 'S';
                      qr_code.temp_sensor_type[5] = '\0';
                      qr_code.temp_sensor_type._4_4_ =
                           CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                      break;
                    case 0xd:
                      builtin_strncpy(qr_code.temp_sensor_type,"GM45",4);
                      qr_code.temp_sensor_type[4] = '2';
                      qr_code.temp_sensor_type[5] = '\0';
                      qr_code.temp_sensor_type._4_4_ =
                           CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                      break;
                    case 0xe:
                      builtin_strncpy(qr_code.temp_sensor_type,"CT75",4);
                      qr_code.temp_sensor_type._4_4_ = qr_code.temp_sensor_type._4_4_ & 0xffffff00;
                      break;
                    case 0xf:
                      builtin_strncpy(qr_code.temp_sensor_type,"DS75SPlus",10);
                      break;
                    case 0x10:
                      builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
                      qr_code.temp_sensor_type[4] = '5';
                      qr_code.temp_sensor_type[5] = '\0';
                      qr_code.temp_sensor_type._4_4_ =
                           CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                      break;
                    case 0x11:
                      builtin_strncpy(qr_code.temp_sensor_type,"SD17",4);
                      qr_code.temp_sensor_type[4] = '7';
                      qr_code.temp_sensor_type[5] = '\0';
                      qr_code.temp_sensor_type._4_4_ =
                           CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                      break;
                    case 0x12:
                      builtin_strncpy(qr_code.temp_sensor_type,"GX21",4);
                      qr_code.temp_sensor_type[4] = 'M';
                      qr_code.temp_sensor_type[5] = '\0';
                      qr_code.temp_sensor_type._4_4_ =
                           CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                      break;
                    case 0x13:
                      builtin_strncpy(qr_code.temp_sensor_type,"NT17",4);
                      qr_code.temp_sensor_type[4] = '5';
                      qr_code.temp_sensor_type[5] = '\0';
                      qr_code.temp_sensor_type._4_4_ =
                           CONCAT22(uVar1,qr_code.temp_sensor_type._4_2_);
                    }
                  }
                  iVar3 = (*ctx->pcb_version_get)(ctx);
                  if ((iVar3 < 0) || (0xffff < iVar3)) {
                    errmsg = "PCB VERSION";
                  }
                  else {
                    sprintf(qr_code.hashboard_ctrl_code,"%x",iVar3);
                    iVar3 = (*ctx->bom_version_get)(ctx);
                    if ((iVar3 < 0) || (0xffff < iVar3)) {
                      errmsg = "BOM VERSION";
                    }
                    else {
                      sprintf(qr_code.hashboard_ctrl_code + 3,"%x",iVar3);
                      len = 2;
                      iVar3 = (*ctx->chip_tech_get)(ctx,(char *)0xa2a0e5,&len);
                      if (iVar3 < 0) {
                        errmsg = "CHIP TECH";
                      }
                      else {
                        len = 0x28;
                        iVar3 = (*ctx->board_name_get)(ctx,data,&len);
                        if ((iVar3 < 0) ||
                           (iVar3 = strncmp(data,(Local_Config_Information->Hash_Board).Board_Name,8
                                           ), iVar3 != 0)) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s : readout boardname:%s,cfg:%s.\n","read_board_info_from_eeprom"
                                 ,data,(Local_Config_Information->Hash_Board).Board_Name);
                          snprintf(tmp1,0x100,"readout boardname:%s,cfg:%s.",data,
                                   (Local_Config_Information->Hash_Board).Board_Name);
                          log_to_file(tmp1,time_stamp);
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s : EnableRepaire:%d\n","read_board_info_from_eeprom",
                                 (uint)(Local_Config_Information->Repair_Mode).Enable_Repair);
                          snprintf(tmp1,0x100,"EnableRepaire:%d",
                                   (uint)(Local_Config_Information->Repair_Mode).Enable_Repair);
                          log_to_file(tmp1,time_stamp);
                          if ((Local_Config_Information->Repair_Mode).Enable_Repair != true) {
                            errmsg = "BOARD NAME";
                            goto LAB_000298f2;
                          }
                        }
                        gTest_loop = 1;
                        uVar6 = (*ctx->voltage_get)(ctx);
                        if ((int)uVar6 < 0) {
                          errmsg = "VOLTAGE";
                        }
                        else {
                          (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Level = 1
                          ;
                          (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Voltage =
                               uVar6;
                          for (i = 1; i < 0x32; i = i + 1) {
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Level =
                                 0;
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Voltage
                                 = 0;
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].
                            Pre_Open_Core_Voltage = 0;
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Voltage
                                 = 0;
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].
                            Frequence = 0;
                          }
                          iVar3 = (*ctx->frequency_get)(ctx);
                          if (-1 < iVar3) {
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].
                            Frequence = iVar3 + (Local_Config_Information->Test_Info).Freq_Flex;
                            print_time_stamp(time_stamp,0x30);
                            printf("%s ",time_stamp);
                            printf("%s : read back voltage:%d frequency:%d\n",
                                   "read_board_info_from_eeprom",
                                   (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].
                                   Voltage,(Local_Config_Information->Test_Info).Test_Standard.
                                           Test_Loop[0].Frequence);
                            snprintf(tmp1,0x100,"read back voltage:%d frequency:%d",
                                     (Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                                     [0].Voltage,
                                     (Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                                     [0].Frequence);
                            log_to_file(tmp1,time_stamp);
                            g_eeprom_version = (*ctx->version_get)(ctx);
                            goto LAB_0002965e;
                          }
                          errmsg = "FREQ";
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    errmsg = "READ ERROR";
  }
LAB_000298f2:
  lcd_clear_result();
  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
  lcd_show(1,"EEPROM data");
  lcd_show(2,"     ERROR");
  lcd_show(3,errmsg);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : EEPROM error: %s\n","read_board_info_from_eeprom",errmsg);
  snprintf(tmp1,0x100,"EEPROM error: %s",errmsg);
  log_to_file(tmp1,time_stamp);
  if (ctx != (eeprom_data_format_t *)0x0) {
    (*ctx->destroy)(ctx);
    ctx = (eeprom_data_format_t *)0x0;
  }
  return false;
}

