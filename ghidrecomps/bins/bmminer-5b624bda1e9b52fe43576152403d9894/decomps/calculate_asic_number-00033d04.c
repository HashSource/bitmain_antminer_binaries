
/* WARNING: Unknown calling convention */

int calculate_asic_number(uint actual_asic_number)

{
  char tmp42 [2048];
  
  if ((actual_asic_number != 1) && (actual_asic_number != 2)) {
    if (actual_asic_number - 3 < 2) {
      actual_asic_number = 4;
    }
    else if (actual_asic_number - 5 < 4) {
      actual_asic_number = 8;
    }
    else if (actual_asic_number - 9 < 8) {
      actual_asic_number = 0x10;
    }
    else if (actual_asic_number - 0x11 < 0x10) {
      actual_asic_number = 0x20;
    }
    else if (actual_asic_number - 0x21 < 0x20) {
      actual_asic_number = 0x40;
    }
    else if (actual_asic_number - 0x41 < 0x40) {
      actual_asic_number = 0x80;
    }
    else if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"actual_asic_number = %d, but it is error\n",actual_asic_number);
      _applog(7,tmp42,false);
      actual_asic_number = 0xffffffff;
    }
    else {
      actual_asic_number = 0xffffffff;
    }
  }
  return actual_asic_number;
}

