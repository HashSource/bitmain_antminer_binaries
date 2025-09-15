
void set_divider(uint div,uint chain,uint mode,uchar addr)

{
  byte bVar1;
  uint uVar2;
  uchar addr_local;
  uint mode_local;
  uint chain_local;
  uint div_local;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  memset(buf,0,9);
  memset(cmd_buf,0,0xc);
  uVar2 = gBM1393_PLL0_DIVIDER_reg & 0xffffff00;
  gBM1393_PLL0_DIVIDER_reg = uVar2 | div & 0xff;
  if (mode == 0) {
    buf[0] = 'A';
  }
  else {
    buf[0] = 'Q';
  }
  buf[1] = '\t';
  buf[3] = 'p';
  buf[4] = (uchar)(uVar2 >> 0x18);
  buf[5] = (uchar)(uVar2 >> 0x10);
  buf[6] = (uchar)(uVar2 >> 8);
  buf[7] = (uchar)div;
  buf[2] = addr;
  bVar1 = CRC5(buf,'@');
  buf[8] = bVar1 & 0x1f;
  cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
  cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
  cmd_buf[2] = (uint)buf[8] << 0x18;
  set_BC_command_buffer(cmd_buf);
  uVar2 = get_BC_write_command();
  set_BC_write_command(uVar2 & 0xfff0ffff | chain << 0x10 | 0x80800000);
  return;
}

