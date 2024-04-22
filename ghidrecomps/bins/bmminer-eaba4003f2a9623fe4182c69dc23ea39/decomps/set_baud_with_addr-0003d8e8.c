
void set_baud_with_addr(uchar bauddiv,int mode,uchar chip_addr,int chain,int iic,int open_core,
                       int bottom_or_mid)

{
  uint uVar1;
  int chain_local;
  int mode_local;
  uchar chip_addr_local;
  uchar bauddiv_local;
  char tmp42 [2048];
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  uint i;
  
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (opt_multi_version == 0) {
    buf[1] = '\x10';
    buf[2] = bauddiv & 0x1f;
    buf[0] = 0x86;
    buf[3] = CRC5(buf,'\x1b');
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
               "set_baud_with_addr",(uint)buf[0],(uint)buf[1],(uint)buf[2],(uint)buf[3]);
      _applog(7,tmp42,false);
    }
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    set_BC_command_buffer(cmd_buf);
    uVar1 = get_BC_write_command();
    set_BC_write_command(uVar1 & 0xfff0ffff | chain << 0x10 | 0x80800000);
  }
  else {
    buf[0] = 'A';
    if (mode != 0) {
      buf[0] = 'Q';
    }
    buf[1] = '\t';
    buf[3] = '\x18';
    buf[4] = '@';
    if (bottom_or_mid == 0) {
      buf[5] = '!';
    }
    else {
      buf[5] = ' ';
    }
    if (iic == 0) {
      buf[6] = bauddiv & 0x1f;
      buf[7] = '\0';
    }
    else {
      buf[6] = bauddiv & 0x1f | 0x40;
      buf[7] = '`';
    }
    if (open_core != 0) {
      buf[6] = buf[6] | 0x80;
    }
    buf[8] = '\0';
    buf[2] = chip_addr;
    buf[8] = CRC5(buf,'@');
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
    cmd_buf[2] = (uint)buf[8] << 0x18;
    while( true ) {
      uVar1 = get_BC_write_command();
      if (-1 < (int)uVar1) break;
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(uVar1 & 0xfff0ffff | chain << 0x10 | 0x80800000);
  }
  return;
}

