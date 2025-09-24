
int32_t scan_hashboard_info(hashboard_sn *sn,hashboard_qr_code *qrcode,_Bool *sn_ok,_Bool *qrcode_ok
                           ,int32_t timeout)

{
  int32_t iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  size_t sVar5;
  _Bool *qrcode_ok_local;
  _Bool *sn_ok_local;
  hashboard_qr_code *qrcode_local;
  hashboard_sn *sn_local;
  char time_stamp [48];
  char tmp1 [256];
  char recv_buffer [10];
  char *terminal_rn;
  char *terminal_r;
  char *terminal_n;
  char *terminal_position;
  
  iVar1 = detect_scan_code_gun();
  if (iVar1 == 0) {
    do {
      memset(recv_buffer,0,10);
      iVar1 = recv_scan_data(recv_buffer,9);
      if (iVar1 < 1) {
        timeout = timeout + -10;
        usleep(10000);
      }
      else {
        pcVar2 = strstr(recv_buffer,"\r\n");
        pcVar3 = strchr(recv_buffer,10);
        pcVar4 = strchr(recv_buffer,0xd);
        if (((pcVar2 == (char *)0x0) && (pcVar3 == (char *)0x0)) && (pcVar4 == (char *)0x0)) {
          sVar5 = strlen(recv_buffer);
          if ((uint)remain_data_len < sVar5) {
            memset(scan_code_data,0,0x100);
            scan_data_offset = 0;
          }
          strcpy(scan_code_data + scan_data_offset,recv_buffer);
        }
        else {
          if (pcVar2 == (char *)0x0) {
            if (pcVar4 == (char *)0x0) {
              *pcVar3 = '\0';
              terminal_position = pcVar3 + 1;
            }
            else {
              *pcVar4 = '\0';
              terminal_position = pcVar4 + 1;
            }
          }
          else {
            *pcVar2 = '\0';
            terminal_position = pcVar2 + 2;
          }
          sVar5 = strlen(recv_buffer);
          if (sVar5 <= (uint)remain_data_len) {
            strcpy(scan_code_data + scan_data_offset,recv_buffer);
            parse_scan_data(scan_code_data,sn,sn_ok,qrcode,qrcode_ok);
            if ((*sn_ok != false) && (*qrcode_ok != false)) break;
          }
          memset(scan_code_data,0,0x100);
          strcpy(scan_code_data,terminal_position);
        }
        scan_data_offset = strlen(scan_code_data);
        sVar5 = strlen(scan_code_data);
        remain_data_len = 0xff - sVar5;
      }
      usleep(5000);
      timeout = timeout + -5;
    } while (0 < timeout);
    if ((*sn_ok == false) || (*qrcode_ok == false)) {
      iVar1 = -1;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s can\'t detect scanner!!!.\n","scan_hashboard_info","scan_hashboard_info");
    snprintf(tmp1,0x100,"%s can\'t detect scanner!!!.","scan_hashboard_info");
    log_to_file(tmp1,time_stamp);
    iVar1 = -1;
  }
  return iVar1;
}

