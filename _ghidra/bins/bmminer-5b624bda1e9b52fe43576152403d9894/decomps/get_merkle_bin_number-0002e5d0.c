
/* WARNING: Unknown calling convention */

int get_merkle_bin_number(void)

{
  uint uVar1;
  char tmp42 [2048];
  
  uVar1 = axi_fpga_addr[0x45];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: MERKLE_BIN_NUMBER is 0x%x\n","get_merkle_bin_number",
             (uint)(ushort)uVar1);
    _applog(7,tmp42,false);
  }
  return (uint)(ushort)uVar1;
}

