
int pop3_statemach_act(int *param_1)

{
  char cVar1;
  code **ppcVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  void *__dest;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  int local_38;
  undefined4 local_34;
  uint local_30;
  int local_2c [2];
  
  ppcVar2 = DAT_00051aec;
  piVar11 = param_1 + 0xf0;
  iVar12 = param_1[0x55];
  local_34 = 0;
  if (param_1[0xfe] == 4) {
    iVar12 = pop3_perform_upgrade_tls();
    return iVar12;
  }
  if (param_1[0xf6] != 0) {
    iVar12 = Curl_pp_flushsend(piVar11);
    return iVar12;
  }
LAB_00051740:
  iVar3 = Curl_pp_readresp(iVar12,piVar11,&local_38,&local_34);
  iVar7 = local_38;
  if (iVar3 != 0) {
    return iVar3;
  }
  if (local_38 == 0) {
    return 0;
  }
  iVar3 = param_1[0xfe];
  switch(iVar3) {
  case 1:
    iVar3 = *param_1;
    sVar4 = strlen((char *)(iVar3 + 0x59c));
    if (iVar7 != 0x2b) {
      Curl_failf(iVar3,DAT_00051ad0);
      return 8;
    }
    if (((3 < sVar4) && (*(char *)(iVar3 + sVar4 + 0x59a) == '>')) && (3 < sVar4 - 2)) {
      uVar8 = 3;
      cVar1 = *(char *)(iVar3 + 0x59f);
      while (cVar1 != '<') {
        uVar8 = uVar8 + 1;
        if (uVar8 == sVar4 - 2) goto LAB_0005193e;
        cVar1 = *(char *)(iVar3 + uVar8 + 0x59c);
      }
      sVar4 = (sVar4 - uVar8) - 1;
      if (sVar4 != 0) {
        __dest = (void *)(**DAT_00051b3c)(1);
        param_1[0x10a] = (int)__dest;
        if (__dest != (void *)0x0) {
          memcpy(__dest,(void *)(iVar3 + uVar8 + 0x59c),sVar4);
          *(undefined *)(param_1[0x10a] + sVar4) = 0;
          param_1[0x108] = param_1[0x108] | 2;
        }
      }
    }
LAB_0005193e:
    param_1[0x104] = 0;
    param_1[0x106] = 0;
    *(undefined *)(param_1 + 0x10b) = 0;
    iVar7 = Curl_pp_sendf(piVar11,DAT_00051ad8,DAT_00051adc);
    if (iVar7 != 0) {
      return iVar7;
    }
    param_1[0xfe] = 2;
    goto LAB_000518c0;
  case 2:
    iVar13 = *param_1;
    pcVar14 = (char *)(iVar13 + 0x59c);
    sVar4 = strlen(pcVar14);
    if (iVar7 != 0x2a) {
      if (iVar7 == 0x2b) {
        if ((*(int *)(iVar13 + 0x318) != 0) && (*(char *)(param_1 + 0x5e) == '\0')) {
          if (*(char *)(param_1 + 0x10b) != '\0') {
            iVar7 = Curl_pp_sendf(piVar11,DAT_00051ad8,DAT_00051ae0);
            if (iVar7 != 0) {
              return iVar7;
            }
            param_1[0xfe] = 3;
            goto LAB_000518c0;
          }
          if (*(int *)(iVar13 + 0x318) != 1) {
            Curl_failf(iVar13,DAT_00051ad4);
            return 0x40;
          }
        }
        goto LAB_0005191c;
      }
      param_1[0x108] = param_1[0x108] | 1;
      iVar7 = pop3_perform_authentication(param_1);
      goto LAB_000518b4;
    }
    if (3 < sVar4) {
      iVar7 = memcmp(pcVar14,DAT_00051ae0,4);
      if (iVar7 == 0) {
        *(undefined *)(param_1 + 0x10b) = 1;
      }
      else {
        iVar7 = memcmp(pcVar14,DAT_00051ae4,4);
        if (iVar7 == 0) {
          param_1[0x108] = param_1[0x108] | 1;
        }
        else if ((sVar4 != 4) && (iVar7 = memcmp(pcVar14,DAT_00051ae8,5), iVar7 == 0)) {
          uVar8 = sVar4 - 5;
          pcVar14 = (char *)0x0;
          if (uVar8 != 0) {
            pcVar14 = (char *)(iVar13 + 0x5a1);
          }
          param_1[0x108] = param_1[0x108] | 4;
          if (uVar8 != 0) {
            do {
              while (((cVar1 = *pcVar14, cVar1 != ' ' && cVar1 != '\t' &&
                      (uVar10 = 0, cVar1 != '\r')) && (cVar1 != '\n'))) {
                pcVar6 = pcVar14;
                if (uVar8 == 0) {
                  uVar10 = 0;
                }
                else {
                  while( true ) {
                    pcVar6 = pcVar6 + 1;
                    uVar10 = uVar10 + 1;
                    if (uVar10 == uVar8) break;
                    cVar1 = *pcVar6;
                    if (((cVar1 == ' ') || (cVar1 == '\t')) || ((cVar1 == '\r' || (cVar1 == '\n'))))
                    goto LAB_000519fe;
                  }
                  pcVar6 = pcVar14 + uVar10;
                }
LAB_000519fe:
                uVar5 = Curl_sasl_decode_mech(pcVar14,uVar10,&local_30);
                if (uVar5 != 0) {
                  uVar9 = local_30;
                  if (uVar10 == local_30) {
                    uVar9 = param_1[0x104] | uVar5;
                  }
                  if (uVar10 == local_30) {
                    param_1[0x104] = uVar9;
                  }
                }
                uVar8 = uVar8 - uVar10;
                pcVar14 = pcVar6;
                if (uVar8 == 0) goto LAB_000518b8;
              }
              uVar8 = uVar8 - 1;
              pcVar14 = pcVar14 + 1;
            } while (uVar8 != 0);
            goto LAB_000518b8;
          }
        }
      }
    }
    goto LAB_000518bc;
  case 3:
    if (local_38 == 0x2b) {
      iVar7 = pop3_perform_upgrade_tls(param_1);
    }
    else {
      if (*(int *)(*param_1 + 0x318) != 1) {
        Curl_failf(*param_1,DAT_00051acc);
        return 0x40;
      }
LAB_0005191c:
      iVar7 = pop3_perform_authentication(param_1);
    }
LAB_000518b4:
    if (iVar7 != 0) {
      return iVar7;
    }
    goto LAB_000518b8;
  case 5:
    iVar3 = *param_1;
    iVar7 = Curl_sasl_continue(param_1 + 0x102,param_1,local_38,local_2c);
    if (iVar7 != 0) {
      return iVar7;
    }
    if (local_2c[0] == 0) {
      if ((param_1[0x108] & param_1[0x109]) << 0x1e < 0) {
        uVar8 = (uint)*(byte *)((int)param_1 + 0x1f1);
        if (uVar8 == 0) goto LAB_000517ca;
        iVar7 = pop3_perform_apop_part_11(param_1);
      }
      else {
        if (-1 < (param_1[0x108] & param_1[0x109]) << 0x1f) {
          Curl_failf(iVar3,DAT_00051ac8);
          return 0x43;
        }
        iVar7 = pop3_perform_user(param_1);
      }
      goto LAB_000518b4;
    }
    if (local_2c[0] == 2) {
      param_1[0xfe] = 0;
      return 0;
    }
LAB_000518b8:
    iVar3 = param_1[0xfe];
LAB_000518bc:
    if (iVar3 == 0) {
      return 0;
    }
    goto LAB_000518c0;
  case 6:
    if (local_38 != 0x2b) {
      Curl_failf(*param_1,DAT_00051ac4);
      return 0x43;
    }
    break;
  case 7:
    iVar7 = *param_1;
    if (local_38 != 0x2b) {
LAB_000517f2:
      Curl_failf(iVar7,DAT_00051ab8);
      return 0x43;
    }
    iVar7 = param_1[0x49];
    if (param_1[0x49] == 0) {
      iVar7 = DAT_00051abc;
    }
    iVar7 = Curl_pp_sendf(piVar11,DAT_00051ac0,iVar7);
    if (iVar7 != 0) {
      return iVar7;
    }
    param_1[0xfe] = 8;
LAB_000518c0:
    iVar7 = Curl_pp_moredata(piVar11);
    if (iVar7 == 0) {
      return 0;
    }
    goto LAB_00051740;
  case 8:
    iVar7 = *param_1;
    if (local_38 != 0x2b) goto LAB_000517f2;
    break;
  case 9:
    iVar12 = *param_1;
    if (local_38 != 0x2b) {
      param_1[0xfe] = 0;
      return 0x38;
    }
    iVar7 = **(int **)(iVar12 + 0x14c);
    param_1[0x100] = 2;
    param_1[0x101] = 2;
    if (iVar7 == 0) {
      Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,0,0,0xffffffff,0);
      iVar7 = param_1[0xf0];
      if (iVar7 != 0) {
        if (*(char *)(iVar12 + 0x307) == '\0') {
          iVar12 = Curl_pop3_write(param_1,iVar7,param_1[0xf1]);
          if (iVar12 != 0) {
            return iVar12;
          }
          iVar7 = param_1[0xf0];
        }
        (**ppcVar2)(iVar7);
        param_1[0xf0] = 0;
        param_1[0xf1] = 0;
      }
    }
  }
  uVar8 = 0;
LAB_000517ca:
  param_1[0xfe] = uVar8;
  return 0;
}

