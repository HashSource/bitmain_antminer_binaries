
void set_frequency_with_addr_plldatai(int pllindex,uchar mode,uchar addr,uchar chain)

{
  uint uVar1;
  uint uVar2;
  uint in_stack_fffff6a8;
  undefined4 in_stack_fffff6ac;
  uchar chain_local;
  uchar addr_local;
  uchar mode_local;
  int pllindex_local;
  char tmp42 [2048];
  char logstr [256];
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  int i;
  int chipIndex;
  uint reg_data_vil;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  
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
  uVar1 = __aeabi_uidiv(addr,dev->addrInterval);
  pllindex_local = pllindex;
  if (0xe < chain_badcore_num[chain][uVar1 & 0xff]) {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      in_stack_fffff6a8 = (uint)chain;
      snprintf(tmp42,0x800,"Detect a bad chip=%d on chain[%d], fixed to 400M\n",uVar1 & 0xff);
      _applog(5,tmp42,false);
    }
    pllindex_local = 0xc;
  }
  uVar1 = (uint)chain;
  uVar2 = freq_pll_1393[pllindex_local].vilpll;
  if (opt_multi_version == 0) {
    memset(buf,0,9);
    memset(cmd_buf,0,0xc);
    buf[0] = '\a';
    buf[1] = '\0';
    buf[2] = '\0';
    buf[3] = '\0';
    buf[3] = CRC5(buf,'\x1b');
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    set_BC_command_buffer(cmd_buf);
    uVar2 = get_BC_write_command();
    set_BC_write_command(uVar2 & 0xfff0ffff | uVar1 << 0x10 | 0x80800000);
    cgsleep_us(CONCAT44(in_stack_fffff6ac,in_stack_fffff6a8));
    memset(buf,0,9);
    memset(cmd_buf,0,0xc);
    buf[0] = 0x82;
    buf[1] = '\0';
    buf[2] = '\0';
    buf[3] = '\0';
    buf[3] = CRC5(buf,'\x1b');
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    set_BC_command_buffer(cmd_buf);
    uVar2 = get_BC_write_command();
    set_BC_write_command(uVar2 & 0xfff0ffff | uVar1 << 0x10 | 0x80800000);
    cgsleep_us(CONCAT44(in_stack_fffff6ac,in_stack_fffff6a8));
  }
  else {
    memset(buf,0,9);
    memset(cmd_buf,0,0xc);
    if (mode == '\0') {
      buf[0] = 'A';
    }
    else {
      buf[0] = 'Q';
    }
    buf[1] = '\t';
    buf[3] = '\b';
    buf[4] = (uchar)(uVar2 >> 0x18);
    buf[5] = (uchar)(uVar2 >> 0x10);
    buf[6] = (uchar)(uVar2 >> 8);
    buf[7] = (uchar)uVar2;
    buf[2] = addr;
    buf[8] = CRC5(buf,'@');
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
    cmd_buf[2] = (uint)buf[8] << 0x18;
    while( true ) {
      uVar2 = get_BC_write_command();
      if (-1 < (int)uVar2) break;
      cgsleep_us(CONCAT44(in_stack_fffff6ac,in_stack_fffff6a8));
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(uVar2 & 0xfff0ffff | uVar1 << 0x10 | 0x80800000);
    cgsleep_us(CONCAT44(in_stack_fffff6ac,in_stack_fffff6a8));
  }
  return;
}

