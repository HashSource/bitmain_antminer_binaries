
int ERR_set_implementation(ERR_FNS *fns)

{
  bool bVar1;
  ERR_FNS *pEVar2;
  
  CRYPTO_lock(9,1,"err.c",0x139);
  bVar1 = err_fns == (ERR_FNS *)0x0;
  pEVar2 = fns;
  if (!bVar1) {
    pEVar2 = err_fns;
  }
  err_fns = pEVar2;
  CRYPTO_lock(10,1,"err.c",0x142);
  return (uint)bVar1;
}

