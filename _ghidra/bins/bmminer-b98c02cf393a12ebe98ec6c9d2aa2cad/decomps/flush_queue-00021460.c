
void flush_queue(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_814;
  char local_810 [24];
  undefined2 uStack_7f8;
  undefined1 local_7f6;
  
  local_814 = 0;
  if (param_1 != 0) {
    iVar1 = pthread_rwlock_trywrlock((pthread_rwlock_t *)(param_1 + 0x140));
    if (iVar1 == 0) {
      local_814 = *(int *)(param_1 + 0x164);
      *(undefined4 *)(param_1 + 0x164) = 0;
      iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)(param_1 + 0x140));
      if (iVar1 != 0) {
        piVar2 = __errno_location();
        snprintf(local_810,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar2,
                 "cgminer.c","flush_queue",0x2541);
        _applog(3,local_810,1);
                    /* WARNING: Subroutine does not return */
        __quit(1);
      }
      (*selective_yield)();
      if (((local_814 != 0) &&
          (_free_work(&local_814,"cgminer.c","flush_queue",0x2545), opt_debug != '\0')) &&
         ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
        builtin_strncpy(local_810,"Discarded queued work it",0x18);
        uStack_7f8 = 0x6d65;
        local_7f6 = 0;
        _applog(7,local_810,0);
      }
    }
  }
  return;
}

