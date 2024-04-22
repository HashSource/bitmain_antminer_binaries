
/* WARNING: Variable defined which should be unmapped: no_use-local */

void set_baud(uchar bauddiv,int no_use)

{
  undefined4 uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint in_stack_fffff7b0;
  uint in_stack_fffff7b4;
  int no_use_local;
  uchar bauddiv_local;
  char tmp42 [2048];
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  uint i;
  
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
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      if (opt_multi_version == 0) {
        buf._0_4_ = CONCAT13(buf[3],CONCAT12(bauddiv,0x1006)) & 0xff1fffff;
        buf._0_4_ = buf._0_4_ | 0x80;
        bVar2 = CRC5(buf,'\x1b');
        uVar1 = buf._0_4_;
        buf[3] = bVar2;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          in_stack_fffff7b0 = uVar1 & 0xff;
          in_stack_fffff7b4 = (uint)uVar1 >> 8 & 0xff;
          snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n","set_baud"
                   ,in_stack_fffff7b0,in_stack_fffff7b4,(uint)uVar1 >> 0x10 & 0xff,(uint)bVar2,
                   no_use);
          _applog(7,tmp42,false);
        }
        cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
                     buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                     ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
        set_BC_command_buffer(cmd_buf);
        uVar3 = get_BC_write_command();
        set_BC_write_command(uVar3 & 0xfff0ffff | i << 0x10 | 0x80800000);
      }
      else {
        uVar3 = gBM1393_MISC_CONTROL_reg & 0xffffe0ff;
        gBM1393_MISC_CONTROL_reg = uVar3 | (bauddiv & 0x1f) << 8;
        buf[0] = 'Q';
        buf[1] = '\t';
        buf[2] = '\0';
        buf[3] = '\x18';
        buf._4_2_ = CONCAT11((uchar)(uVar3 >> 0x10),(uchar)(uVar3 >> 0x18));
        buf._4_3_ = CONCAT12((uchar)(gBM1393_MISC_CONTROL_reg >> 8),buf._4_2_);
        buf[7] = (uchar)uVar3;
        buf[8] = CRC5(buf,'@');
        uVar3 = (uint)buf._0_4_ >> 0x18 |
                buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
        uVar4 = (uint)buf._4_4_ >> 0x18 |
                buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
                ((uint)buf._4_4_ >> 0x10 & 0xff) << 8;
        cmd_buf[2] = (uint)buf[8] << 0x18;
        cmd_buf[0] = uVar3;
        cmd_buf[1] = uVar4;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"%s: cmd_buf[0]=0x%x, cmd_buf[1]=0x%x, cmd_buf[2]=0x%x, misc=0x%x\n",
                   "set_baud",uVar3,uVar4,cmd_buf[2],gBM1393_MISC_CONTROL_reg,no_use);
          _applog(5,tmp42,false);
          in_stack_fffff7b0 = uVar3;
          in_stack_fffff7b4 = uVar4;
        }
        set_BC_command_buffer(cmd_buf);
        uVar3 = get_BC_write_command();
        set_BC_write_command(uVar3 & 0xfff0ffff | i << 0x10 | 0x80800000);
      }
    }
  }
  cgsleep_us(CONCAT44(in_stack_fffff7b4,in_stack_fffff7b0));
  uVar3 = get_BC_write_command();
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s: read bc write is 0x%0x\n","set_baud",uVar3);
    _applog(5,tmp42,false);
  }
  set_BC_write_command(bauddiv & 0x3f | uVar3 & 0xffffffc0);
  dev->baud = bauddiv;
  return;
}

