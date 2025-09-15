
void set_job_length(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x47] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set JOB_LENGTH is 0x%x\n","zynq.c",0x1e7,"set_job_length",value);
    }
    fclose(__stream);
  }
  get_job_id();
  return;
}

