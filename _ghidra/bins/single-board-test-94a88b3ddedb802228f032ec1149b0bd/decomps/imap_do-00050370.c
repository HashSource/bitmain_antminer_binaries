
int imap_do(int *param_1,char *param_2)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  char cVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined4 local_34;
  int local_30;
  int local_2c [2];
  
  iVar8 = *param_1;
  *param_2 = '\0';
  iVar7 = *(int *)(iVar8 + 0x14c);
  pcVar10 = *(char **)(iVar8 + 0x868c);
  pcVar11 = pcVar10;
  do {
    pcVar9 = pcVar11;
    iVar3 = imap_is_bchar(*pcVar9);
    pcVar11 = pcVar9 + 1;
  } while (iVar3 != 0);
  if (pcVar10 == pcVar9) {
    *(undefined4 *)(iVar7 + 4) = 0;
  }
  else {
    pcVar11 = pcVar9;
    if ((pcVar10 < pcVar9) && (pcVar9[-1] == '/')) {
      pcVar11 = pcVar9 + -1;
    }
    iVar3 = Curl_urldecode(iVar8,pcVar10,(int)pcVar11 - (int)pcVar10,iVar7 + 4,0,1);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  cVar4 = *pcVar9;
  while (cVar4 == ';') {
    cVar4 = pcVar9[1];
    pcVar10 = pcVar9 + 1;
    pcVar11 = pcVar10;
    if (cVar4 != '=' && cVar4 != '\0') {
      pcVar9 = pcVar9 + 2;
      do {
        cVar4 = *pcVar9;
        pcVar11 = pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar4 != '=' && cVar4 != '\0');
    }
    if (cVar4 == '\0') {
      return 3;
    }
    iVar3 = Curl_urldecode(iVar8,pcVar10,(int)pcVar11 - (int)pcVar10,&local_34,0,1);
    if (iVar3 != 0) {
      return iVar3;
    }
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar11;
    do {
      pcVar9 = pcVar10;
      iVar3 = imap_is_bchar(*pcVar9);
      pcVar10 = pcVar9 + 1;
    } while (iVar3 != 0);
    iVar3 = Curl_urldecode(iVar8,pcVar11,(int)pcVar9 - (int)pcVar11,&local_30,local_2c,1);
    if (iVar3 != 0) {
      (*Curl_cfree)(local_34);
      return iVar3;
    }
    iVar3 = Curl_raw_equal(local_34,"UIDVALIDITY");
    if ((iVar3 == 0) || (*(int *)(iVar7 + 8) != 0)) {
      iVar3 = Curl_raw_equal(local_34,&DAT_001393e4);
      if ((iVar3 == 0) || (*(int *)(iVar7 + 0xc) != 0)) {
        iVar3 = Curl_raw_equal(local_34,"SECTION");
        if ((iVar3 == 0) || (*(int *)(iVar7 + 0x10) != 0)) {
          iVar3 = Curl_raw_equal(local_34,"PARTIAL");
          if ((iVar3 == 0) || (*(int *)(iVar7 + 0x14) != 0)) {
            (*Curl_cfree)(local_34);
            (*Curl_cfree)(local_30);
            return 3;
          }
          if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
            *(undefined1 *)(local_30 + local_2c[0] + -1) = 0;
          }
          *(int *)(iVar7 + 0x14) = local_30;
        }
        else {
          if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
            *(undefined1 *)(local_30 + local_2c[0] + -1) = 0;
          }
          *(int *)(iVar7 + 0x10) = local_30;
        }
      }
      else {
        if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
          *(undefined1 *)(local_30 + local_2c[0] + -1) = 0;
        }
        *(int *)(iVar7 + 0xc) = local_30;
      }
    }
    else {
      if ((local_2c[0] != 0) && (*(char *)(local_30 + local_2c[0] + -1) == '/')) {
        *(undefined1 *)(local_30 + local_2c[0] + -1) = 0;
      }
      *(int *)(iVar7 + 8) = local_30;
    }
    local_30 = 0;
    (*Curl_cfree)(local_34);
    (*Curl_cfree)(local_30);
    cVar4 = *pcVar9;
  }
  if (((*(int *)(iVar7 + 4) != 0) && (*(int *)(iVar7 + 0xc) == 0)) && (cVar4 == '?')) {
    pcVar10 = pcVar9 + 1;
    pcVar11 = pcVar10;
    do {
      pcVar9 = pcVar11;
      iVar3 = imap_is_bchar(*pcVar9);
      pcVar11 = pcVar9 + 1;
    } while (iVar3 != 0);
    iVar7 = Curl_urldecode(iVar8,pcVar10,(int)pcVar9 - (int)pcVar10,iVar7 + 0x18,0,1);
    if (iVar7 != 0) {
      return iVar7;
    }
  }
  if (*pcVar9 != '\0') {
    return 3;
  }
  iVar3 = *param_1;
  iVar7 = *(int *)(iVar3 + 0x350);
  iVar8 = *(int *)(iVar3 + 0x14c);
  if (iVar7 != 0) {
    uVar12 = Curl_urldecode(iVar3,iVar7,0,iVar8 + 0x1c,0,1);
    iVar7 = (int)((ulonglong)uVar12 >> 0x20);
    if ((int)uVar12 != 0) {
      return (int)uVar12;
    }
    pbVar5 = *(byte **)(iVar8 + 0x1c);
    bVar1 = *pbVar5;
    while ((bVar1 & 0xdf) != 0) {
      pbVar5 = pbVar5 + 1;
      bVar1 = *pbVar5;
    }
    if (bVar1 == 0) {
LAB_000505c6:
      iVar3 = *param_1;
      goto LAB_000505ca;
    }
    uVar12 = (*Curl_cstrdup)(pbVar5);
    iVar7 = (int)((ulonglong)uVar12 >> 0x20);
    *(int *)(iVar8 + 0x20) = (int)uVar12;
    *pbVar5 = 0;
    if (*(int *)(iVar8 + 0x20) != 0) goto LAB_000505c6;
    goto LAB_000506f0;
  }
