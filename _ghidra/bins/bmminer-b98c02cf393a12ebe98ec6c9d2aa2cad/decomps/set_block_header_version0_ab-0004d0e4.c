
void set_block_header_version0_ab(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x160) = param_1;
  if (uVar1 < 6) {
    get_block_header_version0_ab();
    return;
  }
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set BLOCK_VERSION_0 is 0x%x\n","znyq7010.c",0x245,
            "set_block_header_version0_ab",param_1);
  }
  fclose(__stream);
  get_block_header_version0_ab();
  return;
}

