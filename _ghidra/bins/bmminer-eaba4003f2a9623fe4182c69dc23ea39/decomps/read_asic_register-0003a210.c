
void read_asic_register(uchar chain,uchar mode,uchar chip_addr,uchar reg_addr)

{
  uint uVar1;
  int iVar2;
  uchar reg_addr_local;
  uchar chip_addr_local;
  uchar mode_local;
  uchar chain_local;
  char tmp42 [2048];
  char logstr [1024];
  uint cmd_buf [3];
  uchar buf_vil [12];
  uchar buf [5];
  uint value;
  uint ret;
  int wait_count;
  
  buf[3] = '\0';
  buf[4] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  wait_count = 0;
  if (opt_multi_version == 0) {
    buf[0] = '\x02';
    if (mode != '\0') {
      buf[0] = 0x82;
    }
    buf[1] = chip_addr;
    buf[2] = reg_addr;
    buf[3] = CRC5(buf,'\x1b');
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
               "read_asic_register",(uint)buf[0],(uint)buf[1],(uint)buf[2],(uint)buf[3]);
      _applog(7,tmp42,false);
    }
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    set_BC_command_buffer(cmd_buf);
    uVar1 = get_BC_write_command();
    set_BC_write_command(uVar1 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  else {
    buf[0] = 'B';
    if (mode != '\0') {
      buf[0] = 'R';
    }
    buf[1] = '\x05';
    buf[2] = chip_addr;
    buf[3] = reg_addr;
    buf[4] = CRC5(buf,' ');
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s:VIL buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x",
               "read_asic_register",(uint)buf[0],(uint)buf[1],(uint)buf[2],(uint)buf[3],(uint)buf[4]
              );
      _applog(7,tmp42,false);
    }
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    cmd_buf[1] = (uint)buf[4] << 0x18;
    do {
      iVar2 = get_BC_write_command();
      if (-1 < iVar2) goto LAB_0003a564;
      cgsleep_ms(1);
      wait_count = wait_count + 1;
    } while (wait_count < 0xbb9);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      iVar2 = get_hash_on_plug();
      snprintf(tmp42,0x800,"Error: clement debug: wait BC ready timeout, PLUG ON=0x%08x..\n",iVar2);
      _applog(5,tmp42,false);
    }
LAB_0003a564:
    set_BC_command_buffer(cmd_buf);
    uVar1 = get_BC_write_command();
    set_BC_write_command(uVar1 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  return;
}

