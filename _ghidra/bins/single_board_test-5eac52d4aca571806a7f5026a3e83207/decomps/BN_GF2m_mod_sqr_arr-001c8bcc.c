
int BN_GF2m_mod_sqr_arr(undefined4 param_1,int *param_2,undefined4 param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  ulong *puVar9;
  
  BN_CTX_start(param_4);
  pBVar1 = BN_CTX_get(param_4);
  if ((pBVar1 != (BIGNUM *)0x0) && (iVar2 = bn_wexpand(pBVar1,param_2[1] << 1), iVar2 != 0)) {
    iVar2 = param_2[1];
    iVar7 = iVar2 + -1;
    if (-1 < iVar7) {
      puVar8 = (uint *)(*param_2 + iVar2 * 4);
      puVar9 = pBVar1->d + iVar7 * 2 + -7;
      do {
        puVar9[8] = 0;
        iVar7 = iVar7 + -1;
        puVar8 = puVar8 + -1;
        uVar5 = *puVar8;
        HintPreloadData(puVar9);
        uVar3 = uVar5 >> 0xc;
        uVar4 = uVar5 >> 8;
        uVar6 = uVar5 >> 4;
        puVar9[7] = (uVar5 & 4) << 2 | (uVar5 & 8) << 3 | uVar5 & 1 | (uVar5 & 2) << 1 |
                    ((uVar3 & 4) << 2 | (uVar3 & 8) << 3 | uVar3 & 1 | (uVar3 & 2) << 1) << 0x18 |
                    (uVar4 & 1 | (uVar4 & 4) << 2 | (uVar4 & 8) << 3 | (uVar4 & 2) << 1) << 0x10 |
                    ((uVar6 & 4) << 2 | (uVar6 & 8) << 3 | uVar6 & 1 | (uVar6 & 2) << 1) << 8;
        puVar9 = puVar9 + -2;
      } while (iVar7 != -1);
    }
    pBVar1->top = iVar2 << 1;
    bn_correct_top(pBVar1);
    iVar2 = BN_GF2m_mod_arr(param_1,pBVar1,param_3);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
    BN_CTX_end(param_4);
    return iVar2;
  }
  BN_CTX_end(param_4);
  return 0;
}

