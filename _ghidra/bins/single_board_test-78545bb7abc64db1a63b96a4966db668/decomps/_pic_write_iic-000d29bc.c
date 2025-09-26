
/* WARNING: Unknown calling convention */

int32_t _pic_write_iic(int32_t fd,uint8_t slave,uint8_t reg,uint8_t *data,int32_t size)

{
  byte *pbVar1;
  uint32_t uVar2;
  int32_t iVar3;
  uint uVar4;
  char *__format;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uchar read_back_data [2];
  uchar send_data [24];
  char tmp42 [2048];
  
  uVar6 = size + 6;
  if (0xf < size) {
    size = 0x10;
  }
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  uVar7 = reg + 0x3b + (uint)slave + (uVar6 & 0xff);
  uVar5 = (undefined2)uVar7;
  send_data[2] = (uchar)uVar6;
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  send_data[0xc] = '\0';
  send_data[0xd] = '\0';
  send_data[0xe] = '\0';
  send_data[0xf] = '\0';
  send_data[0x10] = '\0';
  send_data[0x11] = '\0';
  send_data[0x12] = '\0';
  send_data[0x13] = '\0';
  send_data[0x14] = '\0';
  send_data[0x15] = '\0';
  send_data[0x16] = '\0';
  send_data[0x17] = '\0';
  send_data[5] = reg;
  send_data[4] = slave;
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = ';';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  if (size < 1) {
    uVar7 = 8;
    uVar4 = 7;
    uVar6 = 6;
  }
  else {
    uVar4 = 0;
    uVar6 = 6;
    do {
      pbVar1 = data + uVar4;
      uVar4 = uVar4 + 1 & 0xffff;
      uVar8 = uVar7 + *pbVar1;
      send_data[uVar6] = *pbVar1;
      uVar7 = uVar8 & 0xffff;
      uVar5 = (undefined2)uVar8;
      uVar6 = uVar6 + 1 & 0xffff;
    } while ((int)uVar4 < size);
    uVar7 = uVar6 + 2 & 0xffff;
    uVar4 = uVar6 + 1 & 0xffff;
  }
  send_data[uVar6] = (uchar)((ushort)uVar5 >> 8);
  send_data[uVar4] = (uchar)uVar5;
  uVar2 = iic_write(fd,send_data,uVar7);
  if (uVar2 == uVar7) {
    usleep(10000);
    iVar3 = iic_read(fd,read_back_data,2);
    if (iVar3 == 2) {
      if ((read_back_data[0] != 0x3b) || (read_back_data[1] != 1)) {
        snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n"
                 ,"_pic_write_iic",(uint)read_back_data[0],(uint)read_back_data[1]);
        size = -0x7ffffe00;
        _applog(0,tmp42,false);
      }
      goto LAB_000d2a94;
    }
    __format = "%s read iic err\n";
  }
  else {
    __format = "%s write iic err\n";
  }
  snprintf(tmp42,0x800,__format,"_pic_write_iic");
  size = -0x7ffffe00;
  _applog(0,tmp42,false);
LAB_000d2a94:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return size;
}

