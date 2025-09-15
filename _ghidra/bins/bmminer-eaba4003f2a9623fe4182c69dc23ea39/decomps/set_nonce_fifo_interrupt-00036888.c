
void set_nonce_fifo_interrupt(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[7] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set NONCE_FIFO_INTERRUPT is 0x%x\n","set_nonce_fifo_interrupt",value);
    _applog(7,tmp42,false);
  }
  get_nonce_fifo_interrupt();
  return;
}

