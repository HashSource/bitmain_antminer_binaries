
ulong bn_mul_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulong *puVar1;
  ulong *puVar2;
  
  if (num < 1) {
    return 0;
  }
  if ((num & 0xfffffffcU) != 0) {
    puVar1 = ap + 4;
    puVar2 = rp + 4;
    do {
      rp = puVar2;
      ap = puVar1;
      num = num - 4;
      rp[-4] = ap[-4] * w;
      rp[-3] = ap[-3] * w;
      rp[-2] = ap[-2] * w;
      rp[-1] = ap[-1] * w;
      puVar1 = ap + 4;
      puVar2 = rp + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return 0;
    }
  }
  *rp = *ap * w;
  if (num != 1) {
    rp[1] = ap[1] * w;
    if (num != 2U) {
      w = ap[2] * w;
    }
    if (num != 2U) {
      rp[2] = w;
    }
  }
  return 0;
}

