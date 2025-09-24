
int BN_mask_bits(BIGNUM *a,int n)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong *unaff_r4;
  bool bVar4;
  
  if (-1 < n) {
    uVar2 = a->top;
    iVar3 = n >> 6;
    if (iVar3 < (int)uVar2) {
      uVar1 = n & 0x3f;
      bVar4 = uVar1 != 0;
      if (bVar4) {
        unaff_r4 = a->d;
        uVar1 = -1 << uVar1;
        uVar2 = iVar3 + 1;
      }
      if (bVar4) {
        a->top = uVar2;
        uVar2 = unaff_r4[iVar3];
      }
      if (bVar4) {
        unaff_r4[iVar3] = uVar2 & ~uVar1;
      }
      else {
        a->top = iVar3;
      }
      bn_correct_top();
      return 1;
    }
  }
  return 0;
}

