
void set_job_start_address(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x46] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set JOB_START_ADDRESS is 0x%x\n","set_job_start_address",value);
    _applog(7,tmp42,false);
  }
  get_job_start_address();
  return;
}

