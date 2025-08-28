
void pcba_app_manual_test(void)

{
  char local_458 [1072];
  undefined2 local_28 [10];
  int local_14;
  
  local_14 = 1;
  bm1744_app_init();
  while( true ) {
    if (local_14 == 0) {
      return;
    }
    local_28[0] = 0;
    sleep(1);
    setbuf(stdin,(char *)0x0);
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      builtin_strncpy(local_458,"Input test paramter:",0x14);
      local_458[0x14] = 0;
      _applog(2,local_458,0);
    }
    __isoc99_fscanf(stdin,&DAT_00034f34,local_28);
    if ((byte)local_28[0] - 0x61 < 0x17) break;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
      builtin_strncpy(local_458,"unknow command\n",0x10);
      _applog(1,local_458,0);
    }
  }
  (*(code *)(&PTR_LAB_00023568_1_00023298)[(byte)local_28[0] - 0x61])();
  return;
}

