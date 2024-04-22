
undefined4 znyq7010_axi_Reinit(void)

{
  FILE *pFVar1;
  uint uVar2;
  
  uVar2 = *axi_fpga_addr;
  if ((uVar2 & 0xffff) != 0xc501) {
    if (log_level < 6) goto LAB_0004c54e;
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n"
              ,"znyq7010.c",0x117,DAT_0004c604,uVar2,0xc501);
    }
    fclose(pFVar1);
  }
  if (5 < log_level) {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: axi_fpga_addr data = 0x%x\n","znyq7010.c",0x11a,DAT_0004c604,uVar2);
    }
    fclose(pFVar1);
  }
LAB_0004c54e:
  job_start_address_1 = fpga_mem_addr + 0x200000;
  job_start_address_2 = fpga_mem_addr + 0x210000;
  nonce2_jobid_address = fpga_mem_addr;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  return 0;
}

