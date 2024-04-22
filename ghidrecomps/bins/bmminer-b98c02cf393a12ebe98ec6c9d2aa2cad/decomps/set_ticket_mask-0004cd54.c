
void set_ticket_mask(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x8c) = param_1;
  if (uVar1 < 6) {
    get_ticket_mask();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set TICKET_MASK_FPGA is 0x%x\n","znyq7010.c",0x208,DAT_0004cdc4,
            param_1);
  }
  fclose(__stream);
  get_ticket_mask();
  return;
}

