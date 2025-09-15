
/* WARNING: Unknown calling convention */

uint get_pic_iic(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0xc];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: IIC_COMMAND is 0x%x\n","get_pic_iic",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

