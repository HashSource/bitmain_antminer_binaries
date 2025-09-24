
undefined4 CRYPTO_atomic_add(int *param_1,int param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(param_1);
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 + param_2;
  DataMemoryBarrier(0x1b);
  *param_3 = iVar2 + param_2;
  return 1;
}

