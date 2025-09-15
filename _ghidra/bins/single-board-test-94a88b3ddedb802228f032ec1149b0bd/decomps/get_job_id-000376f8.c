
undefined4 get_job_id(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x124);
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: JOB_ID is 0x%x\n","znyq7010.c",0x210,uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

