
undefined4 get_work_nonce2(undefined4 *param_1)

{
  FILE *__stream;
  
  *param_1 = *(undefined4 *)(axi_fpga_addr + 0x108);
  param_1[1] = *(undefined4 *)(axi_fpga_addr + 0x10c);
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: WORK_NONCE_2 buf[0]: 0x%x, buf[1]: 0x%x\n","znyq7010.c",0x28a,
              *param_1,param_1[1]);
    }
    fclose(__stream);
  }
  return 0xffffffff;
}

