
undefined4 uart_init(void)

{
  undefined4 uVar1;
  
  if (platform_inited == 0) {
    printf("%s:%d","uart_init",0x206);
    puts("please init platform first!!");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

