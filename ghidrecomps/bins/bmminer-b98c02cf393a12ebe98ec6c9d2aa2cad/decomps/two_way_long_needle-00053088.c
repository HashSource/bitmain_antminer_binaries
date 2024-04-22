
/* WARNING: Type propagation algorithm not settling */

int two_way_long_needle(int param_1,int param_2,char *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  char *pcVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint __n;
  uint local_42c;
  uint local_428 [257];
  
  if (param_4 < 3) {
    __n = param_4 - 1;
    local_42c = 1;
  }
  else {
    __n = critical_factorization_part_0(param_3,param_4,&local_42c);
  }
  uVar9 = local_42c;
  uVar12 = param_4 - 1;
  puVar5 = &local_42c;
  do {
    puVar5 = puVar5 + 1;
    *puVar5 = param_4;
  } while (puVar5 != local_428 + 0xff);
  pbVar3 = (byte *)(param_3 + -1);
  uVar6 = uVar12;
  if (param_4 != 0) {
    do {
      pbVar3 = pbVar3 + 1;
      local_428[*pbVar3] = uVar6;
      uVar6 = uVar6 - 1;
    } while (uVar6 != uVar12 - param_4);
  }
  iVar2 = memcmp(param_3,param_3 + local_42c,__n);
  if (iVar2 != 0) {
    iVar2 = __n - 1;
    uVar9 = param_4 - __n;
    if (param_4 - __n < __n) {
      uVar9 = __n;
    }
    uVar6 = 0;
    do {
      uVar11 = local_428[*(byte *)(param_1 + uVar12 + uVar6)];
      if (local_428[*(byte *)(param_1 + uVar12 + uVar6)] == 0) {
        if (uVar12 <= __n) {
LAB_0005323a:
          if (iVar2 == -1) {
LAB_00053266:
            return param_1 + uVar6;
          }
          pcVar8 = (char *)(iVar2 + uVar6 + param_1);
          pcVar4 = param_3 + iVar2;
          uVar11 = uVar9 + 1;
          if (*(char *)(param_1 + iVar2 + uVar6) == param_3[iVar2]) {
            do {
              if (pcVar4 == param_3) goto LAB_00053266;
              pcVar4 = pcVar4 + -1;
              pcVar8 = pcVar8 + -1;
            } while (*pcVar4 == *pcVar8);
          }
          goto LAB_00053274;
        }
        pcVar8 = (char *)(__n + uVar6 + param_1);
        pcVar4 = param_3 + __n;
        uVar11 = __n;
        if (param_3[__n] == *(char *)(param_1 + __n + uVar6)) {
          do {
            uVar11 = uVar11 + 1;
            if (uVar11 == uVar12) goto LAB_0005323a;
            pcVar4 = pcVar4 + 1;
            pcVar8 = pcVar8 + 1;
          } while (*pcVar4 == *pcVar8);
        }
        uVar6 = uVar6 + (1 - __n) + uVar11;
      }
      else {
LAB_00053274:
        uVar6 = uVar6 + uVar11;
      }
      if (param_2 - param_4 < uVar6) {
        return 0;
      }
    } while( true );
  }
  uVar7 = __n - 1;
  uVar6 = 0;
  uVar11 = 0;
  do {
    while (uVar10 = local_428[*(byte *)(param_1 + uVar12 + uVar6)], uVar10 != 0) {
      if (uVar11 != 0 && uVar10 < uVar9) {
        uVar10 = param_4 - uVar9;
      }
      uVar6 = uVar6 + uVar10;
LAB_00053126:
      uVar11 = 0;
      if (param_2 - param_4 < uVar6) {
        return 0;
      }
    }
    uVar10 = __n;
    if (__n < uVar11) {
      uVar10 = uVar11;
    }
    if (uVar10 < uVar12) {
      pcVar4 = param_3 + uVar10;
      pcVar8 = (char *)(uVar10 + uVar6 + param_1);
      if (param_3[uVar10] == *(char *)(param_1 + uVar10 + uVar6)) {
        do {
          uVar10 = uVar10 + 1;
          if (uVar10 == uVar12) goto LAB_0005316a;
          pcVar4 = pcVar4 + 1;
          pcVar8 = pcVar8 + 1;
        } while (*pcVar4 == *pcVar8);
      }
      uVar6 = uVar6 + (1 - __n) + uVar10;
      goto LAB_00053126;
    }
LAB_0005316a:
    uVar10 = __n;
    if ((uVar11 < __n) &&
       (pcVar4 = (char *)(uVar7 + uVar6 + param_1),
       *(char *)(param_1 + uVar7 + uVar6) == param_3[uVar7])) {
      uVar1 = uVar7;
      pcVar8 = param_3 + uVar7;
      do {
        uVar10 = uVar1;
        if (uVar11 - 1 == uVar10 - 1) break;
        pcVar8 = pcVar8 + -1;
        pcVar4 = pcVar4 + -1;
        uVar1 = uVar10 - 1;
      } while (*pcVar8 == *pcVar4);
    }
    if (uVar10 < uVar11 + 1) {
      return param_1 + uVar6;
    }
    uVar6 = uVar6 + uVar9;
    uVar11 = param_4 - uVar9;
    if (param_2 - param_4 < uVar6) {
      return 0;
    }
  } while( true );
}

