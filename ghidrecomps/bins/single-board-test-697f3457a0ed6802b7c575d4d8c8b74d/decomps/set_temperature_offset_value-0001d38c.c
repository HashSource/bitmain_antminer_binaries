
void set_temperature_offset_value(uint which_i2c,uchar which_chain,uchar *value)

{
  uchar *value_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","set_temperature_offset_value");
    _applog(2,tmp42,false);
  }
  write_temperature_offset_PIC16F1704(which_i2c,which_chain,value);
  usleep(100000);
  return;
}

