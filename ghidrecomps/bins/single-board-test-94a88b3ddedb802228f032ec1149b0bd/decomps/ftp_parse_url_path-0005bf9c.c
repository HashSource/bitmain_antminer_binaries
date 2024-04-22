
undefined4 ftp_parse_url_path(int *param_1)

{
  code **ppcVar1;
  code *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  int local_38;
  int local_2c [2];
  
  piVar7 = param_1 + 0xf0;
  iVar10 = *param_1;
  iVar9 = *(int *)(iVar10 + 0x2e8);
  iVar8 = *(int *)(iVar10 + 0x14c);
  pcVar12 = *(char **)(iVar10 + 0x868c);
  *(undefined *)((int)param_1 + 0x40d) = 0;
  *(undefined *)((int)param_1 + 0x40f) = 0;
  ppcVar1 = DAT_0005c290;
  local_38 = iVar10;
  if (iVar9 == 2) {
    if ((*pcVar12 != '\0') && (sVar6 = strlen(pcVar12), pcVar12[sVar6 - 1] != '/'))
    goto LAB_0005c1a8;
LAB_0005c126:
    param_1[0x102] = 0;
  }
  else {
    if (iVar9 == 3) {
      if (*pcVar12 == '\0') {
        param_1[0x100] = 0;
        goto LAB_0005c126;
      }
      pcVar3 = strrchr(pcVar12,0x2f);
      if (pcVar3 == (char *)0x0) goto LAB_0005c1a8;
      puVar11 = (undefined4 *)(**DAT_0005c290)(1,4);
      param_1[0xff] = (int)puVar11;
      if (puVar11 == (undefined4 *)0x0) {
        return 0x1b;
      }
      iVar13 = *param_1;
      iVar9 = (int)pcVar3 - (int)pcVar12;
      if (iVar9 == 0) {
        iVar9 = 1;
      }
      uVar4 = curlx_uztosi(iVar9);
      uVar4 = curl_easy_unescape(iVar13,pcVar12,uVar4,0);
      *puVar11 = uVar4;
      if (*(int *)param_1[0xff] == 0) goto LAB_0005c0ac;
      pcVar12 = pcVar3 + 1;
      param_1[0x100] = 1;
    }
    else {
      param_1[0x100] = 0;
      param_1[0x101] = 5;
      iVar9 = (**ppcVar1)(5,4);
      param_1[0xff] = iVar9;
      if (iVar9 == 0) {
        return 0x1b;
      }
      iVar9 = curl_strequal(pcVar12,DAT_0005c294);
      if (iVar9 == 0) {
        do {
          do {
            while( true ) {
              pcVar3 = strchr(pcVar12,0x2f);
              if (pcVar3 == (char *)0x0) goto LAB_0005c11c;
              if ((int)pcVar12 - *(int *)(iVar10 + 0x868c) < 1) {
                iVar9 = 0;
              }
              else {
                iVar9 = 1 - param_1[0x100];
                if (1 < (uint)param_1[0x100]) {
                  iVar9 = 0;
                }
              }
              if (pcVar12 == pcVar3) break;
              uVar4 = curlx_sztosi(pcVar3 + (iVar9 - (int)pcVar12));
              iVar13 = param_1[0xff];
              iVar14 = param_1[0x100];
              uVar4 = curl_easy_unescape(*param_1,(int)pcVar12 - iVar9,uVar4,0);
              iVar9 = param_1[0x100];
              *(undefined4 *)(iVar13 + iVar14 * 4) = uVar4;
              iVar14 = param_1[0xff];
              iVar13 = *(int *)(iVar14 + iVar9 * 4);
              if (iVar13 == 0) goto LAB_0005c20c;
              iVar5 = isBadFtpString(iVar13);
              if (iVar5 != 0) {
                (**DAT_0005c2c0)(iVar13);
                freedirs(piVar7);
                return 3;
              }
              iVar13 = param_1[0x101];
              iVar9 = iVar9 + 1;
              param_1[0x100] = iVar9;
              pcVar2 = Curl_crealloc;
              pcVar12 = pcVar3 + 1;
              if (iVar13 <= iVar9) {
                param_1[0x101] = iVar13 << 1;
                iVar9 = (*pcVar2)(iVar14,iVar13 << 3);
                if (iVar9 == 0) goto LAB_0005c0ac;
                param_1[0xff] = iVar9;
              }
            }
            pcVar12 = pcVar12 + 1;
          } while (param_1[0x100] != 0);
          puVar11 = (undefined4 *)param_1[0xff];
          uVar4 = (*Curl_cstrdup)(DAT_0005c294);
          iVar9 = param_1[0x100];
          *puVar11 = uVar4;
          iVar13 = *(int *)(param_1[0xff] + iVar9 * 4);
          param_1[0x100] = iVar9 + 1;
        } while (iVar13 != 0);
LAB_0005c20c:
        Curl_failf(iVar10,DAT_0005c29c);
        freedirs(piVar7);
        return 0x1b;
      }
      pcVar12 = pcVar12 + 1;
      puVar11 = (undefined4 *)param_1[0xff];
      uVar4 = (**DAT_0005c2a4)(DAT_0005c294);
      iVar9 = param_1[0x100];
      *puVar11 = uVar4;
      param_1[0x100] = iVar9 + 1;
    }
LAB_0005c11c:
    if ((pcVar12 == (char *)0x0) || (*pcVar12 == '\0')) goto LAB_0005c126;
    local_38 = *param_1;
LAB_0005c1a8:
    iVar9 = curl_easy_unescape(local_38,pcVar12,0,0);
    param_1[0x102] = iVar9;
    if (iVar9 == 0) {
      freedirs(piVar7);
      Curl_failf(iVar10,DAT_0005c29c);
      return 0x1b;
    }
    iVar9 = isBadFtpString();
    if (iVar9 != 0) {
      freedirs(piVar7);
      return 3;
    }
  }
  if (((*(char *)(iVar10 + 0x309) != '\0') && (param_1[0x102] == 0)) && (*(int *)(iVar8 + 0xc) == 0)
     ) {
    Curl_failf(iVar10,DAT_0005c2a8);
    return 3;
  }
  *(undefined *)((int)param_1 + 0x40e) = 0;
  if (param_1[0x105] == 0) {
    return 0;
  }
  iVar8 = curl_easy_unescape(*param_1,*(undefined4 *)(iVar10 + 0x868c),0,local_2c);
  if (iVar8 != 0) {
    pcVar12 = (char *)param_1[0x102];
    if (pcVar12 != (char *)0x0) {
      strlen(pcVar12);
      pcVar12 = (char *)curlx_uztosi();
    }
    local_2c[0] = local_2c[0] - (int)pcVar12;
    strlen((char *)param_1[0x105]);
    iVar9 = curlx_uztosi();
    if ((iVar9 == local_2c[0]) && (iVar9 = curl_strnequal(iVar8,param_1[0x105],iVar9), iVar9 != 0))
    {
      Curl_infof(iVar10,DAT_0005c2a0);
      *(undefined *)((int)param_1 + 0x40e) = 1;
    }
    (**DAT_0005c298)(iVar8);
    return 0;
  }
LAB_0005c0ac:
  freedirs(piVar7);
  return 0x1b;
}

