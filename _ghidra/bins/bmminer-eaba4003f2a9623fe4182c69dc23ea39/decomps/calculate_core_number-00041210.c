
int calculate_core_number(uint actual_core_number)

{
  uint actual_core_number_local;
  char tmp42 [2048];
  int i;
  
  if (actual_core_number == 1) {
    i = 1;
  }
  else if (actual_core_number == 2) {
    i = 2;
  }
  else if ((actual_core_number < 3) || (4 < actual_core_number)) {
    if ((actual_core_number < 5) || (8 < actual_core_number)) {
      if ((actual_core_number < 9) || (0x10 < actual_core_number)) {
        if ((actual_core_number < 0x11) || (0x20 < actual_core_number)) {
          if ((actual_core_number < 0x21) || (0x40 < actual_core_number)) {
            if ((actual_core_number < 0x41) || (0x80 < actual_core_number)) {
              if ((actual_core_number < 0x81) || (0xd0 < actual_core_number)) {
                if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
                  snprintf(tmp42,0x800,"actual_core_number = %d, but it is error\n",
                           actual_core_number);
                  _applog(7,tmp42,false);
                }
                i = -1;
              }
              else {
                i = 0x100;
              }
            }
            else {
              i = 0x80;
            }
          }
          else {
            i = 0x40;
          }
        }
        else {
          i = 0x20;
        }
      }
      else {
        i = 0x10;
      }
    }
    else {
      i = 8;
    }
  }
  else {
    i = 4;
  }
  return i;
}

