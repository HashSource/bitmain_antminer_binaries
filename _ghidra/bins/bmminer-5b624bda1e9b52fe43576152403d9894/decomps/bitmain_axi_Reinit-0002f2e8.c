
/* WARNING: Unknown calling convention */

int bitmain_axi_Reinit(void)

{
  uint uVar1;
  char logstr [256];
  
  uVar1 = *axi_fpga_addr;
  if ((undefined1 *)(uVar1 & 0xffff) != &LAB_0000c500_1) {
    sprintf(logstr,"data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",uVar1);
    writeInitLogFile(logstr);
  }
  sprintf(logstr,"axi_fpga_addr data = 0x%x\n",uVar1);
  writeInitLogFile(logstr);
  job_start_address_1 = fpga_mem_addr + 0x80000;
  job_start_address_2 = fpga_mem_addr + 0x84000;
  nonce2_jobid_address = fpga_mem_addr;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  return 0;
}

