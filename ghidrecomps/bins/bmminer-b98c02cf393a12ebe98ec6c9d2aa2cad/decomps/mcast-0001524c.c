
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  undefined4 *local_1118;
  undefined uStack_10fd;
  socklen_t local_10fc;
  char *local_10f8;
  addrinfo *local_10f4;
  undefined4 local_10f0;
  undefined4 local_10ec;
  undefined4 uStack_10e8;
  undefined local_10e4;
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
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 local_80c;
  undefined2 uStack_808;
  undefined local_806;
  
  local_10f8 = (char *)0x0;
  local_10ec = s_bmminer__00057cf8._0_4_;
  uStack_10e8 = s_bmminer__00057cf8._4_4_;
  local_10e4 = (undefined)ram0x00057d00;
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
    local_828._0_1_ = s_Invalid_API_Multicast_Address_00057a58[0];
    local_828._1_1_ = s_Invalid_API_Multicast_Address_00057a58[1];
    local_828._2_1_ = s_Invalid_API_Multicast_Address_00057a58[2];
    local_828._3_1_ = s_Invalid_API_Multicast_Address_00057a58[3];
    uStack_824._0_1_ = s_Invalid_API_Multicast_Address_00057a58[4];
    uStack_824._1_1_ = s_Invalid_API_Multicast_Address_00057a58[5];
    uStack_824._2_1_ = s_Invalid_API_Multicast_Address_00057a58[6];
    uStack_824._3_1_ = s_Invalid_API_Multicast_Address_00057a58[7];
    uStack_820._0_1_ = s_Invalid_API_Multicast_Address_00057a58[8];
    uStack_820._1_1_ = s_Invalid_API_Multicast_Address_00057a58[9];
    uStack_820._2_1_ = s_Invalid_API_Multicast_Address_00057a58[10];
    uStack_820._3_1_ = s_Invalid_API_Multicast_Address_00057a58[11];
    uStack_81c._0_1_ = s_Invalid_API_Multicast_Address_00057a58[12];
    uStack_81c._1_1_ = s_Invalid_API_Multicast_Address_00057a58[13];
    uStack_81c._2_1_ = s_Invalid_API_Multicast_Address_00057a58[14];
    uStack_81c._3_1_ = s_Invalid_API_Multicast_Address_00057a58[15];
    local_818._0_1_ = s_Invalid_API_Multicast_Address_00057a58[16];
    local_818._1_1_ = s_Invalid_API_Multicast_Address_00057a58[17];
    local_818._2_1_ = s_Invalid_API_Multicast_Address_00057a58[18];
    local_818._3_1_ = s_Invalid_API_Multicast_Address_00057a58[19];
    uStack_814._0_1_ = s_Invalid_API_Multicast_Address_00057a58[20];
    uStack_814._1_1_ = s_Invalid_API_Multicast_Address_00057a58[21];
    uStack_814._2_1_ = s_Invalid_API_Multicast_Address_00057a58[22];
    uStack_814._3_1_ = s_Invalid_API_Multicast_Address_00057a58[23];
    uStack_810._0_1_ = s_Invalid_API_Multicast_Address_00057a58[24];
    uStack_810._1_1_ = s_Invalid_API_Multicast_Address_00057a58[25];
    uStack_810._2_1_ = s_Invalid_API_Multicast_Address_00057a58[26];
    uStack_810._3_1_ = s_Invalid_API_Multicast_Address_00057a58[27];
    local_80c._0_2_ = (short)ram0x00057a74;
    _applog(3,&local_828,1);
    _quit(1);
    paVar13 = local_10f4;
    if (local_10f4 != (addrinfo *)0x0) goto LAB_000152be;
