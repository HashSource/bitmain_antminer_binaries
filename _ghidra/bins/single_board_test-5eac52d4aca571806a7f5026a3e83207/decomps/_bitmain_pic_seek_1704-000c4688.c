
int32_t _bitmain_pic_seek_1704(int32_t fd,uint32_t addr)

{
  int32_t iVar1;
  int32_t iVar2;
  uint8_t read_back_data [2];
  uint8_t send_data [16];
  char tmp42 [2048];
  
  iVar2 = 0;
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '\x01';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  send_data[0xc] = '\0';
  send_data[0xd] = '\0';
  send_data[0xe] = '\0';
  send_data[0xf] = '\0';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  send_data[2] = '\x06';
  send_data[4] = '\x06';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\r';
  iVar1 = iic_write(fd,send_data,8);
  if (iVar1 == 8) {
    usleep(300000);
    iVar1 = iic_read(fd,read_back_data,2);
    if (iVar1 == 2) {
      if ((read_back_data[0] == 1) && (read_back_data[1] == 1)) goto LAB_000c4702;
      snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "_bitmain_pic_seek_1704",(uint)read_back_data[0],(uint)read_back_data[1]);
    }
    else {
      snprintf(tmp42,0x800,"%s read iic err\n","_bitmain_pic_seek_1704");
    }
  }
  else {
    snprintf(tmp42,0x800,"%s write iic err\n","_bitmain_pic_seek_1704");
  }
  _applog(0,tmp42,false);
  iVar2 = -0x7ffffe00;
LAB_000c4702:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return iVar2;
}

