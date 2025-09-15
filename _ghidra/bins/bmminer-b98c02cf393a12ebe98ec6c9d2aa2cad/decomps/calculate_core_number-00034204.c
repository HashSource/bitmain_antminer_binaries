
int calculate_core_number(int param_1)

{
  int iVar1;
  
  if ((param_1 != 1) && (param_1 != 2)) {
    if (param_1 - 3U < 2) {
      return 4;
    }
    if (param_1 - 5U < 4) {
      return 8;
    }
    if (param_1 - 9U < 8) {
      return 0x10;
    }
    if (param_1 - 0x11U < 0x10) {
      return 0x20;
    }
    if (param_1 - 0x21U < 0x20) {
      return 0x40;
    }
    if (param_1 - 0x41U < 0x40) {
      return 0x80;
    }
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      iVar1 = calculate_core_number_part_11();
      return iVar1;
    }
    param_1 = -1;
  }
  return param_1;
}

