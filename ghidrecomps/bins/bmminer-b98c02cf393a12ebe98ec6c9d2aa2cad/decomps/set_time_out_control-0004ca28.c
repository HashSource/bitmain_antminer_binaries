
void set_time_out_control(undefined4 param_1)

{
  uint uVar1;
  FILE *__stream;
  
  uVar1 = log_level;
  *(undefined4 *)(axi_fpga_addr + 0x88) = param_1;
  if (uVar1 < 6) {
    get_time_out_control();
    return;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: set FAN_CONTROL is 0x%x\n","znyq7010.c",0x1ac,DAT_0004ca98,param_1);
  }
  fclose(__stream);
  get_time_out_control();
  return;
}

