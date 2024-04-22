
/* WARNING: Unknown calling convention */

int get_bt8d_control(void)

{
  FILE *__stream;
  uint uVar1;
  FILE *pFile;
  int ret;
  
  uVar1 = axi_fpga_addr[0xf];
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: get_bt8d_control is 0x%x\n","zynq.c",0x150,"get_bt8d_control",
              uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

