
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int Curl_connect(int param_1,int *param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  bool bVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  size_t sVar11;
  undefined1 *puVar12;
  char *pcVar13;
  char *pcVar14;
  size_t sVar15;
  size_t sVar16;
  void *__dest;
  ulong uVar17;
  long lVar18;
  undefined2 *puVar19;
  ushort **ppuVar20;
  __int32_t **pp_Var21;
  int *piVar22;
  int *piVar23;
  char cVar24;
  char *pcVar25;
  int iVar26;
  undefined *puVar27;
  int *piVar28;
  int iVar29;
  code *pcVar30;
  int *piVar31;
  int iVar32;
  undefined1 *puVar33;
  undefined4 *puVar34;
  uint uVar35;
  byte *pbVar36;
  byte *pbVar37;
  undefined1 uVar38;
  uint uVar39;
  bool bVar40;
  byte *local_11c;
  byte *local_10c;
  uint local_108;
  size_t local_104;
  int local_100;
  uint local_fc;
  int *local_f8;
  undefined4 *local_f0;
  uint local_e0;
  int local_d8;
  int iStack_d4;
  undefined1 uStack_cd;
  int local_cc;
  int local_c8;
  int local_c4;
  char *local_c0;
  int *local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  char local_a8 [17];
  undefined1 local_97;
  
  uVar7 = *(undefined4 *)(param_1 + 0x40);
  *param_3 = '\0';
  local_cc = 0;
  local_c8 = 0;
  uVar8 = Curl_multi_max_host_connections(uVar7);
  uVar9 = Curl_multi_max_total_connections(*(undefined4 *)(param_1 + 0x40));
  iVar29 = *(int *)(param_1 + 0x450);
  *param_3 = '\0';
  if (iVar29 == 0) {
    iVar29 = 3;
    pcVar25 = (char *)0x0;
    goto LAB_00045eb2;
  }
  piVar10 = (int *)(*Curl_ccalloc)(1,0x478);
  if (piVar10 != (int *)0x0) {
    uVar38 = 1;
    piVar10[0x55] = -1;
    piVar10[0x86] = (int)Curl_handler_dummy;
    piVar10[0x56] = -1;
    piVar10[0x57] = -1;
    piVar10[0x58] = -1;
    piVar10[0x11] = -1;
    piVar10[0x2c] = -1;
    piVar10[0x2d] = -1;
    *(undefined1 *)((int)piVar10 + 0x1ed) = 1;
    curlx_tvnow(&local_d8);
    uVar39 = *(uint *)(param_1 + 0x2c4);
    pcVar25 = *(char **)(param_1 + 0x380);
    *piVar10 = param_1;
    piVar10[0x53] = local_d8;
    piVar10[0x54] = iStack_d4;
    piVar10[0x4e] = uVar39;
    if ((pcVar25 == (char *)0x0) || (*pcVar25 == '\0')) {
      *(undefined1 *)((int)piVar10 + 0x1ef) = 0;
LAB_00045d16:
      uVar38 = 0;
    }
    else {
      *(undefined1 *)((int)piVar10 + 0x1ef) = 1;
      if (1 < uVar39) goto LAB_00045d16;
    }
    iVar29 = *(int *)(param_1 + 0x3c0);
    iVar26 = *(int *)(param_1 + 0x3b4);
    uVar1 = *(undefined1 *)(param_1 + 0x2fa);
    uVar2 = *(undefined1 *)(param_1 + 0x314);
    if (iVar29 != 0) {
      iVar29 = 1;
    }
    if (iVar26 != 0) {
      iVar26 = 1;
    }
    uVar3 = *(undefined1 *)(param_1 + 0x315);
    *(undefined1 *)(piVar10 + 0x7c) = uVar38;
    uVar38 = *(undefined1 *)(param_1 + 0x288);
    *(char *)((int)piVar10 + 0x1f1) = (char)iVar26;
    uVar4 = *(undefined1 *)(param_1 + 0x289);
    *(char *)((int)piVar10 + 0x1f2) = (char)iVar29;
    *(undefined1 *)((int)piVar10 + 0x1fa) = uVar1;
    *(undefined1 *)((int)piVar10 + 0x459) = uVar4;
    iVar29 = *(int *)(param_1 + 0x2d8);
    *(undefined1 *)((int)piVar10 + 0x1fd) = uVar2;
    piVar10[0xa9] = -1;
    *(undefined1 *)((int)piVar10 + 0x1fe) = uVar3;
    *(undefined1 *)(piVar10 + 0x116) = uVar38;
    piVar10[0x88] = iVar29;
    piVar10[0xaa] = 0;
    piVar10[0xab] = 0;
    piVar10[0xac] = 0;
    iVar29 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40),1);
    if ((iVar29 == 0) || (piVar10[0x98] != 0)) {
LAB_00045d94:
      iVar29 = Curl_llist_alloc(0x432fd);
      piVar10[0x96] = iVar29;
      iVar29 = Curl_llist_alloc(0x432fd);
      iVar26 = piVar10[0x96];
      piVar10[0x97] = iVar29;
      if ((iVar26 != 0) && (iVar29 != 0)) {
        if (*(int *)(param_1 + 0x358) != 0) {
          iVar29 = (*Curl_cstrdup)();
          piVar10[0x117] = iVar29;
          if (iVar29 == 0) goto LAB_00045f48;
        }
        uVar5 = *(undefined2 *)(param_1 + 0x1a0);
        iVar29 = *(int *)(param_1 + 0x1e0);
        iVar26 = *(int *)(param_1 + 0x1e4);
        piVar10[0x119] = *(int *)(param_1 + 0x1a4);
        *(undefined2 *)(piVar10 + 0x118) = uVar5;
        piVar10[0xe] = iVar29;
        piVar10[0xf] = iVar26;
        *param_2 = (int)piVar10;
        sVar11 = strlen(*(char **)(param_1 + 0x450));
        if (sVar11 < 0x100) {
          local_11c = (byte *)0x102;
        }
        else {
          local_11c = (byte *)(sVar11 + 2);
        }
        (*Curl_cfree)(*(undefined4 *)(param_1 + 0x8688));
        *(undefined4 *)(param_1 + 0x8688) = 0;
        *(undefined4 *)(param_1 + 0x868c) = 0;
        iVar29 = (*Curl_cmalloc)(local_11c);
        *(int *)(param_1 + 0x8688) = iVar29;
        if (iVar29 == 0) {
          pcVar25 = (char *)0x0;
LAB_00045e9a:
          iVar29 = 0x1b;
          goto LAB_00045eb2;
        }
        *(int *)(param_1 + 0x868c) = iVar29;
        puVar12 = (undefined1 *)(*Curl_cmalloc)(local_11c);
        piVar10[0x24] = (int)puVar12;
        if (puVar12 == (undefined1 *)0x0) {
          iVar29 = 0x1b;
          (*Curl_cfree)(*(undefined4 *)(param_1 + 0x8688));
          *(undefined4 *)(param_1 + 0x8688) = 0;
          *(undefined4 *)(param_1 + 0x868c) = 0;
          pcVar25 = (char *)0x0;
          goto LAB_00045eb2;
        }
        piVar10[0x26] = (int)puVar12;
        *puVar12 = 0;
        local_cc = (*Curl_cstrdup)(&DAT_0013a6fc);
        local_c8 = (*Curl_cstrdup)(&DAT_0013a6fc);
        pcVar25 = (char *)(*Curl_cstrdup)(&DAT_0013a6fc);
        if ((local_cc == 0 || local_c8 == 0) || (pcVar25 == (char *)0x0)) goto LAB_00045e9a;
        pcVar13 = *(char **)(param_1 + 0x450);
        local_b8 = 0;
        local_b4 = 0;
        local_b0 = 0;
        local_ac = 0;
        local_11c = *(byte **)(param_1 + 0x868c);
        cVar24 = *pcVar13;
        pcVar14 = pcVar13;
        while (cVar24 != '\0') {
          if ((cVar24 == '\r') || (cVar24 == '\n')) {
            Curl_failf(param_1,"Illegal characters found in URL");
            iVar29 = 3;
            goto LAB_00045eb2;
          }
          pcVar14 = (char *)((int)pcVar14 + 1);
          cVar24 = *pcVar14;
        }
        iVar29 = __isoc99_sscanf(pcVar13,"%15[^:]:%[^\n]",&local_b8,local_11c);
        if ((iVar29 == 2) && (iVar29 = Curl_raw_equal(&local_b8,"file"), iVar29 != 0)) {
          if (*local_11c == '/') {
            if (((char *)local_11c)[1] == '/') {
              sVar11 = strlen((char *)local_11c + 2);
              memmove(local_11c,(char *)local_11c + 2,sVar11 + 1);
              if (*local_11c != '/') goto LAB_0004630c;
              bVar40 = false;
              local_10c = (byte *)0x134c14;
            }
            else {
              bVar40 = false;
              local_10c = (byte *)0x134c14;
            }
          }
          else {
LAB_0004630c:
            pcVar14 = strchr((char *)local_11c,0x2f);
            if (pcVar14 == (char *)0x0) {
              local_10c = (byte *)0x134c14;
              bVar40 = false;
            }
            else {
              bVar40 = false;
              if (pcVar14[1] == '/') {
                pcVar14 = pcVar14 + 1;
              }
              sVar11 = strlen(pcVar14);
              memmove(local_11c,pcVar14,sVar11 + 1);
              local_10c = (byte *)0x134c14;
            }
          }
        }
        else {
          *local_11c = '\0';
          pcVar14 = (char *)local_11c;
          iVar29 = __isoc99_sscanf(*(undefined4 *)(param_1 + 0x450),"%15[^\n:]://%[^\n/?]%[^\n]",
                                   &local_b8,piVar10[0x26],local_11c);
          local_10c = (byte *)&local_b8;
          if (iVar29 < 2) {
            iVar29 = __isoc99_sscanf(*(undefined4 *)(param_1 + 0x450),"%[^\n/?]%[^\n]",piVar10[0x26]
                                     ,local_11c,pcVar14);
            if (iVar29 < 1) {
              Curl_failf(param_1,"<url> malformed");
              iVar29 = 3;
              goto LAB_00045eb2;
            }
            local_10c = *(byte **)(param_1 + 0x354);
            if (local_10c == (byte *)0x0) {
              iVar29 = Curl_raw_nequal(&DAT_00136958,piVar10[0x26],4);
              if (iVar29 == 0) {
                iVar29 = Curl_raw_nequal("DICT.",piVar10[0x26],5);
                if (iVar29 == 0) {
                  iVar29 = Curl_raw_nequal("LDAP.",piVar10[0x26],5);
                  if (iVar29 == 0) {
                    iVar29 = Curl_raw_nequal("IMAP.",piVar10[0x26],5);
                    if (iVar29 == 0) {
                      iVar29 = Curl_raw_nequal("SMTP.",piVar10[0x26],5);
                      if (iVar29 == 0) {
                        bVar40 = true;
                        iVar29 = Curl_raw_nequal(&DAT_00136980,piVar10[0x26],5);
                        local_10c = (byte *)0x1368c4;
                        if (iVar29 != 0) {
                          local_10c = (byte *)0x1368cc;
                        }
                      }
                      else {
                        bVar40 = true;
                        local_10c = &DAT_001368d4;
                      }
                    }
                    else {
                      bVar40 = true;
                      local_10c = &DAT_001368dc;
                    }
                  }
                  else {
                    bVar40 = true;
                    local_10c = &DAT_001368e4;
                  }
                }
                else {
                  bVar40 = true;
                  local_10c = &DAT_001368b8;
                }
              }
              else {
                bVar40 = true;
                local_10c = &DAT_001368c0;
              }
            }
            else {
              bVar40 = true;
            }
          }
          else {
            bVar40 = false;
          }
        }
        pcVar13 = (char *)piVar10[0x26];
        pcVar14 = strchr(pcVar13,0x40);
        if (pcVar14 == (char *)0x0) {
          pcVar14 = strchr(pcVar13,0x3f);
        }
        else {
          pcVar14 = strchr(pcVar14 + 1,0x3f);
        }
        if (pcVar14 == (char *)0x0) {
          cVar24 = *local_11c;
          if (cVar24 == '\0') {
            bVar6 = true;
            ((char *)local_11c)[0] = '/';
            ((char *)local_11c)[1] = '\0';
            cVar24 = *local_11c;
          }
          else {
            bVar6 = false;
          }
        }
        else {
          bVar6 = true;
          sVar11 = strlen(pcVar14);
          sVar15 = strlen((char *)local_11c);
          memmove((char *)local_11c + sVar11 + 1,local_11c,sVar15 + 1);
          memcpy((char *)local_11c + 1,pcVar14,sVar11);
          *local_11c = '/';
          *pcVar14 = '\0';
          cVar24 = *local_11c;
        }
        if (cVar24 == '?') {
          sVar11 = strlen((char *)local_11c);
          memmove((char *)local_11c + 1,local_11c,sVar11 + 1);
          *local_11c = '/';
LAB_000460c2:
          sVar11 = strlen((char *)local_11c);
          sVar15 = strlen(*(char **)(param_1 + 0x450));
          local_104 = strlen((char *)piVar10[0x26]);
          if (!bVar40) {
            sVar16 = strlen((char *)local_10c);
            local_104 = local_104 + 3 + sVar16;
          }
          __dest = (void *)(*Curl_cmalloc)(sVar15 + 2);
          if (__dest == (void *)0x0) goto LAB_00045e9a;
          memcpy(__dest,*(void **)(param_1 + 0x450),local_104);
          memcpy((void *)((int)__dest + local_104),local_11c,sVar11 + 1);
          if (*(char *)(param_1 + 0x454) != '\0') {
            (*Curl_cfree)(*(undefined4 *)(param_1 + 0x450));
            *(undefined4 *)(param_1 + 0x450) = 0;
            *(undefined1 *)(param_1 + 0x454) = 0;
          }
          Curl_infof(param_1,"Rebuilt URL to: %s\n",__dest);
          *(void **)(param_1 + 0x450) = __dest;
          *(undefined1 *)(param_1 + 0x454) = 1;
        }
        else {
          if (*(char *)(param_1 + 0x43e) == '\0') {
            pcVar14 = (char *)Curl_dedotdotify(local_11c);
            if (pcVar14 == (char *)0x0) goto LAB_00045e9a;
            iVar29 = strcmp(pcVar14,(char *)local_11c);
            if (iVar29 != 0) {
              (*Curl_cfree)(*(undefined4 *)(param_1 + 0x8688));
              *(char **)(param_1 + 0x8688) = pcVar14;
              *(char **)(param_1 + 0x868c) = pcVar14;
              local_11c = (byte *)pcVar14;
              goto LAB_000460c2;
            }
            (*Curl_cfree)(pcVar14);
          }
          if (bVar6) goto LAB_000460c2;
        }
        local_c0 = (char *)0x0;
        local_bc = (int *)0x0;
        pcVar13 = (char *)piVar10[0x26];
        local_c4 = 0;
        pcVar14 = strchr(pcVar13,0x40);
        if (pcVar14 != (char *)0x0) {
          iVar29 = *(int *)(param_1 + 0x30c);
          piVar10[0x26] = (int)(pcVar14 + 1);
          if (iVar29 != 2) {
            iVar29 = parse_login_details(pcVar13,pcVar14 + 1 + (-1 - (int)pcVar13),&local_c4,
                                         &local_c0,&local_bc);
            if (iVar29 == 0) {
              if (local_c4 == 0) {
LAB_000461b2:
                if (local_c0 != (char *)0x0) {
                  iVar29 = curl_easy_unescape(param_1,local_c0,0,0);
                  if (iVar29 == 0) goto LAB_00046340;
                  (*Curl_cfree)(local_c8);
                  local_c8 = iVar29;
                }
                if (local_bc != (int *)0x0) {
                  pcVar14 = (char *)curl_easy_unescape(param_1,local_bc,0,0);
                  if (pcVar14 == (char *)0x0) goto LAB_00046340;
                  (*Curl_cfree)(pcVar25);
                  pcVar25 = pcVar14;
                }
                goto LAB_000461f4;
              }
              *(undefined1 *)(piVar10 + 0x80) = 1;
              *(undefined1 *)((int)piVar10 + 0x1f1) = 1;
              iVar29 = curl_easy_unescape(param_1,local_c4,0,0);
              if (iVar29 != 0) {
                (*Curl_cfree)(local_cc);
                local_cc = iVar29;
                goto LAB_000461b2;
              }
LAB_00046340:
              iVar29 = 0x1b;
            }
            (*Curl_cfree)(local_c4);
            (*Curl_cfree)(local_c0);
            (*Curl_cfree)(local_bc);
            goto LAB_00045eb2;
          }
        }
LAB_000461f4:
        (*Curl_cfree)(local_c4);
        (*Curl_cfree)(local_c0);
        (*Curl_cfree)(local_bc);
        if ((*(char *)piVar10[0x26] == '[') &&
           (pcVar14 = strchr((char *)piVar10[0x26],0x25), pcVar14 != (char *)0x0)) {
          iVar29 = strncmp("%25",pcVar14,3);
          if (iVar29 == 0) {
            local_100 = 3;
          }
          else {
            Curl_infof(param_1,"Please URL encode %% as %%25, see RFC 6874.\n");
            local_100 = 1;
          }
          uVar17 = strtoul(pcVar14 + local_100,(char **)&local_bc,10);
          piVar23 = local_bc;
          if ((char)*local_bc == ']') {
            sVar11 = strlen((char *)local_bc);
            memmove(pcVar14,piVar23,sVar11 + 1);
            piVar10[0x22] = uVar17;
          }
          else {
            strncpy(local_a8,pcVar14 + local_100,0x12);
            local_97 = 0;
            pcVar13 = strchr(local_a8,0x5d);
            if (pcVar13 != (char *)0x0) {
              *pcVar13 = '\0';
              uVar39 = if_nametoindex(local_a8);
              if (uVar39 != 0) {
                sVar11 = strlen(local_a8);
                sVar15 = strlen(pcVar14 + sVar11 + local_100);
                memmove(pcVar14,pcVar14 + sVar11 + local_100,sVar15 + 1);
                piVar10[0x22] = uVar39;
                goto LAB_00046218;
              }
              piVar23 = __errno_location();
              pcVar14 = strerror(*piVar23);
              Curl_infof(param_1,"Invalid network interface: %s; %s\n",local_a8,pcVar14);
            }
            Curl_infof(param_1,"Invalid IPv6 address format\n");
          }
        }
LAB_00046218:
        if (*(int *)(param_1 + 0x3f8) != 0) {
          piVar10[0x22] = *(int *)(param_1 + 0x3f8);
        }
        pcVar14 = strchr((char *)local_11c,0x23);
        if (pcVar14 != (char *)0x0) {
          *pcVar14 = '\0';
          pcVar14 = strchr(*(char **)(param_1 + 0x450),0x23);
          if (pcVar14 != (char *)0x0) {
            *pcVar14 = '\0';
          }
        }
        puVar12 = protocols;
        puVar33 = Curl_handler_http;
LAB_00046266:
        iVar29 = Curl_raw_equal(*(undefined4 *)puVar33,local_10c);
        if (iVar29 == 0) goto LAB_0004625c;
        if (((*(uint *)((int)puVar33 + 0x3c) & *(uint *)(param_1 + 0x3fc)) == 0) ||
           ((*(char *)(param_1 + 0x85a8) != '\0' &&
            ((*(uint *)((int)puVar33 + 0x3c) & *(uint *)(param_1 + 0x400)) == 0))))
        goto LAB_000462a6;
        piVar10[0x87] = (int)puVar33;
        piVar10[0x86] = (int)puVar33;
        if (!bVar40) goto LAB_000464e6;
        pbVar36 = (byte *)curl_maprintf("%s://%s",*(undefined4 *)puVar33,
                                        *(undefined4 *)(param_1 + 0x450));
        if (pbVar36 == (byte *)0x0) goto LAB_00045e9a;
        uVar39 = (uint)*pbVar36;
        if (uVar39 != 0x3a) {
          pbVar37 = pbVar36 + -1;
          do {
            pp_Var21 = __ctype_tolower_loc();
            pbVar37[1] = (byte)(*pp_Var21)[uVar39];
            uVar39 = (uint)pbVar37[2];
            pbVar37 = pbVar37 + 1;
          } while (uVar39 != 0x3a);
        }
        if (*(char *)(param_1 + 0x454) != '\0') {
          (*Curl_cfree)(*(undefined4 *)(param_1 + 0x450));
        }
        *(undefined1 *)(param_1 + 0x454) = 1;
        *(byte **)(param_1 + 0x450) = pbVar36;
LAB_000464e6:
        if ((*(int *)(piVar10[0x87] + 0x40) << 0x19 < 0) &&
           (pcVar14 = strchr(*(char **)(*piVar10 + 0x868c),0x3f), pcVar14 != (char *)0x0)) {
          *pcVar14 = '\0';
        }
        if (*(int *)(param_1 + 1000) != 0) {
          iVar29 = (*Curl_cstrdup)();
          piVar10[0x4b] = iVar29;
          if (iVar29 != 0) goto LAB_00046522;
          goto LAB_00045e9a;
        }
LAB_00046522:
        if ((*(char *)((int)piVar10 + 0x1f2) != '\0') &&
           (iVar29 = parse_proxy_auth(param_1,piVar10), iVar29 != 0)) goto LAB_00045eb2;
        if (*(int *)(param_1 + 0x380) == 0) {
          local_11c = (byte *)0x0;
        }
        else {
          local_11c = (byte *)(*Curl_cstrdup)();
          if (local_11c == (byte *)0x0) {
            Curl_failf(param_1,"memory shortage");
            iVar29 = 0x1b;
            goto LAB_00045eb2;
          }
        }
        if ((*(int *)(param_1 + 0x3c8) == 0) || (iVar29 = check_noproxy(piVar10[0x26]), iVar29 == 0)
           ) {
          if (local_11c == (byte *)0x0) {
            local_10c = (byte *)curl_getenv("no_proxy");
            if (local_10c == (byte *)0x0) {
              local_10c = (byte *)curl_getenv("NO_PROXY");
            }
            iVar29 = check_noproxy(piVar10[0x26],local_10c);
            if (iVar29 == 0) {
              pbVar36 = *(byte **)piVar10[0x86];
              uVar39 = (uint)*pbVar36;
              pcVar14 = local_a8;
              if (uVar39 != 0) {
                pcVar14 = local_a8;
                do {
                  pcVar14 = pcVar14 + 1;
                  pp_Var21 = __ctype_tolower_loc();
                  pcVar14[-1] = (char)(*pp_Var21)[uVar39];
                  pbVar36 = pbVar36 + 1;
                  uVar39 = (uint)*pbVar36;
                } while (uVar39 != 0);
              }
              builtin_strncpy(pcVar14,"_proxy",7);
              local_11c = (byte *)curl_getenv(local_a8);
              if (local_11c == (byte *)0x0) {
                iVar29 = Curl_raw_equal("http_proxy",local_a8);
                if (iVar29 == 0) {
                  Curl_strntoupper(local_a8,local_a8,0x80);
                  local_11c = (byte *)curl_getenv(local_a8);
                  if (local_11c != (byte *)0x0) goto LAB_00046d36;
                }
                local_11c = (byte *)curl_getenv("all_proxy");
                if (local_11c == (byte *)0x0) {
                  local_11c = (byte *)curl_getenv("ALL_PROXY");
                  (*Curl_cfree)(local_10c);
                  if (local_11c != (byte *)0x0) goto LAB_00046564;
                  goto LAB_00046574;
                }
              }
LAB_00046d36:
              (*Curl_cfree)(local_10c);
              goto LAB_00046564;
            }
            (*Curl_cfree)(local_10c);
            goto LAB_00046574;
          }
LAB_00046564:
          if (((*(int *)(param_1 + 0x3ec) != 0) || (*local_11c == 0)) ||
             (*(int *)(piVar10[0x86] + 0x40) << 0x1b < 0)) goto LAB_0004656c;
          pcVar14 = strstr((char *)local_11c,"://");
          pbVar36 = local_11c;
          if (pcVar14 != (char *)0x0) {
            pbVar36 = (byte *)(pcVar14 + 3);
            iVar29 = Curl_raw_nequal("socks5h",local_11c,7);
            if (iVar29 == 0) {
              iVar29 = Curl_raw_nequal("socks5",local_11c,6);
              if (iVar29 == 0) {
                iVar29 = Curl_raw_nequal("socks4a",local_11c,7);
                if (iVar29 == 0) {
                  iVar29 = Curl_raw_nequal("socks4",local_11c,6);
                  if ((iVar29 != 0) || (iVar29 = Curl_raw_nequal("socks",local_11c,5), iVar29 != 0))
                  {
                    piVar10[0x4e] = 4;
                  }
                }
                else {
                  piVar10[0x4e] = 6;
                }
              }
              else {
                piVar10[0x4e] = 5;
              }
            }
            else {
              piVar10[0x4e] = 7;
            }
          }
          pcVar14 = strchr((char *)pbVar36,0x40);
          if (pcVar14 != (char *)0x0) {
            local_c0 = (char *)0x0;
            local_bc = (int *)0x0;
            iVar29 = parse_login_details(pbVar36,(int)pcVar14 - (int)pbVar36,&local_c0,&local_bc,0);
            if (iVar29 == 0) {
              (*Curl_cfree)(piVar10[0x4c]);
              pcVar13 = local_c0;
              piVar10[0x4c] = 0;
              if ((local_c0 == (char *)0x0) || (sVar11 = strlen(local_c0), 0xff < sVar11)) {
                iVar29 = (*Curl_cstrdup)(&DAT_0013a6fc);
                piVar10[0x4c] = iVar29;
              }
              else {
                iVar29 = curl_easy_unescape(param_1,pcVar13,0,0);
                piVar10[0x4c] = iVar29;
              }
              if (iVar29 != 0) {
                (*Curl_cfree)(piVar10[0x4d]);
                piVar23 = local_bc;
                piVar10[0x4d] = 0;
                if ((local_bc == (int *)0x0) || (sVar11 = strlen((char *)local_bc), 0xff < sVar11))
                {
                  iVar29 = (*Curl_cstrdup)(&DAT_0013a6fc);
                  piVar10[0x4d] = iVar29;
                }
                else {
                  iVar29 = curl_easy_unescape(param_1,piVar23,0,0);
                  piVar10[0x4d] = iVar29;
                }
                pcVar30 = Curl_cfree;
                if (piVar10[0x4d] != 0) {
                  *(undefined1 *)((int)piVar10 + 0x1f2) = 1;
                  pbVar36 = (byte *)(pcVar14 + 1);
                  (*pcVar30)(local_c0);
                  (*Curl_cfree)(local_bc);
                  goto LAB_0004676c;
                }
              }
              iVar29 = 0x1b;
            }
            (*Curl_cfree)(local_c0);
            (*Curl_cfree)(local_bc);
LAB_000466c6:
            (*Curl_cfree)(local_11c);
            goto LAB_00045eb2;
          }
LAB_0004676c:
          local_10c = pbVar36;
          if (*pbVar36 == 0x5b) {
            uVar39 = (uint)pbVar36[1];
            local_10c = pbVar36 + 1;
            pbVar37 = local_10c;
            if (uVar39 != 0) {
              ppuVar20 = __ctype_b_loc();
              pbVar36 = local_10c;
              do {
                if (((-1 < (int)((uint)(*ppuVar20)[uVar39] << 0x13)) && (uVar39 != 0x3a)) &&
                   (uVar39 != 0x2e)) {
                  pbVar37 = pbVar36;
                  if (uVar39 == 0x25) {
                    iVar29 = strncmp("%25",(char *)pbVar36,3);
                    if (iVar29 != 0) {
                      Curl_infof(param_1,"Please URL encode %% as %%25, see RFC 6874.\n");
                    }
                    pbVar37 = pbVar36 + 1;
                    uVar39 = (uint)pbVar36[1];
                    if (uVar39 != 0) {
                      do {
                        if (((((*ppuVar20)[uVar39] & 0x1400) == 0) && (uVar39 != 0x2d)) &&
                           ((uVar39 != 0x2e && ((uVar39 != 0x5f && (uVar39 != 0x7e))))))
                        goto LAB_00046ea2;
                        pbVar37 = pbVar37 + 1;
                        uVar39 = (uint)*pbVar37;
                      } while (uVar39 != 0);
                    }
                  }
                  else {
LAB_00046ea2:
                    if (*pbVar37 == 0x5d) {
                      pbVar36 = pbVar37 + 1;
                      *pbVar37 = 0;
                      goto LAB_0004677c;
                    }
                  }
                  break;
                }
                pbVar36 = pbVar36 + 1;
                uVar39 = (uint)*pbVar36;
                pbVar37 = pbVar36;
              } while (uVar39 != 0);
            }
            Curl_infof(param_1,"Invalid IPv6 address format\n");
            pbVar36 = pbVar37;
          }
LAB_0004677c:
          pcVar14 = strchr((char *)pbVar36,0x3a);
          if (pcVar14 == (char *)0x0) {
            if (*local_10c == 0x2f) {
              iVar29 = 5;
              goto LAB_000466c6;
            }
            pcVar14 = strchr((char *)local_10c,0x2f);
            if (pcVar14 != (char *)0x0) {
              *pcVar14 = '\0';
            }
            if (*(int *)(param_1 + 0x15c) != 0) {
              piVar10[0x2c] = *(int *)(param_1 + 0x15c);
            }
          }
          else {
            local_bc = (int *)0x0;
            *pcVar14 = '\0';
            lVar18 = strtol(pcVar14 + 1,(char **)&local_bc,10);
            if (((((local_bc == (int *)0x0) || (cVar24 = (char)*local_bc, cVar24 == '\0')) ||
                 (cVar24 == '/')) || (cVar24 == ' ')) && (lVar18 < 0x10000)) {
              piVar10[0x2c] = lVar18;
            }
            else {
              Curl_infof(param_1,"No valid port number in proxy string (%s)\n",pcVar14 + 1);
            }
          }
          iVar29 = (*Curl_cstrdup)(local_10c);
          piVar10[0x28] = iVar29;
          piVar10[0x2a] = iVar29;
          if (iVar29 == 0) {
            iVar29 = 0x1b;
            goto LAB_000466c6;
          }
          (*Curl_cfree)(local_11c);
          uVar35 = piVar10[0x4e];
          uVar39 = uVar35;
          if (1 < uVar35) {
            uVar39 = 0;
          }
          if (uVar35 < 2) {
            if (((*(uint *)(piVar10[0x86] + 0x3c) & 3) == 0) &&
               (*(char *)((int)piVar10 + 0x1fa) == '\0')) {
              piVar10[0x86] = (int)Curl_handler_http;
            }
            *(undefined1 *)(piVar10 + 0x7c) = 1;
          }
          else {
            *(char *)(piVar10 + 0x7c) = (char)uVar39;
            *(char *)((int)piVar10 + 0x1fa) = (char)uVar39;
          }
          *(undefined1 *)((int)piVar10 + 0x1ef) = 1;
        }
        else {
LAB_0004656c:
          (*Curl_cfree)(local_11c);
LAB_00046574:
          *(undefined1 *)((int)piVar10 + 0x1ef) = 0;
          *(undefined1 *)(piVar10 + 0x7c) = 0;
          *(undefined1 *)((int)piVar10 + 0x1f2) = 0;
          *(undefined1 *)((int)piVar10 + 0x1fa) = 0;
        }
        if ((*(int *)(piVar10[0x87] + 0x40) << 0x1f < 0) && ((char)piVar10[0x7c] != '\0')) {
          *(undefined1 *)((int)piVar10 + 0x1fa) = 1;
        }
        iVar29 = __isoc99_sscanf(piVar10[0x26],"[%*45[0123456789abcdefABCDEF:.]%c",&local_c0);
        if ((iVar29 == 1) && (((uint)local_c0 & 0xff) == 0x5d)) {
          iVar29 = piVar10[0x26];
          *(undefined1 *)((int)piVar10 + 499) = 1;
          piVar10[0x26] = iVar29 + 1;
          pcVar14 = strchr((char *)(iVar29 + 1),0x5d);
          if (pcVar14 != (char *)0x0) {
            *pcVar14 = '\0';
            if (pcVar14[1] == ':') {
              pcVar14 = pcVar14 + 1;
            }
            else {
              pcVar14 = (char *)0x0;
            }
          }
        }
        else {
          iVar29 = inet_pton(10,(char *)piVar10[0x26],local_a8);
          if (0 < iVar29) {
            Curl_failf(param_1,"IPv6 numerical address used in URL without brackets");
            iVar29 = 3;
            goto LAB_00045eb2;
          }
          pcVar14 = strrchr((char *)piVar10[0x26],0x3a);
        }
        if ((*(uint *)(param_1 + 0x170) == 0) || (*(char *)(param_1 + 0x85d4) == '\0')) {
          if (pcVar14 != (char *)0x0) {
            uVar39 = strtol(pcVar14 + 1,(char **)&local_bc,10);
            if (0xffff < uVar39) {
              Curl_failf(param_1,"Port number out of range");
              iVar29 = 3;
              goto LAB_00045eb2;
            }
            *pcVar14 = '\0';
            if ((int *)(pcVar14 + 1) != local_bc) {
              iVar29 = curlx_ultous();
              piVar10[0x2d] = iVar29;
            }
          }
        }
        else {
          piVar10[0x2d] = *(uint *)(param_1 + 0x170) & 0xffff;
          if (pcVar14 != (char *)0x0) {
            *pcVar14 = '\0';
          }
          if ((char)piVar10[0x7c] != '\0') {
            local_a8[0] = '\0';
            local_a8[1] = '\0';
            local_a8[2] = '\0';
            local_a8[3] = '\0';
            local_a8[4] = '\0';
            local_a8[5] = '\0';
            local_a8[6] = '\0';
            local_a8[7] = '\0';
            local_a8[8] = '\0';
            local_a8[9] = '\0';
            local_a8[10] = '\0';
            local_a8[0xb] = '\0';
            if ((char)piVar10[0x81] != '\0') {
              if (*(char *)(param_1 + 0x2fb) == '\0') {
                if (*(char *)(param_1 + 0x2fd) == '\0') {
                  uVar7 = 0x49;
                }
                else {
                  uVar7 = 0x44;
                }
              }
              else {
                uVar7 = 0x41;
              }
              curl_msnprintf(local_a8,0xc,";type=%c",uVar7);
            }
            if (*(char *)((int)piVar10 + 499) == '\0') {
              puVar27 = &DAT_0013a6fc;
              iVar29 = piVar10[0x26];
              local_10c = &DAT_0013a6fc;
            }
            else {
              iVar29 = piVar10[0x26];
              puVar27 = &DAT_00135eb4;
              local_10c = &DAT_00135988;
            }
            puVar19 = &DAT_00135588;
            if (*(char *)(param_1 + 0x8690) == '\0') {
              puVar19 = (undefined2 *)&DAT_0013a6fc;
            }
            iVar29 = curl_maprintf("%s://%s%s%s:%hu%s%s%s",*(undefined4 *)piVar10[0x87],puVar27,
                                   iVar29,local_10c,piVar10[0x2d],puVar19,
                                   *(undefined4 *)(param_1 + 0x868c),local_a8);
            if (iVar29 == 0) goto LAB_00045e9a;
            if (*(char *)(param_1 + 0x454) != '\0') {
              (*Curl_cfree)(*(undefined4 *)(param_1 + 0x450));
            }
            *(int *)(param_1 + 0x450) = iVar29;
            *(undefined1 *)(param_1 + 0x454) = 1;
          }
        }
        if (*(int *)(param_1 + 0x3b4) != 0) {
          (*Curl_cfree)(local_cc);
          local_cc = (*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x3b4));
          if (local_cc == 0) goto LAB_00045e9a;
        }
        if (*(int *)(param_1 + 0x3b8) != 0) {
          (*Curl_cfree)(local_c8);
          local_c8 = (*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x3b8));
          if (local_c8 == 0) goto LAB_00045e9a;
        }
        if (*(int *)(param_1 + 0x3bc) != 0) {
          (*Curl_cfree)(pcVar25);
          pcVar25 = (char *)(*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x3bc));
          if (pcVar25 == (char *)0x0) goto LAB_00045e9a;
        }
        iVar29 = *(int *)(param_1 + 0x30c);
        *(undefined1 *)((int)piVar10 + 0x1ff) = 0;
        if (iVar29 != 0) {
          iVar29 = Curl_parsenetrc(piVar10[0x26],&local_cc,&local_c8,
                                   *(undefined4 *)(param_1 + 0x37c));
          if (iVar29 < 1) {
            if (iVar29 != 0) goto LAB_00045e9a;
            *(undefined1 *)((int)piVar10 + 0x1ff) = 1;
            *(undefined1 *)((int)piVar10 + 0x1f1) = 1;
          }
          else {
            Curl_infof(param_1,"Couldn\'t find host %s in the .netrc file; using defaults\n",
                       piVar10[0x26]);
          }
        }
        iVar29 = local_c8;
        if ((*(int *)(piVar10[0x86] + 0x40) << 0x1a < 0) &&
           (*(char *)((int)piVar10 + 0x1f1) == '\0')) {
          iVar26 = (*Curl_cstrdup)("anonymous");
          piVar10[0x48] = iVar26;
          if (iVar26 == 0) {
LAB_00046d68:
            piVar10[0x49] = iVar26;
          }
          else {
            iVar29 = (*Curl_cstrdup)("ftp@example.com");
            piVar10[0x49] = iVar29;
          }
        }
        else {
          iVar26 = (*Curl_cstrdup)(local_cc);
          piVar10[0x48] = iVar26;
          if (iVar26 == 0) goto LAB_00046d68;
          iVar29 = (*Curl_cstrdup)(iVar29);
          piVar10[0x49] = iVar29;
        }
        if ((piVar10[0x48] == 0) || (piVar10[0x49] == 0)) goto LAB_00045e9a;
        if (*pcVar25 != '\0') {
          iVar29 = (*Curl_cstrdup)(pcVar25);
          piVar10[0x4a] = iVar29;
          if (iVar29 == 0) goto LAB_00045e9a;
        }
        fix_hostname_isra_2(param_1,piVar10 + 0x24);
        if (((char *)piVar10[0x2a] != (char *)0x0) && (*(char *)piVar10[0x2a] != '\0')) {
          fix_hostname_isra_2(param_1,piVar10 + 0x28);
        }
        iVar26 = *piVar10;
        (*Curl_cfree)(*(undefined4 *)(iVar26 + 0x14c));
        pcVar30 = Curl_cfree;
        *(undefined4 *)(iVar26 + 0x14c) = 0;
        (*pcVar30)(*(undefined4 *)(iVar26 + 0x13c));
        *(undefined4 *)(iVar26 + 0x13c) = 0;
        memset((void *)(iVar26 + 0x50),0,0x100);
        iVar29 = piVar10[0x86];
        *(undefined4 *)(iVar26 + 0x60) = 0xffffffff;
        *(undefined4 *)(iVar26 + 100) = 0xffffffff;
        pcVar30 = *(code **)(iVar29 + 4);
        piVar10[0x23] = 1;
        if (pcVar30 != (code *)0x0) {
          iVar29 = (*pcVar30)(piVar10);
          if (iVar29 != 0) goto LAB_00045eb2;
          iVar29 = piVar10[0x86];
        }
        iVar26 = piVar10[0x2c];
        bVar40 = iVar26 < 0;
        if (bVar40) {
          iVar26 = *(int *)(iVar29 + 0x38);
        }
        if (bVar40) {
          piVar10[0x2c] = iVar26;
        }
        if (piVar10[0x2d] < 0) {
          piVar10[0x2d] = (uint)*(ushort *)(piVar10[0x87] + 0x38);
        }
        iVar26 = *(int *)(iVar29 + 0x40);
        piVar10[0x5a] = 0x43171;
        piVar10[0x5b] = 0x43171;
        piVar10[0x5c] = 0x431e1;
        piVar10[0x5d] = 0x431e1;
        if (iVar26 << 0x1b < 0) {
          iVar29 = (**(code **)(iVar29 + 0x14))(piVar10,&uStack_cd);
          if (iVar29 == 0) {
            *(undefined1 *)((int)piVar10 + 0x1f6) = 1;
            *piVar10 = param_1;
            Curl_conncache_add_conn(*(undefined4 *)(param_1 + 0x580),piVar10);
            iVar29 = setup_range(param_1);
            if (iVar29 != 0) {
              (**(code **)(piVar10[0x86] + 0xc))(piVar10,iVar29,0);
              goto LAB_00046ac8;
            }
            Curl_setup_transfer(piVar10,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
          }
          Curl_init_do(param_1,piVar10);
        }
        else {
          piVar23 = piVar10 + 0x6a;
          *(undefined4 *)(param_1 + 0x28c) = *(undefined4 *)(param_1 + 0x390);
          *(undefined4 *)(param_1 + 0x290) = *(undefined4 *)(param_1 + 0x394);
          *(undefined4 *)(param_1 + 0x294) = *(undefined4 *)(param_1 + 0x3ac);
          *(undefined4 *)(param_1 + 0x298) = *(undefined4 *)(param_1 + 0x3b0);
          *(undefined4 *)(param_1 + 0x29c) = *(undefined4 *)(param_1 + 0x3a4);
          *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)(param_1 + 0x3a0);
          *(undefined4 *)(param_1 + 0x2a4) = *(undefined4 *)(param_1 + 0x39c);
          *(undefined4 *)(param_1 + 0x2b8) = *(undefined4 *)(param_1 + 0x3e0);
          *(undefined4 *)(param_1 + 700) = *(undefined4 *)(param_1 + 0x3e4);
          iVar29 = Curl_clone_ssl_config(param_1 + 0x280,piVar23);
          if (iVar29 == 0) goto LAB_00045e9a;
          curlx_tvnow(&local_b8);
          iVar29 = curlx_tvdiff(local_b8,local_b4,*(undefined4 *)(*(int *)(param_1 + 0x580) + 0x20),
                                *(undefined4 *)(*(int *)(param_1 + 0x580) + 0x24));
          if (999 < iVar29) {
            Curl_conncache_foreach(*(undefined4 *)(param_1 + 0x580),param_1,0x456b1);
            iVar29 = *(int *)(param_1 + 0x580);
            *(undefined4 *)(iVar29 + 0x20) = local_b8;
            *(undefined4 *)(iVar29 + 0x24) = local_b4;
          }
          if ((*(char *)(param_1 + 0x313) == '\0') || (*(char *)(param_1 + 0x85a8) != '\0')) {
            local_11c = (byte *)IsPipeliningPossible(param_1,piVar10);
            if ((*(uint *)(param_1 + 0x8620) & 0x28) == 0) {
              local_108 = 0;
            }
            else {
              local_108 = *(uint *)(piVar10[0x86] + 0x3c) & 3;
              if (local_108 != 0) {
                local_108 = 1;
              }
            }
            local_10c = (byte *)(uint)*(byte *)((int)piVar10 + 0x1f2);
            if (((local_10c != (byte *)0x0) &&
                (local_10c = (byte *)(*(uint *)(param_1 + 0x8630) & 0x28), local_10c != (byte *)0x0)
                ) && (local_10c = (byte *)(*(uint *)(piVar10[0x86] + 0x3c) & 3),
                     local_10c != (byte *)0x0)) {
              local_10c = (byte *)0x1;
            }
            if (local_11c != (byte *)0x0) {
              uVar39 = Curl_pipeline_site_blacklisted(param_1,piVar10);
              local_11c = (byte *)((uVar39 ^ 1) & 0xff);
            }
            piVar22 = (int *)Curl_conncache_find_bundle(piVar10,*(undefined4 *)(param_1 + 0x580));
            if (piVar22 == (int *)0x0) goto LAB_000475ea;
            if (*piVar22 == 2) {
              iVar29 = piVar10[0x26];
              local_fc = 0;
              pcVar14 = "can multiplex";
            }
            else {
              if (*(int *)(param_1 + 0x40) == 0) {
                local_fc = 0;
              }
              else {
                local_fc = *(uint *)(*(int *)(param_1 + 0x40) + 0xa0);
              }
              pcVar14 = "can pipeline";
              iVar29 = piVar10[0x26];
              if (*piVar22 != 1) {
                pcVar14 = "serially";
              }
            }
            Curl_infof(param_1,"Found bundle for host %s: %p [%s]\n",iVar29,piVar22,pcVar14);
            if (local_11c != (byte *)0x0) {
              iVar29 = *piVar22;
              if (0 < iVar29) {
LAB_000470ca:
                if (iVar29 == 1) {
                  iVar29 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40));
                  if (iVar29 == 0) {
                    Curl_infof(param_1,"Could pipeline, but not asked to!\n");
                    local_11c = (byte *)0x0;
                    goto LAB_000470d6;
                  }
                  iVar29 = *piVar22;
                }
                if ((iVar29 == 2) &&
                   (iVar29 = Curl_pipeline_wanted(*(undefined4 *)(param_1 + 0x40)), iVar29 == 0)) {
                  Curl_infof(param_1,"Could multiplex, but not asked to!\n");
                  local_11c = (byte *)0x0;
                }
                goto LAB_000470d6;
              }
              if ((iVar29 != 0) || (*(char *)(param_1 + 0x43f) == '\0')) {
                Curl_infof(param_1,"Server doesn\'t support multi-use (yet)\n");
                iVar29 = *piVar22;
                local_11c = (byte *)0x0;
                goto LAB_000470ca;
              }
              Curl_infof(param_1,"Server doesn\'t support multi-use yet, wait\n");
              goto LAB_0004772e;
            }
