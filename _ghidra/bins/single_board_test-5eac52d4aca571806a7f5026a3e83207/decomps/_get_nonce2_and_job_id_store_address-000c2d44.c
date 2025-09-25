
/* WARNING: Unknown calling convention */

uint32_t _get_nonce2_and_job_id_store_address(void)

{
  uint32_t val;
  
  fpga_read(0x27,&val);
  return val;
}

