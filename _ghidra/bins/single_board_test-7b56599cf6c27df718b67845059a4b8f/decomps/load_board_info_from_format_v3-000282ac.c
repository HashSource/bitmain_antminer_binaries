
char * load_board_info_from_format_v3(char *data,uint32_t len)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined2 uVar4;
  _Bool _Var5;
  uint8_t uVar6;
  uint32_t len_local;
  char *data_local;
  char time_stamp [48];
  char tmp1 [256];
  char buf [256];
  uint8_t tmp;
  char *errmsg;
  
  errmsg = (char *)0x0;
  if (data[1] == 'H') {
    _Var5 = data_dec((uint32_t *)(data + 2),0x48,'\x01','\x01');
    if (_Var5) {
      memcpy(&zhiju_eeprom_data,data,(uint)(byte)data[1]);
      zhiju_eeprom_data.zhiju_information.zhiju_information_crc5 = data[(byte)data[1] - 1];
      uVar6 = CRC5_long((uint8_t *)data,((byte)data[1] - 1) * 8);
      if (uVar6 == zhiju_eeprom_data.zhiju_information.zhiju_information_crc5) {
        memset(sn.board_sn,0,0x20);
        sn.board_sn[0] = zhiju_eeprom_data.zhiju_information.hashboard_sn[0];
        sn.board_sn[1] = zhiju_eeprom_data.zhiju_information.hashboard_sn[1];
        sn.board_sn[2] = zhiju_eeprom_data.zhiju_information.hashboard_sn[2];
        sn.board_sn[3] = zhiju_eeprom_data.zhiju_information.hashboard_sn[3];
        sn.board_sn[4] = zhiju_eeprom_data.zhiju_information.hashboard_sn[4];
        sn.board_sn[5] = zhiju_eeprom_data.zhiju_information.hashboard_sn[5];
        sn.board_sn[6] = zhiju_eeprom_data.zhiju_information.hashboard_sn[6];
        sn.board_sn[7] = zhiju_eeprom_data.zhiju_information.hashboard_sn[7];
        sn.board_sn[8] = zhiju_eeprom_data.zhiju_information.hashboard_sn[8];
        sn.board_sn[9] = zhiju_eeprom_data.zhiju_information.hashboard_sn[9];
        sn.board_sn[10] = zhiju_eeprom_data.zhiju_information.hashboard_sn[10];
        sn.board_sn[0xb] = zhiju_eeprom_data.zhiju_information.hashboard_sn[0xb];
        sn.board_sn[0xc] = zhiju_eeprom_data.zhiju_information.hashboard_sn[0xc];
        sn.board_sn[0xd] = zhiju_eeprom_data.zhiju_information.hashboard_sn[0xd];
        sn.board_sn[0xe] = zhiju_eeprom_data.zhiju_information.hashboard_sn[0xe];
        sn.board_sn[0xf] = zhiju_eeprom_data.zhiju_information.hashboard_sn[0xf];
        sn.board_sn[0x10] = zhiju_eeprom_data.zhiju_information.hashboard_sn[0x10];
        memset(qr_code.chip_die,0,0x10);
        qr_code.chip_die[0] = zhiju_eeprom_data.zhiju_information.chip_die[0];
        qr_code.chip_die[1] = zhiju_eeprom_data.zhiju_information.chip_die[1];
        memset(qr_code.chip_marking,0,0x10);
        qr_code.chip_marking[0] = zhiju_eeprom_data.zhiju_information.chip_marking[0];
        qr_code.chip_marking[1] = zhiju_eeprom_data.zhiju_information.chip_marking[1];
        qr_code.chip_marking[2] = zhiju_eeprom_data.zhiju_information.chip_marking[2];
        qr_code.chip_marking[3] = zhiju_eeprom_data.zhiju_information.chip_marking[3];
        qr_code.chip_marking[4] = zhiju_eeprom_data.zhiju_information.chip_marking[4];
        qr_code.chip_marking[5] = zhiju_eeprom_data.zhiju_information.chip_marking[5];
        qr_code.chip_marking[6] = zhiju_eeprom_data.zhiju_information.chip_marking[6];
        qr_code.chip_marking[7] = zhiju_eeprom_data.zhiju_information.chip_marking[7];
        qr_code.chip_marking[8] = zhiju_eeprom_data.zhiju_information.chip_marking[8];
        qr_code.chip_marking[9] = zhiju_eeprom_data.zhiju_information.chip_marking[9];
        qr_code.chip_marking[10] = zhiju_eeprom_data.zhiju_information.chip_marking[10];
        qr_code.chip_marking[0xb] = zhiju_eeprom_data.zhiju_information.chip_marking[0xb];
        qr_code.chip_marking[0xc] = zhiju_eeprom_data.zhiju_information.chip_marking[0xc];
        memset(qr_code.chip_ftversion,0,0x10);
        uVar2 = zhiju_eeprom_data.zhiju_information.chip_ft_program_version._4_4_;
        uVar1 = zhiju_eeprom_data.zhiju_information.chip_ft_program_version._0_4_;
        qr_code.chip_ftversion[0] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[0];
        qr_code.chip_ftversion[1] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[1];
        qr_code.chip_ftversion[2] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[2];
        qr_code.chip_ftversion[3] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[3];
        qr_code.chip_ftversion[4] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[4];
        qr_code.chip_ftversion[5] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[5];
        qr_code.chip_ftversion[6] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[6];
        qr_code.chip_ftversion[7] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[7];
        qr_code.chip_ftversion[8] = zhiju_eeprom_data.zhiju_information.chip_ft_program_version[8];
        builtin_strncpy(qr_code.chip_bin,"BIN",4);
        if ((zhiju_eeprom_data.zhiju_information.chip_bin == '\0') ||
           (9 < zhiju_eeprom_data.zhiju_information.chip_bin)) {
          errmsg = "CHIP BIN";
        }
        else {
          qr_code.chip_bin[3] = zhiju_eeprom_data.zhiju_information.chip_bin + '0';
          qr_code.chip_bin[0] = 'B';
          qr_code.chip_bin[1] = 'I';
          qr_code.chip_bin[2] = 'N';
          uVar3 = qr_code.temp_sensor_type._5_3_;
          uVar4 = qr_code.temp_sensor_type._6_2_;
          if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false)
          {
            if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic !=
                false) {
              switch(zhiju_eeprom_data.zhiju_information.asic_sensor & 0x7f) {
              case 1:
                builtin_strncpy(qr_code.temp_sensor_type,"TMP4",4);
                qr_code.temp_sensor_type[4] = '5';
                qr_code.temp_sensor_type[5] = '1';
                qr_code.temp_sensor_type[6] = '\0';
                break;
              default:
                errmsg = "SENSOR TYPE";
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[0] = (uint8_t)uVar1;
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[1] = SUB41(uVar1,1);
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[2] = SUB41(uVar1,2);
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[3] = SUB41(uVar1,3);
                qr_code.chip_ftversion[0] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[0];
                qr_code.chip_ftversion[1] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[1];
                qr_code.chip_ftversion[2] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[2];
                qr_code.chip_ftversion[3] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[3];
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[4] = (uint8_t)uVar2;
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[5] = SUB41(uVar2,1);
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[6] = SUB41(uVar2,2);
                zhiju_eeprom_data.zhiju_information.chip_ft_program_version[7] = SUB41(uVar2,3);
                qr_code.chip_ftversion[4] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[4];
                qr_code.chip_ftversion[5] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[5];
                qr_code.chip_ftversion[6] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[6];
                qr_code.chip_ftversion[7] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[7];
                qr_code.chip_ftversion[8] =
                     zhiju_eeprom_data.zhiju_information.chip_ft_program_version[8];
                return errmsg;
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
                qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
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
                qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
                break;
              case 0xd:
                builtin_strncpy(qr_code.temp_sensor_type,"GM45",4);
                qr_code.temp_sensor_type[4] = '2';
                qr_code.temp_sensor_type[5] = '\0';
                qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
                break;
              case 0xe:
                builtin_strncpy(qr_code.temp_sensor_type,"CT75",4);
                qr_code.temp_sensor_type._4_4_ = (uint)(uint3)uVar3 << 8;
                break;
              case 0xf:
                builtin_strncpy(qr_code.temp_sensor_type,"DS75SPlus",10);
                break;
              case 0x10:
                builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
                qr_code.temp_sensor_type[4] = '5';
                qr_code.temp_sensor_type[5] = '\0';
                qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
                break;
              case 0x11:
                builtin_strncpy(qr_code.temp_sensor_type,"SD17",4);
                qr_code.temp_sensor_type[4] = '7';
                qr_code.temp_sensor_type[5] = '\0';
                qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
                break;
              case 0x12:
                builtin_strncpy(qr_code.temp_sensor_type,"GX21",4);
                qr_code.temp_sensor_type[4] = 'M';
                qr_code.temp_sensor_type[5] = '\0';
                qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
                break;
              case 0x13:
                builtin_strncpy(qr_code.temp_sensor_type,"NT17",4);
                qr_code.temp_sensor_type[4] = '5';
                qr_code.temp_sensor_type[5] = '\0';
                qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
              }
            }
          }
          else {
            switch(zhiju_eeprom_data.zhiju_information.pic_sensor & 0x7f) {
            case 1:
              builtin_strncpy(qr_code.temp_sensor_type,"TMP4",4);
              qr_code.temp_sensor_type[4] = '5';
              qr_code.temp_sensor_type[5] = '1';
              qr_code.temp_sensor_type[6] = '\0';
              break;
            default:
              errmsg = "SENSOR TYPE";
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[0] = (uint8_t)uVar1;
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[1] = SUB41(uVar1,1);
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[2] = SUB41(uVar1,2);
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[3] = SUB41(uVar1,3);
              qr_code.chip_ftversion[0] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[0];
              qr_code.chip_ftversion[1] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[1];
              qr_code.chip_ftversion[2] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[2];
              qr_code.chip_ftversion[3] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[3];
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[4] = (uint8_t)uVar2;
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[5] = SUB41(uVar2,1);
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[6] = SUB41(uVar2,2);
              zhiju_eeprom_data.zhiju_information.chip_ft_program_version[7] = SUB41(uVar2,3);
              qr_code.chip_ftversion[4] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[4];
              qr_code.chip_ftversion[5] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[5];
              qr_code.chip_ftversion[6] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[6];
              qr_code.chip_ftversion[7] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[7];
              qr_code.chip_ftversion[8] =
                   zhiju_eeprom_data.zhiju_information.chip_ft_program_version[8];
              return errmsg;
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
              qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
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
              qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
              break;
            case 0xd:
              builtin_strncpy(qr_code.temp_sensor_type,"GM45",4);
              qr_code.temp_sensor_type[4] = '2';
              qr_code.temp_sensor_type[5] = '\0';
              qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
              break;
            case 0xe:
              builtin_strncpy(qr_code.temp_sensor_type,"CT75",4);
              qr_code.temp_sensor_type._4_4_ = (uint)(uint3)uVar3 << 8;
              break;
            case 0xf:
              builtin_strncpy(qr_code.temp_sensor_type,"DS75SPlus",10);
              break;
            case 0x10:
              builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
              qr_code.temp_sensor_type[4] = '5';
              qr_code.temp_sensor_type[5] = '\0';
              qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
              break;
            case 0x11:
              builtin_strncpy(qr_code.temp_sensor_type,"SD17",4);
              qr_code.temp_sensor_type[4] = '7';
              qr_code.temp_sensor_type[5] = '\0';
              qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
              break;
            case 0x12:
              builtin_strncpy(qr_code.temp_sensor_type,"GX21",4);
              qr_code.temp_sensor_type[4] = 'M';
              qr_code.temp_sensor_type[5] = '\0';
              qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
              break;
            case 0x13:
              builtin_strncpy(qr_code.temp_sensor_type,"NT17",4);
              qr_code.temp_sensor_type[4] = '5';
              qr_code.temp_sensor_type[5] = '\0';
              qr_code.temp_sensor_type._4_4_ = CONCAT22(uVar4,qr_code.temp_sensor_type._4_2_);
            }
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : pcb_version_v1: [0x%x] = %x\n","load_board_info_from_format_v3",0x34,
                 (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v1);
          snprintf(tmp1,0x100,"pcb_version_v1: [0x%x] = %x",0x34,
                   (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v1);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : pcb_version_v2: [0x%x] = %x\n","load_board_info_from_format_v3",0x35,
                 (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v2);
          snprintf(tmp1,0x100,"pcb_version_v2: [0x%x] = %x",0x35,
                   (uint)zhiju_eeprom_data.zhiju_information.pcb_version_v2);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : bom_version_v1: [0x%x] = %x\n","load_board_info_from_format_v3",0x36,
                 (uint)zhiju_eeprom_data.zhiju_information.bom_version_v1);
          snprintf(tmp1,0x100,"bom_version_v1: [0x%x] = %x",0x36,
                   (uint)zhiju_eeprom_data.zhiju_information.bom_version_v1);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : bom_version_v2: [0x%x] = %x\n","load_board_info_from_format_v3",0x37,
                 (uint)zhiju_eeprom_data.zhiju_information.bom_version_v2);
          snprintf(tmp1,0x100,"bom_version_v2: [0x%x] = %x",0x37,
                   (uint)zhiju_eeprom_data.zhiju_information.bom_version_v2);
          log_to_file(tmp1,time_stamp);
          sprintf(qr_code.hashboard_ctrl_code,"%x",
                  (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.pcb_version_v1,
                                 zhiju_eeprom_data.zhiju_information.pcb_version_v2));
          sprintf(qr_code.hashboard_ctrl_code + 3,"%x",
                  (uint)CONCAT11(zhiju_eeprom_data.zhiju_information.bom_version_v1,
                                 zhiju_eeprom_data.zhiju_information.bom_version_v2));
          qr_code.hashboard_ctrl_code[5] = zhiju_eeprom_data.zhiju_information.chip_technology[0];
          qr_code.hashboard_ctrl_code[6] = zhiju_eeprom_data.zhiju_information.chip_technology[1];
          builtin_strncpy(qr_code.factory_job,"FXDZ20210308001-Z(YZ)",0x16);
        }
      }
      else {
        errmsg = "CRC5 ERROR";
      }
    }
    else {
      errmsg = "DEC FAILED";
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : enc 0x%x len 0x%x\n","load_board_info_from_format_v3",(uint)(byte)*data,
           (uint)(byte)data[1]);
    snprintf(tmp1,0x100,"enc 0x%x len 0x%x",(uint)(byte)*data,(uint)(byte)data[1]);
    log_to_file(tmp1,time_stamp);
    errmsg = "LEN ERROR";
  }
  return errmsg;
}

