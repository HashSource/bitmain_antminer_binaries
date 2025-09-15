
int BN_hex2bn(BIGNUM **a,char *str)

{
  char cVar1;
  ushort **ppuVar2;
  uint *puVar3;
  BIGNUM *pBVar4;
  int iVar5;
  ulong *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  BIGNUM *a_00;
  int local_38;
  uint local_30;
  
  if (str == (char *)0x0) {
    local_38 = 0;
  }
  else {
    cVar1 = *str;
    if (cVar1 == '\0') {
      local_38 = 0;
    }
    else {
      iVar12 = 0;
      if (cVar1 == '-') {
        str = str + 1;
      }
      local_30 = (uint)(cVar1 == '-');
      ppuVar2 = __ctype_b_loc();
      while (((*ppuVar2)[(byte)str[iVar12]] & 0x1000) != 0) {
        iVar12 = iVar12 + 1;
      }
      local_38 = local_30 + iVar12;
      if (a != (BIGNUM **)0x0) {
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
        iVar5 = iVar12 * 4 + 0x1f >> 5;
        if ((a_00->dmax < iVar5) && (pBVar4 = bn_expand2(a_00,iVar5), pBVar4 == (BIGNUM *)0x0)) {
          if (*a == (BIGNUM *)0x0) {
            BN_free(a_00);
            local_38 = 0;
          }
          else {
            local_38 = 0;
          }
        }
        else {
          if (iVar12 == 0) {
            a_00->top = 0;
          }
          else {
            puVar6 = a_00->d;
            puVar3 = puVar6 + -1;
            iVar5 = iVar12;
            do {
              iVar11 = iVar5;
              if (7 < iVar5) {
                iVar11 = 8;
              }
              iVar8 = 0;
              uVar10 = 0;
              do {
                uVar7 = (uint)(byte)str[iVar8 + (iVar5 - iVar11)];
                uVar9 = uVar7 - 0x30;
                if (9 < uVar9) {
                  uVar9 = uVar7 - 0x57;
                  if ((5 < uVar7 - 0x61) && (uVar9 = uVar7 - 0x37, 5 < uVar7 - 0x41)) {
                    uVar9 = 0;
                  }
                }
                iVar8 = iVar8 + 1;
                uVar10 = uVar9 | uVar10 << 4;
              } while (0 < iVar11 - iVar8);
              iVar5 = iVar5 + -8;
              puVar3 = puVar3 + 1;
              *puVar3 = uVar10;
            } while (0 < iVar5);
            uVar10 = iVar12 - 1U >> 3;
            iVar12 = uVar10 + 1;
            a_00->top = iVar12;
            puVar6 = puVar6 + uVar10;
            do {
              if (*puVar6 != 0) break;
              iVar12 = iVar12 + -1;
              puVar6 = puVar6 + -1;
            } while (iVar12 != 0);
            a_00->top = iVar12;
          }
          a_00->neg = local_30;
          *a = a_00;
        }
      }
    }
  }
  return local_38;
}

