
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA * DSA_new(void)

{
  DSA *pDVar1;
  
  pDVar1 = DSA_new_method((ENGINE *)0x0);
  return pDVar1;
}

