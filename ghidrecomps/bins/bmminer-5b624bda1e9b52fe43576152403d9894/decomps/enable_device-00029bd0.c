
/* WARNING: Unknown calling convention */

void enable_device(cgpu_info *cgpu)

{
  pthread_rwlock_t *__rwlock;
  int iVar1;
  char *in_r2;
  char *pcVar2;
  int iVar3;
  int line;
  char **line_00;
  
  iVar3 = 0;
  cgpu->deven = DEV_ENABLED;
  iVar1 = pthread_rwlock_wrlock(DAT_00029c60);
  if (iVar1 != 0) {
    _wr_lock(DAT_00029c78,(char *)0x2b51,in_r2,iVar3);
  }
  iVar1 = DAT_00029c68;
  __rwlock = DAT_00029c60;
  iVar3 = *DAT_00029c64;
  line = *(int *)(DAT_00029c68 + 0xa64);
  cgpu->cgminer_id = line;
  pcVar2 = (char *)(line + 1);
  *(cgpu_info **)(iVar3 + line * 4) = cgpu;
  *(char **)(iVar1 + 0xa64) = pcVar2;
  iVar3 = pthread_rwlock_unlock(__rwlock);
  if (iVar3 != 0) {
    _rw_unlock(DAT_00029c78,(char *)0x2b53,pcVar2,line);
  }
  (**DAT_00029c6c)();
  line_00 = DAT_00029c74;
  if (*DAT_00029c70 == '\0') {
    pcVar2 = *DAT_00029c74 + cgpu->threads;
    *DAT_00029c74 = pcVar2;
  }
  else {
    pcVar2 = (char *)cgpu->threads;
    line_00 = (char **)(pcVar2 + *(int *)(iVar1 + 0xa68));
    *(char ***)(iVar1 + 0xa68) = line_00;
  }
  iVar1 = pthread_rwlock_init((pthread_rwlock_t *)&cgpu->qlock,(pthread_rwlockattr_t *)0x0);
  if (iVar1 != 0) {
    _rwlock_init(DAT_00029c78,(char *)0x2b5e,pcVar2,(int)line_00);
  }
  cgpu->queued_work = (work *)0x0;
  return;
}

