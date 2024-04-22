
uint BN_GF2m_mod_mul(undefined4 param_1,undefined4 param_2,undefined4 param_3,BIGNUM *param_4,
                    undefined4 param_5)

{
  int iVar1;
  void *ptr;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  bool bVar9;
  
  iVar1 = BN_num_bits(param_4);
  iVar1 = iVar1 + 1;
  ptr = CRYPTO_malloc(iVar1 * 4,DAT_001234d0,0x229);
  if (ptr == (void *)0x0) {
    return 0;
  }
  iVar4 = param_4->top;
  if (iVar4 == 0) {
    uVar7 = 0;
  }
  else {
    iVar2 = iVar4 + -1;
    if (iVar2 < 0) {
      uVar7 = 0;
    }
    else {
      iVar3 = iVar2 * 0x20;
      uVar7 = 0;
      puVar8 = param_4->d + iVar4;
      do {
        puVar8 = puVar8 + -1;
        uVar6 = *puVar8;
        if (uVar6 != 0) {
          iVar4 = 0x1f;
          uVar5 = 0x80000000;
          while( true ) {
            uVar6 = uVar6 & uVar5;
            uVar5 = uVar5 >> 1;
            if (uVar6 != 0) {
              if ((int)uVar7 < iVar1) {
                *(int *)((int)ptr + uVar7 * 4) = iVar4 + iVar3;
              }
              uVar7 = uVar7 + 1;
            }
            bVar9 = iVar4 == 0;
            iVar4 = iVar4 + -1;
            if (bVar9) break;
            uVar6 = *puVar8;
          }
        }
        iVar3 = iVar3 + -0x20;
        bVar9 = iVar2 != 0;
        iVar2 = iVar2 + -1;
      } while (bVar9);
    }
    if ((int)uVar7 < iVar1) {
      *(undefined4 *)((int)ptr + uVar7 * 4) = 0xffffffff;
      uVar7 = uVar7 + 1;
    }
    uVar6 = 1 - uVar7;
    if (1 < uVar7) {
      uVar6 = 0;
    }
    if (iVar1 < (int)uVar7) {
      uVar6 = uVar6 | 1;
    }
    if (uVar6 == 0) {
      uVar7 = BN_GF2m_mod_mul_arr(param_1,param_2,param_3,ptr,param_5);
      goto LAB_001234a6;
    }
  }
  ERR_put_error(3,0x85,0x6a,DAT_001234d0,0x22d);
LAB_001234a6:
  CRYPTO_free(ptr);
  return uVar7;
}

