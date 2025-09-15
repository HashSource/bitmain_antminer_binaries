
uint get_fan_speed(byte *param_1,uint *param_2)

{
  FILE *__stream;
  uint uVar1;
  
  uVar1 = *(uint *)(axi_fpga_addr + 4);
  *param_2 = uVar1 & 0xff;
  *param_1 = (byte)(uVar1 >> 8) & 7;
  if ((*param_2 != 0) && (5 < log_level)) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: fan_id is 0x%x, fan_speed is 0x%x\n","znyq7010.c",0x17c,
              (uint)*param_1,*param_2);
    }
    fclose(__stream);
  }
  return uVar1;
}

