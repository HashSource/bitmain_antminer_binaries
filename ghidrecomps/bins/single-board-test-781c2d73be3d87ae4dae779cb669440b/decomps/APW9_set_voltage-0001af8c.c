
/* WARNING: Unknown calling convention */

void APW9_set_voltage(uchar N)

{
  ushort uVar1;
  uint8_t cmd [8];
  uint8_t reply [32];
  
  cmd._0_4_ = DAT_0002cafc;
  cmd._4_4_ = DAT_0002cb00;
  memset(reply,0,0x20);
  uVar1 = (ushort)cmd[5];
  cmd[4] = N;
  cmd._6_2_ = uVar1 + (ushort)cmd[3] + (ushort)cmd[2] + (ushort)N;
  power_send_cmd(cmd,'\b',reply,'\b');
  return;
}

