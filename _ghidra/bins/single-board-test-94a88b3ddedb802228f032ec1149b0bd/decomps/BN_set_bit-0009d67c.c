
int BN_set_bit(BIGNUM *a,int n)

{
  bool bVar1;
  ulong *puVar2;
  int iVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (n < 0) {
    return 0;
  }
  iVar6 = a->top;
  iVar5 = n >> 5;
  if (iVar5 < iVar6) {
    puVar2 = a->d;
    goto LAB_0009d6f4;
  }
  iVar8 = iVar5 + 1;
  if ((iVar5 < a->dmax) || (iVar8 <= a->dmax)) {
LAB_0009d69c:
    iVar3 = iVar6 + 1;
    puVar2 = a->d;
    if (iVar6 <= iVar5 && iVar3 < iVar5 + -6) {
      puVar4 = puVar2 + iVar6;
      iVar7 = iVar6;
      do {
        iVar6 = iVar7 + 8;
        HintPreloadData(puVar4 + 0x22);
        iVar3 = iVar7 + 9;
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        puVar4[6] = 0;
        puVar4[7] = 0;
        puVar4 = puVar4 + 8;
        iVar7 = iVar6;
      } while (iVar3 < iVar5 + -6);
    }
    puVar4 = puVar2 + iVar6 + -1;
    do {
      puVar4 = puVar4 + 1;
      *puVar4 = 0;
      bVar1 = iVar3 <= iVar5;
      iVar3 = iVar3 + 1;
    } while (bVar1);
  }
  else {
    puVar2 = (ulong *)bn_expand_internal(a,iVar8);
    if (puVar2 == (ulong *)0x0) {
      return 0;
    }
    if (a->d != (ulong *)0x0) {
      CRYPTO_free(a->d);
    }
    iVar6 = a->top;
    a->d = puVar2;
    a->dmax = iVar8;
    if (iVar6 <= iVar5) goto LAB_0009d69c;
  }
  a->top = iVar8;
LAB_0009d6f4:
  puVar2[iVar5] = puVar2[iVar5] | 1 << (n & 0x1fU);
  return 1;
}

