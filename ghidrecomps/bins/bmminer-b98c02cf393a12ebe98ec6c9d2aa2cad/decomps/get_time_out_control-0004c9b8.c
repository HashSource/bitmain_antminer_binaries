
undefined4 get_time_out_control(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x88);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: TIME_OUT_CONTROL is 0x%x\n","znyq7010.c",0x1a5,DAT_0004ca24,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

