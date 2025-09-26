
undefined4 rand_pool_add(int *param_1,void *param_2,uint param_3,int param_4)

{
  uint uVar1;
  int line;
  uint uVar2;
  uint uVar3;
  void *__dest;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1[5];
  uVar1 = param_1[1];
  if (uVar4 - uVar1 < param_3) {
    ERR_put_error(0x24,0x67,0x6a,"crypto/rand/rand_lib.c",0x2d8);
    return 0;
  }
  __dest = (void *)*param_1;
  if (__dest == (void *)0x0) {
    line = 0x2dd;
  }
  else {
    if (param_3 == 0) {
      return 1;
    }
    uVar2 = param_1[6];
    if ((uVar2 <= uVar1) || (param_2 != (void *)((int)__dest + uVar1))) {
      if (uVar2 - uVar1 < param_3) {
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
        } while (uVar3 - uVar1 < param_3);
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
        uVar1 = param_1[1];
        *param_1 = (int)__dest;
        param_1[6] = uVar5;
      }
      memcpy((void *)(uVar1 + (int)__dest),param_2,param_3);
      param_1[1] = param_3 + param_1[1];
      param_1[7] = param_4 + param_1[7];
      return 1;
    }
    line = 0x2eb;
  }
  ERR_put_error(0x24,0x67,0x44,"crypto/rand/rand_lib.c",line);
  return 0;
}

