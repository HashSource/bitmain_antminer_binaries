
void kill_mining(void)

{
  int iVar1;
  int iVar2;
  char local_810 [24];
  undefined2 uStack_7f8;
  undefined1 local_7f6;
  
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_810,"Killing off mining threa",0x18);
    uStack_7f8 = 0x7364;
    local_7f6 = 0;
    _applog(7,local_810,1);
  }
  if (mining_threads < 1) {
    return;
  }
  iVar2 = 0;
  do {
    while ((iVar1 = get_thread(iVar2), iVar1 != 0 && (*(int *)(iVar1 + 0xc) != 0))) {
      thr_info_cancel();
      if (*(pthread_t *)(iVar1 + 0xc) == 0) goto LAB_0002080e;
      iVar2 = iVar2 + 1;
      pthread_join(*(pthread_t *)(iVar1 + 0xc),(void **)0x0);
      if (mining_threads <= iVar2) {
        return;
      }
    }
    thr_info_cancel(iVar1);
LAB_0002080e:
    iVar2 = iVar2 + 1;
    if (mining_threads <= iVar2) {
      return;
    }
  } while( true );
}

