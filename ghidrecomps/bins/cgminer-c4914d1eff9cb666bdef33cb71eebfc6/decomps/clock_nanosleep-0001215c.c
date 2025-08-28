
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_nanosleep(clockid_t __clock_id,int __flags,timespec *__req,timespec *__rem)

{
  int iVar1;
  
  iVar1 = clock_nanosleep(__clock_id,__flags,__req,__rem);
  return iVar1;
}

