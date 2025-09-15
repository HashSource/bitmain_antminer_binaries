
/* WARNING: Type propagation algorithm not settling */

uint Curl_http(int *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  size_t sVar8;
  size_t __n;
  size_t sVar9;
  int *piVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 extraout_r1;
  undefined1 *puVar13;
  int iVar14;
  undefined1 *puVar15;
  uint uVar16;
  undefined4 uVar17;
  size_t __n_00;
  undefined *puVar18;
  uint uVar19;
  int iVar20;
  undefined *puVar21;
  int *piVar22;
  uint uVar23;
  uint unaff_r5;
  int *piVar24;
  undefined1 *puVar25;
  undefined4 uVar26;
  int iVar27;
  char *__haystack;
  undefined1 *puVar28;
  int iVar29;
  uint uVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  bool bVar33;
  undefined8 uVar34;
  undefined *local_64;
  undefined1 *local_58;
  char *local_54;
  int local_50;
  undefined1 *local_4c;
  uint local_38;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined1 local_2c;
  
  iVar14 = param_1[0x4f];
  iVar29 = *param_1;
  iVar20 = param_1[0x26];
  if (0x13 < iVar14) {
    unaff_r5 = 1;
  }
  uVar30 = *(uint *)(iVar29 + 0x278);
  __haystack = *(char **)(iVar29 + 0x868c);
  local_34 = (undefined1  [4])0x0;
  local_30 = 0;
  local_2c = 0;
  *param_2 = 1;
  if (0x13 < iVar14) {
    return unaff_r5;
  }
  iVar14 = param_1[0x11d];
  bVar33 = iVar14 == 3;
  if (bVar33) {
    iVar14 = 0x14;
    unaff_r5 = 1;
  }
  if (bVar33) {
    param_1[0x4f] = iVar14;
    return unaff_r5;
  }
  piVar24 = *(int **)(iVar29 + 0x14c);
  if (*(char *)(iVar29 + 0x85a8) == '\0') {
    (*Curl_cfree)(*(undefined4 *)(iVar29 + 0x85ac));
    iVar14 = (*Curl_cstrdup)(param_1[0x26]);
    *(int *)(iVar29 + 0x85ac) = iVar14;
    if (iVar14 == 0) {
      return 0x1b;
    }
  }
  iVar14 = param_1[0x86];
  piVar24[8] = 0;
  piVar24[9] = 0;
  piVar24[10] = 0;
  piVar24[0xb] = 0;
  if (((*(uint *)(iVar14 + 0x3c) & 7) != 0) && (*(char *)(iVar29 + 0x309) != '\0')) {
    uVar30 = 4;
  }
  local_64 = *(undefined **)(iVar29 + 0x350);
  if (local_64 == (undefined *)0x0) {
    if (*(char *)(iVar29 + 0x307) == '\0') {
      if (uVar30 - 2 < 4) {
        local_64 = *(undefined **)(&CSWTCH_117 + (uVar30 - 2) * 4);
      }
      else {
        local_64 = &DAT_00135e90;
      }
    }
    else {
      local_64 = &DAT_00135e88;
    }
  }
  iVar14 = Curl_checkheaders(param_1,"User-Agent:");
  if (iVar14 != 0) {
    (*Curl_cfree)(param_1[0x8c]);
    param_1[0x8c] = 0;
  }
  uVar3 = Curl_http_output_auth(param_1,local_64,__haystack,0);
  if (uVar3 != 0) {
    return uVar3;
  }
  if (((*(char *)(iVar29 + 0x862d) == '\0') && (*(char *)(iVar29 + 0x863d) == '\0')) ||
     ((uVar30 & 0xfffffffb) == 1)) {
    *(undefined1 *)((int)param_1 + 0x1fb) = 0;
  }
  else {
    *(undefined1 *)((int)param_1 + 0x1fb) = 1;
  }
  (*Curl_cfree)(param_1[0x90]);
  iVar14 = *(int *)(iVar29 + 0x458);
  param_1[0x90] = 0;
  if ((iVar14 == 0) || (iVar14 = Curl_checkheaders(param_1,"Referer:"), iVar14 != 0)) {
    param_1[0x90] = 0;
  }
  else {
    iVar14 = curl_maprintf("Referer: %s\r\n",*(undefined4 *)(iVar29 + 0x458));
    param_1[0x90] = iVar14;
    if (iVar14 == 0) {
      return 0x1b;
    }
  }
  if ((*(int *)(iVar29 + 0x348) == 0) ||
     (iVar14 = Curl_checkheaders(param_1,"Cookie:"), iVar14 != 0)) {
    local_50 = 0;
  }
  else {
    local_50 = *(int *)(iVar29 + 0x348);
  }
  iVar14 = Curl_checkheaders(param_1,"Accept-Encoding:");
  if ((iVar14 == 0) && (*(int *)(iVar29 + 0x35c) != 0)) {
    (*Curl_cfree)(param_1[0x8d]);
    param_1[0x8d] = 0;
    iVar14 = curl_maprintf("Accept-Encoding: %s\r\n",*(undefined4 *)(iVar29 + 0x35c));
    param_1[0x8d] = iVar14;
    if (iVar14 == 0) {
      return 0x1b;
    }
  }
  iVar14 = Curl_checkheaders(param_1,&DAT_00135f08);
  if ((iVar14 == 0) && (*(char *)(iVar29 + 0x302) != '\0')) {
    iVar14 = Curl_checkheaders(param_1,"Connection:");
    (*Curl_cfree)(param_1[0x94]);
    param_1[0x94] = 0;
    if (iVar14 == 0) {
      iVar14 = (*Curl_cstrdup)("Connection: TE\r\nTE: gzip\r\n");
    }
    else {
      iVar14 = curl_maprintf("%s, TE\r\nTE: gzip\r\n");
    }
    param_1[0x94] = iVar14;
    if (iVar14 == 0) {
      return 0x1b;
    }
  }
  if (param_1[0x4f] == 0x14) {
LAB_00041452:
    local_54 = "";
  }
  else {
    iVar14 = Curl_checkheaders(param_1,"Transfer-Encoding:");
    if (iVar14 == 0) {
      if ((((*(uint *)(param_1[0x86] + 0x3c) & 3) == 0) || (*(char *)(iVar29 + 0x309) == '\0')) ||
         (*(int *)(iVar29 + 0x86b4) != -1 || *(int *)(iVar29 + 0x86b0) != -1)) {
        *(undefined1 *)(iVar29 + 0x149) = 0;
        local_54 = "";
      }
      else {
        if (*(char *)((int)param_1 + 0x1fb) == '\0') {
          if (((*(int *)(iVar29 + 0x8678) == 10) || (param_1[0x4f] == 10)) ||
             ((iVar14 = *(int *)(iVar29 + 0x27c), iVar14 == 1 || ((iVar14 < 2 && (iVar14 != 0))))))
          {
            Curl_failf(iVar29,"Chunky upload is not supported by HTTP 1.0");
            return 0x19;
          }
          *(undefined1 *)(iVar29 + 0x149) = 1;
        }
        else if (*(char *)(iVar29 + 0x149) == '\0') goto LAB_00041452;
        local_54 = "Transfer-Encoding: chunked\r\n";
      }
    }
    else {
      uVar1 = Curl_compareheader(iVar14,"Transfer-Encoding:","chunked");
      local_54 = "";
      *(undefined1 *)(iVar29 + 0x149) = uVar1;
    }
  }
  (*Curl_cfree)(param_1[0x91]);
  param_1[0x91] = 0;
  pcVar4 = (char *)Curl_checkheaders(param_1,"Host:");
  if ((pcVar4 == (char *)0x0) ||
     ((*(char *)(iVar29 + 0x85a8) != '\0' &&
      (iVar14 = Curl_raw_equal(*(undefined4 *)(iVar29 + 0x85ac),param_1[0x26]), iVar14 == 0)))) {
    iVar14 = param_1[0x2d];
    if (((*(int *)(param_1[0x87] + 0x3c) << 0x1e < 0) && (iVar14 == 0x1bb)) ||
       ((*(int *)(param_1[0x87] + 0x3c) << 0x1f < 0 && (iVar14 == 0x50)))) {
      if (*(char *)((int)param_1 + 499) == '\0') {
        puVar21 = &DAT_0013a6fc;
        puVar18 = &DAT_0013a6fc;
      }
      else {
        puVar21 = &DAT_00135eb4;
        puVar18 = &DAT_00135988;
      }
      iVar14 = curl_maprintf("Host: %s%s%s\r\n",puVar21,iVar20,puVar18);
      param_1[0x91] = iVar14;
    }
    else {
      if (*(char *)((int)param_1 + 499) == '\0') {
        puVar18 = &DAT_0013a6fc;
        puVar21 = puVar18;
      }
      else {
        puVar18 = &DAT_00135eb4;
        puVar21 = &DAT_00135988;
      }
      iVar14 = curl_maprintf("Host: %s%s%s:%hu\r\n",puVar18,iVar20,puVar21,iVar14);
      param_1[0x91] = iVar14;
    }
joined_r0x0004102e:
    if (iVar14 == 0) {
      return 0x1b;
    }
  }
  else {
    pcVar5 = (char *)Curl_copy_header_value(pcVar4);
    if (pcVar5 == (char *)0x0) {
      return 0x1b;
    }
    if (*pcVar5 == '\0') {
      (*Curl_cfree)();
    }
    else {
      if (*pcVar5 == '[') {
        sVar8 = strlen(pcVar5);
        memmove(pcVar5,pcVar5 + 1,sVar8 - 1);
        pcVar6 = strchr(pcVar5,0x5d);
      }
      else {
        pcVar6 = strchr(pcVar5,0x3a);
      }
      if (pcVar6 != (char *)0x0) {
        *pcVar6 = '\0';
      }
      (*Curl_cfree)(param_1[0x92]);
      param_1[0x92] = (int)pcVar5;
    }
    iVar14 = strcmp("Host:",pcVar4);
    if (iVar14 != 0) {
      iVar14 = curl_maprintf("%s\r\n",pcVar4);
      param_1[0x91] = iVar14;
      goto joined_r0x0004102e;
    }
    param_1[0x91] = 0;
  }
  local_58 = (undefined1 *)(uint)*(byte *)(param_1 + 0x7c);
  if (local_58 != (undefined1 *)0x0) {
    if (*(char *)((int)param_1 + 0x1fa) == '\0') {
      pcVar4 = (char *)param_1[0x27];
      pcVar5 = (char *)param_1[0x26];
      pcVar6 = *(char **)(iVar29 + 0x450);
      __haystack = pcVar6;
      if ((pcVar4 != pcVar5) && (pcVar7 = strstr(pcVar6,pcVar4), pcVar7 != (char *)0x0)) {
        sVar8 = strlen(pcVar4);
        __n = strlen(pcVar5);
        sVar9 = strlen(pcVar6);
        __haystack = (char *)(*Curl_cmalloc)((__n + sVar9 + 1) - sVar8);
        if (__haystack == (char *)0x0) {
          return 0x1b;
        }
        __n_00 = (int)pcVar7 - (int)pcVar6;
        memcpy(__haystack,pcVar6,__n_00);
        memcpy(__haystack + __n_00,(void *)param_1[0x26],__n);
        memcpy(__haystack + __n + __n_00,pcVar7 + sVar8,
               (size_t)(pcVar6 + ((sVar9 + (1 - (int)pcVar7)) - sVar8)));
        if (*(char *)(iVar29 + 0x454) != '\0') {
          (*Curl_cfree)(*(undefined4 *)(iVar29 + 0x450));
        }
        *(undefined1 *)(iVar29 + 0x454) = 1;
        *(char **)(iVar29 + 0x450) = __haystack;
      }
      iVar14 = Curl_raw_nequal(&DAT_00135fcc,__haystack,6);
      if (iVar14 == 0) {
        local_58 = (undefined1 *)0x0;
      }
      else {
        if (*(char *)(iVar29 + 0x33c) != '\0') {
          pcVar4 = strstr(__haystack,";type=");
          if (pcVar4 == (char *)0x0) {
LAB_000417aa:
            if ((**(char **)(iVar29 + 0x868c) == '\0') &&
               (sVar8 = strlen(__haystack), __haystack[sVar8 - 1] != '/')) {
              local_34[0] = 0x2f;
              puVar11 = (undefined4 *)((int)local_34 + 1);
            }
            else {
              puVar11 = (undefined4 *)local_34;
            }
            if (*(char *)(iVar29 + 0x2fb) == '\0') {
              uVar17 = 0x69;
            }
            else {
              uVar17 = 0x61;
            }
            curl_msnprintf(puVar11,8,";type=%c",uVar17);
          }
          else if ((pcVar4[6] != '\0') && (pcVar4[7] == '\0')) {
            cVar2 = Curl_raw_toupper(pcVar4[6]);
            if ((8 < (byte)(cVar2 + 0xbfU)) || ((1 << (uint)(byte)(cVar2 + 0xbfU) & 0x109U) == 0))
            goto LAB_000417aa;
          }
        }
        local_58 = (undefined1 *)(uint)*(byte *)((int)param_1 + 0x1f1);
        if ((local_58 != (undefined1 *)0x0) &&
           (local_58 = (undefined1 *)(1 - *(byte *)(param_1 + 0x80)), 1 < *(byte *)(param_1 + 0x80))
           ) {
          local_58 = (undefined1 *)0x0;
        }
      }
    }
    else {
      local_58 = (undefined1 *)0x0;
    }
  }
  if (uVar30 == 3) {
    uVar26 = *(undefined4 *)(iVar29 + 0x248);
    uVar17 = Curl_checkheaders(param_1,"Content-Type:");
    uVar3 = Curl_getformdata(iVar29,piVar24,uVar26,uVar17,piVar24 + 2);
    if (uVar3 != 0) {
      return uVar3;
    }
  }
  iVar14 = Curl_checkheaders(param_1,"Accept:");
  if (iVar14 == 0) {
    pcVar4 = "Accept: */*\r\n";
  }
  else {
    pcVar4 = (char *)0x0;
  }
  piVar24[6] = (int)pcVar4;
  if ((uVar30 - 2 < 3) && (*(int *)(iVar29 + 0x8698) != 0 || *(int *)(iVar29 + 0x869c) != 0)) {
    if (*(int *)(iVar29 + 0x869c) < 0) {
      *(undefined4 *)(iVar29 + 0x8698) = 0;
      *(undefined4 *)(iVar29 + 0x869c) = 0;
    }
    else {
      uVar3 = (uint)*(byte *)(iVar29 + 0x85a8);
      if (uVar3 == 0) {
        if (((code *)param_1[0x9b] != (code *)0x0) &&
           (iVar14 = (*(code *)param_1[0x9b])(param_1[0x9c]), iVar14 != 0)) {
          if (iVar14 != 2) {
            Curl_failf(iVar29,"Could not seek stream");
            return 0x1a;
          }
          uVar23 = 0;
          iVar27 = 0;
          uVar16 = *(uint *)(iVar29 + 0x8698);
          iVar14 = *(int *)(iVar29 + 0x869c);
          do {
            uVar12 = 0x4000;
            if ((int)(uint)(0x4000 < uVar16 - uVar23) <=
                (int)-((iVar14 - iVar27) - (uint)(uVar16 < uVar23))) {
              uVar12 = curlx_sotouz();
            }
            uVar16 = (**(code **)(iVar29 + 0x86c0))
                               (iVar29 + 0x59c,1,uVar12,*(undefined4 *)(iVar29 + 0x86c4),uVar3);
            uVar19 = 1 - uVar16;
            if (1 < uVar16) {
              uVar19 = 0;
            }
            bVar33 = CARRY4(uVar23,uVar16);
            uVar23 = uVar23 + uVar16;
            iVar27 = iVar27 + (uint)bVar33;
            if (uVar12 < uVar16) {
              uVar19 = uVar19 | 1;
            }
            if (uVar19 != 0) {
              Curl_failf(iVar29,"Could only read %lld bytes from the input",uVar23,iVar27);
              return 0x1a;
            }
            uVar16 = *(uint *)(iVar29 + 0x8698);
            iVar14 = *(int *)(iVar29 + 0x869c);
          } while ((int)((iVar27 - iVar14) - (uint)(uVar23 < uVar16)) < 0 !=
                   (SBORROW4(iVar27,iVar14) != SBORROW4(iVar27 - iVar14,(uint)(uVar23 < uVar16))));
        }
        uVar3 = *(uint *)(iVar29 + 0x86b0);
        if (-*(int *)(iVar29 + 0x86b4) < (int)(uint)(uVar3 != 0)) {
          iVar14 = uVar3 - *(uint *)(iVar29 + 0x8698);
          iVar27 = (*(int *)(iVar29 + 0x86b4) - *(int *)(iVar29 + 0x869c)) -
                   (uint)(uVar3 < *(uint *)(iVar29 + 0x8698));
          *(int *)(iVar29 + 0x86b0) = iVar14;
          *(int *)(iVar29 + 0x86b4) = iVar27;
          if ((int)(uint)(iVar14 != 0) <= -iVar27) {
            Curl_failf(iVar29,"File already completely uploaded");
            return 0x12;
          }
        }
      }
    }
  }
  if (*(char *)(iVar29 + 0x8691) != '\0') {
    if ((uVar30 & 0xfffffffb) == 1) {
      iVar14 = Curl_checkheaders(param_1,"Range:");
      if (iVar14 == 0) {
        (*Curl_cfree)(param_1[0x8f]);
        iVar14 = curl_maprintf("Range: bytes=%s\r\n",*(undefined4 *)(iVar29 + 0x8694));
        param_1[0x8f] = iVar14;
      }
      else if (uVar30 != 1) goto LAB_0004114a;
    }
    else {
LAB_0004114a:
      iVar14 = Curl_checkheaders(param_1,"Content-Range:");
      if (iVar14 == 0) {
        (*Curl_cfree)(param_1[0x8f]);
        if (*(int *)(iVar29 + 0x23c) < 0) {
          iVar14 = *(int *)(iVar29 + 0x86b0);
          iVar14 = curl_maprintf("Content-Range: bytes 0-%lld/%lld\r\n",extraout_r1,iVar14 + -1,
                                 *(int *)(iVar29 + 0x86b4) + -1 + (uint)(iVar14 != 0),iVar14,
                                 *(int *)(iVar29 + 0x86b4));
          param_1[0x8f] = iVar14;
        }
        else {
          uVar3 = *(uint *)(iVar29 + 0x8698);
          if (uVar3 == 0 && *(int *)(iVar29 + 0x869c) == 0) {
            iVar14 = curl_maprintf("Content-Range: bytes %s/%lld\r\n",
                                   *(undefined4 *)(iVar29 + 0x8694),*(undefined4 *)(iVar29 + 0x86b0)
                                   ,*(undefined4 *)(iVar29 + 0x86b4));
            param_1[0x8f] = iVar14;
          }
          else {
            iVar14 = uVar3 + *(uint *)(iVar29 + 0x86b0);
            iVar27 = *(int *)(iVar29 + 0x869c) +
                     *(int *)(iVar29 + 0x86b4) + (uint)CARRY4(uVar3,*(uint *)(iVar29 + 0x86b0));
            iVar14 = curl_maprintf("Content-Range: bytes %s%lld/%lld\r\n",
                                   *(undefined4 *)(iVar29 + 0x8694),iVar14 + -1,
                                   iVar27 + -1 + (uint)(iVar14 != 0),iVar14,iVar27);
            param_1[0x8f] = iVar14;
          }
        }
        if (param_1[0x8f] == 0) {
          return 0x1b;
        }
      }
    }
  }
  if (((*(int *)(iVar29 + 0x8678) == 10) || (param_1[0x4f] == 10)) ||
     (iVar14 = *(int *)(iVar29 + 0x27c), iVar14 == 1)) {
    puVar21 = &DAT_0013ac2c;
  }
  else if (iVar14 == 0 || 1 < iVar14) {
    puVar21 = &DAT_0013ac24;
  }
  else {
    puVar21 = &DAT_0013ac2c;
  }
  iVar14 = (*Curl_ccalloc)(1,0xc);
  if (iVar14 == 0) {
    return 0x1b;
  }
  uVar3 = Curl_add_bufferf(iVar14,&DAT_001360e4,local_64);
  if (uVar3 != 0) {
    return uVar3;
  }
  if (local_58 == (undefined1 *)0x0) {
    sVar8 = strlen(__haystack);
    uVar3 = Curl_add_buffer(iVar14,__haystack,sVar8);
  }
  else {
    uVar3 = Curl_add_bufferf(iVar14,"ftp://%s:%s@%s",param_1[0x48],param_1[0x49],__haystack + 6);
  }
  if (uVar3 != 0) {
    return uVar3;
  }
  puVar15 = (undefined1 *)param_1[0x91];
  puVar31 = (undefined1 *)param_1[0x8b];
  puVar32 = (undefined1 *)param_1[0x8e];
  if (puVar15 == (undefined1 *)0x0) {
    puVar15 = &DAT_0013a6fc;
  }
  if (puVar31 == (undefined1 *)0x0) {
    puVar31 = &DAT_0013a6fc;
  }
  if (puVar32 == (undefined1 *)0x0) {
    puVar32 = &DAT_0013a6fc;
  }
  if (*(char *)(iVar29 + 0x8691) == '\0') {
    local_64 = &DAT_0013a6fc;
  }
  else {
    local_64 = (undefined *)param_1[0x8f];
    if (local_64 == (undefined1 *)0x0) {
      local_64 = &DAT_0013a6fc;
    }
  }
  if (*(char **)(iVar29 + 0x3a8) == (char *)0x0) {
    local_58 = &DAT_0013a6fc;
  }
  else if (**(char **)(iVar29 + 0x3a8) == '\0') {
    local_58 = &DAT_0013a6fc;
  }
  else {
    local_58 = (undefined1 *)param_1[0x8c];
    if (local_58 == (undefined1 *)0x0) {
      local_58 = &DAT_0013a6fc;
    }
  }
  puVar13 = (undefined1 *)param_1[0x94];
  puVar28 = (undefined1 *)piVar24[6];
  if (puVar13 == (undefined1 *)0x0) {
    puVar13 = &DAT_0013a6fc;
  }
  if (puVar28 == (undefined1 *)0x0) {
    puVar28 = &DAT_0013a6fc;
  }
  if ((*(char **)(iVar29 + 0x35c) == (char *)0x0) || (**(char **)(iVar29 + 0x35c) == '\0')) {
    local_4c = &DAT_0013a6fc;
  }
  else {
    local_4c = (undefined1 *)param_1[0x8d];
    if (local_4c == (undefined1 *)0x0) {
      local_4c = &DAT_0013a6fc;
    }
  }
  if (*(int *)(iVar29 + 0x458) == 0) {
    puVar25 = &DAT_0013a6fc;
  }
  else {
    puVar25 = (undefined1 *)param_1[0x90];
    if (puVar25 == (undefined1 *)0x0) {
      puVar25 = &DAT_0013a6fc;
    }
  }
  uVar3 = Curl_add_bufferf(iVar14,"%s HTTP/%s\r\n%s%s%s%s%s%s%s%s%s%s",local_34,puVar21,puVar15,
                           puVar31,puVar32,local_64,local_58,puVar28,puVar13,local_4c,puVar25,
                           local_54);
  (*Curl_cfree)(param_1[0x8e]);
  iVar27 = *(int *)(iVar29 + 0x8634);
  param_1[0x8e] = 0;
  uVar16 = iVar27 - 4;
  if ((uVar16 < 0x1d) && ((1 << (uVar16 & 0xff) & 0x10000011U) != 0)) {
    (*Curl_cfree)(param_1[0x8b]);
    param_1[0x8b] = 0;
  }
  if (uVar3 != 0) {
    return uVar3;
  }
  if (((-1 < *(int *)(param_1[0x86] + 0x40) << 0x1f) && (param_1[0x4f] != 0x14)) &&
     (*(int *)(iVar29 + 0x27c) == 3)) {
    return 1;
  }
  if (*(int *)(iVar29 + 0x468) == 0) {
LAB_0004176c:
    if (local_50 != 0) {
LAB_00041774:
      uVar3 = Curl_add_bufferf(iVar14,"Cookie: ");
      if (uVar3 != 0) {
        return uVar3;
      }
      puVar21 = &DAT_0013a6fc;
      iVar20 = 0;
LAB_00041666:
      iVar20 = iVar20 + 1;
      uVar3 = Curl_add_bufferf(iVar14,"%s%s",puVar21,local_50,puVar15);
      uVar16 = 1 - uVar3;
      if (1 < uVar3) {
        uVar16 = 0;
      }
      goto LAB_0004167c;
    }
  }
  else {
    Curl_share_lock(iVar29,2,2);
    iVar27 = param_1[0x92];
    if (param_1[0x92] == 0) {
      iVar27 = iVar20;
    }
    piVar10 = (int *)Curl_cookie_getlist(*(undefined4 *)(iVar29 + 0x468),iVar27,
                                         *(undefined4 *)(iVar29 + 0x868c),
                                         (uint)(*(int *)(param_1[0x86] + 0x3c) << 0x1e) >> 0x1f);
    Curl_share_unlock(iVar29,2);
    if (piVar10 == (int *)0x0) goto LAB_0004176c;
    iVar20 = 0;
    piVar22 = piVar10;
    do {
      puVar31 = (undefined1 *)piVar22[2];
      puVar21 = &DAT_00135ec8;
      if (puVar31 != (undefined1 *)0x0) {
        if (iVar20 == 0) {
          uVar3 = Curl_add_bufferf(iVar14,"Cookie: ",&DAT_00135ec8);
          if (uVar3 == 0) {
            puVar31 = (undefined1 *)piVar22[2];
            puVar21 = &DAT_0013a6fc;
            goto LAB_000413a6;
          }
        }
        else {
LAB_000413a6:
          iVar20 = iVar20 + 1;
          uVar3 = Curl_add_bufferf(iVar14,"%s%s=%s",puVar21,piVar22[1],puVar31);
          puVar15 = puVar31;
          if (uVar3 == 0) goto LAB_000413ba;
        }
        Curl_cookie_freelist(piVar10,0);
        goto LAB_000415e4;
      }
LAB_000413ba:
      piVar22 = (int *)*piVar22;
    } while (piVar22 != (int *)0x0);
    Curl_cookie_freelist(piVar10,0);
    if (local_50 != 0) {
      puVar21 = &DAT_00135ec8;
      if (iVar20 == 0) goto LAB_00041774;
      goto LAB_00041666;
    }
    uVar16 = 1;
    uVar3 = 0;
LAB_0004167c:
    if (iVar20 == 0) {
      uVar16 = 0;
    }
    else {
      uVar16 = uVar16 & 1;
    }
    if (uVar16 != 0) {
      uVar3 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
    }
LAB_000415e4:
    if (uVar3 != 0) {
      return uVar3;
    }
  }
  uVar3 = Curl_add_timecondition(iVar29,iVar14);
  if (uVar3 != 0) {
    return uVar3;
  }
  uVar34 = Curl_add_custom_headers(param_1,0,iVar14);
  if ((uint)uVar34 != 0) {
    return (uint)uVar34;
  }
  piVar24[4] = 0;
  Curl_pgrsSetUploadSize(iVar29,(int)((ulonglong)uVar34 >> 0x20),0xffffffff,0xffffffff);
  if (uVar30 == 3) {
    if ((*piVar24 == 0) || (*(char *)((int)param_1 + 0x1fb) != '\0')) {
      uVar30 = Curl_add_bufferf(iVar14,"Content-Length: 0\r\n\r\n");
      if (uVar30 != 0) {
        return uVar30;
      }
      uVar30 = Curl_add_buffer_send(iVar14,param_1,iVar29 + 0x870c,0,0);
      if (uVar30 != 0) {
        Curl_failf(iVar29,"Failed sending POST request");
        return uVar30;
      }
      uVar17 = 0xffffffff;
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = piVar24 + 0xc;
      iVar20 = Curl_FormInit(piVar10);
      if (iVar20 != 0) {
        Curl_failf(iVar29,"Internal HTTP POST error!");
        return 0x22;
      }
      cVar2 = *(char *)(iVar29 + 0x149);
      piVar24[0xf] = *(int *)(iVar29 + 0x86c0);
      *(int **)(iVar29 + 0x86c4) = piVar10;
      *(undefined4 *)(iVar29 + 0x86c0) = 0x5b289;
      piVar24[0x16] = 2;
      if (((cVar2 == '\0') && (iVar20 = Curl_checkheaders(param_1,"Content-Length:"), iVar20 == 0))
         && (uVar30 = Curl_add_bufferf(iVar14,"Content-Length: %lld\r\n",piVar24[2],piVar24[3]),
            uVar30 != 0)) {
        return uVar30;
      }
      local_38 = expect100(iVar29,param_1,iVar14);
      if (local_38 != 0) {
        return local_38;
      }
      iVar20 = Curl_formpostheader(piVar10,&local_38);
      if (iVar20 == 0) {
        Curl_failf(iVar29,"Could not get Content-Type header line!");
        return 0x22;
      }
      uVar30 = Curl_add_buffer(iVar14,iVar20,local_38);
      if (uVar30 != 0) {
        return uVar30;
      }
      uVar34 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
      if ((uint)uVar34 != 0) {
        return (uint)uVar34;
      }
      Curl_pgrsSetUploadSize(iVar29,(int)((ulonglong)uVar34 >> 0x20),piVar24[2],piVar24[3]);
      uVar30 = Curl_add_buffer_send(iVar14,param_1,iVar29 + 0x870c,0,0);
      if (uVar30 != 0) {
        Curl_failf(iVar29,"Failed sending POST request");
        Curl_formclean(piVar24);
        return uVar30;
      }
      piVar10 = piVar24 + 10;
      uVar17 = 0;
    }
LAB_00041a1c:
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,piVar24 + 8,uVar17,piVar10);
    uVar30 = 0;
    iVar20 = 0;
    goto LAB_00040f88;
  }
  if (uVar30 == 4) {
    if (*(char *)((int)param_1 + 0x1fb) == '\0') {
      uVar30 = *(uint *)(iVar29 + 0x86b0);
      iVar20 = *(int *)(iVar29 + 0x86b4);
      if (iVar20 != -1 || uVar30 != 0xffffffff) goto LAB_00041990;
LAB_000418f8:
      uVar3 = expect100(iVar29,param_1,iVar14);
      if (uVar3 != 0) {
        return uVar3;
      }
    }
    else {
      uVar30 = 0;
      iVar20 = 0;
LAB_00041990:
      if (((*(char *)(iVar29 + 0x149) == '\0') &&
          (iVar27 = Curl_checkheaders(param_1,"Content-Length:"), iVar27 == 0)) &&
         (uVar3 = Curl_add_bufferf(iVar14,"Content-Length: %lld\r\n",uVar30,iVar20), uVar3 != 0)) {
        return uVar3;
      }
      if (uVar30 != 0 || iVar20 != 0) goto LAB_000418f8;
    }
    uVar34 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
    if ((uint)uVar34 != 0) {
      return (uint)uVar34;
    }
    Curl_pgrsSetUploadSize(iVar29,(int)((ulonglong)uVar34 >> 0x20),uVar30,iVar20);
    uVar3 = Curl_add_buffer_send(iVar14,param_1,iVar29 + 0x870c,0,0);
    if (uVar3 != 0) {
      Curl_failf(iVar29,"Failed sending PUT request");
      return uVar3;
    }
    if (uVar30 == 0 && iVar20 == 0) {
      uVar17 = 0xffffffff;
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = piVar24 + 10;
      uVar17 = 0;
    }
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,piVar24 + 8,uVar17,piVar10);
    goto LAB_00040f88;
  }
  if (uVar30 != 2) {
    uVar30 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
    if (uVar30 != 0) {
      return uVar30;
    }
    uVar30 = Curl_add_buffer_send(iVar14,param_1,iVar29 + 0x870c,0,0);
    if (uVar30 != 0) {
      Curl_failf(iVar29,"Failed sending HTTP request");
      return uVar30;
    }
    if (piVar24[4] == 0) {
      uVar17 = 0xffffffff;
      piVar10 = (int *)0x0;
    }
    else {
      piVar10 = piVar24 + 10;
      uVar17 = 0;
    }
    goto LAB_00041a1c;
  }
  if (*(char *)((int)param_1 + 0x1fb) == '\0') {
    uVar30 = *(size_t *)(iVar29 + 0x86b0);
    iVar20 = *(int *)(iVar29 + 0x86b4);
    if (iVar20 != -1 || uVar30 != 0xffffffff) goto LAB_00040eb4;
    if (*(char **)(iVar29 + 0x18c) != (char *)0x0) {
      uVar30 = strlen(*(char **)(iVar29 + 0x18c));
      iVar20 = 0;
      goto LAB_00040eb4;
    }
  }
  else {
    uVar30 = 0;
    iVar20 = 0;
LAB_00040eb4:
    if (((*(char *)(iVar29 + 0x149) == '\0') &&
        (iVar27 = Curl_checkheaders(param_1,"Content-Length:"), iVar27 == 0)) &&
       (uVar3 = Curl_add_bufferf(iVar14,"Content-Length: %lld\r\n",uVar30,iVar20), uVar3 != 0)) {
      return uVar3;
    }
  }
  iVar27 = Curl_checkheaders(param_1,"Content-Type:");
  if ((iVar27 == 0) &&
     (uVar3 = Curl_add_bufferf(iVar14,"Content-Type: application/x-www-form-urlencoded\r\n"),
     uVar3 != 0)) {
    return uVar3;
  }
  iVar27 = Curl_checkheaders(param_1,"Expect:");
  if (iVar27 == 0) {
    bVar33 = iVar20 == 0;
    if (iVar20 == 0) {
      bVar33 = uVar30 < 0x401;
    }
    if (bVar33) {
      *(undefined1 *)(iVar29 + 0x867c) = 0;
    }
    else {
      uVar3 = expect100(iVar29,param_1,iVar14);
      if (uVar3 != 0) {
        return uVar3;
      }
    }
  }
  else {
    uVar1 = Curl_compareheader(iVar27,"Expect:","100-continue");
    *(undefined1 *)(iVar29 + 0x867c) = uVar1;
  }
  if (*(int *)(iVar29 + 0x18c) == 0) {
    uVar34 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
    if ((uint)uVar34 != 0) {
      return (uint)uVar34;
    }
    if ((*(char *)(iVar29 + 0x149) != '\0') && (*(char *)((int)param_1 + 0x1fb) != '\0')) {
      uVar3 = Curl_add_buffer(iVar14,"0\r\n\r\n",5);
      goto joined_r0x00041c4a;
    }
    if (*(int *)(iVar29 + 0x86b0) != 0 || *(int *)(iVar29 + 0x86b4) != 0) {
      uVar3 = uVar30;
      iVar27 = iVar20;
      if (uVar30 == 0 && iVar20 == 0) {
        uVar3 = 0xffffffff;
        iVar27 = -1;
      }
      Curl_pgrsSetUploadSize(iVar29,(int)((ulonglong)uVar34 >> 0x20),uVar3,iVar27);
      if (*(char *)((int)param_1 + 0x1fb) == '\0') {
        uVar3 = 0;
        piVar24[2] = uVar30;
        piVar24[3] = iVar20;
        piVar24[4] = (int)(piVar24 + 4);
        goto LAB_00040f3e;
      }
    }
LAB_00040f3a:
    uVar3 = 0;
  }
  else {
    if (((param_1[0x4f] == 0x14) || (*(char *)(iVar29 + 0x867c) != '\0')) ||
       ((int)(uint)(uVar30 < 0x10000) <= iVar20)) {
      piVar24[4] = *(int *)(iVar29 + 0x18c);
      piVar24[2] = uVar30;
      piVar24[3] = iVar20;
      piVar24[0x16] = 2;
      *(undefined4 *)(iVar29 + 0x86c0) = 0x3fa85;
      *(int **)(iVar29 + 0x86c4) = param_1;
      Curl_pgrsSetUploadSize(iVar29,0x3fa85,uVar30,iVar20);
      uVar3 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
joined_r0x00041c4a:
      if (uVar3 != 0) {
        return uVar3;
      }
      goto LAB_00040f3a;
    }
    uVar3 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
    if (uVar3 != 0) {
      return uVar3;
    }
    if (*(char *)(iVar29 + 0x149) == '\0') {
      uVar34 = Curl_add_buffer(iVar14,*(undefined4 *)(iVar29 + 0x18c),uVar30);
      uVar3 = uVar30;
    }
    else {
      uVar3 = uVar30;
      if (uVar30 == 0 && iVar20 == 0) {
LAB_00041ba2:
        uVar34 = Curl_add_buffer(iVar14,"0\r\n\r\n",5);
      }
      else {
        uVar34 = Curl_add_bufferf(iVar14,&DAT_00136220,uVar30);
        if ((int)uVar34 == 0) {
          uVar34 = Curl_add_buffer(iVar14,*(undefined4 *)(iVar29 + 0x18c),uVar30);
          if ((int)uVar34 == 0) {
            uVar3 = uVar30 + 2;
            uVar34 = Curl_add_buffer(iVar14,&DAT_0013c1d4,2);
            if ((int)uVar34 == 0) goto LAB_00041ba2;
          }
          else {
            uVar3 = uVar30 + 2;
          }
        }
        else {
          uVar3 = 0;
        }
      }
      uVar3 = uVar3 + 5;
    }
    if ((uint)uVar34 != 0) {
      return (uint)uVar34;
    }
    Curl_pgrsSetUploadSize(iVar29,(int)((ulonglong)uVar34 >> 0x20),uVar30,iVar20);
  }
