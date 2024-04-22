
/* WARNING: Unknown calling convention */

int bitmain_axi_Reinit(void)

{
  uint uVar1;
  char tmp42 [2048];
  char logstr [1024];
  uint data;
  int ret;
  
  uVar1 = *axi_fpga_addr;
  if (((uVar1 & 0xffff) != 0xc501) && (((use_syslog || (opt_log_output)) || (4 < opt_log_level)))) {
    snprintf(tmp42,0x800,"data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",uVar1
             ,0xc501);
    _applog(5,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"axi_fpga_addr data = 0x%x\n",uVar1);
    _applog(5,tmp42,false);
  }
  nonce2_jobid_address = fpga_mem_addr;
  job_start_address_1 = fpga_mem_addr + 0x80000;
  job_start_address_2 = fpga_mem_addr + 0x84000;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  return 0;
}

