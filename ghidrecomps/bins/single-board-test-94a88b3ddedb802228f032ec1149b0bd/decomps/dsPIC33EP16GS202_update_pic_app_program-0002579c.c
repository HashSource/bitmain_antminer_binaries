
undefined4 dsPIC33EP16GS202_update_pic_app_program(undefined param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined local_3749;
  undefined4 local_3744;
  undefined4 local_3740;
  undefined4 local_373c;
  undefined4 local_3738;
  undefined4 local_3734;
  undefined4 uStack_3730;
  undefined4 uStack_372c;
  undefined4 auStack_3724 [3518];
  FILE *local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  ulong local_1c;
  uint local_18;
  uint local_14;
  
  memset(&uStack_372c,0,0x3700);
  local_14 = 0;
  local_3734 = 0;
  uStack_3730 = (uint)uStack_3730._3_1_ << 0x18;
  local_3744 = 0;
  local_3740 = 0;
  local_373c = 0;
  local_3738 = 0;
  local_1c = 0;
  local_20 = 0xdc0;
  local_24 = 0x370;
  local_28 = 0;
  local_2c = fopen("/etc/config/dsPIC33EP16GS202_app.txt","r");
  if (local_2c == (FILE *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    fseek(local_2c,0,0);
    memset(&uStack_372c,0,0x3700);
    local_3749 = param_1;
    for (local_14 = 0; local_14 < local_20; local_14 = local_14 + 1) {
      fgets((char *)&local_3734,7,local_2c);
      local_1c = strtoul((char *)&local_3734,(char **)0x0,0x10);
      *(char *)(&uStack_372c + local_14) = (char)(local_1c >> 0x18);
      *(char *)((int)&uStack_372c + local_14 * 4 + 1) = (char)(local_1c >> 0x10);
      *(char *)((int)&uStack_372c + local_14 * 4 + 2) = (char)(local_1c >> 8);
      *(char *)((int)&uStack_372c + local_14 * 4 + 3) = (char)local_1c;
    }
    fclose(local_2c);
    local_28 = dsPIC33EP16GS202_reset_pic(local_3749);
    if (local_28 == 0) {
      uVar2 = 0;
    }
    else {
      local_28 = dsPIC33EP16GS202_erase_pic_app_program(local_3749);
      if (local_28 == 0) {
        uVar2 = 0;
      }
      else {
        for (local_14 = 0; local_14 < local_24; local_14 = local_14 + 1) {
          local_3744 = (&uStack_372c)[local_14 * 4];
          local_3740 = (&uStack_372c)[local_14 * 4 + 1];
          local_373c = *(undefined4 *)(&stack0xffffc8d8 + local_14 * 0x10 + 4);
          local_3738 = *(undefined4 *)(&stack0xffffc8d8 + local_14 * 0x10 + 8);
          for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
          }
          local_28 = dsPIC33EP16GS202_send_data_to_pic(local_3749,&local_3744);
          if (local_28 == 0) {
            return 0;
          }
        }
        iVar1 = dsPIC33EP16GS202_reset_pic(local_3749);
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}

