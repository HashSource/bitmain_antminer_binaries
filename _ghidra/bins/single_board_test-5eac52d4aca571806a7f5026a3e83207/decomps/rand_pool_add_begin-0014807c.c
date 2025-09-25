
int rand_pool_add_begin(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *__dest;
  uint uVar4;
  uint uVar5;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar4 = param_1[5];
  iVar1 = param_1[1];
  if (uVar4 - iVar1 < param_2) {
    iVar1 = 0;
    ERR_put_error(0x24,0x71,0x7d,"crypto/rand/rand_lib.c",0x311);
  }
  else {
    __dest = (void *)*param_1;
    if (__dest == (void *)0x0) {
      ERR_put_error(0x24,0x71,0x44,"crypto/rand/rand_lib.c",0x316);
      iVar1 = 0;
    }
    else {
      if ((uint)(param_1[6] - iVar1) < param_2) {
        uVar2 = param_1[6];
        if (param_1[2] != 0) {
          ERR_put_error(0x24,0x7d,0x44,"crypto/rand/rand_lib.c",0x278);
          return 0;
        }
        do {
          uVar3 = uVar2 * 2;
          uVar5 = uVar4;
          if (uVar4 >> 1 <= uVar2) break;
          uVar2 = uVar3;
          uVar5 = uVar3;
        } while (uVar3 - iVar1 < param_2);
        if (param_1[3] == 0) {
          __dest = (void *)CRYPTO_zalloc(uVar5,"crypto/rand/rand_lib.c",0x283);
        }
        else {
          __dest = (void *)CRYPTO_secure_zalloc(uVar5,"crypto/rand/rand_lib.c",0x281);
        }
        if (__dest == (void *)0x0) {
          ERR_put_error(0x24,0x7d,0x41,"crypto/rand/rand_lib.c",0x285);
          return 0;
        }
        memcpy(__dest,(void *)*param_1,param_1[1]);
        if (param_1[3] == 0) {
          CRYPTO_clear_free(*param_1,param_1[6],"crypto/rand/rand_lib.c",0x28c);
        }
        else {
          CRYPTO_secure_clear_free(*param_1,param_1[6],"crypto/rand/rand_lib.c",0x28a);
        }
        iVar1 = param_1[1];
        *param_1 = (int)__dest;
        param_1[6] = uVar5;
      }
      iVar1 = (int)__dest + iVar1;
    }
  }
  return iVar1;
}

