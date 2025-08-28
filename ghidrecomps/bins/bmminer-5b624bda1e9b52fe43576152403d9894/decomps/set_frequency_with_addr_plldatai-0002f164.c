
/* WARNING: Unknown calling convention */

void set_frequency_with_addr_plldatai(int pllindex,uchar mode,uchar addr,uchar chain)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uchar buf [9];
  uint cmd_buf [3];
  
  iVar2 = opt_multi_version;
  uVar4 = freq_pll_1385[pllindex].vilpll;
  if (opt_multi_version == 0) {
    buf._4_4_ = opt_multi_version;
    buf[0] = '\a';
    buf[1] = '\0';
    buf[2] = '\0';
    buf[3] = '\0';
    uVar5 = (uint)chain << 0x10 | 0x80800000;
    buf[8] = '\0';
    cmd_buf[0] = opt_multi_version;
    cmd_buf[1] = opt_multi_version;
    cmd_buf[2] = opt_multi_version;
    bVar3 = CRC5(buf,'\x1b');
    cmd_buf[0] = bVar3 | 0x7000000;
    buf[3] = bVar3;
    set_BC_command_buffer(cmd_buf);
    uVar4 = get_BC_write_command();
    set_BC_write_command(uVar4 & 0xfff0ffff | uVar5);
    cgsleep_us(3000);
    buf._4_4_ = iVar2;
    buf[0] = 0x82;
    buf[1] = '\0';
    buf[2] = '\0';
    buf[3] = '\0';
    buf[8] = '\0';
    cmd_buf[0] = iVar2;
    cmd_buf[1] = iVar2;
    cmd_buf[2] = iVar2;
    bVar3 = CRC5(buf,'\x1b');
    cmd_buf[0] = bVar3 | 0x82000000;
    buf[3] = bVar3;
    set_BC_command_buffer(cmd_buf);
    uVar4 = get_BC_write_command();
    set_BC_write_command(uVar4 & 0xfff0ffff | uVar5);
    cgsleep_us(5000);
  }
  else {
    buf[8] = '\0';
    cmd_buf[0] = 0;
    cmd_buf[1] = 0;
    cmd_buf[2] = 0;
    if (mode == '\0') {
      uVar5 = 0x4809000c;
      buf[0] = 'H';
      buf[1] = '\0';
    }
    else {
      buf[0] = 'X';
      buf[1] = '\0';
      uVar5 = 0x5809000c;
    }
    bVar3 = (byte)(uVar4 >> 0x10);
    buf[5] = bVar3;
    buf[4] = (char)(uVar4 >> 0x18);
    bVar1 = (byte)(uVar4 >> 8);
    buf[7] = (uchar)uVar4;
    buf[6] = bVar1;
    buf[2] = addr;
    buf[3] = '\f';
    buf[1] = '\t';
    buf[8] = CRC5(buf,'@');
    cmd_buf[2] = (uint)buf[8] << 0x18;
    cmd_buf[0] = uVar5 | (uint)addr << 8;
    cmd_buf[1] = (uint)bVar3 << 0x10 | uVar4 & 0xff000000 | uVar4 & 0xff | (uint)bVar1 << 8;
    while (uVar4 = get_BC_write_command(), (int)uVar4 < 0) {
      cgsleep_us(500);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command((uint)chain << 0x10 | 0x80800000 | uVar4 & 0xfff0ffff);
    cgsleep_us(10000);
  }
  return;
}

