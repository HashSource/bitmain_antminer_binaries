
void set_pre_header_hash(uint *value)

{
  FILE *__stream;
  uint *value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x50] = *value;
  axi_fpga_addr[0x51] = value[1];
  axi_fpga_addr[0x52] = value[2];
  axi_fpga_addr[0x53] = value[3];
  axi_fpga_addr[0x54] = value[4];
  axi_fpga_addr[0x55] = value[5];
  axi_fpga_addr[0x56] = value[6];
  axi_fpga_addr[0x57] = value[7];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,
              "%s:%d:%s: set PRE_HEADER_HASH value[0]: 0x%x, value[1]: 0x%x, value[2]: 0x%x, value[3]: 0x%x, value[4]: 0x%x, value[5]: 0x%x, value[6]: 0x%x, value[7]: 0x%x\n"
              ,"zynq.c",0x26f,"set_pre_header_hash",*value,value[1],value[2],value[3],value[4],
              value[5],value[6],value[7]);
    }
    fclose(__stream);
  }
  return;
}

