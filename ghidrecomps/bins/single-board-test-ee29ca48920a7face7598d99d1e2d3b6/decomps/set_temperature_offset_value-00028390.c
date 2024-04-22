
void set_temperature_offset_value(undefined4 param_1,undefined param_2,undefined4 param_3)

{
  char acStack_408 [1024];
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_408,0x400,"--- %s\n","set_temperature_offset_value");
    _applog(2,acStack_408,0);
  }
  write_temperature_offset_PIC16F1704(param_1,param_2,param_3);
  usleep(100000);
  return;
}

