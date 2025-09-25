
int BN_ucmp(BIGNUM *a,BIGNUM *b)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  ulong *puVar5;
  uint uVar6;
  bool bVar7;
  
  iVar2 = a->top;
  iVar3 = iVar2 - b->top;
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = iVar2 + -1;
  if (iVar3 < 0) {
    return 0;
  }
  uVar1 = a->d[iVar3];
  uVar6 = b->d[iVar3];
  if (uVar1 == uVar6) {
    puVar5 = a->d + iVar2 + 0x3fffffff;
    puVar4 = b->d + iVar2 + 0x3fffffff;
    do {
      bVar7 = iVar3 == 0;
      iVar3 = iVar3 + -1;
      if (bVar7) {
        return 0;
      }
      puVar5 = puVar5 + -1;
      uVar1 = *puVar5;
      puVar4 = puVar4 + -1;
      uVar6 = *puVar4;
    } while (uVar1 == uVar6);
  }
  if (uVar6 < uVar1) {
    iVar2 = 1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

