
/* WARNING: Type propagation algorithm not settling */

int * Curl_cookie_add(undefined4 param_1,int **param_2,int param_3,char *param_4,char *param_5,
                     char *param_6)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  int *piVar4;
  int *piVar5;
  code **ppcVar6;
  code **ppcVar7;
  int *piVar8;
  time_t tVar9;
  int *piVar10;
  int iVar11;
  char *pcVar12;
  void *__dest;
  undefined4 uVar13;
  char *pcVar14;
  size_t sVar15;
  size_t sVar16;
  char *pcVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  size_t sVar21;
  uint uVar22;
  code *pcVar23;
  char *pcVar24;
  bool bVar25;
  longlong lVar26;
  char local_428 [1028];
  
  tVar9 = time((time_t *)0x0);
  piVar10 = (int *)(**DAT_0003eb44)(1,0x38);
  if (piVar10 == (int *)0x0) {
    return (int *)0;
  }
  if (param_3 == 0) {
    iVar11 = strncmp(param_4,DAT_0003eb48,10);
    if (iVar11 == 0) {
      param_4 = param_4 + 10;
      *(undefined *)((int)piVar10 + 0x32) = 1;
    }
    if (*param_4 == '#') {
      (**DAT_0003f338)(piVar10);
      return (int *)0x0;
    }
    pcVar12 = strchr(param_4,0xd);
    if (pcVar12 != (char *)0x0) {
      *pcVar12 = '\0';
    }
    pcVar12 = strchr(param_4,10);
    if (pcVar12 != (char *)0x0) {
      *pcVar12 = '\0';
    }
    cVar1 = *param_4;
    while (cVar1 == '\t') {
      param_4 = param_4 + 1;
      cVar1 = *param_4;
    }
    pcVar12 = param_4 + 1;
    if (cVar1 == '\0') goto LAB_0003eb3a;
    do {
      pcVar14 = pcVar12;
      if (*pcVar14 == '\0') goto LAB_0003ea58;
      pcVar12 = pcVar14 + 1;
    } while (*pcVar14 != '\t');
    *pcVar14 = '\0';
    pcVar14 = pcVar14 + 1;
LAB_0003ea58:
    ppcVar6 = DAT_0003eb4c;
    if (param_4 == (char *)0x0) goto LAB_0003eb3a;
    iVar11 = 0;
    do {
      switch(iVar11) {
      case 0:
        if (*param_4 == '.') {
          param_4 = param_4 + 1;
        }
        iVar20 = (**ppcVar6)(param_4);
        iVar11 = 1;
        piVar10[5] = iVar20;
        uVar22 = 1;
        iVar18 = 1;
        if (iVar20 != 0) goto LAB_0003ed9e;
        break;
      case 1:
        iVar11 = Curl_raw_equal(param_4,DAT_0003ef24);
        if (iVar11 != 0) {
          iVar11 = 1;
        }
        *(char *)(piVar10 + 9) = (char)iVar11;
        iVar18 = 2;
LAB_0003ed9e:
        iVar11 = iVar18;
        uVar22 = 0;
        break;
      case 2:
        iVar11 = strcmp(DAT_0003ef24,param_4);
        if ((iVar11 == 0) || (iVar11 = strcmp(DAT_0003ef28,param_4), iVar11 == 0)) {
          uVar19 = (**ppcVar6)(DAT_0003ef2c);
          uVar13 = DAT_0003ef2c;
          uVar22 = 1 - uVar19;
          piVar10[3] = uVar19;
          if (1 < uVar19) {
            uVar22 = 0;
          }
          iVar11 = (**ppcVar6)(uVar13);
          if (iVar11 == 0) {
            uVar22 = 1;
          }
          piVar10[4] = iVar11;
          goto LAB_0003ed32;
        }
        iVar11 = (**ppcVar6)(param_4);
        piVar10[3] = iVar11;
        if (iVar11 == 0) {
          iVar11 = 3;
          uVar22 = 1;
        }
        else {
          uVar19 = sanitize_cookie_path();
          uVar22 = 1 - uVar19;
          piVar10[4] = uVar19;
          if (1 < uVar19) {
            uVar22 = 0;
          }
          iVar11 = 3;
        }
        break;
      case 3:
        uVar22 = 0;
LAB_0003ed32:
        iVar18 = Curl_raw_equal(param_4,DAT_0003ef24);
        iVar11 = 4;
        if (iVar18 != 0) {
          iVar18 = 1;
        }
        *(char *)(piVar10 + 0xc) = (char)iVar18;
        break;
      case 4:
        uVar22 = 0;
        lVar26 = strtoll(param_4,(char **)0x0,10);
        iVar11 = 5;
        *(longlong *)(piVar10 + 6) = lVar26;
        break;
      case 5:
        uVar19 = (**ppcVar6)(param_4);
        piVar10[1] = uVar19;
        uVar22 = 1 - uVar19;
        cVar1 = *pcVar14;
        if (1 < uVar19) {
          uVar22 = 0;
        }
        iVar11 = 6;
        param_4 = pcVar14;
        goto joined_r0x0003ecdc;
      case 6:
        uVar19 = (**ppcVar6)(param_4);
        uVar22 = 1 - uVar19;
        iVar11 = 7;
        if (1 < uVar19) {
          uVar22 = 0;
        }
        piVar10[2] = uVar19;
        break;
      default:
        iVar11 = iVar11 + 1;
        uVar22 = 0;
      }
      cVar1 = *pcVar14;
      param_4 = pcVar14;
joined_r0x0003ecdc:
      while (cVar1 == '\t') {
        cVar1 = param_4[1];
        param_4 = param_4 + 1;
      }
      if (cVar1 == '\0') break;
      pcVar12 = param_4 + 1;
      do {
        pcVar14 = pcVar12;
        if (*pcVar14 == '\0') goto LAB_0003ecfe;
        pcVar12 = pcVar14 + 1;
      } while (*pcVar14 != '\t');
      *pcVar14 = '\0';
      pcVar14 = pcVar14 + 1;
LAB_0003ecfe:
      if (param_4 == (char *)0x0) {
        uVar19 = 0;
      }
      else {
        uVar19 = (uVar22 ^ 1) & 1;
      }
    } while (uVar19 != 0);
    if (iVar11 == 6) {
      iVar11 = (**DAT_0003f1f4)(DAT_0003f214);
      piVar10[2] = iVar11;
      if (iVar11 == 0) goto LAB_0003eb3a;
    }
    else {
      if (iVar11 == 7) {
        uVar19 = 0;
      }
      else {
        uVar19 = (uVar22 ^ 1) & 1;
      }
      if (uVar19 != 0) goto LAB_0003eb3a;
    }
  }
  else {
    pcVar12 = (char *)(*Curl_cmalloc)(5000);
    if (pcVar12 == (char *)0x0) {
      (**DAT_0003f338)(piVar10);
      return (int *)0x0;
    }
    pcVar14 = strchr(param_4,0x3b);
    ppcVar6 = DAT_0003ef34;
    cVar1 = *param_4;
    if ((cVar1 != '\0') && (cVar1 == '\t' || cVar1 == ' ')) {
      pcVar24 = param_4 + 1;
      do {
        param_4 = pcVar24;
        cVar1 = *param_4;
        if (cVar1 == '\0') break;
        pcVar24 = param_4 + 1;
      } while (cVar1 == ' ' || cVar1 == '\t');
    }
    bVar3 = false;
LAB_0003ee54:
    do {
      *pcVar12 = '\0';
      local_428[0] = '\0';
      iVar11 = __isoc99_sscanf(param_4,DAT_0003ef30,local_428,pcVar12);
      if (0 < iVar11) {
        sVar15 = strlen(pcVar12);
        sVar16 = strlen(local_428);
        cVar1 = param_4[sVar16];
        if ((sVar16 != 0) && (cVar2 = param_4[sVar16 - 1], cVar2 == ' ' || cVar2 == '\t')) {
          sVar21 = sVar16;
          if (cVar2 != '\0') {
            do {
              sVar16 = sVar21 - 1;
              cVar2 = param_4[sVar21 - 2];
              if ((cVar2 == '\0') || (cVar2 != ' ' && cVar2 != '\t')) break;
              sVar21 = sVar16;
            } while (sVar16 != 0);
          }
          local_428[sVar16] = '\0';
        }
        if (sVar15 == 0) {
LAB_0003ef00:
          sVar15 = 0;
        }
        else {
          sVar16 = sVar15 - 1;
          if (pcVar12[sVar16] == '\t' || pcVar12[sVar16] == ' ') {
            pcVar24 = pcVar12 + sVar16;
            pcVar17 = pcVar12 + (sVar15 - 2);
            do {
              sVar15 = sVar16;
              *pcVar24 = '\0';
              if (sVar15 == 0) goto LAB_0003ef00;
              cVar2 = *pcVar17;
              pcVar24 = pcVar17;
              sVar16 = sVar15 - 1;
              pcVar17 = pcVar17 + -1;
            } while (cVar2 == ' ' || cVar2 == '\t');
          }
        }
        ppcVar7 = DAT_0003f1f4;
        cVar2 = *pcVar12;
        pcVar24 = pcVar12;
        if ((cVar2 == '\0') || (cVar2 != '\t' && cVar2 != ' ')) {
          if (piVar10[1] != 0) goto LAB_0003ef50;
LAB_0003f034:
          if (cVar1 != '=') goto LAB_0003ef50;
          iVar11 = (**DAT_0003f1f4)(local_428);
          pcVar23 = *ppcVar7;
          piVar10[1] = iVar11;
          iVar11 = (*pcVar23)(pcVar24);
          piVar10[2] = iVar11;
          if (piVar10[1] != 0) {
            if (iVar11 != 0) goto LAB_0003ef58;
            goto LAB_0003f230;
          }
LAB_0003f1e4:
          pcVar14 = (char *)piVar10[0xb];
          bVar3 = true;
          goto LAB_0003efce;
        }
        do {
          pcVar24 = pcVar24 + 1;
          cVar2 = *pcVar24;
          if (cVar2 == '\0') break;
        } while (cVar2 == ' ' || cVar2 == '\t');
        if (piVar10[1] == 0) goto LAB_0003f034;
LAB_0003ef50:
        if (sVar15 == 0) {
          iVar11 = Curl_raw_equal(DAT_0003f1f8,local_428);
          if (iVar11 == 0) {
            iVar11 = Curl_raw_equal(DAT_0003f210,local_428);
            if (iVar11 == 0) {
              if (cVar1 == '=') goto LAB_0003ef58;
            }
            else {
              *(undefined *)((int)piVar10 + 0x32) = 1;
            }
          }
          else {
            *(undefined *)(piVar10 + 0xc) = 1;
          }
          goto LAB_0003ef8a;
        }
LAB_0003ef58:
        iVar11 = Curl_raw_equal(DAT_0003f1f0,local_428);
        if (iVar11 != 0) {
          (**ppcVar6)(piVar10[3]);
          iVar11 = (**DAT_0003f1f4)(pcVar24);
          piVar10[3] = iVar11;
          if (iVar11 == 0) goto LAB_0003f1e4;
          iVar11 = sanitize_cookie_path();
          piVar10[4] = iVar11;
          if (iVar11 != 0) goto LAB_0003ef8a;
LAB_0003f230:
          pcVar14 = (char *)piVar10[0xb];
          bVar3 = true;
          goto LAB_0003efce;
        }
        iVar11 = Curl_raw_equal(DAT_0003f1fc,local_428);
        if (iVar11 == 0) {
          iVar11 = Curl_raw_equal(DAT_0003f204,local_428);
          if (iVar11 == 0) {
            iVar11 = Curl_raw_equal(DAT_0003f208,local_428);
            if (iVar11 == 0) {
              iVar11 = Curl_raw_equal(DAT_0003f334,local_428);
              if (iVar11 != 0) {
                (**ppcVar6)(piVar10[8]);
                iVar11 = (**DAT_0003f330)(pcVar24);
                piVar10[8] = iVar11;
                if (iVar11 == 0) goto LAB_0003f1e4;
              }
              goto LAB_0003ef8a;
            }
            (**ppcVar6)(piVar10[0xb]);
            iVar11 = (**DAT_0003f1f4)(pcVar24);
            piVar10[0xb] = iVar11;
            if (iVar11 == 0) {
              bVar3 = true;
              goto LAB_0003f12e;
            }
          }
          else {
            (**ppcVar6)(piVar10[10]);
            iVar11 = (**DAT_0003f330)(pcVar24);
            piVar10[10] = iVar11;
            if (iVar11 == 0) goto LAB_0003f230;
          }
        }
        else {
          if (*pcVar24 == '.') {
            pcVar24 = pcVar24 + 1;
          }
          if (param_5 == (char *)0x0) {
            iVar11 = isip(pcVar24);
            pcVar17 = strchr(pcVar24,0x2e);
            if (pcVar17 == (char *)0x0) {
              param_5 = DAT_0003f33c;
              goto LAB_0003f0b2;
            }
            (**ppcVar6)(piVar10[5]);
            iVar18 = (**DAT_0003f330)(pcVar24);
            piVar10[5] = iVar18;
            if (iVar18 == 0) goto LAB_0003f1e4;
            if (iVar11 != 0) goto LAB_0003ef8a;
LAB_0003f0dc:
            *(undefined *)(piVar10 + 9) = 1;
          }
          else {
            iVar11 = isip();
            pcVar17 = strchr(pcVar24,0x2e);
            if (pcVar17 == (char *)0x0) {
              param_5 = DAT_0003f200;
            }
LAB_0003f0b2:
            if (iVar11 == 0) {
              iVar11 = tailmatch();
              if (iVar11 != 0) {
                (**ppcVar6)(piVar10[5]);
                iVar11 = (**DAT_0003f1f4)(pcVar24);
                piVar10[5] = iVar11;
                if (iVar11 == 0) goto LAB_0003f230;
                goto LAB_0003f0dc;
              }
            }
            else {
              iVar11 = strcmp(pcVar24,param_5);
              if (iVar11 == 0) {
                (**ppcVar6)(piVar10[5]);
                iVar11 = (**DAT_0003f1f4)(pcVar24);
                piVar10[5] = iVar11;
                if (iVar11 != 0) goto LAB_0003ef8a;
                goto LAB_0003f1e4;
              }
            }
            bVar3 = true;
            Curl_infof(param_1,DAT_0003f20c,pcVar24);
          }
        }
      }
LAB_0003ef8a:
      if ((pcVar14 == (char *)0x0) || (*pcVar14 == '\0')) break;
      cVar1 = pcVar14[1];
      param_4 = pcVar14 + 1;
      if (cVar1 != '\0') {
        if (cVar1 == ' ' || cVar1 == '\t') {
          pcVar14 = pcVar14 + 2;
          do {
            param_4 = pcVar14;
            cVar1 = *param_4;
            if (cVar1 == '\0') goto LAB_0003efb8;
            pcVar14 = param_4 + 1;
          } while (cVar1 == ' ' || cVar1 == '\t');
        }
        pcVar14 = strchr(param_4,0x3b);
        if ((pcVar14 == (char *)0x0) &&
           (pcVar14 = (char *)__rawmemchr(param_4,0), pcVar14 == (char *)0x0)) break;
        goto LAB_0003ee54;
      }
LAB_0003efb8:
      pcVar14 = strchr(param_4,0x3b);
    } while (pcVar14 != (char *)0x0);
    pcVar14 = (char *)piVar10[0xb];
LAB_0003efce:
    if (pcVar14 == (char *)0x0) {
LAB_0003f12e:
      if (piVar10[8] != 0) {
        iVar11 = curl_getdate(piVar10[8],0);
        if (iVar11 == 0) {
          piVar10[6] = 1;
          piVar10[7] = 0;
        }
        else {
          piVar10[6] = iVar11;
          piVar10[7] = iVar11 >> 0x1f;
          if (iVar11 >> 0x1f < 0) {
            piVar10[6] = 0;
            piVar10[7] = 0;
          }
        }
      }
    }
    else {
      if (*pcVar14 == '\"') {
        pcVar14 = pcVar14 + 1;
      }
      lVar26 = strtoll(pcVar14,(char **)0x0,10);
      iVar18 = (int)((ulonglong)lVar26 >> 0x20);
      *(longlong *)(piVar10 + 6) = lVar26;
      iVar11 = 0x7fffffff - (tVar9 >> 0x1f);
      bVar25 = -tVar9 - 1U < (uint)lVar26;
      if ((int)((iVar11 - iVar18) - (uint)bVar25) < 0 ==
          (SBORROW4(iVar11,iVar18) != SBORROW4(iVar11 - iVar18,(uint)bVar25))) {
        *(longlong *)(piVar10 + 6) = lVar26 + tVar9;
      }
      else {
        piVar10[6] = -1;
        piVar10[7] = 0x7fffffff;
      }
    }
    if (bVar3) goto LAB_0003eb32;
    if ((piVar10[5] == 0) && (param_5 != (char *)0x0)) {
      iVar11 = (**DAT_0003f330)(param_5);
      piVar10[5] = iVar11;
      if (iVar11 == 0) goto LAB_0003eb32;
    }
    if ((piVar10[3] == 0) && (param_6 != (char *)0x0)) {
      pcVar14 = strchr(param_6,0x3f);
      if (pcVar14 == (char *)0x0) {
        pcVar14 = strrchr(param_6,0x2f);
      }
      else {
        pcVar14 = (char *)Curl_memrchr(param_6,0x2f,(int)pcVar14 - (int)param_6);
      }
      if (pcVar14 != (char *)0x0) {
        __dest = (void *)(*Curl_cmalloc)(pcVar14 + (2 - (int)param_6));
        piVar10[3] = (int)__dest;
        if (__dest != (void *)0x0) {
          memcpy(__dest,param_6,(size_t)(pcVar14 + (1 - (int)param_6)));
          (pcVar14 + (1 - (int)param_6))[piVar10[3]] = '\0';
          iVar11 = sanitize_cookie_path(piVar10[3]);
          piVar10[4] = iVar11;
          if (iVar11 != 0) goto LAB_0003f022;
        }
LAB_0003eb32:
        (**ppcVar6)(pcVar12);
        goto LAB_0003eb3a;
      }
    }
LAB_0003f022:
    (**ppcVar6)(pcVar12);
    uVar22 = piVar10[1];
  }
  if (uVar22 != 0) {
    if (((*(char *)(param_2 + 2) == '\0') && (*(char *)(param_2 + 4) != '\0')) &&
       ((piVar10[6] | piVar10[7]) == 0)) {
      freecookie(piVar10);
      return (int *)0x0;
    }
    *(char *)((int)piVar10 + 0x31) = *(char *)(param_2 + 2);
    remove_expired(param_2);
    piVar8 = *param_2;
    piVar5 = *param_2;
    do {
      piVar4 = piVar8;
      if (piVar4 == (int *)0x0) {
        if (*(char *)(param_2 + 2) != '\0') {
          Curl_infof(param_1,DAT_0003eb50,DAT_0003eb54,piVar10[1],piVar10[2],piVar10[5],piVar10[3]);
        }
        if (piVar5 == (int *)0x0) {
          *param_2 = piVar10;
        }
        else {
          *piVar5 = (int)piVar10;
        }
        param_2[3] = (int *)((int)param_2[3] + 1);
        return piVar10;
      }
      iVar11 = Curl_raw_equal(piVar4[1],piVar10[1]);
      if (iVar11 != 0) {
        if (piVar4[5] == 0) {
          if (piVar10[5] == 0) goto LAB_0003ebfe;
        }
        else if ((piVar10[5] != 0) && (iVar11 = Curl_raw_equal(), iVar11 != 0)) {
LAB_0003ebfe:
          if (piVar4[4] == 0) {
            if (piVar10[4] == 0) goto LAB_0003ec18;
          }
          else if ((piVar10[4] != 0) && (iVar11 = Curl_raw_equal(), iVar11 != 0)) {
LAB_0003ec18:
            ppcVar6 = DAT_0003ef34;
            if ((*(char *)((int)piVar10 + 0x31) == '\0') && (*(char *)((int)piVar4 + 0x31) != '\0'))
            {
              freecookie(piVar10);
              return (int *)0x0;
            }
            uVar13 = piVar4[1];
            *piVar10 = *piVar4;
            (**ppcVar6)(uVar13);
            (**ppcVar6)(piVar4[2]);
            (**ppcVar6)(piVar4[5]);
            (**ppcVar6)(piVar4[3]);
            (**ppcVar6)(piVar4[4]);
            (**ppcVar6)(piVar4[8]);
            (**ppcVar6)(piVar4[10]);
            (**ppcVar6)(piVar4[0xb]);
            iVar11 = piVar10[1];
            iVar18 = piVar10[2];
            iVar20 = piVar10[3];
            pcVar23 = *ppcVar6;
            *piVar4 = *piVar10;
            piVar4[1] = iVar11;
            piVar4[2] = iVar18;
            piVar4[3] = iVar20;
            iVar11 = piVar10[5];
            iVar18 = piVar10[6];
            iVar20 = piVar10[7];
            piVar4[4] = piVar10[4];
            piVar4[5] = iVar11;
            piVar4[6] = iVar18;
            piVar4[7] = iVar20;
            iVar11 = piVar10[9];
            iVar18 = piVar10[10];
            iVar20 = piVar10[0xb];
            piVar4[8] = piVar10[8];
            piVar4[9] = iVar11;
            piVar4[10] = iVar18;
            piVar4[0xb] = iVar20;
            iVar11 = piVar10[0xd];
            piVar4[0xc] = piVar10[0xc];
            piVar4[0xd] = iVar11;
            (*pcVar23)(piVar10);
            piVar10 = piVar4;
            do {
              piVar10 = (int *)*piVar10;
            } while (piVar10 != (int *)0x0);
            if (*(char *)(param_2 + 2) == '\0') {
              return piVar4;
            }
            Curl_infof(param_1,DAT_0003ef1c,DAT_0003ef20,piVar4[1],piVar4[2],piVar4[5],piVar4[3]);
            return piVar4;
          }
        }
      }
      piVar8 = (int *)*piVar4;
      piVar5 = piVar4;
    } while( true );
  }
LAB_0003eb3a:
  freecookie(piVar10);
  return (int *)0x0;
}

