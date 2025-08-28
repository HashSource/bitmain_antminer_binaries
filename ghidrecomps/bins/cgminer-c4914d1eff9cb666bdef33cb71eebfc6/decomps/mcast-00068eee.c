
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mcast(void)

{
  bool bVar1;
  undefined4 uVar2;
  _Bool _Var3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  time_t tVar7;
  time_t tVar8;
  size_t sVar9;
  ssize_t sVar10;
  char *pcVar11;
  char *pcVar12;
  size_t sVar13;
  char tmp42 [2048];
  ipv6_mreq grp_1;
  ip_mreq grp;
  int optval;
  char replybuf [1024];
  char buf [1024];
  char expect [9];
  addrinfo *res;
  addrinfo hints;
  char came_from_port [10];
  char port_s [10];
  char group;
  char *connectaddr;
  socklen_t came_from_siz;
  sockaddr_storage came_from;
  int reply_port;
  _Bool addrok;
  char *expect_code;
  size_t expect_code_len;
  time_t bindstart;
  addrinfo *client;
  addrinfo *host;
  int count;
  int bound;
  ssize_t rep;
  long reply_sock;
  long mcast_sock;
  char *binderror;
  
  mcast_sock = -1;
  reply_sock = -1;
  builtin_strncpy(expect,"cgminer-",8);
  expect[8] = '\0';
  sprintf(port_s,"%d",opt_api_mcast_port);
  memset(&hints,0,0x20);
  hints.ai_family = 0;
  iVar4 = getaddrinfo(opt_api_mcast_addr,port_s,(addrinfo *)&hints,(addrinfo **)&res);
  uVar2 = tmp42._28_4_;
  if (iVar4 != 0) {
    builtin_strncpy(tmp42,"Invalid API Multicast Address",0x1e);
    tmp42._30_2_ = SUB42(uVar2,2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  host = res;
  while ((host != (addrinfo *)0x0 && (mcast_sock = socket(res->ai_family,2,0), mcast_sock < 1))) {
    host = host->ai_next;
  }
  if (mcast_sock == -1) {
    freeaddrinfo((addrinfo *)res);
    builtin_strncpy(tmp42,"API mcast could not open socket",0x20);
    _applog(3,tmp42,true);
    _quit(1);
  }
  optval = 1;
  iVar4 = setsockopt(mcast_sock,1,2,&optval,4);
  if (iVar4 < 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      piVar5 = __errno_location();
      pcVar6 = strerror(*piVar5);
      snprintf(tmp42,0x800,"API mcast setsockopt SO_REUSEADDR failed (%s)%s",pcVar6,MUNAVAILABLE);
      _applog(3,tmp42,false);
    }
  }
  else {
    bVar1 = false;
    tVar7 = time((time_t *)0x0);
    while (!bVar1) {
      iVar4 = bind(mcast_sock,(sockaddr *)host->ai_addr,host->ai_addrlen);
      if (iVar4 < 0) {
        piVar5 = __errno_location();
        binderror = strerror(*piVar5);
        tVar8 = time((time_t *)0x0);
        if (0x3d < tVar8 - tVar7) break;
        cgsleep_ms(30000);
      }
      else {
        bVar1 = true;
      }
    }
    if (bVar1) {
      if (host->ai_family == 2) {
        memset(&grp,0,8);
        grp.imr_multiaddr.s_addr = *(in_addr_t *)(host->ai_addr->sa_data + 2);
        grp.imr_interface.s_addr = 0;
        iVar4 = setsockopt(mcast_sock,0,0x23,&grp,8);
        if (iVar4 < 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            piVar5 = __errno_location();
            pcVar6 = strerror(*piVar5);
            snprintf(tmp42,0x800,"API mcast join failed (%s)%s",pcVar6,MUNAVAILABLE);
            _applog(3,tmp42,false);
          }
          goto LAB_00069c24;
        }
      }
      else if (host->ai_family == 10) {
        memcpy(&grp_1,host->ai_addr->sa_data + 6,0x10);
        grp_1.ipv6mr_interface = 0;
        iVar4 = setsockopt(mcast_sock,0x29,0x14,&grp_1,0x14);
        if (iVar4 < 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            piVar5 = __errno_location();
            pcVar6 = strerror(*piVar5);
            snprintf(tmp42,0x800,"API mcast join failed (%s)%s",pcVar6,MUNAVAILABLE);
            _applog(3,tmp42,false);
          }
          goto LAB_00069c24;
        }
      }
      freeaddrinfo((addrinfo *)res);
      sVar9 = strlen(opt_api_mcast_code);
      pcVar6 = (char *)_cgmalloc(sVar9 + 10,"api-btm.c","mcast",0x1400);
      snprintf(pcVar6,sVar9 + 10,"%s%s-",expect,opt_api_mcast_code);
      count = 0;
      do {
        while( true ) {
          while( true ) {
            do {
              while( true ) {
                cgsleep_ms(1000);
                count = count + 1;
                came_from_siz = 0x80;
                sVar10 = recvfrom(mcast_sock,buf,0x3ff,0,(sockaddr *)&came_from,&came_from_siz);
                if (-1 < sVar10) break;
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  piVar5 = __errno_location();
                  pcVar11 = strerror(*piVar5);
                  snprintf(tmp42,0x800,"API mcast failed count=%d (%s) (%d)",count,pcVar11,
                           mcast_sock);
                  _applog(7,tmp42,false);
                }
              }
              _Var3 = check_connect(&came_from,&connectaddr,&group);
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                if (_Var3) {
                  pcVar11 = "Accepted";
                }
                else {
                  pcVar11 = "Ignored";
                }
                snprintf(tmp42,0x800,"API mcast from %s - %s",connectaddr,pcVar11);
                _applog(7,tmp42,false);
              }
            } while (!_Var3);
            buf[sVar10] = '\0';
            rep = sVar10;
            if ((0 < sVar10) && (replybuf[sVar10 + 0x3ff] == '\n')) {
              rep = sVar10 + -1;
              replybuf[sVar10 + 0x3ff] = '\0';
            }
            pcVar11 = came_from_port;
            getnameinfo((sockaddr *)&came_from,came_from_siz,(char *)0x0,0,pcVar11,10,1);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              pcVar11 = buf;
              snprintf(tmp42,0x800,"API mcast request rep=%d (%s) from [%s]:%s",rep,pcVar11,
                       connectaddr,came_from_port);
              _applog(7,tmp42,false);
            }
            if ((sVar9 + 9 < (uint)rep) && (iVar4 = memcmp(buf,pcVar6,sVar9 + 9), iVar4 == 0))
            break;
            uVar2 = tmp42._28_4_;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              builtin_strncpy(tmp42,"API mcast request was no good",0x1e);
              tmp42._30_2_ = SUB42(uVar2,2);
              _applog(7,tmp42,false);
            }
          }
          pcVar12 = (char *)atoi(buf + sVar9 + 9);
          if (((int)pcVar12 < 1) || (0xffff < (int)pcVar12)) break;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"API mcast request OK port %s=%d",buf + sVar9 + 9,pcVar12);
            _applog(7,tmp42,false);
            pcVar11 = pcVar12;
          }
          iVar4 = getaddrinfo(connectaddr,buf + sVar9 + 9,(addrinfo *)&hints,(addrinfo **)&res);
          if (iVar4 == 0) {
            client = res;
            while ((client != (addrinfo *)0x0 &&
                   (reply_sock = socket(res->ai_family,2,0), mcast_sock < 1))) {
              client = client->ai_next;
            }
            if (reply_sock == -1) {
              freeaddrinfo((addrinfo *)res);
              if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                snprintf(tmp42,0x800,"API mcast could not open socket to client %s",connectaddr);
                _applog(3,tmp42,false);
              }
            }
            else {
              snprintf(replybuf,0x400,"cgm-FTW-%d-%s",opt_api_port,opt_api_mcast_des);
              sVar13 = strlen(replybuf);
              sVar10 = sendto(reply_sock,replybuf,sVar13 + 1,0,(sockaddr *)client->ai_addr,
                              client->ai_addrlen);
              freeaddrinfo((addrinfo *)res);
              if (sVar10 < 0) {
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  piVar5 = __errno_location();
                  pcVar11 = strerror(*piVar5);
                  snprintf(tmp42,0x800,"API mcast send reply failed (%s) (%d)",pcVar11,reply_sock);
                  _applog(7,tmp42,false);
                }
              }
              else if ((opt_debug != false) &&
                      (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level))))
              {
                snprintf(tmp42,0x800,"API mcast send reply (%s) succeeded (%d) (%d)",replybuf,sVar10
                         ,reply_sock);
                _applog(7,tmp42,false);
              }
              close(reply_sock);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            snprintf(tmp42,0x800,"Invalid client address %s",connectaddr,pcVar11);
            _applog(3,tmp42,false);
          }
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"API mcast request ignored - invalid port (%s)",buf + sVar9 + 9);
          _applog(7,tmp42,false);
        }
      } while( true );
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"API mcast bind to port %d failed (%s)%s",opt_api_mcast_port,binderror,
               MUNAVAILABLE);
      _applog(3,tmp42,false);
    }
  }
LAB_00069c24:
  close(mcast_sock);
  return;
}

