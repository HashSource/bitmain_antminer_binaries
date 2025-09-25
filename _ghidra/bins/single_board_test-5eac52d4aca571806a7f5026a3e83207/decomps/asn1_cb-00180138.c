
undefined4 asn1_cb(char *param_1,char *param_2,int *param_3)

{
  undefined **ppuVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined *puVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  int local_34;
  int local_30;
  int local_2c [2];
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  if ((int)param_2 < 1) {
    pcVar8 = (char *)0x0;
    local_34 = 0;
  }
  else {
    if (*param_1 == ':') {
      pcVar9 = (char *)0x0;
      pcVar8 = param_1;
    }
    else {
      pcVar9 = param_1 + 1;
      do {
        pcVar8 = pcVar9;
        if (param_1 + (int)param_2 == pcVar8) {
          pcVar8 = (char *)0x0;
          local_34 = 0;
          pcVar9 = param_2;
          goto LAB_0018017c;
        }
        pcVar9 = pcVar8 + 1;
      } while (*pcVar8 != ':');
      pcVar9 = pcVar8 + -(int)param_1;
    }
    pcVar8 = pcVar8 + 1;
    local_34 = (int)param_2 - ((int)pcVar8 - (int)param_1);
    param_2 = pcVar9;
  }
  pcVar9 = param_2;
  if (param_2 == (char *)0xffffffff) {
    pcVar9 = (char *)strlen(param_1);
  }
LAB_0018017c:
  pcVar5 = (char *)0x4;
  tntmp_22592 = (undefined **)&tnst_22593;
LAB_001801a6:
  ppuVar1 = tntmp_22592;
  if ((pcVar9 == pcVar5) && (iVar2 = strncmp(*tntmp_22592,param_1,(size_t)pcVar9), iVar2 == 0)) {
    puVar6 = ppuVar1[2];
    if (puVar6 != (undefined *)0xffffffff) {
      if (((uint)puVar6 & 0x10000) == 0) {
        param_3[2] = (int)puVar6;
        param_3[4] = (int)pcVar8;
        if (pcVar8 != (char *)0x0) {
          return 0;
        }
        if (param_1[(int)param_2] != '\0') {
          ERR_put_error(0xd,0xb1,0xbd,"crypto/asn1/asn1_gen.c",0x115);
          return 0xffffffff;
        }
        return 0;
      }
      iVar2 = 0;
      switch(puVar6) {
      case (undefined *)0x10001:
        if (*param_3 != -1) {
          ERR_put_error(0xd,0xb1,0xb5,"crypto/asn1/asn1_gen.c",0x120);
          return 0xffffffff;
        }
        iVar2 = parse_tagging(pcVar8,local_34,param_3,param_3 + 1);
        if (iVar2 != 0) {
          return 1;
        }
        return 0xffffffff;
      case (undefined *)0x10002:
        iVar2 = parse_tagging(pcVar8,local_34,&local_30,local_2c);
        if (iVar2 != 0) {
          if (*param_3 == -1) {
            iVar2 = param_3[0x69];
            if (iVar2 != 0x14) {
              param_3[0x69] = iVar2 + 1;
              param_3[iVar2 * 5 + 5] = local_30;
              param_3[iVar2 * 5 + 6] = local_2c[0];
              param_3[iVar2 * 5 + 8] = 0;
              param_3[iVar2 * 5 + 7] = 1;
              return 1;
            }
            ERR_put_error(0xd,0xb0,0xae,"crypto/asn1/asn1_gen.c",0x1dd);
          }
          else {
            ERR_put_error(0xd,0xb0,0xb3,"crypto/asn1/asn1_gen.c",0x1d8);
          }
        }
        return 0xffffffff;
      default:
        return 1;
      case (undefined *)0x10004:
        iVar4 = param_3[0x69];
        iVar2 = *param_3;
        if (iVar4 != 0x14) {
          iVar3 = iVar4 + 1;
          param_3[0x69] = iVar3;
          iVar7 = 0;
          if (iVar2 != -1) {
            iVar7 = param_3[1];
            iVar3 = -1;
            *param_3 = -1;
          }
          if (iVar2 != -1) {
            param_3[1] = iVar3;
          }
          else {
            iVar2 = 3;
          }
          param_3[iVar4 * 5 + 6] = iVar7;
          param_3[iVar4 * 5 + 5] = iVar2;
          param_3[iVar4 * 5 + 7] = 0;
          param_3[iVar4 * 5 + 8] = 1;
          return 1;
        }
        goto LAB_0018045c;
      case (undefined *)0x10005:
        iVar4 = param_3[0x69];
        iVar2 = *param_3;
        if (iVar4 != 0x14) {
          param_3[0x69] = iVar4 + 1;
          iVar7 = iVar2 + 1;
          bVar10 = iVar7 != 0;
          iVar3 = 0;
          if (bVar10) {
            iVar7 = -1;
            iVar3 = param_3[1];
            *param_3 = -1;
          }
          if (bVar10) {
            param_3[1] = iVar7;
          }
          else {
            iVar2 = 4;
          }
          param_3[iVar4 * 5 + 6] = iVar3;
          param_3[iVar4 * 5 + 5] = iVar2;
          param_3[iVar4 * 5 + 7] = 0;
          param_3[iVar4 * 5 + 8] = 0;
          return 1;
        }
LAB_0018045c:
        ERR_put_error(0xd,0xb0,0xae,"crypto/asn1/asn1_gen.c",0x1dd);
        return 0xffffffff;
      case (undefined *)0x10006:
        iVar7 = param_3[0x69];
        iVar4 = *param_3;
        if (iVar7 == 0x14) goto LAB_0018045c;
        param_3[0x69] = iVar7 + 1;
        if (iVar4 == -1) {
          iVar4 = 0x10;
          goto LAB_001802ce;
        }
        break;
      case (undefined *)0x10007:
        iVar7 = param_3[0x69];
        iVar4 = *param_3;
        if (iVar7 == 0x14) goto LAB_0018045c;
        param_3[0x69] = iVar7 + 1;
        if (iVar4 == -1) {
          iVar4 = 0x11;
          goto LAB_001802ce;
        }
        break;
      case (undefined *)0x10008:
        if (pcVar8 == (char *)0x0) {
          iVar2 = 0x145;
        }
        else {
          iVar2 = strncmp(pcVar8,"ASCII",5);
          if (iVar2 == 0) {
            param_3[3] = 1;
            return 1;
          }
          iVar2 = strncmp(pcVar8,"UTF8",4);
          if (iVar2 == 0) {
            param_3[3] = 2;
            return 1;
          }
          iVar2 = strncmp(pcVar8,"HEX",3);
          if (iVar2 == 0) {
            param_3[3] = 3;
            return 1;
          }
          iVar2 = strncmp(pcVar8,"BITLIST",7);
          if (iVar2 == 0) {
            param_3[3] = 4;
            return 1;
          }
          iVar2 = 0x151;
        }
        ERR_put_error(0xd,0xb1,0xa0,"crypto/asn1/asn1_gen.c",iVar2);
        return 0xffffffff;
      }
      iVar2 = param_3[1];
      *param_3 = -1;
      param_3[1] = -1;
LAB_001802ce:
      param_3[iVar7 * 5 + 6] = iVar2;
      param_3[iVar7 * 5 + 5] = iVar4;
      param_3[iVar7 * 5 + 8] = 0;
      param_3[iVar7 * 5 + 7] = 1;
      return 1;
    }
  }
  else {
    tntmp_22592 = ppuVar1 + 3;
    if (tntmp_22592 != &tag2str_10906) goto code_r0x001801a4;
  }
  ERR_put_error(0xd,0xb1,0xc2,"crypto/asn1/asn1_gen.c",0x10a);
  ERR_add_error_data(2,&DAT_0021f3b0,param_1);
  return 0xffffffff;
code_r0x001801a4:
  pcVar5 = ppuVar1[4];
  goto LAB_001801a6;
}

