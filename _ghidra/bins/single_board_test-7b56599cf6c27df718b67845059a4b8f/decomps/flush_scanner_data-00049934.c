
/* WARNING: Unknown calling convention */

int32_t flush_scanner_data(void)

{
  int32_t iVar1;
  char time_stamp [48];
  char tmp1 [256];
  
  iVar1 = detect_scan_code_gun();
  if (iVar1 == 0) {
    scan_data_offset = 0;
    remain_data_len = 0xff;
    memset(scan_code_data,0,0x100);
    iVar1 = uart_flush(3);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s can\'t detect scanner!!!.\n","flush_scanner_data","flush_scanner_data");
    snprintf(tmp1,0x100,"%s can\'t detect scanner!!!.","flush_scanner_data");
    log_to_file(tmp1,time_stamp);
    iVar1 = -1;
  }
  return iVar1;
}

