
/* WARNING: Unknown calling convention */

int32_t pic_get_voltage_v2(uint8_t which_chain,int32_t *an,int32_t size,int32_t ana_channel)

{
  uchar *puVar1;
  int iVar2;
  int32_t iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  byte *data;
  int iVar7;
  uint32_t uVar8;
  uchar send_data [7];
  uchar read_back_data [8];
  undefined4 local_82c;
  char tmp42 [2048];
  
  uVar4 = (uint)which_chain;
  if (0xf < uVar4) {
    snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","pic_get_voltage_v2",uVar4);
LAB_000c4bac:
    _applog(0,tmp42,false);
    return -0x7ffffdff;
  }
  if ((g_bitmain_pic_state[uVar4].chain_has_opened == 0) &&
     (iVar3 = open_pic(which_chain), iVar3 < 0)) {
    snprintf(tmp42,0x800,"%s: auto exec open_pic, but chain %d open eeprom failed\n",
             "pic_get_voltage_v2",uVar4);
    _applog(0,tmp42,false);
    return iVar3;
  }
  if (size != 3) {
    if (size != 1) {
      snprintf(tmp42,0x800,"%s failed: parameters error!\n","pic_get_voltage_v2");
      goto LAB_000c4bac;
    }
    pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
    read_back_data[0] = '\0';
    read_back_data[1] = '\0';
    read_back_data[2] = '\0';
    read_back_data[3] = '\0';
    read_back_data[4] = '\0';
    read_back_data[5] = '\0';
    read_back_data[6] = '\0';
    read_back_data[7] = '\0';
    if (ana_channel != 3) {
      if (ana_channel != 6) {
        if (ana_channel != 2) goto LAB_000c4c24;
        uVar8 = g_bitmain_pic_state[uVar4].pic_fd;
        send_data[0] = 'U';
        send_data[1] = 0xaa;
        send_data[2] = '\x05';
        send_data[3] = 'A';
        send_data[4] = '\x04';
        send_data[5] = '\0';
        send_data[6] = 'J';
        iVar3 = iic_write(uVar8,send_data,7);
        if (iVar3 == 7) {
          usleep(10000);
          iVar3 = iic_read(uVar8,read_back_data,8);
          if (iVar3 != 8) {
            pcVar6 = "%s read iic err\n";
            goto LAB_000c50a0;
          }
          uVar5 = (uint)read_back_data._0_4_ >> 8 & 0xff;
          if (((read_back_data._0_4_ & 0xff) == 8) && (uVar5 == 0x41)) {
            uVar5 = ((uint)read_back_data._4_4_ >> 8 & 0xff) +
                    (uint)(ushort)((ushort)read_back_data[4] +
                                  (ushort)read_back_data[3] + (ushort)read_back_data[2] + 0x49);
            if ((((uint)read_back_data._4_4_ >> 0x10 & 0xff) == uVar5 >> 8) &&
               ((uint)read_back_data._4_4_ >> 0x18 == (uVar5 & 0xff))) {
              iVar7 = 6;
              *an = (read_back_data._4_4_ & 0xff) << 8 | (uint)read_back_data._4_4_ >> 8 & 0xff;
              goto LAB_000c4c46;
            }
            snprintf(tmp42,0x800,"%s failed 2!\n","_read_an2_voltage_v2");
            _applog(0,tmp42,false);
          }
          else {
            snprintf(tmp42,0x800,
                     "%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
                     "_read_an2_voltage_v2",read_back_data._0_4_ & 0xff,uVar5);
            _applog(0,tmp42,false);
          }
        }
        else {
          pcVar6 = "%s write iic err\n";
LAB_000c50a0:
          snprintf(tmp42,0x800,pcVar6,"_read_an2_voltage_v2");
          _applog(0,tmp42,false);
        }
        iVar7 = 4;
        goto LAB_000c4c46;
      }
      iVar7 = 4;
      goto LAB_000c4d00;
    }
    iVar7 = 4;
LAB_000c4c46:
    uVar8 = g_bitmain_pic_state[uVar4].pic_fd;
    send_data[1] = 0xaa;
    send_data[2] = '\x05';
    send_data[0] = 'U';
    send_data[3] = 'A';
    send_data[4] = '\b';
    send_data[5] = '\0';
    send_data[6] = 'N';
    iVar3 = iic_write(uVar8,send_data,7);
    if (iVar3 == 7) {
      usleep(10000);
      iVar3 = iic_read(uVar8,read_back_data,8);
      if (iVar3 != 8) {
        pcVar6 = "%s read iic err\n";
        goto LAB_000c4f78;
      }
      uVar5 = (uint)read_back_data._0_4_ >> 8 & 0xff;
      if (((read_back_data._0_4_ & 0xff) == 8) && (uVar5 == 0x41)) {
        uVar5 = ((uint)read_back_data._4_4_ >> 8 & 0xff) +
                (uint)(ushort)((ushort)read_back_data[4] +
                              (ushort)read_back_data[3] + (ushort)read_back_data[2] + 0x49);
        if ((((uint)read_back_data._4_4_ >> 0x10 & 0xff) != uVar5 >> 8) ||
           ((uint)read_back_data._4_4_ >> 0x18 != (uVar5 & 0xff))) {
          pcVar6 = "%s failed 2!\n";
          goto LAB_000c4f78;
        }
        puVar1 = read_back_data + iVar7;
        iVar2 = iVar7 + 1;
        iVar7 = iVar7 + 2;
        *an = (uint)CONCAT11(*puVar1,read_back_data[iVar2]);
      }
      else {
        snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n"
                 ,"_read_an3_voltage_v2",read_back_data._0_4_ & 0xff,uVar5);
        _applog(0,tmp42,false);
      }
    }
    else {
      pcVar6 = "%s write iic err\n";
LAB_000c4f78:
      snprintf(tmp42,0x800,pcVar6,"_read_an3_voltage_v2");
      _applog(0,tmp42,false);
    }
LAB_000c4d00:
    uVar8 = g_bitmain_pic_state[uVar4].pic_fd;
    send_data[1] = 0xaa;
    send_data[2] = '\x05';
    send_data[0] = 'U';
    send_data[3] = 'A';
    send_data[4] = '@';
    send_data[5] = '\0';
    send_data[6] = 0x86;
    iVar3 = iic_write(uVar8,send_data,7);
    if (iVar3 == 7) {
      usleep(10000);
      iVar3 = iic_read(uVar8,read_back_data,8);
      if (iVar3 == 8) {
        uVar4 = (uint)read_back_data._0_4_ >> 8 & 0xff;
        if (((read_back_data._0_4_ & 0xff) == 8) && (uVar4 == 0x41)) {
          uVar4 = ((uint)read_back_data._4_4_ >> 8 & 0xff) +
                  (uint)(ushort)((ushort)read_back_data[4] +
                                (ushort)read_back_data[3] + (ushort)read_back_data[2] + 0x49);
          if ((((uint)read_back_data._4_4_ >> 0x10 & 0xff) == uVar4 >> 8) &&
             ((uint)read_back_data._4_4_ >> 0x18 == (uVar4 & 0xff))) {
            *an = (uint)CONCAT11(read_back_data[iVar7],read_back_data[iVar7 + 1]);
          }
          else {
            snprintf(tmp42,0x800,"%s failed 2!\n","_read_an6_voltage_v2");
            _applog(0,tmp42,false);
          }
        }
        else {
          snprintf(tmp42,0x800,
                   "%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
                   "_read_an6_voltage_v2",read_back_data._0_4_ & 0xff,uVar4);
          _applog(0,tmp42,false);
        }
        goto LAB_000c4c24;
      }
      pcVar6 = "%s read iic err\n";
    }
    else {
      pcVar6 = "%s write iic err\n";
    }
    snprintf(tmp42,0x800,pcVar6,"_read_an6_voltage_v2");
    _applog(0,tmp42,false);
LAB_000c4c24:
    pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
    return -0x7ffffdff;
  }
  data = read_back_data;
  pthread_mutex_lock((pthread_mutex_t *)&pic_mutex);
  uVar8 = g_bitmain_pic_state[uVar4].pic_fd;
  send_data[1] = 0xaa;
  send_data[0] = 'U';
  send_data[2] = '\x05';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[3] = 'A';
  send_data[4] = 'L';
  send_data[5] = '\0';
  send_data[6] = 0x92;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  local_82c = 0;
  iVar3 = iic_write(uVar8,send_data,7);
  if (iVar3 == 7) {
    usleep(10000);
    iVar3 = iic_read(uVar8,data,0xc);
    if (iVar3 != 0xc) {
      pcVar6 = "%s read iic err\n";
      goto LAB_000c4f98;
    }
    usleep(10000);
    uVar4 = (uint)read_back_data._0_4_ >> 8 & 0xff;
    if (((read_back_data._0_4_ & 0xff) == 0xc) && (uVar4 == 0x41)) {
      uVar5 = 0;
      uVar4 = 0xc;
      while( true ) {
        uVar4 = uVar5 + uVar4;
        uVar5 = uVar4 & 0xffff;
        if ((byte *)((int)&local_82c + 1) == data) break;
        data = data + 1;
        uVar4 = (uint)*data;
      }
      if (((local_82c >> 0x10 & 0xff) == uVar5 >> 8) && (local_82c >> 0x18 == (uVar4 & 0xff))) {
        iVar3 = 0xc;
        *an = (uint)CONCAT11(read_back_data[4],read_back_data[5]);
        an[1] = (uint)CONCAT11(read_back_data[6],read_back_data[7]);
        an[2] = (uint)CONCAT11((undefined1)local_82c,local_82c._1_1_);
        goto LAB_000c4e80;
      }
      snprintf(tmp42,0x800,"%s failed 2!\n","_read_an_voltage_v2");
      _applog(0,tmp42,false);
    }
    else {
      snprintf(tmp42,0x800,"%s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "_read_an_voltage_v2",read_back_data._0_4_ & 0xff,uVar4);
      _applog(0,tmp42,false);
    }
  }
  else {
    pcVar6 = "%s write iic err\n";
LAB_000c4f98:
    snprintf(tmp42,0x800,pcVar6,"_read_an_voltage_v2");
    _applog(0,tmp42,false);
  }
  iVar3 = -1;
LAB_000c4e80:
  pthread_mutex_unlock((pthread_mutex_t *)&pic_mutex);
  return iVar3;
}

