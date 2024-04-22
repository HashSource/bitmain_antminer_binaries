
void set_block_header_version_3(uint32_t value)

{
  FILE *__stream;
  uint32_t value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x5b] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: %s: set BLOCK_HEADER_VERSION is 0x%x\n","zynq.c",0x21e,
              "set_block_header_version_3","set_block_header_version_3",value);
    }
    fclose(__stream);
  }
  get_block_header_version_3();
  return;
}

