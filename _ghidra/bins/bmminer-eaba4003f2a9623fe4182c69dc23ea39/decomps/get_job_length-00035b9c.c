
/* WARNING: Unknown calling convention */

int get_job_length(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0x47];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: JOB_LENGTH is 0x%x\n","get_job_length",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

