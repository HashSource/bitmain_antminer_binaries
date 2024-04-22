
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kill_mining(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined2 uStack_7f8;
  undefined local_7f6;
  
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_810 = s_Killing_off_mining_threads_0005d350._0_4_;
    uStack_80c = s_Killing_off_mining_threads_0005d350._4_4_;
    uStack_808 = s_Killing_off_mining_threads_0005d350._8_4_;
    uStack_804 = s_Killing_off_mining_threads_0005d350._12_4_;
    local_800 = s_Killing_off_mining_threads_0005d350._16_4_;
    uStack_7fc = s_Killing_off_mining_threads_0005d350._20_4_;
    uStack_7f8 = (undefined2)ram0x0005d368;
    local_7f6 = (undefined)((uint)ram0x0005d368 >> 0x10);
    _applog(7,&local_810,1);
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

