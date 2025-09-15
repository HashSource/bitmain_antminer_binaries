
/* WARNING: Unknown calling convention */

void * two_way_long_needle(uchar *haystack,size_t haystack_len,uchar *needle,size_t needle_len)

{
  byte *pbVar1;
  size_t sVar2;
  uint uVar3;
  size_t __n;
  int iVar4;
  size_t sVar5;
  uint uVar6;
  uchar *puVar7;
  uint uVar8;
  size_t *psVar9;
  size_t sVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  size_t suffix;
  bool bVar15;
  size_t local_42c;
  size_t shift_table [256];
  
  if (needle_len < 3) {
    __n = needle_len - 1;
    local_42c = 1;
  }
  else {
    __n = critical_factorization(needle,needle_len,&local_42c);
  }
  sVar2 = local_42c;
  psVar9 = &local_42c;
  uVar13 = needle_len - 1;
  do {
    psVar9 = psVar9 + 1;
    *psVar9 = needle_len;
  } while (psVar9 != shift_table + 0xff);
  sVar10 = 0;
  if (needle_len != 0) {
    do {
      pbVar1 = needle + sVar10;
      sVar5 = uVar13 - sVar10;
      sVar10 = sVar10 + 1;
      shift_table[*pbVar1] = sVar5;
    } while (sVar10 != needle_len);
  }
  iVar4 = memcmp(needle,needle + local_42c,__n);
  if (iVar4 == 0) {
    uVar6 = __n - 1;
    uVar14 = 0;
    uVar8 = 0;
    do {
      while (uVar11 = shift_table[haystack[uVar14 + uVar13]], uVar11 == 0) {
        uVar11 = __n;
        if (__n <= uVar8) {
          uVar11 = uVar8;
        }
        if (uVar11 < uVar13) {
          puVar7 = needle + uVar11;
          if (needle[uVar11] == haystack[uVar14 + uVar11]) {
            do {
              uVar11 = uVar11 + 1;
              if (uVar13 <= uVar11) goto LAB_0003f496;
              puVar7 = puVar7 + 1;
            } while (haystack[uVar11 + uVar14] == *puVar7);
          }
          uVar14 = (1 - __n) + uVar14 + uVar11;
          goto LAB_0003f450;
        }
LAB_0003f496:
        uVar11 = __n;
        if ((uVar8 < __n) && (needle[uVar6] == haystack[uVar6 + uVar14])) {
          uVar3 = uVar6;
          puVar7 = needle + uVar6;
          do {
            uVar11 = uVar3;
            if (puVar7 == needle + uVar8) break;
            puVar7 = puVar7 + -1;
            uVar3 = uVar11 - 1;
          } while (*puVar7 == haystack[(uVar11 - 1) + uVar14]);
        }
        if (uVar11 < uVar8 + 1) {
          return haystack + uVar14;
        }
        uVar14 = uVar14 + sVar2;
        uVar8 = needle_len - sVar2;
        if (haystack_len - needle_len < uVar14) {
          return (void *)0x0;
        }
      }
      if ((uVar8 != 0) && (uVar11 < sVar2)) {
        uVar11 = needle_len - sVar2;
      }
      uVar14 = uVar14 + uVar11;
LAB_0003f450:
      uVar8 = 0;
    } while (uVar14 <= haystack_len - needle_len);
  }
  else {
    uVar14 = needle_len - __n;
    if (needle_len - __n < __n) {
      uVar14 = __n;
    }
    iVar4 = __n - 1;
    uVar8 = 0;
    do {
      uVar6 = shift_table[haystack[uVar8 + uVar13]];
      if (uVar6 == 0) {
        if (__n < uVar13) {
          puVar7 = needle + __n;
          uVar6 = __n;
          if (needle[__n] == haystack[__n + uVar8]) {
            do {
              uVar6 = uVar6 + 1;
              if (uVar13 <= uVar6) goto LAB_0003f560;
              puVar7 = puVar7 + 1;
            } while (haystack[uVar6 + uVar8] == *puVar7);
          }
          uVar8 = (1 - __n) + uVar8;
          goto LAB_0003f592;
        }
LAB_0003f560:
        if (iVar4 == -1) {
          return haystack + uVar8;
        }
        if (needle[iVar4] == haystack[uVar8 + iVar4]) {
          iVar12 = iVar4;
          do {
            bVar15 = iVar12 == 0;
            iVar12 = iVar12 + -1;
            if (bVar15) {
              return haystack + uVar8;
            }
          } while (needle[iVar12] == (haystack + uVar8)[iVar12]);
        }
        uVar8 = uVar8 + uVar14 + 1;
      }
      else {
LAB_0003f592:
        uVar8 = uVar8 + uVar6;
      }
    } while (uVar8 <= haystack_len - needle_len);
  }
  return (void *)0x0;
}

