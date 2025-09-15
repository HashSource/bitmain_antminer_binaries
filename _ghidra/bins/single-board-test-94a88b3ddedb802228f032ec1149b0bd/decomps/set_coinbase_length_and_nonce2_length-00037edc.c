
void set_coinbase_length_and_nonce2_length(undefined4 param_1)

{
  FILE *__stream;
  
  *(undefined4 *)(axi_fpga_addr + 0x104) = param_1;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: set COINBASE_AND_NONCE2_LENGTH is 0x%x\n","znyq7010.c",0x281,param_1)
      ;
    }
    fclose(__stream);
  }
  get_coinbase_length_and_nonce2_length();
  return;
}

