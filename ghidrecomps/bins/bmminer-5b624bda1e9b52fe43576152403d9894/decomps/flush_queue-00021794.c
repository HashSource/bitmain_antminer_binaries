
/* WARNING: Unknown calling convention */

void flush_queue(cgpu_info *cgpu)

{
  int line;
  int ret;
  int iVar1;
  work *func;
  work *work;
  char tmp42 [2048];
  
  work = (work *)0x0;
  if (cgpu != (cgpu_info *)0x0) {
    line = pthread_rwlock_trywrlock((pthread_rwlock_t *)&cgpu->qlock);
    if (line == 0) {
      func = cgpu->unqueued_work;
      cgpu->unqueued_work = (work *)0x0;
      work = func;
      iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
      if (iVar1 != 0) {
        _rw_unlock(DAT_0002183c,(char *)0x2520,(char *)func,line);
      }
      (**DAT_00021834)();
      if (((work != (work *)0x0) &&
          (_free_work(&work,DAT_00021838,DAT_0002183c->__size,0x2524), *DAT_00021840 != '\0')) &&
         ((*DAT_00021844 != '\0' || ((*DAT_00021848 != '\0' || (6 < *DAT_00021850)))))) {
        tmp42._0_4_ = *DAT_0002184c;
        tmp42._4_4_ = DAT_0002184c[1];
        tmp42._8_4_ = DAT_0002184c[2];
        tmp42._12_4_ = DAT_0002184c[3];
        tmp42._16_4_ = DAT_0002184c[4];
        tmp42._20_4_ = DAT_0002184c[5];
        tmp42._24_2_ = (undefined2)DAT_0002184c[6];
        tmp42[26] = (char)((uint)DAT_0002184c[6] >> 0x10);
        _applog(7,tmp42,false);
      }
    }
  }
  return;
}

