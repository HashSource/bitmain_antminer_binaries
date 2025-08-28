
void pt_handle(int param_1,undefined4 param_2,byte param_3)

{
  ushort uVar1;
  char local_420 [1024];
  FILE *local_20;
  ushort local_1a;
  int local_18;
  int local_14;
  
  local_18 = param_1;
  uVar1 = CRC16_v1(param_1 + 2,0x402);
  local_1a = uVar1 >> 8 | uVar1 << 8;
  if (local_1a == *(ushort *)(local_18 + 0x404)) {
    local_20 = fopen("./pattern_result.txt","a+");
    if (local_20 == (FILE *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        builtin_strncpy(local_420,"open failed pattern_result.txt\n",0x20);
        _applog(2,local_420,0);
      }
    }
    else {
      for (local_14 = 0; local_14 < 0x80; local_14 = local_14 + 1) {
        dump_str(local_20,0,local_14 * 8 + local_18 + 4,8);
      }
      fclose(local_20);
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(local_420,0x400,"chainid=%d cal crc = %04x, chip crc = %04x\n",(uint)param_3,
               (uint)local_1a,(uint)*(ushort *)(local_18 + 0x404));
      _applog(2,local_420,0);
    }
    pattern_test_crc_error = 1;
  }
  return;
}

