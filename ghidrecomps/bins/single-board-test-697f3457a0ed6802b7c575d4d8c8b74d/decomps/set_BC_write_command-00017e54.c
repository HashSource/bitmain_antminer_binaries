
void set_BC_write_command(uint value)

{
  uint uVar1;
  uint value_local;
  char tmp42 [1024];
  uchar i;
  
  i = '\0';
  if ((int)value < 0) {
    do {
      uVar1 = get_BC_write_command();
      if (-1 < (int)uVar1) goto LAB_00017ef4;
      usleep(1000);
      i = i + 1;
    } while (i < 0x65);
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: timeout\n\n","set_BC_write_command");
      _applog(2,tmp42,false);
    }
  }
LAB_00017ef4:
  write_axi_fpga(0x30,value);
  return;
}

