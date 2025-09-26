
int BN_cmp(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if (a == (BIGNUM *)0x0 || b == (BIGNUM *)0x0) {
    if (a == (BIGNUM *)0x0) {
      if (b == (BIGNUM *)0x0) {
        return 0;
      }
      return 1;
    }
  }
  else {
    iVar5 = 0;
    iVar2 = a->neg;
    if (iVar2 == b->neg) {
      iVar6 = a->top;
      if (iVar2 == 0) {
        iVar2 = -1;
        iVar1 = 1;
      }
      else {
        iVar2 = 1;
        iVar1 = -1;
      }
      if (b->top < iVar6) {
        return iVar1;
      }
      if (iVar6 < b->top) {
        return iVar2;
      }
      iVar3 = iVar6 + -1;
      if (iVar3 < 0) {
        return 0;
      }
      uVar4 = a->d[iVar3];
      uVar7 = b->d[iVar3];
      if (uVar7 < uVar4) {
        return iVar1;
      }
      if (uVar4 < uVar7) {
        return iVar2;
      }
      while( true ) {
        iVar3 = iVar3 + -1;
        if (iVar3 == -1) {
          return 0;
        }
        uVar7 = *(uint *)(iVar5 + (int)(a->d + iVar6 + -2));
        uVar4 = *(uint *)(iVar5 + (int)(b->d + iVar6 + -2));
        if (uVar4 < uVar7) break;
        iVar5 = iVar5 + -4;
        if (uVar7 < uVar4) {
          return iVar2;
        }
      }
      return iVar1;
    }
    if (iVar2 == 0) {
      return 1;
    }
  }
  return -1;
}

