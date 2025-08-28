
/* WARNING: Type propagation algorithm not settling */

undefined1 setup_stratum_socket(int param_1)

{
  addrinfo *paVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  ssize_t sVar7;
  int *piVar8;
  undefined4 uVar9;
  size_t sVar10;
  long lVar11;
  addrinfo **ppaVar12;
  uint uVar13;
  char *__s;
  char *local_a68;
  char *local_a64;
  addrinfo *local_a60;
  socklen_t local_a5c;
  int local_a58;
  timeval local_a54;
  addrinfo aStack_a4c;
  fd_set local_a2c [4];
  uint local_828;
  char acStack_824 [12];
  uint local_818;
  char acStack_814 [4];
  undefined4 local_810;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x2c0));
  if (iVar2 != 0) {
    piVar8 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar8,
             "util.c","setup_stratum_socket",0xb56);
    _applog(3,&local_828,1);
    _quit(1);
  }
  *(undefined1 *)(param_1 + 0x281) = 0;
  if (*(int *)(param_1 + 0x24c) != 0) {
    close(*(int *)(param_1 + 0x24c));
  }
  *(undefined4 *)(param_1 + 0x24c) = 0;
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x2c0));
  if (iVar2 != 0) {
    piVar8 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar8,
             "util.c","setup_stratum_socket",0xb5b);
    _applog(3,&local_828,1);
    _quit(1);
  }
  (*selective_yield)();
  memset(&aStack_a4c,0,0x20);
  iVar2 = opt_socks_proxy;
  aStack_a4c.ai_socktype = 1;
  if (*(int *)(param_1 + 0xb8) == 0) {
    if (opt_socks_proxy == 0) {
      local_a68 = *(char **)(param_1 + 600);
    }
    else {
      *(int *)(param_1 + 0xb8) = opt_socks_proxy;
      extract_sockaddr(iVar2,param_1 + 0x25c,param_1 + 0x260);
      *(undefined4 *)(param_1 + 0xb4) = 3;
      local_a68 = *(char **)(param_1 + 600);
      if (*(int *)(param_1 + 0xb8) != 0) goto LAB_000489ba;
    }
    local_a64 = *(char **)(param_1 + 0x248);
  }
  else {
LAB_000489ba:
    local_a68 = *(char **)(param_1 + 0x25c);
    local_a64 = *(char **)(param_1 + 0x260);
  }
  iVar2 = getaddrinfo(local_a68,local_a64,&aStack_a4c,&local_a60);
  paVar1 = local_a60;
  if (iVar2 != 0) {
    if (*(char *)(param_1 + 99) == '\0') {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf((char *)&local_828,0x800,"Failed to resolve (?wrong URL) %s:%s",local_a68,local_a64
                );
        _applog(4,&local_828,0);
      }
      *(undefined1 *)(param_1 + 99) = 1;
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 6)) {
      return 0;
    }
    snprintf((char *)&local_828,0x800,"Failed to getaddrinfo for %s:%s",local_a68,local_a64);
    _applog(6,&local_828,0);
    return 0;
  }
  do {
    if (paVar1 == (addrinfo *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
        snprintf((char *)&local_828,0x800,"Failed to connect to stratum on %s:%s",local_a68,
                 local_a64);
        _applog(6,&local_828,0);
      }
      freeaddrinfo(local_a60);
      return 0;
    }
    uVar3 = socket(paVar1->ai_family,paVar1->ai_socktype,paVar1->ai_protocol);
    if (uVar3 == 0xffffffff) {
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        puVar5 = &local_828;
        uVar3._0_1_ = 'F';
        uVar3._1_1_ = 'a';
        uVar3._2_1_ = 'i';
        uVar3._3_1_ = 'l';
        uVar4._0_1_ = 'e';
        uVar4._1_1_ = 'd';
        uVar4._2_1_ = ' ';
        uVar4._3_1_ = 's';
        uVar13._0_1_ = 'o';
        uVar13._1_1_ = 'c';
        uVar13._2_1_ = 'k';
        uVar13._3_1_ = 'e';
LAB_00048a94:
        *puVar5 = uVar3;
        puVar5[1] = uVar4;
        puVar5[2] = uVar13;
        *(undefined2 *)(puVar5 + 3) = 0x74;
        _applog(7,&local_828,0);
      }
      goto LAB_00048aa2;
    }
    uVar4 = fcntl(uVar3,3,0);
    fcntl(uVar3,4,uVar4 | 0x800);
    iVar2 = connect(uVar3,paVar1->ai_addr,paVar1->ai_addrlen);
    if (iVar2 != -1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        local_828._0_1_ = 'S';
        local_828._1_1_ = 'u';
        local_828._2_1_ = 'c';
        local_828._3_1_ = 'c';
        builtin_strncpy(acStack_824,"eeded immedi",0xc);
        local_818._0_1_ = 'a';
        local_818._1_1_ = 't';
        local_818._2_1_ = 'e';
        local_818._3_1_ = ' ';
        builtin_strncpy(acStack_814,"conn",4);
        local_810._0_1_ = 'e';
        local_810._1_1_ = 'c';
        local_810._2_1_ = 't';
        local_810._3_1_ = '\0';
        _applog(4,&local_828,0);
      }
