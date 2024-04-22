
uint int_ctrl_helper_isra_0(int param_1,uint param_2,uint param_3,char *param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  uint *puVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  int *piVar13;
  
  if (param_2 == 0xb) {
    puVar5 = *(uint **)(param_1 + 0x50);
    if (puVar5 == (uint *)0x0) {
      return 0;
    }
    uVar6 = *puVar5;
joined_r0x000a6c1a:
    if (uVar6 == 0) {
      return 0;
    }
    if (puVar5[1] != 0) {
      return uVar6;
    }
    return 0;
  }
  if ((param_2 & 0xfffffffd) == 0xd) {
    if (param_4 == (char *)0x0) {
LAB_000a6bd8:
      ERR_put_error(0x26,0xac,0x43,DAT_000a6d1c,0x7b);
      return 0xffffffff;
    }
    if (param_2 == 0xd) {
      piVar13 = *(int **)(param_1 + 0x50);
      if (((piVar13 != (int *)0x0) && (iVar9 = *piVar13, iVar9 != 0)) && (piVar13[1] != 0)) {
        iVar11 = 0;
        piVar7 = piVar13;
        while( true ) {
          pcVar12 = (char *)piVar7[1];
          iVar3 = strcmp(pcVar12,param_4);
          if (iVar3 == 0) break;
          iVar9 = piVar7[4];
          iVar11 = iVar11 + 1;
          if ((iVar9 == 0) || (piVar2 = piVar7 + 5, piVar7 = piVar7 + 4, *piVar2 == 0))
          goto LAB_000a6c56;
        }
        if ((iVar9 != 0) && (pcVar12 != (char *)0x0)) {
          return piVar13[iVar11 * 4];
        }
      }
LAB_000a6c56:
      ERR_put_error(0x26,0xac,0x89,DAT_000a6d1c,0x83);
      return 0xffffffff;
    }
  }
  else if ((param_2 == 0x11) && (param_4 == (char *)0x0)) goto LAB_000a6bd8;
  puVar5 = *(uint **)(param_1 + 0x50);
  if (puVar5 == (uint *)0x0) {
LAB_000a6bb4:
    ERR_put_error(0x26,0xac,0x8a,DAT_000a6d1c,0x8f);
    return 0xffffffff;
  }
  uVar6 = *puVar5;
  uVar10 = uVar6;
  if ((uVar6 != 0) && (uVar10 = puVar5[1], uVar10 != 0)) {
    if (uVar6 < param_3) {
      uVar10 = 0;
      puVar8 = puVar5;
      do {
        uVar6 = puVar8[4];
        uVar10 = uVar10 + 1;
        if ((uVar6 == 0) || (puVar1 = puVar8 + 5, puVar8 = puVar8 + 4, *puVar1 == 0)) break;
      } while (uVar6 < param_3);
    }
    else {
      uVar10 = 0;
    }
  }
  if (param_3 != uVar6) goto LAB_000a6bb4;
  switch(param_2) {
  case 0xc:
    uVar6 = puVar5[(uVar10 + 1) * 4];
    puVar5 = puVar5 + (uVar10 + 1) * 4;
    goto joined_r0x000a6c1a;
  default:
    ERR_put_error(0x26,0xac,0x6e,DAT_000a6d1c,0xaf);
    uVar6 = 0xffffffff;
    break;
  case 0xe:
    uVar6 = puVar5[uVar10 * 4 + 1];
LAB_00012070:
    uVar6 = (*(code *)PTR_strlen_00194240)(uVar6);
    return uVar6;
  case 0xf:
    pcVar12 = (char *)puVar5[uVar10 * 4 + 1];
    goto LAB_000a6c86;
  case 0x10:
    uVar6 = puVar5[uVar10 * 4 + 2];
    if (uVar6 != 0) goto LAB_00012070;
    break;
  case 0x11:
    pcVar12 = (char *)puVar5[uVar10 * 4 + 2];
    if (pcVar12 == (char *)0x0) {
      uVar6 = BIO_snprintf(param_4,1,DAT_000a6d20,DAT_000a6d24);
      return uVar6;
    }
LAB_000a6c86:
    sVar4 = strlen(pcVar12);
    uVar6 = BIO_snprintf(param_4,sVar4 + 1,DAT_000a6d20,pcVar12);
    return uVar6;
  case 0x12:
    uVar6 = puVar5[uVar10 * 4 + 3];
  }
  return uVar6;
}

