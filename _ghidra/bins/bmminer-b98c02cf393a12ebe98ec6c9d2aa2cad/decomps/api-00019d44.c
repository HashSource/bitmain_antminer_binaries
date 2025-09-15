
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void api(void)

{
  bool bVar1;
  undefined4 *puVar2;
  char cVar3;
  int *__ptr;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  size_t sVar8;
  __int32_t **pp_Var9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  ushort **ppuVar13;
  byte *pbVar14;
  long lVar15;
  time_t tVar16;
  ssize_t sVar17;
  char *pcVar18;
  char *pcVar19;
  int iVar20;
  time_t tVar21;
  int *piVar22;
  undefined4 uVar23;
  byte bVar24;
  __int32_t *p_Var25;
  bool bVar26;
  undefined4 uVar27;
  byte *pbVar28;
  addrinfo *paVar29;
  int iVar30;
  int iVar31;
  char *pcVar32;
  byte *pbVar33;
  uint uVar34;
  char *pcVar35;
  __int32_t **unaff_r11;
  undefined8 uVar36;
  byte *pbStack_16488;
  char *pcStack_16480;
  int *piStack_16478;
  short sStack_16464;
  char *pcStack_16460;
  byte *pbStack_1644c;
  byte bStack_16422;
  undefined1 uStack_16421;
  void *pvStack_16420;
  socklen_t sStack_1641c;
  addrinfo *paStack_16418;
  undefined4 uStack_16414;
  char acStack_16410 [12];
  char acStack_16404 [32];
  addrinfo aStack_163e4;
  undefined1 auStack_163c4 [12];
  pthread_t pStack_163b8;
  char acStack_16384 [100];
  char acStack_16320 [100];
  sockaddr asStack_162bc [8];
  undefined1 auStack_1623c [252];
  __pthread_unwind_buf_t a_Stack_16140 [6];
  char acStack_16028 [2048];
  char acStack_15828 [2048];
  char acStack_15028 [2048];
  char acStack_14828 [2048];
  char acStack_14028 [2048];
  char acStack_13828 [2048];
  char acStack_13028 [2048];
  char acStack_12828 [2048];
  char acStack_12028 [2048];
  char acStack_11828 [2048];
  char acStack_11028 [2048];
  char acStack_10828 [2048];
  char acStack_10028 [2048];
  char acStack_f828 [2048];
  char acStack_f028 [2048];
  char acStack_e828 [2048];
  char acStack_e028 [2048];
  char acStack_d828 [2048];
  char local_d028 [2048];
  char local_c828 [44];
  undefined2 uStack_c7fc;
  undefined1 local_c7fa;
  char acStack_c028 [2048];
  char local_b828 [28];
  undefined2 local_b80c;
  char acStack_b028 [2048];
  char acStack_a828 [2048];
  char acStack_a028 [2048];
  char acStack_9828 [2048];
  char acStack_9028 [2048];
  char acStack_8828 [2048];
  char local_8028 [2048];
  char local_7828 [40];
  undefined2 local_7800;
  char local_7028 [28];
  undefined2 local_700c;
  char local_6828 [24];
  undefined2 local_6810;
  char local_6028 [8192];
  char acStack_4028 [8192];
  char local_2028;
  char local_2027 [8195];
  
  uVar23 = opt_api_port;
  pvStack_16420 = (void *)0x0;
  piStack_16478 = (int *)0x0;
  bVar1 = false;
  __ptr = (int *)malloc(4);
  cVar3 = opt_api_listen;
  *__ptr = -1;
  if (cVar3 == '\0') {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_16028,0x800,"API not running%s"," - API will not be available");
      _applog(7,acStack_16028,0);
    }
    goto LAB_00019dcc;
  }
  puVar4 = (undefined4 *)malloc(0x10);
  puVar5 = (undefined1 *)malloc(0x10000);
  pcVar32 = (char *)0x0;
  puVar4[1] = puVar5;
  puVar4[2] = puVar5;
  *puVar5 = 0;
  *(undefined1 *)(puVar4 + 3) = 1;
  *(undefined1 *)((int)puVar4 + 0xd) = 0;
  *puVar4 = 0x10000;
  puVar6 = (undefined4 *)malloc(0xc);
  *puVar6 = puVar4;
  puVar2 = io_head;
  if (io_head == (undefined4 *)0x0) {
    puVar6[1] = puVar6;
    puVar6[2] = puVar6;
    io_head = puVar6;
  }
  else {
    uVar27 = io_head[1];
    puVar6[2] = io_head;
    puVar6[1] = uVar27;
    puVar2[1] = puVar6;
    *(undefined4 **)(puVar6[1] + 8) = puVar6;
  }
  iVar7 = pthread_mutex_init((pthread_mutex_t *)quit_restart_lock,(pthread_mutexattr_t *)0x0);
  if (iVar7 != 0) {
    piVar22 = __errno_location();
    snprintf(acStack_c028,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar22,
             "api.c",&__func___11687,0x1511);
    _applog(3,acStack_c028,1);
    _quit(1);
  }
  iVar7 = __sigsetjmp(a_Stack_16140,0);
  if (iVar7 == 0) {
    __pthread_register_cancel(a_Stack_16140);
    pcVar32 = opt_api_groups;
    if (opt_api_groups == (char *)0x0) {
      sVar8 = 1;
      pcVar32 = "";
    }
    else {
      sVar8 = strlen(opt_api_groups);
      sVar8 = sVar8 + 1;
    }
    pbStack_1644c = (byte *)malloc(sVar8);
    if (pbStack_1644c == (byte *)0x0) {
      builtin_strncpy(local_b828,"Failed to malloc ipgroups bu",0x1c);
      local_b80c = 0x66;
      _applog(3,local_b828,1);
      _quit(1);
    }
    strcpy((char *)pbStack_1644c,pcVar32);
    bVar24 = *pbStack_1644c;
    pbVar11 = pbStack_1644c;
    while (bVar24 != 0) {
      pcVar32 = strchr((char *)pbVar11,0x2c);
      if (pcVar32 == (char *)0x0) {
        pbStack_16488 = (byte *)0x0;
      }
      else {
        pbStack_16488 = (byte *)(pcVar32 + 1);
        *pcVar32 = '\0';
      }
      if (pbVar11[1] != 0x3a) {
        pcVar32 = strchr((char *)pbVar11,0x3a);
        if (pcVar32 != (char *)0x0) {
          *pcVar32 = '\0';
        }
        snprintf(acStack_b028,0x800,"API invalid group name \'%s\'",pbVar11);
        _applog(3,acStack_b028,1);
        _quit(1);
      }
      pp_Var9 = __ctype_toupper_loc();
      p_Var25 = *pp_Var9;
      uVar34 = (uint)*(byte *)(p_Var25 + *pbVar11);
      if ((p_Var25[uVar34] < p_Var25[0x41]) || (p_Var25[0x5a] < p_Var25[uVar34])) {
        snprintf(acStack_a828,0x800,"API invalid group name \'%c\'");
        _applog(3,acStack_a828,1);
        _quit(1);
        p_Var25 = *pp_Var9;
      }
      if (uVar34 == p_Var25[0x57]) {
        snprintf(acStack_a028,0x800,"API group name can\'t be \'%c\'",uVar34);
        _applog(3,acStack_a028,1);
        _quit(1);
        p_Var25 = *pp_Var9;
      }
      if (uVar34 == p_Var25[0x52]) {
        snprintf(acStack_9828,0x800,"API group name can\'t be \'%c\'",uVar34);
        _applog(3,acStack_9828,1);
        _quit(1);
        p_Var25 = *pp_Var9;
      }
      if (*(int *)(apigroups + (p_Var25[uVar34] - p_Var25[0x41]) * 4) != 0) {
        snprintf(acStack_9028,0x800,"API duplicate group name \'%c\'",(uint)*pbVar11);
        _applog(3,acStack_9028,1);
        _quit(1);
      }
      local_2028 = '|';
      local_2027[0] = '\0';
      if ((pbVar11 + 2 != (byte *)0x0) && (pbVar11[2] != 0)) {
        pcStack_16480 = local_2027;
        bVar26 = false;
        pbVar11 = pbVar11 + 2;
        do {
          pbVar10 = (byte *)strchr((char *)pbVar11,0x3a);
          pbVar33 = pbVar10;
          if (pbVar10 != (byte *)0x0) {
            pbVar33 = pbVar10 + 1;
            *pbVar10 = 0;
          }
          if ((*pbVar11 == 0x2a) && (pbVar11[1] == 0)) {
            bVar26 = true;
          }
          else {
            if (cmds._0_4_ != 0) {
              puVar5 = cmds;
              iVar7 = 0;
              pcVar32 = (char *)cmds._0_4_;
              do {
                iVar31 = strcasecmp((char *)pbVar11,pcVar32);
                if (iVar31 == 0) {
                  sprintf(acStack_16320,"|%s|",pcVar32);
                  pcVar32 = strstr(&local_2028,acStack_16320);
                  if (pcVar32 == (char *)0x0) {
                    pcVar32 = *(char **)(cmds + iVar7 * 0xc);
                    strcpy(pcStack_16480,pcVar32);
                    sVar8 = strlen(pcVar32);
                    pcVar32 = pcStack_16480 + sVar8;
                    pcStack_16480 = pcStack_16480 + sVar8 + 1;
                    pcVar32[1] = '\0';
                    *pcVar32 = '|';
                  }
                  goto joined_r0x0001a08e;
                }
                puVar5 = (undefined1 *)((int)puVar5 + 0xc);
                pcVar32 = *(char **)puVar5;
                iVar7 = iVar7 + 1;
              } while (pcVar32 != (char *)0x0);
            }
            snprintf(acStack_8828,0x800,"API unknown command \'%s\' in group \'%c\'",pbVar11,uVar34)
            ;
            _applog(3,acStack_8828,1);
            _quit(1);
          }
joined_r0x0001a08e:
        } while ((pbVar33 != (byte *)0x0) && (pbVar11 = pbVar33, *pbVar33 != 0));
        if ((bVar26) && (cmds._0_4_ != 0)) {
          puVar5 = cmds;
LAB_0001a0ae:
          do {
            if ((char)*(int *)((int)puVar5 + 8) == '\0') {
              sprintf(acStack_16320,"|%s|");
              pcVar32 = strstr(&local_2028,acStack_16320);
              if (pcVar32 == (char *)0x0) {
                pcVar32 = *(char **)puVar5;
                strcpy(pcStack_16480,pcVar32);
                sVar8 = strlen(pcVar32);
                pcVar32 = pcStack_16480 + sVar8;
                pcStack_16480 = pcStack_16480 + sVar8 + 1;
                *pcVar32 = '|';
                puVar5 = (undefined1 *)((int)puVar5 + 0xc);
                iVar7 = *(int *)puVar5;
                pcVar32[1] = '\0';
                if (iVar7 == 0) break;
                goto LAB_0001a0ae;
              }
            }
            puVar5 = (undefined1 *)((int)puVar5 + 0xc);
          } while (*(int *)puVar5 != 0);
        }
      }
      iVar31 = (*pp_Var9)[uVar34];
      iVar7 = (*pp_Var9)[0x41];
      sVar8 = strlen(&local_2028);
      pcVar32 = (char *)malloc(sVar8 + 1);
      *(char **)(apigroups + (iVar31 - iVar7) * 4) = pcVar32;
      if (pcVar32 == (char *)0x0) {
        builtin_strncpy(local_8028,"Failed to malloc group commands buf",0x24);
        _applog(3,local_8028,1);
        _quit(1);
      }
      strcpy(pcVar32,&local_2028);
      if (pbStack_16488 == (byte *)0x0) break;
      pbVar11 = pbStack_16488;
      bVar24 = *pbStack_16488;
    }
    unaff_r11 = __ctype_toupper_loc();
    local_2027[0] = '\0';
    local_2028 = '|';
    puVar5 = cmds;
    pcVar32 = local_2027;
    pcVar18 = (char *)cmds._0_4_;
    while (pcVar18 != (char *)0x0) {
      while ((char)*(int *)((int)puVar5 + 8) == '\0') {
        strcpy(pcVar32,pcVar18);
        sVar8 = strlen(pcVar18);
        puVar5 = (undefined1 *)((int)puVar5 + 0xc);
        pcVar18 = *(char **)puVar5;
        pcVar35 = pcVar32 + sVar8;
        pcVar32 = pcVar32 + sVar8 + 1;
        *pcVar35 = '|';
        pcVar35[1] = '\0';
        if (pcVar18 == (char *)0x0) goto LAB_0001a19c;
      }
      puVar5 = (undefined1 *)((int)puVar5 + 0xc);
      pcVar18 = *(char **)puVar5;
    }
LAB_0001a19c:
    p_Var25 = *unaff_r11;
    iVar7 = p_Var25[0x52];
    if (iVar7 + 0x80U < 0x180) {
      iVar7 = p_Var25[iVar7];
    }
    iVar31 = p_Var25[0x41];
    sVar8 = strlen(&local_2028);
    pcVar32 = (char *)malloc(sVar8 + 1);
    *(char **)(apigroups + (iVar7 - iVar31) * 4) = pcVar32;
    if (pcVar32 == (char *)0x0) goto LAB_0001aca2;
  }
  else {
    tidyup(__ptr);
    __pthread_unwind_next(a_Stack_16140);
LAB_0001aca2:
    builtin_strncpy(local_7828,"Failed to malloc noprivgroup commands bu",0x28);
    local_7800 = 0x66;
    _applog(3,local_7828,1);
    _quit(1);
  }
  strcpy(pcVar32,&local_2028);
  free(pbStack_1644c);
  pcVar32 = opt_api_allow;
  if (opt_api_allow != (char *)0x0) {
    sVar8 = strlen(opt_api_allow);
    pbVar11 = (byte *)malloc(sVar8 + 1);
    if (pbVar11 == (byte *)0x0) {
      builtin_strncpy(local_7028,"Failed to malloc ipaccess bu",0x1c);
      local_700c = 0x66;
      _applog(3,local_7028,1);
      _quit(1);
      pcVar32 = opt_api_allow;
    }
    strcpy((char *)pbVar11,pcVar32);
    pbVar33 = pbVar11 + -1;
    sVar8 = 1;
    while( true ) {
      pbVar33 = pbVar33 + 1;
      if (*pbVar33 == 0) break;
      if (*pbVar33 == 0x2c) {
        sVar8 = sVar8 + 1;
      }
    }
    ipaccess = calloc(sVar8,0x24);
    if (ipaccess == (void *)0x0) {
      builtin_strncpy(local_6828,"Failed to calloc ipacces",0x18);
      local_6810 = 0x73;
      _applog(3,local_6828,1);
      _quit(1);
    }
    iVar7 = 0;
    ips = 0;
    pbVar33 = pbVar11;
    do {
      while( true ) {
        bVar24 = *pbVar33;
        if (bVar24 == 0) goto LAB_0001a322;
        if (bVar24 == 9 || bVar24 == 0x20) {
          do {
            pbVar33 = pbVar33 + 1;
            bVar24 = *pbVar33;
          } while (bVar24 == 9 || bVar24 == 0x20);
        }
        if (bVar24 == 0x2c) {
          pbVar10 = pbVar33 + 1;
          goto LAB_0001a31e;
        }
        pbVar12 = (byte *)strchr((char *)pbVar33,0x2c);
        pbVar10 = pbVar12;
        if (pbVar12 != (byte *)0x0) {
          pbVar10 = pbVar12 + 1;
          *pbVar12 = 0;
        }
        ppuVar13 = __ctype_b_loc();
        p_Var25 = *unaff_r11;
        bVar24 = *(byte *)(p_Var25 + 0x52);
        if (((int)((uint)(*ppuVar13)[*pbVar33] << 0x15) < 0) && (pbVar33[1] == 0x3a)) {
          iVar31 = p_Var25[*pbVar33];
          if ((iVar31 == p_Var25[0x57]) || (*(int *)(apigroups + (iVar31 - p_Var25[0x41]) * 4) != 0)
             ) {
            bVar24 = (byte)iVar31;
          }
          pbVar33 = pbVar33 + 2;
        }
        pbVar12 = (byte *)((int)ipaccess + iVar7 * 0x24);
        pbVar12[0x20] = bVar24;
        bVar24 = *pbVar33;
        if (bVar24 == 0x30) break;
        pbVar14 = (byte *)strchr((char *)pbVar33,0x2f);
        if (pbVar14 == (byte *)0x0) {
LAB_0001a4d4:
          pbVar14 = pbVar12 + 0xf;
          do {
            pbVar14 = pbVar14 + 1;
            *pbVar14 = 0xff;
          } while (pbVar14 != pbVar12 + 0x1f);
          sVar8 = strlen((char *)pbVar33);
          bVar24 = *pbVar33;
          pbVar14 = pbVar33 + sVar8;
        }
        if ((bVar24 == 0x5b) && (pbVar14[-1] == 0x5d)) {
          *pbVar33 = 0;
          pbVar33 = pbVar33 + 1;
          pbVar14[-1] = 0;
          bVar26 = true;
        }
        else {
LAB_0001a2ea:
          bVar26 = false;
        }
        if (*pbVar14 == 0) {
LAB_0001a2f6:
          pbVar14 = pbVar12 + -1;
          do {
            pbVar14 = pbVar14 + 1;
            *pbVar14 = 0;
          } while (pbVar14 != pbVar12 + 0xf);
          if (bVar26) {
            iVar31 = inet_pton(10,(char *)pbVar33,pbVar12);
          }
          else {
            sprintf(acStack_16404,"::ffff:%s",pbVar33);
            iVar7 = ips;
            pbVar12 = (byte *)((int)ipaccess + ips * 0x24);
            iVar31 = inet_pton(10,acStack_16404,pbVar12);
          }
          if (iVar31 == 1) {
            pbVar33 = pbVar12 + 0xf;
            pbVar14 = pbVar12;
            do {
              pbVar33 = pbVar33 + 1;
              pbVar28 = pbVar14 + 1;
              *pbVar14 = *pbVar33 & *pbVar14;
              pbVar14 = pbVar28;
            } while (pbVar28 != pbVar12 + 0x10);
            goto LAB_0001a492;
          }
        }
        else {
          *pbVar14 = 0;
          lVar15 = strtol((char *)(pbVar14 + 1),(char **)0x0,10);
          if (0 < lVar15) {
            iVar30 = 0;
            iVar31 = iVar30;
            if (!bVar26) {
              iVar31 = 0x60;
            }
            iVar31 = lVar15 + iVar31;
            if (iVar31 < 0x81) {
              pbVar14 = pbVar12 + 0xf;
              do {
                pbVar14 = pbVar14 + 1;
                *pbVar14 = 0;
              } while (pbVar12 + 0x1f != pbVar14);
              while (uVar34 = 7, iVar31 != 0) {
                while( true ) {
                  iVar31 = iVar31 + -1;
                  pbVar12[iVar30 + 0x10] = pbVar12[iVar30 + 0x10] | (byte)(1 << (uVar34 & 0xff));
                  if (uVar34 == 0) break;
                  uVar34 = uVar34 - 1;
                  if (iVar31 == 0) goto LAB_0001a2f6;
                }
                iVar30 = iVar30 + 1;
              }
              goto LAB_0001a2f6;
            }
          }
        }
LAB_0001a31e:
        pbVar33 = pbVar10;
        if (pbVar10 == (byte *)0x0) goto LAB_0001a322;
      }
      if (((pbVar33[1] != 0x2f) || (pbVar33[2] != 0x30)) || (pbVar33[3] != 0)) {
        pbVar14 = (byte *)strchr((char *)pbVar33,0x2f);
        if (pbVar14 == (byte *)0x0) goto LAB_0001a4d4;
        goto LAB_0001a2ea;
      }
      pbVar33 = pbVar12 + -1;
      pbVar14 = pbVar12 + 0xf;
      do {
        pbVar33 = pbVar33 + 1;
        *pbVar33 = 0;
        pbVar14 = pbVar14 + 1;
        *pbVar14 = 0;
      } while (pbVar12 + 0xf != pbVar33);
LAB_0001a492:
      iVar7 = iVar7 + 1;
      pbVar33 = pbVar10;
      ips = iVar7;
    } while (pbVar10 != (byte *)0x0);
LAB_0001a322:
    free(pbVar11);
    if (iVar7 == 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(acStack_15828,0x800,"API not running (no valid IPs specified)%s",
                 " - API will not be available");
        _applog(4,acStack_15828,0);
      }
      goto LAB_00019dcc;
    }
  }
  sStack_16464 = (short)uVar23;
  iVar31 = (int)sStack_16464;
  cgsleep_ms(opt_log_interval * 1000);
  sprintf(acStack_16410,"%d",iVar31);
  memset(&aStack_163e4,0,0x20);
  aStack_163e4.ai_flags = 1;
  iVar7 = getaddrinfo(opt_api_host,acStack_16410,&aStack_163e4,&paStack_16418);
  if (iVar7 != 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_15028,0x800,"API failed to resolve %s",opt_api_host);
      _applog(3,acStack_15028,0);
    }
