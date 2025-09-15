
int8_t do_calibration_sensor_offset(uchar device,uchar chip_addr,int chain,int temp_chip_index)

{
  char cVar1;
  int16_t iVar2;
  uint uVar3;
  byte bVar4;
  int temp_chip_index_local;
  int chain_local;
  uchar chip_addr_local;
  uchar device_local;
  char tmp42 [2048];
  char logstr [1024];
  int8_t middle;
  int check_ok_counter;
  int get_value_once;
  int8_t retry_Time_Count;
  int8_t error_Limit;
  int16_t ret;
  int8_t local;
  int8_t offset;
  
  device_local = device;
  if ((dev->TempChipType[chain][temp_chip_index] != '\x1a') &&
     (dev->TempChipType[chain][temp_chip_index] != 'U')) {
    DEVICEADDR[chain] = 0x98;
    device_local = DEVICEADDR[chain];
    uVar3 = check_reg_temp(device_local,0xfe,'\0','\0',chip_addr,chain);
    dev->TempChipType[chain][temp_chip_index] = (uchar)uVar3;
    if ((dev->TempChipType[chain][temp_chip_index] != '\x1a') &&
       (dev->TempChipType[chain][temp_chip_index] != 'U')) {
      DEVICEADDR[chain] = 0x9a;
      device_local = DEVICEADDR[chain];
      uVar3 = check_reg_temp(device_local,0xfe,'\0','\0',chip_addr,chain);
      dev->TempChipType[chain][temp_chip_index] = (uchar)uVar3;
      if ((dev->TempChipType[chain][temp_chip_index] != '\x1a') &&
         (dev->TempChipType[chain][temp_chip_index] != 'U')) {
        DEVICEADDR[chain] = 0x9c;
        device_local = DEVICEADDR[chain];
        uVar3 = check_reg_temp(device_local,0xfe,'\0','\0',chip_addr,chain);
        dev->TempChipType[chain][temp_chip_index] = (uchar)uVar3;
      }
    }
  }
  if (dev->TempChipType[chain][temp_chip_index] == '\x1a') {
    is218_Temp = true;
  }
  check_reg_temp(device_local,9,'\x04','\x01',chip_addr,chain);
  check_reg_temp(device_local,0x11,'\0','\x01',chip_addr,chain);
  uVar3 = check_reg_temp(device_local,0,'\0','\0',chip_addr,chain);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"[%s] get local temp is %d\n","do_calibration_sensor_offset",uVar3 & 0xff);
    _applog(5,tmp42,false);
  }
  iVar2 = get_local((ushort)uVar3 & 0xff);
  cVar1 = (char)iVar2;
  uVar3 = check_reg_temp(device_local,1,'\0','\0',chip_addr,chain);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"[%s] get remote temp is %d\n","do_calibration_sensor_offset",uVar3 & 0xff)
    ;
    _applog(5,tmp42,false);
  }
  bVar4 = (byte)uVar3 & 0xbf;
  offset = calc_offset((int)(char)bVar4,(int)cVar1);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"offset local:%d remote:%d offset:%d \n",(int)cVar1,(int)(char)bVar4,
             (int)offset);
    _applog(5,tmp42,false);
  }
  if (offset < '\x01') {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,
               "Warning: Chain[%d] chip[%d] local:%hhd remote:%hhd offset:%hhd, will fixed offset=27\n"
               ,chain,(uint)chip_addr,(int)cVar1,(int)(char)bVar4,(int)offset);
      _applog(5,tmp42,false);
    }
    offset = '\x1b';
  }
  check_reg_temp(device_local,0x11,offset,'\x01',chip_addr,chain);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"New offset Chain[%d] chip[%d] local:%hhd remote:%hhd offset:%hhd \n",chain
             ,(uint)chip_addr,(int)cVar1,(int)(char)bVar4,(int)offset);
    _applog(5,tmp42,false);
  }
  return offset;
}

