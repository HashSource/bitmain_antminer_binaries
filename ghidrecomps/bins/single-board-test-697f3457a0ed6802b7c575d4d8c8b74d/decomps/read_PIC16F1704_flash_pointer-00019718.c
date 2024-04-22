
int read_PIC16F1704_flash_pointer
              (uint which_i2c,uchar which_chain,uchar *flash_addr_h,uchar *flash_addr_l)

{
  short sVar1;
  uchar uVar2;
  int iVar3;
  uchar *flash_addr_l_local;
  uchar *flash_addr_h_local;
  uchar which_chain_local;
  uint which_i2c_local;
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
  send_data[3] = '\b';
  send_data[4] = '\0';
  send_data[5] = '\f';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 6; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[1] == '\b') && (read_back_data[0] == '\x06')) {
    sVar1 = (ushort)read_back_data[3] + read_back_data[2] + 0xe;
    if (((uchar)((ushort)sVar1 >> 8) == read_back_data[4]) && ((uchar)sVar1 == read_back_data[5])) {
      *flash_addr_h = read_back_data[2];
      *flash_addr_l = read_back_data[3];
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok! flash_addr_h = 0x%02x, flash_addr_l = 0x%02x\n\n",
                 "read_PIC16F1704_flash_pointer",(uint)*flash_addr_h,(uint)*flash_addr_l);
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,
                 "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
                 ,"read_PIC16F1704_flash_pointer",read_back_data._0_4_ & 0xff,8,
                 (uint)read_back_data[2],(uint)read_back_data[3],(uint)read_back_data[4],
                 (uint)read_back_data[5]);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
               ,"read_PIC16F1704_flash_pointer",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],
               (uint)read_back_data[2],(uint)read_back_data[3],(uint)read_back_data[4],
               (uint)read_back_data[5]);
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}

