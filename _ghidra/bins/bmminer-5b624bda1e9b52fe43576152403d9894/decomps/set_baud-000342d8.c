
/* WARNING: Unknown calling convention */

void set_baud(uchar bauddiv,int no_use)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if ((uint)dev->baud == (uint)bauddiv) {
    if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: the setting bauddiv(%d) is the same as before\n","set_baud",
               (uint)dev->baud);
      _applog(7,tmp42,false);
    }
  }
  else {
    uVar5 = bauddiv & 0x1f;
    iVar7 = 0;
    uVar6 = uVar5 << 8 | 0x200000;
    while( true ) {
      if (dev->chain_exist[iVar7] == 1) {
        if (opt_multi_version == 0) {
          buf[2] = (uchar)uVar5;
          buf[0] = 0x86;
          buf[1] = '\x10';
          bVar1 = CRC5(buf,'\x1b');
          uVar2 = (uint)bVar1;
          buf[3] = bVar1;
          if ((opt_debug == false) ||
             (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7)))) {
            uVar4 = 0x86100000;
            uVar3 = uVar5;
          }
          else {
            snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                     "set_baud",0x86,0x10,uVar5,uVar2);
            _applog(7,tmp42,false);
            uVar2 = (uint)buf._0_4_ >> 0x18;
            uVar4 = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10;
            uVar3 = (uint)buf._0_4_ >> 0x10 & 0xff;
          }
          cmd_buf[0] = uVar4 | uVar2 | uVar3 << 8;
        }
        else {
          buf[6] = (uchar)uVar5;
          buf[4] = '\0';
          buf[5] = ' ';
          buf[7] = '\0';
          buf[0] = 'X';
          buf[1] = '\t';
          buf[2] = '\0';
          buf[3] = '\x1c';
          buf[8] = CRC5(buf,'@');
          cmd_buf[2] = (uint)buf[8] << 0x18;
          cmd_buf[0] = 0x5809001c;
          cmd_buf[1] = uVar6;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: cmd_buf[0]=0x%x, cmd_buf[1]=0x%x, cmd_buf[2]=0x%x\n",
                     "set_baud",0x5809001c,uVar6,cmd_buf[2]);
            _applog(7,tmp42,false);
          }
        }
        set_BC_command_buffer(cmd_buf);
        uVar2 = get_BC_write_command();
        set_BC_write_command(uVar2 & 0xfff0ffff | iVar7 << 0x10 | 0x80800000U);
      }
      if (iVar7 == 0xf) break;
      iVar7 = iVar7 + 1;
    }
    cgsleep_us(50000);
    uVar6 = get_BC_write_command();
    set_BC_write_command(uVar6 & 0xffffffe0 | uVar5);
    dev->baud = bauddiv;
  }
  return;
}

