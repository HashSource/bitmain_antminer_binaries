
int32_t parse_scan_data(char *scan_data,hashboard_sn *sn,_Bool *sn_ok,hashboard_qr_code *qrcode,
                       _Bool *qrcode_ok)

{
  uint8_t uVar1;
  size_t sVar2;
  char *pcVar3;
  int32_t iVar4;
  hashboard_qr_code *qrcode_local;
  _Bool *sn_ok_local;
  hashboard_sn *sn_local;
  char *scan_data_local;
  char time_stamp [48];
  char tmp1 [256];
  char data [256];
  uint32_t j;
  uint32_t i;
  
  j = 0;
  memset(data,0,0x100);
  if ((((scan_data == (char *)0x0) || (sn == (hashboard_sn *)0x0)) || (sn_ok == (_Bool *)0x0)) ||
     ((qrcode == (hashboard_qr_code *)0x0 || (qrcode_ok == (_Bool *)0x0)))) {
    iVar4 = -1;
  }
  else if (*scan_data == '\0') {
    iVar4 = -2;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : scan_code_data::%s\n","parse_scan_data",scan_data);
    snprintf(tmp1,0x100,"scan_code_data::%s",scan_data);
    log_to_file(tmp1,time_stamp);
    memset(data,0,0x100);
    i = 0;
    while( true ) {
      sVar2 = strlen(scan_data);
      if (sVar2 <= i) break;
      if ((0x1f < (byte)scan_data[i]) && ((byte)scan_data[i] < 0x7f)) {
        data[j] = scan_data[i];
        j = j + 1;
      }
      i = i + 1;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : after check, scan_code_data::%s\n","parse_scan_data",data);
    snprintf(tmp1,0x100,"after check, scan_code_data::%s",data);
    log_to_file(tmp1,time_stamp);
    pcVar3 = strchr(data,0x20);
    if (pcVar3 == (char *)0x0) {
      sVar2 = strlen(data);
      if (sVar2 != 0x11) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : bad data format!!!drop it.\n","parse_scan_data");
        builtin_strncpy(tmp1,"bad data format!!!drop i",0x18);
        tmp1[0x18] = 't';
        tmp1[0x19] = '.';
        tmp1[0x1a] = '\0';
        log_to_file(tmp1,time_stamp);
        return -3;
      }
      *sn_ok = true;
      memset(sn->board_sn,0,0x20);
      sn->sn_len = '\x11';
      memcpy(sn->board_sn,data,0x11);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : recv sn data::[%s]\n","parse_scan_data",sn->board_sn);
      snprintf(tmp1,0x100,"recv sn data::[%s]",sn->board_sn);
      log_to_file(tmp1,time_stamp);
    }
    else {
      *qrcode_ok = true;
      __isoc99_sscanf(data,"%s %s %s %s %s %s %s %s",qrcode,qrcode->chip_die,qrcode->chip_marking,
                      qrcode->chip_bin,qrcode->chip_ftversion,qrcode->temp_sensor_type,
                      qrcode->hashboard_ctrl_code,qrcode->hashboard_index);
      uVar1 = get_sensor_type(&qr_code);
      if (uVar1 == '\0') {
        lcd_clear_result();
        lcd_show(1,"sensor type");
        lcd_show(2,"error");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : sensor type error\n","parse_scan_data");
        builtin_strncpy(tmp1,"sensor type erro",0x10);
        tmp1[0x10] = 'r';
        tmp1[0x11] = '\0';
        log_to_file(tmp1,time_stamp);
        return -1;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : recv qrcode data::\n","parse_scan_data");
      builtin_strncpy(tmp1,"recv qrcode data",0x10);
      tmp1[0x10] = ':';
      tmp1[0x11] = ':';
      tmp1[0x12] = '\0';
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : factory_job::[%s].\n","parse_scan_data",qrcode);
      snprintf(tmp1,0x100,"factory_job::[%s].",qrcode);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : chip_die::[%s].\n","parse_scan_data",qrcode->chip_die);
      snprintf(tmp1,0x100,"chip_die::[%s].",qrcode->chip_die);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : chip_marking::[%s].\n","parse_scan_data",qrcode->chip_marking);
      snprintf(tmp1,0x100,"chip_marking::[%s].",qrcode->chip_marking);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : chip_bin::[%s].\n","parse_scan_data",qrcode->chip_bin);
      snprintf(tmp1,0x100,"chip_bin::[%s].",qrcode->chip_bin);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : chip_ftversion::[%s].\n","parse_scan_data",qrcode->chip_ftversion);
      snprintf(tmp1,0x100,"chip_ftversion::[%s].",qrcode->chip_ftversion);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : temp_sensor_type::[%s].\n","parse_scan_data",qrcode->temp_sensor_type);
      snprintf(tmp1,0x100,"temp_sensor_type::[%s].",qrcode->temp_sensor_type);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : hashboard_ctrl_code::[%s].\n","parse_scan_data",qrcode->hashboard_ctrl_code);
      snprintf(tmp1,0x100,"hashboard_ctrl_code::[%s].",qrcode->hashboard_ctrl_code);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : hashboard_index::[%s].\n","parse_scan_data",qrcode->hashboard_index);
      snprintf(tmp1,0x100,"hashboard_index::[%s].",qrcode->hashboard_index);
      log_to_file(tmp1,time_stamp);
    }
    iVar4 = 0;
  }
  return iVar4;
}

