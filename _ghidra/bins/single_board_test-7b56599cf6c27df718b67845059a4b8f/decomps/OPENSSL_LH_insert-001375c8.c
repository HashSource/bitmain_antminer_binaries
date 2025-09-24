
undefined4 OPENSSL_LH_insert(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  int extraout_r3;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  code *pcVar14;
  
  iVar6 = param_1[3];
  param_1[0x17] = 0;
  uVar2 = __aeabi_uidiv(param_1[9] << 8,iVar6,param_3,param_4,param_4);
  if ((uint)param_1[7] <= uVar2) {
    iVar12 = param_1[5];
    uVar2 = param_1[6];
    iVar13 = param_1[4];
    if (iVar12 + 1U < uVar2) {
      param_1[5] = iVar12 + 1U;
    }
    else {
      pvVar4 = CRYPTO_realloc((void *)*param_1,iVar13 << 3,"crypto/lhash/lhash.c",0xe1);
      if (pvVar4 == (void *)0x0) {
        param_1[0x17] = param_1[0x17] + 1;
        return 0;
      }
      *param_1 = (int)pvVar4;
      memset((void *)((int)pvVar4 + iVar13 * 4),0,iVar13 * 4);
      param_1[4] = iVar13 << 1;
      param_1[6] = iVar13;
      param_1[5] = 0;
      param_1[0xb] = param_1[0xb] + 1;
      iVar6 = param_1[3];
    }
    iVar7 = *param_1;
    iVar9 = uVar2 + iVar12;
    param_1[3] = iVar6 + 1;
    param_1[10] = param_1[10] + 1;
    *(undefined4 *)(iVar7 + iVar9 * 4) = 0;
    piVar10 = (int *)(iVar7 + iVar9 * 4);
    piVar8 = (int *)(iVar7 + iVar12 * 4);
    iVar6 = *(int *)(iVar7 + iVar12 * 4);
    while (iVar6 != 0) {
      __aeabi_uidivmod(*(undefined4 *)(iVar6 + 8),iVar13);
      if (iVar12 != extraout_r1) {
        *piVar8 = *(int *)(iVar6 + 4);
        iVar7 = *piVar10;
      }
      else {
        piVar8 = (int *)(iVar6 + 4);
        iVar7 = extraout_r3;
      }
      if (iVar12 != extraout_r1) {
        *(int *)(iVar6 + 4) = iVar7;
        *piVar10 = iVar6;
      }
      iVar6 = *piVar8;
    }
  }
  iVar6 = (*(code *)param_1[2])(param_2);
  piVar8 = param_1 + 0xe;
  do {
    ExclusiveAccess(piVar8);
    bVar1 = (bool)hasExclusiveAccess(piVar8);
  } while (!bVar1);
  *piVar8 = *piVar8 + 1;
  __aeabi_uidivmod(iVar6,param_1[6]);
  uVar2 = extraout_r1_00;
  if (extraout_r1_00 < (uint)param_1[5]) {
    __aeabi_uidivmod(iVar6,param_1[4]);
    uVar2 = extraout_r1_01;
  }
  pcVar14 = (code *)param_1[1];
  puVar5 = *(undefined4 **)(*param_1 + uVar2 * 4);
  puVar11 = (undefined4 *)(*param_1 + uVar2 * 4);
  if (puVar5 != (undefined4 *)0x0) {
    piVar8 = param_1 + 0x16;
    piVar10 = param_1 + 0xf;
    do {
      do {
        ExclusiveAccess(piVar8);
        bVar1 = (bool)hasExclusiveAccess(piVar8);
      } while (!bVar1);
      *piVar8 = *piVar8 + 1;
      if (iVar6 == puVar5[2]) {
        do {
          ExclusiveAccess(piVar10);
          bVar1 = (bool)hasExclusiveAccess(piVar10);
        } while (!bVar1);
        *piVar10 = *piVar10 + 1;
        iVar12 = (*pcVar14)(*puVar5,param_2);
        if (iVar12 == 0) {
          puVar5 = (undefined4 *)*puVar11;
          if (puVar5 != (undefined4 *)0x0) {
            iVar6 = param_1[0x11];
            uVar3 = *puVar5;
            *puVar5 = param_2;
            param_1[0x11] = iVar6 + 1;
            return uVar3;
          }
          break;
        }
      }
      puVar11 = puVar5 + 1;
      puVar5 = (undefined4 *)puVar5[1];
    } while (puVar5 != (undefined4 *)0x0);
  }
  puVar5 = (undefined4 *)CRYPTO_malloc(0xc,"crypto/lhash/lhash.c",0x6d);
  if (puVar5 != (undefined4 *)0x0) {
    iVar12 = param_1[0x10];
    iVar13 = param_1[9];
    *puVar5 = param_2;
    puVar5[2] = iVar6;
    puVar5[1] = 0;
    *puVar11 = puVar5;
    param_1[0x10] = iVar12 + 1;
    param_1[9] = iVar13 + 1;
    return 0;
  }
  param_1[0x17] = param_1[0x17] + 1;
  return 0;
}

