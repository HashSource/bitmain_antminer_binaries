
/* WARNING: Unknown calling convention */

int32_t app_read_data_from_flash
                  (uint8_t which_chain,uint8_t flash_add_h,uint8_t flash_add_l,uint8_t *data,
                  int32_t size)

{
  byte *pbVar1;
  byte *name;
  int32_t iVar2;
  void *pvVar3;
  char *__format;
  int size_00;
  int size_01;
  uint uVar4;
  size_t __n;
  uint uVar5;
  void *p;
  uint32_t ctx;
  uint8_t send_data [9];
  char tmp42 [2048];
  
  uVar5 = (uint)which_chain;
  if (0xf < uVar5) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","app_read_data_from_flash",uVar5);
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar5].chain_has_opened == 0) &&
     (iVar2 = open_pic(which_chain), iVar2 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "app_read_data_from_flash",uVar5);
    _applog(0,tmp42,false);
    return iVar2;
  }
  ctx = g_bitmain_pic_state[uVar5].pic_fd;
  uVar5 = 0;
  p = (void *)(size + 5);
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  __n = size;
  if (0xf < size) {
    __n = 0x10;
  }
  name = (byte *)malloc((size_t)p);
  uVar4 = (uint)flash_add_h + __n + 0x3d + (uint)flash_add_l & 0xffff;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\a';
  send_data[3] = '6';
  send_data[5] = flash_add_l;
  send_data[4] = flash_add_h;
  send_data[6] = (uint8_t)__n;
  send_data[8] = (uint8_t)uVar4;
  send_data[7] = (uint8_t)(uVar4 >> 8);
  iVar2 = iic_write(ctx,send_data,9);
  if (iVar2 == 9) {
    usleep(300000);
    pvVar3 = (void *)iic_read(ctx,name,(uint32_t)p);
    if (p == pvVar3) {
      if (((name[1] == 0x36) && (name[2] == 1)) && (p == (void *)(uint)*name)) {
        uVar4 = uVar5;
        if (size + 3 < 1) {
          uVar5 = 0;
          uVar4 = uVar5;
        }
        else {
          do {
            pbVar1 = name + uVar5;
            uVar5 = uVar5 + 1 & 0xffff;
            uVar4 = uVar4 + *pbVar1 & 0xffff;
          } while ((int)uVar5 < size + 3);
          uVar5 = uVar4 >> 8;
        }
        if (((name + (int)p)[-2] == uVar5) && ((uint)(name + (int)p)[-1] == (uVar4 & 0xff))) {
          memcpy(data,name + 3,__n);
        }
        else {
          snprintf(tmp42,0x800,"%s failed 2!\n","_app_read_data_from_flash_1704_v8");
          __n = 0;
          _applog(0,tmp42,false);
          hexdump((char *)name,p,size_01);
        }
      }
      else {
        __n = 0;
        snprintf(tmp42,0x800,
                 "%s failed !\n read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x\n"
                 ,"_app_read_data_from_flash_1704_v8",(void *)(uint)*name,(uint)name[1],
                 (uint)name[2]);
        _applog(0,tmp42,false);
        hexdump((char *)name,p,size_00);
      }
      goto LAB_000c53b6;
    }
    __format = "%s read iic 2 err\n";
  }
  else {
    __format = "%s write iic 2 err\n";
  }
  __n = 0;
  snprintf(tmp42,0x800,__format,"_app_read_data_from_flash_1704_v8");
  _applog(0,tmp42,false);
LAB_000c53b6:
  free(name);
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return __n;
}

