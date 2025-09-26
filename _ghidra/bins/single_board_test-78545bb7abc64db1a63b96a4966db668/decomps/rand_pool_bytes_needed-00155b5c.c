
uint rand_pool_bytes_needed(undefined4 *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_r6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  iVar2 = rand_pool_entropy_needed();
  if (param_2 == 0) {
    ERR_put_error(0x24,0x73,0x69,"crypto/rand/rand_lib.c",0x29f);
    return 0;
  }
  uVar8 = param_1[5];
  uVar3 = param_1[1];
  uVar7 = uVar8 - uVar3;
  uVar6 = param_2 * iVar2 + 7U >> 3;
  if (uVar6 <= uVar7) {
    if ((uVar3 < (uint)param_1[4]) && (uVar5 = param_1[4] - uVar3, uVar6 < uVar5)) {
      uVar6 = uVar5;
    }
    uVar5 = param_1[6];
    if (uVar6 <= uVar5 - uVar3) {
      return uVar6;
    }
    bVar9 = uVar6 == uVar7;
    if (uVar6 <= uVar7) {
      bVar9 = param_1[2] == 0;
    }
    if (bVar9) {
      do {
        uVar4 = uVar5 * 2;
        if (uVar8 >> 1 <= uVar5) {
          unaff_r6 = uVar8;
        }
        bVar9 = uVar5 < uVar8 >> 1;
        uVar5 = unaff_r6;
        uVar1 = uVar7;
        if (bVar9) {
          uVar5 = uVar4;
          uVar1 = uVar4 - uVar3;
        }
        unaff_r6 = uVar5;
      } while (uVar1 < uVar6);
      if (param_1[3] == 0) {
        __dest = (void *)CRYPTO_zalloc(uVar5,"crypto/rand/rand_lib.c",0x283);
      }
      else {
        __dest = (void *)CRYPTO_secure_zalloc(uVar5,"crypto/rand/rand_lib.c",0x281);
      }
      if (__dest != (void *)0x0) {
        memcpy(__dest,(void *)*param_1,param_1[1]);
        if (param_1[3] == 0) {
          CRYPTO_clear_free(*param_1,param_1[6],"crypto/rand/rand_lib.c",0x28c);
        }
        else {
          CRYPTO_secure_clear_free(*param_1,param_1[6],"crypto/rand/rand_lib.c",0x28a);
        }
        *param_1 = __dest;
        param_1[6] = uVar5;
        return uVar6;
      }
      ERR_put_error(0x24,0x7d,0x41,"crypto/rand/rand_lib.c",0x285);
    }
    else {
      ERR_put_error(0x24,0x7d,0x44,"crypto/rand/rand_lib.c",0x278);
    }
    param_1[1] = 0;
    param_1[5] = 0;
    return 0;
  }
  ERR_put_error(0x24,0x73,0x7d,"crypto/rand/rand_lib.c",0x2a7);
  return 0;
}

