
/* WARNING: Unknown calling convention */

void set_pre_header_hash(uint *value)

{
  _Bool _Var1;
  uint *puVar2;
  char tmp42 [2048];
  
  puVar2 = axi_fpga_addr;
  axi_fpga_addr[0x50] = *value;
  _Var1 = opt_debug;
  puVar2[0x51] = value[1];
  puVar2[0x52] = value[2];
  puVar2[0x53] = value[3];
  puVar2[0x54] = value[4];
  puVar2[0x55] = value[5];
  puVar2[0x56] = value[6];
  puVar2[0x57] = value[7];
  if ((_Var1 != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,
             "%s: set PRE_HEADER_HASH value[0]: 0x%x, value[1]: 0x%x, value[2]: 0x%x, value[3]: 0x%x, value[4]: 0x%x, value[5]: 0x%x, value[6]: 0x%x, value[7]: 0x%x\n"
             ,"set_pre_header_hash",*value,value[1],value[2],value[3],value[4],value[5],value[6],
             value[7]);
    _applog(7,tmp42,false);
  }
  return;
}

