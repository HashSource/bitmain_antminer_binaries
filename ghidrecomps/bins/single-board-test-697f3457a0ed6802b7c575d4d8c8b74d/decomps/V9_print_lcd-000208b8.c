
/* WARNING: Unknown calling convention */

void V9_print_lcd(void)

{
  char level_str [17];
  char str [17];
  
  str[0] = '\0';
  str[1] = '\0';
  str[2] = '\0';
  str[3] = '\0';
  str[4] = '\0';
  str[5] = '\0';
  str[6] = '\0';
  str[7] = '\0';
  str[8] = '\0';
  str[9] = '\0';
  str[10] = '\0';
  str[11] = '\0';
  str[12] = '\0';
  str[13] = '\0';
  str[14] = '\0';
  str[15] = '\0';
  str[16] = '\0';
  show_result();
  sprintf(str,"Pattern %d %d %d   ",*g_patten.asic_recv_nonces,g_patten.asic_recv_nonces[1],
          g_patten.asic_recv_nonces[2]);
  write_lcd(0,str,0x10);
  if (pattern_result < 1) {
    write_lcd_no_memset(1,"Pattern NG      ",0x10);
  }
  else {
    write_lcd_no_memset(1,"Pattern OK      ",0x10);
  }
  if (read_temp_test_result < 1) {
    write_lcd_no_memset(2,"Sensor NG       ",0x10);
  }
  else {
    write_lcd_no_memset(2,"Sensor OK       ",0x10);
  }
  level_str[0] = '\0';
  level_str[1] = '\0';
  level_str[2] = '\0';
  level_str[3] = '\0';
  level_str[4] = '\0';
  level_str[5] = '\0';
  level_str[6] = '\0';
  level_str[7] = '\0';
  level_str[8] = '\0';
  level_str[9] = '\0';
  level_str[10] = '\0';
  level_str[11] = '\0';
  level_str[12] = '\0';
  level_str[13] = '\0';
  level_str[14] = '\0';
  level_str[15] = '\0';
  level_str[16] = '\0';
  sprintf(level_str,"    Level %d     ",pattern_level);
  write_lcd_no_memset(3,level_str,0x10);
  return;
}

