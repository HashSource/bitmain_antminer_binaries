
_Bool scan_multiple_ft_bin_info(char *data,hashboard_qr_code *qrcode)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  ft_bin_list_t *f;
  hashboard_qr_code *qrcode_local;
  char *data_local;
  char time_stamp [48];
  char tmp1 [256];
  char chipmarking [3] [24];
  char chiptech [3] [16];
  int col [3];
  char mult_ft_bin [3] [24];
  int mult_ft_bin_id;
  char mult_ft_bin_code [24];
  ft_bin_list_t *p_list;
  int marking_index;
  int i;
  
  memset(mult_ft_bin_code,0,0x18);
  memset(mult_ft_bin,0,0x48);
  memset(col,0,0xc);
  mult_ft_bin_id = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : QRCODE:%s\n","scan_multiple_ft_bin_info",data);
  snprintf(tmp1,0x100,"QRCODE:%s",data);
  log_to_file(tmp1,time_stamp);
  __isoc99_sscanf(data,"%s %s %s %s %s %d %s %s %s %d %s %s %s %d %s",qrcode,qrcode->chip_die,
                  qrcode->temp_sensor_type,qrcode->hashboard_ctrl_code,mult_ft_bin_code,
                  &mult_ft_bin_id,chiptech,chipmarking,mult_ft_bin,col,chiptech + 1,chipmarking + 1,
                  mult_ft_bin + 1,col + 1,qrcode->hashboard_index);
  pcVar1 = strstr(mult_ft_bin_code,"MBX");
  if (pcVar1 != (char *)0x0) {
    f = &qrcode->ft_bin_list;
    (qrcode->ft_bin_list).ft_bin_id = (uint8_t)mult_ft_bin_id;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : ft_bin_id:%d\n","scan_multiple_ft_bin_info",(uint)(qrcode->ft_bin_list).ft_bin_id);
    snprintf(tmp1,0x100,"ft_bin_id:%d",(uint)(qrcode->ft_bin_list).ft_bin_id);
    log_to_file(tmp1,time_stamp);
    strncpy(qrcode->chip_marking,chipmarking[0],4);
    strncpy(qrcode->chip_marking + 4,chiptech[0],2);
    strncpy(qrcode->chip_marking + 6,chipmarking[1],4);
    strncpy(qrcode->chip_marking + 10,chiptech[1],2);
    for (i = 0; i < 2; i = i + 1) {
      memset(f->chip_ftversion + i,0,0x10);
      sVar2 = strlen(mult_ft_bin[i]);
      iVar3 = strncmp(mult_ft_bin[i],"X",sVar2);
      if ((iVar3 == 0) || (col[i] == 0)) break;
      sVar2 = strlen(mult_ft_bin[i]);
      memcpy(f->chip_ftversion + i,mult_ft_bin + i,sVar2);
      sVar2 = strlen(mult_ft_bin[i]);
      f->chip_ftversion[i + -1][sVar2 + 0xe] = '\0';
      sVar2 = strlen(mult_ft_bin[i]);
      f->chip_bin[i] = mult_ft_bin[i + -1][sVar2 + 0x17] + 0xd0;
      f->chip_col[i] = (uint8_t)col[i];
    }
    if (((qrcode->ft_bin_list).chip_ftversion[0][0] != '\0') &&
       ((qrcode->ft_bin_list).chip_ftversion[1][0] != '\0')) {
      encode_multi_ft_version(f);
      memcpy(qr_code.chip_ftversion,f,10);
      log_out_multiple_ft_bin_info(f);
      return true;
    }
  }
  return false;
}

