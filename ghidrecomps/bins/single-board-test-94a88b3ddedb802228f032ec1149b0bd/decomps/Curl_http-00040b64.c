
/* WARNING: Type propagation algorithm not settling */

uint Curl_http(int *param_1,undefined *param_2)

{
  code **ppcVar1;
  undefined uVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  size_t sVar9;
  size_t __n;
  size_t sVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 extraout_r1;
  int iVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  size_t __n_00;
  int iVar19;
  uint uVar20;
  int iVar21;
  int *piVar22;
  uint uVar23;
  uint unaff_r5;
  int *piVar24;
  int iVar25;
  undefined4 uVar26;
  char *__haystack;
  int iVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  bool bVar31;
  undefined8 uVar32;
  int local_64;
  uint local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_38;
  undefined local_34 [4];
  undefined4 local_30;
  undefined local_2c;
  
  iVar16 = param_1[0x4f];
  iVar28 = *param_1;
  iVar21 = param_1[0x26];
  if (0x13 < iVar16) {
    unaff_r5 = 1;
  }
  uVar29 = *(uint *)(iVar28 + 0x278);
  __haystack = *(char **)(iVar28 + 0x868c);
  local_34 = (undefined  [4])0x0;
  local_30 = 0;
  local_2c = 0;
  *param_2 = 1;
  if (0x13 < iVar16) {
    return unaff_r5;
  }
  iVar16 = param_1[0x11d];
  bVar31 = iVar16 == 3;
  if (bVar31) {
    iVar16 = 0x14;
    unaff_r5 = 1;
  }
  if (bVar31) {
    param_1[0x4f] = iVar16;
    return unaff_r5;
  }
  piVar24 = *(int **)(iVar28 + 0x14c);
  if (*(char *)(iVar28 + 0x85a8) == '\0') {
    (**DAT_0004111c)(*(undefined4 *)(iVar28 + 0x85ac));
    iVar16 = (**DAT_00041120)(param_1[0x26]);
    *(int *)(iVar28 + 0x85ac) = iVar16;
    if (iVar16 == 0) {
      return 0x1b;
    }
  }
  iVar16 = param_1[0x86];
  piVar24[8] = 0;
  piVar24[9] = 0;
  piVar24[10] = 0;
  piVar24[0xb] = 0;
  if (((*(uint *)(iVar16 + 0x3c) & 7) != 0) && (*(char *)(iVar28 + 0x309) != '\0')) {
    uVar29 = 4;
  }
  local_64 = *(int *)(iVar28 + 0x350);
  if (local_64 == 0) {
    if (*(char *)(iVar28 + 0x307) == '\0') {
      if (uVar29 - 2 < 4) {
        local_64 = *(int *)(DAT_000416f8 + (uVar29 - 2) * 4);
      }
      else {
        local_64 = DAT_00041714;
      }
    }
    else {
      local_64 = DAT_000416fc;
    }
  }
  iVar16 = Curl_checkheaders(param_1,DAT_00040e64);
  if (iVar16 != 0) {
    (**DAT_00040e68)(param_1[0x8c]);
    param_1[0x8c] = 0;
  }
  uVar4 = Curl_http_output_auth(param_1,local_64,__haystack,0);
  if (uVar4 != 0) {
    return uVar4;
  }
  if (((*(char *)(iVar28 + 0x862d) == '\0') && (*(char *)(iVar28 + 0x863d) == '\0')) ||
     ((uVar29 & 0xfffffffb) == 1)) {
    *(undefined *)((int)param_1 + 0x1fb) = 0;
  }
  else {
    *(undefined *)((int)param_1 + 0x1fb) = 1;
  }
  ppcVar1 = DAT_00040e68;
  (**DAT_00040e68)(param_1[0x90]);
  iVar16 = *(int *)(iVar28 + 0x458);
  param_1[0x90] = 0;
  if ((iVar16 == 0) || (iVar16 = Curl_checkheaders(param_1,DAT_00040e6c), iVar16 != 0)) {
    param_1[0x90] = 0;
  }
  else {
    iVar16 = curl_maprintf(DAT_00041718,*(undefined4 *)(iVar28 + 0x458));
    param_1[0x90] = iVar16;
    if (iVar16 == 0) {
      return 0x1b;
    }
  }
  if ((*(int *)(iVar28 + 0x348) == 0) ||
     (iVar16 = Curl_checkheaders(param_1,DAT_00040e70), iVar16 != 0)) {
    local_50 = 0;
  }
  else {
    local_50 = *(int *)(iVar28 + 0x348);
  }
  iVar16 = Curl_checkheaders(param_1,DAT_00040e74);
  if ((iVar16 == 0) && (*(int *)(iVar28 + 0x35c) != 0)) {
    (**ppcVar1)(param_1[0x8d]);
    param_1[0x8d] = 0;
    iVar16 = curl_maprintf(DAT_00041444,*(undefined4 *)(iVar28 + 0x35c));
    param_1[0x8d] = iVar16;
    if (iVar16 == 0) {
      return 0x1b;
    }
  }
  iVar16 = Curl_checkheaders(param_1,DAT_00040e78);
  if ((iVar16 == 0) && (*(char *)(iVar28 + 0x302) != '\0')) {
    iVar16 = Curl_checkheaders(param_1,DAT_00041708);
    (**ppcVar1)(param_1[0x94]);
    param_1[0x94] = 0;
    if (iVar16 == 0) {
      iVar16 = (**DAT_00041a44)(DAT_00041a48);
    }
    else {
      iVar16 = curl_maprintf(DAT_0004170c);
    }
    param_1[0x94] = iVar16;
    if (iVar16 == 0) {
      return 0x1b;
    }
  }
  if (param_1[0x4f] == 0x14) {
LAB_00041452:
    local_54 = DAT_000416f4;
  }
  else {
    iVar16 = Curl_checkheaders(param_1,DAT_00040e7c);
    local_54 = DAT_00040e80;
    if (iVar16 == 0) {
      if ((((*(uint *)(param_1[0x86] + 0x3c) & 3) == 0) || (*(char *)(iVar28 + 0x309) == '\0')) ||
         (*(int *)(iVar28 + 0x86b4) != -1 || *(int *)(iVar28 + 0x86b0) != -1)) {
        local_54 = DAT_000416f4;
        *(undefined *)(iVar28 + 0x149) = 0;
      }
      else {
        if (*(char *)((int)param_1 + 0x1fb) == '\0') {
          if (((*(int *)(iVar28 + 0x8678) == 10) || (param_1[0x4f] == 10)) ||
             ((iVar16 = *(int *)(iVar28 + 0x27c), iVar16 == 1 || ((iVar16 < 2 && (iVar16 != 0))))))
          {
            Curl_failf(iVar28,DAT_00041a54);
            return 0x19;
          }
          *(undefined *)(iVar28 + 0x149) = 1;
        }
        else if (*(char *)(iVar28 + 0x149) == '\0') goto LAB_00041452;
        local_54 = DAT_00041a34;
      }
    }
    else {
      uVar2 = Curl_compareheader(iVar16,DAT_00040e7c,DAT_00040e84);
      *(undefined *)(iVar28 + 0x149) = uVar2;
    }
  }
  (**ppcVar1)(param_1[0x91]);
  param_1[0x91] = 0;
  pcVar5 = (char *)Curl_checkheaders(param_1,DAT_00040e88);
  if ((pcVar5 == (char *)0x0) ||
     ((*(char *)(iVar28 + 0x85a8) != '\0' &&
      (iVar16 = Curl_raw_equal(*(undefined4 *)(iVar28 + 0x85ac),param_1[0x26]), iVar16 == 0)))) {
    iVar16 = param_1[0x2d];
    if (((*(int *)(param_1[0x87] + 0x3c) << 0x1e < 0) && (iVar16 == 0x1bb)) ||
       ((*(int *)(param_1[0x87] + 0x3c) << 0x1f < 0 && (iVar16 == 0x50)))) {
      uVar18 = DAT_0004171c;
      uVar26 = DAT_00041720;
      if (*(char *)((int)param_1 + 499) == '\0') {
        uVar18 = DAT_00041108;
        uVar26 = DAT_00041108;
      }
      iVar16 = curl_maprintf(DAT_0004110c,uVar18,iVar21,uVar26);
      param_1[0x91] = iVar16;
    }
    else {
      iVar11 = DAT_000416f4;
      iVar19 = DAT_000416f4;
      if (*(char *)((int)param_1 + 499) != '\0') {
        iVar11 = DAT_00041110;
        iVar19 = DAT_00041114;
      }
      iVar16 = curl_maprintf(DAT_00041118,iVar11,iVar21,iVar19,iVar16);
      param_1[0x91] = iVar16;
    }
joined_r0x0004102e:
    if (iVar16 == 0) {
      return 0x1b;
    }
  }
  else {
    pcVar6 = (char *)Curl_copy_header_value(pcVar5);
    if (pcVar6 == (char *)0x0) {
      return 0x1b;
    }
    if (*pcVar6 == '\0') {
      (**ppcVar1)();
    }
    else {
      if (*pcVar6 == '[') {
        sVar9 = strlen(pcVar6);
        memmove(pcVar6,pcVar6 + 1,sVar9 - 1);
        pcVar7 = strchr(pcVar6,0x5d);
      }
      else {
        pcVar7 = strchr(pcVar6,0x3a);
      }
      if (pcVar7 != (char *)0x0) {
        *pcVar7 = '\0';
      }
      (**ppcVar1)(param_1[0x92]);
      param_1[0x92] = (int)pcVar6;
    }
    iVar16 = strcmp(DAT_00040e88,pcVar5);
    if (iVar16 != 0) {
      iVar16 = curl_maprintf(DAT_00041710,pcVar5);
      param_1[0x91] = iVar16;
      goto joined_r0x0004102e;
    }
    param_1[0x91] = 0;
  }
  local_58 = (uint)*(byte *)(param_1 + 0x7c);
  if (local_58 != 0) {
    if (*(char *)((int)param_1 + 0x1fa) == '\0') {
      pcVar5 = (char *)param_1[0x27];
      pcVar6 = (char *)param_1[0x26];
      pcVar7 = *(char **)(iVar28 + 0x450);
      __haystack = pcVar7;
      if ((pcVar5 != pcVar6) && (pcVar8 = strstr(pcVar7,pcVar5), pcVar8 != (char *)0x0)) {
        sVar9 = strlen(pcVar5);
        __n = strlen(pcVar6);
        sVar10 = strlen(pcVar7);
        __haystack = (char *)(**DAT_00040e8c)((__n + sVar10 + 1) - sVar9);
        if (__haystack == (char *)0x0) {
          return 0x1b;
        }
        __n_00 = (int)pcVar8 - (int)pcVar7;
        memcpy(__haystack,pcVar7,__n_00);
        memcpy(__haystack + __n_00,(void *)param_1[0x26],__n);
        memcpy(__haystack + __n + __n_00,pcVar8 + sVar9,
               (size_t)(pcVar7 + ((sVar10 + (1 - (int)pcVar8)) - sVar9)));
        if (*(char *)(iVar28 + 0x454) != '\0') {
          (**ppcVar1)(*(undefined4 *)(iVar28 + 0x450));
        }
        *(undefined *)(iVar28 + 0x454) = 1;
        *(char **)(iVar28 + 0x450) = __haystack;
      }
      iVar16 = Curl_raw_nequal(DAT_00040e90,__haystack,6);
      if (iVar16 == 0) {
        local_58 = 0;
      }
      else {
        if (*(char *)(iVar28 + 0x33c) != '\0') {
          pcVar5 = strstr(__haystack,DAT_00040e94);
          if (pcVar5 == (char *)0x0) {
LAB_000417aa:
            if ((**(char **)(iVar28 + 0x868c) == '\0') &&
               (sVar9 = strlen(__haystack), __haystack[sVar9 - 1] != '/')) {
              local_34 = (undefined  [4])CONCAT31(local_34._1_3_,0x2f);
              puVar13 = (undefined4 *)((int)local_34 + 1);
            }
            else {
              puVar13 = (undefined4 *)local_34;
            }
            if (*(char *)(iVar28 + 0x2fb) == '\0') {
              uVar18 = 0x69;
            }
            else {
              uVar18 = 0x61;
            }
            curl_msnprintf(puVar13,8,DAT_00041a40,uVar18);
          }
          else if ((pcVar5[6] != '\0') && (pcVar5[7] == '\0')) {
            cVar3 = Curl_raw_toupper(pcVar5[6]);
            if ((8 < (byte)(cVar3 + 0xbfU)) || ((1 << (uint)(byte)(cVar3 + 0xbfU) & 0x109U) == 0))
            goto LAB_000417aa;
          }
        }
        local_58 = (uint)*(byte *)((int)param_1 + 0x1f1);
        if ((local_58 != 0) &&
           (local_58 = 1 - *(byte *)(param_1 + 0x80), 1 < *(byte *)(param_1 + 0x80))) {
          local_58 = 0;
        }
      }
    }
    else {
      local_58 = 0;
    }
  }
  if (uVar29 == 3) {
    uVar26 = *(undefined4 *)(iVar28 + 0x248);
    uVar18 = Curl_checkheaders(param_1,DAT_00041704);
    uVar4 = Curl_getformdata(iVar28,piVar24,uVar26,uVar18,piVar24 + 2);
    if (uVar4 != 0) {
      return uVar4;
    }
  }
  iVar11 = Curl_checkheaders(param_1,DAT_00041124);
  iVar16 = DAT_00041128;
  if (iVar11 != 0) {
    iVar16 = 0;
  }
  piVar24[6] = iVar16;
  if ((uVar29 - 2 < 3) && ((*(uint *)(iVar28 + 0x8698) | *(uint *)(iVar28 + 0x869c)) != 0)) {
    if ((int)*(uint *)(iVar28 + 0x869c) < 0) {
      *(undefined4 *)(iVar28 + 0x8698) = 0;
      *(undefined4 *)(iVar28 + 0x869c) = 0;
    }
    else {
      uVar4 = (uint)*(byte *)(iVar28 + 0x85a8);
      if (uVar4 == 0) {
        if (((code *)param_1[0x9b] != (code *)0x0) &&
           (iVar16 = (*(code *)param_1[0x9b])(param_1[0x9c]), iVar16 != 0)) {
          if (iVar16 != 2) {
            Curl_failf(iVar28,DAT_0004112c);
            return 0x1a;
          }
          uVar23 = 0;
          iVar11 = 0;
          uVar17 = *(uint *)(iVar28 + 0x8698);
          iVar16 = *(int *)(iVar28 + 0x869c);
          do {
            iVar16 = (iVar16 - iVar11) - (uint)(uVar17 < uVar23);
            uVar14 = 0x4000;
            bVar31 = 0x4000 < uVar17 - uVar23;
            if ((int)(-(uint)bVar31 - iVar16) < 0 == (SBORROW4(-iVar16,(uint)bVar31) != false)) {
              uVar14 = curlx_sotouz();
            }
            uVar17 = (**(code **)(iVar28 + 0x86c0))
                               (iVar28 + 0x59c,1,uVar14,*(undefined4 *)(iVar28 + 0x86c4),uVar4);
            uVar20 = 1 - uVar17;
            if (1 < uVar17) {
              uVar20 = 0;
            }
            bVar31 = CARRY4(uVar23,uVar17);
            uVar23 = uVar23 + uVar17;
            iVar11 = iVar11 + (uint)bVar31;
            if (uVar14 < uVar17) {
              uVar20 = uVar20 | 1;
            }
            if (uVar20 != 0) {
              Curl_failf(iVar28,DAT_00041a58,uVar23,iVar11);
              return 0x1a;
            }
            uVar17 = *(uint *)(iVar28 + 0x8698);
            iVar16 = *(int *)(iVar28 + 0x869c);
          } while ((int)((iVar11 - iVar16) - (uint)(uVar23 < uVar17)) < 0 !=
                   (SBORROW4(iVar11,iVar16) != SBORROW4(iVar11 - iVar16,(uint)(uVar23 < uVar17))));
        }
        uVar4 = *(uint *)(iVar28 + 0x86b0);
        iVar16 = *(int *)(iVar28 + 0x86b4);
        if ((int)(-(uint)(uVar4 != 0) - iVar16) < 0 !=
            (SBORROW4(-iVar16,(uint)(uVar4 != 0)) != false)) {
          iVar11 = uVar4 - *(uint *)(iVar28 + 0x8698);
          iVar16 = (iVar16 - *(int *)(iVar28 + 0x869c)) - (uint)(uVar4 < *(uint *)(iVar28 + 0x8698))
          ;
          *(int *)(iVar28 + 0x86b0) = iVar11;
          *(int *)(iVar28 + 0x86b4) = iVar16;
          if ((int)(-(uint)(iVar11 != 0) - iVar16) < 0 ==
              (SBORROW4(-iVar16,(uint)(iVar11 != 0)) != false)) {
            Curl_failf(iVar28,DAT_00041730);
            return 0x12;
          }
        }
      }
    }
  }
  if (*(char *)(iVar28 + 0x8691) != '\0') {
    if ((uVar29 & 0xfffffffb) == 1) {
      iVar16 = Curl_checkheaders(param_1,DAT_00041700);
      if (iVar16 == 0) {
        (**ppcVar1)(param_1[0x8f]);
        iVar16 = curl_maprintf(DAT_00041a4c,*(undefined4 *)(iVar28 + 0x8694));
        param_1[0x8f] = iVar16;
      }
      else if (uVar29 != 1) goto LAB_0004114a;
    }
    else {
LAB_0004114a:
      iVar16 = Curl_checkheaders(param_1,DAT_00041410);
      if (iVar16 == 0) {
        (**ppcVar1)(param_1[0x8f]);
        if (*(int *)(iVar28 + 0x23c) < 0) {
          iVar16 = *(int *)(iVar28 + 0x86b0);
          iVar16 = curl_maprintf(DAT_00041a68,extraout_r1,iVar16 + -1,
                                 *(int *)(iVar28 + 0x86b4) + -1 + (uint)(iVar16 != 0),iVar16,
                                 *(int *)(iVar28 + 0x86b4));
          param_1[0x8f] = iVar16;
        }
        else {
          uVar4 = *(uint *)(iVar28 + 0x8698);
          if ((uVar4 | *(uint *)(iVar28 + 0x869c)) == 0) {
            iVar16 = curl_maprintf(DAT_00041a50,*(undefined4 *)(iVar28 + 0x8694),
                                   *(undefined4 *)(iVar28 + 0x86b0),*(undefined4 *)(iVar28 + 0x86b4)
                                  );
            param_1[0x8f] = iVar16;
          }
          else {
            iVar16 = uVar4 + *(uint *)(iVar28 + 0x86b0);
            iVar11 = *(uint *)(iVar28 + 0x869c) +
                     *(int *)(iVar28 + 0x86b4) + (uint)CARRY4(uVar4,*(uint *)(iVar28 + 0x86b0));
            iVar16 = curl_maprintf(DAT_00041414,*(undefined4 *)(iVar28 + 0x8694),iVar16 + -1,
                                   iVar11 + -1 + (uint)(iVar16 != 0),iVar16,iVar11);
            param_1[0x8f] = iVar16;
          }
        }
        if (param_1[0x8f] == 0) {
          return 0x1b;
        }
      }
    }
  }
  uVar18 = DAT_00041418;
  if ((((*(int *)(iVar28 + 0x8678) != 10) && (param_1[0x4f] != 10)) &&
      (iVar16 = *(int *)(iVar28 + 0x27c), iVar16 != 1)) && (iVar16 == 0 || 1 < iVar16)) {
    uVar18 = DAT_0004141c;
  }
  iVar16 = (**DAT_00041420)(1,0xc);
  if (iVar16 == 0) {
    return 0x1b;
  }
  uVar4 = Curl_add_bufferf(iVar16,DAT_00041424,local_64);
  if (uVar4 != 0) {
    return uVar4;
  }
  if (local_58 == 0) {
    sVar9 = strlen(__haystack);
    uVar4 = Curl_add_buffer(iVar16,__haystack,sVar9);
  }
  else {
    uVar4 = Curl_add_bufferf(iVar16,DAT_00041428,param_1[0x48],param_1[0x49],__haystack + 6);
  }
  if (uVar4 != 0) {
    return uVar4;
  }
  iVar11 = param_1[0x91];
  if (param_1[0x91] == 0) {
    iVar11 = DAT_0004142c;
  }
  iVar19 = param_1[0x8b];
  if (param_1[0x8b] == 0) {
    iVar19 = DAT_0004142c;
  }
  iVar30 = param_1[0x8e];
  if (param_1[0x8e] == 0) {
    iVar30 = DAT_0004142c;
  }
  if (*(char *)(iVar28 + 0x8691) == '\0') {
    local_64 = DAT_0004142c;
  }
  else {
    local_64 = param_1[0x8f];
    if (local_64 == 0) {
      local_64 = DAT_0004142c;
    }
  }
  if (*(char **)(iVar28 + 0x3a8) == (char *)0x0) {
    local_58 = DAT_000416f4;
  }
  else if (**(char **)(iVar28 + 0x3a8) == '\0') {
    local_58 = DAT_000416f4;
  }
  else {
    local_58 = param_1[0x8c];
    if (local_58 == 0) {
      local_58 = DAT_0004142c;
    }
  }
  iVar15 = param_1[0x94];
  if (param_1[0x94] == 0) {
    iVar15 = DAT_0004142c;
  }
  iVar27 = piVar24[6];
  if (piVar24[6] == 0) {
    iVar27 = DAT_0004142c;
  }
  if ((*(char **)(iVar28 + 0x35c) == (char *)0x0) || (**(char **)(iVar28 + 0x35c) == '\0')) {
    local_4c = DAT_0004142c;
  }
  else {
    local_4c = param_1[0x8d];
    if (local_4c == 0) {
      local_4c = DAT_0004142c;
    }
  }
  iVar25 = DAT_000416f4;
  if ((*(int *)(iVar28 + 0x458) != 0) && (iVar25 = param_1[0x90], param_1[0x90] == 0)) {
    iVar25 = DAT_0004142c;
  }
  uVar4 = Curl_add_bufferf(iVar16,DAT_00041430,local_34,uVar18,iVar11,iVar19,iVar30,local_64,
                           local_58,iVar27,iVar15,local_4c,iVar25,local_54);
  (**ppcVar1)(param_1[0x8e]);
  ppcVar1 = DAT_00041434;
  iVar19 = *(int *)(iVar28 + 0x8634);
  param_1[0x8e] = 0;
  uVar17 = iVar19 - 4;
  if ((uVar17 < 0x1d) && ((1 << (uVar17 & 0xff) & 0x10000011U) != 0)) {
    (**ppcVar1)(param_1[0x8b]);
    param_1[0x8b] = 0;
  }
  if (uVar4 != 0) {
    return uVar4;
  }
  if (((-1 < *(int *)(param_1[0x86] + 0x40) << 0x1f) && (param_1[0x4f] != 0x14)) &&
     (*(int *)(iVar28 + 0x27c) == 3)) {
    return 1;
  }
  if (*(int *)(iVar28 + 0x468) == 0) {
LAB_0004176c:
    if (local_50 != 0) {
LAB_00041774:
      uVar4 = Curl_add_bufferf(iVar16,DAT_00041a38);
      if (uVar4 != 0) {
        return uVar4;
      }
      iVar21 = 0;
      uVar18 = DAT_00041a3c;
LAB_00041666:
      iVar21 = iVar21 + 1;
      uVar4 = Curl_add_bufferf(iVar16,DAT_0004172c,uVar18,local_50,iVar11);
      uVar17 = 1 - uVar4;
      if (1 < uVar4) {
        uVar17 = 0;
      }
      goto LAB_0004167c;
    }
  }
  else {
    Curl_share_lock(iVar28,2,2);
    iVar19 = param_1[0x92];
    if (param_1[0x92] == 0) {
      iVar19 = iVar21;
    }
    piVar12 = (int *)Curl_cookie_getlist(*(undefined4 *)(iVar28 + 0x468),iVar19,
                                         *(undefined4 *)(iVar28 + 0x868c),
                                         (uint)(*(int *)(param_1[0x86] + 0x3c) << 0x1e) >> 0x1f);
    Curl_share_unlock(iVar28,2);
    if (piVar12 == (int *)0x0) goto LAB_0004176c;
    iVar21 = 0;
    piVar22 = piVar12;
    do {
      iVar19 = piVar22[2];
      if (iVar19 != 0) {
        iVar11 = DAT_0004143c;
        if (iVar21 == 0) {
          uVar4 = Curl_add_bufferf(iVar16,DAT_00041440,DAT_0004143c);
          if (uVar4 == 0) {
            iVar19 = piVar22[2];
            iVar11 = DAT_0004142c;
            goto LAB_000413a6;
          }
        }
        else {
LAB_000413a6:
          iVar21 = iVar21 + 1;
          uVar4 = Curl_add_bufferf(iVar16,DAT_00041438,iVar11,piVar22[1],iVar19);
          iVar11 = iVar19;
          if (uVar4 == 0) goto LAB_000413ba;
        }
        Curl_cookie_freelist(piVar12,0);
        goto LAB_000415e4;
      }
LAB_000413ba:
      piVar22 = (int *)*piVar22;
    } while (piVar22 != (int *)0x0);
    Curl_cookie_freelist(piVar12,0);
    if (local_50 != 0) {
      uVar18 = DAT_00041728;
      if (iVar21 == 0) goto LAB_00041774;
      goto LAB_00041666;
    }
    uVar17 = 1;
    uVar4 = 0;
LAB_0004167c:
    if (iVar21 == 0) {
      uVar17 = 0;
    }
    else {
      uVar17 = uVar17 & 1;
    }
    if (uVar17 != 0) {
      uVar4 = Curl_add_buffer(iVar16,DAT_00041724,2);
    }
LAB_000415e4:
    if (uVar4 != 0) {
      return uVar4;
    }
  }
  uVar4 = Curl_add_timecondition(iVar28,iVar16);
  if (uVar4 != 0) {
    return uVar4;
  }
  uVar32 = Curl_add_custom_headers(param_1,0,iVar16);
  if ((uint)uVar32 != 0) {
    return (uint)uVar32;
  }
  piVar24[4] = 0;
  Curl_pgrsSetUploadSize(iVar28,(int)((ulonglong)uVar32 >> 0x20),0xffffffff,0xffffffff);
  if (uVar29 == 3) {
    if ((*piVar24 == 0) || (*(char *)((int)param_1 + 0x1fb) != '\0')) {
      uVar29 = Curl_add_bufferf(iVar16,DAT_00041a60);
      if (uVar29 != 0) {
        return uVar29;
      }
      uVar29 = Curl_add_buffer_send(iVar16,param_1,iVar28 + 0x870c,0,0);
      if (uVar29 != 0) {
        Curl_failf(iVar28,DAT_00041a64);
        return uVar29;
      }
      uVar18 = 0xffffffff;
      piVar12 = (int *)0x0;
    }
    else {
      piVar12 = piVar24 + 0xc;
      iVar21 = Curl_FormInit(piVar12);
      uVar18 = DAT_00041d44;
      if (iVar21 != 0) {
        Curl_failf(iVar28,DAT_00041dc8);
        return 0x22;
      }
      cVar3 = *(char *)(iVar28 + 0x149);
      piVar24[0xf] = *(int *)(iVar28 + 0x86c0);
      *(int **)(iVar28 + 0x86c4) = piVar12;
      *(undefined4 *)(iVar28 + 0x86c0) = uVar18;
      piVar24[0x16] = 2;
      if (((cVar3 == '\0') && (iVar21 = Curl_checkheaders(param_1,DAT_00041dc0), iVar21 == 0)) &&
         (uVar29 = Curl_add_bufferf(iVar16,DAT_00041dc4,piVar24[2],piVar24[3]), uVar29 != 0)) {
        return uVar29;
      }
      local_38 = expect100(iVar28,param_1,iVar16);
      if (local_38 != 0) {
        return local_38;
      }
      iVar21 = Curl_formpostheader(piVar12,&local_38);
      if (iVar21 == 0) {
        Curl_failf(iVar28,DAT_00041d70);
        return 0x22;
      }
      uVar29 = Curl_add_buffer(iVar16,iVar21,local_38);
      if (uVar29 != 0) {
        return uVar29;
      }
      uVar32 = Curl_add_buffer(iVar16,DAT_00041d48,2);
      if ((uint)uVar32 != 0) {
        return (uint)uVar32;
      }
      Curl_pgrsSetUploadSize(iVar28,(int)((ulonglong)uVar32 >> 0x20),piVar24[2],piVar24[3]);
      uVar29 = Curl_add_buffer_send(iVar16,param_1,iVar28 + 0x870c,0,0);
      if (uVar29 != 0) {
        Curl_failf(iVar28,DAT_00041d6c);
        Curl_formclean(piVar24);
        return uVar29;
      }
      piVar12 = piVar24 + 10;
      uVar18 = 0;
    }
LAB_00041a1c:
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,piVar24 + 8,uVar18,piVar12);
    uVar29 = 0;
    uVar4 = 0;
    goto LAB_00040f88;
  }
  if (uVar29 == 4) {
    if (*(char *)((int)param_1 + 0x1fb) == '\0') {
      uVar29 = *(uint *)(iVar28 + 0x86b0);
      uVar4 = *(uint *)(iVar28 + 0x86b4);
      if (uVar4 != 0xffffffff || uVar29 != 0xffffffff) goto LAB_00041990;
LAB_000418f8:
      uVar17 = expect100(iVar28,param_1,iVar16);
      if (uVar17 != 0) {
        return uVar17;
      }
    }
    else {
      uVar29 = 0;
      uVar4 = 0;
LAB_00041990:
      if (((*(char *)(iVar28 + 0x149) == '\0') &&
          (iVar21 = Curl_checkheaders(param_1,DAT_00041d4c), iVar21 == 0)) &&
         (uVar17 = Curl_add_bufferf(iVar16,DAT_00041d50,uVar29,uVar4), uVar17 != 0)) {
        return uVar17;
      }
      if ((uVar29 | uVar4) != 0) goto LAB_000418f8;
    }
    uVar32 = Curl_add_buffer(iVar16,DAT_00041a5c,2);
    if ((uint)uVar32 != 0) {
      return (uint)uVar32;
    }
    Curl_pgrsSetUploadSize(iVar28,(int)((ulonglong)uVar32 >> 0x20),uVar29,uVar4);
    uVar17 = Curl_add_buffer_send(iVar16,param_1,iVar28 + 0x870c,0,0);
    if (uVar17 != 0) {
      Curl_failf(iVar28,DAT_00041d54);
      return uVar17;
    }
    if ((uVar29 | uVar4) == 0) {
      uVar18 = 0xffffffff;
      piVar12 = (int *)0x0;
    }
    else {
      piVar12 = piVar24 + 10;
      uVar18 = 0;
    }
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,piVar24 + 8,uVar18,piVar12);
    goto LAB_00040f88;
  }
  if (uVar29 != 2) {
    uVar29 = Curl_add_buffer(iVar16,DAT_00041724,2);
    if (uVar29 != 0) {
      return uVar29;
    }
    uVar29 = Curl_add_buffer_send(iVar16,param_1,iVar28 + 0x870c,0,0);
    if (uVar29 != 0) {
      Curl_failf(iVar28,DAT_00041d68);
      return uVar29;
    }
    if (piVar24[4] == 0) {
      uVar18 = 0xffffffff;
      piVar12 = (int *)0x0;
    }
    else {
      piVar12 = piVar24 + 10;
      uVar18 = 0;
    }
    goto LAB_00041a1c;
  }
  if (*(char *)((int)param_1 + 0x1fb) == '\0') {
    uVar29 = *(size_t *)(iVar28 + 0x86b0);
    uVar4 = *(uint *)(iVar28 + 0x86b4);
    if (uVar4 != 0xffffffff || uVar29 != 0xffffffff) goto LAB_00040eb4;
    if (*(char **)(iVar28 + 0x18c) != (char *)0x0) {
      uVar29 = strlen(*(char **)(iVar28 + 0x18c));
      uVar4 = 0;
      goto LAB_00040eb4;
    }
  }
  else {
    uVar29 = 0;
    uVar4 = 0;
LAB_00040eb4:
    if (((*(char *)(iVar28 + 0x149) == '\0') &&
        (iVar21 = Curl_checkheaders(param_1,DAT_00041a6c), iVar21 == 0)) &&
       (uVar17 = Curl_add_bufferf(iVar16,DAT_00041a70,uVar29,uVar4), uVar17 != 0)) {
      return uVar17;
    }
  }
  iVar21 = Curl_checkheaders(param_1,DAT_000410f0);
  if ((iVar21 == 0) && (uVar17 = Curl_add_bufferf(iVar16,DAT_00041d60), uVar17 != 0)) {
    return uVar17;
  }
  iVar21 = Curl_checkheaders(param_1,DAT_000410f4);
  if (iVar21 == 0) {
    bVar31 = uVar4 == 0;
    if (uVar4 == 0) {
      bVar31 = uVar29 < 0x401;
    }
    if (bVar31) {
      *(undefined *)(iVar28 + 0x867c) = 0;
    }
    else {
      uVar17 = expect100(iVar28,param_1,iVar16);
      if (uVar17 != 0) {
        return uVar17;
      }
    }
  }
  else {
    uVar2 = Curl_compareheader(iVar21,DAT_000410f4,DAT_000410f8);
    *(undefined *)(iVar28 + 0x867c) = uVar2;
  }
  uVar18 = DAT_000410fc;
  if (*(int *)(iVar28 + 0x18c) == 0) {
    uVar32 = Curl_add_buffer(iVar16,DAT_00041d48,2);
    if ((uint)uVar32 != 0) {
      return (uint)uVar32;
    }
    if ((*(char *)(iVar28 + 0x149) != '\0') && (*(char *)((int)param_1 + 0x1fb) != '\0')) {
      uVar17 = Curl_add_buffer(iVar16,DAT_00041d58,5);
      goto joined_r0x00041c4a;
    }
    if ((*(uint *)(iVar28 + 0x86b0) | *(uint *)(iVar28 + 0x86b4)) != 0) {
      uVar23 = uVar29;
      uVar17 = uVar4;
      if ((uVar29 | uVar4) == 0) {
        uVar23 = 0xffffffff;
        uVar17 = 0xffffffff;
      }
      Curl_pgrsSetUploadSize(iVar28,(int)((ulonglong)uVar32 >> 0x20),uVar23,uVar17);
      if (*(char *)((int)param_1 + 0x1fb) == '\0') {
        uVar17 = 0;
        piVar24[2] = uVar29;
        piVar24[3] = uVar4;
        piVar24[4] = (int)(piVar24 + 4);
        goto LAB_00040f3e;
      }
    }
LAB_00040f3a:
    uVar17 = 0;
  }
  else {
    if (((param_1[0x4f] == 0x14) || (*(char *)(iVar28 + 0x867c) != '\0')) ||
       ((int)(uVar4 - (uVar29 < 0x10000)) < 0 == (SBORROW4(uVar4,(uint)(uVar29 < 0x10000)) != false)
       )) {
      piVar24[4] = *(int *)(iVar28 + 0x18c);
      piVar24[2] = uVar29;
      piVar24[3] = uVar4;
      piVar24[0x16] = 2;
      *(undefined4 *)(iVar28 + 0x86c0) = uVar18;
      *(int **)(iVar28 + 0x86c4) = param_1;
      Curl_pgrsSetUploadSize(iVar28,uVar18,uVar29,uVar4);
      uVar17 = Curl_add_buffer(iVar16,DAT_00041100,2);
joined_r0x00041c4a:
      if (uVar17 != 0) {
        return uVar17;
      }
      goto LAB_00040f3a;
    }
    uVar17 = Curl_add_buffer(iVar16,DAT_00041d48,2);
    if (uVar17 != 0) {
      return uVar17;
    }
    if (*(char *)(iVar28 + 0x149) == '\0') {
      uVar32 = Curl_add_buffer(iVar16,*(undefined4 *)(iVar28 + 0x18c),uVar29);
      uVar17 = uVar29;
    }
    else {
      uVar17 = uVar29;
      if ((uVar29 | uVar4) == 0) {
LAB_00041ba2:
        uVar32 = Curl_add_buffer(iVar16,DAT_00041d58,5);
      }
      else {
        uVar32 = Curl_add_bufferf(iVar16,DAT_00041d5c,uVar29);
        if ((int)uVar32 == 0) {
          uVar32 = Curl_add_buffer(iVar16,*(undefined4 *)(iVar28 + 0x18c),uVar29);
          if ((int)uVar32 == 0) {
            uVar17 = uVar29 + 2;
            uVar32 = Curl_add_buffer(iVar16,DAT_00041d48,2);
            if ((int)uVar32 == 0) goto LAB_00041ba2;
          }
          else {
            uVar17 = uVar29 + 2;
          }
        }
        else {
          uVar17 = 0;
        }
      }
      uVar17 = uVar17 + 5;
    }
    if ((uint)uVar32 != 0) {
      return (uint)uVar32;
    }
    Curl_pgrsSetUploadSize(iVar28,(int)((ulonglong)uVar32 >> 0x20),uVar29,uVar4);
  }
