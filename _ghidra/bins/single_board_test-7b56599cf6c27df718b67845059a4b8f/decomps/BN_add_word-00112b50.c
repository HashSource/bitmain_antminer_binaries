
int BN_add_word(BIGNUM *a,ulong w)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  if (w != 0) {
    iVar1 = BN_is_zero();
    if (iVar1 != 0) {
      iVar1 = BN_set_word(a,w);
      return iVar1;
    }
    if (a->neg != 0) {
      a->neg = 0;
      iVar1 = BN_sub_word(a,w);
      iVar3 = BN_is_zero(a);
      if (iVar3 == 0) {
        a->neg = (uint)(a->neg == 0);
        return iVar1;
      }
      return iVar1;
    }
    iVar3 = a->top;
    iVar1 = 0;
    do {
      if (iVar3 <= iVar1) {
        if (iVar3 != iVar1) {
          return 1;
        }
        iVar1 = bn_wexpand(a,iVar3 + 1);
        if (iVar1 != 0) {
          a->top = a->top + 1;
          a->d[iVar3] = w;
          return 1;
        }
        return 0;
      }
      uVar2 = a->d[iVar1] + w;
      bVar4 = uVar2 < w;
      a->d[iVar1] = uVar2;
      w = (ulong)bVar4;
      iVar1 = iVar1 + 1;
    } while (bVar4);
  }
  return 1;
}

