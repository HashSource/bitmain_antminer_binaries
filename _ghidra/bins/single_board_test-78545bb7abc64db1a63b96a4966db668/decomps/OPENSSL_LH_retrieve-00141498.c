
undefined4
OPENSSL_LH_retrieve(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint extraout_r1;
  uint uVar4;
  uint extraout_r1_00;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  code *pcVar9;
  int *piVar10;
  
  param_1[0x17] = 0;
  iVar2 = (*(code *)param_1[2])(param_2);
  piVar6 = param_1 + 0xe;
  do {
    ExclusiveAccess(piVar6);
    iVar5 = *piVar6;
    bVar1 = (bool)hasExclusiveAccess(piVar6);
  } while (!bVar1);
  *piVar6 = iVar5 + 1;
  __aeabi_uidivmod(iVar2,param_1[6],iVar5 + 1,piVar6,param_4);
  uVar4 = extraout_r1;
  if (extraout_r1 < (uint)param_1[5]) {
    __aeabi_uidivmod(iVar2,param_1[4]);
    uVar4 = extraout_r1_00;
  }
  pcVar9 = (code *)param_1[1];
  piVar6 = param_1 + 0x16;
  piVar10 = param_1 + 0xf;
  puVar7 = *(undefined4 **)(*param_1 + uVar4 * 4);
  puVar8 = (undefined4 *)(*param_1 + uVar4 * 4);
  do {
    if (puVar7 == (undefined4 *)0x0) {
LAB_00141544:
      param_1 = param_1 + 0x15;
      do {
        ExclusiveAccess(param_1);
        bVar1 = (bool)hasExclusiveAccess(param_1);
      } while (!bVar1);
      *param_1 = *param_1 + 1;
      return 0;
    }
    do {
      ExclusiveAccess(piVar6);
      bVar1 = (bool)hasExclusiveAccess(piVar6);
    } while (!bVar1);
    *piVar6 = *piVar6 + 1;
    if (iVar2 == puVar7[2]) {
      do {
        ExclusiveAccess(piVar10);
        bVar1 = (bool)hasExclusiveAccess(piVar10);
      } while (!bVar1);
      *piVar10 = *piVar10 + 1;
      iVar5 = (*pcVar9)(*puVar7,param_2);
      if (iVar5 == 0) {
        if ((undefined4 *)*puVar8 != (undefined4 *)0x0) {
          uVar3 = *(undefined4 *)*puVar8;
          param_1 = param_1 + 0x14;
          do {
            ExclusiveAccess(param_1);
            bVar1 = (bool)hasExclusiveAccess(param_1);
          } while (!bVar1);
          *param_1 = *param_1 + 1;
          return uVar3;
        }
        goto LAB_00141544;
      }
    }
    puVar8 = puVar7 + 1;
    puVar7 = (undefined4 *)puVar7[1];
  } while( true );
}

