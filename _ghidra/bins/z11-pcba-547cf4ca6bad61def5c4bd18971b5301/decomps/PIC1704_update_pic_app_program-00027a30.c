
undefined4 PIC1704_update_pic_app_program(undefined4 param_1,undefined1 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char local_17c8 [1024];
  undefined4 local_13c8;
  undefined4 local_13c4;
  undefined4 local_13c0;
  undefined4 local_13bc;
  char local_13b8 [8];
  undefined4 uStack_13b0;
  undefined4 auStack_13ac [1249];
  FILE *local_28;
  int local_24;
  uint local_20;
  byte local_1c;
  byte local_1b;
  byte local_1a;
  byte local_19;
  ulong local_18;
  uint local_14;
  
  memset(&uStack_13b0,0,5000);
  local_14 = 0;
  local_13b8[0] = '\0';
  local_13b8[1] = '\0';
  local_13b8[2] = '\0';
  local_13b8[3] = '\0';
  local_13b8[4] = 0;
  local_13c8 = 0;
  local_13c4 = 0;
  local_13c0 = 0;
  local_13bc = 0;
  local_18 = 0;
  local_19 = 6;
  local_1a = 0;
  local_1b = 0xf;
  local_1c = 0x7f;
  local_20 = 0;
  local_24 = 0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    builtin_strncpy(local_17c8,"--- update pic program\n",0x18);
    _applog(2,local_17c8,0);
  }
  local_28 = fopen("/mnt/card/pic16f1704_app.txt","r");
  if (local_28 == (FILE *)0x0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(local_17c8,0x400,"%s: open pic16f1704_app.txt failed\n",
               "PIC1704_update_pic_app_program");
      _applog(2,local_17c8,0);
    }
    uVar2 = 0;
  }
  else {
    fseek(local_28,0,0);
    memset(&uStack_13b0,0,5000);
    local_20 = (((uint)local_1b * 0x100 + (uint)local_1c) -
               ((uint)local_1a + (uint)local_19 * 0x100)) + 1;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(local_17c8,0x400,"pic_flash_length = %d\n",local_20);
      _applog(2,local_17c8,0);
    }
    for (local_14 = 0; local_14 < local_20; local_14 = local_14 + 1) {
      fgets(local_13b8,0x3ff,local_28);
      local_18 = strtoul(local_13b8,(char **)0x0,0x10);
      *(char *)((int)&uStack_13b0 + local_14 * 2) = (char)(local_18 >> 8);
      *(char *)((int)&uStack_13b0 + local_14 * 2 + 1) = (char)local_18;
    }
    fclose(local_28);
    local_24 = reset_PIC16F1704_pic(param_1,param_2);
    if (local_24 == 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(local_17c8,0x400,"!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
        _applog(2,local_17c8,0);
      }
      uVar2 = 0;
    }
    else {
      local_24 = erase_PIC16F1704_app_flash(param_1,param_2);
      if (local_24 == 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(local_17c8,0x400,"!!! %s: erase flash error!\n\n",
                   "PIC1704_update_pic_app_program");
          _applog(2,local_17c8,0);
        }
        uVar2 = 0;
      }
      else {
        local_24 = set_PIC16F1704_flash_pointer(param_1,param_2,6,0);
        if (local_24 == 0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
            snprintf(local_17c8,0x400,"!!! %s: set flash pointer error!\n\n",
                     "PIC1704_update_pic_app_program");
            _applog(2,local_17c8,0);
          }
          uVar2 = 0;
        }
        else {
          for (local_14 = 0; uVar1 = (local_20 >> 5) * 4, local_14 <= uVar1 && uVar1 - local_14 != 0
              ; local_14 = local_14 + 1) {
            local_13c8 = (&uStack_13b0)[local_14 * 4];
            local_13c4 = auStack_13ac[local_14 * 4];
            local_13c0 = auStack_13ac[local_14 * 4 + 1];
            local_13bc = auStack_13ac[local_14 * 4 + 2];
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
              snprintf(local_17c8,0x400,"send pic program time: %d\n",local_14);
              _applog(2,local_17c8,0);
            }
            send_data_to_PIC16F1704(param_1,param_2,&local_13c8);
            write_data_into_PIC16F1704_flash(param_1,param_2);
          }
          local_24 = reset_PIC16F1704_pic(param_1,param_2);
          if (local_24 == 0) {
            if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
              snprintf(local_17c8,0x400,"!!! %s: reset pic error!\n\n",
                       "PIC1704_update_pic_app_program");
              _applog(2,local_17c8,0);
            }
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

