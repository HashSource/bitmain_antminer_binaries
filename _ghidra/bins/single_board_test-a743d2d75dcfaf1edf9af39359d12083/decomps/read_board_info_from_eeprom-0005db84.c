
/* WARNING: Unknown calling convention */

_Bool read_board_info_from_eeprom(void)

{
  undefined2 uVar1;
  int32_t iVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  _Bool _Var6;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t len;
  uint8_t eeprom_data [256];
  char data [40];
  int tmp;
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
    goto LAB_0005e296;
  }
  memset(eeprom_data,0xff,gEEPROM_length);
  iVar2 = eeprom_read(gChain,'\0',eeprom_data,len);
  if (iVar2 == 0) {
    ctx = edf_load(eeprom_data,len);
    if (ctx == (eeprom_data_format_t *)0x0) {
      errmsg = load_board_info_from_format_v3((char *)eeprom_data,len);
      if (errmsg != (char *)0x0) goto LAB_0005e4f4;
    }
    else {
      (*ctx->dump_data)(ctx);
      if ((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun != false) {
        memset(&qr_code,0,0x20);
        len = 0x20;
        iVar3 = (*ctx->factory_job_get)(ctx,qr_code.factory_job,&len);
        if (iVar3 < 0) {
          errmsg = "factory job";
        }
        else {
          len = 0x20;
          memset(sn.board_sn,0,0x20);
          iVar3 = (*ctx->board_sn_get)(ctx,(char *)0x1016631,&len);
          if (iVar3 < 0) {
            errmsg = "BOARD SN";
          }
          else {
            sVar4 = strlen(sn.board_sn);
            sn.sn_len = (char)sVar4;
            memset(qr_code.chip_die,0,0x10);
            len = 0x10;
            iVar3 = (*ctx->chip_die_get)(ctx,(char *)0x10165c0,&len);
            if (iVar3 < 0) {
              errmsg = "CHIP DIE";
            }
            else {
              memset(qr_code.chip_marking,0,0x10);
              len = 0x10;
              iVar3 = (*ctx->chip_marking_get)(ctx,(char *)0x10165d0,&len);
              if (iVar3 < 0) {
                errmsg = "MARKING";
              }
              else {
                memset(qr_code.chip_ftversion,0,0x10);
                len = 0x10;
                iVar3 = (*ctx->ft_version_get)(ctx,(char *)0x10165f0,&len);
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
                    if (((Local_Config_Information->Hash_Board).Sensor_Info.
                         Read_Temperature_From_Pic == false) &&
                       ((Local_Config_Information->Hash_Board).Sensor_Info.
                        Read_Temperature_From_Asic != false)) {
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
                        goto LAB_0005e4f4;
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
                        iVar3 = (*ctx->chip_tech_get)(ctx,(char *)0x1016615,&len);
                        if (iVar3 < 0) {
                          errmsg = "CHIP TECH";
                        }
                        else {
                          len = 0x28;
                          iVar3 = (*ctx->board_name_get)(ctx,data,&len);
                          if ((-1 < iVar3) &&
                             (iVar3 = strncmp(data,(Local_Config_Information->Hash_Board).Board_Name
                                              ,8), iVar3 == 0)) goto LAB_0005e296;
                          errmsg = "BOARD NAME";
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_0005e4f4;
      }
    }
LAB_0005e296:
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: sn %s\n","read_board_info_from_eeprom",0x1016631);
    snprintf(tmp1,0x800,"sn %s",0x1016631);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: BIN %s\n","read_board_info_from_eeprom",0x10165e0);
    snprintf(tmp1,0x800,"BIN %s",0x10165e0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: DIE %s\n","read_board_info_from_eeprom",0x10165c0);
    snprintf(tmp1,0x800,"DIE %s",0x10165c0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: FT %s\n","read_board_info_from_eeprom",0x10165f0);
    snprintf(tmp1,0x800,"FT %s",0x10165f0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: marking %s\n","read_board_info_from_eeprom",0x10165d0);
    snprintf(tmp1,0x800,"marking %s",0x10165d0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: factory_job %s\n","read_board_info_from_eeprom",&qr_code);
    snprintf(tmp1,0x800,"factory_job %s",&qr_code);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: hashboard_ctrl_code %s\n","read_board_info_from_eeprom",0x1016610);
    snprintf(tmp1,0x800,"hashboard_ctrl_code %s",0x1016610);
    log_to_file(tmp1,time_stamp);
    _Var6 = true;
  }
  else {
    errmsg = "READ ERROR";
LAB_0005e4f4:
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"EEPROM data");
    lcd_show(2,"     ERROR");
    lcd_show(3,errmsg);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: EEPROM error: %s\n","read_board_info_from_eeprom",errmsg);
    snprintf(tmp1,0x800,"EEPROM error: %s",errmsg);
    log_to_file(tmp1,time_stamp);
    _Var6 = false;
  }
  return _Var6;
}

