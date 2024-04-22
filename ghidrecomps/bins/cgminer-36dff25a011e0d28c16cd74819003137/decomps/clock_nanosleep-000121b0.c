
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_nanosleep(clockid_t __clock_id,int __flags,timespec *__req,timespec *__rem)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_clock_nanosleep_000c00c8)();
  return iVar1;
}