LAB_000470d6:
            bVar40 = false;
            local_f0 = *(undefined4 **)piVar22[2];
            local_f8 = (int *)0x0;
            local_e0 = local_fc;
LAB_00047102:
            if (local_f0 != (undefined4 *)0x0) {
              piVar22 = (int *)*local_f0;
              local_f0 = (undefined4 *)local_f0[2];
              iVar29 = disconnect_if_dead(piVar22,param_1);
              if (iVar29 == 0) {
                uVar39 = ((int *)piVar22[0x97])[3] + ((undefined4 *)piVar22[0x96])[3];
                if (local_11c != (byte *)0x0) {
                  if (*(char *)((int)piVar22 + 0x205) == '\0') {
                    piVar28 = *(int **)piVar22[0x96];
                    piVar31 = *(int **)piVar22[0x97];
                    if (piVar28 == (int *)0x0) {
                      if (piVar31 != (int *)0x0) {
                        iVar29 = *piVar31;
LAB_00047b6e:
                        iVar26 = iVar29;
                        if (iVar26 != 0) goto LAB_00047156;
                      }
                    }
                    else {
                      iVar26 = *piVar28;
                      if (piVar31 == (int *)0x0) {
                        if (iVar26 == 0) goto LAB_00047160;
                      }
                      else {
                        iVar29 = *piVar31;
                        if (iVar26 == 0) goto LAB_00047b6e;
                      }
LAB_00047156:
                      iVar29 = IsPipeliningPossible(iVar26,piVar22);
                      if (iVar29 == 0) goto LAB_00047102;
                    }
                  }
LAB_00047160:
                  puVar34 = (undefined4 *)piVar10[0x86];
                  uVar35 = puVar34[0x10];
                  if ((((-1 < (int)((*(uint *)(piVar22[0x86] + 0x40) ^ uVar35) << 0x1f)) ||
                       ((iVar29 = get_protocol_family(*(undefined4 *)(piVar22[0x86] + 0x3c)),
                        iVar29 == puVar34[0xf] && ((char)piVar22[0x7b] != '\0')))) &&
                      ((-1 < (int)(uVar35 << 0x1f) ||
                       (*(short *)(param_1 + 0x288) == (short)piVar22[0x116])))) &&
                     ((*(char *)((int)piVar10 + 0x1ef) == *(char *)((int)piVar22 + 0x1ef) &&
                      ((local_11c != (byte *)0x0 || ((char)piVar22[0x10] == '\0')))))) {
                    pcVar13 = (char *)piVar10[0x117];
                    if (((pcVar13 == (char *)0x0) && ((short)piVar10[0x118] == 0)) ||
                       (((((short)piVar22[0x118] == (short)piVar10[0x118] &&
                          (piVar22[0x119] == piVar10[0x119])) &&
                         ((char *)piVar22[0x117] != (char *)0x0)) &&
                        ((pcVar13 != (char *)0x0 &&
                         (iVar29 = strcmp((char *)piVar22[0x117],pcVar13), iVar29 == 0)))))) {
                      if (-1 < (int)(uVar35 << 0x18)) {
                        iVar29 = curl_strequal(piVar10[0x48],piVar22[0x48]);
                        if ((iVar29 == 0) ||
                           (iVar29 = curl_strequal(piVar10[0x49],piVar22[0x49]), iVar29 == 0))
                        goto LAB_00047102;
                        puVar34 = (undefined4 *)piVar10[0x86];
                      }
                      if (((char)piVar10[0x7c] == '\0') || ((int)(puVar34[0x10] << 0x1f) < 0)) {
LAB_00047978:
                        iVar29 = Curl_raw_equal(*puVar34,*(undefined4 *)piVar22[0x86]);
                        if ((((iVar29 == 0) &&
                             ((iVar29 = get_protocol_family(*(undefined4 *)(piVar22[0x86] + 0x3c)),
                              iVar29 != *(int *)(piVar10[0x86] + 0x3c) ||
                              ((char)piVar22[0x7b] == '\0')))) ||
                            (iVar29 = Curl_raw_equal(piVar10[0x26],piVar22[0x26]), iVar29 == 0)) ||
                           (piVar10[0x2d] != piVar22[0x2d])) goto LAB_00047102;
                        if (*(int *)(piVar10[0x86] + 0x40) << 0x1f < 0) {
                          iVar29 = Curl_ssl_config_matches(piVar23,piVar22 + 0x6a);
                          if (iVar29 == 0) goto LAB_00047102;
                          if (piVar22[0x5f] != 2) {
                            bVar40 = true;
                            goto LAB_00047102;
                          }
                        }
                      }
                      else {
                        if (((char)piVar22[0x7c] != '\0') &&
                           ((((*(char *)((int)piVar10 + 0x1fa) != '\0' &&
                              (*(char *)((int)piVar22 + 0x1fa) != '\0')) &&
                             (iVar29 = Curl_raw_equal(piVar10[0x2a],piVar22[0x2a]), iVar29 != 0)) &&
                            (piVar10[0x2c] == piVar22[0x2c])))) {
                          puVar34 = (undefined4 *)piVar10[0x86];
                          goto LAB_00047978;
                        }
                        if (((*(char *)((int)piVar22 + 0x1ef) == '\0') ||
                            (piVar10[0x4e] != piVar22[0x4e])) ||
                           ((*(char *)((int)piVar10 + 0x1fa) != *(char *)((int)piVar22 + 0x1fa) ||
                            ((iVar29 = Curl_raw_equal(piVar10[0x2a],piVar22[0x2a]), iVar29 == 0 ||
                             (piVar10[0x2c] != piVar22[0x2c])))))) goto LAB_00047102;
                      }
                      if ((local_108 & 1) == 0) {
                        if (piVar22[0x9d] != 0) goto LAB_00047102;
                      }
                      else {
                        iVar29 = curl_strequal(piVar10[0x48],piVar22[0x48]);
                        if ((iVar29 == 0) ||
                           (iVar29 = curl_strequal(piVar10[0x49],piVar22[0x49]), iVar29 == 0))
                        goto LAB_00047102;
                      }
                      if (((uint)local_10c & 1) == 0) {
                        if (piVar22[0xa3] != 0) goto LAB_00047102;
                      }
                      else {
                        iVar29 = curl_strequal(piVar10[0x4c],piVar22[0x4c]);
                        if ((iVar29 == 0) ||
                           (iVar29 = curl_strequal(piVar10[0x4d],piVar22[0x4d]), iVar29 == 0))
                        goto LAB_00047102;
                      }
                      if ((((uint)local_10c | local_108) & 1) == 0) {
                        if ((local_11c == (byte *)0x0) || (uVar39 == 0)) goto LAB_0004759a;
                        uVar35 = local_fc;
                        if (local_fc != 0) {
                          uVar35 = 1;
                        }
                        if ((uVar39 < local_fc) || (uVar35 == 0)) {
                          iVar29 = Curl_pipeline_penalized(param_1,piVar22);
                          if (iVar29 == 0) {
                            if (uVar35 == 0) {
                              Curl_infof(param_1,"Multiplexed connection found!\n");
                              goto LAB_0004759a;
                            }
                            if (uVar39 < local_e0) goto LAB_00047524;
                          }
                          else {
                            Curl_infof(param_1,"Penalized, skip\n");
                          }
                        }
                        else {
                          Curl_infof(param_1,"Pipe is full, skip (%zu)\n",uVar39);
                        }
                      }
                      else {
                        if ((((local_108 & 1) != 0) && (piVar22[0x9d] != 0)) ||
                           ((uVar39 = local_e0, ((uint)local_10c & 1) != 0 && (piVar22[0xa3] != 0)))
                           ) goto LAB_000472be;
LAB_00047524:
                        local_e0 = uVar39;
                        local_f8 = piVar22;
                      }
                    }
                  }
                  goto LAB_00047102;
                }
                if (uVar39 == 0) {
                  cVar24 = *(char *)((int)piVar22 + 0x1ed);
                  if (piVar22[0x55] == -1) {
                    if (cVar24 == '\0') {
                      bVar40 = true;
                    }
                  }
                  else if (cVar24 == '\0') goto LAB_00047160;
                  Curl_infof(param_1,"Connection #%ld isn\'t open enough, can\'t reuse\n",
                             piVar22[0x11],cVar24,pcVar14);
                }
              }
              goto LAB_00047102;
            }
            piVar22 = local_f8;
            if (local_f8 == (int *)0x0) {
              if ((!bVar40) || (*(char *)(param_1 + 0x43f) == '\0')) goto LAB_000475ea;
              Curl_infof(param_1,"Found pending candidate for reuse and CURLOPT_PIPEWAIT is set\n");
              goto LAB_0004772e;
            }
