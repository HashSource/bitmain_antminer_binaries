
int BN_mask_bits(BIGNUM *a,int n)

{
  uint uVar1;
  ulong *puVar2;
  int iVar3;
  int unaff_r4;
  bool bVar4;
  
  if (-1 < n) {
    puVar2 = (ulong *)a->top;
    iVar3 = n >> 5;
    if (iVar3 < (int)puVar2) {
      uVar1 = n & 0x1f;
      bVar4 = uVar1 != 0;
      if (bVar4) {
        puVar2 = a->d;
        unaff_r4 = iVar3 + 1;
      }
      if (bVar4) {
        a->top = unaff_r4;
        uVar1 = -1 << uVar1;
      }
      if (bVar4) {
        puVar2[iVar3] = puVar2[iVar3] & ~uVar1;
        iVar3 = a->top;
      }
      else {
        a->top = iVar3;
      }
      if (iVar3 < 1) {
        return 1;
      }
      puVar2 = a->d + iVar3 + -1;
      do {
        if (*puVar2 != 0) break;
        iVar3 = iVar3 + -1;
        puVar2 = puVar2 + -1;
      } while (iVar3 != 0);
      a->top = iVar3;
      return 1;
    }
  }
  return 0;
}

