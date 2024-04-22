
/* WARNING: Unknown calling convention */

void display_level_result_on_lcd(void)

{
  char Voltage_char [5];
  
  Voltage_char._0_4_ = DAT_0002d918;
  Voltage_char[4] = DAT_0002d91c;
  sprintf(Voltage_char,"%2d",pattern_test_time + 1);
  lcd_buffer[10] = Voltage_char[0];
  lcd_buffer[11] = Voltage_char[1];
  lcd_buffer[12] = Voltage_char[2];
  write_lcd(0,lcd_buffer,0x10);
  printf("Level: %d\n\n",pattern_test_time + 1);
  return;
}

