
/* WARNING: Unknown calling convention */

int calculate_core_number(uint actual_core_number)

{
  uint uVar1;
  
  if (actual_core_number == 0) {
    printf("%s line %d: Note actual_core_num is 0!\n",DAT_00021c8c,0x13a);
    return 0;
  }
  if (actual_core_number < 2) {
    return 1;
  }
  uVar1 = 1;
  do {
    uVar1 = uVar1 * 2;
  } while (uVar1 < actual_core_number);
  return uVar1;
}

