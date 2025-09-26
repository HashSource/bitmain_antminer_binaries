
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long syscall(long __sysno,...)

{
  long lVar1;
  
  lVar1 = syscall(__sysno);
  return lVar1;
}

