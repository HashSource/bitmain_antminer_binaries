
/* WARNING: Unknown calling convention */

int32_t app_write_data_into_flash
                  (uint8_t which_chain,uint8_t flash_add_h,uint8_t flash_add_l,uint8_t *data,
                  int32_t size)

{
  int32_t iVar1;
  char *__format;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  uint8_t *puVar7;
  uint32_t ctx;
  uint8_t read_back_data [2];
  uint8_t send_data [32];
  char tmp42 [2048];
  
  uVar3 = (uint)which_chain;
  if (0xf < uVar3) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","app_write_data_into_flash",uVar3)
    ;
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar3].chain_has_opened == 0) &&
     (iVar1 = open_pic(which_chain), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "app_write_data_into_flash",uVar3);
    _applog(0,tmp42,false);
    return iVar1;
  }
  uVar5 = size + 6;
  ctx = g_bitmain_pic_state[uVar3].pic_fd;
  if (0xf < size) {
    size = 0x10;
  }
  uVar3 = 0;
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  send_data[2] = (uint8_t)uVar5;
  uVar5 = (uVar5 & 0xff) + (uint)flash_add_l + 0x35 + (uint)flash_add_h;
  uVar4 = (undefined2)uVar5;
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
  send_data[0x18] = '\0';
  send_data[0x19] = '\0';
  send_data[0x1a] = '\0';
  send_data[0x1b] = '\0';
  send_data[0x1c] = '\0';
  send_data[0x1d] = '\0';
  send_data[0x1e] = '\0';
  send_data[0x1f] = '\0';
  send_data[5] = flash_add_l;
  send_data[4] = flash_add_h;
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '5';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  if (0 < size) {
    puVar7 = send_data + 5;
    do {
      uVar2 = (uint)*data;
      if (((uVar3 & 1) == 0) && (0x3f < uVar2)) {
        snprintf(tmp42,0x800,"%s: the data[%d] must less than 0x3f\n",
                 "_app_write_data_into_flash_1704_v8",uVar3);
        _applog(0,tmp42,false);
        uVar2 = (uint)*data;
      }
      uVar3 = uVar3 + 1;
      uVar6 = uVar5 + uVar2;
      uVar5 = uVar6 & 0xffff;
      uVar4 = (undefined2)uVar6;
      puVar7 = puVar7 + 1;
      *puVar7 = (uint8_t)uVar2;
      data = data + 1;
    } while (uVar3 != size);
  }
  uVar3 = size & 0xffff;
  uVar5 = uVar3 + 8 & 0xffff;
  send_data[uVar3 + 6 & 0xffff] = (uint8_t)((ushort)uVar4 >> 8);
  send_data[uVar3 + 7 & 0xffff] = (uint8_t)uVar4;
  uVar3 = iic_write(ctx,send_data,uVar5);
  if (uVar3 == uVar5) {
    usleep(300000);
    iVar1 = iic_read(ctx,read_back_data,2);
    if (iVar1 == 2) {
      if ((read_back_data[0] != 0x35) || (read_back_data[1] != 1)) {
        size = 0;
        snprintf(tmp42,0x800,
                 "%s failed 2! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
                 "_app_write_data_into_flash_1704_v8",(uint)read_back_data[0],
                 (uint)read_back_data[1]);
        _applog(0,tmp42,false);
      }
      goto LAB_000d3718;
    }
    __format = "%s read iic 2 err\n";
  }
  else {
    __format = "%s write iic 2 err\n";
  }
  snprintf(tmp42,0x800,__format,"_app_write_data_into_flash_1704_v8");
  size = 0;
  _applog(0,tmp42,false);
LAB_000d3718:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return size;
}

