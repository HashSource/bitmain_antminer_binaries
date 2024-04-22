
undefined4 get_block_header_version1_ab(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x164);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: BLOCK_VERSION_1 is 0x%x\n","znyq7010.c",0x24d,DAT_0004d1c4,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

