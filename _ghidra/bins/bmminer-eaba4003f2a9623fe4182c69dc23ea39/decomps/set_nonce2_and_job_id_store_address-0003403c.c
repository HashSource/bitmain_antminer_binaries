
void set_nonce2_and_job_id_store_address(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  get_nonce2_and_job_id_store_address();
  axi_fpga_addr[0x44] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set NONCE2_AND_JOBID_STORE_ADDRESS is 0x%x\n",
             "set_nonce2_and_job_id_store_address",value);
    _applog(7,tmp42,false);
  }
  get_nonce2_and_job_id_store_address();
  return;
}

