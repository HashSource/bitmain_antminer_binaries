
/* WARNING: Unknown calling convention */

int32_t get_pic_version(uint8_t which_chain)

{
  int32_t iVar1;
  char *pcVar2;
  int size;
  uint uVar3;
  uint32_t ctx;
  uint8_t read_back_data [5];
  uint8_t send_data [16];
  char tmp42 [2048];
  
  uVar3 = (uint)which_chain;
  if (0xf < uVar3) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","get_pic_version",uVar3);
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar3].chain_has_opened == 0) &&
     (iVar1 = open_pic(which_chain), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "get_pic_version",uVar3);
    _applog(0,tmp42,false);
    return iVar1;
  }
  ctx = g_bitmain_pic_state[uVar3].pic_fd;
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '\x17';
  send_data[2] = '\x04';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  send_data[0xc] = '\0';
  send_data[0xd] = '\0';
  send_data[0xe] = '\0';
  send_data[0xf] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\x1b';
  send_data[6] = '\0';
  send_data[7] = '\0';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  read_back_data[4] = '\0';
  iVar1 = iic_write(ctx,send_data,6);
  if (iVar1 == 6) {
    usleep(300000);
    iVar1 = iic_read(ctx,read_back_data,5);
    if (iVar1 != 5) {
      pcVar2 = "%s read iic err\n";
      goto LAB_001c8b54;
    }
    if ((read_back_data[1] == '\x17') && (read_back_data[0] == '\x05')) {
      uVar3 = (uint)read_back_data._0_4_ >> 0x10 & 0xff;
      if (((uVar3 + 0x1c) * 0x10000 >> 0x18 == (uint)read_back_data._0_4_ >> 0x18) &&
         ((uint)read_back_data[4] == (uVar3 + 0x1c & 0xff))) goto LAB_001c8b0a;
      pcVar2 = "%s failed 2!\n";
    }
    else {
      pcVar2 = "%s failed!\n";
    }
    snprintf(tmp42,0x800,pcVar2,"_bitmain_pic_get_sw_ver_common");
    _applog(0,tmp42,false);
    hexdump((char *)read_back_data,&DAT_00000005,size);
  }
  else {
    pcVar2 = "%s write iic err\n";
LAB_001c8b54:
    snprintf(tmp42,0x800,pcVar2,"_bitmain_pic_get_sw_ver_common");
    _applog(0,tmp42,false);
  }
  uVar3 = 0x80000200;
LAB_001c8b0a:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return uVar3;
}

