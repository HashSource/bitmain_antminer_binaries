
/* WARNING: Unknown calling convention */

void set_nonce2_and_job_id_store_address(uint value)

{
  _Bool _Var1;
  
  _Var1 = opt_debug;
  axi_fpga_addr[0x44] = value;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    set_nonce2_and_job_id_store_address(value);
    return;
  }
  return;
}

