
/* WARNING: Type propagation algorithm not settling */

undefined4 *
Curl_cookie_add(undefined4 param_1,int *param_2,int param_3,char *param_4,char *param_5,
               char *param_6)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  int *piVar4;
  code *pcVar5;
  int *piVar6;
  time_t tVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  void *__dest;
  undefined4 uVar11;
  int iVar12;
  char *pcVar13;
  size_t sVar14;
  size_t sVar15;
  char *pcVar16;
  int iVar17;
  undefined4 uVar18;
  uint uVar19;
  undefined4 uVar20;
  int *piVar21;
  size_t sVar22;
  uint uVar23;
  char *pcVar24;
  bool bVar25;
  longlong lVar26;
  char local_428 [1028];
  
  tVar7 = time((time_t *)0x0);
  puVar8 = (undefined4 *)(*Curl_ccalloc)(1,0x38);
  if (puVar8 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_3 == 0) {
    iVar9 = strncmp(param_4,"#HttpOnly_",10);
    if (iVar9 == 0) {
      param_4 = param_4 + 10;
      *(undefined1 *)((int)puVar8 + 0x32) = 1;
    }
    if (*param_4 == '#') {
      (*Curl_cfree)(puVar8);
      return (undefined4 *)0x0;
    }
    pcVar10 = strchr(param_4,0xd);
    if (pcVar10 != (char *)0x0) {
      *pcVar10 = '\0';
    }
    pcVar10 = strchr(param_4,10);
    if (pcVar10 != (char *)0x0) {
      *pcVar10 = '\0';
    }
    cVar1 = *param_4;
    while (cVar1 == '\t') {
      param_4 = param_4 + 1;
      cVar1 = *param_4;
    }
    pcVar10 = param_4 + 1;
    if (cVar1 != '\0') {
      do {
        pcVar13 = pcVar10;
        if (*pcVar13 == '\0') goto LAB_0003ea58;
        pcVar10 = pcVar13 + 1;
      } while (*pcVar13 != '\t');
      *pcVar13 = '\0';
      pcVar13 = pcVar13 + 1;
LAB_0003ea58:
      if (param_4 == (char *)0x0) goto LAB_0003eb3a;
      iVar9 = 0;
      do {
        switch(iVar9) {
        case 0:
          if (*param_4 == '.') {
            param_4 = param_4 + 1;
          }
          iVar12 = (*Curl_cstrdup)(param_4);
          iVar9 = 1;
          puVar8[5] = iVar12;
          uVar23 = 1;
          iVar17 = 1;
          if (iVar12 != 0) goto LAB_0003ed9e;
          break;
        case 1:
          iVar9 = Curl_raw_equal(param_4,&DAT_00135460);
          if (iVar9 != 0) {
            iVar9 = 1;
          }
          *(char *)(puVar8 + 9) = (char)iVar9;
          iVar17 = 2;
LAB_0003ed9e:
          iVar9 = iVar17;
          uVar23 = 0;
          break;
        case 2:
          iVar9 = strcmp("TRUE",param_4);
          if ((iVar9 == 0) || (iVar9 = strcmp("FALSE",param_4), iVar9 == 0)) {
            uVar19 = (*Curl_cstrdup)(&DAT_00135588);
            uVar23 = 1 - uVar19;
            puVar8[3] = uVar19;
            if (1 < uVar19) {
              uVar23 = 0;
            }
            iVar9 = (*Curl_cstrdup)(&DAT_00135588);
            if (iVar9 == 0) {
              uVar23 = 1;
            }
            puVar8[4] = iVar9;
            goto LAB_0003ed32;
          }
          iVar9 = (*Curl_cstrdup)(param_4);
          puVar8[3] = iVar9;
          if (iVar9 == 0) {
            iVar9 = 3;
            uVar23 = 1;
          }
          else {
            uVar19 = sanitize_cookie_path();
            uVar23 = 1 - uVar19;
            puVar8[4] = uVar19;
            if (1 < uVar19) {
              uVar23 = 0;
            }
            iVar9 = 3;
          }
          break;
        case 3:
          uVar23 = 0;
LAB_0003ed32:
          iVar17 = Curl_raw_equal(param_4,&DAT_00135460);
          iVar9 = 4;
          if (iVar17 != 0) {
            iVar17 = 1;
          }
          *(char *)(puVar8 + 0xc) = (char)iVar17;
          break;
        case 4:
          uVar23 = 0;
          lVar26 = strtoll(param_4,(char **)0x0,10);
          iVar9 = 5;
          *(longlong *)(puVar8 + 6) = lVar26;
          break;
        case 5:
          uVar19 = (*Curl_cstrdup)(param_4);
          puVar8[1] = uVar19;
          uVar23 = 1 - uVar19;
          cVar1 = *pcVar13;
          if (1 < uVar19) {
            uVar23 = 0;
          }
          iVar9 = 6;
          param_4 = pcVar13;
          goto joined_r0x0003ecdc;
        case 6:
          uVar19 = (*Curl_cstrdup)(param_4);
          uVar23 = 1 - uVar19;
          iVar9 = 7;
          if (1 < uVar19) {
            uVar23 = 0;
          }
          puVar8[2] = uVar19;
          break;
        default:
          iVar9 = iVar9 + 1;
          uVar23 = 0;
        }
        cVar1 = *pcVar13;
        param_4 = pcVar13;
joined_r0x0003ecdc:
        while (cVar1 == '\t') {
          cVar1 = param_4[1];
          param_4 = param_4 + 1;
        }
        if (cVar1 == '\0') break;
        pcVar10 = param_4 + 1;
        do {
          pcVar13 = pcVar10;
          if (*pcVar13 == '\0') goto LAB_0003ecfe;
          pcVar10 = pcVar13 + 1;
        } while (*pcVar13 != '\t');
        *pcVar13 = '\0';
        pcVar13 = pcVar13 + 1;
LAB_0003ecfe:
        if (param_4 == (char *)0x0) {
          uVar19 = 0;
        }
        else {
          uVar19 = (uVar23 ^ 1) & 1;
        }
      } while (uVar19 != 0);
      if (iVar9 == 6) {
        iVar9 = (*Curl_cstrdup)(&DAT_0013a6fc);
        puVar8[2] = iVar9;
        if (iVar9 == 0) goto LAB_0003eb3a;
      }
      else {
        if (iVar9 == 7) {
          uVar19 = 0;
        }
        else {
          uVar19 = (uVar23 ^ 1) & 1;
        }
        if (uVar19 != 0) goto LAB_0003eb3a;
      }
      if (uVar23 != 0) goto LAB_0003eb3a;
      goto LAB_0003ebaa;
    }
    goto LAB_0003eb3a;
  }
  pcVar10 = (char *)(*Curl_cmalloc)(5000);
  if (pcVar10 == (char *)0x0) {
    (*Curl_cfree)(puVar8);
    return (undefined4 *)0x0;
  }
  pcVar13 = strchr(param_4,0x3b);
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
    *pcVar10 = '\0';
    local_428[0] = '\0';
    iVar9 = __isoc99_sscanf(param_4,&DAT_00135970,local_428,pcVar10);
    if (0 < iVar9) {
      sVar14 = strlen(pcVar10);
      sVar15 = strlen(local_428);
      cVar1 = param_4[sVar15];
      if ((sVar15 != 0) && (cVar2 = param_4[sVar15 - 1], cVar2 == ' ' || cVar2 == '\t')) {
        sVar22 = sVar15;
        if (cVar2 != '\0') {
          do {
            sVar15 = sVar22 - 1;
            cVar2 = param_4[sVar22 - 2];
            if ((cVar2 == '\0') || (cVar2 != ' ' && cVar2 != '\t')) break;
            sVar22 = sVar15;
          } while (sVar15 != 0);
        }
        local_428[sVar15] = '\0';
      }
      if (sVar14 == 0) {
LAB_0003ef00:
        sVar14 = 0;
      }
      else {
        sVar15 = sVar14 - 1;
        if (pcVar10[sVar15] == '\t' || pcVar10[sVar15] == ' ') {
          pcVar24 = pcVar10 + sVar15;
          pcVar16 = pcVar10 + (sVar14 - 2);
          do {
            sVar14 = sVar15;
            *pcVar24 = '\0';
            if (sVar14 == 0) goto LAB_0003ef00;
            cVar2 = *pcVar16;
            pcVar24 = pcVar16;
            sVar15 = sVar14 - 1;
            pcVar16 = pcVar16 + -1;
          } while (cVar2 == ' ' || cVar2 == '\t');
        }
      }
      cVar2 = *pcVar10;
      pcVar24 = pcVar10;
      if ((cVar2 != '\0') && (cVar2 == '\t' || cVar2 == ' ')) {
        do {
          pcVar24 = pcVar24 + 1;
          cVar2 = *pcVar24;
          if (cVar2 == '\0') break;
        } while (cVar2 == ' ' || cVar2 == '\t');
        if (puVar8[1] != 0) goto LAB_0003ef50;
LAB_0003f034:
        if (cVar1 != '=') goto LAB_0003ef50;
        uVar11 = (*Curl_cstrdup)(local_428);
        pcVar5 = Curl_cstrdup;
        puVar8[1] = uVar11;
        iVar9 = (*pcVar5)(pcVar24);
        puVar8[2] = iVar9;
        if (puVar8[1] != 0) {
          if (iVar9 != 0) goto LAB_0003ef58;
          goto LAB_0003f230;
        }
LAB_0003f1e4:
        pcVar13 = (char *)puVar8[0xb];
        bVar3 = true;
        goto LAB_0003efce;
      }
      if (puVar8[1] == 0) goto LAB_0003f034;
LAB_0003ef50:
      if (sVar14 == 0) {
        iVar9 = Curl_raw_equal("secure",local_428);
        if (iVar9 == 0) {
          iVar9 = Curl_raw_equal("httponly",local_428);
          if (iVar9 == 0) {
            if (cVar1 == '=') goto LAB_0003ef58;
          }
          else {
            *(undefined1 *)((int)puVar8 + 0x32) = 1;
          }
        }
        else {
          *(undefined1 *)(puVar8 + 0xc) = 1;
        }
        goto LAB_0003ef8a;
      }
LAB_0003ef58:
      iVar9 = Curl_raw_equal("path",local_428);
      if (iVar9 != 0) {
        (*Curl_cfree)(puVar8[3]);
        iVar9 = (*Curl_cstrdup)(pcVar24);
        puVar8[3] = iVar9;
        if (iVar9 == 0) goto LAB_0003f1e4;
        iVar9 = sanitize_cookie_path();
        puVar8[4] = iVar9;
        if (iVar9 != 0) goto LAB_0003ef8a;
LAB_0003f230:
        pcVar13 = (char *)puVar8[0xb];
        bVar3 = true;
        goto LAB_0003efce;
      }
      iVar9 = Curl_raw_equal("domain",local_428);
      if (iVar9 == 0) {
        iVar9 = Curl_raw_equal("version",local_428);
        if (iVar9 == 0) {
          iVar9 = Curl_raw_equal("max-age",local_428);
          if (iVar9 == 0) {
            iVar9 = Curl_raw_equal("expires",local_428);
            if (iVar9 != 0) {
              (*Curl_cfree)(puVar8[8]);
              iVar9 = (*Curl_cstrdup)(pcVar24);
              puVar8[8] = iVar9;
              if (iVar9 == 0) goto LAB_0003f1e4;
            }
            goto LAB_0003ef8a;
          }
          (*Curl_cfree)(puVar8[0xb]);
          iVar9 = (*Curl_cstrdup)(pcVar24);
          puVar8[0xb] = iVar9;
          if (iVar9 == 0) {
            bVar3 = true;
            goto LAB_0003f12e;
          }
        }
        else {
          (*Curl_cfree)(puVar8[10]);
          iVar9 = (*Curl_cstrdup)(pcVar24);
          puVar8[10] = iVar9;
          if (iVar9 == 0) goto LAB_0003f230;
        }
      }
      else {
        if (*pcVar24 == '.') {
          pcVar24 = pcVar24 + 1;
        }
        if (param_5 == (char *)0x0) {
          iVar9 = isip(pcVar24);
          pcVar16 = strchr(pcVar24,0x2e);
          if (pcVar16 == (char *)0x0) {
            param_5 = ":";
            goto LAB_0003f0b2;
          }
          (*Curl_cfree)(puVar8[5]);
          iVar17 = (*Curl_cstrdup)(pcVar24);
          puVar8[5] = iVar17;
          if (iVar17 == 0) goto LAB_0003f1e4;
          if (iVar9 != 0) goto LAB_0003ef8a;
LAB_0003f0dc:
          *(undefined1 *)(puVar8 + 9) = 1;
        }
        else {
          iVar9 = isip();
          pcVar16 = strchr(pcVar24,0x2e);
          if (pcVar16 == (char *)0x0) {
            param_5 = ":";
          }
LAB_0003f0b2:
          if (iVar9 == 0) {
            iVar9 = tailmatch();
            if (iVar9 != 0) {
              (*Curl_cfree)(puVar8[5]);
              iVar9 = (*Curl_cstrdup)(pcVar24);
              puVar8[5] = iVar9;
              if (iVar9 == 0) goto LAB_0003f230;
              goto LAB_0003f0dc;
            }
          }
          else {
            iVar9 = strcmp(pcVar24,param_5);
            if (iVar9 == 0) {
              (*Curl_cfree)(puVar8[5]);
              iVar9 = (*Curl_cstrdup)(pcVar24);
              puVar8[5] = iVar9;
              if (iVar9 != 0) goto LAB_0003ef8a;
              goto LAB_0003f1e4;
            }
          }
          bVar3 = true;
          Curl_infof(param_1,"skipped cookie with bad tailmatch domain: %s\n",pcVar24);
        }
      }
    }
