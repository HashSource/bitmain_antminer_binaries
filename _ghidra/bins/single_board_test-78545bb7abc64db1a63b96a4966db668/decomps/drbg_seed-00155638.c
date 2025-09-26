
int drbg_seed(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  double dVar5;
  
  iVar2 = RAND_DRBG_get0_master();
  uVar4 = param_2 >> 0x1f;
  if (iVar2 == 0) {
    uVar4 = 1;
  }
  if (uVar4 == 0) {
    dVar5 = (double)(longlong)(int)param_2;
    iVar1 = (uint)(dVar5 < 0.0) << 0x1f;
    if (iVar1 < 0) {
      iVar2 = 0;
    }
    iVar3 = iVar2;
    if (-1 < iVar1) {
      rand_drbg_lock();
      uVar4 = rand_drbg_seedlen(iVar2);
      if (param_2 < uVar4) {
        dVar5 = 0.0;
      }
      else if ((int)((uint)(dVar5 < (double)(longlong)(int)uVar4) << 0x1f) < 0) {
        dVar5 = 0.0;
      }
      if ((int)((uint)((double)uVar4 < dVar5) << 0x1f) < 0) {
        dVar5 = (double)uVar4;
      }
      iVar3 = rand_drbg_restart(iVar2,param_1,param_2,
                                (uint)(0.0 < dVar5 * 8.0) * (int)(longlong)(dVar5 * 8.0));
      rand_drbg_unlock(iVar2);
    }
    return iVar3;
  }
  return 0;
}

