
int send_data_to_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  uchar uVar1;
  int iVar2;
  uchar *buf_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [22];
  uchar read_back_data [2];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  send_data[0xc] = '\0';
  send_data[0xd] = '\0';
  send_data[0xe] = '\0';
  send_data[0xf] = '\0';
  send_data[0x10] = '\0';
  send_data[0x11] = '\0';
  send_data[0x12] = '\0';
  send_data[0x13] = '\0';
  crc = 0x16;
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    crc = crc + buf[i];
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x14';
  send_data[3] = '\x02';
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[0x15] = (uchar)crc;
  send_data[0x14] = (uchar)(crc >> 8);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 0x16; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[0] == '\x02') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","send_data_to_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "send_data_to_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}

