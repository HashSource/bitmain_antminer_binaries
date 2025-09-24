
/* WARNING: Unknown calling convention */

int32_t _bitmain_set_watchdog_v2(int32_t fd,uint8_t ctrl)

{
  int32_t iVar1;
  uint uVar2;
  uint8_t cmd [8];
  uint8_t reply [32];
  
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x06';
  cmd[3] = 0x81;
  cmd[4] = '\0';
  cmd[5] = '\0';
  cmd[6] = '\0';
  cmd[7] = '\0';
  memset(reply,0,0x20);
  cmd[5] = ctrl;
  cmd[6] = '\x06';
  cmd[7] = ctrl + 0x81;
  iVar1 = exec_power_cmd_v2(fd,cmd,8,reply,8);
  if (iVar1 == 0) {
    uVar2 = (uint)cmd._4_4_ >> 8 & 0xff;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

