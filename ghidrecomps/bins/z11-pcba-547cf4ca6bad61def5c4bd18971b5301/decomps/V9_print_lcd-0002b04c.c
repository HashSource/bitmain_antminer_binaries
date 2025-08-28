
void V9_print_lcd(void)

{
  char local_18 [16];
  
  if (set_address_test_result < 1) {
    write_lcd_no_memset(0,"Address NG      ",0x10);
  }
  else {
    write_lcd_no_memset(0,"Address OK      ",0x10);
  }
  local_18[0] = '\0';
  local_18[1] = '\0';
  local_18[2] = '\0';
  local_18[3] = '\0';
  local_18[4] = '\0';
  local_18[5] = '\0';
  local_18[6] = '\0';
  local_18[7] = '\0';
  local_18[8] = '\0';
  local_18[9] = '\0';
  local_18[10] = '\0';
  local_18[0xb] = '\0';
  local_18[0xc] = '\0';
  local_18[0xd] = '\0';
  local_18[0xe] = '\0';
  local_18[0xf] = '\0';
  sprintf(local_18,"Pattern %c %c %c %c ",(uint)(byte)nonce_test_asic_result,
          (uint)nonce_test_asic_result._1_1_,(uint)nonce_test_asic_result._2_1_);
  write_lcd_no_memset(1,local_18,0x10);
  if (read_temp_test_result < 1) {
    write_lcd_no_memset(2,"Sensor NG       ",0x10);
  }
  else {
    write_lcd_no_memset(2,"Sensor OK       ",0x10);
  }
  if (tempture_value_test_result < 1) {
    write_lcd_no_memset(3,"Temperature NG  ",0x10);
  }
  else {
    write_lcd_no_memset(3,"Temperature OK  ",0x10);
  }
  return;
}

