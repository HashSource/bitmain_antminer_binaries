
void set_address(uchar chain,uchar mode,uchar address)

{
  undefined4 uVar1;
  byte bVar2;
  uint uVar3;
  uchar address_local;
  uchar mode_local;
  uchar chain_local;
  char tmp42 [2048];
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
  if (opt_multi_version == 0) {
    buf._0_4_ = (uint)address << 8;
    if (mode != '\0') {
      buf[2] = '\0';
      buf[3] = '\0';
      buf[1] = address;
      buf[0] = 0x80;
    }
    bVar2 = CRC5(buf,'\x1b');
    uVar1 = buf._0_4_;
    buf[3] = bVar2;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n","set_address",
               uVar1 & 0xff,(uint)uVar1 >> 8 & 0xff,(uint)uVar1 >> 0x10 & 0xff,(uint)bVar2);
      _applog(7,tmp42,false);
    }
    cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                 ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
    set_BC_command_buffer(cmd_buf);
    uVar3 = get_BC_write_command();
    set_BC_write_command(uVar3 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  else {
    buf[2] = address;
    buf[0] = '@';
    buf[1] = '\x05';
    buf[3] = '\0';
    bVar2 = CRC5(buf,' ');
    buf[4] = bVar2;
    cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                 ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
    cmd_buf[1] = (uint)bVar2 << 0x18;
    while( true ) {
      uVar3 = get_BC_write_command();
      if (-1 < (int)uVar3) break;
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(uVar3 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  return;
}

