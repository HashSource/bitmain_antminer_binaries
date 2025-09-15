
void set_address(uchar chain,uchar mode,uchar address)

{
  byte bVar1;
  uint uVar2;
  uchar address_local;
  uchar mode_local;
  uchar chain_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  buf[2] = address;
  buf[0] = '@';
  buf[1] = '\x05';
  buf[3] = '\0';
  bVar1 = CRC5(buf,' ');
  buf[4] = bVar1;
  cmd_buf[0] = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 | (uint)buf._0_4_ >> 0x18;
  cmd_buf[1] = (uint)bVar1 << 0x18;
  while( true ) {
    uVar2 = get_BC_write_command();
    if (-1 < (int)uVar2) break;
    cgsleep_ms(1);
  }
  set_BC_command_buffer(cmd_buf);
  set_BC_write_command((uint)chain << 0x10 | uVar2 & 0xfff0ffff | 0x80800000);
  return;
}

