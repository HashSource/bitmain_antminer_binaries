
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mcast(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  int reply_port;
  int iVar3;
  int iVar4;
  time_t tVar5;
  size_t sVar6;
  uint __n;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  time_t tVar10;
  long lVar11;
  ssize_t sVar12;
  int *piVar13;
  sockaddr *psVar14;
  addrinfo *paVar15;
  char *pcVar16;
  int local_1120;
  char *local_111c;
  char group;
  socklen_t local_1110;
  char *local_110c;
  addrinfo *local_1108;
  undefined4 local_1104;
  char expect [9];
  char port_s [10];
  char came_from_port [10];
  ipv6_mreq grp_1;
  addrinfo hints;
  sockaddr_storage came_from;
  char buf [1024];
  char replybuf [1024];
  char tmp42 [2048];
  
  builtin_strncpy(expect,"bmminer-",8);
  expect[8] = '\0';
  sprintf(port_s,"%d",opt_api_mcast_port);
  hints.ai_flags = 0;
  hints.ai_family = 0;
  hints.ai_socktype = 0;
  hints.ai_protocol = 0;
  hints.ai_addrlen = 0;
  hints.ai_addr = (sockaddr *)0x0;
  hints.ai_canonname = (char *)0x0;
  hints.ai_next = (addrinfo *)0x0;
  iVar3 = getaddrinfo(opt_api_mcast_addr,port_s,(addrinfo *)&hints,&local_1108);
  uVar1 = tmp42._28_4_;
  if (iVar3 == 0) {
    paVar15 = local_1108;
    if (local_1108 == (addrinfo *)0x0) goto LAB_00018c5e;
LAB_000189cc:
    do {
      iVar3 = socket(local_1108->ai_family,2,0);
      if (0 < iVar3) goto LAB_000189dc;
      paVar15 = paVar15->ai_next;
    } while (paVar15 != (addrinfo *)0x0);
    if (iVar3 == -1) goto LAB_00018c5e;
  }
  else {
    builtin_strncpy(tmp42,"Invalid API Multicast Address",0x1e);
    tmp42._30_2_ = SUB42(uVar1,2);
    _applog(3,tmp42,true);
    _quit(1);
    paVar15 = local_1108;
    if (local_1108 != (addrinfo *)0x0) goto LAB_000189cc;
LAB_00018c5e:
    freeaddrinfo(local_1108);
    paVar15 = (addrinfo *)0x0;
    iVar3 = -1;
    builtin_strncpy(tmp42,"API mcast could not open socket",0x20);
    _applog(3,tmp42,true);
    _quit(1);
  }
LAB_000189dc:
  local_1104 = 1;
  iVar4 = setsockopt(iVar3,1,2,&local_1104,4);
  if (iVar4 < 0) {
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_00018ccc;
    piVar13 = __errno_location();
    pcVar16 = strerror(*piVar13);
    pcVar7 = "API mcast setsockopt SO_REUSEADDR failed (%s)%s";
  }
  else {
    tVar5 = time((time_t *)0x0);
    while (iVar4 = bind(iVar3,paVar15->ai_addr,paVar15->ai_addrlen), iVar4 < 0) {
      piVar13 = __errno_location();
      pcVar16 = strerror(*piVar13);
      tVar10 = time((time_t *)0x0);
      if (0x3d < tVar10 - tVar5) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"API mcast bind to port %d failed (%s)%s",opt_api_mcast_port,pcVar16,
                   " - API multicast listener will not be available");
          _applog(3,tmp42,false);
        }
        goto LAB_00018ccc;
      }
      cgsleep_ms(30000);
    }
    if (paVar15->ai_family == 2) {
      replybuf[4] = '\0';
      replybuf[5] = '\0';
      replybuf[6] = '\0';
      replybuf[7] = '\0';
      replybuf._0_4_ = *(undefined4 *)(paVar15->ai_addr->sa_data + 2);
      iVar4 = setsockopt(iVar3,0,0x23,replybuf,8);
    }
    else {
      if (paVar15->ai_family != 10) goto LAB_00018a24;
      psVar14 = paVar15->ai_addr;
      grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[0] = *(undefined4 *)(psVar14->sa_data + 6);
      grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[1] = *(undefined4 *)(psVar14->sa_data + 10);
      grp_1.ipv6mr_multiaddr.__in6_u._8_2_ = psVar14[1].sa_family;
      grp_1.ipv6mr_multiaddr.__in6_u._10_1_ = psVar14[1].sa_data[0];
      grp_1.ipv6mr_multiaddr.__in6_u._11_1_ = psVar14[1].sa_data[1];
      grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[3] = *(undefined4 *)(psVar14[1].sa_data + 2);
      grp_1.ipv6mr_interface = 0;
      iVar4 = setsockopt(iVar3,0x29,0x14,&grp_1,0x14);
    }
    if (-1 < iVar4) {
LAB_00018a24:
      local_111c = replybuf;
      freeaddrinfo(local_1108);
      pcVar16 = opt_api_mcast_code;
      sVar6 = strlen(opt_api_mcast_code);
      __n = sVar6 + 9;
      pcVar7 = (char *)malloc(sVar6 + 10);
      if (pcVar7 == (char *)0x0) {
        builtin_strncpy(tmp42,"Failed to malloc mcast expect_co",0x20);
        tmp42[0x20] = 'd';
        tmp42[0x21] = 'e';
        tmp42[0x22] = '\0';
        _applog(3,tmp42,true);
        _quit(1);
        pcVar16 = opt_api_mcast_code;
      }
      iVar4 = 0;
      local_1120 = -1;
      snprintf(pcVar7,sVar6 + 10,"%s%s-",expect,pcVar16);
LAB_00018a74:
      do {
        while( true ) {
          while( true ) {
            while( true ) {
              do {
                while( true ) {
                  cgsleep_ms(1000);
                  local_1110 = 0x80;
                  iVar4 = iVar4 + 1;
                  uVar8 = recvfrom(iVar3,buf,0x3ff,0,(sockaddr *)&came_from,&local_1110);
                  if (-1 < (int)uVar8) break;
                  if ((opt_debug != false) &&
                     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level))))
                  {
                    piVar13 = __errno_location();
                    pcVar16 = strerror(*piVar13);
                    snprintf(tmp42,0x800,"API mcast failed count=%d (%s) (%d)",iVar4,pcVar16,iVar3);
                    _applog(7,tmp42,false);
                  }
                }
                _Var2 = check_connect(&came_from,&local_110c,&group);
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  pcVar16 = "Ignored";
                  if (_Var2) {
                    pcVar16 = "Accepted";
                  }
                  snprintf(tmp42,0x800,"API mcast from %s - %s",local_110c,pcVar16);
                  _applog(7,tmp42,false);
                }
              } while (!_Var2);
              buf[uVar8] = '\0';
              if ((uVar8 != 0) && (came_from.__ss_padding[uVar8 + 0x77] == '\n')) {
                uVar8 = uVar8 - 1;
                buf[uVar8] = '\0';
              }
              getnameinfo((sockaddr *)&came_from,local_1110,(char *)0x0,0,came_from_port,10,1);
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"API mcast request rep=%d (%s) from [%s]:%s",uVar8,buf,
                         local_110c,came_from_port);
                _applog(7,tmp42,false);
              }
              if ((__n < uVar8) && (iVar9 = memcmp(buf,pcVar7,__n), iVar9 == 0)) break;
              uVar1 = tmp42._28_4_;
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                builtin_strncpy(tmp42,"API mcast request was no good",0x1e);
                tmp42._30_2_ = SUB42(uVar1,2);
                _applog(7,tmp42,false);
              }
            }
            pcVar16 = buf + __n;
            lVar11 = strtol(pcVar16,(char **)0x0,10);
            if (lVar11 - 1U < 0xffff) break;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"API mcast request ignored - invalid port (%s)",pcVar16);
              _applog(7,tmp42,false);
            }
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"API mcast request OK port %s=%d",pcVar16,lVar11);
            _applog(7,tmp42,false);
          }
          iVar9 = getaddrinfo(local_110c,pcVar16,(addrinfo *)&hints,&local_1108);
          paVar15 = local_1108;
          if (iVar9 != 0) goto code_r0x00018dee;
          if ((local_1108 != (addrinfo *)0x0) &&
             (local_1120 = socket(local_1108->ai_family,2,0), iVar3 < 1)) {
            while (paVar15 = paVar15->ai_next, paVar15 != (addrinfo *)0x0) {
              local_1120 = socket(local_1108->ai_family,2,0);
            }
            paVar15 = (addrinfo *)0x0;
          }
          if (local_1120 == -1) break;
          snprintf(local_111c,0x400,"cgm-FTW-%d-%s",opt_api_port,opt_api_mcast_des);
          sVar6 = strlen(local_111c);
          sVar12 = sendto(local_1120,local_111c,sVar6 + 1,0,paVar15->ai_addr,paVar15->ai_addrlen);
          freeaddrinfo(local_1108);
          if (sVar12 < 0) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              piVar13 = __errno_location();
              pcVar16 = strerror(*piVar13);
              snprintf(tmp42,0x800,"API mcast send reply failed (%s) (%d)",pcVar16,local_1120);
              _applog(7,tmp42,false);
            }
          }
          else if ((opt_debug != false) &&
                  (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"API mcast send reply (%s) succeeded (%d) (%d)",local_111c,sVar12,
                     local_1120);
            _applog(7,tmp42,false);
          }
          close(local_1120);
        }
        freeaddrinfo(local_1108);
      } while (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3));
      pcVar16 = "API mcast could not open socket to client %s";
      goto LAB_00018e1e;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_00018ccc;
    piVar13 = __errno_location();
    pcVar16 = strerror(*piVar13);
    pcVar7 = "API mcast join failed (%s)%s";
  }
  snprintf(tmp42,0x800,pcVar7,pcVar16," - API multicast listener will not be available");
  _applog(3,tmp42,false);
LAB_00018ccc:
  close(iVar3);
  return;
code_r0x00018dee:
  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
    pcVar16 = "Invalid client address %s";
LAB_00018e1e:
    snprintf(tmp42,0x800,pcVar16,local_110c);
    _applog(3,tmp42,false);
  }
  goto LAB_00018a74;
}

