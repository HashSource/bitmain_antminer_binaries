
int get_work_nonce2(uint *buf)

{
  FILE *__stream;
  uint *buf_local;
  FILE *pFile;
  int ret;
  
  *buf = axi_fpga_addr[0x42];
  buf[1] = axi_fpga_addr[0x43];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: WORK_NONCE_2 buf[0]: 0x%x, buf[1]: 0x%x\n","zynq.c",0x287,
              "get_work_nonce2",*buf,buf[1]);
    }
    fclose(__stream);
  }
  return -1;
}