LAB_00040f3e:
  uVar17 = Curl_add_buffer_send(iVar16,param_1,iVar28 + 0x870c,uVar17,0);
  if (uVar17 != 0) {
    Curl_failf(iVar28,DAT_00041d64);
    return uVar17;
  }
  if (piVar24[4] == 0) {
    uVar18 = 0xffffffff;
    piVar12 = (int *)0x0;
  }
  else {
    piVar12 = piVar24 + 10;
    uVar18 = 0;
  }
  Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,1,piVar24 + 8,uVar18,piVar12);
LAB_00040f88:
  if ((piVar24[10] | piVar24[0xb]) == 0) {
    return 0;
  }
  Curl_pgrsSetUploadCounter(iVar28);
  iVar16 = Curl_pgrsUpdate(param_1);
  uVar17 = piVar24[10];
  iVar21 = piVar24[0xb];
  if (iVar16 == 0) {
    uVar23 = 0;
  }
  else {
    uVar23 = 0x2a;
  }
  if ((int)((iVar21 - uVar4) - (uint)(uVar17 < uVar29)) < 0 ==
      (SBORROW4(iVar21,uVar4) != SBORROW4(iVar21 - uVar4,(uint)(uVar17 < uVar29)))) {
    Curl_infof(iVar28,DAT_00041104,uVar17,iVar21,uVar29,uVar4);
    *(undefined *)(iVar28 + 0x134) = 1;
    *(undefined4 *)(iVar28 + 0xd4) = 0;
    *(uint *)(iVar28 + 0x130) = *(uint *)(iVar28 + 0x130) & 0xfffffffd;
    return uVar23;
  }
  return uVar23;
}

