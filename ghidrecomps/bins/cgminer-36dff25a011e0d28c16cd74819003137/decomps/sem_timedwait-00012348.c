
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_timedwait(sem_t *__sem,timespec *__abstime)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sem_timedwait_000c0150)();
  return iVar1;
}

