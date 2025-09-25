
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

_Bool read_board_info_from_eeprom(void)

{
  Hash_Board *pHVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined2 uVar4;
  _Bool _Var5;
  int iVar6;
  size_t sVar7;
  char time_stamp [48];
  char tmp1 [256];
  char data [40];
  uint16_t frequency;
  uint16_t pcb_version;
  uint8_t bom_version;
  uint8_t sensor_type;
  uint8_t chip_bin;
  int i;
  char *errmsg;
  
  uVar2 = qr_code.chip_marking._8_4_;
  if ((Local_Config_Information->Repair_Mode).Enable_Repair != false) {
    gScanCodeGun_data_ready = '\x03';
    builtin_strncpy(sn.board_sn,"12345678901234567",0x12);
    builtin_strncpy(qr_code.factory_job,"20200320003(YZ)",0x10);
    qr_code.chip_die[0] = 'E';
    qr_code.chip_die[1] = 'D';
    qr_code.chip_die[2] = '\0';
    builtin_strncpy(qr_code.chip_marking,"S13020AH01",0xb);
    qr_code.chip_marking[0xb] = SUB41(uVar2,3);
    builtin_strncpy(qr_code.chip_bin,"BIN1",5);
    builtin_strncpy(qr_code.chip_ftversion,"F1V01B4C1",10);
    builtin_strncpy(qr_code.temp_sensor_type,"TMP7",4);
    qr_code.temp_sensor_type[4] = '5';
    qr_code.temp_sensor_type[5] = 'A';
    qr_code.temp_sensor_type[6] = '\0';
    builtin_strncpy(qr_code.hashboard_ctrl_code,"10010BB",8);
    builtin_strncpy(qr_code.hashboard_index,"0123",5);
  }
  eeprom_v1_init(&eeprom_ctx,(uint8_t)gChain,eeprom_nonce);
  iVar6 = (*eeprom_ctx.board_name_retrieve)(&eeprom_ctx);
  if ((((iVar6 == 0) && (iVar6 = (*eeprom_ctx.version_retrieve)(&eeprom_ctx), iVar6 == 0)) &&
      (iVar6 = (*eeprom_ctx.pt1_retrieve)(&eeprom_ctx), iVar6 == 0)) &&
     ((iVar6 = (*eeprom_ctx.pt2_retrieve)(&eeprom_ctx), iVar6 == 0 &&
      (iVar6 = (*eeprom_ctx.sweep_retrieve)(&eeprom_ctx), iVar6 == 0)))) {
    _Var5 = (*eeprom_ctx.is_board_name_available)(&eeprom_ctx);
    if (((_Var5) && (_Var5 = (*eeprom_ctx.is_version_available)(&eeprom_ctx), _Var5)) &&
       (_Var5 = (*eeprom_ctx.is_pt1_available)(&eeprom_ctx), _Var5)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom version: %d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.version);
      snprintf(tmp1,0x100,"pt1 eeprom version: %d",(uint)eeprom_ctx.data.version);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom board_name: %s\n","read_board_info_from_eeprom",0xb2715d);
      snprintf(tmp1,0x100,"pt1 eeprom board_name: %s",0xb2715d);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom board_sn: %s\n","read_board_info_from_eeprom",0xb2716c);
      snprintf(tmp1,0x100,"pt1 eeprom board_sn: %s",0xb2716c);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom bom_version: %x\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2._72_4_ >> 0x18);
      snprintf(tmp1,0x100,"pt1 eeprom bom_version: %x",(uint)eeprom_ctx.data.field_2._72_4_ >> 0x18)
      ;
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom chip_bin: %d\n","read_board_info_from_eeprom",
             eeprom_ctx.data.field_2._72_4_ & 0xff);
      snprintf(tmp1,0x100,"pt1 eeprom chip_bin: %d",eeprom_ctx.data.field_2._72_4_ & 0xff);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom chip_die: %s\n","read_board_info_from_eeprom",0xb27196);
      snprintf(tmp1,0x100,"pt1 eeprom chip_die: %s",0xb27196);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom chip_marking: %s\n","read_board_info_from_eeprom",0xb27199);
      snprintf(tmp1,0x100,"pt1 eeprom chip_marking: %s",0xb27199);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom chip_tech: %s\n","read_board_info_from_eeprom",0xb271b1);
      snprintf(tmp1,0x100,"pt1 eeprom chip_tech: %s",0xb271b1);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom factory_job: %s\n","read_board_info_from_eeprom",0xb2717e);
      snprintf(tmp1,0x100,"pt1 eeprom factory_job: %s",0xb2717e);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom ft_version: %s\n","read_board_info_from_eeprom",0xb271a7);
      snprintf(tmp1,0x100,"pt1 eeprom ft_version: %s",0xb271a7);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom pcb_version: %x\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2._72_4_ >> 8 & 0xffff);
      snprintf(tmp1,0x100,"pt1 eeprom pcb_version: %x",
               (uint)eeprom_ctx.data.field_2._72_4_ >> 8 & 0xffff);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom pt1_count: %d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_count);
      snprintf(tmp1,0x100,"pt1 eeprom pt1_count: %d",
               (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_count);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom pt1_result: %d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_result);
      snprintf(tmp1,0x100,"pt1 eeprom pt1_result: %d",
               (uint)eeprom_ctx.data.field_2.format_v1.pt1.pt1_result);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt1 eeprom sensor_type: %d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.pt1.sensor_type);
      snprintf(tmp1,0x100,"pt1 eeprom sensor_type: %d",
               (uint)eeprom_ctx.data.field_2.format_v1.pt1.sensor_type);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : voltage:%d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.pt2.voltage);
      snprintf(tmp1,0x100,"voltage:%d",(uint)eeprom_ctx.data.field_2.format_v1.pt2.voltage);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : frequency:%d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.pt2.frequency);
      snprintf(tmp1,0x100,"frequency:%d",(uint)eeprom_ctx.data.field_2.format_v1.pt2.frequency);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : nonce_rate:%d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.pt2.nonce_rate);
      snprintf(tmp1,0x100,"nonce_rate:%d",(uint)eeprom_ctx.data.field_2.format_v1.pt2.nonce_rate);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2_result:%d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.pt2.pt2_result);
      snprintf(tmp1,0x100,"pt2_result:%d",(uint)eeprom_ctx.data.field_2.format_v1.pt2.pt2_result);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sweep_result:%d\n","read_board_info_from_eeprom",
             (uint)eeprom_ctx.data.field_2.format_v1.sweep.sweep_result);
      snprintf(tmp1,0x100,"sweep_result:%d",
               (uint)eeprom_ctx.data.field_2.format_v1.sweep.sweep_result);
      log_to_file(tmp1,time_stamp);
      memset(&qr_code,0,0x20);
      qr_code.factory_job[0] = eeprom_ctx.data.field_2._18_1_;
      qr_code.factory_job[1] = eeprom_ctx.data.field_2._19_1_;
      qr_code.factory_job[2] = eeprom_ctx.data.field_2._20_1_;
      qr_code.factory_job[3] = eeprom_ctx.data.field_2._21_1_;
      qr_code.factory_job[4] = eeprom_ctx.data.field_2._22_1_;
      qr_code.factory_job[5] = eeprom_ctx.data.field_2._23_1_;
      qr_code.factory_job[6] = eeprom_ctx.data.field_2._24_1_;
      qr_code.factory_job[7] = eeprom_ctx.data.field_2._25_1_;
      qr_code.factory_job[8] = eeprom_ctx.data.field_2._26_1_;
      qr_code.factory_job[9] = eeprom_ctx.data.field_2._27_1_;
      qr_code.factory_job[10] = eeprom_ctx.data.field_2._28_1_;
      qr_code.factory_job[0xb] = eeprom_ctx.data.field_2._29_1_;
      qr_code.factory_job[0xc] = eeprom_ctx.data.field_2._30_1_;
      qr_code.factory_job[0xd] = eeprom_ctx.data.field_2._31_1_;
      qr_code.factory_job[0xe] = eeprom_ctx.data.field_2._32_1_;
      qr_code.factory_job[0xf] = eeprom_ctx.data.field_2._33_1_;
      qr_code.factory_job[0x10] = eeprom_ctx.data.field_2._34_1_;
      qr_code.factory_job[0x11] = eeprom_ctx.data.field_2._35_1_;
      qr_code.factory_job[0x12] = eeprom_ctx.data.field_2._36_1_;
      qr_code.factory_job[0x13] = eeprom_ctx.data.field_2._37_1_;
      qr_code.factory_job[0x14] = eeprom_ctx.data.field_2._38_1_;
      qr_code.factory_job[0x15] = eeprom_ctx.data.field_2._39_1_;
      qr_code.factory_job[0x16] = eeprom_ctx.data.field_2._40_1_;
      qr_code.factory_job[0x17] = eeprom_ctx.data.field_2._41_1_;
      memset(sn.board_sn,0,0x20);
      sn.board_sn[0] = eeprom_ctx.data.field_2._0_1_;
      sn.board_sn[1] = eeprom_ctx.data.field_2._1_1_;
      sn.board_sn[2] = eeprom_ctx.data.field_2._2_1_;
      sn.board_sn[3] = eeprom_ctx.data.field_2._3_1_;
      sn.board_sn[4] = eeprom_ctx.data.field_2._4_1_;
      sn.board_sn[5] = eeprom_ctx.data.field_2._5_1_;
      sn.board_sn[6] = eeprom_ctx.data.field_2._6_1_;
      sn.board_sn[7] = eeprom_ctx.data.field_2._7_1_;
      sn.board_sn[8] = eeprom_ctx.data.field_2._8_1_;
      sn.board_sn[9] = eeprom_ctx.data.field_2._9_1_;
      sn.board_sn[10] = eeprom_ctx.data.field_2._10_1_;
      sn.board_sn[0xb] = eeprom_ctx.data.field_2._11_1_;
      sn.board_sn[0xc] = eeprom_ctx.data.field_2._12_1_;
      sn.board_sn[0xd] = eeprom_ctx.data.field_2._13_1_;
      sn.board_sn[0xe] = eeprom_ctx.data.field_2._14_1_;
      sn.board_sn[0xf] = eeprom_ctx.data.field_2._15_1_;
      sn.board_sn[0x10] = eeprom_ctx.data.field_2._16_1_;
      sn.board_sn[0x11] = eeprom_ctx.data.field_2._17_1_;
      sVar7 = strlen(sn.board_sn);
      sn.sn_len = (char)sVar7;
      memset(qr_code.chip_die,0,0x10);
      qr_code.chip_die[0] = eeprom_ctx.data.field_2._42_1_;
      qr_code.chip_die[1] = eeprom_ctx.data.field_2._43_1_;
      qr_code.chip_die[2] = eeprom_ctx.data.field_2.format_v1.pt1.chip_die[2];
      memset(qr_code.chip_marking,0,0x10);
      qr_code.chip_marking[0] = eeprom_ctx.data.field_2._45_1_;
      qr_code.chip_marking[1] = eeprom_ctx.data.field_2._46_1_;
      qr_code.chip_marking[2] = eeprom_ctx.data.field_2._47_1_;
      qr_code.chip_marking[3] = eeprom_ctx.data.field_2._48_1_;
      qr_code.chip_marking[4] = eeprom_ctx.data.field_2._49_1_;
      qr_code.chip_marking[5] = eeprom_ctx.data.field_2._50_1_;
      qr_code.chip_marking[6] = eeprom_ctx.data.field_2._51_1_;
      qr_code.chip_marking[7] = eeprom_ctx.data.field_2._52_1_;
      qr_code.chip_marking[8] = eeprom_ctx.data.field_2._53_1_;
      qr_code.chip_marking[9] = eeprom_ctx.data.field_2._54_1_;
      qr_code.chip_marking[10] = eeprom_ctx.data.field_2._55_1_;
      qr_code.chip_marking[0xb] = eeprom_ctx.data.field_2._56_1_;
      qr_code.chip_marking[0xc] = eeprom_ctx.data.field_2._57_1_;
      qr_code.chip_marking[0xd] = eeprom_ctx.data.field_2._58_1_;
      memset(qr_code.chip_ftversion,0,0x10);
      qr_code.chip_ftversion[0] = eeprom_ctx.data.field_2._59_1_;
      qr_code.chip_ftversion[1] = eeprom_ctx.data.field_2._60_1_;
      qr_code.chip_ftversion[2] = eeprom_ctx.data.field_2._61_1_;
      qr_code.chip_ftversion[3] = eeprom_ctx.data.field_2._62_1_;
      qr_code.chip_ftversion[4] = eeprom_ctx.data.field_2._63_1_;
      qr_code.chip_ftversion[5] = eeprom_ctx.data.field_2._64_1_;
      qr_code.chip_ftversion[6] = eeprom_ctx.data.field_2._65_1_;
      qr_code.chip_ftversion[7] = eeprom_ctx.data.field_2._66_1_;
      qr_code.chip_ftversion[8] = eeprom_ctx.data.field_2._67_1_;
      qr_code.chip_ftversion[9] = eeprom_ctx.data.field_2._68_1_;
      strncpy(qr_code.chip_bin,"BIN0",0x10);
      if ((eeprom_ctx.data.field_2.format_v1.pt1.chip_bin == '\0') ||
         (9 < eeprom_ctx.data.field_2.format_v1.pt1.chip_bin)) {
        errmsg = "CHIP BIN";
      }
      else {
        qr_code.chip_bin[3] = eeprom_ctx.data.field_2.format_v1.pt1.chip_bin + '0';
        uVar3 = qr_code.temp_sensor_type._5_3_;
        uVar4 = qr_code.temp_sensor_type._6_2_;
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
          if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false
             ) {
            switch(eeprom_ctx.data.field_2.format_v1.pt1.sensor_type & 0x7f) {
            case 1:
              builtin_strncpy(qr_code.temp_sensor_type,"TMP4",4);
              qr_code.temp_sensor_type[4] = '5';
              qr_code.temp_sensor_type[5] = '1';
              qr_code.temp_sensor_type[6] = '\0';
              break;
            default:
              errmsg = "SENSOR TYPE";
              goto LAB_00029030;
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
          switch(eeprom_ctx.data.field_2.format_v1.pt1.sensor_type & 0x7f) {
          case 1:
            builtin_strncpy(qr_code.temp_sensor_type,"TMP4",4);
            qr_code.temp_sensor_type[4] = '5';
            qr_code.temp_sensor_type[5] = '1';
            qr_code.temp_sensor_type[6] = '\0';
            break;
          default:
            errmsg = "SENSOR TYPE";
            goto LAB_00029030;
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
        sprintf(qr_code.hashboard_ctrl_code,"%03x",
                (uint)eeprom_ctx.data.field_2._72_4_ >> 8 & 0xffff);
        sprintf(qr_code.hashboard_ctrl_code + 3,"%02x",(uint)eeprom_ctx.data.field_2._72_4_ >> 0x18)
        ;
        qr_code.hashboard_ctrl_code[5] = eeprom_ctx.data.field_2._69_1_;
        qr_code.hashboard_ctrl_code[6] = eeprom_ctx.data.field_2._70_1_;
        qr_code.hashboard_ctrl_code[7] = eeprom_ctx.data.field_2.format_v1.pt1.chip_tech[2];
        pHVar1 = &Local_Config_Information->Hash_Board;
        sVar7 = strlen((Local_Config_Information->Hash_Board).Board_Name);
        iVar6 = strncmp(eeprom_ctx.data.board_name,pHVar1->Board_Name,sVar7);
        if (iVar6 != 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : readout boardname:%s,cfg:%s.\n","read_board_info_from_eeprom",0xb2715d,
                 (Local_Config_Information->Hash_Board).Board_Name);
          snprintf(tmp1,0x100,"readout boardname:%s,cfg:%s.",0xb2715d,
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
            goto LAB_00029030;
          }
        }
        gTest_loop = 1;
        iVar6 = (*eeprom_ctx.pt2_retrieve)(&eeprom_ctx);
        if ((iVar6 == 0) && (_Var5 = (*eeprom_ctx.is_pt2_available)(&eeprom_ctx), _Var5)) {
          (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Level = 1;
          (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Voltage =
               (uint)eeprom_ctx.data.field_2.format_v1.pt2.voltage;
          for (i = 1; i < 0x3c; i = i + 1) {
            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Level = 0;
            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Voltage = 0;
            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Pre_Open_Core_Voltage =
                 0;
            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Voltage = 0;
            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Frequence = 0;
          }
          (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Frequence =
               (Local_Config_Information->Test_Info).Freq_Flex +
               (uint)eeprom_ctx.data.field_2.format_v1.pt2.frequency;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : read back voltage:%d frequency:%d\n","read_board_info_from_eeprom",
                 (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Voltage,
                 (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Frequence);
          snprintf(tmp1,0x100,"read back voltage:%d frequency:%d",
                   (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Voltage,
                   (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Frequence);
          log_to_file(tmp1,time_stamp);
          g_eeprom_version = (uint32_t)eeprom_ctx.data.version;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : sn %s\n","read_board_info_from_eeprom",0xb275f9);
          snprintf(tmp1,0x100,"sn %s",0xb275f9);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : BIN %s\n","read_board_info_from_eeprom",0xb275a8);
          snprintf(tmp1,0x100,"BIN %s",0xb275a8);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : DIE %s\n","read_board_info_from_eeprom",0xb27588);
          snprintf(tmp1,0x100,"DIE %s",0xb27588);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : FT %s\n","read_board_info_from_eeprom",0xb275b8);
          snprintf(tmp1,0x100,"FT %s",0xb275b8);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : marking %s\n","read_board_info_from_eeprom",0xb27598);
          snprintf(tmp1,0x100,"marking %s",0xb27598);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : factory_job %s\n","read_board_info_from_eeprom",&qr_code);
          snprintf(tmp1,0x100,"factory_job %s",&qr_code);
          log_to_file(tmp1,time_stamp);
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : hashboard_ctrl_code %s\n","read_board_info_from_eeprom",0xb275d8);
          snprintf(tmp1,0x100,"hashboard_ctrl_code %s",0xb275d8);
          log_to_file(tmp1,time_stamp);
          return true;
        }
        errmsg = "PT2 RETRIEVE";
      }
    }
    else {
      errmsg = "AVAIL ERROR";
    }
  }
  else {
    errmsg = "READ ERROR";
  }
LAB_00029030:
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
  return false;
}

