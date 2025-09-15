
int read_data_from_PIC16F1704_flash(int which_chain,int which_i2c,uchar *buf,uchar read_len)

{
  byte bVar1;
  byte bVar2;
  uchar uVar3;
  int iVar4;
  uchar read_len_local;
  uchar *buf_local;
  int which_i2c_local;
  int which_chain_local;
  char tmp42 [1024];
  uchar send_data [8];
  uchar read_back_data [40];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  memset(read_back_data,0,0x28);
  read_back_data[0] = 0xff;
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"\n--- %s\n","read_data_from_PIC16F1704_flash");
    _applog(2,tmp42,false);
  }
  bVar1 = (byte)((ushort)(read_len + 0x3a) >> 8);
  bVar2 = (byte)(read_len + 0x3a);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n",
             "read_data_from_PIC16F1704_flash",(uint)bVar1,(uint)bVar2);
    _applog(2,tmp42,false);
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '4';
  send_data._4_4_ = (uint)CONCAT12(bVar2,CONCAT11(bVar1,read_len)) << 8;
  for (i = '\0'; i < 8; i = i + '\x01') {
    printf("%02x ",(uint)send_data[i]);
  }
  putchar(10);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 8; i = i + '\x01') {
    write_pic((uchar)which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; (uint)i < read_len + 5; i = i + '\x01') {
    uVar3 = read_pic((uchar)which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar3;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  for (i = '\0'; (uint)i < read_len + 5; i = i + '\x01') {
    printf("%02x ",(uint)read_back_data[i]);
  }
  putchar(10);
  if (((read_back_data[1] == '4') && ((uint)read_back_data[0] == read_len + 5)) &&
     (read_back_data[2] == '\x01')) {
    crc = 0;
    for (i = '\0'; (uint)i < read_len + 3; i = i + '\x01') {
      crc = crc + read_back_data[i];
    }
    if (((uchar)(crc >> 8) == read_back_data[read_len + 3]) &&
       ((uchar)crc == read_back_data[read_len + 4])) {
      memcpy(buf,read_back_data + 3,(uint)read_len);
      if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"\n--- %s ok\n\n","read_data_from_PIC16F1704_flash");
        _applog(2,tmp42,false);
      }
      iVar4 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"\n--- %s failed! crc = 0x%04x\n\n","read_data_from_PIC16F1704_flash",
                 (uint)crc);
        _applog(0,tmp42,false);
      }
      iVar4 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
               ,"read_data_from_PIC16F1704_flash",(uint)read_back_data[0],(uint)read_back_data[1],
               (uint)read_back_data[2]);
      _applog(0,tmp42,false);
    }
    iVar4 = 0;
  }
  return iVar4;
}

