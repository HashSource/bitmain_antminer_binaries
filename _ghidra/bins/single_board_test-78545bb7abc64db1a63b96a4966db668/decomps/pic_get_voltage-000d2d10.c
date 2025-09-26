
/* WARNING: Unknown calling convention */

int32_t pic_get_voltage(uint8_t which_chain,int32_t *an,int32_t size)

{
  int32_t iVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  byte *pbVar5;
  char *pcVar6;
  uint32_t uVar7;
  bool bVar8;
  uchar send_data [6];
  uchar read_back_data [7];
  undefined1 uStack_825;
  byte local_824 [4];
  char tmp42 [2048];
  
  uVar2 = (uint)which_chain;
  if (0xf < uVar2) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","pic_get_voltage",uVar2);
LAB_000d2d56:
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar2].chain_has_opened == 0) &&
     (iVar1 = open_pic(which_chain), iVar1 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "pic_get_voltage",uVar2);
    _applog(0,tmp42,false);
    return iVar1;
  }
  if (size == 3) {
    pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
    uVar7 = g_bitmain_pic_state[uVar2].pic_fd;
    send_data[2] = '\x04';
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[3] = '7';
    stack0xfffff7d8 = 0;
    local_824[2] = 0;
    send_data[4] = '\0';
    send_data[5] = ';';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    local_824[0] = 0;
    local_824[1] = 0;
    iVar1 = iic_write(uVar7,send_data,6);
    if (iVar1 != 6) {
      pcVar4 = "%s write iic err\n";
LAB_000d2fbe:
      pcVar6 = "_read_an_voltage";
      goto LAB_000d2f80;
    }
    usleep(10000);
    iVar1 = iic_read(uVar7,read_back_data,0xb);
    if (iVar1 != 0xb) {
      pcVar4 = "%s read iic err\n";
      goto LAB_000d2fbe;
    }
    uVar2 = (uint)read_back_data._0_4_ >> 8 & 0xff;
    if ((read_back_data._0_4_ & 0xff) == 0xb) {
      bVar8 = uVar2 == 0x37;
      if (bVar8) {
        uVar2 = 0;
      }
      pbVar5 = read_back_data;
      if (bVar8) {
        uVar3 = 0xb;
        while( true ) {
          uVar3 = uVar2 + uVar3;
          uVar2 = uVar3 & 0xffff;
          if (pbVar5 == local_824) break;
          pbVar5 = pbVar5 + 1;
          uVar3 = (uint)*pbVar5;
        }
        if (((uint)local_824[1] == uVar2 >> 8) && ((uint)local_824[2] == (uVar3 & 0xff))) {
          iVar1 = 0xb;
          *an = (uint)CONCAT11(read_back_data[3],read_back_data[4]);
          an[1] = (uint)CONCAT11(read_back_data[5],read_back_data[6]);
          an[2] = (uint)CONCAT11(uStack_825,local_824[0]);
          goto LAB_000d2e5e;
        }
        pcVar4 = "_read_an_voltage";
        goto LAB_000d2fa0;
      }
    }
    snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
             "_read_an_voltage",read_back_data._0_4_ & 0xff,uVar2);
    _applog(0,tmp42,false);
  }
  else {
    if (size != 1) {
      snprintf(tmp42,0x800,"%s failed: parameters error!\n","pic_get_voltage");
      goto LAB_000d2d56;
    }
    pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
    uVar7 = g_bitmain_pic_state[uVar2].pic_fd;
    send_data[0] = 'U';
    send_data[1] = 0xaa;
    send_data[2] = '\x04';
    send_data[3] = ':';
    stack0xfffff7d8 = stack0xfffff7d8 & 0xff000000;
    send_data[4] = '\0';
    send_data[5] = '>';
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    iVar1 = iic_write(uVar7,send_data,6);
    if (iVar1 == 6) {
      usleep(10000);
      iVar1 = iic_read(uVar7,read_back_data,7);
      if (iVar1 == 7) {
        uVar3 = (uint)read_back_data._0_4_ >> 8 & 0xff;
        uVar2 = (uint)read_back_data._0_4_ >> 0x10 & 0xff;
        if ((((read_back_data._0_4_ & 0xff) == 7) && (uVar3 == 0x3a)) && (uVar2 == 1)) {
          uVar2 = (uint)read_back_data[3] + (stack0xfffff7d8 & 0xff) + 0x42;
          if ((uVar2 * 0x10000 >> 0x18 == (stack0xfffff7d8 >> 8 & 0xff)) &&
             ((stack0xfffff7d8 >> 0x10 & 0xff) == (uVar2 & 0xff))) {
            *an = (uint)CONCAT11(read_back_data[3],read_back_data[4]);
            iVar1 = 7;
            goto LAB_000d2e5e;
          }
          pcVar4 = "_read_an6_voltage";
LAB_000d2fa0:
          snprintf(tmp42,0x800,"%s failed 2!\n",pcVar4);
          _applog(0,tmp42,false);
        }
        else {
          snprintf(tmp42,0x800,
                   "%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
                   ,"_read_an6_voltage",read_back_data._0_4_ & 0xff,uVar3,uVar2);
          _applog(0,tmp42,false);
        }
        goto LAB_000d2f6e;
      }
      pcVar4 = "%s read iic err\n";
    }
    else {
      pcVar4 = "%s write iic err\n";
    }
    pcVar6 = "_read_an6_voltage";
LAB_000d2f80:
    snprintf(tmp42,0x800,pcVar4,pcVar6);
    _applog(0,tmp42,false);
  }
LAB_000d2f6e:
  iVar1 = -1;
LAB_000d2e5e:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return iVar1;
}

