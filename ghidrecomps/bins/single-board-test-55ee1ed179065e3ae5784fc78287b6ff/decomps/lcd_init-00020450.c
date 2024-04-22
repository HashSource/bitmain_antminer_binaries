
int lcd_init(char *param_1)

{
  int iVar1;
  
  if (lcd_inited == 0) {
    if (param_1 == (char *)0x0) {
      printf("%s:%d","lcd_init",0x18);
      puts("bad param");
      iVar1 = -3;
    }
    else {
      iVar1 = open(param_1,0x802);
      lcd_fd = iVar1;
      if (iVar1 < 0) {
        printf("%s:%d","lcd_init",0x1e);
        puts("open lcd failed!!!");
        iVar1 = -1;
      }
      else {
        lcd_inited = 1;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

