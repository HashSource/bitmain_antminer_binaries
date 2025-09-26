
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DH * DH_new(void)

{
  DH *pDVar1;
  
  pDVar1 = DH_new_method((ENGINE *)0x0);
  return pDVar1;
}

