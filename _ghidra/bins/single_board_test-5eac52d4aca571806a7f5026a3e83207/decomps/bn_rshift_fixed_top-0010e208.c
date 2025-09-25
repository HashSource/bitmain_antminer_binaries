
int bn_rshift_fixed_top(BIGNUM *param_1,BIGNUM *param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  ulong *puVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  char in_CY;
  
  uVar10 = param_3 + 0x3f & (int)param_3 >> 0x20;
  if (in_CY == '\0') {
    uVar10 = param_3;
  }
  iVar12 = (int)uVar10 >> 6;
  if (iVar12 < param_2->top) {
    param_3 = param_3 & 0x3f;
    uVar10 = 0x40 - param_3 & 0x3f;
    iVar13 = param_2->top - iVar12;
    uVar11 = -uVar10 | -uVar10 >> 8;
    if ((param_2 == param_1) || (iVar1 = bn_wexpand(param_1,iVar13), iVar1 != 0)) {
      puVar8 = param_2->d;
      iVar14 = iVar13 + -1;
      puVar6 = param_1->d;
      uVar2 = puVar8[iVar12];
      if (iVar14 == 0) {
        iVar14 = 0;
      }
      else {
        if (iVar13 < 10) {
          iVar1 = 0;
        }
        else {
          iVar1 = 0;
          puVar7 = puVar8 + iVar12 + 0x10;
          puVar9 = puVar6 + 0xf;
          do {
            uVar5 = puVar7[-0xf];
            HintPreloadData(puVar7);
            iVar1 = iVar1 + 8;
            HintPreloadData(puVar9);
            puVar9[-0xf] = uVar5 << uVar10 & uVar11 | uVar2 >> param_3;
            uVar3 = puVar7[-0xe];
            puVar9[-0xe] = uVar3 << uVar10 & uVar11 | uVar5 >> param_3;
            uVar5 = puVar7[-0xd];
            puVar9[-0xd] = uVar5 << uVar10 & uVar11 | uVar3 >> param_3;
            uVar3 = puVar7[-0xc];
            puVar9[-0xc] = uVar3 << uVar10 & uVar11 | uVar5 >> param_3;
            uVar5 = puVar7[-0xb];
            puVar9[-0xb] = uVar5 << uVar10 & uVar11 | uVar3 >> param_3;
            uVar3 = puVar7[-10];
            puVar9[-10] = uVar3 << uVar10 & uVar11 | uVar5 >> param_3;
            uVar5 = puVar7[-9];
            puVar9[-9] = uVar5 << uVar10 & uVar11 | uVar3 >> param_3;
            uVar2 = puVar7[-8];
            puVar9[-8] = uVar2 << uVar10 & uVar11 | uVar5 >> param_3;
            puVar7 = puVar7 + 8;
            puVar9 = puVar9 + 8;
          } while (iVar1 != (iVar13 - 10U & 0xfffffff8) + 8);
        }
        puVar8 = puVar8 + iVar12 + iVar1;
        uVar4 = uVar2;
        puVar7 = puVar6 + iVar1;
        do {
          puVar8 = puVar8 + 1;
          uVar2 = *puVar8;
          iVar1 = iVar1 + 1;
          *puVar7 = uVar4 >> param_3 | uVar2 << uVar10 & uVar11;
          uVar4 = uVar2;
          puVar7 = puVar7 + 1;
        } while (iVar1 < iVar14);
        iVar14 = iVar14 * 4;
      }
      iVar12 = param_2->neg;
      iVar1 = 1;
      *(ulong *)((int)puVar6 + iVar14) = uVar2 >> param_3;
      param_1->neg = iVar12;
      param_1->top = iVar13;
    }
    return iVar1;
  }
  BN_set_word(param_1,0);
  return 1;
}

