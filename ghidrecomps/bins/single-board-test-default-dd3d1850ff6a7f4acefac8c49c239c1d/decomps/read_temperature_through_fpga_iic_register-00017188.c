
byte read_temperature_through_fpga_iic_register(byte param_1,int param_2)

{
  byte bVar1;
  byte local_9;
  
  local_9 = 0;
  if ((gHashBoard_V9 != '\0') && (Conf[248] == '\x01')) {
    local_9 = 9;
  }
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  bVar1 = i2c_read(param_2 << 0x1a | (uint)local_9 << 0x14 | (uint)param_1 << 0x10 | 0x1000000);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (bVar1 != 0) {
    gSensor_OK[(uint)param_1 * 4] = 1;
  }
  if ((int)Conf[224] <= (int)(uint)bVar1) {
    gStartTest = 1;
  }
  if ((int)Conf[226] < (int)(uint)bVar1) {
    gHigherThanAlarmTemp = 1;
  }
  return bVar1;
}