LAB_00015586:
    freeaddrinfo(local_10f4);
    local_1138 = -1;
    paVar13 = (addrinfo *)0x0;
    local_828._0_1_ = s_API_mcast_could_not_open_socket_00057a78[0];
    local_828._1_1_ = s_API_mcast_could_not_open_socket_00057a78[1];
    local_828._2_1_ = s_API_mcast_could_not_open_socket_00057a78[2];
    local_828._3_1_ = s_API_mcast_could_not_open_socket_00057a78[3];
    uStack_824._0_1_ = s_API_mcast_could_not_open_socket_00057a78[4];
    uStack_824._1_1_ = s_API_mcast_could_not_open_socket_00057a78[5];
    uStack_824._2_1_ = s_API_mcast_could_not_open_socket_00057a78[6];
    uStack_824._3_1_ = s_API_mcast_could_not_open_socket_00057a78[7];
    uStack_820._0_1_ = s_API_mcast_could_not_open_socket_00057a78[8];
    uStack_820._1_1_ = s_API_mcast_could_not_open_socket_00057a78[9];
    uStack_820._2_1_ = s_API_mcast_could_not_open_socket_00057a78[10];
    uStack_820._3_1_ = s_API_mcast_could_not_open_socket_00057a78[11];
    uStack_81c._0_1_ = s_API_mcast_could_not_open_socket_00057a78[12];
    uStack_81c._1_1_ = s_API_mcast_could_not_open_socket_00057a78[13];
    uStack_81c._2_1_ = s_API_mcast_could_not_open_socket_00057a78[14];
    uStack_81c._3_1_ = s_API_mcast_could_not_open_socket_00057a78[15];
    local_818._0_1_ = s_API_mcast_could_not_open_socket_00057a78[16];
    local_818._1_1_ = s_API_mcast_could_not_open_socket_00057a78[17];
    local_818._2_1_ = s_API_mcast_could_not_open_socket_00057a78[18];
    local_818._3_1_ = s_API_mcast_could_not_open_socket_00057a78[19];
    uStack_814._0_1_ = s_API_mcast_could_not_open_socket_00057a78[20];
    uStack_814._1_1_ = s_API_mcast_could_not_open_socket_00057a78[21];
    uStack_814._2_1_ = s_API_mcast_could_not_open_socket_00057a78[22];
    uStack_814._3_1_ = s_API_mcast_could_not_open_socket_00057a78[23];
    uStack_810._0_1_ = s_API_mcast_could_not_open_socket_00057a78[24];
    uStack_810._1_1_ = s_API_mcast_could_not_open_socket_00057a78[25];
    uStack_810._2_1_ = s_API_mcast_could_not_open_socket_00057a78[26];
    uStack_810._3_1_ = s_API_mcast_could_not_open_socket_00057a78[27];
    local_80c._0_1_ = s_API_mcast_could_not_open_socket_00057a78[28];
    local_80c._1_1_ = s_API_mcast_could_not_open_socket_00057a78[29];
    local_80c._2_1_ = s_API_mcast_could_not_open_socket_00057a78[30];
    local_80c._3_1_ = s_API_mcast_could_not_open_socket_00057a78[31];
    _applog(3,&local_828,1);
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
          snprintf((char *)&local_828,0x800,"API mcast bind to port %d failed (%s)%s",
                   opt_api_mcast_port,pcVar14," - API multicast listener will not be available");
          _applog(3,&local_828,0);
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
      local_1118 = &local_c28;
      freeaddrinfo(local_10f4);
      pcVar14 = opt_api_mcast_code;
      sVar3 = strlen(opt_api_mcast_code);
      __n = sVar3 + 9;
      pcVar4 = (char *)malloc(sVar3 + 10);
      if (pcVar4 == (char *)0x0) {
        local_828._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[0];
        local_828._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[1];
        local_828._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[2];
        local_828._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[3];
        uStack_824._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[4];
        uStack_824._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[5];
        uStack_824._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[6];
        uStack_824._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[7];
        uStack_820._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[8];
        uStack_820._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[9];
        uStack_820._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[10];
        uStack_820._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[11];
        uStack_81c._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[12];
        uStack_81c._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[13];
        uStack_81c._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[14];
        uStack_81c._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[15];
        local_818._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[16];
        local_818._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[17];
        local_818._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[18];
        local_818._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[19];
        uStack_814._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[20];
        uStack_814._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[21];
        uStack_814._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[22];
        uStack_814._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[23];
        uStack_810._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[24];
        uStack_810._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[25];
        uStack_810._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[26];
        uStack_810._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[27];
        local_80c._0_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[28];
        local_80c._1_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[29];
        local_80c._2_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[30];
        local_80c._3_1_ = s_Failed_to_malloc_mcast_expect_co_00057b40[31];
        uStack_808 = (undefined2)ram0x00057b60;
        local_806 = (undefined)((uint)ram0x00057b60 >> 0x10);
        _applog(3,&local_828,1);
        _quit(1);
        pcVar14 = opt_api_mcast_code;
      }
      local_1120 = -1;
      iVar1 = 0;
      __buf = acStack_1029 + 1;
      snprintf(pcVar4,sVar3 + 10,"%s%s-",&local_10ec,pcVar14);
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
              snprintf((char *)&local_828,0x800,"API mcast failed count=%d (%s) (%d)",iVar1,pcVar14,
                       local_1138);
              _applog(7,&local_828,0);
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
            snprintf((char *)&local_828,0x800,"API mcast from %s - %s",local_10f8,pcVar14);
            _applog(7,&local_828,0);
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
  snprintf((char *)&local_828,0x800,pcVar4,pcVar14," - API multicast listener will not be available"
          );
  _applog(3,&local_828,0);
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
      snprintf((char *)&local_828,0x800,"API mcast request rep=%d (%s) from [%s]:%s",uVar5,__buf,
               local_10f8,acStack_10d4);
      _applog(7,&local_828,0);
    }
    if ((__n < uVar5) && (iVar6 = memcmp(__buf,pcVar4,__n), iVar6 == 0)) {
LAB_000154fa:
      pcVar14 = __buf + __n;
      lVar7 = strtol(pcVar14,(char **)0x0,10);
      if (lVar7 - 1U < 0xffff) {
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          snprintf((char *)&local_828,0x800,"API mcast request OK port %s=%d",pcVar14,lVar7);
          _applog(7,&local_828,0);
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
            snprintf((char *)local_1118,0x400,"cgm-FTW-%d-%s",opt_api_port,opt_api_mcast_des);
            sVar3 = strlen((char *)local_1118);
            sVar9 = sendto(local_1120,local_1118,sVar3 + 1,0,local_111c->ai_addr,
                           local_111c->ai_addrlen);
            freeaddrinfo(local_10f4);
            if (sVar9 < 0) {
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                piVar10 = __errno_location();
                pcVar14 = strerror(*piVar10);
                snprintf((char *)&local_828,0x800,"API mcast send reply failed (%s) (%d)",pcVar14,
                         local_1120);
                _applog(7,&local_828,0);
              }
            }
            else if ((opt_debug != '\0') &&
                    (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf((char *)&local_828,0x800,"API mcast send reply (%s) succeeded (%d) (%d)",
                       local_1118,sVar9,local_1120);
              _applog(7,&local_828,0);
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
        snprintf((char *)&local_828,0x800,pcVar14,local_10f8);
        _applog(3,&local_828,0);
        goto LAB_0001540e;
      }
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf((char *)&local_828,0x800,"API mcast request ignored - invalid port (%s)",pcVar14);
        _applog(7,&local_828,0);
      }
    }
    else if ((opt_debug != '\0') &&
            (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_828._0_1_ = s_API_mcast_request_was_no_good_00057cd8[0];
      local_828._1_1_ = s_API_mcast_request_was_no_good_00057cd8[1];
      local_828._2_1_ = s_API_mcast_request_was_no_good_00057cd8[2];
      local_828._3_1_ = s_API_mcast_request_was_no_good_00057cd8[3];
      uStack_824._0_1_ = s_API_mcast_request_was_no_good_00057cd8[4];
      uStack_824._1_1_ = s_API_mcast_request_was_no_good_00057cd8[5];
      uStack_824._2_1_ = s_API_mcast_request_was_no_good_00057cd8[6];
      uStack_824._3_1_ = s_API_mcast_request_was_no_good_00057cd8[7];
      uStack_820._0_1_ = s_API_mcast_request_was_no_good_00057cd8[8];
      uStack_820._1_1_ = s_API_mcast_request_was_no_good_00057cd8[9];
      uStack_820._2_1_ = s_API_mcast_request_was_no_good_00057cd8[10];
      uStack_820._3_1_ = s_API_mcast_request_was_no_good_00057cd8[11];
      uStack_81c._0_1_ = s_API_mcast_request_was_no_good_00057cd8[12];
      uStack_81c._1_1_ = s_API_mcast_request_was_no_good_00057cd8[13];
      uStack_81c._2_1_ = s_API_mcast_request_was_no_good_00057cd8[14];
      uStack_81c._3_1_ = s_API_mcast_request_was_no_good_00057cd8[15];
      local_818._0_1_ = s_API_mcast_request_was_no_good_00057cd8[16];
      local_818._1_1_ = s_API_mcast_request_was_no_good_00057cd8[17];
      local_818._2_1_ = s_API_mcast_request_was_no_good_00057cd8[18];
      local_818._3_1_ = s_API_mcast_request_was_no_good_00057cd8[19];
      uStack_814._0_1_ = s_API_mcast_request_was_no_good_00057cd8[20];
      uStack_814._1_1_ = s_API_mcast_request_was_no_good_00057cd8[21];
      uStack_814._2_1_ = s_API_mcast_request_was_no_good_00057cd8[22];
      uStack_814._3_1_ = s_API_mcast_request_was_no_good_00057cd8[23];
      uStack_810._0_1_ = s_API_mcast_request_was_no_good_00057cd8[24];
      uStack_810._1_1_ = s_API_mcast_request_was_no_good_00057cd8[25];
      uStack_810._2_1_ = s_API_mcast_request_was_no_good_00057cd8[26];
      uStack_810._3_1_ = s_API_mcast_request_was_no_good_00057cd8[27];
      local_80c._0_2_ = (short)ram0x00057cf4;
      _applog(7,&local_828,0);
    }
  }
  goto LAB_0001540e;
}

