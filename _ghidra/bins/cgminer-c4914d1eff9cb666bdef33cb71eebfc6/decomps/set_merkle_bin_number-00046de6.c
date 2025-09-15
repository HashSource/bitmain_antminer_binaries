
void set_merkle_bin_number(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x45] = value & 0xffff;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set MERKLE_BIN_NUMBER is 0x%x\n","zynq.c",0x2a0,
              "set_merkle_bin_number",value & 0xffff);
    }
    fclose(__stream);
  }
  get_merkle_bin_number();
  return;
}

