
int get_BC_command_buffer(uint *buf)

{
  FILE *__stream;
  uint uVar1;
  uint *buf_local;
  FILE *pFile;
  int ret;
  
  *buf = axi_fpga_addr[0x31];
  buf[1] = axi_fpga_addr[0x32];
  uVar1 = axi_fpga_addr[0x33];
  buf[2] = uVar1;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: BC_COMMAND_BUFFER buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x\n",
              "zynq.c",0x164,"get_BC_command_buffer",*buf,buf[1],buf[2]);
    }
    fclose(__stream);
  }
  return uVar1;
}

