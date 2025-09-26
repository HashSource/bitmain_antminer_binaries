
/* WARNING: Unknown calling convention */

int32_t _pic_write_iic(int32_t fd,uint8_t slave,uint8_t reg,uint8_t *data,int32_t size)

{
  byte bVar1;
  uint uVar2;
  uint32_t uVar3;
  int32_t iVar4;
  uint uVar5;
  char *__format;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uchar read_back_data [2];
  uchar send_data [24];
  char tmp42 [2048];
  
  uVar7 = size + 6;
  if (0xf < size) {
    size = 0x10;
  }
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  uVar8 = reg + 0x3b + (uint)slave + (uVar7 & 0xff);
  uVar6 = (undefined2)uVar8;
  send_data[2] = (uchar)uVar7;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = ';';
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
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  if (size < 1) {
    uVar8 = 8;
    uVar7 = 7;
    uVar5 = 6;
  }
  else {
    uVar7 = 0;
    uVar5 = 6;
    do {
      uVar2 = uVar5;
      bVar1 = data[uVar7];
      uVar7 = uVar7 + 1 & 0xffff;
      uVar5 = uVar2 + 1 & 0xffff;
      send_data[uVar2] = bVar1;
      uVar9 = uVar8 + bVar1;
      uVar8 = uVar9 & 0xffff;
      uVar6 = (undefined2)uVar9;
    } while ((int)uVar7 < size);
    uVar8 = uVar2 + 3 & 0xffff;
    uVar7 = uVar2 + 2 & 0xffff;
  }
  send_data[uVar5] = (uchar)((ushort)uVar6 >> 8);
  send_data[uVar7] = (uchar)uVar6;
  uVar3 = iic_write(fd,send_data,uVar8);
  if (uVar3 == uVar8) {
    usleep(10000);
    iVar4 = iic_read(fd,read_back_data,2);
    if (iVar4 == 2) {
      if ((read_back_data[0] != 0x3b) || (read_back_data[1] != 1)) {
        snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n"
                 ,"_pic_write_iic",(uint)read_back_data[0],(uint)read_back_data[1]);
        size = -0x7ffffe00;
        _applog(0,tmp42,false);
      }
      goto LAB_001c9376;
    }
    __format = "%s read iic err\n";
  }
  else {
    __format = "%s write iic err\n";
  }
  snprintf(tmp42,0x800,__format,"_pic_write_iic");
  size = -0x7ffffe00;
  _applog(0,tmp42,false);
LAB_001c9376:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return size;
}

