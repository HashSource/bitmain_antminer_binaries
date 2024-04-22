
int set_PIC16F1704_voltage(uint which_chain,uchar which_i2c,uchar voltage)

{
  uchar uVar1;
  int iVar2;
  uchar voltage_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [7];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[5] = (uchar)((ushort)(voltage + 0x15) >> 8);
  send_data[6] = (uchar)(voltage + 0x15);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x05';
  send_data[3] = '\x10';
  send_data[4] = voltage;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 7; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '\x10') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","set_PIC16F1704_voltage");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "set_PIC16F1704_voltage",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}

