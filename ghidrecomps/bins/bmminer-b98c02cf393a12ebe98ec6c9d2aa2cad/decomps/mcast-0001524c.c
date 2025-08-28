
void mcast(void)

{
  int iVar1;
  time_t tVar2;
  size_t sVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  time_t tVar8;
  ssize_t sVar9;
  int *piVar10;
  uint uVar11;
  sockaddr *psVar12;
  uint __n;
  addrinfo *paVar13;
  char *pcVar14;
  char *__buf;
  int local_1138;
  int local_1120;
  addrinfo *local_111c;
  char *local_1118;
  undefined1 uStack_10fd;
  socklen_t local_10fc;
  char *local_10f8;
  addrinfo *local_10f4;
  undefined4 local_10f0;
  char local_10ec [12];
  char acStack_10e0 [12];
  char acStack_10d4 [12];
  addrinfo aStack_10c8;
  sockaddr asStack_10a8 [7];
  char acStack_1029 [10];
  char acStack_101f [1015];
  undefined4 local_c28;
  undefined4 local_c24;
  undefined4 uStack_c20;
  undefined4 uStack_c1c;
  undefined4 local_c18;
  char local_828 [28];
  undefined4 local_80c;
  undefined2 uStack_808;
  undefined1 local_806;
  
  local_10f8 = (char *)0x0;
  builtin_strncpy(local_10ec,"bmminer-",8);
  local_10ec[8] = 0;
  sprintf(acStack_10e0,"%d",opt_api_mcast_port);
  memset(&aStack_10c8,0,0x20);
  iVar1 = getaddrinfo(opt_api_mcast_addr,acStack_10e0,&aStack_10c8,&local_10f4);
  if (iVar1 == 0) {
    paVar13 = local_10f4;
    if (local_10f4 == (addrinfo *)0x0) goto LAB_00015586;
LAB_000152be:
    do {
      local_1138 = socket(local_10f4->ai_family,2,0);
      if (0 < local_1138) goto LAB_000152ce;
      paVar13 = paVar13->ai_next;
    } while (paVar13 != (addrinfo *)0x0);
    if (local_1138 == -1) goto LAB_00015586;
  }
  else {
    builtin_strncpy(local_828,"Invalid API Multicast Addres",0x1c);
    local_80c._0_2_ = 0x73;
    _applog(3,local_828,1);
    _quit(1);
    paVar13 = local_10f4;
    if (local_10f4 != (addrinfo *)0x0) goto LAB_000152be;
LAB_00015586:
    freeaddrinfo(local_10f4);
    local_1138 = -1;
    paVar13 = (addrinfo *)0x0;
    builtin_strncpy(local_828,"API mcast could not open soc",0x1c);
    local_80c._0_1_ = 'k';
    local_80c._1_1_ = 'e';
    local_80c._2_1_ = 't';
    local_80c._3_1_ = '\0';
    _applog(3,local_828,1);
    _quit(1);
  }
LAB_000152ce:
  local_10f0 = 1;
  iVar1 = setsockopt(local_1138,1,2,&local_10f0,4);
  if (iVar1 < 0) {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
    goto LAB_0001560c;
    piVar10 = __errno_location();
    pcVar14 = strerror(*piVar10);
    pcVar4 = "API mcast setsockopt SO_REUSEADDR failed (%s)%s";
  }
  else {
    tVar2 = time((time_t *)0x0);
    while (iVar1 = bind(local_1138,paVar13->ai_addr,paVar13->ai_addrlen), iVar1 < 0) {
      piVar10 = __errno_location();
      pcVar14 = strerror(*piVar10);
      tVar8 = time((time_t *)0x0);
      if (0x3d < tVar8 - tVar2) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          snprintf(local_828,0x800,"API mcast bind to port %d failed (%s)%s",opt_api_mcast_port,
                   pcVar14," - API multicast listener will not be available");
          _applog(3,local_828,0);
        }
        goto LAB_0001560c;
      }
      cgsleep_ms(30000);
    }
    if (paVar13->ai_family == 2) {
      local_c24 = 0;
      local_c28 = *(undefined4 *)(paVar13->ai_addr->sa_data + 2);
      iVar1 = setsockopt(local_1138,0,0x23,&local_c28,8);
    }
    else {
      if (paVar13->ai_family != 10) goto LAB_0001534a;
      psVar12 = paVar13->ai_addr;
      local_c28 = *(undefined4 *)(psVar12->sa_data + 6);
      local_c24 = *(undefined4 *)(psVar12->sa_data + 10);
      uStack_c20._0_2_ = psVar12[1].sa_family;
      uStack_c20._2_1_ = psVar12[1].sa_data[0];
      uStack_c20._3_1_ = psVar12[1].sa_data[1];
      uStack_c1c = *(undefined4 *)(psVar12[1].sa_data + 2);
      local_c18 = 0;
      iVar1 = setsockopt(local_1138,0x29,0x14,&local_c28,0x14);
    }
    if (-1 < iVar1) {
LAB_0001534a:
      local_1118 = (char *)&local_c28;
      freeaddrinfo(local_10f4);
      pcVar14 = opt_api_mcast_code;
      sVar3 = strlen(opt_api_mcast_code);
      __n = sVar3 + 9;
      pcVar4 = (char *)malloc(sVar3 + 10);
      if (pcVar4 == (char *)0x0) {
        builtin_strncpy(local_828,"Failed to malloc mcast expec",0x1c);
        local_80c._0_1_ = 't';
        local_80c._1_1_ = '_';
        local_80c._2_1_ = 'c';
        local_80c._3_1_ = 'o';
        uStack_808 = 0x6564;
        local_806 = 0;
        _applog(3,local_828,1);
        _quit(1);
        pcVar14 = opt_api_mcast_code;
      }
      local_1120 = -1;
      iVar1 = 0;
      __buf = acStack_1029 + 1;
      snprintf(pcVar4,sVar3 + 10,"%s%s-",local_10ec,pcVar14);
LAB_0001540e:
      do {
        do {
          while( true ) {
            cgsleep_ms(1000);
            local_10fc = 0x80;
            iVar1 = iVar1 + 1;
            uVar5 = recvfrom(local_1138,__buf,0x3ff,0,asStack_10a8,&local_10fc);
            if (-1 < (int)uVar5) break;
            if ((opt_debug != '\0') &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              piVar10 = __errno_location();
              pcVar14 = strerror(*piVar10);
              snprintf(local_828,0x800,"API mcast failed count=%d (%s) (%d)",iVar1,pcVar14,
                       local_1138);
              _applog(7,local_828,0);
            }
          }
          if (local_10f8 != (char *)0x0) {
            free(local_10f8);
            local_10f8 = (char *)0x0;
          }
          iVar6 = check_connect(asStack_10a8,&local_10f8,&uStack_10fd);
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            pcVar14 = "Ignored";
            if (iVar6 != 0) {
              pcVar14 = "Accepted";
            }
            snprintf(local_828,0x800,"API mcast from %s - %s",local_10f8,pcVar14);
            _applog(7,local_828,0);
          }
        } while (iVar6 == 0);
        __buf[uVar5] = '\0';
        if (uVar5 == 0) goto LAB_00015688;
        uVar11 = uVar5 - 1;
        if (__buf[uVar11] == '\n') {
          __buf[uVar11] = '\0';
          uVar5 = uVar11;
        }
        getnameinfo(asStack_10a8,local_10fc,(char *)0x0,0,acStack_10d4,10,1);
        if (opt_debug != '\0') goto LAB_000156aa;
      } while ((uVar5 <= __n) || (iVar6 = memcmp(__buf,pcVar4,__n), iVar6 != 0));
      goto LAB_000154fa;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
    goto LAB_0001560c;
    piVar10 = __errno_location();
    pcVar14 = strerror(*piVar10);
    pcVar4 = "API mcast join failed (%s)%s";
  }
  snprintf(local_828,0x800,pcVar4,pcVar14," - API multicast listener will not be available");
  _applog(3,local_828,0);
