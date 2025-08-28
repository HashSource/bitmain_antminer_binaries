
/* WARNING: Unknown calling convention */

int get_BC_command_buffer(uint *buf)

{
  _Bool _Var1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char tmp42 [2048];
  
  puVar2 = axi_fpga_addr;
  _Var1 = opt_debug;
  uVar3 = axi_fpga_addr[0x31];
  *buf = uVar3;
  uVar4 = puVar2[0x32];
  buf[1] = uVar4;
  uVar5 = puVar2[0x33];
  buf[2] = uVar5;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: BC_COMMAND_BUFFER buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x\n",
             "get_BC_command_buffer",uVar3,uVar4,uVar5);
    _applog(7,tmp42,false);
  }
  return uVar5;
}

