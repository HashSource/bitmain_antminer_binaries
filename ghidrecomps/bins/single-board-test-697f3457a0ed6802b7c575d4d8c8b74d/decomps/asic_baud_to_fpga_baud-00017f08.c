
uchar asic_baud_to_fpga_baud(uchar asic_baud)

{
  uchar uVar1;
  uchar asic_baud_local;
  char tmp42 [1024];
  
  switch(asic_baud) {
  case '\0':
    uVar1 = '\x01';
    break;
  case '\x01':
    uVar1 = '\x03';
    break;
  case '\x02':
    uVar1 = '\x05';
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: Don\'t support ASIC baud = %d, error!!!\n","asic_baud_to_fpga_baud",
               (uint)asic_baud);
      _applog(2,tmp42,false);
    }
    uVar1 = '5';
    break;
  case '\x06':
    uVar1 = '\r';
    break;
  case '\x1a':
    uVar1 = '5';
  }
  return uVar1;
}