LAB_00019dcc:
    free(__ptr);
    return;
  }
  paVar29 = paStack_16418;
  if (paStack_16418 == (addrinfo *)0x0) {
    iVar7 = *__ptr;
  }
  else {
    do {
      iVar7 = socket(paStack_16418->ai_family,1,0);
      *__ptr = iVar7;
      if (0 < iVar7) goto LAB_0001a67e;
      paVar29 = paVar29->ai_next;
    } while (paVar29 != (addrinfo *)0x0);
  }
  if (iVar7 == -1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      piVar22 = __errno_location();
      pcVar32 = strerror(*piVar22);
      snprintf(acStack_14828,0x800,"API initialisation failed (%s)%s",pcVar32,
               " - API will not be available");
      _applog(3,acStack_14828,0);
    }
    freeaddrinfo(paStack_16418);
    free(__ptr);
    return;
  }
  paVar29 = (addrinfo *)0x0;
LAB_0001a67e:
  uStack_16414 = 1;
  iVar7 = setsockopt(iVar7,1,2,&uStack_16414,4);
  if (((iVar7 < 0) && (opt_debug != '\0')) &&
     ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
    piVar22 = __errno_location();
    pcVar32 = strerror(*piVar22);
    snprintf(acStack_14028,0x800,"API setsockopt SO_REUSEADDR failed (ignored): %s",pcVar32);
    _applog(7,acStack_14028,0);
  }
  tVar16 = time((time_t *)0x0);
  while (iVar7 = bind(*__ptr,paVar29->ai_addr,paVar29->ai_addrlen), iVar7 < 0) {
    piVar22 = __errno_location();
    pcVar32 = strerror(*piVar22);
    tVar21 = time((time_t *)0x0);
    if (0x3d < tVar21 - tVar16) {
      freeaddrinfo(paStack_16418);
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_13028,0x800,"API bind to port %d failed (%s)%s",iVar31,pcVar32,
                 " - API will not be available");
        _applog(3,acStack_13028,0);
      }
      goto LAB_00019dcc;
    }
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(acStack_13828,0x800,"API bind to port %d failed - trying again in 30sec",iVar31);
      _applog(4,acStack_13828,0);
    }
    cgsleep_ms(30000);
  }
  freeaddrinfo(paStack_16418);
  iVar7 = listen(*__ptr,100);
  if (iVar7 < 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      piVar22 = __errno_location();
      pcVar32 = strerror(*piVar22);
      snprintf(acStack_12828,0x800,"API3 initialisation failed (%s)%s",pcVar32,
               " - API will not be available");
      _applog(3,acStack_12828,0);
    }
    close(*__ptr);
    free(__ptr);
    return;
  }
  if (opt_api_allow == (char *)0x0) {
    if (opt_api_network == '\0') {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(acStack_11028,0x800,"API running in local read access mode on port %d (%d)",iVar31,
                 *__ptr);
        _applog(4,acStack_11028,0);
      }
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(acStack_11828,0x800,"API running in UNRESTRICTED read access mode on port %d (%d)",
               iVar31,*__ptr);
      _applog(4,acStack_11828,0);
    }
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
    snprintf(acStack_12028,0x800,"API running in IP access mode on port %d (%d)",iVar31,*__ptr);
    _applog(4,acStack_12028,0);
  }
  if (opt_api_mcast != '\0') {
    mcast_init();
  }
  strbufs = _k_new_list("StrBufs",0xc,2,0,0,"api.c",&__func___11687,0x1581);
  while (bye == '\0') {
    sStack_1641c = 0x80;
    iVar7 = accept(*__ptr,asStack_162bc,&sStack_1641c);
    if (iVar7 < 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        piVar22 = __errno_location();
        pcVar32 = strerror(*piVar22);
        snprintf(acStack_10828,0x800,"API failed (%s)%s (%d)",pcVar32," - API will not be available"
                 ,*__ptr);
        _applog(3,acStack_10828,0);
      }
      break;
    }
    if (pvStack_16420 != (void *)0x0) {
      free(pvStack_16420);
      pvStack_16420 = (void *)0x0;
    }
    iVar31 = check_connect(asStack_162bc,&pvStack_16420,&bStack_16422);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      pcVar32 = "Accepted";
      if (iVar31 == 0) {
        pcVar32 = "Ignored";
      }
      snprintf(acStack_10028,0x800,"API: connection from %s - %s",pvStack_16420,pcVar32);
      _applog(7,acStack_10028,0);
    }
    if (iVar31 != 0) {
      sVar17 = recv(iVar7,local_6028,0x1fff,0);
      if (sVar17 < 0) {
        local_6028[0] = '\0';
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          piVar22 = __errno_location();
          pcVar32 = strerror(*piVar22);
          snprintf(acStack_f828,0x800,"API: recv failed: %s",pcVar32);
          _applog(7,acStack_f828,0);
        }
      }
      else {
        local_6028[sVar17] = '\0';
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          snprintf(acStack_f028,0x800,"API: recv command: (%d) \'%s\'",sVar17,local_6028);
          _applog(7,acStack_f028,0);
        }
        iVar31 = 0;
        pcVar32 = local_6028;
        when = time((time_t *)0x0);
        puVar4[2] = (undefined1 *)puVar4[1];
        *(undefined1 *)puVar4[1] = 0;
        *(undefined1 *)((int)puVar4 + 0xd) = 0;
        if (local_6028[0] != '{') {
          pcVar18 = strchr(pcVar32,0x7c);
          if (pcVar18 == (char *)0x0) {
            iVar31 = 0;
            pcVar35 = (char *)0x0;
          }
          else {
            pcVar35 = pcVar18 + 1;
            *pcVar18 = '\0';
          }
LAB_0001a90c:
          pcVar18 = strchr(pcVar32,0x2b);
          if (pcVar18 == (char *)0x0) {
            uStack_16421 = 0;
            bVar1 = false;
            pcStack_16460 = (char *)0x0;
          }
          else {
            bVar1 = true;
            uStack_16421 = 1;
            sVar8 = strlen(pcVar32);
            pcStack_16460 = (char *)malloc(sVar8 + 3);
            if (pcStack_16460 == (char *)0x0) {
              snprintf(acStack_e828,0x800,"OOM cmdsbuf in %s %s():%d","api.c",&__func___11687,0x15f4
                      );
              _applog(3,acStack_e828,1);
              _quit(1);
            }
            pcVar35 = (char *)0x0;
            pcStack_16460[0] = '|';
            pcStack_16460[1] = '\0';
          }
          pcVar18 = pcVar32;
          if (!bVar1) goto LAB_0001a98c;
LAB_0001a954:
          pcVar19 = strchr(pcVar18,0x2b);
          if (pcVar19 == (char *)0x0) {
            if (*pcVar18 == '\0') goto LAB_0001af08;
            pcVar32 = (char *)0x0;
          }
          else {
            pcVar32 = pcVar19 + 1;
            *pcVar19 = '\0';
            if (*pcVar18 == '\0') goto LAB_0001a974;
          }
          if (cmds._0_4_ != 0) goto LAB_0001a996;
LAB_0001ab36:
          head_join(puVar4,pcVar18,iVar31,&uStack_16421);
LAB_0001ab42:
          message(puVar4,0xe,0,0,iVar31);
          do {
            if (bVar1) {
              tail_join(puVar4,iVar31);
            }
            else {
              send_result_isra_6(puVar4[1],(int)puVar4 + 0xd,iVar7,iVar31);
            }
            while( true ) {
              do {
                if (!bVar1) goto LAB_0001a9dc;
LAB_0001a974:
                bVar26 = bVar1;
                if (pcVar32 == (char *)0x0) {
                  bVar26 = false;
                }
                if (!bVar26) goto LAB_0001af08;
                pcVar18 = pcVar32;
                if (bVar1) goto LAB_0001a954;
LAB_0001a98c:
                pcVar18 = pcVar32;
                if (cmds._0_4_ == 0) goto LAB_0001ab42;
LAB_0001a996:
                puVar5 = cmds;
                iVar30 = 0;
                pcVar19 = (char *)cmds._0_4_;
                while (iVar20 = strcmp(pcVar18,pcVar19), iVar20 != 0) {
                  puVar5 = (undefined1 *)((int)puVar5 + 0xc);
                  pcVar19 = *(char **)puVar5;
                  iVar30 = iVar30 + 1;
                  if (pcVar19 == (char *)0x0) {
                    if (bVar1) goto LAB_0001ab36;
                    goto LAB_0001ab42;
                  }
                }
                sprintf(acStack_16384,"|%s|",pcVar18);
                if (!bVar1) goto LAB_0001aada;
                pcVar19 = strstr(pcStack_16460,acStack_16384);
              } while (pcVar19 != (char *)0x0);
              sVar8 = strlen(pcStack_16460);
              pcVar19 = stpcpy(pcStack_16460 + sVar8,pcVar18);
              pcVar19[0] = '|';
              pcVar19[1] = '\0';
              head_join(puVar4,pcVar18,iVar31,&uStack_16421);
              if (cmds[iVar30 * 0xc + 9] != '\0') break;
              message(puVar4,0x2d,0,*(undefined4 *)(cmds + iVar30 * 0xc),iVar31);
              tail_join(puVar4,iVar31);
            }
LAB_0001aada:
            uVar34 = (uint)bStack_16422;
            p_Var25 = *unaff_r11;
            if ((p_Var25[uVar34] == p_Var25[0x57]) ||
               (pcVar18 = strstr(*(char **)(apigroups + (p_Var25[uVar34] - p_Var25[0x41]) * 4),
                                 acStack_16384), pcVar18 != (char *)0x0)) {
              (**(code **)(cmds + iVar30 * 0xc + 4))(puVar4,iVar7,pcVar35,iVar31,uVar34);
            }
            else {
              message(puVar4,0x2d,0,*(undefined4 *)(cmds + iVar30 * 0xc),iVar31);
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(acStack_e028,0x800,"API: access denied to \'%s\' for \'%s\' command",
                         pvStack_16420,*(undefined4 *)(cmds + iVar30 * 0xc));
                _applog(7,acStack_e028,0);
              }
            }
          } while( true );
        }
        piStack_16478 = (int *)json_loadb(pcVar32,sVar17,0,auStack_1623c);
        if ((piStack_16478 == (int *)0x0) || (*piStack_16478 != 0)) {
          uVar23 = 0x17;
        }
        else {
          piVar22 = (int *)json_object_get(piStack_16478,"command");
          if (piVar22 == (int *)0x0) {
            uVar23 = 0x18;
          }
          else {
            if (*piVar22 == 2) {
              pcVar32 = (char *)json_string_value();
              piVar22 = (int *)json_object_get(piStack_16478,"parameter");
              if (piVar22 == (int *)0x0) {
                iVar31 = 1;
                pcVar35 = (char *)0x0;
              }
              else {
                iVar31 = *piVar22;
                if (iVar31 == 2) {
                  pcVar35 = (char *)json_string_value();
                  iVar31 = 1;
                }
                else if (iVar31 == 3) {
                  uVar23 = json_integer_value();
                  pcVar35 = acStack_4028;
                  iVar31 = 1;
                  sprintf(pcVar35,"%d",uVar23);
                }
                else if (iVar31 == 4) {
                  uVar36 = json_real_value();
                  pcVar35 = acStack_4028;
                  iVar31 = 1;
                  sprintf(pcVar35,"%f",(int)uVar36,(int)((ulonglong)uVar36 >> 0x20));
                }
                else {
                  iVar31 = 1;
                  pcVar35 = (char *)0x0;
                }
              }
              goto LAB_0001a90c;
            }
            uVar23 = 0xe;
          }
        }
        iVar31 = 1;
        message(puVar4,uVar23,0,0,1);
        send_result_isra_6(puVar4[1],(int)puVar4 + 0xd,iVar7,1);