LAB_0004759a:
            iVar29 = IsPipeliningPossible(param_1,piVar22);
            if ((((iVar29 != 0) &&
                 (*(int *)(piVar22[0x97] + 0xc) + *(int *)(piVar22[0x96] + 0xc) != 0)) &&
                (Curl_infof(param_1,"Found connection %ld, with requests in the pipe (%zu)\n",
                            piVar22[0x11]), *(uint *)(piVar22[0x11c] + 4) < uVar8)) &&
               (*(uint *)(*(int *)(param_1 + 0x580) + 0x18) < uVar9)) {
              Curl_infof(param_1,"We can reuse, but we want a new connection anyway\n");
              goto LAB_000475ea;
            }
LAB_000472be:
            pcVar30 = Curl_cfree;
            *(undefined1 *)(piVar22 + 0x10) = 1;
            (*pcVar30)(piVar10[0x28]);
            Curl_free_ssl_config(piVar23);
            cVar24 = *(char *)((int)piVar10 + 0x1f1);
            *piVar22 = *piVar10;
            *(char *)((int)piVar22 + 0x1f1) = cVar24;
            if (cVar24 != '\0') {
              (*Curl_cfree)(piVar22[0x48]);
              piVar22[0x48] = 0;
              (*Curl_cfree)(piVar22[0x49]);
              piVar22[0x49] = 0;
              iVar29 = piVar10[0x49];
              piVar22[0x48] = piVar10[0x48];
              piVar22[0x49] = iVar29;
              piVar10[0x48] = 0;
              piVar10[0x49] = 0;
            }
            cVar24 = *(char *)((int)piVar10 + 0x1f2);
            *(char *)((int)piVar22 + 0x1f2) = cVar24;
            if (cVar24 != '\0') {
              (*Curl_cfree)(piVar22[0x4c]);
              pcVar30 = Curl_cfree;
              piVar22[0x4c] = 0;
              (*pcVar30)(piVar22[0x4d]);
              piVar22[0x4d] = 0;
              iVar29 = piVar10[0x4d];
              piVar22[0x4c] = piVar10[0x4c];
              piVar22[0x4d] = iVar29;
              piVar10[0x4c] = 0;
              piVar10[0x4d] = 0;
            }
            (*Curl_cfree)(piVar22[0x24]);
            piVar22[0x24] = 0;
            iVar29 = piVar10[0x25];
            iVar26 = piVar10[0x26];
            iVar32 = piVar10[0x27];
            piVar22[0x24] = piVar10[0x24];
            piVar22[0x25] = iVar29;
            piVar22[0x26] = iVar26;
            piVar22[0x27] = iVar32;
            Curl_persistconninfo(piVar22);
            iVar29 = piVar10[0x48];
            *(undefined1 *)((int)piVar22 + 0x1ee) = 1;
            (*Curl_cfree)(iVar29);
            piVar10[0x48] = 0;
            (*Curl_cfree)(piVar10[0x49]);
            piVar10[0x49] = 0;
            (*Curl_cfree)(piVar10[0x4c]);
            piVar10[0x4c] = 0;
            (*Curl_cfree)(piVar10[0x4d]);
            pcVar30 = Curl_cfree;
            piVar10[0x4d] = 0;
            (*pcVar30)(piVar10[0x117]);
            piVar10[0x117] = 0;
            Curl_llist_destroy(piVar10[0x96],0);
            Curl_llist_destroy(piVar10[0x97],0);
            piVar10[0x96] = 0;
            piVar10[0x97] = 0;
            (*Curl_cfree)(piVar10[0x98]);
            piVar10[0x98] = 0;
            (*Curl_cfree)(piVar10);
            *param_2 = (int)piVar22;
            pcVar14 = "host";
            if (*(char *)((int)piVar22 + 0x1ef) != '\0') {
              pcVar14 = "proxy";
            }
            if (piVar22[0x2a] == 0) {
              iVar29 = piVar22[0x27];
            }
            else {
              iVar29 = piVar22[0x2b];
            }
            Curl_infof(param_1,"Re-using existing connection! (#%ld) with %s %s\n",piVar22[0x11],
                       pcVar14,iVar29);
            piVar10 = piVar22;
          }
          else {
LAB_000475ea:
            iVar29 = Curl_conncache_find_bundle(piVar10,*(undefined4 *)(param_1 + 0x580));
            if (((iVar29 != 0) && (uVar8 != 0)) && (uVar8 <= *(uint *)(iVar29 + 4))) {
              local_11c = (byte *)0x0;
              curlx_tvnow(&local_b8);
              local_10c = (byte *)0xffffffff;
              for (puVar34 = (undefined4 *)**(undefined4 **)(iVar29 + 8);
                  puVar34 != (undefined4 *)0x0; puVar34 = (undefined4 *)puVar34[2]) {
                piVar23 = (int *)*puVar34;
                if (((char)piVar23[0x10] == '\0') &&
                   (iVar29 = curlx_tvdiff(local_b8,local_b4,piVar23[0x51],piVar23[0x52]),
                   (int)local_10c < iVar29)) {
                  local_11c = (byte *)piVar23;
                  local_10c = (byte *)iVar29;
                }
              }
              if (local_11c != (byte *)0x0) {
                *(int *)local_11c = param_1;
                Curl_disconnect(local_11c,0);
                goto LAB_00047606;
              }
              Curl_infof(param_1,"No more connections allowed to host: %d\n",uVar8);
LAB_0004772e:
              Curl_infof(param_1,"No connections available.\n");
              iVar29 = 0x59;
              conn_free(piVar10);
              *param_2 = 0;
              goto LAB_00045eb2;
            }
LAB_00047606:
            if ((uVar9 != 0) && (uVar9 <= *(uint *)(*(int *)(param_1 + 0x580) + 0x18))) {
              piVar23 = (int *)find_oldest_idle_connection(param_1);
              if (piVar23 == (int *)0x0) {
                Curl_infof(param_1,"No connections available in cache\n");
                goto LAB_0004772e;
              }
              *piVar23 = param_1;
              Curl_disconnect(piVar23,0);
            }
            Curl_conncache_add_conn(*(undefined4 *)(param_1 + 0x580),piVar10);
            if (((*(uint *)(param_1 + 0x8624) & 0x28) != 0) && (*(char *)(param_1 + 0x862c) != '\0')
               ) {
              Curl_infof(param_1,"NTLM picked AND auth done set, clear picked!\n");
              *(undefined4 *)(param_1 + 0x8624) = 0;
              *(undefined1 *)(param_1 + 0x862c) = 0;
            }
            if (((*(uint *)(param_1 + 0x8634) & 0x28) != 0) && (*(char *)(param_1 + 0x863c) != '\0')
               ) {
              Curl_infof(param_1,"NTLM-proxy picked AND auth done set, clear picked!\n");
              *(undefined4 *)(param_1 + 0x8634) = 0;
              *(undefined1 *)(param_1 + 0x863c) = 0;
            }
          }
          *(undefined1 *)(piVar10 + 0x10) = 1;
          Curl_init_do(param_1,piVar10);
          iVar29 = setup_range(param_1);
          if (iVar29 != 0) goto LAB_00045eb2;
          piVar10[0x9b] = *(int *)(param_1 + 400);
          piVar10[0x9c] = *(int *)(param_1 + 0x1e8);
          uVar7 = Curl_timeleft(param_1,0,1);
          if (*(char *)((int)piVar10 + 0x1ee) == '\0') {
            pcVar14 = *(char **)(param_1 + 0x3ec);
            if (pcVar14 == (char *)0x0) {
              pcVar14 = (char *)piVar10[0x2a];
              if ((pcVar14 == (char *)0x0) || (*pcVar14 == '\0')) {
                piVar10[0x2c] = piVar10[0x2d];
                iVar26 = Curl_resolv_timeout(piVar10,piVar10[0x26],piVar10[0x2d],&local_bc,uVar7);
                if (iVar26 == 1) goto LAB_00047922;
                if (iVar26 == -2) {
                  iVar29 = 0x1c;
                }
                else if (local_bc == (int *)0x0) {
                  iVar29 = 6;
                  Curl_failf(param_1,"Couldn\'t resolve host \'%s\'",piVar10[0x27]);
                }
              }
              else {
                iVar26 = Curl_resolv_timeout(piVar10,pcVar14,piVar10[0x2c],&local_bc,uVar7);
                if (iVar26 == 1) {
LAB_00047922:
                  *param_3 = (char)iVar26;
                }
                else if (iVar26 == -2) {
                  iVar29 = 0x1c;
                }
                else if (local_bc == (int *)0x0) {
                  iVar29 = 5;
                  Curl_failf(param_1,"Couldn\'t resolve proxy \'%s\'",piVar10[0x2b]);
                }
              }
            }
            else {
              piVar23 = (int *)(*Curl_ccalloc)(1,0xc);
              local_bc = piVar23;
              if (piVar23 == (int *)0x0) {
                iVar29 = 0x1b;
              }
              else {
                iVar26 = Curl_unix2addr(pcVar14);
                *piVar23 = iVar26;
                if (iVar26 == 0) {
                  sVar11 = strlen(pcVar14);
                  if (sVar11 < 0x6c) {
                    iVar29 = 0x1b;
                  }
                  else {
                    iVar29 = 6;
                    Curl_failf(param_1,"Unix socket path too long: \'%s\'",pcVar14);
                  }
                  (*Curl_cfree)(local_bc);
                  local_bc = (int *)0x0;
                }
                else {
                  local_bc[2] = local_bc[2] + 1;
                }
              }
            }
            piVar10[0x12] = (int)local_bc;
          }
          else {
            *param_3 = '\0';
          }
        }