LAB_000505ca:
  *(undefined4 *)(iVar3 + 0x50) = 0xffffffff;
  *(undefined4 *)(iVar3 + 0x54) = 0xffffffff;
  Curl_pgrsSetUploadCounter(iVar3,iVar7,0,0);
  Curl_pgrsSetDownloadCounter(iVar3,extraout_r1,0,0);
  Curl_pgrsSetUploadSize(iVar3,extraout_r1_00,0xffffffff,0xffffffff);
  Curl_pgrsSetDownloadSize(iVar3,extraout_r1_01,0xffffffff,0xffffffff);
  iVar7 = *param_1;
  puVar6 = *(undefined4 **)(iVar7 + 0x14c);
  if (*(char *)(iVar7 + 0x307) != '\0') {
    *puVar6 = 1;
  }
  pcVar11 = (char *)puVar6[1];
  *param_2 = '\0';
  if (pcVar11 == (char *)0x0) {
    if (*(char *)(iVar7 + 0x309) != '\0') {
      Curl_failf(iVar7,"Cannot APPEND without a mailbox.");
      return 3;
    }
LAB_00050700:
    iVar7 = imap_perform_list(param_1);
joined_r0x000507fa:
    if (iVar7 != 0) {
      return iVar7;
    }
LAB_000506a4:
    iVar7 = imap_multi_statemach(param_1,param_2);
    if (((iVar7 == 0) && (*param_2 != '\0')) && (**(int **)(*param_1 + 0x14c) != 0)) {
      imap_dophase_done_isra_4_part_5(param_1);
    }
  }
  else {
    pcVar9 = (char *)param_1[0x10a];
    pcVar10 = pcVar9;
    if (pcVar9 != (char *)0x0) {
      iVar8 = strcmp(pcVar11,pcVar9);
      pcVar10 = (char *)0x0;
      if (iVar8 == 0) {
        if (((char *)puVar6[2] != (char *)0x0) && ((char *)param_1[0x10b] != (char *)0x0)) {
          iVar8 = strcmp((char *)puVar6[2],(char *)param_1[0x10b]);
          pcVar10 = (char *)0x0;
          if (iVar8 != 0) goto LAB_0005063e;
        }
        pcVar10 = (char *)0x1;
      }
    }
LAB_0005063e:
    if (*(char *)(iVar7 + 0x309) == '\0') {
      if (puVar6[7] == 0) {
        if (pcVar10 != (char *)0x0) {
          if (puVar6[3] == 0) {
            if (puVar6[6] == 0) goto LAB_00050700;
            iVar7 = imap_perform_search(param_1);
          }
          else {
            iVar7 = imap_perform_fetch(param_1);
          }
          goto joined_r0x000507fa;
        }
        if ((puVar6[3] == 0) && (puVar6[6] == 0)) goto LAB_00050700;
      }
      else if (pcVar10 != (char *)0x0) goto LAB_00050700;
      (*Curl_cfree)(pcVar9);
      pcVar2 = Curl_cfree;
      param_1[0x10a] = 0;
      (*pcVar2)(param_1[0x10b]);
      iVar7 = puVar6[1];
      param_1[0x10b] = 0;
      if (iVar7 == 0) {
        Curl_failf(*param_1,"Cannot SELECT without a mailbox.");
        return 3;
      }
      iVar7 = imap_atom(iVar7,0);
      if (iVar7 != 0) {
        iVar8 = imap_sendf(param_1,"SELECT %s",iVar7);
        (*Curl_cfree)(iVar7);
        if (iVar8 != 0) {
          return iVar8;
        }
        param_1[0xfe] = 8;
        goto LAB_000506a4;
      }
    }
    else {
      if (*(int *)(iVar7 + 0x86b4) < 0) {
        Curl_failf(iVar7,"Cannot APPEND with unknown input file size\n");
        return 0x19;
      }
      iVar7 = imap_atom(pcVar11,0);
      if (iVar7 != 0) {
        iVar8 = *param_1;
        iVar8 = imap_sendf(param_1,"APPEND %s (\\Seen) {%lld}",iVar7,iVar8 + 0x8600,
                           *(undefined4 *)(iVar8 + 0x86b0),*(undefined4 *)(iVar8 + 0x86b4));
        (*Curl_cfree)(iVar7);
        if (iVar8 != 0) {
          return iVar8;
        }
        param_1[0xfe] = 0xb;
        goto LAB_000506a4;
      }
    }
LAB_000506f0:
    iVar7 = 0x1b;
  }
  return iVar7;
}

