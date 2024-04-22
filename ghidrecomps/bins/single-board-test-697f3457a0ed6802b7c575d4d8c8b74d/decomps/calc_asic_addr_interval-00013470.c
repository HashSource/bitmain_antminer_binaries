
int calc_asic_addr_interval(int actual_asic_number)

{
  int iVar1;
  int actual_asic_number_local;
  char tmp42 [1024];
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
              if ((opt_debug) && (((use_syslog || (opt_log_output)) || (3 < opt_log_level)))) {
                snprintf(tmp42,0x400,"actual_asic_number = %d, but it is error\n",actual_asic_number
                        );
                _applog(4,tmp42,false);
              }
              return -1;
            }
            i = 0x80;
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
  iVar1 = __aeabi_idiv(0x100,i);
  return iVar1;
}

