
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int shmget(key_t __key,size_t __size,int __shmflg)

{
  int iVar1;
  
  iVar1 = shmget(__key,__size,__shmflg);
  return iVar1;
}

