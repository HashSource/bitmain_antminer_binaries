
ulong BN_div_word(BIGNUM *a,ulong w)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong l;
  int iVar5;
  uint n;
  ulong d;
  
  if (w == 0) {
    return 0xffffffff;
  }
  uVar1 = a->top;
  if (uVar1 != 0) {
    iVar2 = BN_num_bits_word(w);
    n = 0x20 - iVar2;
    iVar2 = BN_lshift(a,a,n);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = a->top;
    iVar5 = iVar2 + -1;
    if (iVar5 < 0) {
      uVar1 = 0;
    }
    else {
      puVar4 = a->d;
      d = w << (n & 0xff);
      iVar2 = iVar5 * 4;
      uVar1 = 0;
      do {
        l = *(ulong *)((int)puVar4 + iVar2);
        iVar5 = iVar5 + -1;
        uVar3 = bn_div_words(uVar1,l,d);
        puVar4 = a->d;
        uVar1 = l - d * uVar3;
        *(ulong *)((int)puVar4 + iVar2) = uVar3;
        iVar2 = iVar2 + -4;
      } while (iVar5 != -1);
      iVar2 = a->top;
      uVar1 = uVar1 >> (n & 0xff);
    }
    if ((0 < iVar2) && (a->d[iVar2 + -1] == 0)) {
      a->top = iVar2 + -1;
    }
  }
  return uVar1;
}

