
int read_PIC16F1704_flash_data(uint which_i2c,uchar which_chain,uchar *buf)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  uchar *buf_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [20];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[11] = '\0';
  read_back_data[12] = '\0';
  read_back_data[13] = '\0';
  read_back_data[14] = '\0';
  read_back_data[15] = '\0';
  read_back_data[16] = '\0';
  read_back_data[17] = '\0';
  read_back_data[18] = '\0';
  read_back_data[19] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x03';
  send_data[4] = '\0';
  send_data[5] = '\a';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(300000);
  for (i = '\0'; i < 0x14; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, \t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x, \t\tread_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x, \t\tread_back_data[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n"
             ,"read_PIC16F1704_flash_data",read_back_data._0_4_ & 0xff,
             (uint)read_back_data._0_4_ >> 8 & 0xff,(uint)read_back_data._0_4_ >> 0x10 & 0xff,
             (uint)read_back_data._0_4_ >> 0x18,read_back_data._4_4_ & 0xff,
             (uint)read_back_data._4_4_ >> 8 & 0xff,(uint)read_back_data._4_4_ >> 0x10 & 0xff,
             (uint)read_back_data._4_4_ >> 0x18,read_back_data._8_4_ & 0xff,
             (uint)read_back_data._8_4_ >> 8 & 0xff,(uint)read_back_data._8_4_ >> 0x10 & 0xff,
             (uint)read_back_data._8_4_ >> 0x18,read_back_data._12_4_ & 0xff,
             (uint)read_back_data._12_4_ >> 8 & 0xff,(uint)read_back_data._12_4_ >> 0x10 & 0xff,
             (uint)read_back_data._12_4_ >> 0x18,read_back_data._16_4_ & 0xff,
             (uint)read_back_data._16_4_ >> 8 & 0xff,(uint)read_back_data._16_4_ >> 0x10 & 0xff,
             (uint)read_back_data._16_4_ >> 0x18);
    _applog(2,tmp42,false);
  }
  usleep(100000);
  if ((read_back_data[1] == '\x03') && (read_back_data[0] == '\x14')) {
    uVar1 = (ushort)read_back_data[17] +
            (ushort)read_back_data[16] +
            (ushort)read_back_data[15] +
            (ushort)read_back_data[14] +
            (ushort)read_back_data[13] +
            (ushort)read_back_data[12] +
            (ushort)read_back_data[11] +
            (ushort)read_back_data[10] +
            (ushort)read_back_data[9] +
            (ushort)read_back_data[8] +
            (ushort)read_back_data[7] +
            (ushort)read_back_data[6] +
            (ushort)read_back_data[5] +
            (ushort)read_back_data[4] + (ushort)read_back_data[3] + read_back_data[2] + 0x17;
    if (((uchar)(uVar1 >> 8) == read_back_data[18]) && ((uchar)uVar1 == read_back_data[19])) {
      for (i = '\0'; i < 0x10; i = i + '\x01') {
        buf[i] = read_back_data[i + 2];
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok\n\n","read_PIC16F1704_flash_data");
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","read_PIC16F1704_flash_data",
                 (uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","read_PIC16F1704_flash_data");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}

