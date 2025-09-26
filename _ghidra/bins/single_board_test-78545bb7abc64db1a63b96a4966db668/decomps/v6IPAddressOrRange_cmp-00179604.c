
int v6IPAddressOrRange_cmp(undefined4 *param_1,undefined4 *param_2)

{
  byte *pbVar1;
  undefined1 *puVar2;
  uint __n;
  undefined1 *puVar3;
  int iVar4;
  size_t sVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  size_t *psVar9;
  int iVar10;
  uint *puVar11;
  undefined1 auStack_38 [15];
  byte abStack_29 [21];
  
  puVar3 = auStack_38;
  puVar2 = auStack_38;
  piVar6 = (int *)*param_1;
  piVar8 = (int *)*param_2;
  if (*piVar6 == 0) {
    psVar9 = (size_t *)piVar6[1];
    sVar5 = *psVar9;
    if (sVar5 < 0x11) {
      if (sVar5 == 0) {
        sVar5 = 0;
      }
      else {
        puVar3 = (undefined1 *)memcpy(auStack_38,(void *)psVar9[2],sVar5);
        if ((psVar9[3] & 7) != 0) {
          puVar3[*psVar9 - 1] = puVar3[*psVar9 - 1] & ~(byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff));
        }
        sVar5 = *psVar9;
      }
      memset(puVar3 + sVar5,0,0x10 - sVar5);
      iVar7 = *(int *)piVar6[1] * 8 - (((int *)piVar6[1])[3] & 7U);
      goto LAB_00179618;
    }
LAB_0017969c:
    iVar4 = -1;
  }
  else {
    if (*piVar6 == 1) {
      psVar9 = *(size_t **)piVar6[1];
      sVar5 = *psVar9;
      if (0x10 < sVar5) goto LAB_0017969c;
      if (sVar5 == 0) {
        sVar5 = 0;
      }
      else {
        puVar2 = (undefined1 *)memcpy(auStack_38,(void *)psVar9[2],sVar5);
        if ((psVar9[3] & 7) != 0) {
          puVar2[*psVar9 - 1] = puVar2[*psVar9 - 1] & ~(byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff));
        }
        sVar5 = *psVar9;
      }
      iVar7 = 0x80;
      memset(puVar2 + sVar5,0,0x10 - sVar5);
    }
    else {
      iVar7 = 0;
    }
LAB_00179618:
    if (*piVar8 == 0) {
      puVar11 = (uint *)piVar8[1];
      __n = *puVar11;
      if (0x10 < __n) goto LAB_0017969c;
      pbVar1 = abStack_29 + 1;
      if (__n != 0) {
        memcpy(pbVar1,(void *)puVar11[2],__n);
        if ((puVar11[3] & 7) != 0) {
          pbVar1[*puVar11 - 1] =
               pbVar1[*puVar11 - 1] & ~(byte)(0xff >> (8 - (puVar11[3] & 7) & 0xff));
        }
        __n = *puVar11;
      }
      memset(pbVar1 + __n,0,0x10 - __n);
      iVar10 = *(int *)piVar8[1] * 8 - (((int *)piVar8[1])[3] & 7U);
    }
    else if (*piVar8 == 1) {
      psVar9 = *(size_t **)piVar8[1];
      sVar5 = *psVar9;
      if (0x10 < sVar5) goto LAB_0017969c;
      if (sVar5 == 0) {
        sVar5 = 0;
      }
      else {
        pbVar1 = abStack_29 + 1;
        memcpy(pbVar1,(void *)psVar9[2],sVar5);
        sVar5 = *psVar9;
        if ((psVar9[3] & 7) != 0) {
          pbVar1[sVar5 - 1] = pbVar1[sVar5 - 1] & ~(byte)(0xff >> (8 - (psVar9[3] & 7) & 0xff));
          sVar5 = *psVar9;
        }
      }
      iVar10 = 0x80;
      memset(abStack_29 + sVar5 + 1,0,0x10 - sVar5);
    }
    else {
      iVar10 = 0;
    }
    iVar4 = memcmp(auStack_38,abStack_29 + 1,0x10);
    if (iVar4 == 0) {
      return iVar7 - iVar10;
    }
  }
  return iVar4;
}

