
/* WARNING: Unknown calling convention */

void set_baud_with_addr(uchar bauddiv,int mode,uchar chip_addr,int chain,int iic,int open_core,
                       int bottom_or_mid)

{
  uint uVar1;
  uint i;
  uint uVar2;
  uint uVar3;
  uint ret;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  uVar3 = (uint)bauddiv;
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (*DAT_00032cb8 == 0) {
    uVar3 = uVar3 & 0x1f;
    buf[0] = 0x86;
    buf[2] = (uchar)uVar3;
    buf[1] = '\x10';
    buf[3] = CRC5(buf,'\x1b');
    uVar1 = (uint)buf[3];
    if ((*DAT_00032cbc == '\0') ||
       (((*DAT_00032cc0 == '\0' && (*DAT_00032cc4 == '\0')) && (*DAT_00032cd0 < 7)))) {
      uVar2 = 0x86100000;
    }
    else {
      snprintf(tmp42,0x800,DAT_00032cc8,DAT_00032ccc,0x86,0x10,uVar3,uVar1);
      _applog(7,tmp42,false);
      uVar3 = (uint)buf[2];
      uVar1 = (uint)buf[3];
      uVar2 = (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10;
    }
    cmd_buf[0] = uVar2 | uVar1 | uVar3 << 8;
    set_BC_command_buffer(cmd_buf);
    uVar3 = get_BC_write_command();
    set_BC_write_command(uVar3 & 0xfff0ffff | chain << 0x10 | 0x80800000U);
  }
  else {
    if (mode == 0) {
      buf[0] = 'H';
    }
    else {
      buf[0] = 'X';
    }
    buf[4] = '@';
    buf[1] = '\t';
    buf[3] = '\x1c';
    if (bottom_or_mid == 0) {
      buf[5] = '!';
    }
    else {
      buf[5] = ' ';
    }
    if (iic == 0) {
      uVar3 = uVar3 & 0x1f;
      buf[6] = (uchar)uVar3;
      uVar1 = 0;
    }
    else {
      uVar1 = 0x60;
      uVar3 = uVar3 & 0x1f | 0x40;
      buf[7] = '`';
      buf[6] = (uchar)uVar3;
    }
    if (open_core != 0) {
      uVar3 = uVar3 | 0x80;
      buf[6] = (uchar)uVar3;
    }
    buf[8] = '\0';
    buf[2] = chip_addr;
    buf[8] = CRC5(buf,'@');
    cmd_buf[2] = (uint)buf[8] << 0x18;
    cmd_buf[0] = (uint)buf[0] << 0x18 | 0x9001c | (uint)chip_addr << 8;
    cmd_buf[1] = uVar1 | (uint)buf[5] << 0x10 | 0x40000000 | uVar3 << 8;
    while (uVar3 = get_BC_write_command(), (int)uVar3 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(chain << 0x10 | 0x80800000U | uVar3 & 0xfff0ffff);
  }
  return;
}

