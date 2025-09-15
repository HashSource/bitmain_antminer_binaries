
void chain_inactive(uchar chain)

{
  uint uVar1;
  uchar chain_local;
  char tmp42 [2048];
  uint cmd_buf [3];
  uchar buf [5];
  uint value;
  uint ret;
  
  buf[3] = '\0';
  buf[4] = '\x05';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (opt_multi_version == 0) {
    buf[0] = 0x83;
    buf[1] = '\0';
    buf[2] = '\0';
    buf[3] = CRC5(buf,'\x1b');
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
               "chain_inactive",(uint)buf[0],(uint)buf[1],(uint)buf[2],(uint)buf[3]);
      _applog(7,tmp42,false);
    }
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    set_BC_command_buffer(cmd_buf);
    uVar1 = get_BC_write_command();
    set_BC_write_command(uVar1 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  else {
    buf[0] = 'S';
    buf[1] = '\x05';
    buf[2] = '\0';
    buf[3] = '\0';
    buf[4] = CRC5(buf,' ');
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x\n",
               "chain_inactive",(uint)buf[0],(uint)buf[1],(uint)buf[2],(uint)buf[3],(uint)buf[4]);
      _applog(7,tmp42,false);
    }
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    cmd_buf[1] = (uint)buf[4] << 0x18;
    while( true ) {
      uVar1 = get_BC_write_command();
      if (-1 < (int)uVar1) break;
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(uVar1 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  return;
}

