
void set_job_start_address(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x118) = param_1;
  if (uVar1 < 6) {
    get_job_start_address();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set JOB_START_ADDRESS is 0x%x\n","znyq7010.c",0x95,DAT_0004bf74,
            param_1);
  }
  fclose(__stream);
  get_job_start_address();
  return;
}

