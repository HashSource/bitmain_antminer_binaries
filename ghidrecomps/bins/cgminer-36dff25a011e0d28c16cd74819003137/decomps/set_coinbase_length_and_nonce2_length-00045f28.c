
void set_coinbase_length_and_nonce2_length(uint value)

{
  FILE *__stream;
  uint value_local;
  FILE *pFile;
  
  axi_fpga_addr[0x41] = value;
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set COINBASE_AND_NONCE2_LENGTH is 0x%x\n","zynq.c",0x269,
              "set_coinbase_length_and_nonce2_length",value);
    }
    fclose(__stream);
  }
  get_coinbase_length_and_nonce2_length();
  return;
}