LAB_00048d12:
      block_socket(uVar3);
      freeaddrinfo(local_a60);
      if (*(int *)(param_1 + 0xb8) == 0) goto LAB_00048e60;
      switch(*(undefined4 *)(param_1 + 0xb4)) {
      case 0:
        iVar2 = http_negotiate(param_1,uVar3,0);
        break;
      case 1:
        iVar2 = http_negotiate(param_1,uVar3,1);
        break;
      case 2:
        iVar2 = socks4_negotiate(param_1,uVar3,0);
        break;
      case 3:
      case 5:
        local_a2c[0].fds_bits[0] = CONCAT13(local_a2c[0].fds_bits[0]._3_1_,0x105);
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          snprintf((char *)&local_828,0x800,"Attempting to negotiate with %s:%s SOCKS5 proxy",
                   *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
          _applog(7,&local_828,0);
        }
        send(uVar3,local_a2c,3,0);
        sVar7 = recv(uVar3,&local_828,1,0);
        if ((((sVar7 != -1) && ((char)local_828 == '\x05')) &&
            (sVar7 = recv(uVar3,&local_828,1,0), sVar7 != -1)) &&
           (((uint)local_a2c[0].fds_bits[0] >> 0x10 & 0xff) == (local_828 & 0xff))) {
          __s = *(char **)(param_1 + 600);
          local_a2c[0].fds_bits[0] = 0x3000105;
          sVar10 = strlen(__s);
          if (0xfe < (int)sVar10) {
            sVar10 = 0xff;
          }
          local_a2c[0].fds_bits[1]._0_1_ = (undefined1)sVar10;
          _cg_memcpy((undefined1 *)((int)local_a2c[0].fds_bits + 5),__s,sVar10,"util.c",
                     "socks5_negotiate",0xac1);
          lVar11 = strtol(*(char **)(param_1 + 0x248),(char **)0x0,10);
          *(char *)((int)local_a2c[0].fds_bits + sVar10 + 6) = (char)lVar11;
          *(char *)((int)local_a2c[0].fds_bits + sVar10 + 5) = (char)((uint)lVar11 >> 8);
          send(uVar3,local_a2c,sVar10 + 7,0);
          sVar7 = recv(uVar3,&local_828,1,0);
          if (((sVar7 != -1) && ((char)local_828 == '\x05')) &&
             ((sVar7 = recv(uVar3,&local_828,1,0), sVar7 != -1 && ((local_828 & 0xff) == 0)))) {
            recv(uVar3,&local_828,1,0);
            sVar7 = recv(uVar3,&local_828,1,0);
            if (sVar7 != -1) {
              if ((local_828 & 0xff) == 1) {
                iVar2 = 4;
                do {
                  recv(uVar3,&local_828,1,0);
                  iVar2 = iVar2 + -1;
                } while (iVar2 != 0);
LAB_0004920a:
                recv(uVar3,&local_828,1,0);
                recv(uVar3,&local_828,1,0);
                if ((opt_debug != '\0') &&
                   (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                  snprintf((char *)&local_828,0x800,"Success negotiating with %s:%s SOCKS5 proxy",
                           *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
                  _applog(7,&local_828,0);
                }
LAB_00048e60:
                if (*(int *)(param_1 + 0x250) == 0) {
                  uVar9 = _cgcalloc(0x2000,1,"util.c","setup_stratum_socket",0xbe4);
                  *(undefined4 *)(param_1 + 0x250) = uVar9;
                  *(undefined4 *)(param_1 + 0x254) = 0x2000;
                }
                *(uint *)(param_1 + 0x24c) = uVar3;
                local_a2c[0].fds_bits[0] = 0x2d;
                local_828 = 0x1e;
                local_a54.tv_sec = 1;
                uVar4 = fcntl(uVar3,3,0);
                fcntl(uVar3,4,uVar4 | 0x800);
                setsockopt(uVar3,1,9,&local_a54,4);
                if (opt_delaynet == '\0') {
                  fcntl(uVar3,2,1);
                }
                setsockopt(uVar3,6,1,&local_a54,4);
                setsockopt(uVar3,6,6,&local_a54,4);
                setsockopt(uVar3,6,4,local_a2c,4);
                setsockopt(uVar3,6,5,&local_828,4);
                return 1;
              }
              if ((local_828 & 0xff) == 3) {
                sVar7 = recv(uVar3,&local_828,1,0);
                if ((sVar7 != -1) && (uVar4 = local_828 & 0xff, uVar4 != 0)) {
                  uVar13 = 0;
                  do {
                    uVar13 = uVar13 + 1;
                    recv(uVar3,&local_828,1,0);
                  } while (uVar4 != uVar13);
                }
                goto LAB_0004920a;
              }
            }
          }
        }
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
          return 0;
        }
        snprintf((char *)&local_828,0x800,"Bad response from %s:%s SOCKS5 server",
                 *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
        _applog(4,&local_828,0);
        return 0;
      case 4:
        iVar2 = socks4_negotiate(param_1,uVar3,1);
        break;
      default:
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
          return 0;
        }
        snprintf((char *)&local_828,0x800,"Unsupported proxy type for %s:%s",
                 *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));
        _applog(4,&local_828,0);
        return 0;
      }
      if (iVar2 == 0) {
        return 0;
      }
      goto LAB_00048e60;
    }
    local_a54.tv_sec = 1;
    local_a54.tv_usec = 0;
    puVar5 = (uint *)__errno_location();
    if (*puVar5 == 0x73) {
      uVar4 = uVar3 & 0x1f;
      uVar13 = uVar3 + 0x1f & (int)uVar3 >> 0x20;
      if (*puVar5 < 0x73) {
        uVar13 = uVar3;
      }
      iVar2 = (int)uVar13 >> 5;
      if ((int)uVar3 < 1) {
        uVar4 = -(-uVar3 & 0x1f);
      }
      uVar4 = 1 << (uVar4 & 0xff);
      while( true ) {
        ppaVar12 = &aStack_a4c.ai_next;
        do {
          ppaVar12 = ppaVar12 + 1;
          *ppaVar12 = (addrinfo *)0x0;
        } while ((addrinfo **)(local_a2c[0].fds_bits + 0x1f) != ppaVar12);
        local_a2c[0].fds_bits[iVar2] = local_a2c[0].fds_bits[iVar2] | uVar4;
        iVar6 = select(uVar3 + 1,(fd_set *)0x0,local_a2c,(fd_set *)0x0,&local_a54);
        if (0 < iVar6) break;
        if ((iVar6 == 0) || (*puVar5 != 4)) goto LAB_00048c50;
      }
      if ((uVar4 & local_a2c[0].fds_bits[iVar2]) != 0) {
        local_a5c = 4;
        iVar2 = getsockopt(uVar3,1,4,&local_a58,&local_a5c);
        if ((iVar2 == 0) && (local_a58 == 0)) {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            local_828._0_1_ = 'S';
            local_828._1_1_ = 'u';
            local_828._2_1_ = 'c';
            local_828._3_1_ = 'c';
            builtin_strncpy(acStack_824,"eeded delaye",0xc);
            local_818._0_1_ = 'd';
            local_818._1_1_ = ' ';
            local_818._2_1_ = 'c';
            local_818._3_1_ = 'o';
            builtin_strncpy(acStack_814,"nnec",4);
            local_810._0_2_ = 0x74;
            _applog(7,&local_828,0);
          }
          goto LAB_00048d12;
        }
      }
