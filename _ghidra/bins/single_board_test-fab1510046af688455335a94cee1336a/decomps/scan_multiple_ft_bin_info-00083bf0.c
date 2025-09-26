
_Bool scan_multiple_ft_bin_info(char *data,hashboard_qr_code *qrcode)

{
  _Bool _Var1;
  char *pcVar2;
  size_t __n;
  int iVar3;
  ft_bin_list_t *list;
  hashboard_qr_code *qrcode_local;
  char *data_local;
  char time_stamp [48];
  char tmp1 [2048];
  int speed_bin;
  int ele_bin;
  int vol_bin;
  int ft_ver;
  int fe_ver;
  char chipmarking [3] [24];
  char chiptech [3] [16];
  int col [3];
  char mult_ft_bin [3] [24];
  int mult_ft_bin_id;
  char mult_ft_bin_code [24];
  ft_bin_list_t *p_list;
  int i;
  
  memset(mult_ft_bin_code,0,0x18);
  memset(mult_ft_bin,0,0x48);
  memset(col,0,0xc);
  mult_ft_bin_id = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: QRCODE:%s\n","scan_multiple_ft_bin_info",data);
  snprintf(tmp1,0x800,"QRCODE:%s",data);
  log_to_file(tmp1,time_stamp);
  __isoc99_sscanf(data,"%s %s %s %s %s %d %s %s %s %d %s %s %s %d %s",qrcode,qrcode->chip_die,
                  qrcode->temp_sensor_type,qrcode->hashboard_ctrl_code,mult_ft_bin_code,
                  &mult_ft_bin_id,chiptech,chipmarking,mult_ft_bin,col,chiptech + 1,chipmarking + 1,
                  mult_ft_bin + 1,col + 1,qrcode->hashboard_index);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: mult_ft_bin0 %s\n","scan_multiple_ft_bin_info",mult_ft_bin);
  snprintf(tmp1,0x800,"mult_ft_bin0 %s",mult_ft_bin);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: mult_ft_bin1 %s\n","scan_multiple_ft_bin_info",mult_ft_bin + 1);
  snprintf(tmp1,0x800,"mult_ft_bin1 %s",mult_ft_bin + 1);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: mult_ft_bin2 %s\n","scan_multiple_ft_bin_info",mult_ft_bin + 2);
  snprintf(tmp1,0x800,"mult_ft_bin2 %s",mult_ft_bin + 2);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: col %d\n","scan_multiple_ft_bin_info",col[0]);
  snprintf(tmp1,0x800,"col %d",col[0]);
  log_to_file(tmp1,time_stamp);
  strncat(qr_code.hashboard_ctrl_code,chiptech[0],2);
  strcpy(qr_code.chip_marking,chipmarking[0]);
  multiple_ft_bin_info_compress
            (mult_ft_bin[0],mult_ft_bin[1],col,qrcode->chip_ftversion,qrcode->chip_bin);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: chip_ftversion %s\n","scan_multiple_ft_bin_info",qrcode->chip_ftversion);
  snprintf(tmp1,0x800,"chip_ftversion %s",qrcode->chip_ftversion);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: chip_bin %s\n","scan_multiple_ft_bin_info",qrcode->chip_bin);
  snprintf(tmp1,0x800,"chip_bin %s",qrcode->chip_bin);
  log_to_file(tmp1,time_stamp);
  pcVar2 = strstr(mult_ft_bin_code,"MBX");
  if (pcVar2 != (char *)0x0) {
    list = &qrcode->ft_bin_list;
    (qrcode->ft_bin_list).ft_bin_id = (uint8_t)mult_ft_bin_id;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ft_bin_id:%d\n","scan_multiple_ft_bin_info",(uint)(qrcode->ft_bin_list).ft_bin_id);
    snprintf(tmp1,0x800,"ft_bin_id:%d",(uint)(qrcode->ft_bin_list).ft_bin_id);
    log_to_file(tmp1,time_stamp);
    for (i = 0; i < 3; i = i + 1) {
      __n = strlen(mult_ft_bin[i]);
      iVar3 = strncmp(mult_ft_bin[i],"X",__n);
      if ((iVar3 == 0) || (col[i] == 0)) break;
      __isoc99_sscanf(mult_ft_bin + i,"%*C%dV%dB%dC%d-%d",&fe_ver,&ft_ver,&vol_bin,&ele_bin,
                      &speed_bin);
      _Var1 = check_ft_bin_val(mult_ft_bin[i][0],fe_ver,ft_ver,vol_bin,ele_bin,speed_bin,col[i]);
      if (!_Var1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: err ft_bin info!\n","scan_multiple_ft_bin_info");
        builtin_strncpy(tmp1,"err ft_bin info!",0x10);
        tmp1[0x10] = '\0';
        log_to_file(tmp1,time_stamp);
        (qrcode->ft_bin_list).ft_bin_cnt = 0;
        return false;
      }
      *(byte *)(list->ft_bin + i) = *(byte *)(list->ft_bin + i) & 0xfe | mult_ft_bin[i][0] == 'F';
      *(byte *)(list->ft_bin + i) = *(byte *)(list->ft_bin + i) & 0xf1 | (byte)((fe_ver & 7U) << 1);
      *(ushort *)(list->ft_bin + i) =
           *(ushort *)(list->ft_bin + i) & 0xfc0f | (ushort)((ft_ver & 0x3fU) << 4);
      *(byte *)((int)list->ft_bin + i * 4 + 1) =
           *(byte *)((int)list->ft_bin + i * 4 + 1) & 0xe3 | (byte)((vol_bin & 7U) << 2);
      *(byte *)((int)list->ft_bin + i * 4 + 1) =
           *(byte *)((int)list->ft_bin + i * 4 + 1) & 0x9f | (byte)((ele_bin & 3U) << 5);
      list->ft_bin[i].v = list->ft_bin[i].v & 0xfffc7fff | (speed_bin & 7U) << 0xf;
      *(byte *)((int)list->ft_bin + i * 4 + 2) =
           *(byte *)((int)list->ft_bin + i * 4 + 2) & 0xf | (byte)((col[i] & 0xfU) << 4);
      (qrcode->ft_bin_list).ft_bin_cnt = (qrcode->ft_bin_list).ft_bin_cnt + 1;
    }
    log_out_multiple_ft_bin_info(list);
    if ((qrcode->ft_bin_list).ft_bin_cnt != 0) {
      return true;
    }
  }
  return false;
}

