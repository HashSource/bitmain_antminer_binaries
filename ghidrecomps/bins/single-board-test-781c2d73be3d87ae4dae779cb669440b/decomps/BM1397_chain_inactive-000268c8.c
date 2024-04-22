
/* WARNING: Unknown calling convention */

void BM1397_chain_inactive(uchar which_chain)

{
  uint uVar1;
  uint ret;
  uchar buf [5];
  uint cmd_buf [3];
  
  buf[4] = '\0';
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  printf("\n--- %s\n",DAT_00026940);
  buf[0] = 'S';
  buf[1] = '\x05';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = CRC5(buf,' ');
  cmd_buf[1] = (uint)buf[4] << 0x18;
  cmd_buf[0] = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 | (uint)buf._0_4_ >> 0x18;
  set_BC_command_buffer(cmd_buf);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xfff0ffff | (uint)which_chain << 0x10 | 0x80800000);
  usleep(5000);
  return;
}

