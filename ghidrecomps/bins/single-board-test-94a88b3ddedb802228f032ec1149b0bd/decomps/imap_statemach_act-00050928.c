
int imap_statemach_act(int *param_1)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  undefined4 extraout_r1;
  byte *pbVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  byte *__s1;
  int *piVar12;
  char *pcVar13;
  int iVar14;
  longlong lVar15;
  int local_68;
  uint local_58;
  int iStack_54;
  int local_50;
  undefined4 local_4c;
  uint local_48;
  int local_44;
  char *local_40;
  undefined1 auStack_3c [24];
  
  piVar12 = param_1 + 0xf0;
  iVar14 = param_1[0x55];
  local_4c = 0;
  if (param_1[0xfe] == 4) {
    iVar3 = imap_perform_upgrade_tls();
  }
  else if (param_1[0xf6] == 0) {
    while (iVar3 = Curl_pp_readresp(iVar14,piVar12,&local_50,&local_4c), iVar5 = local_50,
          iVar3 == 0) {
      iVar3 = local_50 + 1;
      if (iVar3 == 0) {
        return 8;
      }
      if (local_50 == 0) {
        return 0;
      }
      switch(param_1[0xfe]) {
      case 1:
        if (local_50 != 0x4f) {
          Curl_failf(*param_1,"Got unexpected imap-server response");
          return 8;
        }
        param_1[0x102] = 0;
        param_1[0x104] = 0;
        *(undefined1 *)((int)param_1 + 0x425) = 0;
        iVar3 = imap_sendf(param_1,"CAPABILITY");
        if (iVar3 != 0) {
          return iVar3;
        }
        param_1[0xfe] = 2;
        break;
      case 2:
        iVar3 = *param_1;
        if (local_50 != 0x2a) {
          if (((local_50 == 0x4f) && (*(int *)(iVar3 + 0x318) != 0)) &&
             ((char)param_1[0x5e] == '\0')) {
            if (*(char *)((int)param_1 + 0x425) != '\0') {
              iVar3 = imap_sendf(param_1,"STARTTLS");
              if (iVar3 != 0) {
                return iVar3;
              }
              param_1[0xfe] = 3;
              break;
            }
            if (*(int *)(iVar3 + 0x318) != 1) {
              Curl_failf(iVar3,"STARTTLS not supported.");
              return 0x40;
            }
          }
LAB_00050c04:
          local_68 = imap_perform_authentication(param_1);
          goto joined_r0x00050f20;
        }
        __s1 = (byte *)(iVar3 + 0x59e);
        while (bVar1 = *__s1, bVar1 != 0) {
          if (((bVar1 == 0x20 || bVar1 == 9) || (bVar1 == 0xd)) ||
             (pbVar7 = __s1, uVar10 = 0, bVar1 == 10)) {
            __s1 = __s1 + 1;
          }
          else {
            while( true ) {
              uVar8 = uVar10;
              bVar1 = pbVar7[1];
              uVar10 = uVar8 + 1;
              if (((bVar1 & 0xdf) == 0) || (bVar1 == 9)) break;
              if ((bVar1 == 0xd) || (pbVar7 = pbVar7 + 1, bVar1 == 10)) break;
            }
            if (uVar10 == 8) {
              iVar3 = memcmp(__s1,"STARTTLS",8);
              if (iVar3 != 0) goto LAB_00050c16;
              *(undefined1 *)((int)param_1 + 0x425) = 1;
            }
            else if (uVar10 == 0xd) {
              iVar3 = memcmp(__s1,"LOGINDISABLED",0xd);
              if (iVar3 != 0) goto LAB_00050c16;
              *(undefined1 *)((int)param_1 + 0x426) = 1;
            }
            else if (uVar10 == 7) {
              iVar3 = memcmp(__s1,"SASL-IR",7);
              if (iVar3 != 0) goto LAB_00050c16;
              *(undefined1 *)((int)param_1 + 0x427) = 1;
            }
            else if (5 < uVar10) {
LAB_00050c16:
              iVar3 = memcmp(__s1,"AUTH=",5);
              if (iVar3 == 0) {
                __s1 = __s1 + 5;
                uVar10 = uVar8 - 4;
                uVar8 = Curl_sasl_decode_mech(__s1,uVar10,&local_48);
                if (uVar8 != 0) {
                  uVar11 = local_48;
                  if (uVar10 == local_48) {
                    uVar11 = param_1[0x102] | uVar8;
                  }
                  if (uVar10 == local_48) {
                    param_1[0x102] = uVar11;
                  }
                }
              }
            }
            __s1 = __s1 + uVar10;
          }
        }
        break;
      case 3:
        if (local_50 != 0x4f) {
          if (*(int *)(*param_1 + 0x318) != 1) {
            Curl_failf(*param_1,"STARTTLS denied. %c",local_50);
            return 0x40;
          }
          goto LAB_00050c04;
        }
        local_68 = imap_perform_upgrade_tls(param_1);
        goto joined_r0x00050f20;
      default:
        goto switchD_00050978_caseD_4;
      case 5:
        iVar5 = *param_1;
        iVar3 = Curl_sasl_continue(param_1 + 0x100,param_1,local_50,&local_44);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (local_44 != 0) {
          if (local_44 == 2) {
            param_1[0xfe] = 0;
          }
          break;
        }
        if ((*(char *)((int)param_1 + 0x426) != '\0') || (-1 < param_1[0x106] << 0x1f)) {
          Curl_failf(iVar5,"Authentication cancelled");
          return 0x43;
        }
        uVar10 = (uint)*(byte *)((int)param_1 + 0x1f1);
        if (uVar10 != 0) {
          iVar3 = imap_perform_login_part_7(param_1);
          if (iVar3 != 0) {
            return iVar3;
          }
          break;
        }
        goto LAB_000509a0;
      case 6:
        if (local_50 != 0x4f) {
          Curl_failf(*param_1,"Access denied. %c",local_50);
          return 0x43;
        }
        goto switchD_00050978_caseD_4;
      case 7:
      case 0xd:
        iVar3 = *param_1;
        pcVar13 = (char *)(iVar3 + 0x59c);
        sVar4 = strlen(pcVar13);
        if (iVar5 != 0x2a) {
          if (iVar5 != 0x4f) {
            return 0x15;
          }
          goto switchD_00050978_caseD_4;
        }
        iVar3 = iVar3 + sVar4;
        *(undefined1 *)(iVar3 + 0x59c) = 10;
        local_68 = Curl_client_write(param_1,1,pcVar13,sVar4 + 1);
        *(undefined1 *)(iVar3 + 0x59c) = 0;
        goto joined_r0x00050f20;
      case 8:
        iVar3 = *param_1;
        iVar5 = *(int *)(iVar3 + 0x14c);
        if (local_50 != 0x2a) {
          if (local_50 != 0x4f) {
            Curl_failf(iVar3,"Select failed");
            return 0x43;
          }
          if (((*(char **)(iVar5 + 8) != (char *)0x0) && ((char *)param_1[0x10b] != (char *)0x0)) &&
             (iVar6 = strcmp(*(char **)(iVar5 + 8),(char *)param_1[0x10b]), iVar6 != 0)) {
            Curl_failf(iVar3,"Mailbox UIDVALIDITY has changed");
            return 0x4e;
          }
          iVar3 = (*Curl_cstrdup)(*(undefined4 *)(iVar5 + 4));
          iVar6 = *(int *)(iVar5 + 0x1c);
          param_1[0x10a] = iVar3;
          if (iVar6 == 0) {
            if (*(int *)(iVar5 + 0x18) == 0) {
              local_68 = imap_perform_fetch(param_1);
            }
            else {
              local_68 = imap_perform_search();
            }
          }
          else {
            local_68 = imap_perform_list(param_1);
          }
          goto joined_r0x00050f20;
        }
        iVar3 = __isoc99_sscanf(iVar3 + 0x59e,"OK [UIDVALIDITY %19[0123456789]]",auStack_3c);
        if (iVar3 == 1) {
          (*Curl_cfree)(param_1[0x10b]);
          param_1[0x10b] = 0;
          iVar3 = (*Curl_cstrdup)(auStack_3c);
          param_1[0x10b] = iVar3;
        }
        break;
      case 9:
        iVar5 = *param_1;
        if (local_50 != 0x2a) {
          Curl_pgrsSetDownloadSize(iVar5,iVar3,0xffffffff,0xffffffff);
          param_1[0xfe] = 0;
          return 0x4e;
        }
        cVar9 = *(char *)(iVar5 + 0x59c);
        pcVar13 = (char *)(iVar5 + 0x59c);
        if (cVar9 != '\0' && cVar9 != '{') {
          pcVar2 = (char *)(iVar5 + 0x59d);
          do {
            pcVar13 = pcVar2;
            cVar9 = *pcVar13;
            pcVar2 = pcVar13 + 1;
          } while (cVar9 != '{' && cVar9 != '\0');
        }
        if ((((cVar9 == '{') &&
             (lVar15 = strtoll(pcVar13 + 1,&local_40,10), 1 < (int)local_40 - (int)pcVar13)) &&
            (*local_40 == '}')) && ((local_40[1] == '\r' && (local_40[2] == '\0')))) {
          local_58 = (uint)lVar15;
          iStack_54 = (int)((ulonglong)lVar15 >> 0x20);
          Curl_infof(iVar5,"Found %llu bytes to download\n",local_58,iStack_54);
          Curl_pgrsSetDownloadSize(iVar5,extraout_r1,local_58,iStack_54);
          if (param_1[0xf0] != 0) {
            uVar10 = param_1[0xf1];
            if (local_58 <= (uint)param_1[0xf1]) {
              uVar10 = local_58;
            }
            iVar3 = Curl_client_write(param_1,1,param_1[0xf0],uVar10);
            if (iVar3 != 0) {
              return iVar3;
            }
            uVar8 = *(uint *)(iVar5 + 0x70);
            *(uint *)(iVar5 + 0x70) = uVar8 + uVar10;
            *(uint *)(iVar5 + 0x74) = *(int *)(iVar5 + 0x74) + (uint)CARRY4(uVar8,uVar10);
            Curl_infof(iVar5,"Written %llu bytes, %llu bytes are left for transfer\n",uVar10,0,
                       local_58 - uVar10,iStack_54 - (uint)(local_58 < uVar10));
            if (uVar10 < (uint)param_1[0xf1]) {
              memmove((void *)param_1[0xf0],(void *)(param_1[0xf0] + uVar10),param_1[0xf1] - uVar10)
              ;
              param_1[0xf1] = param_1[0xf1] - uVar10;
            }
            else {
              (*Curl_cfree)(param_1[0xf0]);
              param_1[0xf0] = 0;
              param_1[0xf1] = 0;
            }
          }
          if (iStack_54 == *(int *)(iVar5 + 0x74) && local_58 == *(uint *)(iVar5 + 0x70)) {
            local_68 = 0;
            Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
          }
          else {
            *(uint *)(iVar5 + 0x60) = local_58;
            *(int *)(iVar5 + 100) = iStack_54;
            local_68 = 0;
            Curl_setup_transfer(param_1,0,local_58,iStack_54,0,0,0xffffffff,0);
          }
        }
        else {
          local_68 = 8;
          Curl_failf(*(undefined4 *)param_1[0xfb],"Failed to parse FETCH response.");
        }
        param_1[0xfe] = 0;
joined_r0x00050f20:
        if (local_68 != 0) {
          return local_68;
        }
        break;
      case 10:
        if (local_50 != 0x4f) {
          return 8;
        }
        goto switchD_00050978_caseD_4;
      case 0xb:
        iVar5 = *param_1;
        if (local_50 != 0x2b) {
          return 0x19;
        }
        Curl_pgrsSetUploadSize
                  (iVar5,iVar3,*(undefined4 *)(iVar5 + 0x86b0),*(undefined4 *)(iVar5 + 0x86b4));
        Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0,0);
        param_1[0xfe] = 0;
        break;
      case 0xc:
        if (local_50 != 0x4f) {
          return 0x19;
        }
switchD_00050978_caseD_4:
        uVar10 = 0;
LAB_000509a0:
        param_1[0xfe] = uVar10;
      }
      if (param_1[0xfe] == 0) {
        return 0;
      }
      iVar3 = Curl_pp_moredata(piVar12);
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  else {
    iVar3 = Curl_pp_flushsend(piVar12);
  }
  return iVar3;
}

