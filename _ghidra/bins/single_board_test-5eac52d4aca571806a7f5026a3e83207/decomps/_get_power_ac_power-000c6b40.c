
/* WARNING: Unknown calling convention */

float _get_power_ac_power(void)

{
  int32_t iVar1;
  uint8_t cmd [6];
  uint8_t reply [32];
  float f_power;
  char acStack_80c [2048];
  
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x04';
  cmd[3] = '\b';
  cmd[4] = '\x04';
  cmd[5] = '\b';
  memset(reply,0,0x20);
  iVar1 = exec_power_cmd_v2(_g_power_state.power_fd,cmd,6,reply,10);
  if (iVar1 == 0) {
    f_power = (float)CONCAT13(reply[7],CONCAT12(reply[6],CONCAT11(reply[5],reply[4])));
    return f_power;
  }
  f_power = (float)0x20746547;
  builtin_strncpy(acStack_80c,"ac power failed\n",0x10);
  acStack_80c[0x10] = 0;
  _applog(3,(char *)&f_power,false);
  return 0.0;
}

