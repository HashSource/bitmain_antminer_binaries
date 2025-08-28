
void V9_print_lcd(void)

{
  char local_1c [20];
  
  if (set_address_test_result < 1) {
    write_lcd_no_memset(0,"Address NG      ",0x10);
  }
  else {
    write_lcd_no_memset(0,"Address OK      ",0x10);
  }
  local_1c[0] = '\0';
  local_1c[1] = '\0';
  local_1c[2] = '\0';
  local_1c[3] = '\0';
  local_1c[4] = '\0';
  local_1c[5] = '\0';
  local_1c[6] = '\0';
  local_1c[7] = '\0';
  local_1c[8] = '\0';
  local_1c[9] = '\0';
  local_1c[10] = '\0';
  local_1c[0xb] = '\0';
  local_1c[0xc] = '\0';
  local_1c[0xd] = '\0';
  local_1c[0xe] = '\0';
  local_1c[0xf] = '\0';
  local_1c[0x10] = 0;
  sprintf(local_1c,"Pattern %c %c %c   ",(uint)(byte)nonce_test_asic_result,
          (uint)nonce_test_asic_result._1_1_,(uint)nonce_test_asic_result._2_1_);
  write_lcd_no_memset(1,local_1c,0x10);
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

