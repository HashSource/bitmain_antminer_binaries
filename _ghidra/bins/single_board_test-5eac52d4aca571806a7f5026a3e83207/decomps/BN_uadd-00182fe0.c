
int BN_uadd(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  int num;
  int iVar8;
  ulong *puVar9;
  ulong *puVar10;
  int iVar11;
  ulong *puVar12;
  
  iVar7 = a->top;
  iVar5 = b->top;
  num = iVar7;
  iVar8 = iVar5;
  pBVar3 = a;
  if (iVar5 <= iVar7) {
    num = iVar5;
    iVar8 = iVar7;
    pBVar3 = b;
  }
  if (iVar7 < iVar5) {
    a = b;
  }
  iVar11 = iVar8 - num;
  if (iVar7 < iVar5) {
    b = pBVar3;
  }
  iVar5 = bn_wexpand(r,iVar8 + 1);
  if (iVar5 != 0) {
    puVar9 = a->d;
    puVar12 = r->d;
    r->top = iVar8;
    uVar4 = bn_add_words(puVar12,puVar9,b->d,num);
    puVar12 = puVar12 + num;
    puVar9 = puVar9 + num;
    if (iVar11 != 0) {
      iVar8 = iVar11;
      puVar10 = puVar12;
      if (8 < iVar11) {
        puVar1 = puVar9;
        puVar2 = puVar12;
        do {
          uVar6 = *puVar1;
          iVar8 = iVar8 + -8;
          HintPreloadData(puVar1 + 0x14);
          *puVar2 = uVar6 + uVar4;
          if (uVar6 + uVar4 == 0) {
            uVar4 = uVar4 & 1;
          }
          else {
            uVar4 = 0;
          }
          uVar6 = puVar1[1];
          puVar2[1] = uVar4 + uVar6;
          if (uVar4 + uVar6 != 0) {
            uVar4 = 0;
          }
          uVar6 = puVar1[2];
          puVar2[2] = uVar4 + uVar6;
          if (uVar4 + uVar6 != 0) {
            uVar4 = 0;
          }
          uVar6 = puVar1[3];
          puVar2[3] = uVar6 + uVar4;
          if (uVar6 + uVar4 != 0) {
            uVar4 = 0;
          }
          uVar6 = puVar1[4];
          puVar2[4] = uVar6 + uVar4;
          if (uVar6 + uVar4 != 0) {
            uVar4 = 0;
          }
          uVar6 = puVar1[5];
          puVar2[5] = uVar6 + uVar4;
          if (uVar6 + uVar4 != 0) {
            uVar4 = 0;
          }
          uVar6 = puVar1[6];
          puVar2[6] = uVar6 + uVar4;
          if (uVar6 + uVar4 != 0) {
            uVar4 = 0;
          }
          uVar6 = puVar1[7];
          puVar2[7] = uVar6 + uVar4;
          if (uVar6 + uVar4 != 0) {
            uVar4 = 0;
          }
          puVar9 = puVar1 + 8;
          puVar10 = puVar2 + 8;
          puVar1 = puVar1 + 8;
          puVar2 = puVar2 + 8;
        } while (iVar8 != (iVar11 + -8) - (iVar11 - 9U & 0xfffffff8));
      }
      do {
        uVar6 = *puVar9 + uVar4;
        if (uVar6 == 0) {
          uVar4 = uVar4 & 1;
        }
        else {
          uVar4 = 0;
        }
        iVar8 = iVar8 + -1;
        *puVar10 = uVar6;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      } while (iVar8 != 0);
      puVar12 = puVar12 + iVar11;
    }
    iVar8 = r->top;
    iVar5 = 1;
    *puVar12 = uVar4;
    r->neg = 0;
    r->top = iVar8 + uVar4;
  }
  return iVar5;
}

