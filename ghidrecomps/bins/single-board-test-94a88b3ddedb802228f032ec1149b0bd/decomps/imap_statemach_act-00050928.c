
int imap_statemach_act(int *param_1)

{
  byte bVar1;
  code **ppcVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  undefined4 extraout_r1;
  byte *pbVar9;
  uint uVar10;
  char cVar11;
  uint uVar12;
  uint uVar13;
  byte *__s1;
  int *piVar14;
  char *pcVar15;
  int iVar16;
  longlong lVar17;
  int local_68;
  uint local_58;
  int iStack_54;
  int local_50;
  undefined4 local_4c;
  uint local_48;
  int local_44;
  char *local_40;
  undefined auStack_3c [24];
  
  ppcVar2 = DAT_00050d34;
  piVar14 = param_1 + 0xf0;
  iVar16 = param_1[0x55];
  local_4c = 0;
  if (param_1[0xfe] == 4) {
    iVar5 = imap_perform_upgrade_tls();
  }
  else if (param_1[0xf6] == 0) {
    while (iVar5 = Curl_pp_readresp(iVar16,piVar14,&local_50,&local_4c), iVar7 = local_50,
          iVar5 == 0) {
      iVar5 = local_50 + 1;
      if (iVar5 == 0) {
        return 8;
      }
      if (local_50 == 0) {
        return 0;
      }
      switch(param_1[0xfe]) {
      case 1:
        if (local_50 != 0x4f) {
          Curl_failf(*param_1,DAT_00050d0c);
          return 8;
        }
        param_1[0x102] = 0;
        param_1[0x104] = 0;
        *(undefined *)((int)param_1 + 0x425) = 0;
        iVar5 = imap_sendf(param_1,DAT_00050d2c);
        if (iVar5 != 0) {
          return iVar5;
        }
        param_1[0xfe] = 2;
        break;
      case 2:
        iVar5 = *param_1;
        if (local_50 != 0x2a) {
          if (((local_50 == 0x4f) && (*(int *)(iVar5 + 0x318) != 0)) &&
             (*(char *)(param_1 + 0x5e) == '\0')) {
            if (*(char *)((int)param_1 + 0x425) != '\0') {
              iVar5 = imap_sendf(param_1,DAT_00050f34);
              if (iVar5 != 0) {
                return iVar5;
              }
              param_1[0xfe] = 3;
              break;
            }
            if (*(int *)(iVar5 + 0x318) != 1) {
              Curl_failf(iVar5,DAT_00050d08);
              return 0x40;
            }
          }
LAB_00050c04:
          local_68 = imap_perform_authentication(param_1);
          goto joined_r0x00050f20;
        }
        __s1 = (byte *)(iVar5 + 0x59e);
        while (bVar1 = *__s1, bVar1 != 0) {
          if (((bVar1 == 0x20 || bVar1 == 9) || (bVar1 == 0xd)) ||
             (pbVar9 = __s1, uVar12 = 0, bVar1 == 10)) {
            __s1 = __s1 + 1;
          }
          else {
            while( true ) {
              uVar10 = uVar12;
              bVar1 = pbVar9[1];
              uVar12 = uVar10 + 1;
              if (((bVar1 & 0xdf) == 0) || (bVar1 == 9)) break;
              if ((bVar1 == 0xd) || (pbVar9 = pbVar9 + 1, bVar1 == 10)) break;
            }
            if (uVar12 == 8) {
              iVar5 = memcmp(__s1,DAT_00050d24,8);
              if (iVar5 != 0) goto LAB_00050c16;
              *(undefined *)((int)param_1 + 0x425) = 1;
            }
            else if (uVar12 == 0xd) {
              iVar5 = memcmp(__s1,DAT_00050d28,0xd);
              if (iVar5 != 0) goto LAB_00050c16;
              *(undefined *)((int)param_1 + 0x426) = 1;
            }
            else if (uVar12 == 7) {
              iVar5 = memcmp(__s1,DAT_00050d18,7);
              if (iVar5 != 0) goto LAB_00050c16;
              *(undefined *)((int)param_1 + 0x427) = 1;
            }
            else if (5 < uVar12) {
LAB_00050c16:
              iVar5 = memcmp(__s1,DAT_00050d20,5);
              if (iVar5 == 0) {
                __s1 = __s1 + 5;
                uVar12 = uVar10 - 4;
                uVar10 = Curl_sasl_decode_mech(__s1,uVar12,&local_48);
                if (uVar10 != 0) {
                  uVar13 = local_48;
                  if (uVar12 == local_48) {
                    uVar13 = param_1[0x102] | uVar10;
                  }
                  if (uVar12 == local_48) {
                    param_1[0x102] = uVar13;
                  }
                }
              }
            }
            __s1 = __s1 + uVar12;
          }
        }
        break;
      case 3:
        if (local_50 != 0x4f) {
          if (*(int *)(*param_1 + 0x318) != 1) {
            Curl_failf(*param_1,DAT_00050d04,local_50);
            return 0x40;
          }
          goto LAB_00050c04;
        }
        local_68 = imap_perform_upgrade_tls(param_1);
        goto joined_r0x00050f20;
      default:
        goto switchD_00050978_caseD_4;
      case 5:
        iVar7 = *param_1;
        iVar5 = Curl_sasl_continue(param_1 + 0x100,param_1,local_50,&local_44);
        if (iVar5 != 0) {
          return iVar5;
        }
        if (local_44 != 0) {
          if (local_44 == 2) {
            param_1[0xfe] = 0;
          }
          break;
        }
        if ((*(char *)((int)param_1 + 0x426) != '\0') || (-1 < param_1[0x106] << 0x1f)) {
          Curl_failf(iVar7,DAT_00050d00);
          return 0x43;
        }
        uVar12 = (uint)*(byte *)((int)param_1 + 0x1f1);
        if (uVar12 != 0) {
          iVar5 = imap_perform_login_part_7(param_1);
          if (iVar5 != 0) {
            return iVar5;
          }
          break;
        }
        goto LAB_000509a0;
      case 6:
        if (local_50 != 0x4f) {
          Curl_failf(*param_1,DAT_00050d14,local_50);
          return 0x43;
        }
        goto switchD_00050978_caseD_4;
      case 7:
      case 0xd:
        iVar5 = *param_1;
        pcVar15 = (char *)(iVar5 + 0x59c);
        sVar6 = strlen(pcVar15);
        if (iVar7 != 0x2a) {
          if (iVar7 != 0x4f) {
            return 0x15;
          }
          goto switchD_00050978_caseD_4;
        }
        iVar5 = iVar5 + sVar6;
        *(undefined *)(iVar5 + 0x59c) = 10;
        local_68 = Curl_client_write(param_1,1,pcVar15,sVar6 + 1);
        *(undefined *)(iVar5 + 0x59c) = 0;
        goto joined_r0x00050f20;
      case 8:
        iVar5 = *param_1;
        iVar7 = *(int *)(iVar5 + 0x14c);
        if (local_50 != 0x2a) {
          if (local_50 != 0x4f) {
            Curl_failf(iVar5,DAT_00050d10);
            return 0x43;
          }
          if (((*(char **)(iVar7 + 8) != (char *)0x0) && ((char *)param_1[0x10b] != (char *)0x0)) &&
             (iVar8 = strcmp(*(char **)(iVar7 + 8),(char *)param_1[0x10b]), iVar8 != 0)) {
            Curl_failf(iVar5,DAT_00050d30);
            return 0x4e;
          }
          iVar5 = (**ppcVar2)(*(undefined4 *)(iVar7 + 4));
          iVar8 = *(int *)(iVar7 + 0x1c);
          param_1[0x10a] = iVar5;
          if (iVar8 == 0) {
            if (*(int *)(iVar7 + 0x18) == 0) {
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
        iVar5 = __isoc99_sscanf(iVar5 + 0x59e,DAT_00050f28,auStack_3c);
        if (iVar5 == 1) {
          (*Curl_cfree)(param_1[0x10b]);
          param_1[0x10b] = 0;
          iVar5 = (**ppcVar2)(auStack_3c);
          param_1[0x10b] = iVar5;
        }
        break;
      case 9:
        iVar7 = *param_1;
        if (local_50 != 0x2a) {
          Curl_pgrsSetDownloadSize(iVar7,iVar5,0xffffffff,0xffffffff);
          param_1[0xfe] = 0;
          return 0x4e;
        }
        cVar11 = *(char *)(iVar7 + 0x59c);
        pcVar15 = (char *)(iVar7 + 0x59c);
        if (cVar11 != '\0' && cVar11 != '{') {
          pcVar4 = (char *)(iVar7 + 0x59d);
          do {
            pcVar15 = pcVar4;
            cVar11 = *pcVar15;
            pcVar4 = pcVar15 + 1;
          } while (cVar11 != '{' && cVar11 != '\0');
        }
        if ((((cVar11 == '{') &&
             (lVar17 = strtoll(pcVar15 + 1,&local_40,10), 1 < (int)local_40 - (int)pcVar15)) &&
            (*local_40 == '}')) && ((local_40[1] == '\r' && (local_40[2] == '\0')))) {
          local_58 = (uint)lVar17;
          iStack_54 = (int)((ulonglong)lVar17 >> 0x20);
          Curl_infof(iVar7,DAT_00050f2c,local_58,iStack_54);
          Curl_pgrsSetDownloadSize(iVar7,extraout_r1,local_58,iStack_54);
          if (param_1[0xf0] != 0) {
            uVar12 = param_1[0xf1];
            if (local_58 <= (uint)param_1[0xf1]) {
              uVar12 = local_58;
            }
            iVar5 = Curl_client_write(param_1,1,param_1[0xf0],uVar12);
            uVar3 = DAT_00050f30;
            if (iVar5 != 0) {
              return iVar5;
            }
            uVar10 = *(uint *)(iVar7 + 0x70);
            *(uint *)(iVar7 + 0x70) = uVar10 + uVar12;
            *(uint *)(iVar7 + 0x74) = *(int *)(iVar7 + 0x74) + (uint)CARRY4(uVar10,uVar12);
            Curl_infof(iVar7,uVar3,uVar12,0,local_58 - uVar12,iStack_54 - (uint)(local_58 < uVar12))
            ;
            if (uVar12 < (uint)param_1[0xf1]) {
              memmove((void *)param_1[0xf0],(void *)((int)(void *)param_1[0xf0] + uVar12),
                      param_1[0xf1] - uVar12);
              param_1[0xf1] = param_1[0xf1] - uVar12;
            }
            else {
              (*Curl_cfree)(param_1[0xf0]);
              param_1[0xf0] = 0;
              param_1[0xf1] = 0;
            }
          }
          if (iStack_54 == *(int *)(iVar7 + 0x74) && local_58 == *(uint *)(iVar7 + 0x70)) {
            local_68 = 0;
            Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
          }
          else {
            *(uint *)(iVar7 + 0x60) = local_58;
            *(int *)(iVar7 + 100) = iStack_54;
            local_68 = 0;
            Curl_setup_transfer(param_1,0,local_58,iStack_54,0,0,0xffffffff,0);
          }
        }
        else {
          local_68 = 8;
          Curl_failf(*(undefined4 *)param_1[0xfb],DAT_00050d1c);
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
        iVar7 = *param_1;
        if (local_50 != 0x2b) {
          return 0x19;
        }
        Curl_pgrsSetUploadSize
                  (iVar7,iVar5,*(undefined4 *)(iVar7 + 0x86b0),*(undefined4 *)(iVar7 + 0x86b4));
        Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0,0);
        param_1[0xfe] = 0;
        break;
      case 0xc:
        if (local_50 != 0x4f) {
          return 0x19;
        }
switchD_00050978_caseD_4:
        uVar12 = 0;
LAB_000509a0:
        param_1[0xfe] = uVar12;
      }
      if (param_1[0xfe] == 0) {
        return 0;
      }
      iVar5 = Curl_pp_moredata(piVar14);
      if (iVar5 == 0) {
        return 0;
      }
    }
  }
  else {
    iVar5 = Curl_pp_flushsend(piVar14);
  }
  return iVar5;
}

