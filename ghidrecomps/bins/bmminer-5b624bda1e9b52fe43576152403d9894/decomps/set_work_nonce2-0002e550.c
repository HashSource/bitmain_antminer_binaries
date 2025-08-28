
/* WARNING: Unknown calling convention */

void set_work_nonce2(uint *value)

{
  _Bool _Var1;
  uint *puVar2;
  uint buf [2];
  char tmp42 [2048];
  
  puVar2 = axi_fpga_addr;
  buf[0] = 0;
  axi_fpga_addr[0x42] = *value;
  _Var1 = opt_debug;
  buf[1] = 0;
  puVar2[0x43] = value[1];
  if ((_Var1 != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set WORK_NONCE_2 value[0]: 0x%x, value[1]: 0x%x\n","set_work_nonce2",
             *value,value[1]);
    _applog(7,tmp42,false);
  }
  get_work_nonce2(buf);
  return;
}

