
int open_lcd(void)

{
  lcd_fd = open("/dev/bitmain-lcd",0x882);
  if (lcd_fd < 1) {
    puts("open lcd failed!!!");
  }
  return lcd_fd;
}

