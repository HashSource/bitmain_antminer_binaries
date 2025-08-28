
uint set_pic_iic(uint param_1)

{
  uint uVar1;
  FILE *__stream;
  char acStack_820 [2052];
  
  uVar1 = log_level;
  param_1 = param_1 & 0x7fffffff;
  *(uint *)(axi_fpga_addr + 0x30) = param_1;
  if (7 < uVar1) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: fpga write, addr:value ==> 0x%08x:0x%08x\n","driver-btm-c5.c",
              0x4e3,"set_pic_iic",0xc,param_1);
    }
    fclose(__stream);
  }
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_820,0x800,"%s: set IIC_COMMAND is 0x%x\n","set_pic_iic",param_1);
    _applog(7,acStack_820,0);
  }
  while (uVar1 = get_pic_iic(), -1 < (int)uVar1) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_820,0x800,"%s: waiting write pic iic\n","set_pic_iic");
      _applog(7,acStack_820,0);
    }
    cgsleep_us(1000,0);
  }
  return uVar1 & 0xff;
}

