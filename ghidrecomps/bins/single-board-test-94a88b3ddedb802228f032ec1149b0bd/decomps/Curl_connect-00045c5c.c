
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int Curl_connect(int param_1,int **param_2,char *param_3,undefined *param_4)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  undefined2 uVar5;
  bool bVar6;
  code **ppcVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  size_t sVar12;
  undefined *puVar13;
  char *pcVar14;
  char *pcVar15;
  size_t sVar16;
  size_t sVar17;
  void *__dest;
  undefined2 *puVar18;
  ulong uVar19;
  long lVar20;
  int iVar21;
  ushort **ppuVar22;
  __int32_t **pp_Var23;
  int *piVar24;
  int *piVar25;
  char cVar26;
  char *pcVar27;
  int iVar28;
  int *piVar29;
  int iVar30;
  code *pcVar31;
  int *piVar32;
  int iVar33;
  undefined4 *puVar34;
  undefined4 *puVar35;
  uint uVar36;
  byte *pbVar37;
  byte *pbVar38;
  code **ppcVar39;
  int **ppiVar40;
  undefined uVar41;
  uint uVar42;
  bool bVar43;
  int *local_11c;
  undefined4 *local_10c;
  uint local_108;
  size_t local_104;
  int local_100;
  uint local_fc;
  int *local_f8;
  int **local_f0;
  uint local_e0;
  int local_d8;
  int iStack_d4;
  undefined uStack_cd;
  int local_cc;
  int local_c8;
  int local_c4;
  char *local_c0;
  int *local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined local_97;
  
  uVar8 = *(undefined4 *)(param_1 + 0x40);
  *param_3 = '\0';
  local_cc = 0;
  local_c8 = 0;
  uVar9 = Curl_multi_max_host_connections(uVar8);
  uVar10 = Curl_multi_max_total_connections(*(undefined4 *)(param_1 + 0x40));
  iVar30 = *(int *)(param_1 + 0x450);
  *param_3 = '\0';
  if (iVar30 == 0) {
    iVar30 = 3;
    pcVar27 = (char *)0x0;
    ppcVar39 = DAT_00045fa4;
    goto LAB_00045eb2;
  }
  piVar11 = (int *)(*Curl_ccalloc)(1,0x478);
  iVar30 = DAT_00045f94;
  ppcVar39 = DAT_00045fa4;
  if (piVar11 != (int *)0x0) {
    uVar41 = 1;
    piVar11[0x55] = -1;
    piVar11[0x86] = iVar30;
    piVar11[0x56] = -1;
    piVar11[0x57] = -1;
    piVar11[0x58] = -1;
    piVar11[0x11] = -1;
    piVar11[0x2c] = -1;
    piVar11[0x2d] = -1;
    *(undefined *)((int)piVar11 + 0x1ed) = 1;
    curlx_tvnow(&local_d8);
    uVar42 = *(uint *)(param_1 + 0x2c4);
    pcVar27 = *(char **)(param_1 + 0x380);
    *piVar11 = param_1;
    piVar11[0x53] = local_d8;
    piVar11[0x54] = iStack_d4;
    piVar11[0x4e] = uVar42;
    if ((pcVar27 == (char *)0x0) || (*pcVar27 == '\0')) {
      *(undefined *)((int)piVar11 + 0x1ef) = 0;
LAB_00045d16:
      uVar41 = 0;
    }
    else {
      *(undefined *)((int)piVar11 + 0x1ef) = 1;
      if (1 < uVar42) goto LAB_00045d16;
    }
    iVar30 = *(int *)(param_1 + 0x3c0);
    iVar28 = *(int *)(param_1 + 0x3b4);
    uVar1 = *(undefined *)(param_1 + 0x2fa);
    uVar2 = *(undefined *)(param_1 + 0x314);
    if (iVar30 != 0) {
      iVar30 = 1;
    }
    if (iVar28 != 0) {
      iVar28 = 1;
    }
    uVar3 = *(undefined *)(param_1 + 0x315);
    *(undefined *)(piVar11 + 0x7c) = uVar41;
    uVar41 = *(undefined *)(param_1 + 0x288);
    *(char *)((int)piVar11 + 0x1f1) = (char)iVar28;
    uVar4 = *(undefined *)(param_1 + 0x289);
    *(char *)((int)piVar11 + 0x1f2) = (char)iVar30;
    *(undefined *)((int)piVar11 + 0x1fa) = uVar1;
    *(undefined *)((int)piVar11 + 0x459) = uVar4;
    iVar30 = *(int *)(param_1 + 0x2d8);
    *(undefined *)((int)piVar11 + 0x1fd) = uVar2;
    piVar11[0xa9] = -1;
    *(undefined *)((int)piVar11 + 0x1fe) = uVar3;
    *(undefined *)(piVar11 + 0x116) = uVar41;
    piVar11[0x88] = iVar30;
    piVar11[0xaa] = 0;
    piVar11[0xab] = 0;
    piVar11[0xac] = 0;
    iVar30 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40),1);
    if ((iVar30 == 0) || (piVar11[0x98] != 0)) {
LAB_00045d94:
      iVar30 = Curl_llist_alloc(DAT_00045f98);
      piVar11[0x96] = iVar30;
      iVar30 = Curl_llist_alloc(DAT_00045f98);
      iVar28 = piVar11[0x96];
      piVar11[0x97] = iVar30;
      if ((iVar28 != 0) && (iVar30 != 0)) {
        if (*(int *)(param_1 + 0x358) != 0) {
          iVar30 = (**DAT_00045f9c)();
          piVar11[0x117] = iVar30;
          if (iVar30 == 0) goto LAB_00045f48;
        }
        uVar5 = *(undefined2 *)(param_1 + 0x1a0);
        iVar30 = *(int *)(param_1 + 0x1e0);
        iVar28 = *(int *)(param_1 + 0x1e4);
        piVar11[0x119] = *(int *)(param_1 + 0x1a4);
        *(undefined2 *)(piVar11 + 0x118) = uVar5;
        piVar11[0xe] = iVar30;
        piVar11[0xf] = iVar28;
        *param_2 = piVar11;
        sVar12 = strlen(*(char **)(param_1 + 0x450));
        ppcVar7 = DAT_00045fa8;
        ppcVar39 = DAT_00045fa4;
        if (sVar12 < 0x100) {
          local_11c = (int *)0x102;
        }
        else {
          local_11c = (int *)(sVar12 + 2);
        }
        (**DAT_00045fa4)(*(undefined4 *)(param_1 + 0x8688));
        *(undefined4 *)(param_1 + 0x8688) = 0;
        *(undefined4 *)(param_1 + 0x868c) = 0;
        iVar30 = (**ppcVar7)(local_11c);
        *(int *)(param_1 + 0x8688) = iVar30;
        if (iVar30 == 0) {
          pcVar27 = (char *)0x0;
LAB_00045e9a:
          iVar30 = 0x1b;
          goto LAB_00045eb2;
        }
        *(int *)(param_1 + 0x868c) = iVar30;
        puVar13 = (undefined *)(**ppcVar7)(local_11c);
        piVar11[0x24] = (int)puVar13;
        if (puVar13 == (undefined *)0x0) {
          iVar30 = 0x1b;
          (**ppcVar39)(*(undefined4 *)(param_1 + 0x8688));
          *(undefined4 *)(param_1 + 0x8688) = 0;
          *(undefined4 *)(param_1 + 0x868c) = 0;
          pcVar27 = (char *)0x0;
          goto LAB_00045eb2;
        }
        piVar11[0x26] = (int)puVar13;
        *puVar13 = 0;
        local_cc = (*Curl_cstrdup)(DAT_00045fa0);
        local_c8 = (*Curl_cstrdup)(DAT_00045fa0);
        pcVar27 = (char *)(*Curl_cstrdup)(DAT_00045fa0);
        if ((local_cc == 0 || local_c8 == 0) || (pcVar27 == (char *)0x0)) goto LAB_00045e9a;
        pcVar14 = *(char **)(param_1 + 0x450);
        local_b8 = 0;
        local_b4 = 0;
        local_b0 = 0;
        local_ac = 0;
        local_11c = *(int **)(param_1 + 0x868c);
        cVar26 = *pcVar14;
        pcVar15 = pcVar14;
        while (cVar26 != '\0') {
          if ((cVar26 == '\r') || (cVar26 == '\n')) {
            Curl_failf(param_1,DAT_000464c4);
            iVar30 = 3;
            goto LAB_00045eb2;
          }
          pcVar15 = pcVar15 + 1;
          cVar26 = *pcVar15;
        }
        iVar30 = __isoc99_sscanf(pcVar14,DAT_000462b8,&local_b8,local_11c);
        if ((iVar30 == 2) && (iVar30 = Curl_raw_equal(&local_b8,DAT_000464c8), iVar30 != 0)) {
          if (*(char *)local_11c == '/') {
            if (*(char *)((int)local_11c + 1) == '/') {
              sVar12 = strlen((char *)(undefined2 *)((int)local_11c + 2));
              memmove(local_11c,(undefined2 *)((int)local_11c + 2),sVar12 + 1);
              if (*(char *)local_11c != '/') goto LAB_0004630c;
              bVar43 = false;
              local_10c = DAT_00047894;
            }
            else {
              bVar43 = false;
              local_10c = DAT_00046f00;
            }
          }
          else {
LAB_0004630c:
            pcVar15 = strchr((char *)local_11c,0x2f);
            if (pcVar15 == (char *)0x0) {
              local_10c = DAT_00047894;
              bVar43 = false;
            }
            else {
              bVar43 = false;
              if (pcVar15[1] == '/') {
                pcVar15 = pcVar15 + 1;
              }
              sVar12 = strlen(pcVar15);
              memmove(local_11c,pcVar15,sVar12 + 1);
              local_10c = DAT_000464c8;
            }
          }
        }
        else {
          uVar8 = DAT_000462bc;
          *(undefined *)local_11c = 0;
          puVar18 = (undefined2 *)local_11c;
          iVar30 = __isoc99_sscanf(*(undefined4 *)(param_1 + 0x450),uVar8,&local_b8,piVar11[0x26],
                                   local_11c);
          local_10c = &local_b8;
          if (iVar30 < 2) {
            iVar30 = __isoc99_sscanf(*(undefined4 *)(param_1 + 0x450),DAT_000464d0,piVar11[0x26],
                                     local_11c,puVar18);
            if (iVar30 < 1) {
              Curl_failf(param_1,DAT_00046efc);
              iVar30 = 3;
              goto LAB_00045eb2;
            }
            local_10c = *(undefined4 **)(param_1 + 0x354);
            if (local_10c == (undefined4 *)0x0) {
              iVar30 = Curl_raw_nequal(DAT_0004788c,piVar11[0x26],4);
              if (iVar30 == 0) {
                iVar30 = Curl_raw_nequal(DAT_00047898,piVar11[0x26],5);
                if (iVar30 == 0) {
                  iVar30 = Curl_raw_nequal(DAT_000478a8,piVar11[0x26],5);
                  if (iVar30 == 0) {
                    iVar30 = Curl_raw_nequal(DAT_000478bc,piVar11[0x26],5);
                    if (iVar30 == 0) {
                      iVar30 = Curl_raw_nequal(DAT_000478cc,piVar11[0x26],5);
                      if (iVar30 == 0) {
                        bVar43 = true;
                        iVar30 = Curl_raw_nequal(DAT_000478dc,piVar11[0x26],5);
                        local_10c = DAT_000478e0;
                        if (iVar30 != 0) {
                          local_10c = DAT_000478e4;
                        }
                      }
                      else {
                        bVar43 = true;
                        local_10c = DAT_000478d0;
                      }
                    }
                    else {
                      bVar43 = true;
                      local_10c = DAT_000478c0;
                    }
                  }
                  else {
                    bVar43 = true;
                    local_10c = DAT_000478ac;
                  }
                }
                else {
                  bVar43 = true;
                  local_10c = DAT_0004789c;
                }
              }
              else {
                bVar43 = true;
                local_10c = DAT_00047890;
              }
            }
            else {
              bVar43 = true;
            }
          }
          else {
            bVar43 = false;
          }
        }
        pcVar14 = (char *)piVar11[0x26];
        pcVar15 = strchr(pcVar14,0x40);
        if (pcVar15 == (char *)0x0) {
          pcVar15 = strchr(pcVar14,0x3f);
        }
        else {
          pcVar15 = strchr(pcVar15 + 1,0x3f);
        }
        if (pcVar15 == (char *)0x0) {
          cVar26 = *(char *)local_11c;
          if (cVar26 == '\0') {
            bVar6 = true;
            *(undefined2 *)local_11c = *DAT_000464d4;
            cVar26 = *(char *)local_11c;
          }
          else {
            bVar6 = false;
          }
        }
        else {
          bVar6 = true;
          sVar12 = strlen(pcVar15);
          sVar16 = strlen((char *)local_11c);
          memmove((void *)((int)local_11c + sVar12 + 1),local_11c,sVar16 + 1);
          memcpy((void *)((int)local_11c + 1),pcVar15,sVar12);
          *(undefined *)local_11c = 0x2f;
          *pcVar15 = '\0';
          cVar26 = *(char *)local_11c;
        }
        if (cVar26 == '?') {
          sVar12 = strlen((char *)local_11c);
          memmove((void *)((int)local_11c + 1),local_11c,sVar12 + 1);
          *(undefined *)local_11c = 0x2f;
LAB_000460c2:
          sVar12 = strlen((char *)local_11c);
          sVar16 = strlen(*(char **)(param_1 + 0x450));
          local_104 = strlen((char *)piVar11[0x26]);
          if (!bVar43) {
            sVar17 = strlen((char *)local_10c);
            local_104 = local_104 + 3 + sVar17;
          }
          __dest = (void *)(**ppcVar7)(sVar16 + 2);
          if (__dest == (void *)0x0) goto LAB_00045e9a;
          memcpy(__dest,*(void **)(param_1 + 0x450),local_104);
          memcpy((void *)((int)__dest + local_104),local_11c,sVar12 + 1);
          if (*(char *)(param_1 + 0x454) != '\0') {
            (**ppcVar39)(*(undefined4 *)(param_1 + 0x450));
            *(undefined4 *)(param_1 + 0x450) = 0;
            *(undefined *)(param_1 + 0x454) = 0;
          }
          Curl_infof(param_1,DAT_000462c0,__dest);
          *(void **)(param_1 + 0x450) = __dest;
          *(undefined *)(param_1 + 0x454) = 1;
        }
        else {
          if (*(char *)(param_1 + 0x43e) == '\0') {
            puVar18 = (undefined2 *)Curl_dedotdotify(local_11c);
            if (puVar18 == (undefined2 *)0x0) goto LAB_00045e9a;
            iVar30 = strcmp((char *)puVar18,(char *)local_11c);
            if (iVar30 != 0) {
              (**ppcVar39)(*(undefined4 *)(param_1 + 0x8688));
              *(undefined2 **)(param_1 + 0x8688) = puVar18;
              *(undefined2 **)(param_1 + 0x868c) = puVar18;
              local_11c = (int *)puVar18;
              goto LAB_000460c2;
            }
            (**ppcVar39)(puVar18);
          }
          if (bVar6) goto LAB_000460c2;
        }
        local_c0 = (char *)0x0;
        local_bc = (int *)0x0;
        pcVar14 = (char *)piVar11[0x26];
        local_c4 = 0;
        pcVar15 = strchr(pcVar14,0x40);
        if (pcVar15 != (char *)0x0) {
          iVar30 = *(int *)(param_1 + 0x30c);
          piVar11[0x26] = (int)(pcVar15 + 1);
          if (iVar30 != 2) {
            iVar30 = parse_login_details(pcVar14,pcVar15 + 1 + (-1 - (int)pcVar14),&local_c4,
                                         &local_c0,&local_bc);
            if (iVar30 == 0) {
              if (local_c4 == 0) {
LAB_000461b2:
                if (local_c0 != (char *)0x0) {
                  iVar30 = curl_easy_unescape(param_1,local_c0,0,0);
                  if (iVar30 == 0) goto LAB_00046340;
                  (**ppcVar39)(local_c8);
                  local_c8 = iVar30;
                }
                if (local_bc != (int *)0x0) {
                  pcVar15 = (char *)curl_easy_unescape(param_1,local_bc,0,0);
                  if (pcVar15 == (char *)0x0) goto LAB_00046340;
                  (**ppcVar39)(pcVar27);
                  pcVar27 = pcVar15;
                }
                goto LAB_000461f4;
              }
              *(undefined *)(piVar11 + 0x80) = 1;
              *(undefined *)((int)piVar11 + 0x1f1) = 1;
              iVar30 = curl_easy_unescape(param_1,local_c4,0,0);
              if (iVar30 != 0) {
                (**ppcVar39)(local_cc);
                local_cc = iVar30;
                goto LAB_000461b2;
              }
LAB_00046340:
              iVar30 = 0x1b;
            }
            (**ppcVar39)(local_c4);
            (**ppcVar39)(local_c0);
            (**ppcVar39)(local_bc);
            goto LAB_00045eb2;
          }
        }
LAB_000461f4:
        (**ppcVar39)(local_c4);
        (**ppcVar39)(local_c0);
        (**ppcVar39)(local_bc);
        if ((*(char *)piVar11[0x26] == '[') &&
           (pcVar15 = strchr((char *)piVar11[0x26],0x25), pcVar15 != (char *)0x0)) {
          iVar30 = strncmp(DAT_000464cc,pcVar15,3);
          if (iVar30 == 0) {
            local_100 = 3;
          }
          else {
            Curl_infof(param_1,DAT_00047588);
            local_100 = 1;
          }
          uVar19 = strtoul(pcVar15 + local_100,(char **)&local_bc,10);
          piVar25 = local_bc;
          if (*(char *)local_bc == ']') {
            sVar12 = strlen((char *)local_bc);
            memmove(pcVar15,piVar25,sVar12 + 1);
            piVar11[0x22] = uVar19;
          }
          else {
            strncpy((char *)&local_a8,pcVar15 + local_100,0x12);
            local_97 = 0;
            pcVar14 = strchr((char *)&local_a8,0x5d);
            if (pcVar14 != (char *)0x0) {
              *pcVar14 = '\0';
              uVar42 = if_nametoindex((char *)&local_a8);
              if (uVar42 != 0) {
                sVar12 = strlen((char *)&local_a8);
                sVar16 = strlen(pcVar15 + sVar12 + local_100);
                memmove(pcVar15,pcVar15 + sVar12 + local_100,sVar16 + 1);
                piVar11[0x22] = uVar42;
                goto LAB_00046218;
              }
              piVar25 = __errno_location();
              pcVar15 = strerror(*piVar25);
              Curl_infof(param_1,DAT_000478c4,&local_a8,pcVar15);
            }
            Curl_infof(param_1,DAT_000478c8);
          }
        }
LAB_00046218:
        if (*(int *)(param_1 + 0x3f8) != 0) {
          piVar11[0x22] = *(int *)(param_1 + 0x3f8);
        }
        pcVar15 = strchr((char *)local_11c,0x23);
        puVar35 = DAT_000462c4;
        puVar34 = DAT_000462cc;
        if (pcVar15 != (char *)0x0) {
          *pcVar15 = '\0';
          pcVar15 = strchr(*(char **)(param_1 + 0x450),0x23);
          puVar35 = DAT_000462c4;
          puVar34 = DAT_000462cc;
          if (pcVar15 != (char *)0x0) {
            *pcVar15 = '\0';
            puVar35 = DAT_000462c4;
            puVar34 = DAT_000462cc;
          }
        }
LAB_00046266:
        iVar30 = Curl_raw_equal(*puVar34,local_10c);
        if (iVar30 == 0) goto LAB_0004625c;
        if (((puVar34[0xf] & *(uint *)(param_1 + 0x3fc)) == 0) ||
           ((*(char *)(param_1 + 0x85a8) != '\0' &&
            ((puVar34[0xf] & *(uint *)(param_1 + 0x400)) == 0)))) goto LAB_000462a6;
        piVar11[0x87] = (int)puVar34;
        piVar11[0x86] = (int)puVar34;
        if (!bVar43) goto LAB_000464e6;
        pbVar37 = (byte *)curl_maprintf(DAT_00046814,*puVar34,*(undefined4 *)(param_1 + 0x450));
        if (pbVar37 == (byte *)0x0) goto LAB_00045e9a;
        uVar42 = (uint)*pbVar37;
        if (uVar42 != 0x3a) {
          pbVar38 = pbVar37 + -1;
          do {
            pp_Var23 = __ctype_tolower_loc();
            pbVar38[1] = (byte)(*pp_Var23)[uVar42];
            uVar42 = (uint)pbVar38[2];
            pbVar38 = pbVar38 + 1;
          } while (uVar42 != 0x3a);
        }
        if (*(char *)(param_1 + 0x454) != '\0') {
          (**ppcVar39)(*(undefined4 *)(param_1 + 0x450));
        }
        *(undefined *)(param_1 + 0x454) = 1;
        *(byte **)(param_1 + 0x450) = pbVar37;
LAB_000464e6:
        if ((*(int *)(piVar11[0x87] + 0x40) << 0x19 < 0) &&
           (pcVar15 = strchr(*(char **)(*piVar11 + 0x868c),0x3f), pcVar15 != (char *)0x0)) {
          *pcVar15 = '\0';
        }
        if (*(int *)(param_1 + 1000) != 0) {
          iVar30 = (*Curl_cstrdup)();
          piVar11[0x4b] = iVar30;
          if (iVar30 != 0) goto LAB_00046522;
          goto LAB_00045e9a;
        }
LAB_00046522:
        if ((*(char *)((int)piVar11 + 0x1f2) != '\0') &&
           (iVar30 = parse_proxy_auth(param_1,piVar11), iVar30 != 0)) goto LAB_00045eb2;
        if (*(int *)(param_1 + 0x380) == 0) {
          local_11c = (int *)0x0;
        }
        else {
          local_11c = (int *)(*Curl_cstrdup)();
          if (local_11c == (int *)0x0) {
            Curl_failf(param_1,DAT_00046ecc);
            iVar30 = 0x1b;
            goto LAB_00045eb2;
          }
        }
        if ((*(int *)(param_1 + 0x3c8) == 0) || (iVar30 = check_noproxy(piVar11[0x26]), iVar30 == 0)
           ) {
          if (local_11c == (int *)0x0) {
            local_10c = (undefined4 *)curl_getenv(DAT_00046ed4);
            if (local_10c == (undefined4 *)0x0) {
              local_10c = (undefined4 *)curl_getenv(DAT_00047bcc);
            }
            iVar30 = check_noproxy(piVar11[0x26],local_10c);
            if (iVar30 == 0) {
              pbVar37 = *(byte **)piVar11[0x86];
              uVar42 = (uint)*pbVar37;
              puVar35 = &local_a8;
              if (uVar42 != 0) {
                puVar34 = &local_a8;
                do {
                  puVar35 = (undefined4 *)((int)puVar34 + 1);
                  pp_Var23 = __ctype_tolower_loc();
                  *(char *)puVar34 = (char)(*pp_Var23)[uVar42];
                  pbVar37 = pbVar37 + 1;
                  uVar42 = (uint)*pbVar37;
                  puVar34 = puVar35;
                } while (uVar42 != 0);
              }
              uVar5 = *(undefined2 *)(DAT_00046ed8 + 1);
              uVar41 = *(undefined *)((int)DAT_00046ed8 + 6);
              *puVar35 = *DAT_00046ed8;
              *(undefined2 *)(puVar35 + 1) = uVar5;
              *(undefined *)((int)puVar35 + 6) = uVar41;
              local_11c = (int *)curl_getenv(&local_a8);
              if (local_11c == (int *)0x0) {
                iVar30 = Curl_raw_equal(DAT_00047bc0,&local_a8);
                if (iVar30 == 0) {
                  Curl_strntoupper(&local_a8,&local_a8,0x80);
                  local_11c = (int *)curl_getenv(&local_a8);
                  if (local_11c != (int *)0x0) goto LAB_00046d36;
                }
                local_11c = (int *)curl_getenv(DAT_00047bc4);
                if (local_11c == (int *)0x0) {
                  local_11c = (int *)curl_getenv(DAT_00047bc8);
                  (**ppcVar39)(local_10c);
                  if (local_11c != (int *)0x0) goto LAB_00046564;
                  goto LAB_00046574;
                }
              }
LAB_00046d36:
              (**ppcVar39)(local_10c);
              goto LAB_00046564;
            }
            (**ppcVar39)(local_10c);
            goto LAB_00046574;
          }
LAB_00046564:
          if (((*(int *)(param_1 + 0x3ec) != 0) || (*(byte *)local_11c == 0)) ||
             (*(int *)(piVar11[0x86] + 0x40) << 0x1b < 0)) goto LAB_0004656c;
          pcVar15 = strstr((char *)local_11c,DAT_00046818);
          pbVar37 = (byte *)local_11c;
          if (pcVar15 != (char *)0x0) {
            pbVar37 = (byte *)(pcVar15 + 3);
            iVar30 = Curl_raw_nequal(DAT_0004681c,local_11c,7);
            if (iVar30 == 0) {
              iVar30 = Curl_raw_nequal(DAT_00046ec8,local_11c,6);
              if (iVar30 == 0) {
                iVar30 = Curl_raw_nequal(DAT_00046edc,local_11c,7);
                if (iVar30 == 0) {
                  iVar30 = Curl_raw_nequal(DAT_00046f54,local_11c,6);
                  if ((iVar30 != 0) ||
                     (iVar30 = Curl_raw_nequal(DAT_00047888,local_11c,5), iVar30 != 0)) {
                    piVar11[0x4e] = 4;
                  }
                }
                else {
                  piVar11[0x4e] = 6;
                }
              }
              else {
                piVar11[0x4e] = 5;
              }
            }
            else {
              piVar11[0x4e] = 7;
            }
          }
          pcVar15 = strchr((char *)pbVar37,0x40);
          if (pcVar15 != (char *)0x0) {
            local_c0 = (char *)0x0;
            local_bc = (int *)0x0;
            iVar30 = parse_login_details(pbVar37,(int)pcVar15 - (int)pbVar37,&local_c0,&local_bc,0);
            if (iVar30 == 0) {
              (**ppcVar39)(piVar11[0x4c]);
              pcVar14 = local_c0;
              piVar11[0x4c] = 0;
              if ((local_c0 == (char *)0x0) || (sVar12 = strlen(local_c0), 0xff < sVar12)) {
                iVar30 = (*Curl_cstrdup)(DAT_00046820);
                piVar11[0x4c] = iVar30;
              }
              else {
                iVar30 = curl_easy_unescape(param_1,pcVar14,0,0);
                piVar11[0x4c] = iVar30;
              }
              if (iVar30 != 0) {
                (**ppcVar39)(piVar11[0x4d]);
                piVar25 = local_bc;
                piVar11[0x4d] = 0;
                if ((local_bc == (int *)0x0) || (sVar12 = strlen((char *)local_bc), 0xff < sVar12))
                {
                  iVar30 = (*Curl_cstrdup)(DAT_00046820);
                  piVar11[0x4d] = iVar30;
                }
                else {
                  iVar30 = curl_easy_unescape(param_1,piVar25,0,0);
                  piVar11[0x4d] = iVar30;
                }
                if (piVar11[0x4d] != 0) {
                  pcVar31 = *ppcVar39;
                  *(undefined *)((int)piVar11 + 0x1f2) = 1;
                  pbVar37 = (byte *)(pcVar15 + 1);
                  (*pcVar31)(local_c0);
                  (**ppcVar39)(local_bc);
                  goto LAB_0004676c;
                }
              }
              iVar30 = 0x1b;
            }
            (**ppcVar39)(local_c0);
            (**ppcVar39)(local_bc);
LAB_000466c6:
            (**ppcVar39)(local_11c);
            goto LAB_00045eb2;
          }
LAB_0004676c:
          local_10c = (undefined4 *)pbVar37;
          if (*pbVar37 == 0x5b) {
            uVar42 = (uint)pbVar37[1];
            local_10c = (undefined4 *)(pbVar37 + 1);
            pbVar38 = (byte *)local_10c;
            if (uVar42 != 0) {
              ppuVar22 = __ctype_b_loc();
              pbVar37 = (byte *)local_10c;
              do {
                if (((-1 < (int)((uint)(*ppuVar22)[uVar42] << 0x13)) && (uVar42 != 0x3a)) &&
                   (uVar42 != 0x2e)) {
                  pbVar38 = pbVar37;
                  if (uVar42 == 0x25) {
                    iVar30 = strncmp(DAT_00046ee0,(char *)pbVar37,3);
                    if (iVar30 != 0) {
                      Curl_infof(param_1,DAT_00046f04);
                    }
                    pbVar38 = pbVar37 + 1;
                    uVar42 = (uint)pbVar37[1];
                    if (uVar42 != 0) {
                      do {
                        if (((((*ppuVar22)[uVar42] & 0x1400) == 0) && (uVar42 != 0x2d)) &&
                           ((uVar42 != 0x2e && ((uVar42 != 0x5f && (uVar42 != 0x7e))))))
                        goto LAB_00046ea2;
                        pbVar38 = pbVar38 + 1;
                        uVar42 = (uint)*pbVar38;
                      } while (uVar42 != 0);
                    }
                  }
                  else {
LAB_00046ea2:
                    if (*pbVar38 == 0x5d) {
                      pbVar37 = pbVar38 + 1;
                      *pbVar38 = 0;
                      goto LAB_0004677c;
                    }
                  }
                  break;
                }
                pbVar37 = pbVar37 + 1;
                uVar42 = (uint)*pbVar37;
                pbVar38 = pbVar37;
              } while (uVar42 != 0);
            }
            Curl_infof(param_1,DAT_00046ec4);
            pbVar37 = pbVar38;
          }
LAB_0004677c:
          pcVar15 = strchr((char *)pbVar37,0x3a);
          if (pcVar15 == (char *)0x0) {
            if (*(byte *)local_10c == 0x2f) {
              iVar30 = 5;
              goto LAB_000466c6;
            }
            pcVar15 = strchr((char *)local_10c,0x2f);
            if (pcVar15 != (char *)0x0) {
              *pcVar15 = '\0';
            }
            if (*(int *)(param_1 + 0x15c) != 0) {
              piVar11[0x2c] = *(int *)(param_1 + 0x15c);
            }
          }
          else {
            local_bc = (int *)0x0;
            *pcVar15 = '\0';
            lVar20 = strtol(pcVar15 + 1,(char **)&local_bc,10);
            if (((((local_bc == (int *)0x0) || (cVar26 = *(char *)local_bc, cVar26 == '\0')) ||
                 (cVar26 == '/')) || (cVar26 == ' ')) && (lVar20 < 0x10000)) {
              piVar11[0x2c] = lVar20;
            }
            else {
              Curl_infof(param_1,DAT_00046824,pcVar15 + 1);
            }
          }
          iVar30 = (*Curl_cstrdup)(local_10c);
          piVar11[0x28] = iVar30;
          piVar11[0x2a] = iVar30;
          if (iVar30 == 0) {
            iVar30 = 0x1b;
            goto LAB_000466c6;
          }
          (**ppcVar39)(local_11c);
          uVar36 = piVar11[0x4e];
          uVar42 = uVar36;
          if (1 < uVar36) {
            uVar42 = 0;
          }
          if (uVar36 < 2) {
            if (((*(uint *)(piVar11[0x86] + 0x3c) & 3) == 0) &&
               (*(char *)((int)piVar11 + 0x1fa) == '\0')) {
              piVar11[0x86] = (int)Curl_handler_http;
            }
            *(undefined *)(piVar11 + 0x7c) = 1;
          }
          else {
            *(char *)(piVar11 + 0x7c) = (char)uVar42;
            *(char *)((int)piVar11 + 0x1fa) = (char)uVar42;
          }
          *(undefined *)((int)piVar11 + 0x1ef) = 1;
        }
        else {
LAB_0004656c:
          (**ppcVar39)(local_11c);
LAB_00046574:
          *(undefined *)((int)piVar11 + 0x1ef) = 0;
          *(undefined *)(piVar11 + 0x7c) = 0;
          *(undefined *)((int)piVar11 + 0x1f2) = 0;
          *(undefined *)((int)piVar11 + 0x1fa) = 0;
        }
        if ((*(int *)(piVar11[0x87] + 0x40) << 0x1f < 0) && (*(char *)(piVar11 + 0x7c) != '\0')) {
          *(undefined *)((int)piVar11 + 0x1fa) = 1;
        }
        iVar30 = __isoc99_sscanf(piVar11[0x26],DAT_0004680c,&local_c0);
        if ((iVar30 == 1) && (((uint)local_c0 & 0xff) == 0x5d)) {
          iVar30 = piVar11[0x26];
          *(undefined *)((int)piVar11 + 499) = 1;
          piVar11[0x26] = (int)(char *)(iVar30 + 1);
          pcVar15 = strchr((char *)(iVar30 + 1),0x5d);
          if (pcVar15 != (char *)0x0) {
            *pcVar15 = '\0';
            if (pcVar15[1] == ':') {
              pcVar15 = pcVar15 + 1;
            }
            else {
              pcVar15 = (char *)0x0;
            }
          }
        }
        else {
          iVar30 = inet_pton(10,(char *)piVar11[0x26],&local_a8);
          if (0 < iVar30) {
            Curl_failf(param_1,DAT_00046810);
            iVar30 = 3;
            goto LAB_00045eb2;
          }
          pcVar15 = strrchr((char *)piVar11[0x26],0x3a);
        }
        if ((*(uint *)(param_1 + 0x170) == 0) || (*(char *)(param_1 + 0x85d4) == '\0')) {
          if (pcVar15 != (char *)0x0) {
            uVar42 = strtol(pcVar15 + 1,(char **)&local_bc,10);
            if (0xffff < uVar42) {
              Curl_failf(param_1,DAT_00046ed0);
              iVar30 = 3;
              goto LAB_00045eb2;
            }
            *pcVar15 = '\0';
            if ((int *)(pcVar15 + 1) != local_bc) {
              iVar30 = curlx_ultous();
              piVar11[0x2d] = iVar30;
            }
          }
        }
        else {
          piVar11[0x2d] = *(uint *)(param_1 + 0x170) & 0xffff;
          if (pcVar15 != (char *)0x0) {
            *pcVar15 = '\0';
          }
          if (*(char *)(piVar11 + 0x7c) != '\0') {
            local_a8 = 0;
            local_a4 = 0;
            local_a0 = 0;
            if (*(char *)(piVar11 + 0x81) != '\0') {
              if (*(char *)(param_1 + 0x2fb) == '\0') {
                if (*(char *)(param_1 + 0x2fd) == '\0') {
                  uVar8 = 0x49;
                }
                else {
                  uVar8 = 0x44;
                }
              }
              else {
                uVar8 = 0x41;
              }
              curl_msnprintf(&local_a8,0xc,DAT_00046ef8,uVar8);
            }
            if (*(char *)((int)piVar11 + 499) == '\0') {
              local_10c = (undefined4 *)DAT_00046ef4;
              iVar30 = piVar11[0x26];
              uVar8 = DAT_00046ef4;
            }
            else {
              iVar30 = piVar11[0x26];
              local_10c = (undefined4 *)DAT_00046b68;
              uVar8 = DAT_00046b64;
            }
            puVar18 = &DAT_00135588;
            if (*(char *)(param_1 + 0x8690) == '\0') {
              puVar18 = DAT_00046b7c;
            }
            iVar30 = curl_maprintf(DAT_00046b6c,*(undefined4 *)piVar11[0x87],uVar8,iVar30,local_10c,
                                   piVar11[0x2d],puVar18,*(undefined4 *)(param_1 + 0x868c),&local_a8
                                  );
            if (iVar30 == 0) goto LAB_00045e9a;
            if (*(char *)(param_1 + 0x454) != '\0') {
              (**ppcVar39)(*(undefined4 *)(param_1 + 0x450));
            }
            *(int *)(param_1 + 0x450) = iVar30;
            *(undefined *)(param_1 + 0x454) = 1;
          }
        }
        if (*(int *)(param_1 + 0x3b4) != 0) {
          (**ppcVar39)(local_cc);
          local_cc = (*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x3b4));
          if (local_cc == 0) goto LAB_00045e9a;
        }
        if (*(int *)(param_1 + 0x3b8) != 0) {
          (**ppcVar39)(local_c8);
          local_c8 = (*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x3b8));
          if (local_c8 == 0) goto LAB_00045e9a;
        }
        if (*(int *)(param_1 + 0x3bc) != 0) {
          (**ppcVar39)(pcVar27);
          pcVar27 = (char *)(*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x3bc));
          if (pcVar27 == (char *)0x0) goto LAB_00045e9a;
        }
        iVar30 = *(int *)(param_1 + 0x30c);
        *(undefined *)((int)piVar11 + 0x1ff) = 0;
        if (iVar30 != 0) {
          iVar30 = Curl_parsenetrc(piVar11[0x26],&local_cc,&local_c8,
                                   *(undefined4 *)(param_1 + 0x37c));
          if (iVar30 < 1) {
            if (iVar30 != 0) goto LAB_00045e9a;
            *(undefined *)((int)piVar11 + 0x1ff) = 1;
            *(undefined *)((int)piVar11 + 0x1f1) = 1;
          }
          else {
            Curl_infof(param_1,DAT_00046ef0,piVar11[0x26]);
          }
        }
        iVar30 = local_c8;
        if ((*(int *)(piVar11[0x86] + 0x40) << 0x1a < 0) &&
           (*(char *)((int)piVar11 + 0x1f1) == '\0')) {
          iVar28 = (*Curl_cstrdup)(DAT_00046ee4);
          ppcVar7 = DAT_00046ee8;
          piVar11[0x48] = iVar28;
          if (iVar28 == 0) {
LAB_00046d68:
            piVar11[0x49] = iVar28;
          }
          else {
            iVar30 = (**ppcVar7)(DAT_00046eec);
            piVar11[0x49] = iVar30;
          }
        }
        else {
          iVar28 = (*Curl_cstrdup)(local_cc);
          ppcVar7 = DAT_00046b70;
          piVar11[0x48] = iVar28;
          if (iVar28 == 0) goto LAB_00046d68;
          iVar30 = (**ppcVar7)(iVar30);
          piVar11[0x49] = iVar30;
        }
        if ((piVar11[0x48] == 0) || (piVar11[0x49] == 0)) goto LAB_00045e9a;
        if (*pcVar27 != '\0') {
          iVar30 = (*Curl_cstrdup)(pcVar27);
          piVar11[0x4a] = iVar30;
          if (iVar30 == 0) goto LAB_00045e9a;
        }
        fix_hostname_isra_2(param_1,piVar11 + 0x24);
        if (((char *)piVar11[0x2a] != (char *)0x0) && (*(char *)piVar11[0x2a] != '\0')) {
          fix_hostname_isra_2(param_1,piVar11 + 0x28);
        }
        iVar28 = *piVar11;
        (**ppcVar39)(*(undefined4 *)(iVar28 + 0x14c));
        pcVar31 = *ppcVar39;
        *(undefined4 *)(iVar28 + 0x14c) = 0;
        (*pcVar31)(*(undefined4 *)(iVar28 + 0x13c));
        *(undefined4 *)(iVar28 + 0x13c) = 0;
        memset((void *)(iVar28 + 0x50),0,0x100);
        iVar30 = piVar11[0x86];
        *(undefined4 *)(iVar28 + 0x60) = 0xffffffff;
        *(undefined4 *)(iVar28 + 100) = 0xffffffff;
        pcVar31 = *(code **)(iVar30 + 4);
        piVar11[0x23] = 1;
        if (pcVar31 != (code *)0x0) {
          iVar30 = (*pcVar31)(piVar11);
          if (iVar30 != 0) goto LAB_00045eb2;
          iVar30 = piVar11[0x86];
        }
        iVar28 = piVar11[0x2c];
        bVar43 = iVar28 < 0;
        if (bVar43) {
          iVar28 = *(int *)(iVar30 + 0x38);
        }
        if (bVar43) {
          piVar11[0x2c] = iVar28;
        }
        if (piVar11[0x2d] < 0) {
          piVar11[0x2d] = (uint)*(ushort *)(piVar11[0x87] + 0x38);
        }
        iVar33 = DAT_00046b78;
        iVar28 = DAT_00046b74;
        iVar21 = *(int *)(iVar30 + 0x40);
        piVar11[0x5a] = DAT_00046b74;
        piVar11[0x5b] = iVar28;
        piVar11[0x5c] = iVar33;
        piVar11[0x5d] = iVar33;
        if (iVar21 << 0x1b < 0) {
          iVar30 = (**(code **)(iVar30 + 0x14))(piVar11,&uStack_cd);
          if (iVar30 == 0) {
            *(undefined *)((int)piVar11 + 0x1f6) = 1;
            *piVar11 = param_1;
            Curl_conncache_add_conn(*(undefined4 *)(param_1 + 0x580),piVar11);
            iVar30 = setup_range(param_1);
            if (iVar30 != 0) {
              (**(code **)(piVar11[0x86] + 0xc))(piVar11,iVar30,0);
              goto LAB_00046ac8;
            }
            Curl_setup_transfer(piVar11,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
          }
          Curl_init_do(param_1,piVar11);
        }
        else {
          piVar25 = piVar11 + 0x6a;
          *(undefined4 *)(param_1 + 0x28c) = *(undefined4 *)(param_1 + 0x390);
          *(undefined4 *)(param_1 + 0x290) = *(undefined4 *)(param_1 + 0x394);
          *(undefined4 *)(param_1 + 0x294) = *(undefined4 *)(param_1 + 0x3ac);
          *(undefined4 *)(param_1 + 0x298) = *(undefined4 *)(param_1 + 0x3b0);
          *(undefined4 *)(param_1 + 0x29c) = *(undefined4 *)(param_1 + 0x3a4);
          *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)(param_1 + 0x3a0);
          *(undefined4 *)(param_1 + 0x2a4) = *(undefined4 *)(param_1 + 0x39c);
          *(undefined4 *)(param_1 + 0x2b8) = *(undefined4 *)(param_1 + 0x3e0);
          *(undefined4 *)(param_1 + 700) = *(undefined4 *)(param_1 + 0x3e4);
          iVar30 = Curl_clone_ssl_config(param_1 + 0x280,piVar25);
          if (iVar30 == 0) goto LAB_00045e9a;
          curlx_tvnow(&local_b8);
          iVar30 = curlx_tvdiff(local_b8,local_b4,*(undefined4 *)(*(int *)(param_1 + 0x580) + 0x20),
                                *(undefined4 *)(*(int *)(param_1 + 0x580) + 0x24));
          if (999 < iVar30) {
            Curl_conncache_foreach(*(undefined4 *)(param_1 + 0x580),param_1,DAT_000472a4);
            iVar30 = *(int *)(param_1 + 0x580);
            *(undefined4 *)(iVar30 + 0x20) = local_b8;
            *(undefined4 *)(iVar30 + 0x24) = local_b4;
          }
          if ((*(char *)(param_1 + 0x313) == '\0') || (*(char *)(param_1 + 0x85a8) != '\0')) {
            local_11c = (int *)IsPipeliningPossible(param_1,piVar11);
            if ((*(uint *)(param_1 + 0x8620) & 0x28) == 0) {
              local_108 = 0;
            }
            else {
              local_108 = *(uint *)(piVar11[0x86] + 0x3c) & 3;
              if (local_108 != 0) {
                local_108 = 1;
              }
            }
            local_10c = (undefined4 *)(uint)*(byte *)((int)piVar11 + 0x1f2);
            if (((local_10c != (undefined4 *)0x0) &&
                (local_10c = (undefined4 *)(*(uint *)(param_1 + 0x8630) & 0x28),
                local_10c != (undefined4 *)0x0)) &&
               (local_10c = (undefined4 *)(*(uint *)(piVar11[0x86] + 0x3c) & 3),
               local_10c != (undefined4 *)0x0)) {
              local_10c = (undefined4 *)0x1;
            }
            if (local_11c != (int *)0x0) {
              uVar42 = Curl_pipeline_site_blacklisted(param_1,piVar11);
              local_11c = (int *)((uVar42 ^ 1) & 0xff);
            }
            piVar24 = (int *)Curl_conncache_find_bundle(piVar11,*(undefined4 *)(param_1 + 0x580));
            if (piVar24 == (int *)0x0) goto LAB_000475ea;
            if (*piVar24 == 2) {
              iVar30 = piVar11[0x26];
              local_fc = 0;
              uVar8 = DAT_00047be4;
            }
            else {
              if (*(int *)(param_1 + 0x40) == 0) {
                local_fc = 0;
              }
              else {
                local_fc = *(uint *)(*(int *)(param_1 + 0x40) + 0xa0);
              }
              iVar30 = piVar11[0x26];
              uVar8 = DAT_000472ac;
              if (*piVar24 != 1) {
                uVar8 = DAT_000472a8;
              }
            }
            Curl_infof(param_1,DAT_000472b0,iVar30,piVar24,uVar8);
            if (local_11c != (int *)0x0) {
              iVar30 = *piVar24;
              if (0 < iVar30) {
LAB_000470ca:
                if (iVar30 == 1) {
                  iVar30 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40));
                  if (iVar30 == 0) {
                    Curl_infof(param_1,DAT_000478b0);
                    local_11c = (int *)0x0;
                    goto LAB_000470d6;
                  }
                  iVar30 = *piVar24;
                }
                if ((iVar30 == 2) &&
                   (iVar30 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40)), iVar30 == 0)) {
                  Curl_infof(param_1,DAT_000478a4);
                  local_11c = (int *)0x0;
                }
                goto LAB_000470d6;
              }
              if ((iVar30 != 0) || (*(char *)(param_1 + 0x43f) == '\0')) {
                Curl_infof(param_1,DAT_000478a0);
                iVar30 = *piVar24;
                local_11c = (int *)0x0;
                goto LAB_000470ca;
              }
              Curl_infof(param_1,DAT_000478b4);
              goto LAB_0004772e;
            }
