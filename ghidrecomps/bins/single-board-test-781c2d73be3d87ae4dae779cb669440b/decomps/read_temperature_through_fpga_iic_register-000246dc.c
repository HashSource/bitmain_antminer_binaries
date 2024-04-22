
/* WARNING: Unknown calling convention */

uchar read_temperature_through_fpga_iic_register(uchar which_chain,uint which_i2c)

{
  byte bVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = (uint)gHashBoard_V9;
  if (uVar3 != 0) {
    if (Conf.sensor_model == 1) {
      uVar3 = 0x900000;
    }
    else {
      uVar3 = 0;
    }
  }
  uVar3 = uVar3 | which_i2c << 0x1a | 0x1000000 | (uint)which_chain << 0x10;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  bVar1 = i2c_read(uVar3);
  uVar2 = (uint)bVar1;
  i2c_read(uVar3);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (uVar2 == 0xff) {
    gSensor_OK[which_chain][0] = false;
  }
  if (Conf.StartTemp <= (int)uVar2) {
    gStartTest = true;
  }
  if (Conf.AlarmTemp < (int)uVar2) {
    gHigherThanAlarmTemp = true;
  }
  return bVar1;
}