LAB_00046ac8:
        (*Curl_cfree)(pcVar25);
        (*Curl_cfree)(local_c8);
        (*Curl_cfree)(local_cc);
        (*Curl_cfree)(0);
        if (iVar29 == 0) {
          iVar29 = *param_2;
          if ((*(int *)(*(int *)(iVar29 + 600) + 0xc) != 0) ||
             (*(int *)(*(int *)(iVar29 + 0x25c) + 0xc) != 0)) {
            *param_4 = 1;
            return 0;
          }
          if (*param_3 != '\0') {
            return 0;
          }
          iVar29 = Curl_setup_conn(iVar29,param_4);
          goto LAB_00045ed2;
        }
        if (iVar29 == 0x59) goto LAB_00045f1c;
        goto LAB_00045ede;
      }
    }
    else {
      iVar29 = (*Curl_ccalloc)(0x4000,1);
      piVar10[0x98] = iVar29;
      if (iVar29 != 0) goto LAB_00045d94;
LAB_00045f48:
      iVar26 = piVar10[0x96];
    }
    Curl_llist_destroy(iVar26,0);
    Curl_llist_destroy(piVar10[0x97],0);
    pcVar30 = Curl_cfree;
    piVar10[0x96] = 0;
    piVar10[0x97] = 0;
    (*pcVar30)(piVar10[0x98]);
    (*Curl_cfree)(piVar10[0x117]);
    (*Curl_cfree)(piVar10);
  }
  pcVar25 = (char *)0x0;
  iVar29 = 0x1b;
LAB_00045eb2:
  (*Curl_cfree)(pcVar25);
  (*Curl_cfree)(local_c8);
  (*Curl_cfree)(local_cc);
  (*Curl_cfree)(0);
LAB_00045ed2:
  if (iVar29 == 0x59) {
LAB_00045f1c:
    iVar29 = 0x59;
    *param_2 = 0;
  }
  else if (iVar29 != 0) {
LAB_00045ede:
    if (*param_2 != 0) {
      Curl_disconnect(*param_2,0);
      *param_2 = 0;
    }
  }
  return iVar29;
LAB_0004625c:
  puVar12 = (undefined1 *)((int)puVar12 + 4);
  puVar33 = *(undefined1 **)puVar12;
  if ((undefined4 *)puVar33 == (undefined4 *)0x0) goto LAB_000462a6;
  goto LAB_00046266;
LAB_000462a6:
  iVar29 = 1;
  Curl_failf(param_1,"Protocol \"%s\" not supported or disabled in libcurl",local_10c);
  goto LAB_00045eb2;
}