LAB_00048c50:
      close(uVar3);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        local_828._0_1_ = 'S';
        local_828._1_1_ = 'e';
        local_828._2_1_ = 'l';
        local_828._3_1_ = 'e';
        acStack_824[0] = 'c';
        acStack_824[1] = 't';
        acStack_824[2] = ' ';
        acStack_824[3] = 't';
        acStack_824[4] = 'i';
        acStack_824[5] = 'm';
        acStack_824[6] = 'e';
        acStack_824[7] = 'o';
        acStack_824[8] = 'u';
        acStack_824[9] = 't';
        acStack_824[10] = '/';
        acStack_824[0xb] = 'f';
        puVar5 = (uint *)(acStack_824 + 0xc);
        uVar3._0_1_ = 'a';
        uVar3._1_1_ = 'i';
        uVar3._2_1_ = 'l';
        uVar3._3_1_ = 'e';
        uVar4._0_1_ = 'd';
        uVar4._1_1_ = ' ';
        uVar4._2_1_ = 'c';
        uVar4._3_1_ = 'o';
        uVar13._0_1_ = 'n';
        uVar13._1_1_ = 'n';
        uVar13._2_1_ = 'e';
        uVar13._3_1_ = 'c';
        goto LAB_00048a94;
      }
LAB_00048aa2:
      paVar1 = paVar1->ai_next;
    }
    else {
      close(uVar3);
      if ((opt_debug == '\0') ||
         (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7))))
      goto LAB_00048aa2;
      local_828._0_1_ = 'F';
      local_828._1_1_ = 'a';
      local_828._2_1_ = 'i';
      local_828._3_1_ = 'l';
      builtin_strncpy(acStack_824,"ed sock conn",0xc);
      local_818._0_1_ = 'e';
      local_818._1_1_ = 'c';
      local_818._2_1_ = 't';
      local_818._3_1_ = '\0';
      _applog(7,&local_828,0);
      paVar1 = paVar1->ai_next;
    }
  } while( true );
}

