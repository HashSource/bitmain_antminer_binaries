
/* WARNING: Type propagation algorithm not settling */

BIGNUM * BN_GF2m_mod_sqrt(BIGNUM *param_1,undefined4 param_2,BIGNUM *param_3,BN_CTX *param_4)

{
  int iVar1;
  int *ptr;
  int iVar2;
  BIGNUM *a;
  int iVar3;
  uint uVar4;
  uint uVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  int iVar8;
  bool bVar9;
  
  iVar1 = BN_num_bits(param_3);
  iVar1 = iVar1 + 1;
  ptr = (int *)CRYPTO_malloc(iVar1 * 4,DAT_00123f04,0x446);
  if (ptr == (int *)0x0) {
    return (BIGNUM *)0x0;
  }
  iVar3 = param_3->top;
  if (iVar3 == 0) {
    pBVar6 = (BIGNUM *)0x0;
  }
  else {
    iVar8 = iVar3 + -1;
    if (iVar8 < 0) {
      pBVar6 = (BIGNUM *)0x0;
    }
    else {
      iVar2 = iVar8 * 0x20;
      pBVar6 = (BIGNUM *)0x0;
      puVar7 = param_3->d + iVar3;
      do {
        puVar7 = puVar7 + -1;
        uVar5 = *puVar7;
        if (uVar5 != 0) {
          iVar3 = 0x1f;
          uVar4 = 0x80000000;
          while( true ) {
            uVar5 = uVar5 & uVar4;
            uVar4 = uVar4 >> 1;
            if (uVar5 != 0) {
              if ((int)pBVar6 < iVar1) {
                ptr[(int)pBVar6] = iVar3 + iVar2;
              }
              pBVar6 = (BIGNUM *)((int)&pBVar6->d + 1);
            }
            bVar9 = iVar3 == 0;
            iVar3 = iVar3 + -1;
            if (bVar9) break;
            uVar5 = *puVar7;
          }
        }
        iVar8 = iVar8 + -1;
        iVar2 = iVar2 + -0x20;
      } while (iVar8 != -1);
    }
    if ((int)pBVar6 < iVar1) {
      ptr[(int)pBVar6] = -1;
      pBVar6 = (BIGNUM *)((int)&pBVar6->d + 1);
    }
    uVar5 = 1 - (int)pBVar6;
    if ((BIGNUM *)0x1 < pBVar6) {
      uVar5 = 0;
    }
    if (iVar1 < (int)pBVar6) {
      uVar5 = uVar5 | 1;
    }
    if (uVar5 == 0) {
      if (*ptr != 0) {
        BN_CTX_start(param_4);
        a = BN_CTX_get(param_4);
        pBVar6 = a;
        if ((a != (BIGNUM *)0x0) &&
           (pBVar6 = (BIGNUM *)BN_set_bit(a,*ptr + -1), pBVar6 != (BIGNUM *)0x0)) {
          pBVar6 = (BIGNUM *)BN_GF2m_mod_exp_arr(param_1,param_2,a,ptr,param_4);
        }
        BN_CTX_end(param_4);
        CRYPTO_free(ptr);
        return pBVar6;
      }
      pBVar6 = (BIGNUM *)0x1;
      BN_set_word(param_1,0);
      goto LAB_00123ed8;
    }
  }
  ERR_put_error(3,0x89,0x6a,DAT_00123f04,0x44a);
LAB_00123ed8:
  CRYPTO_free(ptr);
  return pBVar6;
}

