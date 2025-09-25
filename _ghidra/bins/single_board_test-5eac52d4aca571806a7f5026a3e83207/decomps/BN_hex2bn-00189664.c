
int BN_hex2bn(BIGNUM **a,char *str)

{
  int iVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  BIGNUM *a_00;
  char *pcVar9;
  uint uVar10;
  bool bVar11;
  
  if ((str != (char *)0x0) && (uVar5 = (uint)(byte)*str, uVar5 != 0)) {
    bVar11 = uVar5 == 0x2d;
    iVar7 = 0;
    if (bVar11) {
      str = str + 1;
      uVar5 = 1;
    }
    pcVar8 = str + -1;
    if (!bVar11) {
      uVar5 = 0;
    }
    do {
      pcVar8 = pcVar8 + 1;
      iVar1 = ossl_ctype_check(*pcVar8,0x10);
      if (iVar1 == 0) {
        if (iVar7 == 0) {
          return 0;
        }
        iVar1 = uVar5 + iVar7;
        if (a == (BIGNUM **)0x0) {
          return iVar1;
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
        if ((iVar7 * 4 < 0x7fffffc1) &&
           ((iVar4 = iVar7 * 4 + 0x3f >> 6, iVar4 <= a_00->dmax ||
            (pBVar3 = bn_expand2(a_00,iVar4), pBVar3 != (BIGNUM *)0x0)))) {
          iVar4 = 0;
          do {
            if (iVar7 < 0x11) {
              iVar6 = 0;
            }
            else {
              iVar6 = iVar7 + -0x10;
            }
            uVar10 = 0;
            pcVar8 = str + iVar6;
            do {
              pcVar9 = pcVar8 + 1;
              uVar2 = OPENSSL_hexchar2int(*pcVar8);
              uVar10 = uVar2 & ~((int)uVar2 >> 0x1f) | uVar10 << 4;
              pcVar8 = pcVar9;
            } while (str + iVar7 != pcVar9);
            iVar7 = iVar7 + -0x10;
            iVar6 = iVar4 + 1;
            a_00->d[iVar4] = uVar10;
            iVar4 = iVar6;
          } while (0 < iVar7);
          a_00->top = iVar6;
          bn_correct_top(a_00);
          iVar7 = a_00->top;
          *a = a_00;
          if (iVar7 == 0) {
            return iVar1;
          }
          a_00->neg = uVar5;
          return iVar1;
        }
        if (*a != (BIGNUM *)0x0) {
          return 0;
        }
        BN_free(a_00);
        return 0;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0x20000000);
  }
  return 0;
}

