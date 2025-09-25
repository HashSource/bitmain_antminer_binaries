
/* WARNING: Unknown calling convention */

int32_t mainboard_sensor_open(void)

{
  int32_t iVar1;
  iic_init_param_t param;
  char tmp42 [2048];
  
  param.chain_id = 0;
  param.i2c_path = (char *)0x0;
  param.master_addr = 0;
  param.slave_high = '\t';
  param.slave_low = '\x04';
  g_sensor_fd = iic_init(&param);
  if (g_sensor_fd < 1) {
    snprintf(tmp42,0x800,"can not open i2c[%s]",param.i2c_path);
    _applog(0,tmp42,false);
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

