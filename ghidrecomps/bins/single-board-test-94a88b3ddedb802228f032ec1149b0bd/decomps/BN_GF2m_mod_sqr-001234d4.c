
uint BN_GF2m_mod_sqr(undefined4 param_1,undefined4 param_2,BIGNUM *param_3,undefined4 param_4)

{
  int iVar1;
  void *ptr;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulong *puVar8;
  bool bVar9;
  
  iVar1 = BN_num_bits(param_3);
  iVar1 = iVar1 + 1;
  ptr = CRYPTO_malloc(iVar1 * 4,DAT_001235ac,0x264);
  if (ptr == (void *)0x0) {
    return 0;
  }
  iVar3 = param_3->top;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    iVar7 = iVar3 + -1;
    if (iVar7 < 0) {
      uVar6 = 0;
    }
    else {
      iVar2 = iVar7 * 0x20;
      uVar6 = 0;
      puVar8 = param_3->d + iVar3;
      do {
        puVar8 = puVar8 + -1;
        uVar5 = *puVar8;
        if (uVar5 != 0) {
          iVar3 = 0x1f;
          uVar4 = 0x80000000;
          while( true ) {
            uVar5 = uVar5 & uVar4;
            uVar4 = uVar4 >> 1;
            if (uVar5 != 0) {
              if ((int)uVar6 < iVar1) {
                *(int *)((int)ptr + uVar6 * 4) = iVar3 + iVar2;
              }
              uVar6 = uVar6 + 1;
            }
            bVar9 = iVar3 == 0;
            iVar3 = iVar3 + -1;
            if (bVar9) break;
            uVar5 = *puVar8;
          }
        }
        iVar7 = iVar7 + -1;
        iVar2 = iVar2 + -0x20;
      } while (iVar7 != -1);
    }
    if ((int)uVar6 < iVar1) {
      *(undefined4 *)((int)ptr + uVar6 * 4) = 0xffffffff;
      uVar6 = uVar6 + 1;
    }
    uVar5 = 1 - uVar6;
    if (1 < uVar6) {
      uVar5 = 0;
    }
    if (iVar1 < (int)uVar6) {
      uVar5 = uVar5 | 1;
    }
    if (uVar5 == 0) {
      uVar6 = BN_GF2m_mod_sqr_arr(param_1,param_2,ptr,param_4);
      goto LAB_00123584;
    }
  }
  ERR_put_error(3,0x88,0x6a,DAT_001235ac,0x268);
LAB_00123584:
  CRYPTO_free(ptr);
  return uVar6;
}

