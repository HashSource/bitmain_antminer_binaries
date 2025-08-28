
undefined4 get_QN_write_data_command(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x80);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,"a+");
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: QN_WRITE_DATA_COMMAND is 0x%x\n","znyq7010.c",0xa9,
            "get_QN_write_data_command",uVar1);
  }
  fclose(__stream);
  return uVar1;
}

