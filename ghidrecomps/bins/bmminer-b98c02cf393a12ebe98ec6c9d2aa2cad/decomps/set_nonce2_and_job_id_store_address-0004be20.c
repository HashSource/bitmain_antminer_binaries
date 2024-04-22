
void set_nonce2_and_job_id_store_address(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  get_nonce2_and_job_id_store_address();
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x110) = param_1;
  if (uVar1 < 6) {
    get_nonce2_and_job_id_store_address();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set NONCE2_AND_JOBID_STORE_ADDRESS is 0x%x\n","znyq7010.c",0x86,
            DAT_0004be98,param_1);
  }
  fclose(__stream);
  get_nonce2_and_job_id_store_address();
  return;
}

