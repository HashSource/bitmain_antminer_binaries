
int PIC16F1704_i2c_forward_send
              (uint32_t i2c,uint8_t chain,uint8_t dev_addr,int rw_flag,uint8_t reg_addr,int len,
              uint8_t *data)

{
  uchar uVar1;
  int rw_flag_local;
  uint8_t dev_addr_local;
  uint8_t chain_local;
  uint32_t i2c_local;
  char tmp42 [1024];
  uint8_t recv_data [12];
  uint8_t send_data [32];
  int i_2;
  int i_1;
  int i;
  int body_len;
  uint16_t crc;
  
  memset(send_data,0,0x20);
  recv_data[0] = '\0';
  recv_data[1] = '\0';
  recv_data[2] = '\0';
  recv_data[3] = '\0';
  recv_data[4] = '\0';
  recv_data[5] = '\0';
  recv_data[6] = '\0';
  recv_data[7] = '\0';
  recv_data[8] = '\0';
  recv_data[9] = '\0';
  recv_data[10] = '\0';
  recv_data[11] = '\0';
  crc = 0;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\0';
  send_data[3] = '&';
  send_data[4] = (byte)rw_flag | dev_addr << 1;
  send_data[5] = reg_addr;
  if (rw_flag == 0) {
    body_len = len + 4;
    memcpy(send_data + 6,data,len);
  }
  else {
    body_len = 5;
    send_data[6] = (uint8_t)len;
  }
  send_data[2] = (char)body_len + '\x02';
  for (i_1 = 0; i_1 < body_len; i_1 = i_1 + 1) {
    crc = crc + send_data[i_1 + 2];
  }
  send_data[body_len + 2] = (uint8_t)(crc >> 8);
  send_data[body_len + 3] = (uint8_t)crc;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = 0; i < body_len + 4; i = i + 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"write pic i2c[%d] %02x\n",i,(uint)send_data[i]);
      _applog(2,tmp42,false);
    }
    write_pic((uchar)i2c,chain,send_data[i]);
  }
  usleep(200000);
  if (rw_flag == 1) {
    for (i = 0; i < len + 5; i = i + 1) {
      uVar1 = read_pic((uchar)i2c,chain);
      recv_data[i] = uVar1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"read pic i2c[%d] %02x\n",i,(uint)recv_data[i]);
        _applog(2,tmp42,false);
      }
    }
    for (i_2 = 0; i_2 < len + 3; i_2 = i_2 + 1) {
      crc = crc + recv_data[i_2];
    }
    if (crc != *(uint16_t *)(recv_data + len + 3)) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"crc failed 0x%x\n",(uint)crc);
        _applog(2,tmp42,false);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return -1;
    }
    if ((((recv_data._0_4_ & 0xff) != body_len + 2U) || (recv_data[1] != '&')) ||
       (recv_data[2] != '\x01')) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"pic read failed %d %d %d\n",(uint)*data,(uint)data[1],(uint)data[2]);
        _applog(2,tmp42,false);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return -1;
    }
    memcpy(data,recv_data + 3,len);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  return 0;
}

