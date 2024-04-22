
/* WARNING: Unknown calling convention */

void V9_print_lcd(uint result)

{
  char *buf;
  
  display_level_result_on_lcd();
  if ((int)(result << 0x1f) < 0) {
    write_lcd_no_memset(1,"   Pattern OK   ",0x10);
    pattern_test_time = '\0';
  }
  else {
    write_lcd_no_memset(1,"   Pattern NG   ",0x10);
    pattern_test_time = pattern_test_time + '\x01';
  }
  if ((int)(result << 0x1e) < 0) {
    buf = "   Sensor OK    ";
  }
  else {
    buf = "   Sensor NG    ";
  }
  write_lcd_no_memset(2,buf,0x10);
  if ((int)(result << 0x1d) < 0) {
    write_lcd_no_memset(3," Temperature OK ",0x10);
    return;
  }
  write_lcd_no_memset(3," Temperature NG ",0x10);
  return;
}

