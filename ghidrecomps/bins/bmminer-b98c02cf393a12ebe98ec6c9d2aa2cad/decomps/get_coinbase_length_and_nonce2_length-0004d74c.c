
undefined4 get_coinbase_length_and_nonce2_length(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x104);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: COINBASE_AND_NONCE2_LENGTH is 0x%x\n","znyq7010.c",0x2b6,
            DAT_0004d7b8,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

