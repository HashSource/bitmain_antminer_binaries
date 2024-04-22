
/* WARNING: Unknown calling convention */

int open_lcd(void)

{
  lcd_fd = open("/dev/bitmain-lcd",0x882);
  if (0 < lcd_fd) {
    return lcd_fd;
  }
  puts("open lcd failed!!!");
  return lcd_fd;
}

