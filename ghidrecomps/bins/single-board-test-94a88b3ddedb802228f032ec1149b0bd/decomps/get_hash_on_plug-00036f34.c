
undefined4 get_hash_on_plug(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 8);
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: HASH_ON_PLUG is 0x%x\n","znyq7010.c",0x154,uVar1);
    }
    fclose(__stream);
  }
  return uVar1;
}