LAB_0001560c:
  if (local_10f8 != (char *)0x0) {
    free(local_10f8);
    local_10f8 = (char *)0x0;
  }
  close(local_1138);
  return;
LAB_00015688:
  getnameinfo(asStack_10a8,local_10fc,(char *)0x0,0,acStack_10d4,10,1);
  if (opt_debug != '\0') {
LAB_000156aa:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (6 < opt_log_level)) {
      snprintf(local_828,0x800,"API mcast request rep=%d (%s) from [%s]:%s",uVar5,__buf,local_10f8,
               acStack_10d4);
      _applog(7,local_828,0);
    }
    if ((__n < uVar5) && (iVar6 = memcmp(__buf,pcVar4,__n), iVar6 == 0)) {
LAB_000154fa:
      pcVar14 = __buf + __n;
      lVar7 = strtol(pcVar14,(char **)0x0,10);
      if (lVar7 - 1U < 0xffff) {
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          snprintf(local_828,0x800,"API mcast request OK port %s=%d",pcVar14,lVar7);
          _applog(7,local_828,0);
        }
        iVar6 = getaddrinfo(local_10f8,pcVar14,&aStack_10c8,&local_10f4);
        if (iVar6 == 0) {
          local_111c = local_10f4;
          if (local_10f4 == (addrinfo *)0x0) {
          }
          else {
            do {
              local_1120 = socket(local_10f4->ai_family,2,0);
              if (0 < local_1138) break;
              local_111c = local_111c->ai_next;
            } while (local_111c != (addrinfo *)0x0);
          }
          if (local_1120 != -1) {
            snprintf(local_1118,0x400,"cgm-FTW-%d-%s",opt_api_port,opt_api_mcast_des);
            sVar3 = strlen(local_1118);
            sVar9 = sendto(local_1120,local_1118,sVar3 + 1,0,local_111c->ai_addr,
                           local_111c->ai_addrlen);
            freeaddrinfo(local_10f4);
            if (sVar9 < 0) {
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                piVar10 = __errno_location();
                pcVar14 = strerror(*piVar10);
                snprintf(local_828,0x800,"API mcast send reply failed (%s) (%d)",pcVar14,local_1120)
                ;
                _applog(7,local_828,0);
              }
            }
            else if ((opt_debug != '\0') &&
                    (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(local_828,0x800,"API mcast send reply (%s) succeeded (%d) (%d)",local_1118,
                       sVar9,local_1120);
              _applog(7,local_828,0);
            }
            close(local_1120);
            goto LAB_0001540e;
          }
          freeaddrinfo(local_10f4);
          if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
          goto LAB_0001540e;
          pcVar14 = "API mcast could not open socket to client %s";
        }
        else {
          if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3))
          goto LAB_0001540e;
          pcVar14 = "Invalid client address %s";
        }
        snprintf(local_828,0x800,pcVar14,local_10f8);
        _applog(3,local_828,0);
        goto LAB_0001540e;
      }
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(local_828,0x800,"API mcast request ignored - invalid port (%s)",pcVar14);
        _applog(7,local_828,0);
      }
    }
    else if ((opt_debug != '\0') &&
            (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      builtin_strncpy(local_828,"API mcast request was no goo",0x1c);
      local_80c._0_2_ = 100;
      _applog(7,local_828,0);
    }
  }
  goto LAB_0001540e;
}

