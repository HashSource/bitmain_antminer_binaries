
int BN_lshift1(BIGNUM *r,BIGNUM *a)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  ulong *puVar7;
  
  if (r == a) {
    iVar4 = bn_wexpand(r,r->top + 1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  else {
    iVar4 = a->top;
    r->neg = a->neg;
    iVar4 = bn_wexpand(r,iVar4 + 1);
    if (iVar4 == 0) {
      return 0;
    }
    r->top = a->top;
  }
  iVar4 = a->top;
  puVar7 = r->d;
  puVar3 = a->d;
  if (0 < iVar4) {
    if (iVar4 < 9) {
      iVar5 = 0;
      puVar6 = puVar7;
    }
    else {
      iVar5 = 0;
      puVar1 = puVar7;
      puVar2 = puVar3;
      do {
        iVar5 = iVar5 + 8;
        HintPreloadData(puVar2 + 0x19);
        *puVar1 = *puVar2 << 1;
        puVar1[1] = puVar2[1] << 1;
        puVar1[2] = puVar2[2] << 1;
        puVar1[3] = puVar2[3] << 1;
        puVar1[4] = puVar2[4] << 1;
        puVar1[5] = puVar2[5] << 1;
        puVar1[6] = puVar2[6] << 1;
        puVar1[7] = puVar2[7] << 1;
        puVar3 = puVar2 + 8;
        puVar6 = puVar1 + 8;
        puVar1 = puVar1 + 8;
        puVar2 = puVar2 + 8;
      } while (iVar5 != (iVar4 - 9U & 0xfffffff8) + 8);
    }
    do {
      iVar5 = iVar5 + 1;
      *puVar6 = *puVar3 << 1;
      puVar3 = puVar3 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar5 < iVar4);
    puVar7 = puVar7 + iVar4;
  }
  *puVar7 = 0;
  return 1;
}

