
void set_misc_control(uchar chain,uchar mode,uchar addr,int i2c)

{
  uint uVar1;
  int i2c_local;
  uchar addr_local;
  uchar mode_local;
  uchar chain_local;
  char tmp42 [2048];
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  uint temp_misc;
  
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  temp_misc = gBM1393_MISC_CONTROL_reg;
  if (i2c != 0) {
    temp_misc = gBM1393_MISC_CONTROL_reg | 0x4060;
  }
  buf[0] = 'A';
  if (mode != '\0') {
    buf[0] = 'Q';
  }
  buf[1] = '\t';
  buf[2] = addr;
  buf[3] = '\x18';
  buf._4_2_ = CONCAT11((uchar)(temp_misc >> 0x10),(uchar)(temp_misc >> 0x18));
  buf._4_3_ = CONCAT12((uchar)(temp_misc >> 8),buf._4_2_);
  buf[7] = (uchar)temp_misc;
  buf[8] = CRC5(buf,'@');
  cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
               buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
  cmd_buf[1] = (uint)buf._4_4_ >> 0x18 |
               buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._4_4_ >> 0x10 & 0xff) << 8;
  cmd_buf[2] = (uint)buf[8] << 0x18;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s: cmd_buf[0]=0x%x, cmd_buf[1]=0x%x, cmd_buf[2]=0x%x, misc=0x%x\n",
             "set_misc_control",cmd_buf[0],cmd_buf[1],cmd_buf[2],temp_misc);
    _applog(5,tmp42,false);
  }
  set_BC_command_buffer(cmd_buf);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  return;
}

