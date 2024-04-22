
/* WARNING: Unknown calling convention */

void BM1391_set_address(uchar which_chain,uchar address)

{
  uint3 uVar1;
  uint uVar2;
  uint ret;
  uchar buf [5];
  uint cmd_buf [3];
  
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  buf[4] = '\0';
  uVar1 = CONCAT12(address,0x500) >> 8;
  buf[1] = (char)uVar1;
  buf[2] = (char)(uVar1 >> 8);
  buf[3] = (char)(uVar1 >> 0x10);
  buf[0] = '@';
  buf[4] = CRC5(buf,' ');
  cmd_buf[1] = (uint)buf[4] << 0x18;
  cmd_buf[0] = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 | (uint)buf._0_4_ >> 0x18;
  set_BC_command_buffer(cmd_buf);
  uVar2 = get_BC_write_command();
  set_BC_write_command(uVar2 & 0xfff0ffff | (uint)which_chain << 0x10 | 0x80800000);
  return;
}

