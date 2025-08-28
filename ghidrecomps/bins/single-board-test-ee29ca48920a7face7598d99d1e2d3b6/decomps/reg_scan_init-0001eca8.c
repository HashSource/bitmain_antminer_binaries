
void reg_scan_init(void)

{
  int iVar1;
  char local_414 [20];
  undefined2 local_400;
  undefined1 local_3fe;
  int local_14;
  
  memset(&reg_scan_items,0,0x4b0);
  for (local_14 = 0; local_14 < 100; local_14 = local_14 + 1) {
    *(undefined4 *)(&DAT_00047f00 + local_14 * 0xc) = 0xffffffff;
  }
  iVar1 = pthread_create(&p_reg_scan,(pthread_attr_t *)0x0,(__start_routine *)0x1ebfd,(void *)0x0);
  if ((iVar1 != 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (2 < opt_log_level)))) {
    builtin_strncpy(local_414,"create pthread faile",0x14);
    local_400 = 0xa64;
    local_3fe = 0;
    _applog(3,local_414,0);
  }
  return;
}

