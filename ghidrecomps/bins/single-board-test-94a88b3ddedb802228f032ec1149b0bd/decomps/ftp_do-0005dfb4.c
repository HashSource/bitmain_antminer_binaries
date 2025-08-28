
int ftp_do(int *param_1,char *param_2)

{
  char cVar1;
  undefined1 uVar2;
  code *pcVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  char *extraout_r1_02;
  char *extraout_r1_03;
  char *extraout_r1_04;
  undefined4 extraout_r1_05;
  char *extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  char *extraout_r1_10;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  char *__s;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  bool bVar14;
  undefined8 uVar15;
  longlong lVar16;
  
  iVar9 = *param_1;
  *param_2 = '\0';
  cVar1 = *(char *)(iVar9 + 0x414);
  *(undefined1 *)(param_1 + 0x104) = 0;
  pcVar4 = param_2;
  if (cVar1 != '\0') {
    do {
      iVar12 = iVar9 + 0x8600;
      uVar6 = *(uint *)(iVar9 + 0x86d8);
      puVar13 = (undefined4 *)(iVar9 + 0x86d8);
      iVar10 = iVar9;
      switch(uVar6) {
      case 0:
        goto switchD_0005dfe6_caseD_0;
      case 1:
        puVar11 = *(undefined4 **)(iVar9 + 0x86e8);
        uVar7 = *puVar11;
        uVar8 = puVar11[2];
        *(undefined4 *)(iVar9 + 0x1a8) = puVar11[1];
        *(undefined4 *)(iVar9 + 0x160) = uVar8;
        puVar11[1] = 0;
        puVar11[2] = 0;
        *(undefined4 *)(iVar9 + 0x86d8) = 2;
        uVar15 = Curl_ftp_parselist_geterror(uVar7);
        pcVar4 = (char *)((ulonglong)uVar15 >> 0x20);
        if ((int)uVar15 == 0) {
          if (*(int *)(*(int *)(iVar9 + 0x86e4) + 0xc) == 0) {
            iVar10 = 0x4e;
            *puVar13 = 3;
            goto LAB_0005e2f0;
          }
        }
        else {
          *puVar13 = 3;
        }
        break;
      case 2:
        puVar11 = *(undefined4 **)**(undefined4 **)(iVar9 + 0x86e4);
        iVar10 = curl_maprintf("%s%s",*(undefined4 *)(iVar9 + 0x86dc),*puVar11);
        if (iVar10 == 0) {
          iVar10 = 0x1b;
          goto LAB_0005e2f0;
        }
        (*Curl_cfree)(*(undefined4 *)(*param_1 + 0x8688));
        iVar12 = *param_1;
        uVar7 = *puVar11;
        *(int *)(iVar12 + 0x8688) = iVar10;
        *(int *)(iVar12 + 0x868c) = iVar10;
        Curl_infof(iVar12,"Wildcard - START of \"%s\"\n",uVar7);
        pcVar4 = extraout_r1_04;
        if (*(code **)(*param_1 + 0x418) != (code *)0x0) {
          uVar15 = (**(code **)(*param_1 + 0x418))
                             (puVar11,*(undefined4 *)(iVar9 + 0x86f0),
                              *(undefined4 *)(*(int *)(iVar9 + 0x86e4) + 0xc));
          pcVar4 = (char *)((ulonglong)uVar15 >> 0x20);
          if ((int)uVar15 == 1) {
            iVar10 = 0x58;
            goto LAB_0005e2f0;
          }
          if ((int)uVar15 == 2) {
            Curl_infof(*param_1,"Wildcard - \"%s\" skipped by user\n",*puVar11);
            *puVar13 = 4;
            pcVar4 = extraout_r1_06;
            break;
          }
        }
        if (puVar11[1] == 0) {
          if ((int)(puVar11[0xe] << 0x19) < 0) {
            iVar10 = puVar11[7];
            param_1[0x110] = puVar11[6];
            param_1[0x111] = iVar10;
          }
          iVar10 = ftp_parse_url_path(param_1);
          if (iVar10 != 0) goto LAB_0005e2f0;
          Curl_llist_remove(*(undefined4 **)(iVar9 + 0x86e4),**(undefined4 **)(iVar9 + 0x86e4),0);
          iVar10 = *param_1;
          pcVar4 = extraout_r1_10;
          if (*(int *)(*(int *)(iVar9 + 0x86e4) + 0xc) == 0) {
            *(undefined4 *)(iVar9 + 0x86d8) = 3;
          }
          goto LAB_0005e15c;
        }
        *(undefined4 *)(iVar9 + 0x86d8) = 4;
        break;
      case 3:
        puVar13 = *(undefined4 **)(iVar9 + 0x86e8);
        lVar16 = CONCAT44(pcVar4,puVar13);
        uVar7 = 6;
        if (puVar13 != (undefined4 *)0x0) {
          lVar16 = Curl_ftp_parselist_geterror(*puVar13);
          iVar10 = *param_1;
          uVar7 = 6;
          iVar12 = iVar10 + 0x8600;
          if ((int)lVar16 != 0) {
            uVar7 = 5;
            iVar12 = iVar10 + 0x8600;
          }
        }
        *(undefined4 *)(iVar9 + 0x86d8) = uVar7;
        goto LAB_0005e23c;
      case 4:
        if (*(code **)(iVar9 + 0x41c) != (code *)0x0) {
          (**(code **)(iVar9 + 0x41c))(*(undefined4 *)(iVar9 + 0x86f0));
        }
        Curl_llist_remove(*(undefined4 **)(iVar9 + 0x86e4),**(undefined4 **)(iVar9 + 0x86e4),0);
        if (*(int *)(*(int *)(iVar9 + 0x86e4) + 0xc) == 0) {
          uVar7 = 3;
        }
        else {
          uVar7 = 2;
        }
        *(undefined4 *)(iVar9 + 0x86d8) = uVar7;
        pcVar4 = extraout_r1_02;
        break;
      default:
        goto switchD_0005dfe6_default;
      }
      iVar9 = *param_1;
    } while( true );
  }
  uVar15 = ftp_parse_url_path();
  pcVar4 = (char *)((ulonglong)uVar15 >> 0x20);
  if ((int)uVar15 != 0) {
    return (int)uVar15;
  }
  iVar10 = *param_1;
  goto LAB_0005e000;
switchD_0005dfe6_caseD_0:
  __s = *(char **)(iVar9 + 0x868c);
  pcVar4 = strrchr(__s,0x2f);
  if (pcVar4 == (char *)0x0) {
    if (*__s == '\0') goto LAB_0005e29c;
    uVar15 = (*Curl_cstrdup)(__s);
    uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
    *(int *)(iVar9 + 0x86e0) = (int)uVar15;
    if ((int)uVar15 == 0) goto LAB_0005e31c;
    *__s = '\0';
LAB_0005e0d0:
    piVar5 = (int *)(*Curl_ccalloc)(1,0xc);
    if (piVar5 == (int *)0x0) {
      iVar10 = 0x1b;
      (*Curl_cfree)(*(undefined4 *)(iVar9 + 0x86e0));
      *(undefined4 *)(iVar9 + 0x86e0) = 0;
      uVar7 = extraout_r1_07;
LAB_0005e2e8:
      lVar16 = CONCAT44(uVar7,iVar10);
      if (*(int *)(iVar9 + 0x86d8) == 3) {
LAB_0005e2f0:
        if ((*(uint *)(*param_1 + 0x86d8) & 0xfffffffd) == 4) {
          return 0;
        }
        return iVar10;
      }
      goto LAB_0005e2b4;
    }
    iVar10 = Curl_ftp_parselist_data_alloc();
    *piVar5 = iVar10;
    if (iVar10 == 0) {
      iVar10 = 0x1b;
      (*Curl_cfree)(*(undefined4 *)(iVar9 + 0x86e0));
      pcVar3 = Curl_cfree;
      *(undefined4 *)(iVar9 + 0x86e0) = 0;
      (*pcVar3)(piVar5);
      uVar7 = extraout_r1_05;
      goto LAB_0005e2e8;
    }
    iVar12 = *param_1;
    *(int **)(iVar9 + 0x86e8) = piVar5;
    iVar10 = *(int *)(iVar12 + 0x2e8);
    *(undefined4 *)(iVar9 + 0x86ec) = 0x5bf85;
    bVar14 = iVar10 == 2;
    if (bVar14) {
      iVar10 = 1;
    }
    if (bVar14) {
      *(int *)(iVar12 + 0x2e8) = iVar10;
    }
    iVar10 = ftp_parse_url_path(param_1);
    if (iVar10 != 0) {
      (*Curl_cfree)(*(undefined4 *)(iVar9 + 0x86e0));
      *(undefined4 *)(iVar9 + 0x86e0) = 0;
      (**(code **)(iVar9 + 0x86ec))(*(undefined4 *)(iVar9 + 0x86e8));
      *(undefined4 *)(iVar9 + 0x86ec) = 0;
      *(undefined4 *)(iVar9 + 0x86e8) = 0;
      uVar7 = extraout_r1_08;
      goto LAB_0005e2e8;
    }
    iVar10 = (*Curl_cstrdup)(*(undefined4 *)(*param_1 + 0x868c));
    *(int *)(iVar9 + 0x86dc) = iVar10;
    if (iVar10 == 0) {
      (*Curl_cfree)(*(undefined4 *)(iVar9 + 0x86e0));
      *(undefined4 *)(iVar9 + 0x86e0) = 0;
      (**(code **)(iVar9 + 0x86ec))(*(undefined4 *)(iVar9 + 0x86e8));
      *(undefined4 *)(iVar9 + 0x86ec) = 0;
      *(undefined4 *)(iVar9 + 0x86e8) = 0;
      iVar10 = 0x1b;
      uVar7 = extraout_r1_09;
      goto LAB_0005e2e8;
    }
    iVar10 = *param_1;
    piVar5[1] = *(int *)(iVar10 + 0x1a8);
    *(undefined4 *)(iVar10 + 0x1a8) = 0x5ea55;
    piVar5[2] = *(int *)(iVar10 + 0x160);
    *(int **)(iVar10 + 0x160) = param_1;
    Curl_infof(iVar10,"Wildcard - Parsing started\n");
    lVar16 = ZEXT48(extraout_r1_03) << 0x20;
    if (*(int *)(iVar9 + 0x86d8) == 3) {
      iVar10 = *param_1;
      pcVar4 = extraout_r1_03;
LAB_0005e15c:
      uVar6 = *(uint *)(iVar10 + 0x86d8);
switchD_0005dfe6_default:
      if ((uVar6 & 0xfffffffd) == 4) {
        return 0;
      }
      goto LAB_0005e000;
    }
LAB_0005e2c2:
    uVar7 = 1;
LAB_0005e2b6:
    iVar10 = *param_1;
    *(undefined4 *)(iVar9 + 0x86d8) = uVar7;
    iVar12 = iVar10 + 0x8600;
  }
  else {
    if (pcVar4[1] != '\0') {
      uVar15 = (*Curl_cstrdup)(pcVar4 + 1);
      uVar7 = (undefined4)((ulonglong)uVar15 >> 0x20);
      *(int *)(iVar9 + 0x86e0) = (int)uVar15;
      if ((int)uVar15 != 0) {
        pcVar4[1] = '\0';
        goto LAB_0005e0d0;
      }
LAB_0005e31c:
      iVar10 = 0x1b;
      goto LAB_0005e2e8;
    }
LAB_0005e29c:
    *(undefined4 *)(iVar9 + 0x86d8) = 3;
    lVar16 = ftp_parse_url_path(param_1);
    if (*(int *)(iVar9 + 0x86d8) != 3) {
      if ((int)lVar16 == 0) goto LAB_0005e2c2;
LAB_0005e2b4:
      uVar7 = 5;
      goto LAB_0005e2b6;
    }
    iVar10 = *param_1;
    iVar12 = iVar10 + 0x8600;
  }
LAB_0005e23c:
  pcVar4 = (char *)((ulonglong)lVar16 >> 0x20);
  if ((*(uint *)(iVar12 + 0xd8) & 0xfffffffd) == 4) {
    return 0;
  }
  if ((int)lVar16 != 0) {
    return (int)lVar16;
  }
LAB_0005e000:
  *(undefined4 *)(iVar10 + 0x50) = 0xffffffff;
  *(undefined4 *)(iVar10 + 0x54) = 0xffffffff;
  Curl_pgrsSetUploadCounter(iVar10,pcVar4,0,0);
  Curl_pgrsSetDownloadCounter(iVar10,extraout_r1,0,0);
  Curl_pgrsSetUploadSize(iVar10,extraout_r1_00,0xffffffff,0xffffffff);
  Curl_pgrsSetDownloadSize(iVar10,extraout_r1_01,0xffffffff,0xffffffff);
  *(undefined1 *)((int)param_1 + 0x40d) = 1;
  if (*(char *)(*param_1 + 0x307) != '\0') {
    *(undefined4 *)(*(int *)(*param_1 + 0x14c) + 0xc) = 1;
  }
  *param_2 = '\0';
  iVar9 = ftp_state_quote(param_1,1,0xc);
  if (iVar9 == 0) {
    iVar9 = ftp_multi_statemach(param_1,param_2);
    uVar2 = *(undefined1 *)((int)param_1 + 0x1f7);
    Curl_infof(*param_1,"ftp_perform ends with SECONDARY: %d\n",uVar2);
    if (iVar9 == 0) {
      if (*param_2 != '\0') {
        iVar9 = ftp_dophase_done(param_1,uVar2);
        return iVar9;
      }
      return 0;
    }
  }
  freedirs(param_1 + 0xf0);
  return iVar9;
}

