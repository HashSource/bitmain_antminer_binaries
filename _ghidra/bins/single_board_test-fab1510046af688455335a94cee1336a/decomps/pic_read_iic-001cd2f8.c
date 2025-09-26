
/* WARNING: Unknown calling convention */

int32_t pic_read_iic(uint8_t which_chain,uint8_t slave,uint8_t reg,uint8_t *data,int32_t max_size)

{
  int32_t iVar1;
  char *__format;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint32_t uVar5;
  uint uVar6;
  uint32_t size;
  uchar send_data [8];
  uchar read_back_data [22];
  char tmp42 [2048];
  
  uVar2 = (uint)which_chain;
  if (0xf < uVar2) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","pic_read_iic",uVar2);
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar2].chain_has_opened == 0) &&
     (iVar1 = open_pic(which_chain), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n","pic_read_iic",
             uVar2);
LAB_001cd480:
    _applog(0,tmp42,false);
    return iVar1;
  }
  uVar4 = 0;
  iVar1 = _pic_write_iic(g_bitmain_pic_state[uVar2].pic_fd,slave,reg,(uint8_t *)0x0,0);
  if (iVar1 < 0) {
    snprintf(tmp42,0x800,"%s: select slave: 0x%02x, reg/command: 0x%02x is failed","pic_read_iic",
             (uint)slave,(uint)reg);
    goto LAB_001cd480;
  }
  if (0xf < max_size) {
    max_size = 0x10;
  }
  usleep(10000);
  uVar5 = g_bitmain_pic_state[uVar2].pic_fd;
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  uVar2 = max_size + 0x42U + (uint)slave & 0xffff;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[7] = (uchar)uVar2;
  send_data[2] = '\x06';
  send_data[6] = (uchar)(uVar2 >> 8);
  send_data[5] = (uchar)max_size;
  send_data[3] = '<';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0xc] = '\0';
  read_back_data[0xd] = '\0';
  read_back_data[0xe] = '\0';
  read_back_data[0xf] = '\0';
  read_back_data[0x10] = '\0';
  read_back_data[0x11] = '\0';
  read_back_data[0x12] = '\0';
  read_back_data[0x13] = '\0';
  read_back_data[0x14] = '\0';
  read_back_data[0x15] = '\0';
  send_data[4] = slave;
  iVar1 = iic_write(uVar5,send_data,8);
  if (iVar1 == 8) {
    size = max_size + 5;
    usleep(10000);
    uVar5 = iic_read(uVar5,read_back_data,size);
    if (size == uVar5) {
      uVar3 = read_back_data._0_4_ & 0xff;
      uVar6 = (uint)read_back_data._0_4_ >> 8 & 0xff;
      uVar2 = (uint)read_back_data._0_4_ >> 0x10 & 0xff;
      if (((size == uVar3) && (uVar6 == 0x3c)) && (uVar2 == 1)) {
        uVar2 = 0;
        if (0 < (int)(max_size + 3U)) {
          while( true ) {
            uVar4 = uVar4 + 1 & 0xffff;
            uVar2 = uVar2 + uVar3 & 0xffff;
            if ((int)(max_size + 3U) <= (int)uVar4) break;
            uVar3 = (uint)read_back_data[uVar4];
          }
          uVar4 = uVar2 >> 8;
        }
        if ((read_back_data[max_size + 3] == uVar4) &&
           ((uint)read_back_data[max_size + 4] == (uVar2 & 0xff))) {
          memcpy(data,read_back_data + 3,max_size);
        }
        else {
          snprintf(tmp42,0x800,"%s failed 2!\n","_pic_read_iic");
          max_size = 0;
          _applog(0,tmp42,false);
        }
      }
      else {
        max_size = 0;
        snprintf(tmp42,0x800,
                 "%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
                 ,"_pic_read_iic",uVar3,uVar6,uVar2);
        _applog(0,tmp42,false);
      }
      goto LAB_001cd3c8;
    }
    __format = "%s read iic err\n";
  }
  else {
    __format = "%s write iic err\n";
  }
  max_size = 0;
  snprintf(tmp42,0x800,__format,"_pic_read_iic");
  _applog(0,tmp42,false);
LAB_001cd3c8:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return max_size;
}

