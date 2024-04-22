
undefined4 asn1_cb(char *param_1,size_t param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  bool bVar10;
  size_t local_38;
  char *local_34;
  int local_30;
  int local_2c [2];
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  local_38 = param_2;
  if ((int)param_2 < 1) {
    pcVar8 = (char *)0x0;
    local_34 = (char *)0x0;
  }
  else {
    if (*param_1 == ':') {
      local_38 = 0;
      pcVar8 = param_1;
    }
    else {
      pcVar1 = param_1 + 1;
      do {
        pcVar8 = pcVar1;
        if (pcVar8 == param_1 + param_2) {
          pcVar8 = (char *)0x0;
          local_34 = (char *)0x0;
          goto LAB_00109b74;
        }
        pcVar1 = pcVar8 + 1;
      } while (*pcVar8 != ':');
      local_38 = (int)pcVar8 - (int)param_1;
    }
    pcVar8 = pcVar8 + 1;
    local_34 = param_1 + (param_2 - (int)pcVar8);
  }
  param_2 = local_38;
  if (local_38 == 0xffffffff) {
    param_2 = strlen(param_1);
  }
LAB_00109b74:
  piVar4 = DAT_00109e50;
  iVar7 = DAT_00109e4c + 0xc;
  iVar9 = DAT_00109e4c + 600;
  *DAT_00109e50 = DAT_00109e4c;
LAB_00109b8c:
  HintPreloadData(iVar7 + 0x58);
  if ((*(size_t *)(iVar7 + -8) != param_2) ||
     (iVar2 = strncmp(*(char **)(iVar7 + -0xc),param_1,param_2), iVar2 != 0)) goto LAB_00109b84;
  uVar5 = *(uint *)(iVar7 + -4);
  if (uVar5 != 0xffffffff) {
    if ((uVar5 & 0x10000) == 0) {
      param_3[2] = uVar5;
      param_3[4] = (int)pcVar8;
      if (pcVar8 != (char *)0x0) {
        return 0;
      }
      if (param_1[local_38] != '\0') {
        ERR_put_error(0xd,0xb1,0xbd,DAT_00109e54,0x149);
        return 0xffffffff;
      }
      return 0;
    }
    switch(uVar5) {
    case 0x10001:
      if (*param_3 != -1) {
        ERR_put_error(0xd,0xb1,0xb5,DAT_00109f28,0x154);
        return 0xffffffff;
      }
      iVar7 = parse_tagging(pcVar8,local_34,param_3,param_3 + 1);
      if (iVar7 == 0) {
        return 0xffffffff;
      }
      return 1;
    case 0x10002:
      iVar7 = parse_tagging(pcVar8,local_34,&local_30,local_2c);
      if (iVar7 == 0) {
        return 0xffffffff;
      }
      if (*param_3 == -1) {
        iVar7 = param_3[0x69];
        if (iVar7 == 0x14) {
          ERR_put_error(0xd,0xb0,0xae,DAT_00109f28,0x218);
          return 0xffffffff;
        }
        param_3[0x69] = iVar7 + 1;
        param_3[iVar7 * 5 + 5] = local_30;
        param_3[iVar7 * 5 + 6] = local_2c[0];
        param_3[iVar7 * 5 + 8] = 0;
        param_3[iVar7 * 5 + 7] = 1;
        return 1;
      }
      ERR_put_error(0xd,0xb0,0xb3,DAT_00109e54,0x213);
      return 0xffffffff;
    default:
      return 1;
    case 0x10004:
      iVar2 = param_3[0x69];
      iVar9 = *param_3;
      if (iVar2 != 0x14) {
        iVar3 = iVar9 + 1;
        bVar10 = iVar3 == 0;
        if (!bVar10) {
          iVar7 = param_3[1];
        }
        param_3[0x69] = iVar2 + 1;
        if (bVar10) {
          iVar3 = 3;
          iVar9 = 0;
        }
        if (!bVar10) {
          param_3[iVar2 * 5 + 5] = iVar9;
          iVar3 = -1;
        }
        if (bVar10) {
          param_3[iVar2 * 5 + 5] = iVar3;
        }
        if (bVar10) {
          param_3[iVar2 * 5 + 6] = iVar9;
        }
        if (!bVar10) {
          param_3[iVar2 * 5 + 6] = iVar7;
          *param_3 = iVar3;
        }
        if (!bVar10) {
          param_3[1] = iVar3;
        }
        param_3[iVar2 * 5 + 7] = 0;
        param_3[iVar2 * 5 + 8] = 1;
        return 1;
      }
      goto LAB_00109ea0;
    case 0x10005:
      iVar2 = param_3[0x69];
      iVar9 = *param_3;
      if (iVar2 != 0x14) {
        iVar3 = iVar9 + 1;
        bVar10 = iVar3 == 0;
        if (!bVar10) {
          iVar7 = param_3[1];
        }
        if (bVar10) {
          iVar3 = 4;
        }
        param_3[0x69] = iVar2 + 1;
        if (bVar10) {
          iVar9 = 0;
        }
        else {
          iVar3 = -1;
        }
        if (!bVar10) {
          param_3[iVar2 * 5 + 5] = iVar9;
        }
        if (bVar10) {
          param_3[iVar2 * 5 + 5] = iVar3;
        }
        if (!bVar10) {
          param_3[iVar2 * 5 + 6] = iVar7;
        }
        if (bVar10) {
          param_3[iVar2 * 5 + 6] = iVar9;
        }
        else {
          *param_3 = iVar3;
        }
        if (!bVar10) {
          param_3[1] = iVar3;
        }
        param_3[iVar2 * 5 + 7] = 0;
        param_3[iVar2 * 5 + 8] = 0;
        return 1;
      }
LAB_00109ea0:
      ERR_put_error(0xd,0xb0,0xae,DAT_00109f28,0x218);
      return 0xffffffff;
    case 0x10006:
      iVar9 = param_3[0x69];
      iVar7 = *param_3;
      if (iVar9 == 0x14) goto LAB_00109ea0;
      piVar4 = param_3 + iVar9 * 5;
      param_3[0x69] = iVar9 + 1;
      piVar6 = piVar4 + 5;
      if (iVar7 == -1) {
        piVar4[5] = 0x10;
        piVar4[6] = 0;
        goto LAB_00109cea;
      }
      break;
    case 0x10007:
      iVar9 = param_3[0x69];
      iVar7 = *param_3;
      if (iVar9 == 0x14) goto LAB_00109ea0;
      piVar4 = param_3 + iVar9 * 5;
      param_3[0x69] = iVar9 + 1;
      piVar6 = piVar4 + 5;
      if (iVar7 == -1) {
        piVar4[5] = 0x11;
        piVar4[6] = 0;
        goto LAB_00109cea;
      }
      break;
    case 0x10008:
      if (pcVar8 == (char *)0x0) {
        ERR_put_error(0xd,0xb1,0xa0,DAT_00109f28,0x179);
        return 0xffffffff;
      }
      iVar7 = strncmp(pcVar8,DAT_00109e5c,5);
      if (iVar7 == 0) {
        param_3[3] = 1;
        return 1;
      }
      iVar7 = strncmp(pcVar8,DAT_00109e60,4);
      if (iVar7 == 0) {
        param_3[3] = 2;
        return 1;
      }
      iVar7 = strncmp(pcVar8,DAT_00109e64,3);
      if (iVar7 == 0) {
        param_3[3] = 3;
        return 1;
      }
      iVar7 = strncmp(pcVar8,DAT_00109e68,7);
      if (iVar7 != 0) {
        ERR_put_error(0xd,0xb1,0xc3,DAT_00109f28,0x185);
        return 0xffffffff;
      }
      param_3[3] = 4;
      return 1;
    }
    iVar9 = param_3[1];
    piVar4[5] = iVar7;
    piVar6[1] = iVar9;
    *param_3 = -1;
    param_3[1] = -1;
LAB_00109cea:
    piVar6[2] = 1;
    piVar6[3] = 0;
    return 1;
  }
  goto LAB_00109bd0;
LAB_00109b84:
  *piVar4 = iVar7;
  iVar7 = iVar7 + 0xc;
  if (iVar7 == iVar9) {
LAB_00109bd0:
    ERR_put_error(0xd,0xb1,0xc2,DAT_00109e54,0x13e);
    ERR_add_error_data(2,DAT_00109e58,param_1);
    return 0xffffffff;
  }
  goto LAB_00109b8c;
}

