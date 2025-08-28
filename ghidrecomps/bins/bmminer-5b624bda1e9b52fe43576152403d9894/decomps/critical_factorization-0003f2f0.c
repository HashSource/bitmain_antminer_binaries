
/* WARNING: Unknown calling convention */

size_t critical_factorization(uchar *needle,size_t needle_len,size_t *period)

{
  uint uVar1;
  size_t sVar2;
  size_t sVar3;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  uint uVar9;
  
  sVar2 = 1;
  uVar1 = 0;
  uVar7 = 0xffffffff;
  sVar8 = 1;
  while (uVar9 = uVar1 + sVar2, sVar3 = sVar2, uVar5 = uVar1, uVar1 + sVar2 < needle_len) {
    while (uVar1 = uVar9, needle[uVar1] < needle[sVar3 + uVar7]) {
      sVar3 = 1;
      sVar8 = uVar1 - uVar7;
      uVar9 = uVar1 + 1;
      uVar5 = uVar1;
      if (needle_len <= uVar1 + 1) goto LAB_0003f324;
    }
    if (needle[uVar1] == needle[sVar3 + uVar7]) {
      if (sVar3 == sVar8) {
        sVar2 = 1;
        sVar8 = sVar3;
      }
      else {
        sVar2 = sVar3 + 1;
        uVar1 = uVar5;
      }
    }
    else {
      sVar2 = 1;
      uVar1 = uVar5 + 1;
      uVar7 = uVar5;
      sVar8 = sVar2;
    }
  }
LAB_0003f324:
  sVar3 = 1;
  *period = sVar8;
  uVar1 = 0;
  sVar2 = 1;
  uVar9 = 0xffffffff;
  while (uVar5 = uVar1 + sVar3, sVar4 = sVar3, uVar6 = uVar1, uVar1 + sVar3 < needle_len) {
    while (uVar1 = uVar5, needle[sVar4 + uVar9] < needle[uVar1]) {
      sVar4 = 1;
      sVar2 = uVar1 - uVar9;
      uVar5 = uVar1 + 1;
      uVar6 = uVar1;
      if (needle_len <= uVar1 + 1) goto LAB_0003f35a;
    }
    if (needle[uVar1] == needle[sVar4 + uVar9]) {
      if (sVar4 == sVar2) {
        sVar3 = 1;
        sVar2 = sVar4;
      }
      else {
        sVar3 = sVar4 + 1;
        uVar1 = uVar6;
      }
    }
    else {
      sVar3 = 1;
      uVar1 = uVar6 + 1;
      sVar2 = 1;
      uVar9 = uVar6;
    }
  }
LAB_0003f35a:
  uVar1 = uVar9 + 1;
  if (uVar9 + 1 < uVar7 + 1) {
    uVar1 = uVar7 + 1;
    sVar2 = sVar8;
  }
  *period = sVar2;
  return uVar1;
}