LAB_000470d6:
            bVar43 = false;
            local_f0 = *(int ***)piVar24[2];
            local_f8 = (int *)0x0;
            local_e0 = local_fc;
LAB_00047102:
            if (local_f0 != (int **)0x0) {
              piVar24 = *local_f0;
              local_f0 = (int **)local_f0[2];
              iVar30 = disconnect_if_dead(piVar24,param_1);
              if (iVar30 == 0) {
                uVar42 = (int)((int **)piVar24[0x97])[3] + (int)((int **)piVar24[0x96])[3];
                if (local_11c != (int *)0x0) {
                  if (*(char *)((int)piVar24 + 0x205) == '\0') {
                    piVar29 = *(int **)piVar24[0x96];
                    piVar32 = *(int **)piVar24[0x97];
                    if (piVar29 == (int *)0x0) {
                      if (piVar32 != (int *)0x0) {
                        iVar30 = *piVar32;
LAB_00047b6e:
                        iVar28 = iVar30;
                        if (iVar28 != 0) goto LAB_00047156;
                      }
                    }
                    else {
                      iVar28 = *piVar29;
                      if (piVar32 == (int *)0x0) {
                        if (iVar28 == 0) goto LAB_00047160;
                      }
                      else {
                        iVar30 = *piVar32;
                        if (iVar28 == 0) goto LAB_00047b6e;
                      }
LAB_00047156:
                      iVar30 = IsPipeliningPossible(iVar28,piVar24);
                      if (iVar30 == 0) goto LAB_00047102;
                    }
                  }
LAB_00047160:
                  puVar35 = (undefined4 *)piVar11[0x86];
                  uVar36 = puVar35[0x10];
                  if ((((-1 < (int)((*(uint *)(piVar24[0x86] + 0x40) ^ uVar36) << 0x1f)) ||
                       ((iVar30 = get_protocol_family(*(undefined4 *)(piVar24[0x86] + 0x3c)),
                        iVar30 == puVar35[0xf] && (*(char *)(piVar24 + 0x7b) != '\0')))) &&
                      ((-1 < (int)(uVar36 << 0x1f) ||
                       (*(short *)(param_1 + 0x288) == *(short *)(piVar24 + 0x116))))) &&
                     ((*(char *)((int)piVar11 + 0x1ef) == *(char *)((int)piVar24 + 0x1ef) &&
                      ((local_11c != (int *)0x0 || (*(char *)(piVar24 + 0x10) == '\0')))))) {
                    pcVar15 = (char *)piVar11[0x117];
                    if (((pcVar15 == (char *)0x0) && (*(short *)(piVar11 + 0x118) == 0)) ||
                       ((((*(short *)(piVar24 + 0x118) == *(short *)(piVar11 + 0x118) &&
                          (piVar24[0x119] == piVar11[0x119])) &&
                         ((char *)piVar24[0x117] != (char *)0x0)) &&
                        ((pcVar15 != (char *)0x0 &&
                         (iVar30 = strcmp((char *)piVar24[0x117],pcVar15), iVar30 == 0)))))) {
                      if (-1 < (int)(uVar36 << 0x18)) {
                        iVar30 = curl_strequal(piVar11[0x48],piVar24[0x48]);
                        if ((iVar30 == 0) ||
                           (iVar30 = curl_strequal(piVar11[0x49],piVar24[0x49]), iVar30 == 0))
                        goto LAB_00047102;
                        puVar35 = (undefined4 *)piVar11[0x86];
                      }
                      if ((*(char *)(piVar11 + 0x7c) == '\0') || ((int)(puVar35[0x10] << 0x1f) < 0))
                      {
LAB_00047978:
                        iVar30 = Curl_raw_equal(*puVar35,*(undefined4 *)piVar24[0x86]);
                        if ((((iVar30 == 0) &&
                             ((iVar30 = get_protocol_family(*(undefined4 *)(piVar24[0x86] + 0x3c)),
                              iVar30 != *(int *)(piVar11[0x86] + 0x3c) ||
                              (*(char *)(piVar24 + 0x7b) == '\0')))) ||
                            (iVar30 = Curl_raw_equal(piVar11[0x26],piVar24[0x26]), iVar30 == 0)) ||
                           (piVar11[0x2d] != piVar24[0x2d])) goto LAB_00047102;
                        if (*(int *)(piVar11[0x86] + 0x40) << 0x1f < 0) {
                          iVar30 = Curl_ssl_config_matches(piVar25,piVar24 + 0x6a);
                          if (iVar30 == 0) goto LAB_00047102;
                          if (piVar24[0x5f] != 2) {
                            bVar43 = true;
                            goto LAB_00047102;
                          }
                        }
                      }
                      else {
                        if ((*(char *)(piVar24 + 0x7c) != '\0') &&
                           ((((*(char *)((int)piVar11 + 0x1fa) != '\0' &&
                              (*(char *)((int)piVar24 + 0x1fa) != '\0')) &&
                             (iVar30 = Curl_raw_equal(piVar11[0x2a],piVar24[0x2a]), iVar30 != 0)) &&
                            (piVar11[0x2c] == piVar24[0x2c])))) {
                          puVar35 = (undefined4 *)piVar11[0x86];
                          goto LAB_00047978;
                        }
                        if (((*(char *)((int)piVar24 + 0x1ef) == '\0') ||
                            (piVar11[0x4e] != piVar24[0x4e])) ||
                           ((*(char *)((int)piVar11 + 0x1fa) != *(char *)((int)piVar24 + 0x1fa) ||
                            ((iVar30 = Curl_raw_equal(piVar11[0x2a],piVar24[0x2a]), iVar30 == 0 ||
                             (piVar11[0x2c] != piVar24[0x2c])))))) goto LAB_00047102;
                      }
                      if ((local_108 & 1) == 0) {
                        if (piVar24[0x9d] != 0) goto LAB_00047102;
                      }
                      else {
                        iVar30 = curl_strequal(piVar11[0x48],piVar24[0x48]);
                        if ((iVar30 == 0) ||
                           (iVar30 = curl_strequal(piVar11[0x49],piVar24[0x49]), iVar30 == 0))
                        goto LAB_00047102;
                      }
                      if (((uint)local_10c & 1) == 0) {
                        if (piVar24[0xa3] != 0) goto LAB_00047102;
                      }
                      else {
                        iVar30 = curl_strequal(piVar11[0x4c],piVar24[0x4c]);
                        if ((iVar30 == 0) ||
                           (iVar30 = curl_strequal(piVar11[0x4d],piVar24[0x4d]), iVar30 == 0))
                        goto LAB_00047102;
                      }
                      if ((((uint)local_10c | local_108) & 1) == 0) {
                        if ((local_11c == (int *)0x0) || (uVar42 == 0)) goto LAB_0004759a;
                        uVar36 = local_fc;
                        if (local_fc != 0) {
                          uVar36 = 1;
                        }
                        if ((uVar42 < local_fc) || (uVar36 == 0)) {
                          iVar30 = Curl_pipeline_penalized(param_1,piVar24);
                          if (iVar30 == 0) {
                            if (uVar36 == 0) {
                              Curl_infof(param_1,DAT_00047bd0);
                              goto LAB_0004759a;
                            }
                            if (uVar42 < local_e0) goto LAB_00047524;
                          }
                          else {
                            Curl_infof(param_1,DAT_00047bd4);
                          }
                        }
                        else {
                          Curl_infof(param_1,DAT_0004758c,uVar42);
                        }
                      }
                      else {
                        if ((((local_108 & 1) != 0) && (piVar24[0x9d] != 0)) ||
                           ((uVar42 = local_e0, ((uint)local_10c & 1) != 0 && (piVar24[0xa3] != 0)))
                           ) goto LAB_000472be;
LAB_00047524:
                        local_e0 = uVar42;
                        local_f8 = piVar24;
                      }
                    }
                  }
                  goto LAB_00047102;
                }
                if (uVar42 == 0) {
                  cVar26 = *(char *)((int)piVar24 + 0x1ed);
                  if (piVar24[0x55] == -1) {
                    if (cVar26 == '\0') {
                      bVar43 = true;
                    }
                  }
                  else if (cVar26 == '\0') goto LAB_00047160;
                  Curl_infof(param_1,DAT_00047584,piVar24[0x11],cVar26,uVar8);
                }
              }
              goto LAB_00047102;
            }
            piVar24 = local_f8;
            if (local_f8 == (int *)0x0) {
              if ((!bVar43) || (*(char *)(param_1 + 0x43f) == '\0')) goto LAB_000475ea;
              Curl_infof(param_1,DAT_00047be0);
              goto LAB_0004772e;
            }