LAB_0001af08:
        if (bVar1) {
          send_result_isra_6(puVar4[1],(int)puVar4 + 0xd,iVar7,iVar31);
        }
LAB_0001a9dc:
        if (piStack_16478 == (int *)0x0) {
          iVar31 = 0;
        }
        if (((iVar31 != 0) && (*piStack_16478 == 0)) &&
           ((piStack_16478[1] != -1 &&
            (iVar31 = piStack_16478[1] + -1, piStack_16478[1] = iVar31, iVar31 == 0)))) {
          json_delete(piStack_16478);
        }
      }
    }
    close(iVar7);
  }
  if (pvStack_16420 != (void *)0x0) {
    free(pvStack_16420);
    pvStack_16420 = (void *)0x0;
  }
  __pthread_unregister_cancel(a_Stack_16140);
  tidyup(__ptr);
  free(__ptr);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    if (do_a_quit == '\0') {
      if (do_a_restart == '\0') {
        pcVar32 = "UNKNOWN!";
        if (bye != '\0') {
          pcVar32 = "BYE";
        }
      }
      else {
        pcVar32 = "RESTART";
      }
    }
    else {
      pcVar32 = "QUIT";
    }
    snprintf(acStack_d828,0x800,"API: terminating due to: %s",pcVar32);
    _applog(7,acStack_d828,0);
  }
  iVar7 = pthread_mutex_lock((pthread_mutex_t *)quit_restart_lock);
  if (iVar7 != 0) {
    _mutex_lock_part_3_constprop_27(&__func___11687,0x165b);
  }
  if (do_a_restart == '\0') {
    if (do_a_quit == '\0') goto LAB_0001b2ac;
    iVar7 = thr_info_create(auStack_163c4,0,0x16281);
    if (iVar7 != 0) {
      iVar7 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
      if (iVar7 != 0) {
        _mutex_unlock_noyield_part_5_constprop_32(&__func___11687,0x166a);
      }
      (*selective_yield)();
      builtin_strncpy(local_c828,"API failed to initiate a clean quit - aborti",0x2c);
      uStack_c7fc = 0x676e;
      local_c7fa = 0;
      _applog(3,local_c828,1);
      _quit(1);
    }
  }
  else {
    iVar7 = thr_info_create(auStack_163c4,0,0x16161);
    if (iVar7 != 0) {
      iVar7 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
      if (iVar7 != 0) {
        _mutex_unlock_noyield_part_5_constprop_32(&__func___11687,0x1661);
      }
      (*selective_yield)();
      builtin_strncpy(local_d028,"API failed to initiate a restart - aborting",0x2c);
      _applog(3,local_d028,1);
      _quit(1);
    }
  }
  pthread_detach(pStack_163b8);
LAB_0001b2ac:
  iVar7 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
  if (iVar7 != 0) {
    _mutex_unlock_noyield_part_5_constprop_32(&__func___11687,0x1670);
  }
  (*selective_yield)();
  return;
}

