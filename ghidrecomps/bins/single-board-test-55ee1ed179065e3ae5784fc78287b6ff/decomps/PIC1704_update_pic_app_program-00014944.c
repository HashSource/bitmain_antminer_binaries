
undefined4 PIC1704_update_pic_app_program(undefined4 param_1,undefined1 param_2)

{
  uint uVar1;
  undefined4 extraout_r3;
  undefined4 uVar2;
  undefined4 local_13d0;
  undefined4 local_13cc;
  undefined4 local_13c8;
  undefined4 local_13c4;
  char local_13c0 [8];
  undefined4 uStack_13b8;
  undefined4 auStack_13b4 [1249];
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
  local_13c0[0] = '\0';
  local_13c0[1] = 0;
  local_13c0[2] = 0;
  local_13c0[3] = 0;
  local_13c0[4] = 0;
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
  local_30 = fopen("/mnt/card/pic16f1704_app.txt","r");
  if (local_30 == (FILE *)0x0) {
    printf("\n%s: open pic16f1704_app.txt failed\n","PIC1704_update_pic_app_program");
    uVar2 = extraout_r3;
  }
  else {
    fseek(local_30,0,0);
    memset(&uStack_13b8,0,5000);
    local_28 = (((uint)local_23 * 0x100 + (uint)local_24) -
               ((uint)local_21 * 0x100 + (uint)local_22)) + 1;
    printf("pic_flash_length = %d\n",local_28);
    for (local_14 = 0; local_14 < local_28; local_14 = local_14 + 1) {
      fgets(local_13c0,0x3ff,local_30);
      local_20 = strtoul(local_13c0,(char **)0x0,0x10);
      *(char *)((int)&uStack_13b8 + local_14 * 2) = (char)(local_20 >> 8);
      *(char *)((int)&uStack_13b8 + local_14 * 2 + 1) = (char)local_20;
    }
    fclose(local_30);
    local_2c = reset_PIC16F1704_pic(param_1,param_2);
    if (local_2c == 0) {
      printf("!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
      uVar2 = 0;
    }
    else {
      local_2c = erase_PIC16F1704_app_flash(param_1,param_2);
      if (local_2c == 0) {
        printf("!!! %s: erase flash error!\n\n","PIC1704_update_pic_app_program");
        uVar2 = 0;
      }
      else {
        local_2c = set_PIC16F1704_flash_point32_ter(param_1,param_2,6,0);
        if (local_2c == 0) {
          printf("!!! %s: set flash point32_ter error!\n\n","PIC1704_update_pic_app_program");
          uVar2 = 0;
        }
        else {
          for (local_14 = 0; uVar1 = (local_28 >> 5) * 4, local_14 <= uVar1 && uVar1 - local_14 != 0
              ; local_14 = local_14 + 1) {
            local_13d0 = (&uStack_13b8)[local_14 * 4];
            local_13cc = auStack_13b4[local_14 * 4];
            local_13c8 = auStack_13b4[local_14 * 4 + 1];
            local_13c4 = auStack_13b4[local_14 * 4 + 2];
            printf("send pic program time: %d\n",local_14);
            for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
              printf("buf[%d] = 0x%02x\n",local_18,(uint)*(byte *)((int)&local_13d0 + local_18));
            }
            putchar(10);
            send_data_to_PIC16F1704(param_1,param_2,&local_13d0);
            write_data_int32_to_PIC16F1704_flash(param_1,param_2);
          }
          local_2c = reset_PIC16F1704_pic(param_1,param_2);
          if (local_2c == 0) {
            printf("!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
            uVar2 = 0;
          }
          else {
            uVar2 = 1;
          }
        }
      }
    }
  }
  return uVar2;
}

