
void set_nonce2_and_job_id_store_address(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  get_nonce2_and_job_id_store_address();
  axi_fpga_addr[0x44] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set NONCE2_AND_JOBID_STORE_ADDRESS is 0x%x\n","zynq.c",0x9a,
              "set_nonce2_and_job_id_store_address",value);
    }
    fclose(__stream);
  }
  get_nonce2_and_job_id_store_address();
  return;
}

