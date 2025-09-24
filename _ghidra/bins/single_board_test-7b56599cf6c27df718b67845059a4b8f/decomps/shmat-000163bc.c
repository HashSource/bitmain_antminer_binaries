
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * shmat(int __shmid,void *__shmaddr,int __shmflg)

{
  void *pvVar1;
  
  pvVar1 = shmat(__shmid,__shmaddr,__shmflg);
  return pvVar1;
}

