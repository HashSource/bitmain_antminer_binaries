
int RAND_DRBG_secure_new(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  __pid_t _Var5;
  
  iVar3 = CRYPTO_secure_zalloc(0x104,"crypto/rand/drbg_lib.c",0xbf);
  if (iVar3 == 0) {
    ERR_put_error(0x24,0x6d,0x41,"crypto/rand/drbg_lib.c",0xc3);
    return 0;
  }
  iVar4 = CRYPTO_secure_allocated();
  if (iVar4 != 0) {
    iVar4 = 1;
  }
  *(int *)(iVar3 + 8) = iVar4;
  _Var5 = openssl_get_fork_id();
  *(int *)(iVar3 + 4) = param_3;
  *(__pid_t *)(iVar3 + 0x10) = _Var5;
  if (param_3 == 0) {
    *(undefined4 *)(iVar3 + 0xf4) = 0x1481e9;
    *(undefined4 *)(iVar3 + 0xf8) = 0x147aa9;
    uVar2 = master_reseed_time_interval;
    uVar1 = master_reseed_interval;
    *(undefined4 *)(iVar3 + 0xfc) = 0x148005;
    *(undefined4 *)(iVar3 + 0x44) = uVar1;
    *(undefined4 *)(iVar3 + 0x4c) = uVar2;
    *(undefined4 *)(iVar3 + 0x100) = 0x147ae1;
    iVar4 = RAND_DRBG_set(iVar3,param_1,param_2);
    if (iVar4 != 0) {
      return iVar3;
    }
  }
  else {
    *(undefined4 *)(iVar3 + 0xf4) = 0x1481e9;
    uVar2 = slave_reseed_time_interval;
    uVar1 = slave_reseed_interval;
    *(undefined4 *)(iVar3 + 0xf8) = 0x147aa9;
    *(undefined4 *)(iVar3 + 0x44) = uVar1;
    *(undefined4 *)(iVar3 + 0x4c) = uVar2;
    iVar4 = RAND_DRBG_set(iVar3,param_1,param_2);
    if (iVar4 != 0) {
      rand_drbg_lock(param_3);
      if (*(int *)(iVar3 + 0x20) <= *(int *)(param_3 + 0x20)) {
        rand_drbg_unlock(param_3);
        return iVar3;
      }
      rand_drbg_unlock(param_3);
      ERR_put_error(0x24,0x6d,0x83,"crypto/rand/drbg_lib.c",0xec);
    }
  }
  RAND_DRBG_free(iVar3);
  return 0;
}

