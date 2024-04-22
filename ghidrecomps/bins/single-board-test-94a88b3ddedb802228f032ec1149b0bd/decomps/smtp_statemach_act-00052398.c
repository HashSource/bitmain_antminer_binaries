
int smtp_statemach_act(int *param_1)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  void *__s1;
  bool bVar16;
  undefined8 uVar17;
  int local_38;
  undefined4 local_34;
  uint local_30;
  int local_2c [2];
  
  piVar12 = param_1 + 0xf0;
  iVar13 = param_1[0x55];
  iVar14 = *param_1;
  local_34 = 0;
  if (param_1[0xfe] == 5) {
    iVar9 = smtp_perform_upgrade_tls();
  }
  else if (param_1[0xf6] == 0) {
    while( true ) {
      uVar17 = Curl_pp_readresp(iVar13,piVar12,&local_38,&local_34);
      iVar7 = local_38;
      iVar9 = (int)uVar17;
      if (iVar9 != 0) break;
      iVar9 = param_1[0xfe];
      if (iVar9 == 0xc) {
        if (local_38 == 0) {
          return 0;
        }
switchD_000523f6_caseD_5:
        param_1[0xfe] = 0;
        return 0;
      }
      if ((local_38 != 1) && (*(int *)(iVar14 + 0x86f4) = local_38, local_38 == 0)) {
        return 0;
      }
      switch(iVar9) {
      case 1:
        if (99 < local_38 - 200U) {
          Curl_failf(*param_1,DAT_000526c8,local_38);
          return 8;
        }
        param_1[0x103] = 0;
        param_1[0x105] = 0;
        *(undefined *)(param_1 + 0x107) = 0;
        *(undefined *)((int)param_1 + 0x41e) = 0;
        iVar9 = Curl_pp_sendf(piVar12,DAT_00052834,param_1[0x100]);
        if (iVar9 != 0) {
          return iVar9;
        }
        param_1[0xfe] = 2;
        break;
      case 2:
        iVar2 = *param_1;
        iVar9 = local_38 + -1;
        if (iVar9 != 0) {
          iVar9 = 1;
        }
        sVar3 = strlen((char *)(iVar2 + 0x59c));
        bVar16 = iVar7 != 0;
        if (iVar7 != 1) {
          bVar16 = 0x62 < iVar7 - 200U;
        }
        if (!bVar16 || (iVar7 == 1 || iVar7 - 200U == 99)) {
          uVar10 = sVar3 - 4;
          __s1 = (void *)(iVar2 + 0x5a0);
          if (uVar10 < 8) {
            if (3 < uVar10) goto LAB_00052644;
          }
          else {
            iVar7 = memcmp(__s1,DAT_000526cc,8);
            if (iVar7 == 0) {
              *(undefined *)(param_1 + 0x107) = 1;
            }
            else {
LAB_00052644:
              iVar7 = memcmp(__s1,DAT_000526d8,4);
              if (iVar7 == 0) {
                *(undefined *)((int)param_1 + 0x41d) = 1;
              }
              else if ((4 < uVar10) && (iVar7 = memcmp(__s1,DAT_000526dc,5), iVar7 == 0)) {
                uVar10 = sVar3 - 9;
                *(undefined *)((int)param_1 + 0x41e) = 1;
                if (uVar10 != 0) {
                  pcVar4 = (char *)(iVar2 + 0x5a5);
                  do {
                    while (((cVar1 = *pcVar4, cVar1 == ' ' || cVar1 == '\t' ||
                            (uVar11 = 0, cVar1 == '\r')) || (cVar1 == '\n'))) {
                      uVar10 = uVar10 - 1;
                      pcVar4 = pcVar4 + 1;
                      if (uVar10 == 0) goto LAB_00052734;
                    }
                    pcVar6 = pcVar4;
                    if (uVar10 == 0) {
                      uVar11 = 0;
                    }
                    else {
                      while( true ) {
                        pcVar6 = pcVar6 + 1;
                        uVar11 = uVar11 + 1;
                        if (uVar11 == uVar10) break;
                        cVar1 = *pcVar6;
                        if (((cVar1 == ' ') || (cVar1 == '\t')) ||
                           ((cVar1 == '\r' || (cVar1 == '\n')))) goto LAB_00052700;
                      }
                      pcVar6 = pcVar4 + uVar11;
                    }
LAB_00052700:
                    uVar5 = Curl_sasl_decode_mech(pcVar4,uVar11,&local_30);
                    if (uVar5 != 0) {
                      uVar8 = local_30;
                      if (uVar11 == local_30) {
                        uVar8 = param_1[0x103] | uVar5;
                      }
                      if (uVar11 == local_30) {
                        param_1[0x103] = uVar8;
                      }
                    }
                    uVar10 = uVar10 - uVar11;
                    pcVar4 = pcVar6;
                  } while (uVar10 != 0);
                }
              }
            }
          }
LAB_00052734:
          if (iVar9 != 0) {
            if ((*(int *)(iVar2 + 0x318) != 0) && (*(char *)(param_1 + 0x5e) == '\0')) {
              if (*(char *)(param_1 + 0x107) != '\0') {
                iVar9 = Curl_pp_sendf(piVar12,DAT_00052840,DAT_00052848);
                if (iVar9 != 0) {
                  return iVar9;
                }
                param_1[0xfe] = 4;
                break;
              }
              if (*(int *)(iVar2 + 0x318) != 1) {
                Curl_failf(iVar2,DAT_0005283c);
                return 0x40;
              }
            }
LAB_00052748:
            iVar2 = smtp_perform_authentication(param_1);
            goto LAB_0005243c;
          }
        }
        else {
          if ((1 < *(uint *)(iVar2 + 0x318)) && (*(char *)(param_1 + 0x5e) == '\0')) {
            Curl_failf(iVar2,DAT_00052838,iVar7);
            return 9;
          }
          param_1[0x105] = 0;
          iVar9 = Curl_pp_sendf(piVar12,DAT_000526c4,param_1[0x100]);
          if (iVar9 != 0) {
            return iVar9;
          }
          param_1[0xfe] = 3;
        }
        break;
      case 3:
        if (99 < local_38 - 200U) {
          Curl_failf(*param_1,DAT_000526d4,local_38);
          return 9;
        }
        param_1[0xfe] = 0;
        break;
      case 4:
        if (local_38 != 0xdc) {
          if (*(int *)(*param_1 + 0x318) != 1) {
            Curl_failf(*param_1,DAT_000526c0,local_38);
            return 0x40;
          }
          goto LAB_00052748;
        }
        iVar2 = smtp_perform_upgrade_tls(param_1);
        goto LAB_0005243c;
      default:
        goto switchD_000523f6_caseD_5;
      case 6:
        iVar7 = *param_1;
        iVar9 = Curl_sasl_continue(param_1 + 0x101,param_1,local_38,local_2c);
        if (iVar9 != 0) {
          return iVar9;
        }
        if (local_2c[0] == 0) {
          Curl_failf(iVar7,DAT_000526bc);
          return 0x43;
        }
        if (local_2c[0] == 2) {
          param_1[0xfe] = 0;
        }
        break;
      case 7:
        iVar9 = *param_1;
        iVar15 = *(int *)(iVar9 + 0x14c);
        sVar3 = strlen((char *)(iVar9 + 0x59c));
        if (*(int *)(iVar15 + 8) == 0) {
          if ((99 < iVar7 - 200U) && (iVar7 != 1)) goto LAB_000524c0;
        }
        else if ((99 < iVar7 - 200U) && (iVar7 != 1 && iVar7 != 0x229)) {
LAB_000524c0:
          Curl_failf(iVar9,DAT_000526b8,iVar7);
          return 0x38;
        }
        if (*(char *)(iVar9 + 0x307) == '\0') {
          *(undefined *)(iVar9 + sVar3 + 0x59c) = 10;
          iVar2 = Curl_client_write(param_1,1,(char *)(iVar9 + 0x59c),sVar3 + 1);
          *(undefined *)(iVar9 + sVar3 + 0x59c) = 0;
        }
        else {
          iVar2 = 0;
        }
        if (iVar7 != 1) {
          iVar9 = *(int *)(iVar15 + 8);
          if (iVar9 != 0) {
            iVar9 = *(int *)(iVar9 + 4);
            *(int *)(iVar15 + 8) = iVar9;
            if (iVar9 != 0) {
              iVar2 = smtp_perform_command(param_1);
              goto LAB_0005243c;
            }
          }
          goto LAB_00052438;
        }
        goto LAB_0005243c;
      case 8:
        if (99 < local_38 - 200U) {
          Curl_failf(*param_1,DAT_000526b4,local_38);
          return 0x37;
        }
LAB_00052470:
        iVar2 = smtp_perform_rcpt_to(param_1);
        goto LAB_0005243c;
      case 9:
        iVar9 = *(int *)(*param_1 + 0x14c);
        if (99 < local_38 - 200U) {
          Curl_failf(*param_1,DAT_000526d0,local_38);
          return 0x37;
        }
        iVar7 = *(int *)(*(int *)(iVar9 + 8) + 4);
        *(int *)(iVar9 + 8) = iVar7;
        if (iVar7 != 0) goto LAB_00052470;
        iVar9 = Curl_pp_sendf(piVar12,DAT_00052840,DAT_00052844);
        if (iVar9 != 0) {
          return iVar9;
        }
        param_1[0xfe] = 10;
        break;
      case 10:
        iVar9 = *param_1;
        if (local_38 != 0x162) {
          Curl_failf(iVar9,DAT_000526b0,local_38);
          return 0x37;
        }
        Curl_pgrsSetUploadSize
                  (iVar9,(int)((ulonglong)uVar17 >> 0x20),*(undefined4 *)(iVar9 + 0x86b0),
                   *(undefined4 *)(iVar9 + 0x86b4));
        Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0,0);
        param_1[0xfe] = 0;
        break;
      case 0xb:
        iVar9 = 0;
        if (local_38 == 0xfa) {
          iVar2 = 0;
        }
        else {
          iVar2 = 0x38;
        }
LAB_00052438:
        param_1[0xfe] = iVar9;
LAB_0005243c:
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      if (param_1[0xfe] == 0) {
        return 0;
      }
      iVar9 = Curl_pp_moredata(piVar12);
      if (iVar9 == 0) {
        return 0;
      }
    }
  }
  else {
    iVar9 = Curl_pp_flushsend(piVar12);
  }
  return iVar9;
}

