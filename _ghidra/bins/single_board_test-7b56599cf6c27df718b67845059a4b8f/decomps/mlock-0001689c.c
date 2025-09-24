
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mlock(void *__addr,size_t __len)

{
  int iVar1;
  
  iVar1 = mlock(__addr,__len);
  return iVar1;
}

