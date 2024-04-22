
undefined4 erase_PIC16F1704_app_flash(undefined4 param_1,undefined param_2)

{
  char acStack_418 [1024];
  uint local_18;
  byte local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = 0;
  local_11 = 6;
  local_12 = 0;
  local_13 = 0xf;
  local_14 = 0x7f;
  local_18 = 0;
  set_PIC16F1704_flash_pointer(param_1,param_2,6,0);
  local_18 = (((uint)local_13 * 0x100 + (uint)local_14) - ((uint)local_12 + (uint)local_11 * 0x100))
             + 1;
  local_10 = local_18 >> 5;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_418,0x400,"%s: erase_loop = %d\n","erase_PIC16F1704_app_flash",local_10);
    _applog(2,acStack_418,0);
  }
  for (local_c = 0; local_c < local_10; local_c = local_c + 1) {
    erase_PIC16F1704_flash(param_1,param_2);
  }
  return 1;
}