LAB_00040f3e:
  uVar3 = Curl_add_buffer_send(iVar14,param_1,iVar29 + 0x870c,uVar3,0);
  if (uVar3 != 0) {
    Curl_failf(iVar29,"Failed sending HTTP POST request");
    return uVar3;
  }
  if (piVar24[4] == 0) {
    uVar17 = 0xffffffff;
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = piVar24 + 10;
    uVar17 = 0;
  }
  Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,piVar24 + 8,uVar17,piVar10);
LAB_00040f88:
  if (piVar24[10] == 0 && piVar24[0xb] == 0) {
    return 0;
  }
  Curl_pgrsSetUploadCounter(iVar29);
  iVar14 = Curl_pgrsUpdate(param_1);
  uVar3 = piVar24[10];
  iVar27 = piVar24[0xb];
  if (iVar14 == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = 0x2a;
  }
  if ((int)((iVar27 - iVar20) - (uint)(uVar3 < uVar30)) < 0 ==
      (SBORROW4(iVar27,iVar20) != SBORROW4(iVar27 - iVar20,(uint)(uVar3 < uVar30)))) {
    Curl_infof(iVar29,"upload completely sent off: %lld out of %lld bytes\n",uVar3,iVar27,uVar30,
               iVar20);
    *(undefined1 *)(iVar29 + 0x134) = 1;
    *(undefined4 *)(iVar29 + 0xd4) = 0;
    *(uint *)(iVar29 + 0x130) = *(uint *)(iVar29 + 0x130) & 0xfffffffd;
    return uVar16;
  }
  return uVar16;
}

