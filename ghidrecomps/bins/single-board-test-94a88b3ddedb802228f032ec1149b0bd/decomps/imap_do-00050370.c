
int imap_do(int *param_1,char *param_2)

{
  byte bVar1;
  code **ppcVar2;
  code **ppcVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  char cVar5;
  code *pcVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  undefined8 uVar14;
  undefined4 local_34;
  int local_30;
  int local_2c [2];
  
  iVar10 = *param_1;
  *param_2 = '\0';
  iVar9 = *(int *)(iVar10 + 0x14c);
  pcVar12 = *(char **)(iVar10 + 0x868c);
  pcVar13 = pcVar12;
  do {
    pcVar11 = pcVar13;
    iVar4 = imap_is_bchar(*pcVar11);
    pcVar13 = pcVar11 + 1;
  } while (iVar4 != 0);
  if (pcVar12 == pcVar11) {
    *(undefined4 *)(iVar9 + 4) = 0;
  }
  else {
    pcVar13 = pcVar11;
    if ((pcVar12 < pcVar11) && (pcVar11[-1] == '/')) {
      pcVar13 = pcVar11 + -1;
    }
    iVar4 = Curl_urldecode(iVar10,pcVar12,(int)pcVar13 - (int)pcVar12,iVar9 + 4,0,1);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  ppcVar2 = DAT_00050580;
  cVar5 = *pcVar11;
  while (cVar5 == ';') {
    cVar5 = pcVar11[1];
    pcVar12 = pcVar11 + 1;
    pcVar13 = pcVar12;
    if (cVar5 != '=' && cVar5 != '\0') {
      pcVar11 = pcVar11 + 2;
      do {
        cVar5 = *pcVar11;
        pcVar13 = pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar5 != '=' && cVar5 != '\0');
    }
    if (cVar5 == '\0') {
      return 3;
    }
    iVar4 = Curl_urldecode(iVar10,pcVar12,(int)pcVar13 - (int)pcVar12,&local_34,0,1);
    if (iVar4 != 0) {
      return iVar4;
    }
    pcVar13 = pcVar13 + 1;
    pcVar12 = pcVar13;
    do {
      pcVar11 = pcVar12;
      iVar4 = imap_is_bchar(*pcVar11);
      pcVar12 = pcVar11 + 1;
    } while (iVar4 != 0);
    iVar4 = Curl_urldecode(iVar10,pcVar13,(int)pcVar11 - (int)pcVar13,&local_30,local_2c,1);
    if (iVar4 != 0) {
      (**DAT_00050580)(local_34);
      return iVar4;
    }
    iVar4 = Curl_raw_equal(local_34,DAT_00050570);
    if ((iVar4 == 0) || (*(int *)(iVar9 + 8) != 0)) {
      iVar4 = Curl_raw_equal(local_34,DAT_00050574);
      if ((iVar4 == 0) || (*(int *)(iVar9 + 0xc) != 0)) {
        iVar4 = Curl_raw_equal(local_34,DAT_00050578);
        if ((iVar4 == 0) || (*(int *)(iVar9 + 0x10) != 0)) {
          iVar4 = Curl_raw_equal(local_34,DAT_0005057c);
          ppcVar3 = DAT_00050580;
          if ((iVar4 == 0) || (*(int *)(iVar9 + 0x14) != 0)) {
            (**DAT_00050580)(local_34);
            (**ppcVar3)(local_30);
            return 3;
          }
          if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
            *(undefined *)(local_30 + local_2c[0] + -1) = 0;
          }
          *(int *)(iVar9 + 0x14) = local_30;
        }
        else {
          if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
            *(undefined *)(local_30 + local_2c[0] + -1) = 0;
          }
          *(int *)(iVar9 + 0x10) = local_30;
        }
      }
      else {
        if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
          *(undefined *)(local_30 + local_2c[0] + -1) = 0;
        }
        *(int *)(iVar9 + 0xc) = local_30;
      }
    }
    else {
      if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
        *(undefined *)(local_30 + local_2c[0] + -1) = 0;
      }
      *(int *)(iVar9 + 8) = local_30;
    }
    local_30 = 0;
    (**ppcVar2)(local_34);
    (**ppcVar2)(local_30);
    cVar5 = *pcVar11;
  }
  if (((*(int *)(iVar9 + 4) != 0) && (*(int *)(iVar9 + 0xc) == 0)) && (cVar5 == '?')) {
    pcVar12 = pcVar11 + 1;
    pcVar13 = pcVar12;
    do {
      pcVar11 = pcVar13;
      iVar4 = imap_is_bchar(*pcVar11);
      pcVar13 = pcVar11 + 1;
    } while (iVar4 != 0);
    iVar9 = Curl_urldecode(iVar10,pcVar12,(int)pcVar11 - (int)pcVar12,iVar9 + 0x18,0,1);
    if (iVar9 != 0) {
      return iVar9;
    }
  }
  if (*pcVar11 != '\0') {
    return 3;
  }
  iVar4 = *param_1;
  iVar9 = *(int *)(iVar4 + 0x350);
  iVar10 = *(int *)(iVar4 + 0x14c);
  if (iVar9 != 0) {
    uVar14 = Curl_urldecode(iVar4,iVar9,0,iVar10 + 0x1c,0,1);
    iVar9 = (int)((ulonglong)uVar14 >> 0x20);
    if ((int)uVar14 != 0) {
      return (int)uVar14;
    }
    pbVar7 = *(byte **)(iVar10 + 0x1c);
    bVar1 = *pbVar7;
    while ((bVar1 & 0xdf) != 0) {
      pbVar7 = pbVar7 + 1;
      bVar1 = *pbVar7;
    }
    if (bVar1 == 0) {
LAB_000505c6:
      iVar4 = *param_1;
      goto LAB_000505ca;
    }
    uVar14 = (**DAT_00050820)(pbVar7);
    iVar9 = (int)((ulonglong)uVar14 >> 0x20);
    *(int *)(iVar10 + 0x20) = (int)uVar14;
    *pbVar7 = 0;
    if (*(int *)(iVar10 + 0x20) != 0) goto LAB_000505c6;
    goto LAB_000506f0;
  }
