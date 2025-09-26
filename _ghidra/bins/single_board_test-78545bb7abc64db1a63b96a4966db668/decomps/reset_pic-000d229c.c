
/* WARNING: Unknown calling convention */

int32_t reset_pic(uint8_t which_chain)

{
  int32_t iVar1;
  uint uVar2;
  char *__format;
  int iVar3;
  int iVar4;
  uint32_t ctx;
  byte *pbVar5;
  uint8_t read_back_data [5];
  uint8_t send_data [16];
  char tmp42 [2048];
  
  uVar2 = (uint)which_chain;
  if (0xf < uVar2) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","reset_pic",uVar2);
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar2].chain_has_opened == 0) &&
     (iVar1 = open_pic(which_chain), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n","reset_pic",
             uVar2);
    _applog(0,tmp42,false);
    return iVar1;
  }
  ctx = g_bitmain_pic_state[uVar2].pic_fd;
  iVar3 = 0;
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
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
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  read_back_data[4] = '\0';
  send_data[0] = 'U';
  send_data[3] = '\a';
  send_data[4] = '\0';
  send_data[5] = '\v';
  send_data[6] = '\0';
  send_data[7] = '\0';
  iVar1 = iic_write(ctx,send_data,6);
  if (iVar1 == 6) {
    usleep(300000);
    iVar1 = iic_read(ctx,read_back_data,5);
    pbVar5 = read_back_data;
    if (iVar1 != 5) {
      __format = "%s read iic err\n";
      goto LAB_000d23ec;
    }
    do {
      iVar4 = iVar3 + 1;
      printf("data[%d]:%2x  ",iVar3,(uint)*pbVar5);
      iVar3 = iVar4;
      pbVar5 = pbVar5 + 1;
    } while (iVar4 != 5);
    putchar(10);
    uVar2 = (uint)read_back_data._0_4_ >> 8 & 0xff;
    if ((((read_back_data._0_4_ & 0xff) == 5) && (uVar2 == 7)) && (read_back_data[2] == 0xfe)) {
      iVar1 = 0;
      goto LAB_000d236a;
    }
    snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
             "_bitmain_pic_reset_common",read_back_data._0_4_ & 0xff,uVar2);
    _applog(3,tmp42,false);
  }
  else {
    __format = "%s write iic err\n";
LAB_000d23ec:
    snprintf(tmp42,0x800,__format,"_bitmain_pic_reset_common");
    _applog(0,tmp42,false);
  }
  iVar1 = -0x7ffffe00;
LAB_000d236a:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  usleep(500000);
  return iVar1;
}

