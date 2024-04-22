
/* WARNING: Unknown calling convention */

int get_coinbase_length_and_nonce2_length(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0x41];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: COINBASE_AND_NONCE2_LENGTH is 0x%x\n",
             "get_coinbase_length_and_nonce2_length",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