LAB_0004759a:
            iVar30 = IsPipeliningPossible(param_1,piVar24);
            if ((((iVar30 != 0) &&
                 (*(int *)(piVar24[0x97] + 0xc) + *(int *)(piVar24[0x96] + 0xc) != 0)) &&
                (Curl_infof(param_1,DAT_00047878,piVar24[0x11]),
                *(uint *)(piVar24[0x11c] + 4) < uVar9)) &&
               (*(uint *)(*(int *)(param_1 + 0x580) + 0x18) < uVar10)) {
              Curl_infof(param_1,DAT_0004787c);
              goto LAB_000475ea;
            }
LAB_000472be:
            pcVar31 = *ppcVar39;
            *(undefined *)(piVar24 + 0x10) = 1;
            (*pcVar31)(piVar11[0x28]);
            Curl_free_ssl_config(piVar25);
            ppcVar7 = DAT_00047574;
            cVar26 = *(char *)((int)piVar11 + 0x1f1);
            *piVar24 = *piVar11;
            *(char *)((int)piVar24 + 0x1f1) = cVar26;
            if (cVar26 != '\0') {
              (**ppcVar7)(piVar24[0x48]);
              piVar24[0x48] = 0;
              (**ppcVar7)(piVar24[0x49]);
              piVar24[0x49] = 0;
              iVar30 = piVar11[0x49];
              piVar24[0x48] = piVar11[0x48];
              piVar24[0x49] = iVar30;
              piVar11[0x48] = 0;
              piVar11[0x49] = 0;
            }
            cVar26 = *(char *)((int)piVar11 + 0x1f2);
            *(char *)((int)piVar24 + 0x1f2) = cVar26;
            if (cVar26 != '\0') {
              (**ppcVar39)(piVar24[0x4c]);
              pcVar31 = *ppcVar39;
              piVar24[0x4c] = 0;
              (*pcVar31)(piVar24[0x4d]);
              piVar24[0x4d] = 0;
              iVar30 = piVar11[0x4d];
              piVar24[0x4c] = piVar11[0x4c];
              piVar24[0x4d] = iVar30;
              piVar11[0x4c] = 0;
              piVar11[0x4d] = 0;
            }
            (**ppcVar39)(piVar24[0x24]);
            piVar24[0x24] = 0;
            iVar30 = piVar11[0x25];
            iVar28 = piVar11[0x26];
            iVar33 = piVar11[0x27];
            piVar24[0x24] = piVar11[0x24];
            piVar24[0x25] = iVar30;
            piVar24[0x26] = iVar28;
            piVar24[0x27] = iVar33;
            Curl_persistconninfo(piVar24);
            iVar30 = piVar11[0x48];
            *(undefined *)((int)piVar24 + 0x1ee) = 1;
            (**ppcVar39)(iVar30);
            piVar11[0x48] = 0;
            (**ppcVar39)(piVar11[0x49]);
            piVar11[0x49] = 0;
            (**ppcVar39)(piVar11[0x4c]);
            piVar11[0x4c] = 0;
            (**ppcVar39)(piVar11[0x4d]);
            pcVar31 = *ppcVar39;
            piVar11[0x4d] = 0;
            (*pcVar31)(piVar11[0x117]);
            piVar11[0x117] = 0;
            Curl_llist_destroy(piVar11[0x96],0);
            Curl_llist_destroy(piVar11[0x97],0);
            piVar11[0x96] = 0;
            piVar11[0x97] = 0;
            (**ppcVar39)(piVar11[0x98]);
            piVar11[0x98] = 0;
            (**ppcVar39)(piVar11);
            *param_2 = piVar24;
            uVar8 = DAT_00047578;
            if (*(char *)((int)piVar24 + 0x1ef) != '\0') {
              uVar8 = DAT_0004757c;
            }
            if (piVar24[0x2a] == 0) {
              iVar30 = piVar24[0x27];
            }
            else {
              iVar30 = piVar24[0x2b];
            }
            Curl_infof(param_1,DAT_00047580,piVar24[0x11],uVar8,iVar30);
            piVar11 = piVar24;
          }
          else {
LAB_000475ea:
            iVar30 = Curl_conncache_find_bundle(piVar11,*(undefined4 *)(param_1 + 0x580));
            if (((iVar30 != 0) && (uVar9 != 0)) && (uVar9 <= *(uint *)(iVar30 + 4))) {
              local_11c = (int *)0x0;
              curlx_tvnow(&local_b8);
              local_10c = (undefined4 *)0xffffffff;
              for (ppiVar40 = (int **)**(undefined4 **)(iVar30 + 8); ppiVar40 != (int **)0x0;
                  ppiVar40 = (int **)ppiVar40[2]) {
                piVar25 = *ppiVar40;
                if ((*(char *)(piVar25 + 0x10) == '\0') &&
                   (iVar30 = curlx_tvdiff(local_b8,local_b4,piVar25[0x51],piVar25[0x52]),
                   (int)local_10c < iVar30)) {
                  local_11c = piVar25;
                  local_10c = (undefined4 *)iVar30;
                }
              }
              if (local_11c != (int *)0x0) {
                *local_11c = param_1;
                Curl_disconnect(local_11c,0);
                goto LAB_00047606;
              }
              Curl_infof(param_1,DAT_00047bd8,uVar9);
LAB_0004772e:
              Curl_infof(param_1,DAT_000478b8);
              iVar30 = 0x59;
              conn_free(piVar11);
              *param_2 = (int *)0x0;
              goto LAB_00045eb2;
            }
LAB_00047606:
            if ((uVar10 != 0) && (uVar10 <= *(uint *)(*(int *)(param_1 + 0x580) + 0x18))) {
              piVar25 = (int *)find_oldest_idle_connection(param_1);
              if (piVar25 == (int *)0x0) {
                Curl_infof(param_1,DAT_00047bdc);
                goto LAB_0004772e;
              }
              *piVar25 = param_1;
              Curl_disconnect(piVar25,0);
            }
            Curl_conncache_add_conn(*(undefined4 *)(param_1 + 0x580),piVar11);
            if (((*(uint *)(param_1 + 0x8624) & 0x28) != 0) && (*(char *)(param_1 + 0x862c) != '\0')
               ) {
              Curl_infof(param_1,DAT_00047880);
              *(undefined4 *)(param_1 + 0x8624) = 0;
              *(undefined *)(param_1 + 0x862c) = 0;
            }
            if (((*(uint *)(param_1 + 0x8634) & 0x28) != 0) && (*(char *)(param_1 + 0x863c) != '\0')
               ) {
              Curl_infof(param_1,DAT_00047884);
              *(undefined4 *)(param_1 + 0x8634) = 0;
              *(undefined *)(param_1 + 0x863c) = 0;
            }
          }
          *(undefined *)(piVar11 + 0x10) = 1;
          Curl_init_do(param_1,piVar11);
          iVar30 = setup_range(param_1);
          if (iVar30 != 0) goto LAB_00045eb2;
          piVar11[0x9b] = *(int *)(param_1 + 400);
          piVar11[0x9c] = *(int *)(param_1 + 0x1e8);
          uVar8 = Curl_timeleft(param_1,0,1);
          if (*(char *)((int)piVar11 + 0x1ee) == '\0') {
            pcVar15 = *(char **)(param_1 + 0x3ec);
            if (pcVar15 == (char *)0x0) {
              pcVar15 = (char *)piVar11[0x2a];
              if ((pcVar15 == (char *)0x0) || (*pcVar15 == '\0')) {
                piVar11[0x2c] = piVar11[0x2d];
                iVar28 = Curl_resolv_timeout(piVar11,piVar11[0x26],piVar11[0x2d],&local_bc,uVar8);
                if (iVar28 == 1) goto LAB_00047922;
                if (iVar28 == -2) {
                  iVar30 = 0x1c;
                }
                else if (local_bc == (int *)0x0) {
                  iVar30 = 6;
                  Curl_failf(param_1,DAT_000478d4,piVar11[0x27]);
                }
              }
              else {
                iVar28 = Curl_resolv_timeout(piVar11,pcVar15,piVar11[0x2c],&local_bc,uVar8);
                if (iVar28 == 1) {
LAB_00047922:
                  *param_3 = (char)iVar28;
                }
                else if (iVar28 == -2) {
                  iVar30 = 0x1c;
                }
                else if (local_bc == (int *)0x0) {
                  iVar30 = 5;
                  Curl_failf(param_1,DAT_00047bbc,piVar11[0x2b]);
                }
              }
            }
            else {
              piVar25 = (int *)(*Curl_ccalloc)(1,0xc);
              local_bc = piVar25;
              if (piVar25 == (int *)0x0) {
                iVar30 = 0x1b;
              }
              else {
                iVar28 = Curl_unix2addr(pcVar15);
                *piVar25 = iVar28;
                if (iVar28 == 0) {
                  sVar12 = strlen(pcVar15);
                  if (sVar12 < 0x6c) {
                    iVar30 = 0x1b;
                  }
                  else {
                    iVar30 = 6;
                    Curl_failf(param_1,DAT_000478d8,pcVar15);
                  }
                  (**ppcVar39)(local_bc);
                  local_bc = (int *)0x0;
                }
                else {
                  local_bc[2] = local_bc[2] + 1;
                }
              }
            }
            piVar11[0x12] = (int)local_bc;
          }
          else {
            *param_3 = '\0';
          }
        }
