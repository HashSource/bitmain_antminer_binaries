
void set_nonce_fifo_interrupt(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[7] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set NONCE_FIFO_INTERRUPT is 0x%x\n","zynq.c",0x2af,
              "set_nonce_fifo_interrupt",value);
    }
    fclose(__stream);
  }
  get_nonce_fifo_interrupt();
  return;
}

