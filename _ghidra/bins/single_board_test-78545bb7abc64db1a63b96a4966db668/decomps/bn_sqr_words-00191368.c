
void bn_sqr_words(ulong *rp,ulong *ap,int num)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  bool bVar4;
  
  if (0 < num) {
    if ((num & 0xfffffffcU) != 0) {
      puVar1 = rp + 8;
      puVar2 = ap + 4;
      do {
        ap = puVar2;
        rp = puVar1;
        uVar3 = ap[-4];
        num = num - 4;
        rp[-7] = 0;
        rp[-8] = uVar3 * uVar3;
        uVar3 = ap[-3];
        rp[-5] = 0;
        rp[-6] = uVar3 * uVar3;
        uVar3 = ap[-2];
        rp[-3] = 0;
        rp[-4] = uVar3 * uVar3;
        uVar3 = ap[-1];
        rp[-1] = 0;
        rp[-2] = uVar3 * uVar3;
        puVar1 = rp + 8;
        puVar2 = ap + 4;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return;
      }
    }
    uVar3 = *ap;
    rp[1] = 0;
    *rp = uVar3 * uVar3;
    if (num != 1) {
      uVar3 = ap[1];
      bVar4 = num != 2;
      rp[3] = 0;
      uVar3 = uVar3 * uVar3;
      rp[2] = uVar3;
      if (bVar4) {
        uVar3 = ap[2];
      }
      if (bVar4) {
        rp[5] = 0;
        uVar3 = uVar3 * uVar3;
      }
      if (bVar4) {
        rp[4] = uVar3;
      }
    }
  }
  return;
}

