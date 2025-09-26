
/* WARNING: Unknown calling convention */

int32_t dhash_init(void)

{
  uint32_t value;
  uint32_t *puVar1;
  uint32_t tmp;
  sysinfo si;
  
  nonce2_jobid_address = get_fpga_map_mem_addr();
  job_start_address_2 = nonce2_jobid_address + 0x84000;
  puVar1 = nonce2_jobid_address + 0x80000;
  job_start_address_1 = puVar1;
  sysinfo((sysinfo *)&si);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      if (si.totalram < 0xbebc201) {
        value = 0x7000000;
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0x7000000;
      }
      else {
        value = 0xf000000;
        PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      }
    }
    else {
      value = 0x1f000000;
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
    }
  }
  else {
    value = 0x3f000000;
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
  }
  current_job_start_address = puVar1;
  _set_nonce2_and_job_id_store_address(value);
  fpga_write(0x29,PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  fpga_read(0x29,&tmp);
  disable_bypass_mode();
  enable_sync_header();
  return 0;
}

