
undefined4 BN_GF2m_add(BIGNUM *param_1,int *param_2,int *param_3)

{
  ulong *puVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *unaff_r8;
  int *unaff_r9;
  
  iVar4 = param_3[1];
  iVar5 = param_2[1];
  if (iVar5 < iVar4) {
    unaff_r8 = param_3;
    param_3 = unaff_r9;
  }
  if (iVar5 < iVar4) {
    param_3 = param_2;
    iVar5 = iVar4;
    param_2 = unaff_r8;
  }
  if ((param_1->dmax < iVar5) && (pBVar2 = bn_expand2(param_1,iVar5), pBVar2 == (BIGNUM *)0x0)) {
    return 0;
  }
  if (param_3[1] < 1) {
    iVar5 = 0;
  }
  else {
    puVar1 = param_1->d;
    iVar6 = 0;
    iVar4 = *param_2;
    iVar5 = 0;
    iVar3 = *param_3;
    do {
      iVar5 = iVar5 + 1;
      *(uint *)((int)puVar1 + iVar6) = *(uint *)(iVar4 + iVar6) ^ *(uint *)(iVar3 + iVar6);
      iVar6 = iVar6 + 4;
    } while (iVar5 < param_3[1]);
  }
  iVar4 = param_2[1];
  if (iVar5 < iVar4) {
    iVar3 = *param_2;
    iVar6 = iVar5 * 4;
    puVar1 = param_1->d;
    iVar7 = 0;
    do {
      iVar5 = iVar5 + 1;
      *(undefined4 *)((int)puVar1 + iVar7 + iVar6) = *(undefined4 *)(iVar3 + iVar6 + iVar7);
      iVar7 = iVar7 + 4;
      iVar4 = param_2[1];
    } while (iVar5 < iVar4);
  }
  param_1->top = iVar4;
  if (iVar4 < 1) {
    return 1;
  }
  puVar1 = param_1->d + iVar4 + -1;
  do {
    if (*puVar1 != 0) break;
    iVar4 = iVar4 + -1;
    puVar1 = puVar1 + -1;
  } while (iVar4 != 0);
  param_1->top = iVar4;
  return 1;
}

