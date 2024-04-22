
void set_hash_counting_number(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x90) = param_1;
  if (uVar1 < 6) {
    get_hash_counting_number();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set DHASH_ACC_CONTROL is 0x%x\n","znyq7010.c",0x337,DAT_0004dd60,
            param_1);
  }
  fclose(__stream);
  get_hash_counting_number();
  return;
}

