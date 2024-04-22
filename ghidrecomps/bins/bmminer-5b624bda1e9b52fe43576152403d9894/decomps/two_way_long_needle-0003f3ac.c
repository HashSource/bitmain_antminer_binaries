
/* WARNING: Unknown calling convention */

void * two_way_long_needle(uchar *haystack,size_t haystack_len,uchar *needle,size_t needle_len)

{
  byte *pbVar1;
  uint uVar2;
  size_t __n;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  uchar *puVar6;
  size_t *psVar7;
  size_t sVar8;
  size_t shift;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t shift_1;
  int iVar12;
  uint uVar13;
  size_t j;
  uint uVar14;
  size_t *period;
  size_t suffix;
  bool bVar15;
  uint local_42c;
  size_t shift_table [256];
  
  if (needle_len < 3) {
    __n = needle_len - 1;
    local_42c = 1;
  }
  else {
    __n = critical_factorization(needle,needle_len,&local_42c);
  }
  uVar10 = local_42c;
  psVar7 = &local_42c;
  uVar13 = needle_len - 1;
  do {
    psVar7 = psVar7 + 1;
    *psVar7 = needle_len;
  } while (psVar7 != shift_table + 0xff);
  sVar8 = 0;
  if (needle_len != 0) {
    do {
      pbVar1 = needle + sVar8;
      sVar4 = uVar13 - sVar8;
      sVar8 = sVar8 + 1;
      shift_table[*pbVar1] = sVar4;
    } while (sVar8 != needle_len);
  }
  iVar3 = memcmp(needle,needle + local_42c,__n);
  if (iVar3 == 0) {
    uVar5 = __n - 1;
    uVar14 = 0;
    uVar11 = 0;
    do {
      while (uVar9 = shift_table[haystack[uVar14 + uVar13]], uVar9 == 0) {
        uVar9 = __n;
        if (__n <= uVar11) {
          uVar9 = uVar11;
        }
        if (uVar9 < uVar13) {
          puVar6 = needle + uVar9;
          if (needle[uVar9] == haystack[uVar14 + uVar9]) {
            do {
              uVar9 = uVar9 + 1;
              if (uVar13 <= uVar9) goto LAB_0003f496;
              puVar6 = puVar6 + 1;
            } while (haystack[uVar9 + uVar14] == *puVar6);
          }
          uVar14 = (1 - __n) + uVar14 + uVar9;
          goto LAB_0003f450;
        }
LAB_0003f496:
        uVar9 = __n;
        if ((uVar11 < __n) && (needle[uVar5] == haystack[uVar5 + uVar14])) {
          uVar2 = uVar5;
          puVar6 = needle + uVar5;
          do {
            uVar9 = uVar2;
            if (puVar6 == needle + uVar11) break;
            puVar6 = puVar6 + -1;
            uVar2 = uVar9 - 1;
          } while (*puVar6 == haystack[(uVar9 - 1) + uVar14]);
        }
        if (uVar9 < uVar11 + 1) {
          return haystack + uVar14;
        }
        uVar14 = uVar14 + uVar10;
        uVar11 = needle_len - uVar10;
        if (haystack_len - needle_len < uVar14) {
          return (void *)0x0;
        }
      }
      if ((uVar11 != 0) && (uVar9 < uVar10)) {
        uVar9 = needle_len - uVar10;
      }
      uVar14 = uVar14 + uVar9;
LAB_0003f450:
      uVar11 = 0;
    } while (uVar14 <= haystack_len - needle_len);
  }
  else {
    uVar10 = needle_len - __n;
    if (needle_len - __n < __n) {
      uVar10 = __n;
    }
    iVar3 = __n - 1;
    uVar14 = 0;
    do {
      uVar11 = shift_table[haystack[uVar14 + uVar13]];
      if (uVar11 == 0) {
        if (__n < uVar13) {
          puVar6 = needle + __n;
          uVar11 = __n;
          if (needle[__n] == haystack[__n + uVar14]) {
            do {
              uVar11 = uVar11 + 1;
              if (uVar13 <= uVar11) goto LAB_0003f560;
              puVar6 = puVar6 + 1;
            } while (haystack[uVar11 + uVar14] == *puVar6);
          }
          uVar14 = (1 - __n) + uVar14;
          goto LAB_0003f592;
        }
LAB_0003f560:
        if (iVar3 == -1) {
          return haystack + uVar14;
        }
        if (needle[iVar3] == haystack[uVar14 + iVar3]) {
          iVar12 = iVar3;
          do {
            bVar15 = iVar12 == 0;
            iVar12 = iVar12 + -1;
            if (bVar15) {
              return haystack + uVar14;
            }
          } while (needle[iVar12] == (haystack + uVar14)[iVar12]);
        }
        uVar14 = uVar14 + uVar10 + 1;
      }
      else {
LAB_0003f592:
        uVar14 = uVar14 + uVar11;
      }
    } while (uVar14 <= haystack_len - needle_len);
  }
  return (void *)0x0;
}

