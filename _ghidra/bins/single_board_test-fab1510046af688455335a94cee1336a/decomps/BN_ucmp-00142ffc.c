
int BN_ucmp(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar5 = a->top;
  iVar2 = iVar5 - b->top;
  if (iVar2 == 0) {
    iVar4 = iVar5 + -1;
    if (-1 < iVar4) {
      uVar6 = a->d[iVar4];
      uVar3 = b->d[iVar4];
      if (uVar6 == uVar3) {
        iVar2 = 0;
        do {
          bVar7 = iVar4 == 0;
          iVar4 = iVar4 + -1;
          iVar1 = iVar2 + iVar5 * 4;
          iVar2 = iVar2 + -4;
          if (bVar7) {
            return 0;
          }
          uVar6 = *(uint *)((int)a->d + iVar1 + -8);
          uVar3 = *(uint *)((int)b->d + iVar2 + iVar5 * 4 + -4);
        } while (uVar6 == uVar3);
      }
      if (uVar3 < uVar6) {
        iVar2 = 1;
      }
      else {
        iVar2 = -1;
      }
    }
  }
  return iVar2;
}

