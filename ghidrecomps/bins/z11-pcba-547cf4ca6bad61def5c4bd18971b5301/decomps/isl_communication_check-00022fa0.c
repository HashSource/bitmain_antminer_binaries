
undefined4 isl_communication_check(ushort param_1)

{
  undefined4 uVar1;
  char acStack_418 [1026];
  ushort local_16;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_c = 0;
  do {
    if (2 < local_c) {
      if (local_10 == 3) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0xffffffff;
      }
      return uVar1;
    }
    local_14 = 0;
    do {
      local_16 = 0;
      ISL_get_voltage(gChain,0,(&isl_dev_addr)[local_c],&local_16);
      if ((local_16 < 0x385) && (799 < local_16)) {
        local_10 = local_10 + 1;
        break;
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_418,0x400,
                 "asic%d read voltage again voltage %d, expect voltage %d retry %d\n",local_c,
                 (uint)local_16,(uint)param_1,local_14);
        _applog(2,acStack_418,0);
      }
      usleep(200000);
      local_14 = local_14 + 1;
    } while (local_14 < 3);
    local_c = local_c + 1;
  } while( true );
}

