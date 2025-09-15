
void display_level_result_on_lcd(void)

{
  char local_14 [8];
  uint local_c;
  
  builtin_strncpy(local_14,"     ",5);
  sprintf(local_14,"%2d",pattern_test_time + 1);
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    lcd_buffer[local_c + 10] = local_14[local_c];
  }
  write_lcd(0,lcd_buffer,0x10);
  printf("Level: %d\n\n",pattern_test_time + 1);
  return;
}

