
undefined4 get_ticket_mask(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x8c);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: TICKET_MASK_FPGA is 0x%x\n","znyq7010.c",0x201,DAT_0004cd50,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

