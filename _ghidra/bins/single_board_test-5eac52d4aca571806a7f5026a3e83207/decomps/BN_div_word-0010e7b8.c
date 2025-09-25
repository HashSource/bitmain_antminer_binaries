
ulong BN_div_word(BIGNUM *a,ulong w)

{
  int iVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong d;
  int iVar5;
  uint n;
  ulong l;
  
  if (w == 0) {
    return 0xffffffff;
  }
  if (a->top == 0) {
    uVar4 = 0;
  }
  else {
    iVar1 = BN_num_bits_word(w);
    n = 0x40 - iVar1;
    iVar1 = BN_lshift(a,a,n);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    iVar1 = a->top;
    iVar5 = iVar1 + -1;
    if (iVar5 < 0) {
      uVar4 = 0;
    }
    else {
      puVar3 = a->d;
      d = w << (n & 0xff);
      iVar1 = iVar5 * 4;
      uVar4 = 0;
      do {
        l = *(ulong *)((int)puVar3 + iVar1);
        iVar5 = iVar5 + -1;
        uVar2 = bn_div_words(uVar4,l,d);
        puVar3 = a->d;
        uVar4 = l - uVar2 * d;
        *(ulong *)((int)puVar3 + iVar1) = uVar2;
        iVar1 = iVar1 + -4;
      } while (iVar5 != -1);
      uVar4 = uVar4 >> (n & 0xff);
      iVar1 = a->top;
    }
    if (0 < iVar1) {
      if (a->d[iVar1 + 0x3fffffff] != 0) {
        return uVar4;
      }
      iVar1 = iVar1 + -1;
      a->top = iVar1;
    }
    if (iVar1 == 0) {
      a->neg = 0;
      return uVar4;
    }
  }
  return uVar4;
}

