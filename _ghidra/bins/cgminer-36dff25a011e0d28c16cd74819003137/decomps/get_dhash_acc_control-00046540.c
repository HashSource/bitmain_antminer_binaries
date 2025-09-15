
/* WARNING: Unknown calling convention */

int get_dhash_acc_control(void)

{
  FILE *__stream;
  uint uVar1;
  FILE *pFile;
  int ret;
  
  uVar1 = axi_fpga_addr[0x40];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: DHASH_ACC_CONTROL is 0x%x\n","zynq.c",0x2a2,
              "get_dhash_acc_control",uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

