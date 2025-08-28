
/* WARNING: Unknown calling convention */

void set_dhash_acc_control(uint value)

{
  _Bool _Var1;
  uint uVar2;
  int iVar3;
  char tmp42 [2048];
  
  _Var1 = opt_debug;
  axi_fpga_addr[0x40] = value;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set DHASH_ACC_CONTROL is 0x%x\n","set_dhash_acc_control",value);
    _applog(7,tmp42,false);
  }
  iVar3 = 10;
  do {
    uVar2 = get_dhash_acc_control();
    if ((value | 0x80) == (uVar2 | 0x80)) {
      return;
    }
    axi_fpga_addr[0x40] = value;
    cgsleep_ms(2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s set DHASH_ACC_CONTROL failed!","set_dhash_acc_control");
    _applog(7,tmp42,false);
  }
  return;
}

