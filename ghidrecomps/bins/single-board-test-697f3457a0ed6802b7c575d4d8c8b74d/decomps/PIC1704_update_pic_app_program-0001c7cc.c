
int PIC1704_update_pic_app_program(uint which_i2c,uchar which_chain)

{
  FILE *__stream;
  ulong uVar1;
  int iVar2;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar buf [16];
  char data_read [5];
  uchar program_data [5000];
  FILE *pic_program_file;
  int ret;
  uint pic_flash_length;
  uchar end_addr_l;
  uchar end_addr_h;
  uchar start_addr_l;
  uchar start_addr_h;
  uint data_int;
  uint i;
  
  memset(program_data,0,5000);
  data_read[0] = '\0';
  data_read[1] = '\0';
  data_read[2] = '\0';
  data_read[3] = '\0';
  data_read[4] = '\0';
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  buf[10] = '\0';
  buf[0xb] = '\0';
  buf[0xc] = '\0';
  buf[0xd] = '\0';
  buf[0xe] = '\0';
  buf[0xf] = '\0';
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"--- update pic program\n",0x18);
    _applog(2,tmp42,false);
  }
  __stream = fopen("/mnt/card/pic16f1704_app.txt","r");
  if (__stream == (FILE *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: open pic16f1704_app.txt failed\n","PIC1704_update_pic_app_program");
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  else {
    fseek(__stream,0,0);
    memset(program_data,0,5000);
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"pic_flash_length = %d\n",0x980);
      _applog(2,tmp42,false);
    }
    for (i = 0; i < 0x980; i = i + 1) {
      fgets(data_read,0x3ff,__stream);
      uVar1 = strtoul(data_read,(char **)0x0,0x10);
      program_data[i * 2] = (uchar)(uVar1 >> 8);
      program_data[i * 2 + 1] = (uchar)uVar1;
    }
    fclose(__stream);
    iVar2 = reset_PIC16F1704_pic(which_i2c,which_chain);
    if (iVar2 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
        _applog(2,tmp42,false);
      }
      iVar2 = 0;
    }
    else {
      iVar2 = erase_PIC16F1704_app_flash(which_i2c,which_chain);
      if (iVar2 == 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"!!! %s: erase flash error!\n\n","PIC1704_update_pic_app_program");
          _applog(2,tmp42,false);
        }
        iVar2 = 0;
      }
      else {
        iVar2 = set_PIC16F1704_flash_pointer(which_i2c,which_chain,'\x06','\0');
        if (iVar2 == 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            snprintf(tmp42,0x400,"!!! %s: set flash pointer error!\n\n",
                     "PIC1704_update_pic_app_program");
            _applog(2,tmp42,false);
          }
          iVar2 = 0;
        }
        else {
          for (i = 0; i < 0x130; i = i + 1) {
            iVar2 = i * 0x10;
            buf._0_4_ = *(undefined4 *)(program_data + iVar2);
            buf._4_4_ = *(undefined4 *)(program_data + iVar2 + 4);
            buf._8_4_ = *(undefined4 *)(program_data + iVar2 + 8);
            buf._12_4_ = *(undefined4 *)(program_data + iVar2 + 0xc);
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"send pic program time: %d\n",i);
              _applog(2,tmp42,false);
            }
            send_data_to_PIC16F1704(which_i2c,which_chain,buf);
            write_data_into_PIC16F1704_flash(which_i2c,which_chain);
          }
          iVar2 = reset_PIC16F1704_pic(which_i2c,which_chain);
          if (iVar2 == 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
              _applog(2,tmp42,false);
            }
            iVar2 = 0;
          }
          else {
            iVar2 = 1;
          }
        }
      }
    }
  }
  return iVar2;
}

