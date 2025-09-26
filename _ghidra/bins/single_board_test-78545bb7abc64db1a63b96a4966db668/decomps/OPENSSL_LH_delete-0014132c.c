
undefined4 OPENSSL_LH_delete(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint extraout_r1;
  uint extraout_r1_00;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  void *pvVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  undefined4 uVar12;
  code *pcVar13;
  int iVar14;
  
  param_1[0x17] = 0;
  iVar2 = (*(code *)param_1[2])(param_2);
  piVar5 = param_1 + 0xe;
  do {
    ExclusiveAccess(piVar5);
    bVar1 = (bool)hasExclusiveAccess(piVar5);
  } while (!bVar1);
  *piVar5 = *piVar5 + 1;
  __aeabi_uidivmod(iVar2,param_1[6]);
  uVar10 = extraout_r1;
  if (extraout_r1 < (uint)param_1[5]) {
    __aeabi_uidivmod(iVar2,param_1[4]);
    uVar10 = extraout_r1_00;
  }
  pcVar13 = (code *)param_1[1];
  piVar5 = param_1 + 0x16;
  piVar11 = param_1 + 0xf;
  puVar6 = *(undefined4 **)(*param_1 + uVar10 * 4);
  puVar9 = (undefined4 *)(*param_1 + uVar10 * 4);
  do {
    if (puVar6 == (undefined4 *)0x0) {
LAB_00141478:
      param_1[0x13] = param_1[0x13] + 1;
      return 0;
    }
    do {
      ExclusiveAccess(piVar5);
      bVar1 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar1);
    *piVar5 = *piVar5 + 1;
    if (iVar2 == puVar6[2]) {
      do {
        ExclusiveAccess(piVar11);
        bVar1 = (bool)hasExclusiveAccess(piVar11);
      } while (!bVar1);
      *piVar11 = *piVar11 + 1;
      iVar3 = (*pcVar13)(*puVar6,param_2);
      if (iVar3 == 0) {
        puVar6 = (undefined4 *)*puVar9;
        if (puVar6 != (undefined4 *)0x0) {
          *puVar9 = puVar6[1];
          uVar7 = *puVar6;
          CRYPTO_free(puVar6);
          uVar10 = param_1[3];
          iVar2 = param_1[9];
          param_1[0x12] = param_1[0x12] + 1;
          param_1[9] = iVar2 + -1;
          if (uVar10 < 0x11) {
            return uVar7;
          }
          uVar4 = __aeabi_uidiv((iVar2 + -1) * 0x100,uVar10);
          if ((uint)param_1[8] < uVar4) {
            return uVar7;
          }
          iVar3 = param_1[5];
          iVar14 = param_1[6];
          iVar2 = iVar3 + iVar14 + 0x3fffffff;
          uVar12 = *(undefined4 *)(*param_1 + iVar2 * 4);
          *(undefined4 *)(*param_1 + iVar2 * 4) = 0;
          if (iVar3 == 0) {
            pvVar8 = CRYPTO_realloc((void *)*param_1,iVar14 << 2,"crypto/lhash/lhash.c",0x10c);
            if (pvVar8 == (void *)0x0) {
              param_1[0x17] = param_1[0x17] + 1;
              return uVar7;
            }
            uVar4 = param_1[6];
            *param_1 = (int)pvVar8;
            uVar10 = param_1[3];
            param_1[6] = uVar4 >> 1;
            iVar3 = (uVar4 >> 1) - 1;
            param_1[5] = iVar3;
            param_1[4] = (uint)param_1[4] >> 1;
            param_1[0xd] = param_1[0xd] + 1;
          }
          else {
            pvVar8 = (void *)*param_1;
            iVar3 = iVar3 + -1;
            param_1[5] = iVar3;
          }
          iVar2 = *(int *)((int)pvVar8 + iVar3 * 4);
          param_1[3] = uVar10 - 1;
          param_1[0xc] = param_1[0xc] + 1;
          if (iVar2 == 0) {
            *(undefined4 *)((int)pvVar8 + iVar3 * 4) = uVar12;
            return uVar7;
          }
          do {
            iVar3 = iVar2;
            iVar2 = *(int *)(iVar3 + 4);
          } while (iVar2 != 0);
          *(undefined4 *)(iVar3 + 4) = uVar12;
          return uVar7;
        }
        goto LAB_00141478;
      }
    }
    puVar9 = puVar6 + 1;
    puVar6 = (undefined4 *)puVar6[1];
  } while( true );
}

