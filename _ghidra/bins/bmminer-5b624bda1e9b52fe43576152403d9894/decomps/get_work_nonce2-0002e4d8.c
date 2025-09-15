
/* WARNING: Unknown calling convention */

int get_work_nonce2(uint *buf)

{
  _Bool _Var1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  char tmp42 [2048];
  
  puVar2 = axi_fpga_addr;
  _Var1 = opt_debug;
  uVar3 = axi_fpga_addr[0x42];
  *buf = uVar3;
  uVar4 = puVar2[0x43];
  buf[1] = uVar4;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: WORK_NONCE_2 buf[0]: 0x%x, buf[1]: 0x%x\n","get_work_nonce2",uVar3,
             uVar4);
    _applog(7,tmp42,false);
  }
  return -1;
}

