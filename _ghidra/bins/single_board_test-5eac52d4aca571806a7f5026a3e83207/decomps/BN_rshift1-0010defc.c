
int BN_rshift1(BIGNUM *r,BIGNUM *a)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  ulong *puVar7;
  
  iVar1 = BN_is_zero(a);
  if (iVar1 != 0) {
    BN_set_word(r,0);
    return 1;
  }
  puVar6 = a->d;
  iVar1 = a->top;
  if (a != r) {
    iVar2 = bn_wexpand(r,iVar1);
    if (iVar2 == 0) {
      return 0;
    }
    r->neg = a->neg;
  }
  iVar3 = iVar1 + -1;
  puVar7 = r->d;
  iVar2 = iVar1;
  if (puVar6[iVar3] == 1) {
    iVar2 = iVar1 + -1;
  }
  puVar7[iVar3] = puVar6[iVar3] >> 1;
  r->top = iVar2;
  if (0 < iVar3) {
    if (9 < iVar1) {
      puVar4 = puVar6 + iVar1 + -0x19;
      puVar5 = puVar7 + iVar1;
      do {
        iVar3 = iVar3 + -8;
        HintPreloadData(puVar4);
        puVar5[-2] = puVar4[0x17] >> 1;
        puVar5[-3] = puVar4[0x16] >> 1;
        puVar5[-4] = puVar4[0x15] >> 1;
        puVar5[-5] = puVar4[0x14] >> 1;
        puVar5[-6] = puVar4[0x13] >> 1;
        puVar5[-7] = puVar4[0x12] >> 1;
        puVar5[-8] = puVar4[0x11] >> 1;
        puVar5[-9] = puVar4[0x10] >> 1;
        puVar4 = puVar4 + -8;
        puVar5 = puVar5 + -8;
      } while (iVar3 != (iVar1 + -9) - (iVar1 - 10U & 0xfffffff8));
    }
    puVar6 = puVar6 + iVar3;
    puVar7 = puVar7 + iVar3;
    do {
      puVar6 = puVar6 + -1;
      iVar3 = iVar3 + -1;
      puVar7 = puVar7 + -1;
      *puVar7 = *puVar6 >> 1;
    } while (iVar3 != 0);
  }
  if (iVar2 == 0) {
    r->neg = 0;
  }
  return 1;
}

