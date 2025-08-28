
void set_BC_write_command(uint value)

{
  int iVar1;
  uint value_local;
  char tmp42 [2048];
  char logstr [1024];
  int wait_count;
  
  wait_count = 0;
  axi_fpga_addr[0x30] = value;
  if ((int)value < 0) {
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) {
        return;
      }
      cgsleep_ms(1);
      wait_count = wait_count + 1;
    } while (wait_count < 0xbb9);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      builtin_strncpy(tmp42,"Error: set_BC_write_command wait buffer ready timeout!\n",0x38);
      _applog(5,tmp42,false);
    }
  }
  else {
    get_BC_write_command();
  }
  return;
}

