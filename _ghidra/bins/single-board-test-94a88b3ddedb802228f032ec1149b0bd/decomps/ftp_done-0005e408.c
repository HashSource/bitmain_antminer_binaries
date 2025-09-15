
int ftp_done(int *param_1,int param_2,int param_3)

{
  char cVar1;
  code *pcVar2;
  char *pcVar3;
  char *__s;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int iVar17;
  int local_40;
  int iStack_3c;
  int local_38;
  int local_34;
  undefined1 auStack_30 [4];
  int local_2c [2];
  
  iVar13 = *param_1;
  piVar14 = param_1 + 0xf0;
  puVar15 = *(undefined4 **)(iVar13 + 0x14c);
  uVar16 = *(undefined4 *)(iVar13 + 0x868c);
  if (puVar15 == (undefined4 *)0x0) {
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
    iVar12 = 0;
    break;
  default:
switchD_0005e438_caseD_1:
    *(undefined1 *)((int)param_1 + 0x40f) = 1;
    *(undefined1 *)((int)param_1 + 0x40d) = 0;
    *(undefined1 *)((int)param_1 + 0x1ed) = 1;
    iVar12 = param_2;
  }
  (*Curl_cfree)(param_1[0x105]);
  if (*(char *)(iVar13 + 0x414) != '\0') {
    if ((*(code **)(iVar13 + 0x41c) != (code *)0x0) && (param_1[0x102] != 0)) {
      (**(code **)(iVar13 + 0x41c))(*(undefined4 *)(iVar13 + 0x86f0));
    }
    param_1[0x110] = -1;
    param_1[0x111] = -1;
  }
  pcVar3 = (char *)curl_easy_unescape(iVar13,uVar16,0,0);
  if (pcVar3 == (char *)0x0) {
    *(undefined1 *)((int)param_1 + 0x40d) = 0;
    param_1[0x105] = 0;
    *(undefined1 *)((int)param_1 + 0x1ed) = 1;
    if (iVar12 == 0) {
      iVar12 = 0x1b;
    }
    freedirs(piVar14);
    if (param_1[0x56] == -1) goto LAB_0005e5f0;
LAB_0005e58e:
    if ((char)param_1[100] != '\0') {
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
    pcVar2 = Curl_cfree;
    if (*(char *)((int)param_1 + 0x40f) == '\0') {
      if ((sVar4 - (int)__s == 0) || (*(int *)(iVar13 + 0x2e8) == 2)) {
        iVar5 = (*Curl_cstrdup)(&DAT_0013a6fc);
        pcVar2 = Curl_cfree;
        param_1[0x105] = iVar5;
        (*pcVar2)(pcVar3);
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
      Curl_infof(iVar13,"Remembering we are in dir \"%s\"\n",pcVar3);
    }
    else {
      param_1[0x105] = 0;
      (*pcVar2)(pcVar3);
    }
LAB_0005e55a:
    freedirs(piVar14);
    if (param_1[0x56] != -1) {
      if ((((iVar12 == 0) && ((char)param_1[0x103] != '\0')) &&
          ((int)(uint)(*(int *)(iVar13 + 0x60) == 0) <= *(int *)(iVar13 + 100))) &&
         (iVar5 = Curl_pp_sendf(piVar14,"%s",&DAT_0013cf1c), iVar5 != 0)) {
        uVar16 = curl_easy_strerror();
        Curl_failf(iVar13,"Failure sending ABOR command: %s",uVar16);
        *(undefined1 *)((int)param_1 + 0x40d) = 0;
        *(undefined1 *)((int)param_1 + 0x1ed) = 1;
        iVar12 = iVar5;
      }
      goto LAB_0005e58e;
    }
  }
  if (iVar12 == 0) {
    if (((puVar15[3] == 0) && (*(char *)((int)param_1 + 0x40d) != '\0')) &&
       ((char)param_1[0xf4] != '\0')) {
      if (param_3 != 0) goto LAB_0005e5f0;
      iVar17 = param_1[0xfa];
      param_1[0xfa] = 60000;
      curlx_tvnow(&local_40);
      param_1[0xf8] = local_40;
      param_1[0xf9] = iStack_3c;
      iVar5 = Curl_GetFTPResponse(&local_38,param_1,&local_34);
      param_1[0xfa] = iVar17;
      if ((local_38 == 0) && (iVar5 == 0x1c)) {
        Curl_failf(iVar13,"control connection looks dead");
        *(undefined1 *)((int)param_1 + 0x40d) = 0;
        *(undefined1 *)((int)param_1 + 0x1ed) = 1;
        return 0x1c;
      }
      if (iVar5 != 0) {
        return iVar5;
      }
      if ((char)param_1[0x103] == '\0') {
        if (local_34 != 0xfa && local_34 != 0xe2) {
          iVar12 = 0x12;
          Curl_failf(iVar13,"server did not report OK, got %d");
          goto LAB_0005e5f0;
        }
      }
      else if ((int)(uint)(*(int *)(iVar13 + 0x60) == 0) <= *(int *)(iVar13 + 100)) {
        Curl_infof(iVar13,"partial download completed, closing connection\n");
        *(undefined1 *)((int)param_1 + 0x1ed) = 1;
        return 0;
      }
    }
    else if (param_3 != 0) goto LAB_0005e5f0;
    if (*(char *)(iVar13 + 0x309) == '\0') {
      uVar6 = *(uint *)(iVar13 + 0x50);
      uVar7 = *(uint *)(iVar13 + 0x54);
      if (uVar7 != 0xffffffff || uVar6 != 0xffffffff) {
        uVar9 = *(uint *)*puVar15;
        uVar11 = ((uint *)*puVar15)[1];
        if (((uVar7 != uVar11 || uVar6 != uVar9) &&
            (uVar11 != *(int *)(iVar13 + 0x8684) + uVar7 + CARRY4(*(uint *)(iVar13 + 0x8680),uVar6)
             || uVar9 != *(uint *)(iVar13 + 0x8680) + uVar6)) &&
           (uVar11 != *(uint *)(iVar13 + 100) || uVar9 != *(uint *)(iVar13 + 0x60))) {
          iVar12 = 0x12;
          Curl_failf(iVar13,"Received only partial file: %lld bytes");
          goto LAB_0005e5f0;
        }
      }
      if ((char)param_1[0x103] == '\0') {
        uVar9 = *(uint *)*puVar15;
        uVar11 = ((uint *)*puVar15)[1];
        if ((uVar9 == 0 && uVar11 == 0) &&
           ((int)((uVar11 - uVar7) - (uint)(uVar9 < uVar6)) < 0 !=
            (SBORROW4(uVar11,uVar7) != SBORROW4(uVar11 - uVar7,(uint)(uVar9 < uVar6))))) {
          iVar12 = 0x13;
          Curl_failf(iVar13,"No data was received!");
        }
      }
    }
    else {
      iVar5 = *(int *)(iVar13 + 0x86b0);
      iVar17 = *(int *)(iVar13 + 0x86b4);
      if (iVar17 != -1 || iVar5 != -1) {
        iVar8 = *(int *)*puVar15;
        iVar10 = ((int *)*puVar15)[1];
        if (((iVar17 != iVar10 || iVar5 != iVar8) && (*(char *)(iVar13 + 0x24e) == '\0')) &&
           (puVar15[3] == 0)) {
          iVar12 = 0x12;
          Curl_failf(iVar13,"Uploaded unaligned file size (%lld out of %lld bytes)",iVar8,iVar10,
                     iVar5,iVar17);
        }
      }
    }
  }
LAB_0005e5f0:
  puVar15[3] = 0;
  *(undefined1 *)(param_1 + 0x103) = 0;
  if (iVar12 != 0 || param_2 != 0) {
    return iVar12;
  }
  if ((param_3 == 0) && (puVar15 = *(undefined4 **)(iVar13 + 0x254), puVar15 != (undefined4 *)0x0))
  {
    do {
      pcVar3 = (char *)*puVar15;
      if (pcVar3 != (char *)0x0) {
        cVar1 = *pcVar3;
        if (cVar1 == '*') {
          pcVar3 = pcVar3 + 1;
        }
        iVar13 = Curl_pp_sendf(piVar14,"%s",pcVar3);
        if (iVar13 != 0) {
          return iVar13;
        }
        curlx_tvnow(&local_40);
        param_1[0xf8] = local_40;
        param_1[0xf9] = iStack_3c;
        iVar13 = Curl_GetFTPResponse(auStack_30,param_1,local_2c);
        if (iVar13 != 0) {
          return iVar13;
        }
        if ((cVar1 != '*') && (399 < local_2c[0])) {
          Curl_failf(*param_1,"QUOT string not accepted: %s",pcVar3);
          return 0x15;
        }
      }
      puVar15 = (undefined4 *)puVar15[1];
    } while (puVar15 != (undefined4 *)0x0);
  }
  return 0;
}

