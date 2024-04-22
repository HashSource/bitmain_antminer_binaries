
void V9_print_lcd_type(int type)

{
  int type_local;
  
  if (type == -1) {
    write_lcd_no_memset(0," hardware error ",0x10);
    write_lcd_no_memset(1,"     check      ",0x10);
    write_lcd_no_memset(2," u2 u44 u16 u23 ",0x10);
    write_lcd_no_memset(3," u30            ",0x10);
  }
  else {
    V9_print_lcd();
  }
  return;
}

