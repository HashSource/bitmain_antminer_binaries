
/* WARNING: Unknown calling convention */

int get_coinbase_length_and_nonce2_length(void)

{
  FILE *__stream;
  uint uVar1;
  FILE *pFile;
  int ret;
  
  uVar1 = axi_fpga_addr[0x41];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: COINBASE_AND_NONCE2_LENGTH is 0x%x\n","zynq.c",0x262,
              "get_coinbase_length_and_nonce2_length",uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

