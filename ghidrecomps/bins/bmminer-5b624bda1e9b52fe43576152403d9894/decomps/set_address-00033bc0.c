
/* WARNING: Unknown calling convention */

void set_address(uchar chain,uchar mode,uchar address)

{
  uint3 uVar1;
  undefined4 uVar2;
  byte bVar3;
  uint ret;
  uint uVar5;
  uint uVar6;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  uint uVar4;
  
  uVar6 = (uint)address;
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (*DAT_00033ce8 == 0) {
    buf[0] = '\x01';
    if (mode != '\0') {
      buf[0] = 0x81;
    }
    buf[1] = address;
    buf[2] = '\0';
    buf[3] = '\0';
    bVar3 = CRC5(buf,'\x1b');
    uVar2 = buf._0_4_;
    uVar4 = (uint)bVar3;
    buf[3] = bVar3;
    uVar5 = (uint)*DAT_00033cec;
    if (uVar5 != 0) {
      if (((*DAT_00033cf0 == '\0') && (*DAT_00033cf4 == '\0')) && (*DAT_00033d00 < 7)) {
        uVar5 = 0;
      }
      else {
        snprintf(tmp42,0x800,DAT_00033cfc,DAT_00033cf8,uVar2 & 0xff,uVar6,0,uVar4);
        _applog(7,tmp42,false);
        uVar6 = (uint)buf._0_4_ >> 8 & 0xff;
        uVar4 = (uint)buf._0_4_ >> 0x18;
        uVar5 = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
      }
    }
    cmd_buf[0] = uVar4 | uVar5 | buf._0_4_ << 0x18 | uVar6 << 0x10;
    set_BC_command_buffer(cmd_buf);
    uVar6 = get_BC_write_command();
    ret = uVar6 & 0xfff0ffff;
    set_BC_write_command(ret | (uint)chain << 0x10 | 0x80800000);
  }
  else {
    uVar1 = CONCAT12(address,0x500) >> 8;
    buf[1] = (char)uVar1;
    buf[2] = (char)(uVar1 >> 8);
    buf[3] = (char)(uVar1 >> 0x10);
    buf[0] = 'A';
    bVar3 = CRC5(buf,' ');
    cmd_buf[1] = (uint)bVar3 << 0x18;
    cmd_buf[0] = uVar6 << 8 | 0x41050000;
    buf[4] = bVar3;
    while (uVar6 = get_BC_write_command(), (int)uVar6 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command((uint)chain << 0x10 | 0x80800000 | uVar6 & 0xfff0ffff);
  }
  return;
}

