
undefined4 get_nonce_fifo_interrupt(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x1c);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: NONCE_FIFO_INTERRUPT is 0x%x\n","znyq7010.c",0x2e7,DAT_0004da4c,
            uVar1);
  }
  fclose(__stream);
  return uVar1;
}

