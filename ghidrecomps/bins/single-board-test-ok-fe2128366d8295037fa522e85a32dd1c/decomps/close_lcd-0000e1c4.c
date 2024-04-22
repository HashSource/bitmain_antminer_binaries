
int close_lcd(void)

{
  int iVar1;
  
  iVar1 = close(lcd_fd);
  if (iVar1 == 0) {
    puts("lcd closed!!!");
  }
  else {
    puts("lcd close failed!!!");
  }
  return iVar1;
}