LAB_000505ca:
  *(undefined4 *)(iVar4 + 0x50) = 0xffffffff;
  *(undefined4 *)(iVar4 + 0x54) = 0xffffffff;
  Curl_pgrsSetUploadCounter(iVar4,iVar9,0,0);
  Curl_pgrsSetDownloadCounter(iVar4,extraout_r1,0,0);
  Curl_pgrsSetUploadSize(iVar4,extraout_r1_00,0xffffffff,0xffffffff);
  Curl_pgrsSetDownloadSize(iVar4,extraout_r1_01,0xffffffff,0xffffffff);
  iVar9 = *param_1;
  puVar8 = *(undefined4 **)(iVar9 + 0x14c);
  if (*(char *)(iVar9 + 0x307) != '\0') {
    *puVar8 = 1;
  }
  pcVar13 = (char *)puVar8[1];
  *param_2 = '\0';
  if (pcVar13 == (char *)0x0) {
    if (*(char *)(iVar9 + 0x309) != '\0') {
      Curl_failf(iVar9,DAT_00050830);
      return 3;
    }
LAB_00050700:
    iVar9 = imap_perform_list(param_1);
joined_r0x000507fa:
    if (iVar9 != 0) {
      return iVar9;
    }
LAB_000506a4:
    iVar9 = imap_multi_statemach(param_1,param_2);
    if (((iVar9 == 0) && (*param_2 != '\0')) && (**(int **)(*param_1 + 0x14c) != 0)) {
      imap_dophase_done_isra_4_part_5(param_1);
    }
  }
  else {
    pcVar11 = (char *)param_1[0x10a];
    pcVar12 = pcVar11;
    if (pcVar11 != (char *)0x0) {
      iVar10 = strcmp(pcVar13,pcVar11);
      pcVar12 = (char *)0x0;
      if (iVar10 == 0) {
        if (((char *)puVar8[2] != (char *)0x0) && ((char *)param_1[0x10b] != (char *)0x0)) {
          iVar10 = strcmp((char *)puVar8[2],(char *)param_1[0x10b]);
          pcVar12 = (char *)0x0;
          if (iVar10 != 0) goto LAB_0005063e;
        }
        pcVar12 = (char *)0x1;
      }
    }
LAB_0005063e:
    ppcVar2 = DAT_00050818;
    if (*(char *)(iVar9 + 0x309) == '\0') {
      if (puVar8[7] == 0) {
        if (pcVar12 != (char *)0x0) {
          if (puVar8[3] == 0) {
            if (puVar8[6] == 0) goto LAB_00050700;
            iVar9 = imap_perform_search(param_1);
          }
          else {
            iVar9 = imap_perform_fetch(param_1);
          }
          goto joined_r0x000507fa;
        }
        if ((puVar8[3] == 0) && (puVar8[6] == 0)) goto LAB_00050700;
      }
      else if (pcVar12 != (char *)0x0) goto LAB_00050700;
      (**DAT_00050818)(pcVar11);
      pcVar6 = *ppcVar2;
      param_1[0x10a] = 0;
      (*pcVar6)(param_1[0x10b]);
      iVar9 = puVar8[1];
      param_1[0x10b] = 0;
      if (iVar9 == 0) {
        Curl_failf(*param_1,DAT_0005082c);
        return 3;
      }
      iVar9 = imap_atom(iVar9,0);
      if (iVar9 != 0) {
        iVar10 = imap_sendf(param_1,DAT_0005081c,iVar9);
        (**ppcVar2)(iVar9);
        if (iVar10 != 0) {
          return iVar10;
        }
        param_1[0xfe] = 8;
        goto LAB_000506a4;
      }
    }
    else {
      if (*(int *)(iVar9 + 0x86b4) < 0) {
        Curl_failf(iVar9,DAT_00050828);
        return 0x19;
      }
      iVar9 = imap_atom(pcVar13,0);
      if (iVar9 != 0) {
        iVar10 = *param_1;
        iVar10 = imap_sendf(param_1,DAT_00050824,iVar9,iVar10 + 0x8600,
                            *(undefined4 *)(iVar10 + 0x86b0),*(undefined4 *)(iVar10 + 0x86b4));
        (**DAT_00050818)(iVar9);
        if (iVar10 != 0) {
          return iVar10;
        }
        param_1[0xfe] = 0xb;
        goto LAB_000506a4;
      }
    }
LAB_000506f0:
    iVar9 = 0x1b;
  }
  return iVar9;
}

