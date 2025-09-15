
/* WARNING: Unknown calling convention */

int get_nonce_fifo_interrupt(void)

{
  FILE *__stream;
  uint uVar1;
  FILE *pFile;
  int ret;
  
  uVar1 = axi_fpga_addr[7];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: NONCE_FIFO_INTERRUPT is 0x%x\n","zynq.c",0x2a8,
              "get_nonce_fifo_interrupt",uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

