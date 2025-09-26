
int BN_dec2bn(BIGNUM **a,char *str)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  byte *pbVar6;
  ulong w;
  BIGNUM *a_00;
  int iVar7;
  uint uVar8;
  
  if (str == (char *)0x0) {
    return 0;
  }
  cVar1 = *str;
  if (cVar1 != '\0') {
    if (cVar1 == '-') {
      str = str + 1;
    }
    uVar8 = (uint)(cVar1 == '-');
    pbVar6 = (byte *)str + -1;
    iVar7 = 0;
    do {
      pbVar6 = pbVar6 + 1;
      iVar3 = ossl_ctype_check(*pbVar6,4);
      if (iVar3 == 0) {
        if (iVar7 == 0) {
          a_00 = (BIGNUM *)0x0;
        }
        else {
          iVar3 = uVar8 + iVar7;
          if (a == (BIGNUM **)0x0) {
            return iVar3;
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
             ((iVar5 = iVar7 * 4 + 0x3f >> 6, iVar5 <= a_00->dmax ||
              (pBVar4 = bn_expand2(a_00,iVar5), pBVar4 != (BIGNUM *)0x0)))) {
            w = 0;
            pbVar6 = (byte *)str + iVar7;
            iVar7 = ((iVar7 / 0x13) * 0x13 - iVar7) + 0x13;
            if (iVar7 == 0x13) {
              iVar7 = 0;
            }
            do {
              iVar7 = iVar7 + 1;
              iVar5 = w * 10;
              pbVar2 = (byte *)str;
              while( true ) {
                if (pbVar2 == pbVar6) {
                  bn_correct_top(a_00);
                  iVar7 = a_00->top;
                  *a = a_00;
                  if (iVar7 != 0) {
                    a_00->neg = uVar8;
                    return iVar3;
                  }
                  return iVar3;
                }
                str = (char *)(pbVar2 + 1);
                w = iVar5 + -0x30 + (uint)*pbVar2;
                if (iVar7 != 0x13) break;
                iVar7 = BN_mul_word(a_00,0x89e80000);
                if ((iVar7 == 0) || (iVar7 = BN_add_word(a_00,w), iVar7 == 0)) goto LAB_001976ae;
                iVar7 = 1;
                iVar5 = 0;
                pbVar2 = (byte *)str;
              }
            } while( true );
          }
        }
        goto LAB_001976ae;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0x20000000);
    a_00 = (BIGNUM *)0x0;
LAB_001976ae:
    if (*a == (BIGNUM *)0x0) {
      BN_free(a_00);
      return 0;
    }
  }
  return 0;
}

