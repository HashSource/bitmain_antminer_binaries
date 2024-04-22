
void set_job_start_address(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x46] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set JOB_START_ADDRESS is 0x%x\n","zynq.c",0x94,
              "set_job_start_address",value);
    }
    fclose(__stream);
  }
  get_job_start_address();
  return;
}

