
int BN_sub_word(BIGNUM *a,ulong w)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  
  if (w == 0) {
    return 1;
  }
  iVar1 = BN_is_zero();
  if (iVar1 != 0) {
    iVar1 = BN_set_word(a,w);
    if (iVar1 != 0) {
      BN_set_negative(a,1);
      return iVar1;
    }
    return 0;
  }
  if (a->neg != 0) {
    a->neg = 0;
    iVar1 = BN_add_word(a,w);
    a->neg = 1;
    return iVar1;
  }
  iVar1 = a->top;
  puVar4 = a->d;
  uVar5 = *puVar4;
  if (iVar1 == 1) {
    if (uVar5 < w) {
      *puVar4 = w - uVar5;
      a->neg = 1;
      return 1;
    }
    *puVar4 = uVar5 - w;
    iVar1 = 0;
    if (uVar5 - w != 0) {
      return 1;
    }
  }
  else {
    iVar2 = 0;
    iVar3 = 0;
    if (uVar5 < w) {
      do {
        iVar2 = iVar2 + 1;
        *puVar4 = uVar5 - w;
        w = 1;
        puVar4 = puVar4 + 1;
        uVar5 = *puVar4;
        iVar3 = iVar2;
      } while (uVar5 == 0);
    }
    *puVar4 = uVar5 - w;
    if (uVar5 - w != 0) {
      return 1;
    }
    iVar1 = iVar1 + -1;
    if (iVar1 != iVar3) {
      return 1;
    }
  }
  a->top = iVar1;
  return 1;
}

