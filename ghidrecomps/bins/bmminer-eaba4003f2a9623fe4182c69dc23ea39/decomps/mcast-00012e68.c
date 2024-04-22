
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void mcast(void)

{
  bool bVar1;
  _Bool _Var2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  time_t tVar6;
  time_t tVar7;
  size_t sVar8;
  char *pcVar9;
  ssize_t sVar10;
  sockaddr *psVar11;
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
  expect._0_4_ = s_cgminer__0006e214._0_4_;
  expect._4_4_ = s_cgminer__0006e214._4_4_;
  expect[8] = (char)ram0x0006e21c;
  sprintf(port_s,"%d",opt_api_mcast_port);
  memset(&hints,0,0x20);
  hints.ai_family = 0;
  iVar3 = getaddrinfo(opt_api_mcast_addr,port_s,(addrinfo *)&hints,(addrinfo **)&res);
  if (iVar3 != 0) {
    tmp42[0] = s_Invalid_API_Multicast_Address_0006dfc0[0];
    tmp42[1] = s_Invalid_API_Multicast_Address_0006dfc0[1];
    tmp42[2] = s_Invalid_API_Multicast_Address_0006dfc0[2];
    tmp42[3] = s_Invalid_API_Multicast_Address_0006dfc0[3];
    tmp42[4] = s_Invalid_API_Multicast_Address_0006dfc0[4];
    tmp42[5] = s_Invalid_API_Multicast_Address_0006dfc0[5];
    tmp42[6] = s_Invalid_API_Multicast_Address_0006dfc0[6];
    tmp42[7] = s_Invalid_API_Multicast_Address_0006dfc0[7];
    tmp42[8] = s_Invalid_API_Multicast_Address_0006dfc0[8];
    tmp42[9] = s_Invalid_API_Multicast_Address_0006dfc0[9];
    tmp42[10] = s_Invalid_API_Multicast_Address_0006dfc0[10];
    tmp42[11] = s_Invalid_API_Multicast_Address_0006dfc0[11];
    tmp42[12] = s_Invalid_API_Multicast_Address_0006dfc0[12];
    tmp42[13] = s_Invalid_API_Multicast_Address_0006dfc0[13];
    tmp42[14] = s_Invalid_API_Multicast_Address_0006dfc0[14];
    tmp42[15] = s_Invalid_API_Multicast_Address_0006dfc0[15];
    tmp42[16] = s_Invalid_API_Multicast_Address_0006dfc0[16];
    tmp42[17] = s_Invalid_API_Multicast_Address_0006dfc0[17];
    tmp42[18] = s_Invalid_API_Multicast_Address_0006dfc0[18];
    tmp42[19] = s_Invalid_API_Multicast_Address_0006dfc0[19];
    tmp42[20] = s_Invalid_API_Multicast_Address_0006dfc0[20];
    tmp42[21] = s_Invalid_API_Multicast_Address_0006dfc0[21];
    tmp42[22] = s_Invalid_API_Multicast_Address_0006dfc0[22];
    tmp42[23] = s_Invalid_API_Multicast_Address_0006dfc0[23];
    tmp42[24] = s_Invalid_API_Multicast_Address_0006dfc0[24];
    tmp42[25] = s_Invalid_API_Multicast_Address_0006dfc0[25];
    tmp42[26] = s_Invalid_API_Multicast_Address_0006dfc0[26];
    tmp42[27] = s_Invalid_API_Multicast_Address_0006dfc0[27];
    tmp42[28] = (char)(short)ram0x0006dfdc;
    tmp42[29] = (char)((ushort)(short)ram0x0006dfdc >> 8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  host = res;
  while ((host != (addrinfo *)0x0 && (mcast_sock = socket(res->ai_family,2,0), mcast_sock < 1))) {
    host = host->ai_next;
  }
  if (mcast_sock == -1) {
    freeaddrinfo((addrinfo *)res);
    tmp42[0] = s_API_mcast_could_not_open_socket_0006dfe0[0];
    tmp42[1] = s_API_mcast_could_not_open_socket_0006dfe0[1];
    tmp42[2] = s_API_mcast_could_not_open_socket_0006dfe0[2];
    tmp42[3] = s_API_mcast_could_not_open_socket_0006dfe0[3];
    tmp42[4] = s_API_mcast_could_not_open_socket_0006dfe0[4];
    tmp42[5] = s_API_mcast_could_not_open_socket_0006dfe0[5];
    tmp42[6] = s_API_mcast_could_not_open_socket_0006dfe0[6];
    tmp42[7] = s_API_mcast_could_not_open_socket_0006dfe0[7];
    tmp42[8] = s_API_mcast_could_not_open_socket_0006dfe0[8];
    tmp42[9] = s_API_mcast_could_not_open_socket_0006dfe0[9];
    tmp42[10] = s_API_mcast_could_not_open_socket_0006dfe0[10];
    tmp42[11] = s_API_mcast_could_not_open_socket_0006dfe0[11];
    tmp42[12] = s_API_mcast_could_not_open_socket_0006dfe0[12];
    tmp42[13] = s_API_mcast_could_not_open_socket_0006dfe0[13];
    tmp42[14] = s_API_mcast_could_not_open_socket_0006dfe0[14];
    tmp42[15] = s_API_mcast_could_not_open_socket_0006dfe0[15];
    tmp42[16] = s_API_mcast_could_not_open_socket_0006dfe0[16];
    tmp42[17] = s_API_mcast_could_not_open_socket_0006dfe0[17];
    tmp42[18] = s_API_mcast_could_not_open_socket_0006dfe0[18];
    tmp42[19] = s_API_mcast_could_not_open_socket_0006dfe0[19];
    tmp42[20] = s_API_mcast_could_not_open_socket_0006dfe0[20];
    tmp42[21] = s_API_mcast_could_not_open_socket_0006dfe0[21];
    tmp42[22] = s_API_mcast_could_not_open_socket_0006dfe0[22];
    tmp42[23] = s_API_mcast_could_not_open_socket_0006dfe0[23];
    tmp42[24] = s_API_mcast_could_not_open_socket_0006dfe0[24];
    tmp42[25] = s_API_mcast_could_not_open_socket_0006dfe0[25];
    tmp42[26] = s_API_mcast_could_not_open_socket_0006dfe0[26];
    tmp42[27] = s_API_mcast_could_not_open_socket_0006dfe0[27];
    tmp42[28] = s_API_mcast_could_not_open_socket_0006dfe0[28];
    tmp42[29] = s_API_mcast_could_not_open_socket_0006dfe0[29];
    tmp42[30] = s_API_mcast_could_not_open_socket_0006dfe0[30];
    tmp42[31] = s_API_mcast_could_not_open_socket_0006dfe0[31];
    _applog(3,tmp42,true);
    _quit(1);
  }
  optval = 1;
  iVar3 = setsockopt(mcast_sock,1,2,&optval,4);
  if (iVar3 < 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      piVar4 = __errno_location();
      pcVar5 = strerror(*piVar4);
      snprintf(tmp42,0x800,"API mcast setsockopt SO_REUSEADDR failed (%s)%s",pcVar5,MUNAVAILABLE);
      _applog(3,tmp42,false);
    }
  }
  else {
    bVar1 = false;
    tVar6 = time((time_t *)0x0);
    while (!bVar1) {
      iVar3 = bind(mcast_sock,(sockaddr *)host->ai_addr,host->ai_addrlen);
      if (iVar3 < 0) {
        piVar4 = __errno_location();
        binderror = strerror(*piVar4);
        tVar7 = time((time_t *)0x0);
        if (0x3d < tVar7 - tVar6) break;
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
        iVar3 = setsockopt(mcast_sock,0,0x23,&grp,8);
        if (iVar3 < 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            piVar4 = __errno_location();
            pcVar5 = strerror(*piVar4);
            snprintf(tmp42,0x800,"API mcast join failed (%s)%s",pcVar5,MUNAVAILABLE);
            _applog(3,tmp42,false);
          }
          goto die;
        }
      }
      else if (host->ai_family == 10) {
        psVar11 = host->ai_addr;
        grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[0] = *(undefined4 *)(psVar11->sa_data + 6);
        grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[1] = *(undefined4 *)(psVar11->sa_data + 10);
        grp_1.ipv6mr_multiaddr.__in6_u._8_2_ = psVar11[1].sa_family;
        grp_1.ipv6mr_multiaddr.__in6_u._10_1_ = psVar11[1].sa_data[0];
        grp_1.ipv6mr_multiaddr.__in6_u._11_1_ = psVar11[1].sa_data[1];
        grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[3] = *(undefined4 *)(psVar11[1].sa_data + 2);
        grp_1.ipv6mr_interface = 0;
        iVar3 = setsockopt(mcast_sock,0x29,0x14,&grp_1,0x14);
        if (iVar3 < 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            piVar4 = __errno_location();
            pcVar5 = strerror(*piVar4);
            snprintf(tmp42,0x800,"API mcast join failed (%s)%s",pcVar5,MUNAVAILABLE);
            _applog(3,tmp42,false);
          }
          goto die;
        }
      }
      freeaddrinfo((addrinfo *)res);
      sVar8 = strlen(opt_api_mcast_code);
      expect_code_len = sVar8 + 9;
      expect_code = (char *)_cgmalloc(sVar8 + 10,"api-btm.c","mcast",0x13f0);
      snprintf(expect_code,sVar8 + 10,"%s%s-",expect,opt_api_mcast_code);
      count = 0;
      do {
        while( true ) {
          cgsleep_ms(1000);
          count = count + 1;
          came_from_siz = 0x80;
          rep = recvfrom(mcast_sock,buf,0x3ff,0,(sockaddr *)&came_from,&came_from_siz);
          if (-1 < rep) break;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            piVar4 = __errno_location();
            pcVar5 = strerror(*piVar4);
            snprintf(tmp42,0x800,"API mcast failed count=%d (%s) (%d)",count,pcVar5,mcast_sock);
            _applog(7,tmp42,false);
          }
        }
        _Var2 = check_connect(&came_from,&connectaddr,&group);
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          if (_Var2) {
            pcVar5 = "Accepted";
          }
          else {
            pcVar5 = "Ignored";
          }
          snprintf(tmp42,0x800,"API mcast from %s - %s",connectaddr,pcVar5);
          _applog(7,tmp42,false);
        }
        if (_Var2) {
          buf[rep] = '\0';
          if ((0 < rep) && (replybuf[rep + 0x3ff] == '\n')) {
            iVar3 = rep + 0x3ff;
            rep = rep + -1;
            replybuf[iVar3] = '\0';
          }
          pcVar5 = came_from_port;
          getnameinfo((sockaddr *)&came_from,came_from_siz,(char *)0x0,0,pcVar5,10,1);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            pcVar5 = buf;
            snprintf(tmp42,0x800,"API mcast request rep=%d (%s) from [%s]:%s",rep,pcVar5,connectaddr
                     ,came_from_port);
            _applog(7,tmp42,false);
          }
          if ((expect_code_len < (uint)rep) &&
             (iVar3 = memcmp(buf,expect_code,expect_code_len), iVar3 == 0)) {
            pcVar9 = (char *)atoi(buf + expect_code_len);
            if (((int)pcVar9 < 1) || (0xffff < (int)pcVar9)) {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"API mcast request ignored - invalid port (%s)",
                         buf + expect_code_len);
                _applog(7,tmp42,false);
              }
            }
            else {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"API mcast request OK port %s=%d",buf + expect_code_len,pcVar9)
                ;
                _applog(7,tmp42,false);
                pcVar5 = pcVar9;
              }
              iVar3 = getaddrinfo(connectaddr,buf + expect_code_len,(addrinfo *)&hints,
                                  (addrinfo **)&res);
              if (iVar3 == 0) {
                client = res;
                while ((client != (addrinfo *)0x0 &&
                       (reply_sock = socket(res->ai_family,2,0), mcast_sock < 1))) {
                  client = client->ai_next;
                }
                if (reply_sock == -1) {
                  freeaddrinfo((addrinfo *)res);
                  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    snprintf(tmp42,0x800,"API mcast could not open socket to client %s",connectaddr)
                    ;
                    _applog(3,tmp42,false);
                  }
                }
                else {
                  snprintf(replybuf,0x400,"cgm-FTW-%d-%s",opt_api_port,opt_api_mcast_des);
                  sVar8 = strlen(replybuf);
                  sVar10 = sendto(reply_sock,replybuf,sVar8 + 1,0,(sockaddr *)client->ai_addr,
                                  client->ai_addrlen);
                  freeaddrinfo((addrinfo *)res);
                  if (sVar10 < 0) {
                    if ((opt_debug != false) &&
                       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))
                       ) {
                      piVar4 = __errno_location();
                      pcVar5 = strerror(*piVar4);
                      snprintf(tmp42,0x800,"API mcast send reply failed (%s) (%d)",pcVar5,reply_sock
                              );
                      _applog(7,tmp42,false);
                    }
                  }
                  else if ((opt_debug != false) &&
                          (((use_syslog != false || (opt_log_output != false)) ||
                           (6 < opt_log_level)))) {
                    snprintf(tmp42,0x800,"API mcast send reply (%s) succeeded (%d) (%d)",replybuf,
                             sVar10,reply_sock);
                    _applog(7,tmp42,false);
                  }
                  close(reply_sock);
                }
              }
              else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level))
              {
                snprintf(tmp42,0x800,"Invalid client address %s",connectaddr,pcVar5);
                _applog(3,tmp42,false);
              }
            }
          }
          else if ((opt_debug != false) &&
                  (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_API_mcast_request_was_no_good_0006e1f4[0];
            tmp42[1] = s_API_mcast_request_was_no_good_0006e1f4[1];
            tmp42[2] = s_API_mcast_request_was_no_good_0006e1f4[2];
            tmp42[3] = s_API_mcast_request_was_no_good_0006e1f4[3];
            tmp42[4] = s_API_mcast_request_was_no_good_0006e1f4[4];
            tmp42[5] = s_API_mcast_request_was_no_good_0006e1f4[5];
            tmp42[6] = s_API_mcast_request_was_no_good_0006e1f4[6];
            tmp42[7] = s_API_mcast_request_was_no_good_0006e1f4[7];
            tmp42[8] = s_API_mcast_request_was_no_good_0006e1f4[8];
            tmp42[9] = s_API_mcast_request_was_no_good_0006e1f4[9];
            tmp42[10] = s_API_mcast_request_was_no_good_0006e1f4[10];
            tmp42[11] = s_API_mcast_request_was_no_good_0006e1f4[11];
            tmp42[12] = s_API_mcast_request_was_no_good_0006e1f4[12];
            tmp42[13] = s_API_mcast_request_was_no_good_0006e1f4[13];
            tmp42[14] = s_API_mcast_request_was_no_good_0006e1f4[14];
            tmp42[15] = s_API_mcast_request_was_no_good_0006e1f4[15];
            tmp42[16] = s_API_mcast_request_was_no_good_0006e1f4[16];
            tmp42[17] = s_API_mcast_request_was_no_good_0006e1f4[17];
            tmp42[18] = s_API_mcast_request_was_no_good_0006e1f4[18];
            tmp42[19] = s_API_mcast_request_was_no_good_0006e1f4[19];
            tmp42[20] = s_API_mcast_request_was_no_good_0006e1f4[20];
            tmp42[21] = s_API_mcast_request_was_no_good_0006e1f4[21];
            tmp42[22] = s_API_mcast_request_was_no_good_0006e1f4[22];
            tmp42[23] = s_API_mcast_request_was_no_good_0006e1f4[23];
            tmp42[24] = s_API_mcast_request_was_no_good_0006e1f4[24];
            tmp42[25] = s_API_mcast_request_was_no_good_0006e1f4[25];
            tmp42[26] = s_API_mcast_request_was_no_good_0006e1f4[26];
            tmp42[27] = s_API_mcast_request_was_no_good_0006e1f4[27];
            tmp42[28] = (char)(short)ram0x0006e210;
            tmp42[29] = (char)((ushort)(short)ram0x0006e210 >> 8);
            _applog(7,tmp42,false);
          }
        }
      } while( true );
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"API mcast bind to port %d failed (%s)%s",opt_api_mcast_port,binderror,
               MUNAVAILABLE);
      _applog(3,tmp42,false);
    }
  }
die:
  close(mcast_sock);
  return;
}

