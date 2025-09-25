
/* WARNING: Unknown calling convention */

void _set_nonce2_and_job_id_store_address(uint32_t value)

{
  uint32_t temp;
  
  fpga_read(0x27,&temp);
  fpga_write(0x27,value);
  fpga_read(0x27,&temp);
  return;
}

