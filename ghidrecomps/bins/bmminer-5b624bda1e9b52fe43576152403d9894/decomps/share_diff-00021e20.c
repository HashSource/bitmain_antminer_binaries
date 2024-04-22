
/* WARNING: Unknown calling convention */

uint64_t share_diff(work *work)

{
  uint64_t *puVar1;
  char *buf;
  int iVar2;
  uint bufsiz;
  char *in_r2;
  char *func;
  int in_r3;
  uint line;
  bool bVar3;
  bool bVar4;
  double dVar5;
  uint64_t uVar6;
  undefined4 in_stack_fffff7d8;
  uint in_stack_fffff7dc;
  char tmp42 [2048];
  
  __aeabi_ul2d(*(undefined4 *)(work->hash + 0x18),*(undefined4 *)(work->hash + 0x1c));
  __aeabi_ul2d(*(undefined4 *)(work->hash + 0x10),*(undefined4 *)(work->hash + 0x14));
  __aeabi_ul2d(*(undefined4 *)(work->hash + 8),*(undefined4 *)(work->hash + 0xc));
  __aeabi_ul2d(*(undefined4 *)work->hash,*(undefined4 *)(work->hash + 4));
  dVar5 = round((double)CONCAT44(in_stack_fffff7dc,in_stack_fffff7d8));
  uVar6 = __fixunsdfdi(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  bufsiz = (uint)(uVar6 >> 0x20);
  buf = (char *)uVar6;
  iVar2 = pthread_mutex_lock(DAT_00021fb8);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_00021fc8,(char *)0x13ba,in_r2,in_r3);
  }
  iVar2 = pthread_rwlock_wrlock(DAT_00021fbc);
  if (iVar2 != 0) {
    _wr_lock(DAT_00021fc8,(char *)0x13ba,in_r2,in_r3);
  }
  iVar2 = DAT_00021fdc;
  bVar3 = bufsiz <= *(uint *)((int)DAT_00021fc0 + 4);
  if (*(uint *)((int)DAT_00021fc0 + 4) == bufsiz) {
    bVar3 = buf <= *(char **)DAT_00021fc0;
  }
  if (!bVar3) {
    *DAT_00021fc0 = uVar6;
    suffix_string((ulonglong)in_stack_fffff7dc << 0x20,buf,bufsiz,iVar2);
  }
  puVar1 = &work->pool->best_diff;
  func = *(char **)puVar1;
  line = *(uint *)((int)&work->pool->best_diff + 4);
  bVar4 = bufsiz <= line;
  if (line == bufsiz) {
    bVar4 = buf <= func;
  }
  if (!bVar4) {
    *puVar1 = uVar6;
  }
  iVar2 = pthread_rwlock_unlock(DAT_00021fbc);
  if (iVar2 != 0) {
    _rw_unlock(DAT_00021fc8,(char *)0x13c8,func,line);
  }
  iVar2 = pthread_mutex_unlock(DAT_00021fb8);
  if (iVar2 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_00021fc8,(char *)0x13c8,func,line);
  }
  (**DAT_00021fc4)();
  if ((!bVar3) && (((*DAT_00021fcc != '\0' || (*DAT_00021fd0 != '\0')) || (5 < *DAT_00021fd4)))) {
    snprintf(tmp42,0x800,DAT_00021fd8,DAT_00021fdc);
    _applog(6,tmp42,false);
  }
  return uVar6;
}