LAB_0003ef8a:
    if ((pcVar13 == (char *)0x0) || (*pcVar13 == '\0')) break;
    cVar1 = pcVar13[1];
    param_4 = pcVar13 + 1;
    if (cVar1 != '\0') {
      if (cVar1 == ' ' || cVar1 == '\t') {
        pcVar13 = pcVar13 + 2;
        do {
          param_4 = pcVar13;
          cVar1 = *param_4;
          if (cVar1 == '\0') goto LAB_0003efb8;
          pcVar13 = param_4 + 1;
        } while (cVar1 == ' ' || cVar1 == '\t');
      }
      pcVar13 = strchr(param_4,0x3b);
      if ((pcVar13 == (char *)0x0) &&
         (pcVar13 = (char *)__rawmemchr(param_4,0), pcVar13 == (char *)0x0)) break;
      goto LAB_0003ee54;
    }
LAB_0003efb8:
    pcVar13 = strchr(param_4,0x3b);
  } while (pcVar13 != (char *)0x0);
  pcVar13 = (char *)puVar8[0xb];
LAB_0003efce:
  if (pcVar13 == (char *)0x0) {
LAB_0003f12e:
    if (puVar8[8] != 0) {
      iVar9 = curl_getdate(puVar8[8],0);
      if (iVar9 == 0) {
        puVar8[6] = 1;
        puVar8[7] = 0;
      }
      else {
        puVar8[6] = iVar9;
        puVar8[7] = iVar9 >> 0x1f;
        if (iVar9 >> 0x1f < 0) {
          puVar8[6] = 0;
          puVar8[7] = 0;
        }
      }
    }
  }
  else {
    if (*pcVar13 == '\"') {
      pcVar13 = pcVar13 + 1;
    }
    lVar26 = strtoll(pcVar13,(char **)0x0,10);
    iVar17 = (int)((ulonglong)lVar26 >> 0x20);
    *(longlong *)(puVar8 + 6) = lVar26;
    iVar9 = 0x7fffffff - (tVar7 >> 0x1f);
    bVar25 = -tVar7 - 1U < (uint)lVar26;
    if ((int)((iVar9 - iVar17) - (uint)bVar25) < 0 ==
        (SBORROW4(iVar9,iVar17) != SBORROW4(iVar9 - iVar17,(uint)bVar25))) {
      *(longlong *)(puVar8 + 6) = lVar26 + tVar7;
    }
    else {
      puVar8[6] = 0xffffffff;
      puVar8[7] = 0x7fffffff;
    }
  }
  if (bVar3) goto LAB_0003eb32;
  if ((puVar8[5] == 0) && (param_5 != (char *)0x0)) {
    iVar9 = (*Curl_cstrdup)(param_5);
    puVar8[5] = iVar9;
    if (iVar9 == 0) goto LAB_0003eb32;
  }
  if ((puVar8[3] == 0) && (param_6 != (char *)0x0)) {
    pcVar13 = strchr(param_6,0x3f);
    if (pcVar13 == (char *)0x0) {
      pcVar13 = strrchr(param_6,0x2f);
    }
    else {
      pcVar13 = (char *)Curl_memrchr(param_6,0x2f,(int)pcVar13 - (int)param_6);
    }
    if (pcVar13 != (char *)0x0) {
      __dest = (void *)(*Curl_cmalloc)(pcVar13 + (2 - (int)param_6));
      puVar8[3] = __dest;
      if (__dest != (void *)0x0) {
        memcpy(__dest,param_6,(size_t)(pcVar13 + (1 - (int)param_6)));
        (pcVar13 + (1 - (int)param_6))[puVar8[3]] = '\0';
        iVar9 = sanitize_cookie_path(puVar8[3]);
        puVar8[4] = iVar9;
        if (iVar9 != 0) goto LAB_0003f022;
      }
LAB_0003eb32:
      (*Curl_cfree)(pcVar10);
      goto LAB_0003eb3a;
    }
  }
