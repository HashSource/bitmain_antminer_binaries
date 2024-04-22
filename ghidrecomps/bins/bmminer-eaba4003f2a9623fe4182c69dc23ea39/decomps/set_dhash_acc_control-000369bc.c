
void set_dhash_acc_control(uint value)

{
  uint uVar1;
  uint value_local;
  char tmp42 [2048];
  int a;
  
  a = 10;
  axi_fpga_addr[0x40] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set DHASH_ACC_CONTROL is 0x%x\n","set_dhash_acc_control",value);
    _applog(7,tmp42,false);
  }
  while ((0 < a && (uVar1 = get_dhash_acc_control(), (value | 0x80) != (uVar1 | 0x80)))) {
    axi_fpga_addr[0x40] = value;
    a = a + -1;
    cgsleep_ms(2);
  }
  if (((a == 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"%s set DHASH_ACC_CONTROL failed!","set_dhash_acc_control");
    _applog(7,tmp42,false);
  }
  return;
}

