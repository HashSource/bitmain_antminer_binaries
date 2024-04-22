
undefined4 get_pic_iic(void)

{
  undefined4 uVar1;
  char acStack_808 [2048];
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x30);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_808,0x800,"%s: IIC_COMMAND is 0x%x\n",DAT_0002e540,uVar1);
    _applog(7,acStack_808,0);
  }
  return uVar1;
}

