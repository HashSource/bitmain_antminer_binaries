
int get_PIC16F1704_freq(uint which_chain,uchar which_i2c,ushort *freq)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  ushort *freq_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [6];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '%';
  send_data[4] = '\0';
  send_data[5] = ')';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(300000);
  for (i = '\0'; i < 6; i = i + '\x01') {
    uVar2 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
             ,"get_PIC16F1704_freq",read_back_data._0_4_ & 0xff,
             (uint)read_back_data._0_4_ >> 8 & 0xff,(uint)read_back_data._0_4_ >> 0x10 & 0xff,
             (uint)read_back_data._0_4_ >> 0x18,(uint)read_back_data[4],(uint)read_back_data[5]);
    _applog(2,tmp42,false);
  }
  if ((read_back_data[1] == '%') && (read_back_data[0] == '\x06')) {
    uVar1 = (ushort)read_back_data[3] + read_back_data[2] + 0x2b;
    if (((uchar)(uVar1 >> 8) == read_back_data[4]) && ((uchar)uVar1 == read_back_data[5])) {
      *freq = CONCAT11(read_back_data[2],read_back_data[3]);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok, freq = %d\n\n","get_PIC16F1704_freq",(uint)*freq);
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_freq",(uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","get_PIC16F1704_freq");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}

