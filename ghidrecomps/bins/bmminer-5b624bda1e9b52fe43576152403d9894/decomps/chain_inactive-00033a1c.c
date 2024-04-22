
/* WARNING: Unknown calling convention */

void chain_inactive(uchar chain)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint ret;
  uchar buf [5];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\x05';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (*DAT_00033ba0 == 0) {
    buf[0] = 0x85;
    buf[3] = CRC5(buf,'\x1b');
    uVar3 = (uint)buf[3];
    uVar2 = (uint)*DAT_00033ba4;
    if ((uVar2 == 0) ||
       (((*DAT_00033ba8 == '\0' && (*DAT_00033bac == '\0')) && (uVar2 = 0, *DAT_00033bb8 < 7)))) {
      uVar1 = 0x85000000;
    }
    else {
      snprintf(tmp42,0x800,DAT_00033bb4,DAT_00033bb0,0x85,0,0,uVar3);
      _applog(7,tmp42,false);
      uVar3 = (uint)buf[3];
      uVar2 = (uint)buf[2] << 8;
      uVar1 = (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10;
    }
    cmd_buf[0] = uVar3 | uVar2 | uVar1;
    set_BC_command_buffer(cmd_buf);
    uVar2 = get_BC_write_command();
    set_BC_write_command(uVar2 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  else {
    buf[0] = 'U';
    buf[1] = '\x05';
    buf[4] = CRC5(buf,' ');
    uVar2 = (uint)buf[4];
    if ((*DAT_00033ba4 == 0) ||
       (((*DAT_00033ba8 == '\0' && (*DAT_00033bac == '\0')) && (*DAT_00033bb8 < 7)))) {
      cmd_buf[0] = 0x55050000;
    }
    else {
      snprintf(tmp42,0x800,DAT_00033bbc,DAT_00033bb0,0x55,5,0,0,uVar2);
      _applog(7,tmp42,false);
      uVar2 = (uint)buf[4];
      cmd_buf[0] = (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[3] | (uint)buf[2] << 8;
    }
    cmd_buf[1] = uVar2 << 0x18;
    while (uVar2 = get_BC_write_command(), (int)uVar2 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command((uint)chain << 0x10 | 0x80800000 | uVar2 & 0xfff0ffff);
  }
  return;
}

