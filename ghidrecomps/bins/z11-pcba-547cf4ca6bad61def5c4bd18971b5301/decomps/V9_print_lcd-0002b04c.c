
void V9_print_lcd(void)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (set_address_test_result < 1) {
    write_lcd_no_memset(0,"Address NG      ",0x10);
  }
  else {
    write_lcd_no_memset(0,"Address OK      ",0x10);
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  sprintf((char *)&local_18,"Pattern %c %c %c %c ",(uint)(byte)nonce_test_asic_result,
          (uint)nonce_test_asic_result._1_1_,(uint)nonce_test_asic_result._2_1_);
  write_lcd_no_memset(1,&local_18,0x10);
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

