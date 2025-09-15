
int get_PIC16F1704_software_version(uint which_i2c,uchar which_chain,uchar *version)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  uchar *version_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [5];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x17';
  send_data[4] = '\0';
  send_data[5] = '\x1b';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n"
             ,"get_PIC16F1704_software_version",read_back_data._0_4_ & 0xff,
             (uint)read_back_data._0_4_ >> 8 & 0xff,(uint)read_back_data._0_4_ >> 0x10 & 0xff,
             (uint)read_back_data._0_4_ >> 0x18,(uint)read_back_data[4]);
    _applog(2,tmp42,false);
  }
  if ((read_back_data[1] == '\x17') && (read_back_data[0] == '\x05')) {
    uVar1 = read_back_data[2] + 0x1c;
    if (((uchar)(uVar1 >> 8) == read_back_data[3]) && ((uchar)uVar1 == read_back_data[4])) {
      *version = read_back_data[2];
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok, version = 0x%02x\n\n","get_PIC16F1704_software_version",
                 (uint)*version);
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_software_version",
                 (uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","get_PIC16F1704_software_version");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}

