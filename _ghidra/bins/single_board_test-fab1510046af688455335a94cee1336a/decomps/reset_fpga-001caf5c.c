
/* WARNING: Unknown calling convention */

void reset_fpga(uint32_t time)

{
  fpga_write(0x12,time | 0x80808000);
  current_job_start_address = job_start_address_1;
  _set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  return;
}

