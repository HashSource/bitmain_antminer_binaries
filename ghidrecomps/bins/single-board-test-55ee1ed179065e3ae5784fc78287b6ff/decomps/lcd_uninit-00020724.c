
undefined4 lcd_uninit(int param_1)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = 0;
  if (lcd_inited != 0) {
    iVar1 = close(param_1);
    if (iVar1 != 0) {
      printf("%s:%d","lcd_uninit",0x75);
      puts("lcd close failed!!!");
      local_c = 0xffffffff;
    }
    lcd_inited = 0;
  }
  return local_c;
}

