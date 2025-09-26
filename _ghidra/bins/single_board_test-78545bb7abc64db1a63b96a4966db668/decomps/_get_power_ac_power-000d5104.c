
/* WARNING: Unknown calling convention */

float _get_power_ac_power(void)

{
  int32_t iVar1;
  uint8_t cmd [6];
  uint8_t reply [32];
  float f_power;
  char acStack_80c [2044];
  
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x04';
  cmd[3] = '\b';
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
  cmd[4] = '\x04';
  cmd[5] = '\b';
  reply[0] = '\0';
  reply[1] = '\0';
  reply[2] = '\0';
  reply[3] = '\0';
  iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,10);
  if (iVar1 == 0) {
    return (float)reply._4_4_;
  }
  f_power = (float)0x20746547;
  builtin_strncpy(acStack_80c,"ac power failed\n",0x10);
  acStack_80c[0x10] = 0;
  _applog(3,(char *)&f_power,false);
  return 0.0;
}

