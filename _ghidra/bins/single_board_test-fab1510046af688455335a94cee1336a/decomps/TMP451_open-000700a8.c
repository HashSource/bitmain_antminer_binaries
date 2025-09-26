
int32_t TMP451_open(uint32_t which_chain)

{
  uint32_t uVar1;
  uint32_t which_chain_local;
  iic_init_param_t param;
  int32_t ret;
  
  param.master_addr = 0;
  param.slave_high = '\t';
  param.slave_low = '\x04';
  uVar1 = _g_tmp451_sensor.sensor_fd;
  if ((_g_tmp451_sensor.chain_has_opened == 0) &&
     (param.chain_id = which_chain, uVar1 = iic_init(&param), -1 < (int)uVar1)) {
    _g_tmp451_sensor.chain_has_opened = 1;
    _g_tmp451_sensor.sensor_fd = uVar1;
  }
  return uVar1;
}

