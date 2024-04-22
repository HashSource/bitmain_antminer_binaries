
void set_job_id(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x124) = param_1;
  if (uVar1 < 6) {
    get_job_id();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set JOB_ID is 0x%x\n","znyq7010.c",0x217,DAT_0004cea8,param_1);
  }
  fclose(__stream);
  get_job_id();
  return;
}

