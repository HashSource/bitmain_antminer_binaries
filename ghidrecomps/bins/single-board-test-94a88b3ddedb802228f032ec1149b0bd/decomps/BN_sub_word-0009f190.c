
int BN_sub_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  int iVar4;
  
  if (w != 0) {
    if (a->top == 0) {
      iVar4 = BN_set_word(a,w);
      if (iVar4 == 0) {
        return 0;
      }
      BN_set_negative(a,1);
      return iVar4;
    }
    if (a->neg != 0) {
      a->neg = 0;
      iVar4 = BN_add_word(a,w);
      a->neg = 1;
      return iVar4;
    }
    puVar1 = a->d;
    uVar3 = *puVar1;
    iVar4 = 0;
    if (a->top == 1) {
      if (uVar3 < w) {
        *puVar1 = w - uVar3;
        a->neg = 1;
        return 1;
      }
    }
    else if (uVar3 < w) {
      iVar4 = 0;
      puVar2 = puVar1;
      do {
        puVar1 = puVar2 + 1;
        iVar4 = iVar4 + 1;
        *puVar2 = uVar3 - w;
        uVar3 = *puVar1;
        w = 1;
        puVar2 = puVar1;
      } while (uVar3 == 0);
    }
    *puVar1 = uVar3 - w;
    if ((uVar3 - w == 0) && (a->top + -1 == iVar4)) {
      a->top = iVar4;
      return 1;
    }
  }
  return 1;
}

