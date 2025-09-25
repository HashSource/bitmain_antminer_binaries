
int BN_usub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong uVar10;
  ulong *puVar11;
  
  iVar5 = a->top;
  iVar7 = b->top;
  iVar6 = iVar5 - iVar7;
  if (-1 < iVar6) {
    iVar3 = bn_wexpand(r,iVar5);
    if (iVar3 != 0) {
      puVar9 = a->d;
      puVar8 = r->d;
      uVar4 = bn_sub_words(puVar8,puVar9,b->d,iVar7);
      puVar9 = puVar9 + iVar7;
      puVar8 = puVar8 + iVar7;
      if (iVar6 != 0) {
        iVar7 = iVar6;
        puVar11 = puVar8;
        if (8 < iVar6) {
          puVar1 = puVar8;
          puVar2 = puVar9;
          do {
            iVar7 = iVar7 + -8;
            HintPreloadData(puVar2 + 0x14);
            uVar10 = *puVar2 - uVar4;
            if (*puVar2 == 0) {
              uVar4 = uVar4 & 1;
            }
            else {
              uVar4 = 0;
            }
            *puVar1 = uVar10;
            uVar10 = puVar2[1] - uVar4;
            if (puVar2[1] != 0) {
              uVar4 = 0;
            }
            puVar1[1] = uVar10;
            uVar10 = puVar2[2] - uVar4;
            if (puVar2[2] != 0) {
              uVar4 = 0;
            }
            puVar1[2] = uVar10;
            uVar10 = puVar2[3] - uVar4;
            if (puVar2[3] != 0) {
              uVar4 = 0;
            }
            puVar1[3] = uVar10;
            uVar10 = puVar2[4] - uVar4;
            if (puVar2[4] != 0) {
              uVar4 = 0;
            }
            puVar1[4] = uVar10;
            uVar10 = puVar2[5] - uVar4;
            if (puVar2[5] != 0) {
              uVar4 = 0;
            }
            puVar1[5] = uVar10;
            uVar10 = puVar2[6] - uVar4;
            if (puVar2[6] != 0) {
              uVar4 = 0;
            }
            puVar1[6] = uVar10;
            uVar10 = puVar2[7] - uVar4;
            if (puVar2[7] != 0) {
              uVar4 = 0;
            }
            puVar1[7] = uVar10;
            puVar9 = puVar2 + 8;
            puVar11 = puVar1 + 8;
            puVar1 = puVar1 + 8;
            puVar2 = puVar2 + 8;
          } while (iVar7 != (iVar6 + -8) - (iVar6 - 9U & 0xfffffff8));
        }
        do {
          uVar10 = *puVar9 - uVar4;
          if (*puVar9 == 0) {
            uVar4 = uVar4 & 1;
          }
          else {
            uVar4 = 0;
          }
          iVar7 = iVar7 + -1;
          *puVar11 = uVar10;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        } while (iVar7 != 0);
        puVar8 = puVar8 + iVar6;
      }
      if (iVar5 != 0) {
        uVar10 = puVar8[-1];
        puVar8 = puVar8 + -1;
        while ((uVar10 == 0 && (iVar5 = iVar5 + -1, iVar5 != 0))) {
          puVar8 = puVar8 + -1;
          uVar10 = *puVar8;
        }
      }
      iVar3 = 1;
      r->top = iVar5;
      r->neg = 0;
    }
    return iVar3;
  }
  ERR_put_error(3,0x73,100,"crypto/bn/bn_add.c",0x8b);
  return 0;
}

