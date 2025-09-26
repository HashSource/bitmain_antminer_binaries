
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA * RSA_new(void)

{
  RSA *pRVar1;
  
  pRVar1 = RSA_new_method((ENGINE *)0x0);
  return pRVar1;
}

