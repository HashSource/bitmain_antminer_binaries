
undefined4 ftp_parse_url_path(int *param_1)

{
  code *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  int local_38;
  int local_2c [2];
  
  piVar6 = param_1 + 0xf0;
  iVar9 = *param_1;
  iVar8 = *(int *)(iVar9 + 0x2e8);
  iVar7 = *(int *)(iVar9 + 0x14c);
  pcVar11 = *(char **)(iVar9 + 0x868c);
  *(undefined1 *)((int)param_1 + 0x40d) = 0;
  *(undefined1 *)((int)param_1 + 0x40f) = 0;
  local_38 = iVar9;
  if (iVar8 == 2) {
    if ((*pcVar11 != '\0') && (sVar5 = strlen(pcVar11), pcVar11[sVar5 - 1] != '/'))
    goto LAB_0005c1a8;
LAB_0005c126:
    param_1[0x102] = 0;
  }
  else {
    if (iVar8 == 3) {
      if (*pcVar11 == '\0') {
        param_1[0x100] = 0;
        goto LAB_0005c126;
      }
      pcVar2 = strrchr(pcVar11,0x2f);
      if (pcVar2 == (char *)0x0) goto LAB_0005c1a8;
      puVar10 = (undefined4 *)(*Curl_ccalloc)(1,4);
      param_1[0xff] = (int)puVar10;
      if (puVar10 == (undefined4 *)0x0) {
        return 0x1b;
      }
      iVar12 = *param_1;
      iVar8 = (int)pcVar2 - (int)pcVar11;
      if (iVar8 == 0) {
        iVar8 = 1;
      }
      uVar3 = curlx_uztosi(iVar8);
      uVar3 = curl_easy_unescape(iVar12,pcVar11,uVar3,0);
      *puVar10 = uVar3;
      if (*(int *)param_1[0xff] == 0) goto LAB_0005c0ac;
      pcVar11 = pcVar2 + 1;
      param_1[0x100] = 1;
    }
    else {
      param_1[0x100] = 0;
      param_1[0x101] = 5;
      iVar8 = (*Curl_ccalloc)(5,4);
      param_1[0xff] = iVar8;
      if (iVar8 == 0) {
        return 0x1b;
      }
      iVar8 = curl_strequal(pcVar11,&DAT_00135588);
      if (iVar8 == 0) {
        do {
          do {
            while( true ) {
              pcVar2 = strchr(pcVar11,0x2f);
              if (pcVar2 == (char *)0x0) goto LAB_0005c11c;
              if ((int)pcVar11 - *(int *)(iVar9 + 0x868c) < 1) {
                iVar8 = 0;
              }
              else {
                iVar8 = 1 - param_1[0x100];
                if (1 < (uint)param_1[0x100]) {
                  iVar8 = 0;
                }
              }
              if (pcVar11 == pcVar2) break;
              uVar3 = curlx_sztosi(pcVar2 + (iVar8 - (int)pcVar11));
              iVar12 = param_1[0xff];
              iVar13 = param_1[0x100];
              uVar3 = curl_easy_unescape(*param_1,(int)pcVar11 - iVar8,uVar3,0);
              iVar8 = param_1[0x100];
              *(undefined4 *)(iVar12 + iVar13 * 4) = uVar3;
              iVar13 = param_1[0xff];
              iVar12 = *(int *)(iVar13 + iVar8 * 4);
              if (iVar12 == 0) goto LAB_0005c20c;
              iVar4 = isBadFtpString(iVar12);
              if (iVar4 != 0) {
                (*Curl_cfree)(iVar12);
                freedirs(piVar6);
                return 3;
              }
              iVar12 = param_1[0x101];
              iVar8 = iVar8 + 1;
              param_1[0x100] = iVar8;
              pcVar1 = Curl_crealloc;
              pcVar11 = pcVar2 + 1;
              if (iVar12 <= iVar8) {
                param_1[0x101] = iVar12 << 1;
                iVar8 = (*pcVar1)(iVar13,iVar12 << 3);
                if (iVar8 == 0) goto LAB_0005c0ac;
                param_1[0xff] = iVar8;
              }
            }
            pcVar11 = pcVar11 + 1;
          } while (param_1[0x100] != 0);
          puVar10 = (undefined4 *)param_1[0xff];
          uVar3 = (*Curl_cstrdup)(&DAT_00135588);
          iVar8 = param_1[0x100];
          *puVar10 = uVar3;
          iVar12 = *(int *)(param_1[0xff] + iVar8 * 4);
          param_1[0x100] = iVar8 + 1;
        } while (iVar12 != 0);
LAB_0005c20c:
        Curl_failf(iVar9,"no memory");
        freedirs(piVar6);
        return 0x1b;
      }
      pcVar11 = pcVar11 + 1;
      puVar10 = (undefined4 *)param_1[0xff];
      uVar3 = (*Curl_cstrdup)(&DAT_00135588);
      iVar8 = param_1[0x100];
      *puVar10 = uVar3;
      param_1[0x100] = iVar8 + 1;
    }
LAB_0005c11c:
    if ((pcVar11 == (char *)0x0) || (*pcVar11 == '\0')) goto LAB_0005c126;
    local_38 = *param_1;
LAB_0005c1a8:
    iVar8 = curl_easy_unescape(local_38,pcVar11,0,0);
    param_1[0x102] = iVar8;
    if (iVar8 == 0) {
      freedirs(piVar6);
      Curl_failf(iVar9,"no memory");
      return 0x1b;
    }
    iVar8 = isBadFtpString();
    if (iVar8 != 0) {
      freedirs(piVar6);
      return 3;
    }
  }
  if (((*(char *)(iVar9 + 0x309) != '\0') && (param_1[0x102] == 0)) && (*(int *)(iVar7 + 0xc) == 0))
  {
    Curl_failf(iVar9,"Uploading to a URL without a file name!");
    return 3;
  }
  *(undefined1 *)((int)param_1 + 0x40e) = 0;
  if (param_1[0x105] == 0) {
    return 0;
  }
  iVar7 = curl_easy_unescape(*param_1,*(undefined4 *)(iVar9 + 0x868c),0,local_2c);
  if (iVar7 != 0) {
    pcVar11 = (char *)param_1[0x102];
    if (pcVar11 != (char *)0x0) {
      strlen(pcVar11);
      pcVar11 = (char *)curlx_uztosi();
    }
    local_2c[0] = local_2c[0] - (int)pcVar11;
    strlen((char *)param_1[0x105]);
    iVar8 = curlx_uztosi();
    if ((iVar8 == local_2c[0]) && (iVar8 = curl_strnequal(iVar7,param_1[0x105],iVar8), iVar8 != 0))
    {
      Curl_infof(iVar9,"Request has same path as previous transfer\n");
      *(undefined1 *)((int)param_1 + 0x40e) = 1;
    }
    (*Curl_cfree)(iVar7);
    return 0;
  }
LAB_0005c0ac:
  freedirs(piVar6);
  return 0x1b;
}

