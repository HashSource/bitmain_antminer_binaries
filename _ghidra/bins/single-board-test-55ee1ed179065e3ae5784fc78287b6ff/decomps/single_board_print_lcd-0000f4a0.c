
void single_board_print_lcd(uint param_1)

{
  display_level_result_on_lcd();
  if ((param_1 & 1) == 0) {
    write_lcd_no_memset(1,"   Pattern NG   ",0x10);
    pattern_test_time = pattern_test_time + '\x01';
  }
  else {
    write_lcd_no_memset(1,"   Pattern OK   ",0x10);
    pattern_test_time = '\0';
  }
  if (g_test_epprom == '\0') {
    puts("eeprom NG");
    write_lcd_no_memset(2,"   epprom NG\t",0x10);
  }
  else {
    puts("eeprom OK");
    write_lcd_no_memset(2,"   epprom OK\t",0x10);
  }
  if ((param_1 & 4) == 0) {
    write_lcd_no_memset(3," Temperature NG ",0x10);
  }
  else {
    write_lcd_no_memset(3," Temperature OK ",0x10);
  }
  return;
}

