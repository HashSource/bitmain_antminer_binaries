
/* WARNING: Unknown calling convention */

int get_bt8d_control(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0xf];
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s: get_bt8d_control is 0x%x\n","get_bt8d_control",uVar1);
    _applog(5,tmp42,false);
  }
  return uVar1;
}

