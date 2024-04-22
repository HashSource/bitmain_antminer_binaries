
FILE * PIC1704_update_pic_app_program(undefined4 param_1,undefined param_2)

{
  FILE *__stream;
  uint uVar1;
  undefined local_142d;
  undefined4 local_142c;
  undefined4 local_13d0;
  undefined4 local_13cc;
  undefined4 local_13c8;
  undefined4 local_13c4;
  char local_13c0;
  undefined local_13bf;
  undefined local_13be;
  undefined local_13bd;
  undefined local_13bc;
  undefined4 uStack_13b8;
  undefined4 auStack_13b0 [1248];
  FILE *local_30;
  int local_2c;
  uint local_28;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  ulong local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  
  memset(&uStack_13b8,0,5000);
  local_1c = 0;
  local_14 = 0;
  local_13c0 = '\0';
  local_13bf = 0;
  local_13be = 0;
  local_13bd = 0;
  local_13bc = 0;
  local_13d0 = 0;
  local_13cc = 0;
  local_13c8 = 0;
  local_13c4 = 0;
  local_20 = 0;
  local_21 = 6;
  local_22 = 0;
  local_23 = 0xf;
  local_24 = 0x7f;
  local_28 = 0;
  local_2c = 0;
  puts("\n--- update pic program");
  __stream = fopen("/mnt/card/pic16f1704_app.txt","r");
  local_30 = __stream;
  if (__stream == (FILE *)0x0) {
    printf("\n%s: open pic16f1704_app.txt failed\n","PIC1704_update_pic_app_program");
  }
  else {
    fseek(__stream,0,0);
    memset(&uStack_13b8,0,5000);
    local_28 = (((uint)local_23 * 0x100 + (uint)local_24) -
               ((uint)local_21 * 0x100 + (uint)local_22)) + 1;
    printf("pic_flash_length = %d\n",local_28);
    local_142d = param_2;
    local_142c = param_1;
    for (local_14 = 0; local_14 < local_28; local_14 = local_14 + 1) {
      fgets(&local_13c0,0x3ff,local_30);
      local_20 = strtoul(&local_13c0,(char **)0x0,0x10);
      *(char *)((int)&uStack_13b8 + local_14 * 2) = (char)(local_20 >> 8);
      *(char *)((int)&uStack_13b8 + local_14 * 2 + 1) = (char)local_20;
    }
    fclose(local_30);
    local_2c = reset_PIC16F1704_pic(local_142c,local_142d);
    if (local_2c == 0) {
      printf("!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
      __stream = (FILE *)0x0;
    }
    else {
      local_2c = erase_PIC16F1704_app_flash(local_142c,local_142d);
      if (local_2c == 0) {
        printf("!!! %s: erase flash error!\n\n","PIC1704_update_pic_app_program");
        __stream = (FILE *)0x0;
      }
      else {
        local_2c = set_PIC16F1704_flash_point32_ter(local_142c,local_142d,6,0);
        if (local_2c == 0) {
          printf("!!! %s: set flash point32_ter error!\n\n","PIC1704_update_pic_app_program");
          __stream = (FILE *)0x0;
        }
        else {
          for (local_14 = 0; uVar1 = (local_28 >> 5) * 4, local_14 <= uVar1 && uVar1 - local_14 != 0
              ; local_14 = local_14 + 1) {
            local_13d0 = (&uStack_13b8)[local_14 * 4];
            local_13cc = (&uStack_13b8)[local_14 * 4 + 1];
            local_13c8 = *(undefined4 *)(&stack0xffffec4c + local_14 * 0x10 + 4);
            local_13c4 = *(undefined4 *)(&stack0xffffec4c + local_14 * 0x10 + 8);
            printf("send pic program time: %d\n",local_14);
            for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
              printf("buf[%d] = 0x%02x\n",local_18,(uint)*(byte *)((int)&local_13d0 + local_18));
            }
            putchar(10);
            send_data_to_PIC16F1704(local_142c,local_142d,&local_13d0);
            write_data_int32_to_PIC16F1704_flash(local_142c,local_142d);
          }
          local_2c = reset_PIC16F1704_pic(local_142c,local_142d);
          if (local_2c == 0) {
            printf("!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
            __stream = (FILE *)0x0;
          }
          else {
            __stream = (FILE *)0x1;
          }
        }
      }
    }
  }
  return __stream;
}

