
int write_PIC16F1705_iic_slave(uint which_i2c,uchar which_chain,uchar *buf,uchar buf_len)

{
  byte bVar1;
  uchar uVar2;
  byte bVar3;
  int iVar4;
  uchar *buf_local;
  uchar buf_len_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [100];
  uchar read_back_data [5];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  bVar3 = buf_len + 4;
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  memset(send_data,0,100);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","write_PIC16F1705_iic_slave");
    _applog(2,tmp42,false);
  }
  crc = bVar3 + 0x26;
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    crc = crc + buf[i];
  }
  bVar1 = (byte)(crc >> 8);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
             "write_PIC16F1705_iic_slave",(uint)bVar1,(uint)(byte)crc);
    _applog(2,tmp42,false);
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '&';
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[buf_len + 4] = bVar1;
  send_data[buf_len + 5] = (byte)crc;
  send_data[2] = bVar3;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (uint)i < bVar3 + 2; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[1] == '&') && (read_back_data[2] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","write_PIC16F1705_iic_slave");
      _applog(2,tmp42,false);
    }
    iVar4 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x, read_back_data[4] = 0x%02x\n\n"
               ,"write_PIC16F1705_iic_slave",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],
               (uint)read_back_data[2],(uint)read_back_data._0_4_ >> 0x18,(uint)read_back_data[4]);
      _applog(2,tmp42,false);
    }
    iVar4 = 0;
  }
  return iVar4;
}

