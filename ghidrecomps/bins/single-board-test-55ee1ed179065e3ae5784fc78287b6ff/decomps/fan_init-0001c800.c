
undefined4 fan_init(void)

{
  undefined4 uVar1;
  
  if (platform_inited == 0) {
    printf("%s:%d","fan_init",0xb);
    puts("please init platform first!!");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

