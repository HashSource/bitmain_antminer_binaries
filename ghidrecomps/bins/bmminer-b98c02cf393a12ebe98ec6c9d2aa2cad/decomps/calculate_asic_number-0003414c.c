
int calculate_asic_number(int param_1)

{
  char acStack_808 [2056];
  
  if ((param_1 != 1) && (param_1 != 2)) {
    if (param_1 - 3U < 2) {
      param_1 = 4;
    }
    else if (param_1 - 5U < 4) {
      param_1 = 8;
    }
    else if (param_1 - 9U < 8) {
      param_1 = 0x10;
    }
    else if (param_1 - 0x11U < 0x10) {
      param_1 = 0x20;
    }
    else if (param_1 - 0x21U < 0x20) {
      param_1 = 0x40;
    }
    else if (param_1 - 0x41U < 0x40) {
      param_1 = 0x80;
    }
    else if ((opt_debug == '\0') ||
            (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7)))) {
      param_1 = -1;
    }
    else {
      snprintf(acStack_808,0x800,"actual_asic_number = %d, but it is error\n",param_1);
      _applog(7,acStack_808,0);
      param_1 = -1;
    }
  }
  return param_1;
}

