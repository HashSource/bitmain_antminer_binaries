
undefined4 calculate_asic_number(uint param_1)

{
  char acStack_10c [256];
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == 1) {
    local_c = 1;
  }
  else if (param_1 == 2) {
    local_c = 2;
  }
  else if ((param_1 < 3) || (4 < param_1)) {
    if ((param_1 < 5) || (8 < param_1)) {
      if ((param_1 < 9) || (0x10 < param_1)) {
        if ((param_1 < 0x11) || (0x20 < param_1)) {
          if ((param_1 < 0x21) || (0x40 < param_1)) {
            if ((param_1 < 0x41) || (0x80 < param_1)) {
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (3 < opt_log_level)))) {
                snprintf(acStack_10c,0x100,"actual_asic_number = %d, but it is error\n",param_1);
                _applog(4,acStack_10c,0);
              }
              local_c = 0xffffffff;
            }
            else {
              local_c = 0x80;
            }
          }
          else {
            local_c = 0x40;
          }
        }
        else {
          local_c = 0x20;
        }
      }
      else {
        local_c = 0x10;
      }
    }
    else {
      local_c = 8;
    }
  }
  else {
    local_c = 4;
  }
  return local_c;
}

