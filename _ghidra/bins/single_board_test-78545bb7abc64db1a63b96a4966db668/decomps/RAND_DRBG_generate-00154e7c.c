
undefined4
RAND_DRBG_generate(int param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5,
                  uint param_6)

{
  __pid_t _Var1;
  time_t tVar2;
  int iVar3;
  bool bVar4;
  
  if (*(int *)(param_1 + 0x5c) != 1) {
    rand_drbg_restart(param_1,0,0);
    if (*(int *)(param_1 + 0x5c) == 2) {
      ERR_put_error(0x24,0x6b,0x72,"crypto/rand/drbg_lib.c",0x242);
      return 0;
    }
    if (*(int *)(param_1 + 0x5c) == 0) {
      ERR_put_error(0x24,0x6b,0x73,"crypto/rand/drbg_lib.c",0x246);
      return 0;
    }
  }
  if (*(uint *)(param_1 + 0x24) < param_3) {
    ERR_put_error(0x24,0x6b,0x75,"crypto/rand/drbg_lib.c",0x24c);
    return 0;
  }
  if (*(uint *)(param_1 + 0x3c) < param_6) {
    ERR_put_error(0x24,0x6b,0x66,"crypto/rand/drbg_lib.c",0x250);
  }
  else {
    _Var1 = openssl_get_fork_id();
    bVar4 = _Var1 != *(int *)(param_1 + 0x10);
    if (bVar4) {
      *(__pid_t *)(param_1 + 0x10) = _Var1;
    }
    if ((*(uint *)(param_1 + 0x44) != 0) && (*(uint *)(param_1 + 0x44) <= *(uint *)(param_1 + 0x40))
       ) {
      bVar4 = true;
    }
    if (0 < *(int *)(param_1 + 0x4c)) {
      tVar2 = time((time_t *)0x0);
      if (tVar2 < *(int *)(param_1 + 0x48)) {
        bVar4 = true;
      }
      else if (*(int *)(param_1 + 0x4c) <= tVar2 - *(int *)(param_1 + 0x48)) {
        bVar4 = true;
      }
    }
    if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 4) != 0)) {
      DataMemoryBarrier(0x1b);
      DataMemoryBarrier(0x1b);
      if (*(int *)(param_1 + 0x54) != *(int *)(*(int *)(param_1 + 4) + 0x54)) {
        bVar4 = true;
      }
    }
    if (bVar4 || param_4 != 0) {
      iVar3 = RAND_DRBG_reseed(param_1,param_5,param_6,param_4);
      if (iVar3 == 0) {
        ERR_put_error(0x24,0x6b,0x76,"crypto/rand/drbg_lib.c",0x26c);
        return 0;
      }
      param_6 = 0;
      param_5 = 0;
    }
    iVar3 = (**(code **)(*(int *)(param_1 + 0xf0) + 8))(param_1,param_2,param_3,param_5,param_6);
    if (iVar3 != 0) {
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x5c) = 2;
    ERR_put_error(0x24,0x6b,0x70,"crypto/rand/drbg_lib.c",0x275);
  }
  return 0;
}

