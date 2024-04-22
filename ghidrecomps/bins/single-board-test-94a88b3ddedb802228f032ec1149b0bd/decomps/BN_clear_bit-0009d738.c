
int BN_clear_bit(BIGNUM *a,int n)

{
  ulong *puVar1;
  int iVar2;
  
  if ((n < 0) || (iVar2 = n >> 5, a->top <= iVar2)) {
    iVar2 = 0;
  }
  else {
    puVar1 = a->d;
    puVar1[iVar2] = puVar1[iVar2] & ~(1 << (n & 0x1fU));
    iVar2 = a->top;
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    else {
      puVar1 = puVar1 + iVar2 + -1;
      do {
        if (*puVar1 != 0) break;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
      } while (iVar2 != 0);
      a->top = iVar2;
      iVar2 = 1;
    }
  }
  return iVar2;
}

