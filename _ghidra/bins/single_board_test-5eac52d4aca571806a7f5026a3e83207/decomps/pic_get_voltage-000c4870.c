
/* WARNING: Unknown calling convention */

int32_t pic_get_voltage(uint8_t which_chain,int32_t *an,int32_t size)

{
  int32_t iVar1;
  char *pcVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  char *pcVar6;
  uint32_t uVar7;
  uchar send_data [6];
  uchar read_back_data [7];
  byte local_824;
  byte local_823;
  byte local_822;
  char tmp42 [2048];
  
  uVar3 = (uint)which_chain;
  if (0xf < uVar3) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","pic_get_voltage",uVar3);
LAB_000c4aec:
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar3].chain_has_opened == 0) &&
     (iVar1 = open_pic(which_chain), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "pic_get_voltage",uVar3);
    _applog(0,tmp42,false);
    return iVar1;
  }
  if (size == 3) {
    pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
    uVar7 = g_bitmain_pic_state[uVar3].pic_fd;
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = '7';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    send_data[4] = '\0';
    send_data[5] = ';';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    local_824 = 0;
    local_823 = 0;
    local_822 = 0;
    iVar1 = iic_write(uVar7,send_data,6);
    if (iVar1 != 6) {
      pcVar2 = "%s write iic err\n";
LAB_000c4b0a:
      pcVar6 = "_read_an_voltage";
      goto LAB_000c4ac4;
    }
    usleep(10000);
    iVar1 = iic_read(uVar7,read_back_data,0xb);
    if (iVar1 != 0xb) {
      pcVar2 = "%s read iic err\n";
      goto LAB_000c4b0a;
    }
    if ((read_back_data[0] == 0xb) && (read_back_data[1] == 0x37)) {
      uVar5 = 0;
      pbVar4 = read_back_data;
      uVar3 = 0xb;
      while( true ) {
        uVar3 = uVar5 + uVar3;
        uVar5 = uVar3 & 0xffff;
        if (&local_824 == pbVar4) break;
        pbVar4 = pbVar4 + 1;
        uVar3 = (uint)*pbVar4;
      }
      if (((uint)local_823 == uVar5 >> 8) && ((uint)local_822 == (uVar3 & 0xff))) {
        iVar1 = 0xb;
        *an = (uint)CONCAT11(read_back_data[3],read_back_data[4]);
        an[1] = (uint)CONCAT11(read_back_data[5],read_back_data[6]);
        an[2] = (uint)local_824;
        goto LAB_000c4958;
      }
      pcVar2 = "_read_an_voltage";
LAB_000c49a8:
      snprintf(tmp42,0x800,"%s failed 2!\n",pcVar2);
      _applog(0,tmp42,false);
    }
    else {
      snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "_read_an_voltage",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(0,tmp42,false);
    }
  }
  else {
    if (size != 1) {
      snprintf(tmp42,0x800,"%s failed: parameters error!\n","pic_get_voltage");
      goto LAB_000c4aec;
    }
    pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
    uVar7 = g_bitmain_pic_state[uVar3].pic_fd;
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = ':';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    send_data[4] = '\0';
    send_data[5] = '>';
    read_back_data[3] = '\0';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    iVar1 = iic_write(uVar7,send_data,6);
    if (iVar1 == 6) {
      usleep(10000);
      iVar1 = iic_read(uVar7,read_back_data,7);
      if (iVar1 == 7) {
        if (((read_back_data[0] == 7) && (read_back_data[1] == 0x3a)) && (read_back_data[2] == 1)) {
          uVar3 = (uint)read_back_data[3] + (uint)read_back_data[4] + 0x42;
          if ((uVar3 * 0x10000 >> 0x18 == (uint)read_back_data[5]) &&
             ((uint)read_back_data[6] == (uVar3 & 0xff))) {
            *an = (uint)CONCAT11(read_back_data[3],read_back_data[4]);
            iVar1 = 7;
            goto LAB_000c4958;
          }
          pcVar2 = "_read_an6_voltage";
          goto LAB_000c49a8;
        }
        snprintf(tmp42,0x800,
                 "%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
                 ,"_read_an6_voltage",(uint)read_back_data[0],(uint)read_back_data[1],
                 (uint)read_back_data[2]);
        _applog(0,tmp42,false);
        goto LAB_000c49ba;
      }
      pcVar2 = "%s read iic err\n";
    }
    else {
      pcVar2 = "%s write iic err\n";
    }
    pcVar6 = "_read_an6_voltage";
LAB_000c4ac4:
    snprintf(tmp42,0x800,pcVar2,pcVar6);
    _applog(0,tmp42,false);
  }
LAB_000c49ba:
  iVar1 = -1;
LAB_000c4958:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return iVar1;
}

