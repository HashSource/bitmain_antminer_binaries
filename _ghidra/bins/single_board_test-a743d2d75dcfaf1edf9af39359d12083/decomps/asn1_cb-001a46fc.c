
undefined4 asn1_cb(char *param_1,size_t param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
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
    pcVar9 = (char *)0x0;
    local_34 = (char *)0x0;
  }
  else {
    if (*param_1 == ':') {
      local_38 = 0;
      pcVar9 = param_1;
    }
    else {
      pcVar1 = param_1 + 1;
      do {
        pcVar9 = pcVar1;
        if (pcVar9 == param_1 + param_2) {
          pcVar9 = (char *)0x0;
          local_34 = (char *)0x0;
          goto LAB_001a4744;
        }
        pcVar1 = pcVar9 + 1;
      } while (*pcVar9 != ':');
      local_38 = (int)pcVar9 - (int)param_1;
    }
    pcVar9 = pcVar9 + 1;
    local_34 = param_1 + (param_2 - (int)pcVar9);
  }
  param_2 = local_38;
  if (local_38 == 0xffffffff) {
    param_2 = strlen(param_1);
  }
LAB_001a4744:
  tntmp_16050 = "\bK\"";
  pcVar1 = "\x10K\"";
LAB_001a475c:
  pcVar8 = pcVar1;
  HintPreloadData(pcVar8 + 0x58);
  if ((*(size_t *)(pcVar8 + -8) != param_2) ||
     (iVar2 = strncmp(*(char **)(pcVar8 + -0xc),param_1,param_2), iVar2 != 0)) goto LAB_001a4754;
  uVar5 = *(uint *)(pcVar8 + -4);
  if (uVar5 != 0xffffffff) {
    if ((uVar5 & 0x10000) == 0) {
      param_3[2] = uVar5;
      param_3[4] = (int)pcVar9;
      if (pcVar9 != (char *)0x0) {
        return 0;
      }
      if (param_1[local_38] != '\0') {
        ERR_put_error(0xd,0xb1,0xbd,"asn1_gen.c",0x149);
        return 0xffffffff;
      }
      return 0;
    }
    switch(uVar5) {
    case 0x10001:
      if (*param_3 != -1) {
        ERR_put_error(0xd,0xb1,0xb5,"asn1_gen.c",0x154);
        return 0xffffffff;
      }
      iVar2 = parse_tagging(pcVar9,local_34,param_3,param_3 + 1);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      return 1;
    case 0x10002:
      iVar2 = parse_tagging(pcVar9,local_34,&local_30,local_2c);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      if (*param_3 == -1) {
        iVar2 = param_3[0x69];
        if (iVar2 == 0x14) {
          ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x218);
          return 0xffffffff;
        }
        param_3[0x69] = iVar2 + 1;
        param_3[iVar2 * 5 + 5] = local_30;
        param_3[iVar2 * 5 + 6] = local_2c[0];
        param_3[iVar2 * 5 + 8] = 0;
        param_3[iVar2 * 5 + 7] = 1;
        return 1;
      }
      ERR_put_error(0xd,0xb0,0xb3,"asn1_gen.c",0x213);
      return 0xffffffff;
    default:
      return 1;
    case 0x10004:
      iVar6 = param_3[0x69];
      iVar2 = *param_3;
      if (iVar6 != 0x14) {
        iVar3 = iVar2 + 1;
        bVar10 = iVar3 == 0;
        if (!bVar10) {
          pcVar8 = (char *)param_3[1];
        }
        param_3[0x69] = iVar6 + 1;
        if (bVar10) {
          iVar3 = 3;
          iVar2 = 0;
        }
        if (!bVar10) {
          param_3[iVar6 * 5 + 5] = iVar2;
          iVar3 = -1;
        }
        if (bVar10) {
          param_3[iVar6 * 5 + 5] = iVar3;
        }
        if (bVar10) {
          param_3[iVar6 * 5 + 6] = iVar2;
        }
        if (!bVar10) {
          param_3[iVar6 * 5 + 6] = (int)pcVar8;
          *param_3 = iVar3;
        }
        if (!bVar10) {
          param_3[1] = iVar3;
        }
        param_3[iVar6 * 5 + 7] = 0;
        param_3[iVar6 * 5 + 8] = 1;
        return 1;
      }
      goto LAB_001a4a70;
    case 0x10005:
      iVar6 = param_3[0x69];
      iVar2 = *param_3;
      if (iVar6 != 0x14) {
        iVar3 = iVar2 + 1;
        bVar10 = iVar3 == 0;
        if (!bVar10) {
          pcVar8 = (char *)param_3[1];
        }
        if (bVar10) {
          iVar3 = 4;
        }
        param_3[0x69] = iVar6 + 1;
        if (bVar10) {
          iVar2 = 0;
        }
        else {
          iVar3 = -1;
        }
        if (!bVar10) {
          param_3[iVar6 * 5 + 5] = iVar2;
        }
        if (bVar10) {
          param_3[iVar6 * 5 + 5] = iVar3;
        }
        if (!bVar10) {
          param_3[iVar6 * 5 + 6] = (int)pcVar8;
        }
        if (bVar10) {
          param_3[iVar6 * 5 + 6] = iVar2;
        }
        else {
          *param_3 = iVar3;
        }
        if (!bVar10) {
          param_3[1] = iVar3;
        }
        param_3[iVar6 * 5 + 7] = 0;
        param_3[iVar6 * 5 + 8] = 0;
        return 1;
      }
LAB_001a4a70:
      ERR_put_error(0xd,0xb0,0xae,"asn1_gen.c",0x218);
      return 0xffffffff;
    case 0x10006:
      iVar6 = param_3[0x69];
      iVar2 = *param_3;
      if (iVar6 == 0x14) goto LAB_001a4a70;
      piVar4 = param_3 + iVar6 * 5;
      param_3[0x69] = iVar6 + 1;
      piVar7 = piVar4 + 5;
      if (iVar2 == -1) {
        piVar4[5] = 0x10;
        piVar4[6] = 0;
        goto LAB_001a48ba;
      }
      break;
    case 0x10007:
      iVar6 = param_3[0x69];
      iVar2 = *param_3;
      if (iVar6 == 0x14) goto LAB_001a4a70;
      piVar4 = param_3 + iVar6 * 5;
      param_3[0x69] = iVar6 + 1;
      piVar7 = piVar4 + 5;
      if (iVar2 == -1) {
        piVar4[5] = 0x11;
        piVar4[6] = 0;
        goto LAB_001a48ba;
      }
      break;
    case 0x10008:
      if (pcVar9 == (char *)0x0) {
        ERR_put_error(0xd,0xb1,0xa0,"asn1_gen.c",0x179);
        return 0xffffffff;
      }
      iVar2 = strncmp(pcVar9,"ASCII",5);
      if (iVar2 == 0) {
        param_3[3] = 1;
        return 1;
      }
      iVar2 = strncmp(pcVar9,"UTF8",4);
      if (iVar2 == 0) {
        param_3[3] = 2;
        return 1;
      }
      iVar2 = strncmp(pcVar9,"HEX",3);
      if (iVar2 == 0) {
        param_3[3] = 3;
        return 1;
      }
      iVar2 = strncmp(pcVar9,"BITLIST",7);
      if (iVar2 != 0) {
        ERR_put_error(0xd,0xb1,0xc3,"asn1_gen.c",0x185);
        return 0xffffffff;
      }
      param_3[3] = 4;
      return 1;
    }
    iVar6 = param_3[1];
    piVar4[5] = iVar2;
    piVar7[1] = iVar6;
    *param_3 = -1;
    param_3[1] = -1;
LAB_001a48ba:
    piVar7[2] = 1;
    piVar7[3] = 0;
    return 1;
  }
  goto LAB_001a47a0;
LAB_001a4754:
  pcVar1 = pcVar8 + 0xc;
  tntmp_16050 = pcVar8;
  if (pcVar8 + 0xc == "string=") {
LAB_001a47a0:
    ERR_put_error(0xd,0xb1,0xc2,"asn1_gen.c",0x13e);
    ERR_add_error_data(2,&DAT_00224ae4,param_1);
    return 0xffffffff;
  }
  goto LAB_001a475c;
}

