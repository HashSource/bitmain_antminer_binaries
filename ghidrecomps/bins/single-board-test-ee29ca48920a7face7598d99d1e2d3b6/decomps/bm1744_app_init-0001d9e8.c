
undefined4 bm1744_app_init(void)

{
  int iVar1;
  undefined4 uVar2;
  char local_414 [24];
  undefined4 local_3fc;
  char acStack_3f8 [12];
  undefined2 local_3ec;
  undefined1 local_3ea;
  int local_14;
  
  local_14 = 0;
  reg_scan_init();
  start_recv = 1;
  local_14 = 0;
  while( true ) {
    if (0 < local_14) {
      iVar1 = pthread_create(&p_scanhash,(pthread_attr_t *)0x0,(__start_routine *)0x1bf01,
                             (void *)0x0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
          builtin_strncpy(local_414,"create bm1744_scanhash_l",0x18);
          local_3fc._0_1_ = 'o';
          local_3fc._1_1_ = 'o';
          local_3fc._2_1_ = 'p';
          local_3fc._3_1_ = ' ';
          builtin_strncpy(acStack_3f8,"thread faile",0xc);
          local_3ec = 0xa64;
          local_3ea = 0;
          _applog(1,local_414,0);
        }
        uVar2 = 0xffffffff;
      }
      return uVar2;
    }
    iVar1 = pthread_create((pthread_t *)(g_chain + local_14 * 0x20 + 0x18),(pthread_attr_t *)0x0,
                           (__start_routine *)0x1d311,&local_14);
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
    builtin_strncpy(local_414,"create p_dispatch failed",0x18);
    local_3fc = CONCAT22(local_3fc._2_2_,10);
    _applog(1,local_414,0);
  }
  return 0xffffffff;
}

