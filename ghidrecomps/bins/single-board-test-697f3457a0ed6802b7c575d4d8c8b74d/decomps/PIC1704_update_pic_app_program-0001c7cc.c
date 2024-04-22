
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
  buf[11] = '\0';
  buf[12] = '\0';
  buf[13] = '\0';
  buf[14] = '\0';
  buf[15] = '\0';
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    tmp42[0] = s_____update_pic_program_00035998[0];
    tmp42[1] = s_____update_pic_program_00035998[1];
    tmp42[2] = s_____update_pic_program_00035998[2];
    tmp42[3] = s_____update_pic_program_00035998[3];
    tmp42[4] = s_____update_pic_program_00035998[4];
    tmp42[5] = s_____update_pic_program_00035998[5];
    tmp42[6] = s_____update_pic_program_00035998[6];
    tmp42[7] = s_____update_pic_program_00035998[7];
    tmp42[8] = s_____update_pic_program_00035998[8];
    tmp42[9] = s_____update_pic_program_00035998[9];
    tmp42[10] = s_____update_pic_program_00035998[10];
    tmp42[11] = s_____update_pic_program_00035998[11];
    tmp42[12] = s_____update_pic_program_00035998[12];
    tmp42[13] = s_____update_pic_program_00035998[13];
    tmp42[14] = s_____update_pic_program_00035998[14];
    tmp42[15] = s_____update_pic_program_00035998[15];
    tmp42[16] = s_____update_pic_program_00035998[16];
    tmp42[17] = s_____update_pic_program_00035998[17];
    tmp42[18] = s_____update_pic_program_00035998[18];
    tmp42[19] = s_____update_pic_program_00035998[19];
    tmp42[20] = s_____update_pic_program_00035998[20];
    tmp42[21] = s_____update_pic_program_00035998[21];
    tmp42[22] = s_____update_pic_program_00035998[22];
    tmp42[23] = s_____update_pic_program_00035998[23];
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
    which_chain_local = which_chain;
    which_i2c_local = which_i2c;
    for (i = 0; i < 0x980; i = i + 1) {
      fgets(data_read,0x3ff,__stream);
      uVar1 = strtoul(data_read,(char **)0x0,0x10);
      program_data[i * 2] = (uchar)(uVar1 >> 8);
      program_data[i * 2 + 1] = (uchar)uVar1;
    }
    fclose(__stream);
    iVar2 = reset_PIC16F1704_pic(which_i2c_local,which_chain_local);
    if (iVar2 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
        _applog(2,tmp42,false);
      }
      iVar2 = 0;
    }
    else {
      iVar2 = erase_PIC16F1704_app_flash(which_i2c_local,which_chain_local);
      if (iVar2 == 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"!!! %s: erase flash error!\n\n","PIC1704_update_pic_app_program");
          _applog(2,tmp42,false);
        }
        iVar2 = 0;
      }
      else {
        iVar2 = set_PIC16F1704_flash_pointer(which_i2c_local,which_chain_local,'\x06','\0');
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
            send_data_to_PIC16F1704(which_i2c_local,which_chain_local,buf);
            write_data_into_PIC16F1704_flash(which_i2c_local,which_chain_local);
          }
          iVar2 = reset_PIC16F1704_pic(which_i2c_local,which_chain_local);
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

