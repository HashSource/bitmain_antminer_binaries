
/* WARNING: Unknown calling convention */

size_t critical_factorization(uchar *needle,size_t needle_len,size_t *period)

{
  uint uVar1;
  uint uVar2;
  size_t k;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  size_t j;
  uint uVar6;
  size_t max_suffix;
  size_t p;
  uchar b;
  size_t max_suffix_rev;
  
  k = 1;
  j = 0;
  max_suffix = 0xffffffff;
  p = 1;
  while (uVar2 = j + k, sVar3 = k, sVar4 = j, j + k < needle_len) {
    while (j = uVar2, needle[j] < needle[sVar3 + max_suffix]) {
      sVar3 = 1;
      p = j - max_suffix;
      uVar2 = j + 1;
      sVar4 = j;
      if (needle_len <= j + 1) goto LAB_0003f324;
    }
    if (needle[j] == needle[sVar3 + max_suffix]) {
      if (sVar3 == p) {
        k = 1;
        p = sVar3;
      }
      else {
        k = sVar3 + 1;
        j = sVar4;
      }
    }
    else {
      k = 1;
      j = sVar4 + 1;
      max_suffix = sVar4;
      p = k;
    }
  }
LAB_0003f324:
  sVar4 = 1;
  *period = p;
  uVar2 = 0;
  sVar3 = 1;
  max_suffix_rev = 0xffffffff;
  while (uVar1 = uVar2 + sVar4, sVar5 = sVar4, uVar6 = uVar2, uVar2 + sVar4 < needle_len) {
    while (uVar2 = uVar1, needle[sVar5 + max_suffix_rev] < needle[uVar2]) {
      sVar5 = 1;
      sVar3 = uVar2 - max_suffix_rev;
      uVar1 = uVar2 + 1;
      uVar6 = uVar2;
      if (needle_len <= uVar2 + 1) goto LAB_0003f35a;
    }
    if (needle[uVar2] == needle[sVar5 + max_suffix_rev]) {
      if (sVar5 == sVar3) {
        sVar4 = 1;
        sVar3 = sVar5;
      }
      else {
        sVar4 = sVar5 + 1;
        uVar2 = uVar6;
      }
    }
    else {
      sVar4 = 1;
      uVar2 = uVar6 + 1;
      sVar3 = 1;
      max_suffix_rev = uVar6;
    }
  }
LAB_0003f35a:
  uVar2 = max_suffix_rev + 1;
  if (max_suffix_rev + 1 < max_suffix + 1) {
    uVar2 = max_suffix + 1;
    sVar3 = p;
  }
  *period = sVar3;
  return uVar2;
}

