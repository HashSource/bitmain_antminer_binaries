
void set_coinbase_length_and_nonce2_length(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x104) = param_1;
  if (uVar1 < 6) {
    get_coinbase_length_and_nonce2_length();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set COINBASE_AND_NONCE2_LENGTH is 0x%x\n","znyq7010.c",0x2bd,
            DAT_0004d82c,param_1);
  }
  fclose(__stream);
  get_coinbase_length_and_nonce2_length();
  return;
}

