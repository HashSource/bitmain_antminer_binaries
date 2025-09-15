
/* WARNING: Unknown calling convention */

int get_nonce_fifo_interrupt(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[7];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: NONCE_FIFO_INTERRUPT is 0x%x\n","get_nonce_fifo_interrupt",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

