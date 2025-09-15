
void set_job_length(uint value)

{
  uint value_local;
  char tmp42 [2048];
  
  axi_fpga_addr[0x47] = value;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set JOB_LENGTH is 0x%x\n","set_job_length",value);
    _applog(7,tmp42,false);
  }
  get_job_id();
  return;
}

