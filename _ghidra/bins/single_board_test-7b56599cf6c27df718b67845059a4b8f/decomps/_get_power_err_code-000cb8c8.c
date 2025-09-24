
/* WARNING: Unknown calling convention */

int32_t _get_power_err_code(_Bool clean_cache,_Bool print)

{
  int32_t iVar1;
  int32_t iVar2;
  bool bVar3;
  uint8_t cmd [6];
  uint8_t reply [32];
  char tmp42 [2048];
  
  bVar3 = 0x61 < _g_power_state.power_version;
  if (_g_power_state.power_version != 0x62) {
    bVar3 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar3 || (_g_power_state.power_version == 0x62 || _g_power_state.power_version - 100 == 2)) {
    cmd[0] = 'U';
    cmd[1] = 0xaa;
    cmd[2] = '\x04';
    cmd[3] = '\x0e';
    cmd[4] = '\x04';
    cmd[5] = '\x0e';
    memset(reply,0,0x20);
    if (clean_cache) {
      cmd[5] = 0x8e;
      cmd[3] = 0x8e;
    }
    iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,0xe);
    if (iVar2 == 0) {
      if (!print) {
        iVar1._0_1_ = reply[8];
        iVar1._1_1_ = reply[9];
        iVar1._2_1_ = reply[10];
        iVar1._3_1_ = reply[0xb];
        return iVar1;
      }
      snprintf(tmp42,0x800,
               "Get power error code[4-7 8-11] %02x%02x%02x%02x %02x%02x%02x%02x, err_code:0x%08x\n"
               ,(uint)reply[4],(uint)reply[5],(uint)reply[6],(uint)reply[7],reply._8_4_ & 0xff,
               (uint)reply._8_4_ >> 8 & 0xff,(uint)reply._8_4_ >> 0x10 & 0xff,
               (uint)reply._8_4_ >> 0x18,reply._8_4_);
      _applog(3,tmp42,false);
      iVar2._0_1_ = reply[8];
      iVar2._1_1_ = reply[9];
      iVar2._2_1_ = reply[10];
      iVar2._3_1_ = reply[0xb];
      return iVar2;
    }
    builtin_strncpy(tmp42,"Get power error code failed\n",0x1c);
    tmp42[0x1c] = '\0';
    _applog(3,tmp42,false);
  }
  return -1;
}

