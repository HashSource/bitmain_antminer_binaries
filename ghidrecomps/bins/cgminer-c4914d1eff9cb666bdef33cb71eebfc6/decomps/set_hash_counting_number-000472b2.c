
void set_hash_counting_number(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x24] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set DHASH_ACC_CONTROL is 0x%x\n","zynq.c",0x2f9,
              "set_hash_counting_number",value);
    }
    fclose(__stream);
  }
  get_hash_counting_number();
  return;
}

