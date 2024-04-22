
int BN_dec2bn(BIGNUM **a,char *str)

{
  char cVar1;
  byte bVar2;
  ushort **ppuVar3;
  BIGNUM *pBVar4;
  int iVar5;
  ulong *puVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  ulong w;
  BIGNUM *a_00;
  int iVar10;
  
  if (str == (char *)0x0) {
    return 0;
  }
  cVar1 = *str;
  if (cVar1 == '\0') {
    return 0;
  }
  iVar7 = 0;
  if (cVar1 == '-') {
    str = str + 1;
  }
  uVar9 = (uint)(cVar1 == '-');
  ppuVar3 = __ctype_b_loc();
  while (((*ppuVar3)[(byte)str[iVar7]] & 0x800) != 0) {
    iVar7 = iVar7 + 1;
  }
  iVar10 = uVar9 + iVar7;
  if (a == (BIGNUM **)0x0) {
    return iVar10;
  }
  a_00 = *a;
  if (a_00 == (BIGNUM *)0x0) {
    a_00 = BN_new();
    if (a_00 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  else {
    BN_set_word(a_00,0);
  }
  iVar5 = iVar7 * 4 + 0x1f >> 5;
  if ((a_00->dmax < iVar5) && (pBVar4 = bn_expand2(a_00,iVar5), pBVar4 == (BIGNUM *)0x0)) {
    if (*a != (BIGNUM *)0x0) {
      return 0;
    }
    BN_free(a_00);
    return 0;
  }
  w = 0;
  pbVar8 = (byte *)(str + -1);
  iVar7 = ((iVar7 / 9) * 9 - iVar7) + 9;
  if (iVar7 == 9) {
    iVar7 = 0;
  }
  do {
    pbVar8 = pbVar8 + 1;
    bVar2 = *pbVar8;
    iVar5 = w * 5;
    while( true ) {
      if (bVar2 == 0) {
        iVar7 = a_00->top;
        a_00->neg = uVar9;
        if (iVar7 < 1) goto LAB_0009e51a;
        puVar6 = a_00->d + iVar7 + -1;
        goto LAB_0009e50c;
      }
      iVar7 = iVar7 + 1;
      w = ((uint)bVar2 + iVar5 * 2) - 0x30;
      if (iVar7 != 9) break;
      BN_mul_word(a_00,1000000000);
      BN_add_word(a_00,w);
      pbVar8 = pbVar8 + 1;
      bVar2 = *pbVar8;
      iVar7 = 0;
      iVar5 = 0;
    }
  } while( true );
  while (iVar7 = iVar7 + -1, puVar6 = puVar6 + -1, iVar7 != 0) {
LAB_0009e50c:
    if (*puVar6 != 0) break;
  }
  a_00->top = iVar7;
LAB_0009e51a:
  *a = a_00;
  return iVar10;
}

