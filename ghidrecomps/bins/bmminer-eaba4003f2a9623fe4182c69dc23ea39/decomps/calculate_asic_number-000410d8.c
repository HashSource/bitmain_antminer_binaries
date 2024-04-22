
int calculate_asic_number(uint actual_asic_number)

{
  uint actual_asic_number_local;
  char tmp42 [2048];
  int i;
  
  if (actual_asic_number == 1) {
    i = 1;
  }
  else if (actual_asic_number == 2) {
    i = 2;
  }
  else if ((actual_asic_number < 3) || (4 < actual_asic_number)) {
    if ((actual_asic_number < 5) || (8 < actual_asic_number)) {
      if ((actual_asic_number < 9) || (0x10 < actual_asic_number)) {
        if ((actual_asic_number < 0x11) || (0x20 < actual_asic_number)) {
          if ((actual_asic_number < 0x21) || (0x40 < actual_asic_number)) {
            if ((actual_asic_number < 0x41) || (0x80 < actual_asic_number)) {
              if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"actual_asic_number = %d, but it is error\n",actual_asic_number
                        );
                _applog(7,tmp42,false);
              }
              i = -1;
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

