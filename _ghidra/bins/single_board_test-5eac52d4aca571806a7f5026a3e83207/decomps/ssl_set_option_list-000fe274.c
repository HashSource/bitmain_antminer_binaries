
undefined4 ssl_set_option_list(char *param_1,size_t param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (param_2 == 0xffffffff) {
    uVar10 = param_3[0x14];
    puVar9 = (undefined4 *)param_3[0x13];
    if (uVar10 == 0) {
      return 0;
    }
    uVar4 = *param_3;
    bVar2 = false;
    bVar1 = true;
LAB_000fe360:
    uVar8 = 0;
    do {
      uVar7 = puVar9[2];
      uVar8 = uVar8 + 1;
      HintPreloadData(puVar9 + 0x22);
      if (((uVar4 & 0xc & uVar7) != 0) && (iVar3 = strcmp((char *)*puVar9,param_1), iVar3 == 0)) {
LAB_000fe2f2:
        puVar5 = (uint *)param_3[5];
        if (puVar5 != (uint *)0x0) {
          uVar10 = uVar7 & 0xf00;
          if ((uVar7 & 1) != 0) {
            bVar1 = bVar2;
          }
          if (uVar10 == 0x100) {
            puVar5 = (uint *)param_3[0xf];
          }
          else if (uVar10 == 0x200) {
            puVar5 = (uint *)param_3[0x10];
          }
          else if (uVar10 != 0) {
            return 1;
          }
          if (bVar1) {
            *puVar5 = puVar9[3] | *puVar5;
          }
          else {
            *puVar5 = *puVar5 & ~puVar9[3];
          }
        }
        return 1;
      }
      puVar9 = puVar9 + 4;
    } while (uVar8 != uVar10);
  }
  else {
    if (*param_1 == '+') {
      bVar2 = false;
      bVar1 = true;
LAB_000fe396:
      param_2 = param_2 - 1;
      param_1 = param_1 + 1;
      uVar10 = param_3[0x14];
      puVar9 = (undefined4 *)param_3[0x13];
      if (uVar10 == 0) {
        return 0;
      }
      uVar4 = *param_3;
      if (param_2 == 0xffffffff) goto LAB_000fe360;
    }
    else {
      if (*param_1 == '-') {
        bVar2 = true;
        bVar1 = false;
        goto LAB_000fe396;
      }
      uVar10 = param_3[0x14];
      puVar9 = (undefined4 *)param_3[0x13];
      if (uVar10 == 0) {
        return 0;
      }
      uVar4 = *param_3;
      bVar2 = false;
      bVar1 = true;
    }
    puVar6 = puVar9 + 0x1d;
    uVar8 = 0;
    do {
      uVar7 = puVar6[-0x1b];
      uVar8 = uVar8 + 1;
      puVar9 = puVar6 + -0x1d;
      HintPreloadData(puVar6);
      if ((((uVar4 & 0xc & uVar7) != 0) && (puVar6[-0x1c] == param_2)) &&
         (iVar3 = strncasecmp((char *)puVar6[-0x1d],param_1,param_2), iVar3 == 0))
      goto LAB_000fe2f2;
      puVar6 = puVar6 + 4;
    } while (uVar8 != uVar10);
  }
  return 0;
}

