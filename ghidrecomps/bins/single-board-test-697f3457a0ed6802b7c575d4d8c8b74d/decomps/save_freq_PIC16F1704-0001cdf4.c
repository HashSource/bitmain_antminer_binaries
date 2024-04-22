
int save_freq_PIC16F1704(uint which_chain,uchar which_i2c,ushort freq)

{
  short sVar1;
  uchar uVar2;
  int iVar3;
  ushort freq_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [8];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  sVar1 = (freq & 0xff) + (freq >> 8) + 0x2a;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '$';
  send_data._4_2_ = CONCAT11((uchar)freq,(uchar)(freq >> 8));
  send_data._4_3_ = CONCAT12((uchar)((ushort)sVar1 >> 8),send_data._4_2_);
  send_data[7] = (uchar)sVar1;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 8; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(300000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar2 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '$') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","save_freq_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar3 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "save_freq_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}

