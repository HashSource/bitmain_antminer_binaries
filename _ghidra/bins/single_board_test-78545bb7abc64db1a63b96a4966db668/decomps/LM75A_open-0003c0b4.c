
int32_t LM75A_open(uint32_t which_chain,uint8_t index)

{
  byte bVar1;
  uint32_t uVar2;
  uint8_t index_local;
  uint32_t which_chain_local;
  char time_stamp [48];
  char tmp1 [256];
  iic_init_param_t param;
  int32_t ret;
  
  param.master_addr = 0;
  bVar1 = (byte)which_chain;
  param.chain_id = which_chain;
  if (index != '\0') {
    if (index != '\x01') {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : not supported index\n","LM75A_open");
      builtin_strncpy(tmp1,"not supported index",0x14);
      log_to_file(tmp1,time_stamp);
      return -1;
    }
    bVar1 = bVar1 + 4;
  }
  param.slave_low = bVar1 & 7;
  param.slave_high = '\t';
  if ((_g_lm75a_sensor[which_chain * 2 + (uint)index].sensor_fd == 0) ||
     (_g_lm75a_sensor[(uint)index + which_chain * 2].chain_has_opened == 0)) {
    if (_g_lm75a_sensor[(uint)index + which_chain * 2].chain_has_opened == 0) {
      uVar2 = iic_init(&param);
      if (-1 < (int)uVar2) {
        _g_lm75a_sensor[which_chain * 2 + (uint)index].sensor_fd = uVar2;
        _g_lm75a_sensor[(uint)index + which_chain * 2].chain_has_opened = 1;
      }
    }
    else {
      uVar2 = _g_lm75a_sensor[which_chain * 2 + (uint)index].sensor_fd;
    }
  }
  else {
    uVar2 = _g_lm75a_sensor[which_chain * 2 + (uint)index].sensor_fd;
  }
  return uVar2;
}