LAB_00046ac8:
        (**ppcVar39)(pcVar27);
        (**ppcVar39)(local_c8);
        (**ppcVar39)(local_cc);
        (**ppcVar39)(0);
        if (iVar30 == 0) {
          piVar11 = *param_2;
          if ((*(int *)(piVar11[0x96] + 0xc) != 0) || (*(int *)(piVar11[0x97] + 0xc) != 0)) {
            *param_4 = 1;
            return 0;
          }
          if (*param_3 != '\0') {
            return 0;
          }
          iVar30 = Curl_setup_conn(piVar11,param_4);
          goto LAB_00045ed2;
        }
        if (iVar30 == 0x59) goto LAB_00045f1c;
        goto LAB_00045ede;
      }
    }
    else {
      iVar30 = (*Curl_ccalloc)(0x4000,1);
      piVar11[0x98] = iVar30;
      if (iVar30 != 0) goto LAB_00045d94;
LAB_00045f48:
      iVar28 = piVar11[0x96];
    }
    ppcVar39 = DAT_00045fa4;
    Curl_llist_destroy(iVar28,0);
    Curl_llist_destroy(piVar11[0x97],0);
    pcVar31 = *ppcVar39;
    piVar11[0x96] = 0;
    piVar11[0x97] = 0;
    (*pcVar31)(piVar11[0x98]);
    (**ppcVar39)(piVar11[0x117]);
    (**ppcVar39)(piVar11);
  }
  pcVar27 = (char *)0x0;
  iVar30 = 0x1b;
LAB_00045eb2:
  (**ppcVar39)(pcVar27);
  (**ppcVar39)(local_c8);
  (**ppcVar39)(local_cc);
  (**ppcVar39)(0);
LAB_00045ed2:
  if (iVar30 == 0x59) {
LAB_00045f1c:
    iVar30 = 0x59;
    *param_2 = (int *)0x0;
  }
  else if (iVar30 != 0) {
LAB_00045ede:
    if (*param_2 != (int *)0x0) {
      Curl_disconnect(*param_2,0);
      *param_2 = (int *)0x0;
    }
  }
  return iVar30;
LAB_0004625c:
  puVar34 = (undefined4 *)puVar35[1];
  puVar35 = puVar35 + 1;
  if (puVar34 == (undefined4 *)0x0) goto LAB_000462a6;
  goto LAB_00046266;
LAB_000462a6:
  iVar30 = 1;
  Curl_failf(param_1,DAT_000462c8,local_10c);
  goto LAB_00045eb2;
}

