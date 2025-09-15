
void set_job_id(undefined4 param_1)

{
  FILE *__stream;
  
  *(undefined4 *)(axi_fpga_addr + 0x124) = param_1;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set JOB_ID is 0x%x\n","znyq7010.c",0x217,param_1);
    }
    fclose(__stream);
  }
  get_job_id();
  return;
}

