
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_timedwait(sem_t *__sem,timespec *__abstime)

{
  int iVar1;
  
  iVar1 = sem_timedwait(__sem,__abstime);
  return iVar1;
}

