
undefined4 start_pcba_test(void)

{
  int iVar1;
  char local_454 [16];
  undefined4 local_444;
  char acStack_440 [1004];
  char local_54 [64];
  int local_14;
  
  memset(local_54,0,0x40);
  iVar1 = cgpu_init();
  if (iVar1 < 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      builtin_strncpy(local_454,"cgpu init failed",0x10);
      local_444 = CONCAT22(local_444._2_2_,10);
      _applog(2,local_454,0);
    }
    return 0xffffffff;
  }
  display_arguments();
  do {
    memset(local_54,0,0x40);
    iVar1 = strcmp(app_conf + 0x184,"keyboard");
    if (iVar1 == 0) {
      local_14 = __isoc99_fscanf(stdin,&DAT_00034a80,local_54);
    }
    else {
      iVar1 = strcmp(app_conf + 0x184,"button");
      if (iVar1 != 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          builtin_strncpy(local_454,"please assign ct",0x10);
          local_444._0_1_ = 'r';
          local_444._1_1_ = 'l';
          local_444._2_1_ = ' ';
          local_444._3_1_ = 't';
          builtin_strncpy(acStack_440,"ype: keyboard or button\n",0x18);
          acStack_440[0x18] = 0;
          _applog(2,local_454,0);
        }
        cgpu_exit();
        return 0;
      }
      local_14 = v9_key_read(local_54,0x40);
    }
    if ((0 < local_14) && (local_54[0] == '0')) {
      singleBoardTest_V9_BM1744();
    }
    usleep(100000);
  } while( true );
}

