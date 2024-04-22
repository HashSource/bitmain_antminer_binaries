
uint ftp_done(int *param_1,uint param_2,int param_3)

{
  char cVar1;
  code **ppcVar2;
  char *pcVar3;
  char *__s;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  char **ppcVar13;
  uint **ppuVar14;
  undefined4 uVar15;
  uint uVar16;
  bool bVar17;
  int local_40;
  int iStack_3c;
  int local_38;
  int local_34;
  undefined auStack_30 [4];
  int local_2c [2];
  
  iVar11 = *param_1;
  piVar12 = param_1 + 0xf0;
  ppuVar14 = *(uint ***)(iVar11 + 0x14c);
  uVar15 = *(undefined4 *)(iVar11 + 0x868c);
  if (ppuVar14 == (uint **)0x0) {
    return 0;
  }
  switch(param_2) {
  case 0:
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x17:
  case 0x19:
  case 0x1e:
  case 0x24:
  case 0x3f:
  case 0x4e:
    if (param_3 != 0) goto switchD_0005e438_caseD_1;
    uVar6 = 0;
    break;
  default:
switchD_0005e438_caseD_1:
    *(undefined *)((int)param_1 + 0x40f) = 1;
    *(undefined *)((int)param_1 + 0x40d) = 0;
    *(undefined *)((int)param_1 + 0x1ed) = 1;
    uVar6 = param_2;
  }
  ppcVar2 = DAT_0005e7f8;
  (**DAT_0005e7f8)(param_1[0x105]);
  if (*(char *)(iVar11 + 0x414) != '\0') {
    if ((*(code **)(iVar11 + 0x41c) != (code *)0x0) && (param_1[0x102] != 0)) {
      (**(code **)(iVar11 + 0x41c))(*(undefined4 *)(iVar11 + 0x86f0));
    }
    param_1[0x110] = -1;
    param_1[0x111] = -1;
  }
  pcVar3 = (char *)curl_easy_unescape(iVar11,uVar15,0,0);
  if (pcVar3 == (char *)0x0) {
    *(undefined *)((int)param_1 + 0x40d) = 0;
    param_1[0x105] = 0;
    *(undefined *)((int)param_1 + 0x1ed) = 1;
    if (uVar6 == 0) {
      uVar6 = 0x1b;
    }
    freedirs(piVar12);
    if (param_1[0x56] == -1) goto LAB_0005e5f0;
LAB_0005e58e:
    if (*(char *)(param_1 + 100) != '\0') {
      Curl_ssl_close(param_1,1);
    }
    close_secondarysocket(param_1);
  }
  else {
    __s = (char *)param_1[0x102];
    if (__s != (char *)0x0) {
      __s = (char *)strlen(__s);
    }
    sVar4 = strlen(pcVar3);
    if (*(char *)((int)param_1 + 0x40f) == '\0') {
      if ((sVar4 - (int)__s == 0) || (*(int *)(iVar11 + 0x2e8) == 2)) {
        iVar10 = (**DAT_0005e7d4)(DAT_0005e7d8);
        pcVar8 = *ppcVar2;
        param_1[0x105] = iVar10;
        (*pcVar8)(pcVar3);
LAB_0005e546:
        pcVar3 = (char *)param_1[0x105];
        if (pcVar3 == (char *)0x0) goto LAB_0005e55a;
      }
      else {
        param_1[0x105] = (int)pcVar3;
        if (__s != (char *)0x0) {
          pcVar3[sVar4 - (int)__s] = '\0';
          goto LAB_0005e546;
        }
      }
      Curl_infof(iVar11,DAT_0005e7dc,pcVar3);
    }
    else {
      pcVar8 = *ppcVar2;
      param_1[0x105] = 0;
      (*pcVar8)(pcVar3);
    }
LAB_0005e55a:
    freedirs(piVar12);
    if (param_1[0x56] != -1) {
      if ((((uVar6 == 0) && (*(char *)(param_1 + 0x103) != '\0')) &&
          (bVar17 = *(int *)(iVar11 + 0x60) == 0,
          (int)(*(int *)(iVar11 + 100) - (uint)bVar17) < 0 ==
          (SBORROW4(*(int *)(iVar11 + 100),(uint)bVar17) != false))) &&
         (uVar5 = Curl_pp_sendf(piVar12,DAT_0005e7e0,DAT_0005e7e4), uVar5 != 0)) {
        uVar15 = curl_easy_strerror();
        Curl_failf(iVar11,DAT_0005e7f4,uVar15);
        *(undefined *)((int)param_1 + 0x40d) = 0;
        *(undefined *)((int)param_1 + 0x1ed) = 1;
        uVar6 = uVar5;
      }
      goto LAB_0005e58e;
    }
  }
  if (uVar6 == 0) {
    if (((ppuVar14[3] == (uint *)0x0) && (*(char *)((int)param_1 + 0x40d) != '\0')) &&
       (*(char *)(param_1 + 0xf4) != '\0')) {
      if (param_3 != 0) goto LAB_0005e5f0;
      iVar10 = param_1[0xfa];
      param_1[0xfa] = 60000;
      curlx_tvnow(&local_40);
      param_1[0xf8] = local_40;
      param_1[0xf9] = iStack_3c;
      uVar5 = Curl_GetFTPResponse(&local_38,param_1,&local_34);
      param_1[0xfa] = iVar10;
      if ((local_38 == 0) && (uVar5 == 0x1c)) {
        Curl_failf(iVar11,DAT_0005e858);
        *(undefined *)((int)param_1 + 0x40d) = 0;
        *(undefined *)((int)param_1 + 0x1ed) = 1;
        return 0x1c;
      }
      if (uVar5 != 0) {
        return uVar5;
      }
      if (*(char *)(param_1 + 0x103) == '\0') {
        if (local_34 != 0xfa && local_34 != 0xe2) {
          uVar6 = 0x12;
          Curl_failf(iVar11,DAT_0005e7ec);
          goto LAB_0005e5f0;
        }
      }
      else {
        bVar17 = *(int *)(iVar11 + 0x60) == 0;
        if ((int)(*(int *)(iVar11 + 100) - (uint)bVar17) < 0 ==
            (SBORROW4(*(int *)(iVar11 + 100),(uint)bVar17) != false)) {
          Curl_infof(iVar11,DAT_0005e860);
          *(undefined *)((int)param_1 + 0x1ed) = 1;
          return 0;
        }
      }
    }
    else if (param_3 != 0) goto LAB_0005e5f0;
    if (*(char *)(iVar11 + 0x309) == '\0') {
      uVar5 = *(uint *)(iVar11 + 0x50);
      uVar16 = *(uint *)(iVar11 + 0x54);
      if (uVar16 != 0xffffffff || uVar5 != 0xffffffff) {
        uVar7 = **ppuVar14;
        uVar9 = (*ppuVar14)[1];
        if (((uVar16 != uVar9 || uVar5 != uVar7) &&
            (uVar9 != *(int *)(iVar11 + 0x8684) + uVar16 + CARRY4(*(uint *)(iVar11 + 0x8680),uVar5)
             || uVar7 != *(uint *)(iVar11 + 0x8680) + uVar5)) &&
           (uVar9 != *(uint *)(iVar11 + 100) || uVar7 != *(uint *)(iVar11 + 0x60))) {
          uVar6 = 0x12;
          Curl_failf(iVar11,DAT_0005e7e8);
          goto LAB_0005e5f0;
        }
      }
      if (*(char *)(param_1 + 0x103) == '\0') {
        uVar7 = **ppuVar14;
        uVar9 = (*ppuVar14)[1];
        if (((uVar7 | uVar9) == 0) &&
           ((int)((uVar9 - uVar16) - (uint)(uVar7 < uVar5)) < 0 !=
            (SBORROW4(uVar9,uVar16) != SBORROW4(uVar9 - uVar16,(uint)(uVar7 < uVar5))))) {
          uVar6 = 0x13;
          Curl_failf(iVar11,DAT_0005e7f0);
        }
      }
    }
    else {
      uVar5 = *(uint *)(iVar11 + 0x86b0);
      uVar16 = *(uint *)(iVar11 + 0x86b4);
      if (uVar16 != 0xffffffff || uVar5 != 0xffffffff) {
        uVar7 = **ppuVar14;
        uVar9 = (*ppuVar14)[1];
        if (((uVar16 != uVar9 || uVar5 != uVar7) && (*(char *)(iVar11 + 0x24e) == '\0')) &&
           (ppuVar14[3] == (uint *)0x0)) {
          uVar6 = 0x12;
          Curl_failf(iVar11,DAT_0005e854,uVar7,uVar9,uVar5,uVar16);
        }
      }
    }
  }
LAB_0005e5f0:
  ppuVar14[3] = (uint *)0x0;
  *(undefined *)(param_1 + 0x103) = 0;
  if ((uVar6 | param_2) != 0) {
    return uVar6;
  }
  if ((param_3 == 0) && (ppcVar13 = *(char ***)(iVar11 + 0x254), ppcVar13 != (char **)0x0)) {
    do {
      pcVar3 = *ppcVar13;
      if (pcVar3 != (char *)0x0) {
        cVar1 = *pcVar3;
        if (cVar1 == '*') {
          pcVar3 = pcVar3 + 1;
        }
        uVar6 = Curl_pp_sendf(piVar12,DAT_0005e7e0,pcVar3);
        if (uVar6 != 0) {
          return uVar6;
        }
        curlx_tvnow(&local_40);
        param_1[0xf8] = local_40;
        param_1[0xf9] = iStack_3c;
        uVar6 = Curl_GetFTPResponse(auStack_30,param_1,local_2c);
        if (uVar6 != 0) {
          return uVar6;
        }
        if ((cVar1 != '*') && (399 < local_2c[0])) {
          Curl_failf(*param_1,DAT_0005e85c,pcVar3);
          return 0x15;
        }
      }
      ppcVar13 = (char **)ppcVar13[1];
    } while (ppcVar13 != (char **)0x0);
  }
  return 0;
}

