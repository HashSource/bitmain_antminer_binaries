
void update_pic_program(undefined1 param_1)

{
  uint uVar1;
  undefined4 local_283c;
  undefined4 local_2838;
  undefined4 local_2834;
  undefined4 local_2830;
  char local_282c [8];
  undefined4 uStack_2824;
  undefined4 auStack_2820 [2559];
  FILE *local_24;
  uint local_20;
  byte local_1c;
  byte local_1b;
  byte local_1a;
  byte local_19;
  ulong local_18;
  uint local_14;
  
  memset(&uStack_2824,0,0x2800);
  local_14 = 0;
  local_282c[0] = '\0';
  local_282c[1] = '\0';
  local_282c[2] = '\0';
  local_282c[3] = '\0';
  local_282c[4] = 0;
  local_283c = 0;
  local_2838 = 0;
  local_2834 = 0;
  local_2830 = 0;
  local_18 = 0;
  local_19 = 3;
  local_1a = 0;
  local_1b = 0xf;
  local_1c = 0x7f;
  local_20 = 0;
  puts("\n--- update pic program");
  local_24 = fopen("/etc/config/hash_s8_app.txt","r");
  if (local_24 == (FILE *)0x0) {
    printf("\n%s: open hash_s8_app.txt failed\n","update_pic_program");
  }
  else {
    fseek(local_24,0,0);
    memset(&uStack_2824,0,0x2800);
    local_20 = (((uint)local_1b * 0x100 + (uint)local_1c) -
               ((uint)local_1a + (uint)local_19 * 0x100)) + 1;
    printf("pic_flash_length = %d\n",local_20);
    for (local_14 = 0; local_14 < local_20; local_14 = local_14 + 1) {
      fgets(local_282c,0x3ff,local_24);
      local_18 = strtoul(local_282c,(char **)0x0,0x10);
      *(char *)((int)&uStack_2824 + local_14 * 2) = (char)(local_18 >> 8);
      *(char *)((int)&uStack_2824 + local_14 * 2 + 1) = (char)local_18;
    }
    fclose(local_24);
    reset_iic_pic(param_1);
    erase_pic_flash_all(param_1);
    set_pic_iic_flash_addr_pointer(param_1,3,0);
    for (local_14 = 0; uVar1 = (local_20 >> 5) * 4, local_14 <= uVar1 && uVar1 - local_14 != 0;
        local_14 = local_14 + 1) {
      local_283c = (&uStack_2824)[local_14 * 4];
      local_2838 = auStack_2820[local_14 * 4];
      local_2834 = auStack_2820[local_14 * 4 + 1];
      local_2830 = auStack_2820[local_14 * 4 + 2];
      send_data_to_pic_flash(param_1,&local_283c);
      write_data_into_pic_flash(param_1);
    }
    usleep(500000);
  }
  return;
}

