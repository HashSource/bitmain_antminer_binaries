
/* WARNING: Unknown calling convention */

uchar set_pic_iic(uint data)

{
  _Bool _Var1;
  uint uVar2;
  char tmp42 [2048];
  
  _Var1 = opt_debug;
  axi_fpga_addr[0xc] = data & 0x7fffffff;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: set IIC_COMMAND is 0x%x\n","set_pic_iic",data & 0x7fffffff);
    _applog(7,tmp42,false);
  }
  while (uVar2 = get_pic_iic(), -1 < (int)uVar2) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: waiting write pic iic\n","set_pic_iic");
      _applog(7,tmp42,false);
    }
    cgsleep_us(1000);
  }
  return (uchar)uVar2;
}

