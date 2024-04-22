
void display_level_result_on_lcd(void)

{
  undefined4 local_14;
  undefined local_10;
  uint local_c;
  
  local_14 = DAT_0001a920;
  local_10 = DAT_0001a924;
  sprintf((char *)&local_14,"%2d",pattern_test_time + 1);
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    lcd_buffer[local_c + 10] = *(char *)((int)&local_14 + local_c);
  }
  write_lcd(0,lcd_buffer,0x10);
  printf("Level: %d\n\n",pattern_test_time + 1);
  return;
}

