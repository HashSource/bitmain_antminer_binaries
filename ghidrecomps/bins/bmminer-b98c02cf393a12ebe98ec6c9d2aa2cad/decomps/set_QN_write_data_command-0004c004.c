
void set_QN_write_data_command(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x80) = param_1;
  if (uVar1 < 6) {
    get_QN_write_data_command();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set QN_WRITE_DATA_COMMAND is 0x%x\n","znyq7010.c",0xb0,DAT_0004c070,
            param_1);
  }
  fclose(__stream);
  get_QN_write_data_command();
  return;
}

