
undefined4 get_dhash_acc_control(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x100);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: DHASH_ACC_CONTROL is 0x%x\n","znyq7010.c",0x2f6,DAT_0004db2c,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

