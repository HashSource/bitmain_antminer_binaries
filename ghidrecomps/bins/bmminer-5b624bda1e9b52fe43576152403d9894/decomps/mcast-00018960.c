
/* WARNING: Unknown calling convention */

void mcast(void)

{
  undefined4 *puVar1;
  char **ppcVar2;
  char *pcVar3;
  undefined4 *puVar4;
  _Bool _Var5;
  _Bool addrok;
  int reply_port;
  int iVar6;
  int iVar7;
  time_t tVar8;
  size_t sVar9;
  uint __n;
  size_t expect_code_len;
  char *pcVar10;
  char *expect_code;
  uint uVar11;
  ssize_t rep;
  time_t tVar12;
  long lVar13;
  ssize_t sVar14;
  int *piVar15;
  char *pcVar16;
  sockaddr *psVar17;
  addrinfo *host;
  undefined4 uVar18;
  addrinfo *paVar19;
  time_t bindstart;
  socklen_t *came_from_siz;
  int count;
  char *binderror;
  addrinfo *client;
  int local_1120;
  char *local_111c;
  char group;
  socklen_t local_1110;
  char *connectaddr;
  addrinfo *res;
  int optval;
  char expect [9];
  char port_s [10];
  char came_from_port [10];
  ipv6_mreq grp_1;
  addrinfo hints;
  sockaddr_storage came_from;
  char buf [1024];
  char replybuf [1024];
  char tmp42 [2048];
  
  puVar1 = DAT_00018c24;
  expect._0_4_ = *DAT_00018c20;
  expect._4_4_ = DAT_00018c20[1];
  expect[8] = (char)DAT_00018c20[2];
  sprintf(port_s,DAT_00018c28,*DAT_00018c24);
  hints.ai_flags = 0;
  hints.ai_family = 0;
  hints.ai_socktype = 0;
  hints.ai_protocol = 0;
  hints.ai_addrlen = 0;
  hints.ai_addr = (sockaddr *)0x0;
  hints.ai_canonname = (char *)0x0;
  hints.ai_next = (addrinfo *)0x0;
  iVar6 = getaddrinfo(*DAT_00018c2c,port_s,(addrinfo *)&hints,(addrinfo **)&res);
  if (iVar6 == 0) {
    paVar19 = res;
    if (res == (addrinfo *)0x0) goto LAB_00018c5e;
LAB_000189cc:
    do {
      iVar6 = socket(res->ai_family,2,0);
      if (0 < iVar6) goto LAB_000189dc;
      paVar19 = paVar19->ai_next;
    } while (paVar19 != (addrinfo *)0x0);
    if (iVar6 == -1) goto LAB_00018c5e;
  }
  else {
    tmp42._0_4_ = *DAT_000190fc;
    tmp42._4_4_ = DAT_000190fc[1];
    tmp42._8_4_ = DAT_000190fc[2];
    tmp42._12_4_ = DAT_000190fc[3];
    tmp42._16_4_ = DAT_000190fc[4];
    tmp42._20_4_ = DAT_000190fc[5];
    tmp42._24_4_ = DAT_000190fc[6];
    tmp42[28] = (char)(short)DAT_000190fc[7];
    tmp42[29] = (char)((ushort)(short)DAT_000190fc[7] >> 8);
    _applog(3,tmp42,true);
    _quit(1);
    paVar19 = res;
    if (res != (addrinfo *)0x0) goto LAB_000189cc;
LAB_00018c5e:
    puVar4 = DAT_00018e5c;
    freeaddrinfo((addrinfo *)res);
    paVar19 = (addrinfo *)0x0;
    iVar6 = -1;
    tmp42._0_4_ = *puVar4;
    tmp42._4_4_ = puVar4[1];
    tmp42._8_4_ = puVar4[2];
    tmp42._12_4_ = puVar4[3];
    tmp42._16_4_ = puVar4[4];
    tmp42._20_4_ = puVar4[5];
    tmp42._24_4_ = puVar4[6];
    tmp42._28_4_ = puVar4[7];
    _applog(3,tmp42,true);
    _quit(1);
  }
LAB_000189dc:
  optval = 1;
  iVar7 = setsockopt(iVar6,1,2,&optval,4);
  if (iVar7 < 0) {
    if (((*DAT_00018e60 == '\0') && (*DAT_00018e64 == '\0')) && (*DAT_00018e68 < 3)) goto die;
    piVar15 = __errno_location();
    pcVar16 = strerror(*piVar15);
    pcVar10 = DAT_00018e70;
    uVar18 = DAT_00018e6c;
  }
  else {
    tVar8 = time((time_t *)0x0);
    while (iVar7 = bind(iVar6,(sockaddr *)paVar19->ai_addr,paVar19->ai_addrlen), iVar7 < 0) {
      piVar15 = __errno_location();
      pcVar10 = strerror(*piVar15);
      tVar12 = time((time_t *)0x0);
      if (0x3d < tVar12 - tVar8) {
        if (((*DAT_00019100 != '\0') || (*DAT_00019104 != '\0')) || (2 < *DAT_00019114)) {
          snprintf(tmp42,0x800,DAT_00019118,*puVar1,pcVar10,DAT_00019108);
          _applog(3,tmp42,false);
        }
        goto die;
      }
      cgsleep_ms(30000);
    }
    if (paVar19->ai_family == 2) {
      replybuf[4] = '\0';
      replybuf[5] = '\0';
      replybuf[6] = '\0';
      replybuf[7] = '\0';
      replybuf._0_4_ = *(undefined4 *)(paVar19->ai_addr->sa_data + 2);
      iVar7 = setsockopt(iVar6,0,0x23,replybuf,8);
    }
    else {
      if (paVar19->ai_family != 10) goto LAB_00018a24;
      psVar17 = paVar19->ai_addr;
      grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[0] = *(undefined4 *)(psVar17->sa_data + 6);
      grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[1] = *(undefined4 *)(psVar17->sa_data + 10);
      grp_1.ipv6mr_multiaddr.__in6_u._8_2_ = psVar17[1].sa_family;
      grp_1.ipv6mr_multiaddr.__in6_u._10_1_ = psVar17[1].sa_data[0];
      grp_1.ipv6mr_multiaddr.__in6_u._11_1_ = psVar17[1].sa_data[1];
      grp_1.ipv6mr_multiaddr.__in6_u.__u6_addr32[3] = *(undefined4 *)(psVar17[1].sa_data + 2);
      grp_1.ipv6mr_interface = 0;
      iVar7 = setsockopt(iVar6,0x29,0x14,&grp_1,0x14);
    }
    if (-1 < iVar7) {
LAB_00018a24:
      ppcVar2 = DAT_00018c30;
      local_111c = replybuf;
      freeaddrinfo((addrinfo *)res);
      pcVar16 = *ppcVar2;
      sVar9 = strlen(pcVar16);
      __n = sVar9 + 9;
      pcVar10 = (char *)malloc(sVar9 + 10);
      if (pcVar10 == (char *)0x0) {
        tmp42._0_4_ = *DAT_00019110;
        tmp42._4_4_ = DAT_00019110[1];
        tmp42._8_4_ = DAT_00019110[2];
        tmp42._12_4_ = DAT_00019110[3];
        tmp42._16_4_ = DAT_00019110[4];
        tmp42._20_4_ = DAT_00019110[5];
        tmp42._24_4_ = DAT_00019110[6];
        tmp42._28_4_ = DAT_00019110[7];
        tmp42._32_2_ = (undefined2)DAT_00019110[8];
        tmp42[34] = (char)((uint)DAT_00019110[8] >> 0x10);
        _applog(3,tmp42,true);
        _quit(1);
        pcVar16 = *ppcVar2;
      }
      pcVar3 = DAT_00018c44;
      count = 0;
      local_1120 = -1;
      snprintf(pcVar10,sVar9 + 10,DAT_00018c34,expect,pcVar16);
LAB_00018a74:
      do {
        while( true ) {
          while( true ) {
            while( true ) {
              do {
                while( true ) {
                  cgsleep_ms(1000);
                  local_1110 = 0x80;
                  count = count + 1;
                  uVar11 = recvfrom(iVar6,buf,0x3ff,0,(sockaddr *)&came_from,&local_1110);
                  if (-1 < (int)uVar11) break;
                  if ((*pcVar3 != '\0') &&
                     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level))))
                  {
                    piVar15 = __errno_location();
                    pcVar16 = strerror(*piVar15);
                    snprintf(tmp42,0x800,DAT_00018e74,count,pcVar16,iVar6);
                    _applog(7,tmp42,false);
                  }
                }
                _Var5 = check_connect(&came_from,&connectaddr,&group);
                if ((*pcVar3 != '\0') &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  uVar18 = DAT_00018c48;
                  if (_Var5) {
                    uVar18 = DAT_00018c38;
                  }
                  snprintf(tmp42,0x800,DAT_00018c3c,connectaddr,uVar18);
                  _applog(7,tmp42,false);
                }
              } while (!_Var5);
              buf[uVar11] = '\0';
              if ((uVar11 != 0) && (came_from.__ss_padding[uVar11 + 0x77] == '\n')) {
                uVar11 = uVar11 - 1;
                buf[uVar11] = '\0';
              }
              getnameinfo((sockaddr *)&came_from,local_1110,(char *)0x0,0,came_from_port,10,1);
              if ((*pcVar3 != '\0') &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,DAT_00018c40,uVar11,buf,connectaddr,came_from_port);
                _applog(7,tmp42,false);
              }
              if ((__n < uVar11) && (iVar7 = memcmp(buf,pcVar10,__n), iVar7 == 0)) break;
              if ((*pcVar3 != '\0') &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                tmp42._0_4_ = *DAT_00018c4c;
                tmp42._4_4_ = DAT_00018c4c[1];
                tmp42._8_4_ = DAT_00018c4c[2];
                tmp42._12_4_ = DAT_00018c4c[3];
                tmp42._16_4_ = DAT_00018c4c[4];
                tmp42._20_4_ = DAT_00018c4c[5];
                tmp42._24_4_ = DAT_00018c4c[6];
                tmp42[28] = (char)(short)DAT_00018c4c[7];
                tmp42[29] = (char)((ushort)(short)DAT_00018c4c[7] >> 8);
                _applog(7,tmp42,false);
              }
            }
            pcVar16 = buf + __n;
            lVar13 = strtol(pcVar16,(char **)0x0,10);
            if (lVar13 - 1U < 0xffff) break;
            if ((*pcVar3 != '\0') &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,DAT_00018e78,pcVar16);
              _applog(7,tmp42,false);
            }
          }
          if ((*pcVar3 != '\0') &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,DAT_00018e7c,pcVar16,lVar13);
            _applog(7,tmp42,false);
          }
          iVar7 = getaddrinfo(connectaddr,pcVar16,(addrinfo *)&hints,(addrinfo **)&res);
          paVar19 = res;
          if (iVar7 != 0) goto code_r0x00018dee;
          if ((res != (addrinfo *)0x0) && (local_1120 = socket(res->ai_family,2,0), iVar6 < 1)) {
            while (paVar19 = paVar19->ai_next, paVar19 != (addrinfo *)0x0) {
              local_1120 = socket(res->ai_family,2,0);
            }
            paVar19 = (addrinfo *)0x0;
          }
          if (local_1120 == -1) break;
          snprintf(local_111c,0x400,DAT_000190ec,opt_api_port,opt_api_mcast_des);
          sVar9 = strlen(local_111c);
          sVar14 = sendto(local_1120,local_111c,sVar9 + 1,0,(sockaddr *)paVar19->ai_addr,
                          paVar19->ai_addrlen);
          freeaddrinfo((addrinfo *)res);
          if (sVar14 < 0) {
            if ((*pcVar3 != '\0') &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              piVar15 = __errno_location();
              pcVar16 = strerror(*piVar15);
              snprintf(tmp42,0x800,DAT_000190f8,pcVar16,local_1120);
              _applog(7,tmp42,false);
            }
          }
          else if ((*pcVar3 != '\0') &&
                  (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,DAT_000190f0,local_111c,sVar14,local_1120);
            _applog(7,tmp42,false);
          }
          close(local_1120);
        }
        freeaddrinfo((addrinfo *)res);
        pcVar16 = DAT_000190f4;
      } while (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3));
      goto LAB_00018e1e;
    }
    if (((*DAT_00019100 == '\0') && (*DAT_00019104 == '\0')) && (*DAT_00019114 < 3)) goto die;
    piVar15 = __errno_location();
    pcVar16 = strerror(*piVar15);
    pcVar10 = DAT_0001910c;
    uVar18 = DAT_00019108;
  }
  snprintf(tmp42,0x800,pcVar10,pcVar16,uVar18);
  _applog(3,tmp42,false);
die:
  close(iVar6);
  return;
code_r0x00018dee:
  pcVar16 = DAT_00018e80;
  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
LAB_00018e1e:
    snprintf(tmp42,0x800,pcVar16,connectaddr);
    _applog(3,tmp42,false);
  }
  goto LAB_00018a74;
}

