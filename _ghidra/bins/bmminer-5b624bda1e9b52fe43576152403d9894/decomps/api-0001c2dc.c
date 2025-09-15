
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

void api(int api_thr_id)

{
  bool bVar1;
  io_list *piVar2;
  undefined4 uVar3;
  _Bool _Var4;
  int *arg;
  io_data *io_data_00;
  char *pcVar5;
  io_list *piVar6;
  int iVar7;
  size_t sVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  ushort **ppuVar12;
  int iVar13;
  long lVar14;
  int iVar15;
  time_t tVar16;
  time_t tVar17;
  size_t sVar18;
  char *pcVar19;
  char *pcVar20;
  json_t *json;
  int *piVar21;
  char cVar22;
  __int32_t *p_Var23;
  byte *pbVar24;
  char *func;
  char *func_00;
  byte bVar25;
  bool bVar26;
  int __res;
  io_list *piVar27;
  int iVar28;
  int iVar29;
  int line;
  int line_00;
  int line_01;
  int line_02;
  json_type jVar30;
  CMDS *pCVar31;
  byte *__cp;
  addrinfo *paVar32;
  int iVar33;
  undefined1 *puVar34;
  IPACCESS *__buf;
  json_t *pjVar35;
  int unaff_r6;
  _Bool *p_Var36;
  json_t *pjVar37;
  char *unaff_r9;
  uint uVar38;
  char *pcVar39;
  double dVar40;
  json_int_t jVar41;
  io_data *io_data;
  byte *local_4bf8;
  __int32_t **local_4bec;
  char *local_4be8;
  char *local_4bd4;
  short port;
  byte local_4b9e;
  _Bool local_4b9d;
  char *local_4b9c;
  socklen_t local_4b98;
  addrinfo *local_4b94;
  undefined4 local_4b90;
  char port_s [10];
  addrinfo hints;
  thr_info bye_thr;
  char cmdbuf [100];
  sockaddr_storage cli;
  json_error_t json_err;
  __pthread_unwind_buf_t __cancel_buf;
  char cmdbuf_1 [100];
  char buf [8192];
  char param_buf [8192];
  
  iVar13 = opt_api_port;
  arg = (int *)malloc(4);
  _Var4 = opt_api_listen;
  *arg = -1;
  if (_Var4 == false) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(param_buf,0x800,"API not running%s"," - API will not be available");
      _applog(7,param_buf,false);
    }
    goto LAB_0001c364;
  }
  io_data_00 = (io_data *)malloc(0x10);
  pcVar5 = (char *)malloc(0x10000);
  *pcVar5 = '\0';
  io_data_00->ptr = pcVar5;
  io_data_00->cur = pcVar5;
  io_data_00->close = false;
  io_data_00->siz = 0x10000;
  io_data_00->sock = true;
  piVar6 = (io_list *)malloc(0xc);
  piVar6->io_data = io_data_00;
  piVar2 = io_head;
  if (io_head == (io_list *)0x0) {
    piVar6->prev = piVar6;
    piVar6->next = piVar6;
    io_head = piVar6;
  }
  else {
    piVar27 = io_head->prev;
    piVar6->next = io_head;
    piVar6->prev = piVar27;
    piVar2->prev = piVar6;
    piVar6->prev->next = piVar6;
  }
  iVar7 = pthread_mutex_init((pthread_mutex_t *)&quit_restart_lock,(pthread_mutexattr_t *)0x0);
  if (iVar7 != 0) {
    piVar21 = __errno_location();
    snprintf(param_buf,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar21,"api.c",
             "api",0x14c5);
    _applog(3,param_buf,true);
    _quit(1);
  }
  iVar7 = __sigsetjmp(&__cancel_buf,0);
  if (iVar7 == 0) {
    __pthread_register_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
    pcVar5 = opt_api_groups;
    my_thr_id = api_thr_id;
    if (opt_api_groups == (char *)0x0) {
      sVar8 = 1;
      pcVar5 = "";
    }
    else {
      sVar8 = strlen(opt_api_groups);
      sVar8 = sVar8 + 1;
    }
    pbVar9 = (byte *)malloc(sVar8);
    if (pbVar9 == (byte *)0x0) {
      builtin_strncpy(param_buf,"Failed to malloc ipgroups bu",0x1c);
      param_buf[0x1c] = 'f';
      param_buf[0x1d] = '\0';
      _applog(3,param_buf,true);
      _quit(1);
      strcpy((char *)0x0,pcVar5);
      local_4bec = __ctype_toupper_loc();
    }
    else {
      memcpy(pbVar9,pcVar5,sVar8);
      if (*pbVar9 == 0) {
        local_4bec = __ctype_toupper_loc();
      }
      else {
        local_4bec = __ctype_toupper_loc();
        pbVar24 = pbVar9;
        do {
          pbVar10 = (byte *)strchr((char *)pbVar24,0x2c);
          local_4bf8 = pbVar10;
          if (pbVar10 != (byte *)0x0) {
            local_4bf8 = pbVar10 + 1;
            *pbVar10 = 0;
          }
          if (pbVar24[1] != 0x3a) {
            pcVar5 = strchr((char *)pbVar24,0x3a);
            if (pcVar5 != (char *)0x0) {
              *pcVar5 = '\0';
            }
            snprintf(buf,0x800,"API invalid group name \'%s\'",pbVar24);
            _applog(3,buf,true);
            _quit(1);
          }
          p_Var23 = *local_4bec;
          uVar38 = (uint)*(byte *)(p_Var23 + *pbVar24);
          if ((p_Var23[uVar38] < p_Var23[0x41]) || (p_Var23[0x5a] < p_Var23[uVar38])) {
            snprintf(buf,0x800,"API invalid group name \'%c\'");
            _applog(3,buf,true);
            _quit(1);
            p_Var23 = *local_4bec;
          }
          if (uVar38 == p_Var23[0x57]) {
            snprintf(buf,0x800,"API group name can\'t be \'%c\'",uVar38);
            _applog(3,buf,true);
            _quit(1);
            p_Var23 = *local_4bec;
          }
          if (uVar38 == p_Var23[0x52]) {
            snprintf(buf,0x800,"API group name can\'t be \'%c\'",uVar38);
            _applog(3,buf,true);
            _quit(1);
            p_Var23 = *local_4bec;
          }
          if (apigroups[p_Var23[uVar38] - p_Var23[0x41]].commands != (char *)0x0) {
            snprintf(buf,0x800,"API duplicate group name \'%c\'",(uint)*pbVar24);
            _applog(3,buf,true);
            _quit(1);
          }
          bVar1 = false;
          param_buf[0] = '|';
          param_buf[1] = '\0';
          if ((pbVar24 + 2 != (byte *)0x0) && (pbVar24[2] != 0)) {
            local_4be8 = param_buf + 1;
            pbVar24 = pbVar24 + 2;
            do {
              pbVar11 = (byte *)strchr((char *)pbVar24,0x3a);
              pbVar10 = pbVar11;
              if (pbVar11 != (byte *)0x0) {
                pbVar10 = pbVar11 + 1;
                *pbVar11 = 0;
              }
              if ((*pbVar24 == 0x2a) && (pbVar24[1] == 0)) {
                bVar1 = true;
              }
              else {
                if (cmds[0].name != (char *)0x0) {
                  pCVar31 = cmds;
                  iVar7 = 0;
                  pcVar5 = cmds[0].name;
                  do {
                    iVar33 = strcasecmp((char *)pbVar24,pcVar5);
                    if (iVar33 == 0) {
                      sprintf(cmdbuf_1,"|%s|",pcVar5);
                      pcVar5 = strstr(param_buf,cmdbuf_1);
                      if (pcVar5 == (char *)0x0) {
                        pcVar5 = cmds[iVar7].name;
                        strcpy(local_4be8,pcVar5);
                        sVar8 = strlen(pcVar5);
                        local_4be8[sVar8] = '|';
                        local_4be8[sVar8 + 1] = '\0';
                        local_4be8 = local_4be8 + sVar8 + 1;
                      }
                      goto joined_r0x0001c61a;
                    }
                    pCVar31 = pCVar31 + 1;
                    pcVar5 = pCVar31->name;
                    iVar7 = iVar7 + 1;
                  } while (pcVar5 != (char *)0x0);
                }
                snprintf(buf,0x800,"API unknown command \'%s\' in group \'%c\'",pbVar24,uVar38);
                _applog(3,buf,true);
                _quit(1);
              }
joined_r0x0001c61a:
            } while ((pbVar10 != (byte *)0x0) && (pbVar24 = pbVar10, *pbVar10 != 0));
            if ((bVar1) && (cmds[0].name != (char *)0x0)) {
              p_Var36 = &cmds[0].iswritemode;
              do {
                while (*p_Var36 != false) {
LAB_0001c64c:
                  piVar21 = (int *)(p_Var36 + 4);
                  p_Var36 = p_Var36 + 0xc;
                  if (*piVar21 == 0) goto LAB_0001c69e;
                }
                sprintf(cmdbuf_1,"|%s|");
                pcVar5 = strstr(param_buf,cmdbuf_1);
                if (pcVar5 != (char *)0x0) goto LAB_0001c64c;
                pcVar5 = ((CMDS *)(p_Var36 + -8))->name;
                strcpy(local_4be8,pcVar5);
                sVar8 = strlen(pcVar5);
                local_4be8[sVar8] = '|';
                local_4be8[sVar8 + 1] = '\0';
                local_4be8 = local_4be8 + sVar8 + 1;
                piVar21 = (int *)(p_Var36 + 4);
                p_Var36 = p_Var36 + 0xc;
              } while (*piVar21 != 0);
            }
          }
LAB_0001c69e:
          iVar33 = (*local_4bec)[uVar38];
          iVar7 = (*local_4bec)[0x41];
          sVar8 = strlen(param_buf);
          pcVar5 = (char *)malloc(sVar8 + 1);
          apigroups[iVar33 - iVar7].commands = pcVar5;
          if (pcVar5 == (char *)0x0) {
            builtin_strncpy(buf,"Failed to malloc group commands buf",0x24);
            _applog(3,buf,true);
            _quit(1);
          }
          strcpy(pcVar5,param_buf);
        } while ((local_4bf8 != (byte *)0x0) && (pbVar24 = local_4bf8, *local_4bf8 != 0));
      }
    }
    param_buf._1_3_ = SUB43(param_buf._0_4_,1) & 0xffff00;
    param_buf[0] = '|';
    pCVar31 = cmds;
    pcVar5 = param_buf + 1;
    pcVar39 = cmds[0].name;
    while (pcVar39 != (char *)0x0) {
      while (pCVar31->iswritemode != false) {
        pCVar31 = pCVar31 + 1;
        pcVar39 = pCVar31->name;
        if (pcVar39 == (char *)0x0) goto LAB_0001c7f4;
      }
      strcpy(pcVar5,pcVar39);
      sVar8 = strlen(pcVar39);
      pcVar5[sVar8] = '|';
      pcVar5[sVar8 + 1] = '\0';
      pcVar5 = pcVar5 + sVar8 + 1;
      pCVar31 = pCVar31 + 1;
      pcVar39 = pCVar31->name;
    }
LAB_0001c7f4:
    p_Var23 = *local_4bec;
    iVar7 = p_Var23[0x52];
    if (iVar7 + 0x80U < 0x180) {
      iVar7 = p_Var23[iVar7];
    }
    iVar33 = p_Var23[0x41];
    sVar8 = strlen(param_buf);
    pcVar5 = (char *)malloc(sVar8 + 1);
    apigroups[iVar7 - iVar33].commands = pcVar5;
    if (pcVar5 == (char *)0x0) {
      builtin_strncpy(buf,"Failed to malloc noprivgroup commands bu",0x28);
      buf[0x28] = 'f';
      buf[0x29] = '\0';
      _applog(3,buf,true);
      _quit(1);
    }
    strcpy(pcVar5,param_buf);
    free(pbVar9);
    pcVar5 = opt_api_allow;
    if (opt_api_allow != (char *)0x0) {
      sVar8 = strlen(opt_api_allow);
      pbVar9 = (byte *)malloc(sVar8 + 1);
      if (pbVar9 == (byte *)0x0) {
        builtin_strncpy(param_buf,"Failed to malloc ipaccess bu",0x1c);
        param_buf[0x1c] = 'f';
        param_buf[0x1d] = '\0';
        _applog(3,param_buf,true);
        _quit(1);
        pcVar5 = opt_api_allow;
      }
      strcpy((char *)pbVar9,pcVar5);
      pbVar24 = pbVar9 + -1;
      sVar8 = 1;
      while( true ) {
        pbVar24 = pbVar24 + 1;
        if (*pbVar24 == 0) break;
        if (*pbVar24 == 0x2c) {
          sVar8 = sVar8 + 1;
        }
      }
      ipaccess = (IPACCESS *)calloc(sVar8,0x24);
      uVar3 = param_buf._24_4_;
      if (ipaccess == (IPACCESS *)0x0) {
        builtin_strncpy(param_buf,"Failed to calloc ipaccess",0x1a);
        param_buf._26_2_ = SUB42(uVar3,2);
        _applog(3,param_buf,true);
        _quit(1);
      }
      iVar7 = 0;
      ips = 0;
      if ((pbVar9 == (byte *)0x0) || (bVar25 = *pbVar9, pbVar24 = pbVar9, bVar25 == 0)) {
        free(pbVar9);
      }
      else {
        do {
          if (bVar25 == 0x20 || bVar25 == 9) {
            do {
              pbVar24 = pbVar24 + 1;
              bVar25 = *pbVar24;
            } while (bVar25 == 0x20 || bVar25 == 9);
          }
          if (bVar25 == 0x2c) {
            pbVar10 = pbVar24 + 1;
          }
          else {
            pbVar11 = (byte *)strchr((char *)pbVar24,0x2c);
            pbVar10 = pbVar11;
            if (pbVar11 != (byte *)0x0) {
              pbVar10 = pbVar11 + 1;
              *pbVar11 = 0;
            }
            ppuVar12 = __ctype_b_loc();
            p_Var23 = *local_4bec;
            cVar22 = (char)p_Var23[0x52];
            if (((int)((uint)(*ppuVar12)[*pbVar24] << 0x15) < 0) && (pbVar24[1] == 0x3a)) {
              iVar33 = p_Var23[*pbVar24];
              if ((iVar33 == p_Var23[0x57]) ||
                 (apigroups[iVar33 - p_Var23[0x41]].commands != (char *)0x0)) {
                cVar22 = (char)iVar33;
              }
              pbVar24 = pbVar24 + 2;
            }
            __buf = ipaccess + iVar7;
            __buf->group = cVar22;
            bVar25 = *pbVar24;
            if ((((bVar25 == 0x30) && (pbVar24[1] == 0x2f)) && (pbVar24[2] == 0x30)) &&
               (pbVar24[3] == 0)) {
              iVar33 = 0;
              puVar34 = &__buf[-1].field_0x23;
              do {
                iVar33 = iVar33 + 1;
                puVar34[1] = 0;
                puVar34[0x11] = 0;
                puVar34 = puVar34 + 1;
              } while (iVar33 != 0x10);
              iVar7 = iVar7 + 1;
              ips = iVar7;
            }
            else {
              pbVar11 = (byte *)strchr((char *)pbVar24,0x2f);
              if (pbVar11 == (byte *)0x0) {
                iVar33 = 0;
                do {
                  iVar29 = iVar33 + 1;
                  (__buf->mask).__in6_u.__u6_addr8[iVar33] = 0xff;
                  iVar33 = iVar29;
                } while (iVar29 != 0x10);
                sVar8 = strlen((char *)pbVar24);
                bVar25 = *pbVar24;
                pbVar11 = pbVar24 + sVar8;
              }
              if ((bVar25 == 0x5b) && (pbVar11[-1] == 0x5d)) {
                bVar1 = true;
                __cp = pbVar24 + 1;
                *pbVar24 = 0;
                pbVar11[-1] = 0;
              }
              else {
                bVar1 = false;
                __cp = pbVar24;
              }
              if (*pbVar11 == 0) {
LAB_0001ca6e:
                iVar33 = 0;
                do {
                  (__buf->ip).__in6_u.__u6_addr8[iVar33] = '\0';
                  iVar33 = iVar33 + 1;
                } while (iVar33 != 0x10);
                if (bVar1) {
                  iVar33 = inet_pton(10,(char *)__cp,__buf);
                }
                else {
                  sprintf(param_buf,"::ffff:%s",__cp);
                  iVar7 = ips;
                  __buf = ipaccess + ips;
                  iVar33 = inet_pton(10,param_buf,__buf);
                }
                if (iVar33 == 1) {
                  iVar33 = 0;
                  do {
                    iVar33 = iVar33 + 1;
                    (__buf->ip).__in6_u.__u6_addr8[0] =
                         (__buf->ip).__in6_u.__u6_addr8[0] & (__buf->mask).__in6_u.__u6_addr8[0];
                    __buf = (IPACCESS *)((__buf->ip).__in6_u.__u6_addr8 + 1);
                  } while (iVar33 != 0x10);
                  iVar7 = iVar7 + 1;
                  ips = iVar7;
                }
              }
              else {
                *pbVar11 = 0;
                lVar14 = strtol((char *)(pbVar11 + 1),(char **)0x0,10);
                if (0 < lVar14) {
                  if (bVar1) {
                    iVar33 = 0;
                  }
                  else {
                    iVar33 = 0x60;
                  }
                  iVar33 = lVar14 + iVar33;
                  if (iVar33 < 0x81) {
                    iVar15 = 0;
                    iVar29 = 0;
                    do {
                      iVar28 = iVar29 + 1;
                      (__buf->mask).__in6_u.__u6_addr8[iVar29] = '\0';
                      iVar29 = iVar28;
                    } while (iVar28 != 0x10);
                    uVar38 = 7;
                    for (; 0 < iVar33; iVar33 = iVar33 + -1) {
                      (__buf->mask).__in6_u.__u6_addr8[iVar15] =
                           (byte)(1 << (uVar38 & 0xff)) | (__buf->mask).__in6_u.__u6_addr8[iVar15];
                      if (uVar38 == 0) {
                        iVar15 = iVar15 + 1;
                        uVar38 = 7;
                      }
                      else {
                        uVar38 = uVar38 - 1;
                      }
                    }
                    goto LAB_0001ca6e;
                  }
                }
              }
            }
          }
        } while ((pbVar10 != (byte *)0x0) && (bVar25 = *pbVar10, pbVar24 = pbVar10, bVar25 != 0));
        free(pbVar9);
        if (iVar7 != 0) goto LAB_0001c98a;
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(param_buf,0x800,"API not running (no valid IPs specified)%s",
                 " - API will not be available");
        _applog(4,param_buf,false);
      }
      goto LAB_0001c364;
    }
LAB_0001c98a:
    unaff_r6 = (int)(short)iVar13;
    cgsleep_ms(opt_log_interval * 1000);
    sprintf(port_s,"%d",unaff_r6);
    hints.ai_flags = 1;
    hints.ai_family = 0;
    hints.ai_socktype = 0;
    hints.ai_protocol = 0;
    hints.ai_addrlen = 0;
    hints.ai_addr = (sockaddr *)0x0;
    hints.ai_canonname = (char *)0x0;
    hints.ai_next = (addrinfo *)0x0;
    iVar13 = getaddrinfo(opt_api_host,port_s,(addrinfo *)&hints,&local_4b94);
    if (iVar13 == 0) {
      paVar32 = local_4b94;
      if (local_4b94 == (addrinfo *)0x0) {
        iVar13 = *arg;
      }
      else {
        do {
          iVar13 = socket(local_4b94->ai_family,1,0);
          *arg = iVar13;
          if (0 < iVar13) goto LAB_0001cc48;
          paVar32 = paVar32->ai_next;
        } while (paVar32 != (addrinfo *)0x0);
      }
      if (iVar13 == -1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          piVar21 = __errno_location();
          pcVar5 = strerror(*piVar21);
          snprintf(param_buf,0x800,"API initialisation failed (%s)%s",pcVar5,
                   " - API will not be available");
          _applog(3,param_buf,false);
        }
        freeaddrinfo(local_4b94);
        free(arg);
        return;
      }
      paVar32 = (addrinfo *)0x0;
LAB_0001cc48:
      local_4b90 = 1;
      iVar13 = setsockopt(iVar13,1,2,&local_4b90,4);
      if (((iVar13 < 0) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        piVar21 = __errno_location();
        pcVar5 = strerror(*piVar21);
        snprintf(param_buf,0x800,"API setsockopt SO_REUSEADDR failed (ignored): %s",pcVar5);
        _applog(7,param_buf,false);
      }
      tVar16 = time((time_t *)0x0);
      while (iVar13 = bind(*arg,paVar32->ai_addr,paVar32->ai_addrlen), iVar13 < 0) {
        piVar21 = __errno_location();
        unaff_r9 = strerror(*piVar21);
        tVar17 = time((time_t *)0x0);
        if (0x3d < tVar17 - tVar16) goto LAB_0001d50c;
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(param_buf,0x800,"API bind to port %d failed - trying again in 30sec",unaff_r6);
          _applog(4,param_buf,false);
        }
        cgsleep_ms(30000);
      }
      freeaddrinfo(local_4b94);
      iVar13 = listen(*arg,100);
      if (iVar13 < 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          piVar21 = __errno_location();
          pcVar5 = strerror(*piVar21);
          snprintf(param_buf,0x800,"API3 initialisation failed (%s)%s",pcVar5,
                   " - API will not be available");
          _applog(3,param_buf,false);
        }
        close(*arg);
        goto LAB_0001c364;
      }
      if (opt_api_allow == (char *)0x0) {
        if (opt_api_network == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            iVar13 = *arg;
            pcVar5 = "API running in local read access mode on port %d (%d)";
            goto LAB_0001ccf2;
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          pcVar5 = "API running in UNRESTRICTED read access mode on port %d (%d)";
          iVar13 = *arg;
LAB_0001ccf2:
          snprintf(param_buf,0x800,pcVar5,unaff_r6,iVar13);
          _applog(4,param_buf,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        pcVar5 = "API running in IP access mode on port %d (%d)";
        iVar13 = *arg;
        goto LAB_0001ccf2;
      }
      if (opt_api_mcast != false) {
        mcast_init();
      }
      strbufs = _k_new_list("StrBufs",0xc,2,0,false,"api.c","api",0x1535);
      if (bye == false) {
        bVar1 = false;
        json = (json_t *)0x0;
        do {
          local_4b98 = 0x80;
          iVar13 = accept(*arg,(sockaddr *)&cli,&local_4b98);
          if (iVar13 < 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              piVar21 = __errno_location();
              pcVar5 = strerror(*piVar21);
              snprintf(cmdbuf_1,0x800,"API failed (%s)%s (%d)",pcVar5," - API will not be available"
                       ,*arg);
              _applog(3,cmdbuf_1,false);
            }
            break;
          }
          _Var4 = check_connect(&cli,&local_4b9c,(char *)&local_4b9e);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            pcVar5 = "Accepted";
            if (!_Var4) {
              pcVar5 = "Ignored";
            }
            snprintf(cmdbuf_1,0x800,"API: connection from %s - %s",local_4b9c,pcVar5);
            _applog(7,cmdbuf_1,false);
          }
          if (_Var4) {
            sVar18 = recv(iVar13,buf,0x1fff,0);
            if ((int)sVar18 < 0) {
              buf._0_4_ = buf._0_4_ & 0xffffff00;
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                piVar21 = __errno_location();
                pcVar5 = strerror(*piVar21);
                snprintf(cmdbuf_1,0x800,"API: recv failed: %s",pcVar5);
                _applog(7,cmdbuf_1,false);
              }
            }
            else {
              buf[sVar18] = '\0';
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(cmdbuf_1,0x800,"API: recv command: (%d) \'%s\'",sVar18,buf);
                _applog(7,cmdbuf_1,false);
              }
              pjVar35 = (json_t *)0x0;
              when = time((time_t *)0x0);
              io_data_00->cur = io_data_00->ptr;
              *io_data_00->ptr = '\0';
              io_data_00->close = false;
              if (buf[0] != '{') {
                pcVar5 = strchr(buf,0x7c);
                if (pcVar5 == (char *)0x0) {
                  pcVar39 = buf;
                  pjVar35 = (json_t *)0x0;
                  pjVar37 = (json_t *)0x0;
                }
                else {
                  pcVar39 = buf;
                  pjVar37 = (json_t *)(pcVar5 + 1);
                  *pcVar5 = '\0';
                }
                goto LAB_0001d0dc;
              }
              json = json_loadb(buf,sVar18,0,&json_err);
              if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
                iVar7 = 0x17;
LAB_0001d43a:
                message(io_data_00,iVar7,0,(char *)0x0,true);
                pjVar35 = (json_t *)0x1;
                send_result(io_data_00,iVar13,true);
                pjVar37 = json;
                if (json != (json_t *)0x0) {
                  pjVar37 = (json_t *)0x1;
                }
                if (bVar1) {
LAB_0001d2a2:
                  send_result(io_data_00,iVar13,SUB41(pjVar35,0));
                }
              }
              else {
                pjVar35 = json_object_get(json,"command");
                if (pjVar35 == (json_t *)0x0) {
                  iVar7 = 0x18;
                  goto LAB_0001d43a;
                }
                if (pjVar35->type != JSON_STRING) {
                  iVar7 = 0xe;
                  goto LAB_0001d43a;
                }
                pcVar39 = json_string_value(pjVar35);
                pjVar37 = json_object_get(json,"parameter");
                if (pjVar37 == (json_t *)0x0) {
LAB_0001d856:
                  pjVar35 = (json_t *)0x1;
                }
                else {
                  jVar30 = pjVar37->type;
                  if (jVar30 == JSON_STRING) {
                    pjVar37 = (json_t *)json_string_value(pjVar37);
                    pjVar35 = (json_t *)0x1;
                  }
                  else if (jVar30 == JSON_INTEGER) {
                    jVar41 = json_integer_value(pjVar37);
                    pjVar37 = (json_t *)param_buf;
                    pjVar35 = (json_t *)0x1;
                    sprintf((char *)pjVar37,"%d",(int)jVar41);
                  }
                  else {
                    if (jVar30 != JSON_REAL) {
                      pjVar37 = (json_t *)0x0;
                      goto LAB_0001d856;
                    }
                    dVar40 = json_real_value(pjVar37);
                    pjVar37 = (json_t *)param_buf;
                    pjVar35 = (json_t *)0x1;
                    sprintf((char *)pjVar37,"%f",SUB84(dVar40,0),(int)((ulonglong)dVar40 >> 0x20));
                  }
                }
LAB_0001d0dc:
                pcVar5 = strchr(pcVar39,0x2b);
                if (pcVar5 == (char *)0x0) {
                  local_4b9d = false;
                  bVar1 = false;
                  local_4bd4 = (char *)0x0;
                }
                else {
                  local_4b9d = true;
                  sVar8 = strlen(pcVar39);
                  local_4bd4 = (char *)malloc(sVar8 + 3);
                  if (local_4bd4 == (char *)0x0) {
                    snprintf(cmdbuf_1,0x800,"OOM cmdsbuf in %s %s():%d","api.c","api",0x15a4);
                    _applog(3,cmdbuf_1,true);
                    _quit(1);
                  }
                  bVar1 = true;
                  pjVar37 = (json_t *)0x0;
                  local_4bd4[0] = '|';
                  local_4bd4[1] = '\0';
                }
                pcVar5 = pcVar39;
                do {
                  if (bVar1) {
                    pcVar19 = strchr(pcVar5,0x2b);
                    pcVar39 = pcVar19;
                    if (pcVar19 != (char *)0x0) {
                      pcVar39 = pcVar19 + 1;
                      *pcVar19 = '\0';
                    }
                    pcVar19 = pcVar39;
                    if (*pcVar5 != '\0') goto LAB_0001d180;
                  }
                  else {
LAB_0001d180:
                    _Var4 = SUB41(pjVar35,0);
                    pcVar19 = pcVar39;
                    if (cmds[0].name != (char *)0x0) {
                      pCVar31 = cmds;
                      iVar7 = 0;
                      pcVar20 = cmds[0].name;
                      do {
                        iVar33 = strcmp(pcVar5,pcVar20);
                        if (iVar33 == 0) {
                          sprintf(cmdbuf,"|%s|",pcVar5);
                          if (bVar1) {
                            pcVar20 = strstr(local_4bd4,cmdbuf);
                            if (pcVar20 != (char *)0x0) goto LAB_0001d1c8;
                            sVar8 = strlen(local_4bd4);
                            pcVar20 = stpcpy(local_4bd4 + sVar8,pcVar5);
                            pcVar20[0] = '|';
                            pcVar20[1] = '\0';
                            head_join(io_data_00,pcVar5,_Var4,&local_4b9d);
                            if (cmds[iVar7].joinable == false) {
                              message(io_data_00,0x2d,0,cmds[iVar7].name,_Var4);
                              tail_join(io_data_00,_Var4);
                              goto LAB_0001d1c8;
                            }
                          }
                          bVar25 = local_4b9e;
                          p_Var23 = *local_4bec;
                          if ((p_Var23[local_4b9e] == p_Var23[0x57]) ||
                             (pcVar20 = strstr(apigroups[p_Var23[local_4b9e] - p_Var23[0x41]].
                                               commands,cmdbuf), pcVar20 != (char *)0x0)) {
                            (*cmds[iVar7].func)(io_data_00,iVar13,(char *)pjVar37,_Var4,bVar25);
                          }
                          else {
                            message(io_data_00,0x2d,0,cmds[iVar7].name,_Var4);
                            if ((opt_debug != false) &&
                               (((use_syslog != false || (opt_log_output != false)) ||
                                (6 < opt_log_level)))) {
                              snprintf(cmdbuf_1,0x800,
                                       "API: access denied to \'%s\' for \'%s\' command",local_4b9c,
                                       cmds[iVar7].name);
                              _applog(7,cmdbuf_1,false);
                            }
                          }
                          if (!bVar1) goto LAB_0001d228;
                          goto LAB_0001d28c;
                        }
                        pCVar31 = pCVar31 + 1;
                        pcVar20 = pCVar31->name;
                        iVar7 = iVar7 + 1;
                      } while (pcVar20 != (char *)0x0);
                    }
                    if (bVar1) {
                      head_join(io_data_00,pcVar5,_Var4,&local_4b9d);
                      message(io_data_00,0xe,0,(char *)0x0,_Var4);
LAB_0001d28c:
                      tail_join(io_data_00,_Var4);
                    }
                    else {
                      message(io_data_00,0xe,0,(char *)0x0,_Var4);
LAB_0001d228:
                      send_result(io_data_00,iVar13,_Var4);
                      pcVar19 = pcVar5;
                    }
                  }
LAB_0001d1c8:
                  bVar26 = bVar1;
                  if (pcVar19 == (char *)0x0) {
                    bVar26 = false;
                  }
                  pcVar5 = pcVar19;
                } while (bVar26);
                pjVar37 = pjVar35;
                if (bVar1) goto LAB_0001d2a2;
              }
              if (((pjVar37 != (json_t *)0x0) && (json->type == JSON_OBJECT)) &&
                 ((json->refcount != 0xffffffff &&
                  (sVar18 = json->refcount - 1, json->refcount = sVar18, sVar18 == 0)))) {
                json_delete(json);
              }
            }
          }
          close(iVar13);
        } while (bye == false);
      }
      __pthread_unregister_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
      tidyup(arg);
      free(arg);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        if (do_a_quit == false) {
          if (do_a_restart == false) {
            if (bye == false) {
              pcVar5 = "UNKNOWN!";
            }
            else {
              pcVar5 = "BYE";
            }
          }
          else {
            pcVar5 = "RESTART";
          }
        }
        else {
          pcVar5 = "QUIT";
        }
        snprintf(cmdbuf_1,0x800,"API: terminating due to: %s",pcVar5);
        _applog(7,cmdbuf_1,false);
      }
      iVar13 = pthread_mutex_lock((pthread_mutex_t *)&quit_restart_lock);
      if (iVar13 != 0) {
        _mutex_lock((pthread_mutex_t *)"api",(char *)0x1607,func,line);
      }
      if (do_a_restart == false) {
        if (do_a_quit == false) goto LAB_0001ceaa;
        iVar13 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x194dd,
                                 &bye_thr);
        if (iVar13 != 0) {
          _mutex_unlock(&quit_restart_lock,"api",(char *)0x1616,line_01);
          builtin_strncpy(cmdbuf_1,"API failed to initiate a clean quit - aborti",0x2c);
          cmdbuf_1[0x2c] = 'n';
          cmdbuf_1[0x2d] = 'g';
          cmdbuf_1[0x2e] = '\0';
          _applog(3,cmdbuf_1,true);
          _quit(1);
        }
      }
      else {
        iVar13 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,(_func_void_ptr_void_ptr *)0x19441,
                                 &bye_thr);
        if (iVar13 != 0) {
          _mutex_unlock(&quit_restart_lock,"api",(char *)0x160d,line_02);
          builtin_strncpy(cmdbuf_1,"API failed to initiate a restart - aborting",0x2c);
          _applog(3,cmdbuf_1,true);
          _quit(1);
        }
      }
      pthread_detach(bye_thr.pth);
LAB_0001ceaa:
      iVar13 = pthread_mutex_unlock((pthread_mutex_t *)&quit_restart_lock);
      if (iVar13 != 0) {
        _mutex_unlock_noyield((pthread_mutex_t *)"api",(char *)0x161c,func_00,line_00);
      }
      (*selective_yield)();
      return;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_0001c364;
    snprintf(param_buf,0x800,"API failed to resolve %s",opt_api_host);
  }
  else {
    tidyup(arg);
    __pthread_unwind_next((__pthread_unwind_buf_t *)&__cancel_buf);
LAB_0001d50c:
    freeaddrinfo(local_4b94);
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_0001c364;
    snprintf(param_buf,0x800,"API bind to port %d failed (%s)%s",unaff_r6,unaff_r9,
             " - API will not be available");
  }
  _applog(3,param_buf,false);
LAB_0001c364:
  free(arg);
  return;
}

