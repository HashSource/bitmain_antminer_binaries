
int BN_set_bit(BIGNUM *a,int n)

{
  int iVar1;
  int iVar2;
  ulong *puVar3;
  
  if (n < 0) {
    return 0;
  }
  iVar2 = n >> 6;
  if (iVar2 < a->top) {
    puVar3 = a->d;
  }
  else {
    iVar1 = bn_wexpand(a,iVar2 + 1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = a->top;
    puVar3 = a->d;
    if (iVar1 <= iVar2) {
      memset(puVar3 + iVar1,0,((1 - iVar1) + iVar2) * 4);
    }
    a->top = iVar2 + 1;
  }
  puVar3[iVar2] = 1 << (n & 0x3fU) | puVar3[iVar2];
  return 1;
}

