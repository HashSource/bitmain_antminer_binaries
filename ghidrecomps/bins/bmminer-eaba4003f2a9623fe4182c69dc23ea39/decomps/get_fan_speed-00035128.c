
int get_fan_speed(uchar *fan_id,uint *fan_speed)

{
  uint uVar1;
  uint *fan_speed_local;
  uchar *fan_id_local;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[1];
  *fan_speed = uVar1 & 0xff;
  *fan_id = (byte)(uVar1 >> 8) & 7;
  if (((*fan_speed != 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    snprintf(tmp42,0x800,"%s: fan_id is 0x%x, fan_speed is 0x%x\n","get_fan_speed",(uint)*fan_id,
             *fan_speed);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

