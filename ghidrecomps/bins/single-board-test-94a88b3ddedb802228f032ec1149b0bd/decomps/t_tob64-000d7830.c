
void t_tob64(undefined *param_1,byte *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  iVar1 = DAT_000d7910;
  iVar7 = param_3 % 3;
  if (iVar7 == 1) {
    uVar6 = (uint)*param_2;
    uVar8 = 0;
  }
  else if (iVar7 == 2) {
    uVar8 = (uint)*param_2;
    uVar6 = (uint)param_2[1];
  }
  else {
    uVar6 = 0;
    uVar8 = uVar6;
  }
  uVar9 = 0;
  uVar5 = 0;
  pbVar3 = param_2 + iVar7;
  do {
    iVar2 = DAT_000d7910;
    uVar9 = uVar9 & 1;
    if (uVar5 >> 2 != 0) {
      uVar9 = 1;
    }
    if (uVar9 == 0) {
      uVar9 = uVar8 >> 4 | (uVar5 & 3) << 4;
      puVar4 = param_1;
      if (uVar9 != 0) goto LAB_000d7882;
      uVar8 = uVar6 >> 6 | (uVar8 & 0xf) << 2;
      if (uVar8 != 0) goto LAB_000d7894;
      uVar9 = uVar6 & 0x3f;
      if (uVar9 != 0) goto LAB_000d789e;
    }
    else {
      uVar9 = uVar8 >> 4 | (uVar5 & 3) << 4;
      *param_1 = *(undefined *)(iVar1 + (uVar5 >> 2));
      puVar4 = param_1 + 1;
LAB_000d7882:
      uVar8 = uVar6 >> 6 | (uVar8 & 0xf) << 2;
      param_1 = puVar4 + 1;
      *puVar4 = *(undefined *)(iVar2 + uVar9);
LAB_000d7894:
      *param_1 = *(undefined *)(iVar2 + uVar8);
      puVar4 = param_1 + 1;
LAB_000d789e:
      uVar9 = 1;
      param_1 = puVar4 + 1;
      *puVar4 = *(undefined *)(iVar2 + (uVar6 & 0x3f));
    }
    if (param_3 <= iVar7) {
      *param_1 = 0;
      return;
    }
    uVar5 = (uint)*pbVar3;
    iVar7 = iVar7 + 3;
    uVar8 = (uint)pbVar3[1];
    uVar6 = (uint)pbVar3[2];
    pbVar3 = pbVar3 + 3;
  } while( true );
}

