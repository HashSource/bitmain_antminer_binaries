
uchar set_pic_iic(uint data)

{
  uint uVar1;
  uint in_stack_fffff7e0;
  undefined4 in_stack_fffff7e4;
  uint data_local;
  char tmp42 [2048];
  uchar ret_data;
  uint ret;
  
  axi_fpga_addr[0xc] = data & 0x7fffffff;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    in_stack_fffff7e0 = data & 0x7fffffff;
    snprintf(tmp42,0x800,"%s: set IIC_COMMAND is 0x%x\n","set_pic_iic");
    _applog(7,tmp42,false);
  }
  while( true ) {
    uVar1 = get_pic_iic();
    if ((int)uVar1 < 0) break;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: waiting write pic iic\n","set_pic_iic");
      _applog(7,tmp42,false);
    }
    cgsleep_us(CONCAT44(in_stack_fffff7e4,in_stack_fffff7e0));
  }
  return (uchar)uVar1;
}

