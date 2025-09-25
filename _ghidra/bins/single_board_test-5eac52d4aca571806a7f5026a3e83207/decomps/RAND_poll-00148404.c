
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_poll(void)

{
  RAND_METHOD *pRVar1;
  RAND_METHOD *pRVar2;
  int iVar3;
  int iVar4;
  void *buf;
  undefined4 uVar5;
  _func_3915 *p_Var6;
  undefined4 extraout_s1;
  double entropy;
  
  pRVar1 = RAND_get_rand_method();
  if (pRVar1 != (RAND_METHOD *)0x0) {
    pRVar2 = (RAND_METHOD *)RAND_OpenSSL();
    if (pRVar1 == pRVar2) {
      iVar3 = RAND_DRBG_get0_master();
      if (iVar3 != 0) {
        rand_drbg_lock();
        iVar4 = rand_drbg_restart(iVar3,0,0);
        rand_drbg_unlock(iVar3);
        return iVar4;
      }
    }
    else {
      iVar3 = rand_pool_new(0x100,1,0x20,0x3000);
      if (iVar3 != 0) {
        iVar4 = rand_pool_acquire_entropy();
        if (iVar4 == 0) {
          p_Var6 = (_func_3915 *)0x0;
        }
        else {
          p_Var6 = pRVar1->add;
          if (p_Var6 != (_func_3915 *)0x0) {
            buf = (void *)rand_pool_buffer(iVar3);
            iVar4 = rand_pool_length(iVar3);
            uVar5 = rand_pool_entropy(iVar3);
            entropy = (double)FixedToFP(CONCAT44(extraout_s1,uVar5),0x20,0x40,3,1,0);
            iVar4 = (*p_Var6)(buf,iVar4,entropy);
            if (iVar4 != 0) {
              iVar4 = 1;
            }
            rand_pool_free(iVar3);
            return iVar4;
          }
        }
        rand_pool_free(iVar3);
        return (int)p_Var6;
      }
    }
  }
  return 0;
}

