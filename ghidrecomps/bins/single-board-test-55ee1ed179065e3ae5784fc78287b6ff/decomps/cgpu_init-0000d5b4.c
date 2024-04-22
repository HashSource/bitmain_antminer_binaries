
undefined4 cgpu_init(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  printf("\n%s\n","cgpu_init",param_3,0,0);
  memset(cgpu,0,0x1004c4);
  iVar1 = check_chain();
  if (iVar1 != 0) {
    printf("!!! %s: check chain error\n","cgpu_init");
  }
  iVar2 = open_key();
  if (iVar2 < 1) {
    printf("!!! %s: open start key error\n","cgpu_init");
    close_key();
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = open_i2c();
    if (iVar2 < 1) {
      printf("!!! %s: open i2c error\n","cgpu_init");
      close_i2c();
      close_key();
      uVar3 = 0xffffffff;
    }
    else {
      memset(lcd_output,0x20,0x40);
      write_lcd(0,lcd_output,0x40);
      if (iVar1 != 0) {
        printf("no hashboard %d\n",1);
        write_lcd(0,"No Hashboard",0x10);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}