LAB_0003f022:
  (*Curl_cfree)(pcVar10);
  if (puVar8[1] != 0) {
LAB_0003ebaa:
    if ((((char)param_2[2] == '\0') && ((char)param_2[4] != '\0')) &&
       (puVar8[6] == 0 && puVar8[7] == 0)) {
      freecookie(puVar8);
      return (undefined4 *)0x0;
    }
    *(char *)((int)puVar8 + 0x31) = (char)param_2[2];
    remove_expired(param_2);
    piVar6 = (int *)*param_2;
    piVar21 = (int *)*param_2;
    do {
      piVar4 = piVar6;
      if (piVar4 == (int *)0x0) {
        if ((char)param_2[2] != '\0') {
          Curl_infof(param_1,"%s cookie %s=\"%s\" for domain %s, path %s, expire %lld\n","Added",
                     puVar8[1],puVar8[2],puVar8[5],puVar8[3]);
        }
        if (piVar21 == (int *)0x0) {
          *param_2 = (int)puVar8;
        }
        else {
          *piVar21 = (int)puVar8;
        }
        param_2[3] = param_2[3] + 1;
        return puVar8;
      }
      iVar9 = Curl_raw_equal(piVar4[1],puVar8[1]);
      if (iVar9 != 0) {
        if (piVar4[5] == 0) {
          if (puVar8[5] == 0) goto LAB_0003ebfe;
        }
        else if ((puVar8[5] != 0) && (iVar9 = Curl_raw_equal(), iVar9 != 0)) {
LAB_0003ebfe:
          if (piVar4[4] == 0) {
            if (puVar8[4] == 0) goto LAB_0003ec18;
          }
          else if ((puVar8[4] != 0) && (iVar9 = Curl_raw_equal(), iVar9 != 0)) {
LAB_0003ec18:
            if ((*(char *)((int)puVar8 + 0x31) == '\0') && (*(char *)((int)piVar4 + 0x31) != '\0'))
            {
              freecookie(puVar8);
              return (undefined4 *)0x0;
            }
            uVar11 = piVar4[1];
            *puVar8 = *piVar4;
            (*Curl_cfree)(uVar11);
            (*Curl_cfree)(piVar4[2]);
            (*Curl_cfree)(piVar4[5]);
            (*Curl_cfree)(piVar4[3]);
            (*Curl_cfree)(piVar4[4]);
            (*Curl_cfree)(piVar4[8]);
            (*Curl_cfree)(piVar4[10]);
            (*Curl_cfree)(piVar4[0xb]);
            pcVar5 = Curl_cfree;
            uVar11 = puVar8[1];
            uVar18 = puVar8[2];
            uVar20 = puVar8[3];
            *piVar4 = *puVar8;
            piVar4[1] = uVar11;
            piVar4[2] = uVar18;
            piVar4[3] = uVar20;
            uVar11 = puVar8[5];
            uVar18 = puVar8[6];
            uVar20 = puVar8[7];
            piVar4[4] = puVar8[4];
            piVar4[5] = uVar11;
            piVar4[6] = uVar18;
            piVar4[7] = uVar20;
            uVar11 = puVar8[9];
            uVar18 = puVar8[10];
            uVar20 = puVar8[0xb];
            piVar4[8] = puVar8[8];
            piVar4[9] = uVar11;
            piVar4[10] = uVar18;
            piVar4[0xb] = uVar20;
            uVar11 = puVar8[0xd];
            piVar4[0xc] = puVar8[0xc];
            piVar4[0xd] = uVar11;
            (*pcVar5)(puVar8);
            piVar21 = piVar4;
            do {
              piVar21 = (int *)*piVar21;
            } while (piVar21 != (int *)0x0);
            if ((char)param_2[2] == '\0') {
              return piVar4;
            }
            Curl_infof(param_1,"%s cookie %s=\"%s\" for domain %s, path %s, expire %lld\n",
                       "Replaced",piVar4[1],piVar4[2],piVar4[5],piVar4[3]);
            return piVar4;
          }
        }
      }
      piVar6 = (int *)*piVar4;
      piVar21 = piVar4;
    } while( true );
  }
LAB_0003eb3a:
  freecookie(puVar8);
  return (undefined4 *)0x0;
}

