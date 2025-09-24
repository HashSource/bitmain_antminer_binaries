
int * rand_pool_new(int param_1,int param_2,uint param_3,uint param_4)

{
  int *ptr;
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x10;
  }
  ptr = (int *)CRYPTO_THREAD_run_once(&rand_init,0x14bc91);
  if ((ptr != (int *)0x0) && (ptr = do_rand_init_ossl_ret_, do_rand_init_ossl_ret_ != (int *)0x0)) {
    ptr = (int *)CRYPTO_zalloc(0x24,"crypto/rand/rand_lib.c",0x1bd);
    if (ptr == (int *)0x0) {
      ERR_put_error(0x24,0x74,0x41,"crypto/rand/rand_lib.c",0x1bf);
    }
    else {
      if (0x2fff < param_4) {
        param_4 = 0x3000;
      }
      if (uVar2 < param_3) {
        uVar2 = param_3;
      }
      bVar3 = uVar2 <= param_4;
      ptr[5] = param_4;
      ptr[4] = param_3;
      if (!bVar3) {
        uVar2 = param_4;
      }
      if (bVar3) {
        ptr[6] = uVar2;
      }
      if (!bVar3) {
        ptr[6] = param_4;
      }
      if (param_2 == 0) {
        iVar1 = CRYPTO_zalloc(uVar2,"crypto/rand/rand_lib.c",0x1cd);
        *ptr = iVar1;
      }
      else {
        iVar1 = CRYPTO_secure_zalloc(uVar2,"crypto/rand/rand_lib.c",0x1cb);
        *ptr = iVar1;
      }
      if (iVar1 == 0) {
        ERR_put_error(0x24,0x74,0x41,"crypto/rand/rand_lib.c",0x1d0);
        CRYPTO_free(ptr);
        ptr = (int *)0x0;
      }
      else {
        ptr[8] = param_1;
        ptr[3] = param_2;
      }
    }
  }
  return ptr;
}

