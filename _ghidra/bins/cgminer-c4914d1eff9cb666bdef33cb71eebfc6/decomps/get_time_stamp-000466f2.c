
/* WARNING: Unknown calling convention */

int get_time_stamp(void)

{
  FILE *__stream;
  uint uVar1;
  FILE *pFile;
  int ret;
  
  uVar1 = axi_fpga_addr[0x4d];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: TIME_STAMP is 0x%x\n","zynq.c",0x23a,"get_time_stamp",uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

