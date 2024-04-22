
int read_PIC16F1705_iic_slave
              (uint which_i2c,uchar which_chain,uchar *buf,uchar buf_len,uchar *read_back_buf)

{
  uchar uVar1;
  byte bVar2;
  int iVar3;
  uchar *buf_local;
  uchar buf_len_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [100];
  uchar read_back_data [100];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  bVar2 = buf_len + 4;
  memset(read_back_data,0,100);
  read_back_data[0] = 0xff;
  memset(send_data,0,100);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","read_PIC16F1705_iic_slave");
    _applog(2,tmp42,false);
  }
  crc = bVar2 + 0x26;
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    crc = crc + buf[i];
  }
  crc_data[0] = (uchar)(crc >> 8);
  crc_data[1] = (byte)crc;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
             "read_PIC16F1705_iic_slave",(uint)crc_data[0],(uint)(byte)crc);
    _applog(2,tmp42,false);
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '&';
  length = bVar2;
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[buf_len + 4] = crc_data[0];
  send_data[buf_len + 5] = crc_data[1];
  send_data[2] = bVar2;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (uint)i < length + 2; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; (uint)i < buf[2] + 3; i = i + '\x01') {
    uVar1 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[1] == '&') && (read_back_data[2] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","read_PIC16F1705_iic_slave");
      _applog(2,tmp42,false);
    }
    iVar3 = 1;
  }
  else {
    for (i = '\0'; (uint)i < buf[2] + 3; i = i + '\x01') {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! read_back_data[%d] = 0x%02x\n\n",
                 "read_PIC16F1705_iic_slave",(uint)i,(uint)read_back_data[i]);
        _applog(2,tmp42,false);
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}

