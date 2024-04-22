
/* WARNING: Unknown calling convention */

int calculate_core_number(uint actual_core_number)

{
  int iVar1;
  
  if ((actual_core_number != 1) && (actual_core_number != 2)) {
    if (actual_core_number - 3 < 2) {
      return 4;
    }
    if (actual_core_number - 5 < 4) {
      return 8;
    }
    if (actual_core_number - 9 < 8) {
      return 0x10;
    }
    if (actual_core_number - 0x11 < 0x10) {
      return 0x20;
    }
    if (actual_core_number - 0x21 < 0x20) {
      return 0x40;
    }
    if (actual_core_number - 0x41 < 0x40) {
      return 0x80;
    }
    if ((*DAT_00033e20 != '\0') &&
       (((*DAT_00033e24 != '\0' || (*DAT_00033e28 != '\0')) || (6 < *DAT_00033e2c)))) {
      iVar1 = calculate_core_number(actual_core_number);
      return iVar1;
    }
    actual_core_number = 0xffffffff;
  }
  return actual_core_number;
}

