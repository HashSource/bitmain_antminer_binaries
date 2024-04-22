
undefined4 get_BC_command_buffer(undefined4 *param_1)

{
  FILE *__stream;
  undefined4 uVar1;
  
  *param_1 = *(undefined4 *)(axi_fpga_addr + 0xc4);
  param_1[1] = *(undefined4 *)(axi_fpga_addr + 200);
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0xcc);
  param_1[2] = uVar1;
  if (7 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: BC_COMMAND_BUFFER buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x\n",
              "znyq7010.c",0x1b9,*param_1,param_1[1],param_1[2]);
    }
    fclose(__stream);
  }
  return uVar1;
}

