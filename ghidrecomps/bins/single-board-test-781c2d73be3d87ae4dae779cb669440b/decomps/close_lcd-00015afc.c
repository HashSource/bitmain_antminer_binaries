
/* WARNING: Unknown calling convention */

int close_lcd(void)

{
  int iVar1;
  
  iVar1 = close(lcd_fd);
  if (iVar1 != 0) {
    puts("lcd close failed!!!");
    return iVar1;
  }
  puts("lcd closed!!!");
  return 0;
}

