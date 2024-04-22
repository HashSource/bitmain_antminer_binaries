
void set_nonce2_and_job_id_store_address(undefined4 param_1)

{
  FILE *__stream;
  
  get_nonce2_and_job_id_store_address();
  *(undefined4 *)(axi_fpga_addr + 0x110) = param_1;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set NONCE2_AND_JOBID_STORE_ADDRESS is 0x%x\n","znyq7010.c",0x86,
              param_1);
    }
    fclose(__stream);
  }
  get_nonce2_and_job_id_store_address();
  return;
}

