
int ftp_do(int *param_1,char *param_2)

{
  char cVar1;
  undefined uVar2;
  code **ppcVar3;
  code **ppcVar4;
  char *pcVar5;
  int *piVar6;
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
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  char *__s;
  undefined4 *puVar13;
  int iVar14;
  undefined4 *puVar15;
  bool bVar16;
  undefined8 uVar17;
  longlong lVar18;
  
  iVar11 = *param_1;
  *param_2 = '\0';
  cVar1 = *(char *)(iVar11 + 0x414);
  *(undefined *)(param_1 + 0x104) = 0;
  ppcVar3 = DAT_0005e390;
  pcVar5 = param_2;
  if (cVar1 != '\0') {
    do {
      iVar14 = iVar11 + 0x8600;
      uVar8 = *(uint *)(iVar11 + 0x86d8);
      puVar15 = (undefined4 *)(iVar11 + 0x86d8);
      iVar12 = iVar11;
      switch(uVar8) {
      case 0:
        goto switchD_0005dfe6_caseD_0;
      case 1:
        puVar13 = *(undefined4 **)(iVar11 + 0x86e8);
        uVar9 = *puVar13;
        uVar7 = puVar13[2];
        *(undefined4 *)(iVar11 + 0x1a8) = puVar13[1];
        *(undefined4 *)(iVar11 + 0x160) = uVar7;
        puVar13[1] = 0;
        puVar13[2] = 0;
        *(undefined4 *)(iVar11 + 0x86d8) = 2;
        uVar17 = Curl_ftp_parselist_geterror(uVar9);
        pcVar5 = (char *)((ulonglong)uVar17 >> 0x20);
        if ((int)uVar17 == 0) {
          if (*(int *)(*(int *)(iVar11 + 0x86e4) + 0xc) == 0) {
            iVar12 = 0x4e;
            *puVar15 = 3;
            goto LAB_0005e2f0;
          }
        }
        else {
          *puVar15 = 3;
        }
        break;
      case 2:
        puVar13 = *(undefined4 **)**(undefined4 **)(iVar11 + 0x86e4);
        iVar12 = curl_maprintf(DAT_0005e384,*(undefined4 *)(iVar11 + 0x86dc),*puVar13);
        if (iVar12 == 0) {
          iVar12 = 0x1b;
          goto LAB_0005e2f0;
        }
        (**ppcVar3)(*(undefined4 *)(*param_1 + 0x8688));
        uVar9 = DAT_0005e388;
        iVar14 = *param_1;
        uVar7 = *puVar13;
        *(int *)(iVar14 + 0x8688) = iVar12;
        *(int *)(iVar14 + 0x868c) = iVar12;
        Curl_infof(iVar14,uVar9,uVar7);
        pcVar5 = extraout_r1_04;
        if (*(code **)(*param_1 + 0x418) != (code *)0x0) {
          uVar17 = (**(code **)(*param_1 + 0x418))
                             (puVar13,*(undefined4 *)(iVar11 + 0x86f0),
                              *(undefined4 *)(*(int *)(iVar11 + 0x86e4) + 0xc));
          pcVar5 = (char *)((ulonglong)uVar17 >> 0x20);
          if ((int)uVar17 == 1) {
            iVar12 = 0x58;
            goto LAB_0005e2f0;
          }
          if ((int)uVar17 == 2) {
            Curl_infof(*param_1,DAT_0005e394,*puVar13);
            *puVar15 = 4;
            pcVar5 = extraout_r1_06;
            break;
          }
        }
        if (puVar13[1] == 0) {
          if ((int)(puVar13[0xe] << 0x19) < 0) {
            iVar12 = puVar13[7];
            param_1[0x110] = puVar13[6];
            param_1[0x111] = iVar12;
          }
          iVar12 = ftp_parse_url_path(param_1);
          if (iVar12 != 0) goto LAB_0005e2f0;
          Curl_llist_remove(*(undefined4 **)(iVar11 + 0x86e4),**(undefined4 **)(iVar11 + 0x86e4),0);
          iVar12 = *param_1;
          pcVar5 = extraout_r1_10;
          if (*(int *)(*(int *)(iVar11 + 0x86e4) + 0xc) == 0) {
            *(undefined4 *)(iVar11 + 0x86d8) = 3;
          }
          goto LAB_0005e15c;
        }
        *(undefined4 *)(iVar11 + 0x86d8) = 4;
        break;
      case 3:
        puVar15 = *(undefined4 **)(iVar11 + 0x86e8);
        lVar18 = CONCAT44(pcVar5,puVar15);
        uVar9 = 6;
        if (puVar15 != (undefined4 *)0x0) {
          lVar18 = Curl_ftp_parselist_geterror(*puVar15);
          iVar12 = *param_1;
          uVar9 = 6;
          iVar14 = iVar12 + 0x8600;
          if ((int)lVar18 != 0) {
            uVar9 = 5;
            iVar14 = iVar12 + 0x8600;
          }
        }
        *(undefined4 *)(iVar11 + 0x86d8) = uVar9;
        goto LAB_0005e23c;
      case 4:
        if (*(code **)(iVar11 + 0x41c) != (code *)0x0) {
          (**(code **)(iVar11 + 0x41c))(*(undefined4 *)(iVar11 + 0x86f0));
        }
        Curl_llist_remove(*(undefined4 **)(iVar11 + 0x86e4),**(undefined4 **)(iVar11 + 0x86e4),0);
        if (*(int *)(*(int *)(iVar11 + 0x86e4) + 0xc) == 0) {
          uVar9 = 3;
        }
        else {
          uVar9 = 2;
        }
        *(undefined4 *)(iVar11 + 0x86d8) = uVar9;
        pcVar5 = extraout_r1_02;
        break;
      default:
        goto switchD_0005dfe6_caseD_5;
      }
      iVar11 = *param_1;
    } while( true );
  }
  uVar17 = ftp_parse_url_path();
  pcVar5 = (char *)((ulonglong)uVar17 >> 0x20);
  if ((int)uVar17 != 0) {
    return (int)uVar17;
  }
  iVar12 = *param_1;
  goto LAB_0005e000;
switchD_0005dfe6_caseD_0:
  __s = *(char **)(iVar11 + 0x868c);
  pcVar5 = strrchr(__s,0x2f);
  ppcVar3 = DAT_0005e370;
  if (pcVar5 == (char *)0x0) {
    if (*__s != '\0') {
      uVar17 = (**DAT_0005e370)(__s);
      uVar9 = (undefined4)((ulonglong)uVar17 >> 0x20);
      *(int *)(iVar11 + 0x86e0) = (int)uVar17;
      if ((int)uVar17 != 0) {
        *__s = '\0';
        goto LAB_0005e0d0;
      }
LAB_0005e31c:
      iVar12 = 0x1b;
      goto LAB_0005e2e8;
    }
LAB_0005e29c:
    *(undefined4 *)(iVar11 + 0x86d8) = 3;
    lVar18 = ftp_parse_url_path(param_1);
    if (*(int *)(iVar11 + 0x86d8) != 3) {
      if ((int)lVar18 != 0) goto LAB_0005e2b4;
LAB_0005e2c2:
      uVar9 = 1;
      goto LAB_0005e2b6;
    }
    iVar12 = *param_1;
    iVar14 = iVar12 + 0x8600;
  }
  else {
    if (pcVar5[1] == '\0') goto LAB_0005e29c;
    uVar17 = (**DAT_0005e370)(pcVar5 + 1);
    uVar9 = (undefined4)((ulonglong)uVar17 >> 0x20);
    *(int *)(iVar11 + 0x86e0) = (int)uVar17;
    if ((int)uVar17 == 0) goto LAB_0005e31c;
    pcVar5[1] = '\0';
LAB_0005e0d0:
    piVar6 = (int *)(**DAT_0005e374)(1,0xc);
    if (piVar6 != (int *)0x0) {
      iVar12 = Curl_ftp_parselist_data_alloc();
      *piVar6 = iVar12;
      ppcVar4 = DAT_0005e390;
      uVar9 = DAT_0005e378;
      if (iVar12 == 0) {
        iVar12 = 0x1b;
        (**DAT_0005e390)(*(undefined4 *)(iVar11 + 0x86e0));
        pcVar10 = *ppcVar4;
        *(undefined4 *)(iVar11 + 0x86e0) = 0;
        (*pcVar10)(piVar6);
        uVar9 = extraout_r1_05;
        goto LAB_0005e2e8;
      }
      iVar14 = *param_1;
      *(int **)(iVar11 + 0x86e8) = piVar6;
      iVar12 = *(int *)(iVar14 + 0x2e8);
      *(undefined4 *)(iVar11 + 0x86ec) = uVar9;
      bVar16 = iVar12 == 2;
      if (bVar16) {
        iVar12 = 1;
      }
      if (bVar16) {
        *(int *)(iVar14 + 0x2e8) = iVar12;
      }
      iVar12 = ftp_parse_url_path(param_1);
      if (iVar12 != 0) {
        (**DAT_0005e390)(*(undefined4 *)(iVar11 + 0x86e0));
        *(undefined4 *)(iVar11 + 0x86e0) = 0;
        (**(code **)(iVar11 + 0x86ec))(*(undefined4 *)(iVar11 + 0x86e8));
        *(undefined4 *)(iVar11 + 0x86ec) = 0;
        *(undefined4 *)(iVar11 + 0x86e8) = 0;
        uVar9 = extraout_r1_08;
        goto LAB_0005e2e8;
      }
      iVar12 = (**ppcVar3)(*(undefined4 *)(*param_1 + 0x868c));
      *(int *)(iVar11 + 0x86dc) = iVar12;
      uVar7 = DAT_0005e380;
      uVar9 = DAT_0005e37c;
      if (iVar12 == 0) {
        (**DAT_0005e404)(*(undefined4 *)(iVar11 + 0x86e0));
        *(undefined4 *)(iVar11 + 0x86e0) = 0;
        (**(code **)(iVar11 + 0x86ec))(*(undefined4 *)(iVar11 + 0x86e8));
        *(undefined4 *)(iVar11 + 0x86ec) = 0;
        *(undefined4 *)(iVar11 + 0x86e8) = 0;
        iVar12 = 0x1b;
        uVar9 = extraout_r1_09;
        goto LAB_0005e2e8;
      }
      iVar12 = *param_1;
      piVar6[1] = *(int *)(iVar12 + 0x1a8);
      *(undefined4 *)(iVar12 + 0x1a8) = uVar9;
      piVar6[2] = *(int *)(iVar12 + 0x160);
      *(int **)(iVar12 + 0x160) = param_1;
      Curl_infof(iVar12,uVar7);
      lVar18 = ZEXT48(extraout_r1_03) << 0x20;
      if (*(int *)(iVar11 + 0x86d8) == 3) {
        iVar12 = *param_1;
        pcVar5 = extraout_r1_03;
LAB_0005e15c:
        uVar8 = *(uint *)(iVar12 + 0x86d8);
switchD_0005dfe6_caseD_5:
        if ((uVar8 & 0xfffffffd) == 4) {
          return 0;
        }
        goto LAB_0005e000;
      }
      goto LAB_0005e2c2;
    }
    iVar12 = 0x1b;
    (**DAT_0005e390)(*(undefined4 *)(iVar11 + 0x86e0));
    *(undefined4 *)(iVar11 + 0x86e0) = 0;
    uVar9 = extraout_r1_07;
LAB_0005e2e8:
    lVar18 = CONCAT44(uVar9,iVar12);
    if (*(int *)(iVar11 + 0x86d8) == 3) {
LAB_0005e2f0:
      if ((*(uint *)(*param_1 + 0x86d8) & 0xfffffffd) == 4) {
        return 0;
      }
      return iVar12;
    }
LAB_0005e2b4:
    uVar9 = 5;
LAB_0005e2b6:
    iVar12 = *param_1;
    *(undefined4 *)(iVar11 + 0x86d8) = uVar9;
    iVar14 = iVar12 + 0x8600;
  }
LAB_0005e23c:
  pcVar5 = (char *)((ulonglong)lVar18 >> 0x20);
  if ((*(uint *)(iVar14 + 0xd8) & 0xfffffffd) == 4) {
    return 0;
  }
  if ((int)lVar18 != 0) {
    return (int)lVar18;
  }
LAB_0005e000:
  *(undefined4 *)(iVar12 + 0x50) = 0xffffffff;
  *(undefined4 *)(iVar12 + 0x54) = 0xffffffff;
  Curl_pgrsSetUploadCounter(iVar12,pcVar5,0,0);
  Curl_pgrsSetDownloadCounter(iVar12,extraout_r1,0,0);
  Curl_pgrsSetUploadSize(iVar12,extraout_r1_00,0xffffffff,0xffffffff);
  Curl_pgrsSetDownloadSize(iVar12,extraout_r1_01,0xffffffff,0xffffffff);
  *(undefined *)((int)param_1 + 0x40d) = 1;
  if (*(char *)(*param_1 + 0x307) != '\0') {
    *(undefined4 *)(*(int *)(*param_1 + 0x14c) + 0xc) = 1;
  }
  *param_2 = '\0';
  iVar11 = ftp_state_quote(param_1,1,0xc);
  if (iVar11 == 0) {
    iVar11 = ftp_multi_statemach(param_1,param_2);
    uVar2 = *(undefined *)((int)param_1 + 0x1f7);
    Curl_infof(*param_1,DAT_0005e38c,uVar2);
    if (iVar11 == 0) {
      if (*param_2 != '\0') {
        iVar11 = ftp_dophase_done(param_1,uVar2);
        return iVar11;
      }
      return 0;
    }
  }
  freedirs(param_1 + 0xf0);
  return iVar11;
}

