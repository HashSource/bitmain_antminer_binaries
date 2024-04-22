
int write_hash_ID_PIC16F1704(uint which_chain,uchar which_i2c,uchar *buf)

{
  uchar uVar1;
  int iVar2;
  uchar *buf_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [18];
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
  send_data[11] = '\0';
  send_data[12] = '\0';
  send_data[13] = '\0';
  send_data[14] = '\0';
  send_data[15] = '\0';
  crc = 0x22;
  for (i = '\0'; i < 0xc; i = i + '\x01') {
    crc = crc + buf[i];
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x10';
  send_data[3] = '\x12';
  for (i = '\0'; i < 0xc; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[17] = (uchar)crc;
  send_data[16] = (uchar)(crc >> 8);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 0x12; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(400000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '\x12') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","write_hash_ID_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "write_hash_ID_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}

