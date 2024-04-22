
/* WARNING: Unknown calling convention */

void * restart_thread(void *arg)

{
  _func_void_cgpu_info_ptr **pp_Var1;
  pthread_t __th;
  int iVar2;
  cgpu_info *pcVar3;
  char *in_r2;
  int in_r3;
  int *piVar4;
  _func_void_cgpu_info_ptr *line;
  int iVar5;
  cgpu_info *cgpu;
  int mt;
  
  __th = pthread_self();
  pthread_detach(__th);
  discard_stale();
  iVar2 = pthread_rwlock_rdlock(DAT_000284b4);
  if (iVar2 != 0) {
    _rd_lock(DAT_000284c4,(char *)0x14e0,in_r2,in_r3);
  }
  iVar2 = *DAT_000284b8;
  piVar4 = DAT_000284b8;
  pcVar3 = (cgpu_info *)pthread_rwlock_unlock(DAT_000284b4);
  if (pcVar3 != (cgpu_info *)0x0) {
    pcVar3 = (cgpu_info *)DAT_000284c4;
    _rw_unlock(DAT_000284c4,(char *)0x14e2,in_r2,(int)piVar4);
  }
  pp_Var1 = DAT_000284c8;
  line = *DAT_000284c8;
  (*line)(pcVar3);
  piVar4 = DAT_000284cc;
  if (0 < iVar2) {
    iVar5 = 0;
    do {
      while( true ) {
        line = *(_func_void_cgpu_info_ptr **)(*piVar4 + iVar5 * 4);
        iVar5 = iVar5 + 1;
        pcVar3 = *(cgpu_info **)(line + 0x24);
        if ((pcVar3 == (cgpu_info *)0x0) || (in_r2 = (char *)pcVar3->deven, in_r2 != (char *)0x0))
        break;
        line[0x3e] = (code)0x1;
        flush_queue(pcVar3);
        line = pcVar3->drv->flush_work;
        (*line)(pcVar3);
        if (iVar5 == iVar2) goto LAB_00028460;
      }
    } while (iVar5 != iVar2);
  }
LAB_00028460:
  iVar2 = pthread_mutex_lock(DAT_000284bc);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_000284c4,(char *)0x14f7,in_r2,(int)line);
  }
  pthread_cond_broadcast(DAT_000284c0);
  pcVar3 = (cgpu_info *)pthread_mutex_unlock(DAT_000284bc);
  if (pcVar3 != (cgpu_info *)0x0) {
    pcVar3 = (cgpu_info *)DAT_000284c4;
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_000284c4,(char *)0x14f9,in_r2,(int)line);
  }
  (**pp_Var1)(pcVar3);
  return (void *)0x0;
}

