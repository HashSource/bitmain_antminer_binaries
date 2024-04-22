
int write_data_to_PIC16F1704_flash(int which_chain,int which_i2c,uchar *buf,int buf_len)

{
  byte bVar1;
  uchar uVar2;
  int iVar3;
  int buf_len_local;
  uchar *buf_local;
  int which_i2c_local;
  int which_chain_local;
  char tmp42 [1024];
  uchar send_data [12];
  uchar read_back_data [5];
  uchar crc_data [2];
  int send_len;
  uchar length;
  uchar i;
  ushort crc;
  
  length = '\x06';
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[11] = '\0';
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (3 < opt_log_level)))) {
    snprintf(tmp42,0x400,"\n--- %s\n","write_data_to_PIC16F1704_flash");
    _applog(4,tmp42,false);
  }
  crc = (short)buf_len * 2 + 0x39;
  for (i = '\0'; (int)(uint)i < buf_len; i = i + '\x01') {
    crc = crc + buf[i];
  }
  bVar1 = (byte)(crc >> 8);
  crc_data[1] = (uchar)crc;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
             "write_data_to_PIC16F1704_flash",(uint)bVar1,(uint)crc_data[1]);
    _applog(2,tmp42,false);
  }
  send_data[2] = (char)buf_len + '\x06';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '3';
  send_data._4_4_ = (uint)CONCAT21(send_data._6_2_,(char)buf_len) << 8;
  memcpy(send_data + 6,buf,buf_len);
  send_data[buf_len + 6] = bVar1;
  send_data[buf_len + 7] = crc_data[1];
  for (i = '\0'; (int)(uint)i < buf_len + 8; i = i + '\x01') {
    printf("%02x ",(uint)send_data[i]);
  }
  putchar(10);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (int)(uint)i < (int)(buf_len + length + 2); i = i + '\x01') {
    write_pic((uchar)which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    printf("%02x ",(uint)read_back_data[i]);
  }
  putchar(10);
  if (((read_back_data[0] == '\x05') && (read_back_data[1] == '3')) && (read_back_data[2] == '\x01')
     ) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"\n--- %s ok\n\n","write_data_to_PIC16F1704_flash");
      _applog(2,tmp42,false);
    }
    iVar3 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
               ,"write_data_to_PIC16F1704_flash",read_back_data._0_4_ & 0xff,(uint)read_back_data[1]
               ,(uint)read_back_data[2]);
      _applog(0,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}

