
bool rand_drbg_restart(int param_1,int param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int line;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    ERR_put_error(0x24,0x66,0x44,"crypto/rand/drbg_lib.c",0x1de);
    *(undefined4 *)(param_1 + 0x5c) = 2;
    rand_pool_free(*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
    return false;
  }
  if (param_2 != 0) {
    if (param_4 == 0) {
      if (*(uint *)(param_1 + 0x3c) < param_3) {
        ERR_put_error(0x24,0x66,0x66,"crypto/rand/drbg_lib.c",0x1fb);
        *(undefined4 *)(param_1 + 0x5c) = 2;
        return false;
      }
      goto LAB_0014b196;
    }
    if (*(uint *)(param_1 + 0x2c) < param_3) {
      line = 0x1e9;
      iVar2 = 0x6a;
LAB_0014b21e:
      ERR_put_error(0x24,0x66,iVar2,"crypto/rand/drbg_lib.c",line);
      *(undefined4 *)(param_1 + 0x5c) = 2;
      return false;
    }
    if (param_3 * 8 < param_4) {
      line = 0x1ef;
      iVar2 = 0x7c;
      goto LAB_0014b21e;
    }
    iVar2 = rand_pool_attach(param_2,param_3,param_4);
    *(int *)(param_1 + 0x18) = iVar2;
    if (iVar2 == 0) {
      return false;
    }
  }
  param_3 = 0;
  param_2 = 0;
LAB_0014b196:
  iVar2 = *(int *)(param_1 + 0x5c);
  if (iVar2 == 2) {
    RAND_DRBG_uninstantiate(param_1);
    iVar2 = *(int *)(param_1 + 0x5c);
  }
  bVar1 = false;
  if (iVar2 == 0) {
    RAND_DRBG_instantiate(param_1,"OpenSSL NIST SP 800-90A DRBG",0x1c);
    iVar2 = *(int *)(param_1 + 0x5c);
    bVar1 = iVar2 == 1;
  }
  if (iVar2 == 1) {
    if (param_2 == 0) {
      if ((!bVar1) && (iVar2 = RAND_DRBG_reseed(param_1,0,0), iVar2 == 0)) {
        ERR_put_error(0x24,0x66,0x76,"crypto/rand/drbg_lib.c",0x221);
      }
    }
    else {
      (**(code **)(*(int *)(param_1 + 0xf0) + 4))(param_1,param_2,param_3,0,0);
    }
  }
  rand_pool_free(*(undefined4 *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x18) = 0;
  return *(int *)(param_1 + 0x5c) == 1;
}

