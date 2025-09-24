
/* WARNING: Unknown calling convention */

int32_t reset_pic(uint8_t which_chain)

{
  uint uVar1;
  int32_t iVar2;
  char *__format;
  int32_t iVar3;
  uint32_t ctx;
  uint8_t read_back_data [2];
  uint8_t send_data [16];
  char tmp42 [2048];
  
  uVar1 = (uint)which_chain;
  if (0xf < uVar1) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","reset_pic",uVar1);
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar1].chain_has_opened == 0) &&
     (iVar2 = open_pic(which_chain), iVar2 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n","reset_pic",
             uVar1);
    _applog(0,tmp42,false);
    return iVar2;
  }
  ctx = g_bitmain_pic_state[uVar1].pic_fd;
  iVar3 = 0;
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '\a';
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
  send_data[5] = '\v';
  send_data[6] = '\0';
  send_data[7] = '\0';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  iVar2 = iic_write(ctx,send_data,6);
  if (iVar2 == 6) {
    usleep(300000);
    iVar2 = iic_read(ctx,read_back_data,2);
    if (iVar2 != 2) {
      __format = "%s read iic err\n";
      goto LAB_000c97d4;
    }
    if ((read_back_data[0] == '\a') && (read_back_data[1] == '\x01')) goto LAB_000c977e;
  }
  else {
    __format = "%s write iic err\n";
LAB_000c97d4:
    snprintf(tmp42,0x800,__format,"_bitmain_pic_reset_common");
    _applog(0,tmp42,false);
  }
  iVar3 = -0x7ffffe00;
LAB_000c977e:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  usleep(500000);
  return iVar3;
}

