
/* WARNING: Unknown calling convention */

int32_t _bitmain_set_watchdog_v2(int32_t fd,uint8_t ctrl)

{
  int32_t iVar1;
  uint16_t crc;
  uint uVar2;
  uint8_t cmd [8];
  uint8_t reply [32];
  
  cmd[0] = 'U';
  cmd[1] = 0xaa;
  cmd[2] = '\x06';
  cmd[3] = 0x81;
  reply[0] = '\0';
  reply[1] = '\0';
  reply[2] = '\0';
  reply[3] = '\0';
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
  uVar2 = (uint)ctrl * 0x100 + 0x8106 & 0xffff;
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
  cmd._4_4_ = (uint)CONCAT12((char)(uVar2 >> 8),CONCAT11((char)uVar2,ctrl)) << 8;
  iVar1 = exec_power_cmd_v2(fd,cmd,8,reply,8);
  if (iVar1 == 0) {
    uVar2 = (uint)cmd._4_4_ >> 8 & 0xff;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

