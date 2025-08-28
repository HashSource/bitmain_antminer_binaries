
void singleboard_set_address_test(void)

{
  int iVar1;
  char local_420 [20];
  undefined2 local_40c;
  undefined1 local_40a;
  undefined1 local_20;
  byte local_1f;
  undefined1 local_1e;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  
  read_register(0,0,0,0);
  read_register(0,1,0,0);
  usleep(200000);
  asic_addr_interval();
  set_address();
  usleep(200000);
  read_register(0,1,0,0);
  local_14 = 0;
  do {
    if (2 < local_14) {
LAB_000223a2:
      if (local_14 == 3) {
        set_address_test_result = 1;
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(local_420,0x400,"%s Success\n","singleboard_set_address_test");
          _applog(2,local_420,0);
        }
      }
      else {
        set_address_test_result = 0xffffffff;
      }
      return;
    }
    local_20 = 0;
    local_1f = (char)local_14 * (char)addr_interval;
    local_1e = 0;
    local_1c = 0;
    local_18 = 0;
    iVar1 = read_reg_item(&local_20,500);
    if (iVar1 < 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        builtin_strncpy(local_420,"read chip num timeou",0x14);
        local_40c = 0xa74;
        local_40a = 0;
        _applog(2,local_420,0);
      }
      goto LAB_000223a2;
    }
    if ((local_1c & 0xff) != (uint)local_1f) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(local_420,0x400,"Set address Fail set:%02x get:%02x\n",(uint)local_1f,
                 local_1c & 0xff);
        _applog(2,local_420,0);
      }
      goto LAB_000223a2;
    }
    local_14 = local_14 + 1;
  } while( true );
}

