
int8_t calibration_sensor_offset(uchar device,int chain)

{
  char cVar1;
  uchar chain_00;
  int8_t iVar2;
  uint uVar3;
  int chain_local;
  uchar device_local;
  char tmp42 [2048];
  char logstr [1024];
  char temp_offset [10];
  int8_t local;
  uint ret;
  int i;
  byte local_21;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  chain_00 = (uchar)chain;
  get_temperature_offset_value(chain_00,(uchar *)temp_offset);
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"Chain[J%d] PIC temp offset=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",chain,
             (int)temp_offset[0],(int)temp_offset[1],(int)temp_offset[2],(int)temp_offset[3],
             (int)temp_offset[4],(int)temp_offset[5],(int)temp_offset[6],(int)temp_offset[7],
             (int)temp_offset[8],(int)temp_offset[9]);
    _applog(5,tmp42,false);
  }
  temp_offset[8] = temp_offset[8] & 0x1f;
  if (temp_offset[8] == 7) {
    DEVICEADDR[chain] = 0x9c;
  }
  else if ((temp_offset[8] == 9) || (temp_offset[8] == 6)) {
    DEVICEADDR[chain] = 0x9a;
  }
  else {
    DEVICEADDR[chain] = 0x98;
  }
  local_21 = DEVICEADDR[chain];
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"chain[%d] temp chip I2C addr=0x%02x\n",chain,(uint)local_21);
    _applog(5,tmp42,false);
  }
  if (((temp_offset[8] != '\x01') && (temp_offset[8] != '\x02')) &&
     ((chip_hasNoMiddle = true, use_syslog != false ||
      ((opt_log_output != false || (4 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"chain[%d] has no middle temp, use special fix mode.\n",chain);
    _applog(5,tmp42,false);
  }
  dev->chain_asic_temp_num[chain] = '\0';
  i = 0;
  do {
    if (3 < i) {
LAB_0003e7f6:
      if (dev->chain_asic_temp_num[chain] < '\x01') {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Warning: Chain[J%d] has no temp offset in PIC! will fix it\n",
                   chain + 1);
          _applog(5,tmp42,false);
        }
        dev->chain_asic_temp_num[chain] = '\x04';
        dev->TempChipAddr[chain][0] = (uchar)(((int)temp_offset[0] - 1U & 0xff) << 1);
        dev->TempChipAddr[chain][1] = (uchar)(((int)temp_offset[2] - 1U & 0xff) << 1);
        dev->TempChipAddr[chain][2] = (uchar)(((int)temp_offset[4] - 1U & 0xff) << 1);
        dev->TempChipAddr[chain][3] = (uchar)(((int)temp_offset[6] - 1U & 0xff) << 1);
        for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
          set_misc_control(chain_00,'\0',dev->TempChipAddr[chain][i],1);
          check_asic_reg_with_addr(0x18,dev->TempChipAddr[chain][i],chain,1);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Chain[J%d] use default temp chip[%d] \n",chain + 1,
                     (uint)dev->TempChipAddr[chain][i]);
            _applog(5,tmp42,false);
          }
          iVar2 = do_calibration_sensor_offset(local_21,dev->TempChipAddr[chain][i],chain,i);
          middle_Offset[chain][i] = iVar2;
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Chain[J%d] chip[%d] get middle temp offset=%d typeID=%02x\n",
                     chain + 1,(uint)dev->TempChipAddr[chain][i],(int)middle_Offset[chain][i],
                     (uint)dev->TempChipType[chain][i]);
            _applog(5,tmp42,false);
          }
        }
      }
      return '\0';
    }
    if (('\0' < temp_offset[i * 2]) && (temp_offset[i * 2] < 'l')) {
      dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]] =
           (uchar)(((int)temp_offset[i * 2] - 1U & 0xff) << 1);
      middle_Offset[chain][dev->chain_asic_temp_num[chain]] = temp_offset[i * 2 + 1];
      set_misc_control(chain_00,'\0',dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],1);
      check_asic_reg_with_addr
                (0x18,dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain,1);
      uVar3 = check_reg_temp(local_21,0xfe,'\0','\0',
                             dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain);
      dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] = (uchar)uVar3;
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Chain[J%d] chip[%d] use PIC middle temp offset=%d typeID=%02x\n",chain
                 ,(dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]] >> 1) + 1,
                 (int)middle_Offset[chain][dev->chain_asic_temp_num[chain]],
                 (uint)dev->TempChipType[chain][dev->chain_asic_temp_num[chain]]);
        _applog(5,tmp42,false);
      }
      if (((dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != '\x1a') &&
          (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'U')) &&
         (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'A')) {
        chip_hasNoMiddle = true;
        DEVICEADDR[chain] = 0x98;
        local_21 = DEVICEADDR[chain];
        uVar3 = check_reg_temp(local_21,0xfe,'\0','\0',
                               dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain);
        dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] = (uchar)uVar3;
        if (((dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != '\x1a') &&
            (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'U')) &&
           (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'A')) {
          DEVICEADDR[chain] = 0x9a;
          local_21 = DEVICEADDR[chain];
          uVar3 = check_reg_temp(local_21,0xfe,'\0','\0',
                                 dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain);
          dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] = (uchar)uVar3;
          if (((dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != '\x1a') &&
              (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'U')) &&
             (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'A')) {
            DEVICEADDR[chain] = 0x9c;
            local_21 = DEVICEADDR[chain];
            uVar3 = check_reg_temp(local_21,0xfe,'\0','\0',
                                   dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain);
            dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] = (uchar)uVar3;
          }
        }
      }
      if (((dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != '\x1a') &&
          (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'U')) &&
         (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'A')) {
        dev->chain_asic_temp_num[chain] = '\0';
        goto LAB_0003e7f6;
      }
      if (dev->TempChipType[chain][dev->chain_asic_temp_num[chain]] != 'U') {
        is218_Temp = true;
      }
      cVar1 = dev->chain_asic_temp_num[chain];
      iVar2 = do_calibration_sensor_offset
                        (local_21,dev->TempChipAddr[chain][dev->chain_asic_temp_num[chain]],chain,
                         (int)dev->chain_asic_temp_num[chain]);
      middle_Offset[chain][cVar1] = iVar2;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Chain[J%d] chip[%d] get middle temp offset=%d typeID=%02x\n",chain,
                 (uint)dev->TempChipAddr[chain][i],
                 (int)middle_Offset[chain][dev->chain_asic_temp_num[chain]],
                 (uint)dev->TempChipType[chain][dev->chain_asic_temp_num[chain]]);
        _applog(5,tmp42,false);
      }
      dev->chain_asic_temp_num[chain] = dev->chain_asic_temp_num[chain] + '\x01';
    }
    i = i + 1;
  } while( true );
}

