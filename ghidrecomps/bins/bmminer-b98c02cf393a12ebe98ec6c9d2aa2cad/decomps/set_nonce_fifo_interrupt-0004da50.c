
void set_nonce_fifo_interrupt(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x1c) = param_1;
  if (uVar1 < 6) {
    get_nonce_fifo_interrupt();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set NONCE_FIFO_INTERRUPT is 0x%x\n","znyq7010.c",0x2ee,DAT_0004dabc,
            param_1);
  }
  fclose(__stream);
  get_nonce_fifo_interrupt();
  return;
}

