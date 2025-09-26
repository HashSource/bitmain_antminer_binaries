
/* WARNING: Unknown calling convention */

int32_t _get_power_err_code(_Bool clean_cache,_Bool print)

{
  undefined4 uVar1;
  int32_t iVar2;
  uint uVar3;
  bool bVar4;
  uint8_t cmd [6];
  uint8_t reply [32];
  char tmp42 [2048];
  
  uVar3 = _g_power_state.power_version & 0xfffffff7;
  bVar4 = 0x61 < uVar3;
  if (uVar3 != 0x62) {
    bVar4 = 1 < _g_power_state.power_version - 100;
  }
  if (!bVar4 || (uVar3 == 0x62 || _g_power_state.power_version - 100 == 2)) {
    reply[4] = '\0';
    reply[5] = '\0';
    reply[6] = '\0';
    reply[7] = '\0';
    reply[8] = '\0';
    reply[9] = '\0';
    reply[10] = '\0';
    reply[0xb] = '\0';
    reply[0xc] = '\0';
    reply[0xd] = '\0';
    reply[0xe] = '\0';
    reply[0xf] = '\0';
    reply[0x10] = '\0';
    reply[0x11] = '\0';
    reply[0x12] = '\0';
    reply[0x13] = '\0';
    reply[0x14] = '\0';
    reply[0x15] = '\0';
    reply[0x16] = '\0';
    reply[0x17] = '\0';
    reply[0x18] = '\0';
    reply[0x19] = '\0';
    reply[0x1a] = '\0';
    reply[0x1b] = '\0';
    reply[0x1c] = '\0';
    reply[0x1d] = '\0';
    reply[0x1e] = '\0';
    reply[0x1f] = '\0';
    reply[0] = '\0';
    reply[1] = '\0';
    reply[2] = '\0';
    reply[3] = '\0';
    cmd[0] = 'U';
    cmd[1] = 0xaa;
    cmd[2] = '\x04';
    cmd[3] = '\x0e';
    cmd[4] = '\x04';
    cmd[5] = '\x0e';
    if (clean_cache) {
      cmd[4] = '\x04';
      cmd[5] = 0x8e;
      cmd[0] = 'U';
      cmd[1] = 0xaa;
      cmd[2] = '\x04';
      cmd[3] = 0x8e;
    }
    iVar2 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,0xe);
    uVar1 = reply._8_4_;
    if (iVar2 == 0) {
      if (print) {
        snprintf(tmp42,0x800,
                 "Get power code[0-3 4-7 8-11 12-13] %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x, power_code:0x%08x\n"
                 ,reply._0_4_ & 0xff,(uint)reply._0_4_ >> 8 & 0xff,(uint)reply._0_4_ >> 0x10 & 0xff,
                 (uint)reply._0_4_ >> 0x18,reply._4_4_ & 0xff,(uint)reply._4_4_ >> 8 & 0xff,
                 (uint)reply._4_4_ >> 0x10 & 0xff,(uint)reply._4_4_ >> 0x18,reply._8_4_ & 0xff,
                 (uint)reply._8_4_ >> 8 & 0xff,(uint)reply._8_4_ >> 0x10 & 0xff,
                 (uint)reply._8_4_ >> 0x18,reply._12_4_ & 0xff,(uint)reply._12_4_ >> 8 & 0xff,
                 reply._8_4_);
        _applog(3,tmp42,false);
      }
      reply[8] = (uint8_t)uVar1;
      reply[9] = SUB41(uVar1,1);
      reply[10] = SUB41(uVar1,2);
      reply[0xb] = SUB41(uVar1,3);
      iVar2._0_1_ = reply[8];
      iVar2._1_1_ = reply[9];
      iVar2._2_1_ = reply[10];
      iVar2._3_1_ = reply[0xb];
      return iVar2;
    }
    builtin_strncpy(tmp42,"Get power code faile",0x14);
    tmp42[0x14] = 'd';
    tmp42[0x15] = '\n';
    tmp42[0x16] = '\0';
    _applog(3,tmp42,false);
  }
  return -1;
}

