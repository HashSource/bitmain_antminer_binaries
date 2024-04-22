
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined setup_stratum_socket(int param_1)

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
  undefined local_a2c [4];
  undefined local_a28;
  undefined auStack_a27 [119];
  undefined4 auStack_9b0 [98];
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 local_810;
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x2c0));
  uVar9 = DAT_00049294;
  if (iVar2 != 0) {
    piVar8 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar8,
             "util.c",uVar9,0xb56);
    _applog(3,&local_828,1);
    _quit(1);
  }
  *(undefined *)(param_1 + 0x281) = 0;
  if (*(int *)(param_1 + 0x24c) != 0) {
    close(*(int *)(param_1 + 0x24c));
  }
  *(undefined4 *)(param_1 + 0x24c) = 0;
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x2c0));
  uVar9 = DAT_00049294;
  if (iVar2 != 0) {
    piVar8 = __errno_location();
    snprintf((char *)&local_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar8,
             "util.c",uVar9,0xb5b);
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
      *(undefined *)(param_1 + 99) = 1;
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
        uVar3 = s_Failed_socket_000677ac._0_4_;
        uVar4 = s_Failed_socket_000677ac._4_4_;
        uVar13 = s_Failed_socket_000677ac._8_4_;
        uVar9 = ram0x000677b8;
LAB_00048a94:
        *puVar5 = uVar3;
        puVar5[1] = uVar4;
        puVar5[2] = uVar13;
        *(short *)(puVar5 + 3) = (short)uVar9;
        _applog(7,&local_828,0);
      }
      goto LAB_00048aa2;
    }
    uVar4 = fcntl(uVar3,3,0);
    fcntl(uVar3,4,uVar4 | 0x800);
    iVar2 = connect(uVar3,paVar1->ai_addr,paVar1->ai_addrlen);
    if (iVar2 != -1) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        local_828._0_1_ = s_Succeeded_immediate_connect_0006780c[0];
        local_828._1_1_ = s_Succeeded_immediate_connect_0006780c[1];
        local_828._2_1_ = s_Succeeded_immediate_connect_0006780c[2];
        local_828._3_1_ = s_Succeeded_immediate_connect_0006780c[3];
        uStack_824._0_1_ = s_Succeeded_immediate_connect_0006780c[4];
        uStack_824._1_1_ = s_Succeeded_immediate_connect_0006780c[5];
        uStack_824._2_1_ = s_Succeeded_immediate_connect_0006780c[6];
        uStack_824._3_1_ = s_Succeeded_immediate_connect_0006780c[7];
        uStack_820._0_1_ = s_Succeeded_immediate_connect_0006780c[8];
        uStack_820._1_1_ = s_Succeeded_immediate_connect_0006780c[9];
        uStack_820._2_1_ = s_Succeeded_immediate_connect_0006780c[10];
        uStack_820._3_1_ = s_Succeeded_immediate_connect_0006780c[11];
        uStack_81c._0_1_ = s_Succeeded_immediate_connect_0006780c[12];
        uStack_81c._1_1_ = s_Succeeded_immediate_connect_0006780c[13];
        uStack_81c._2_1_ = s_Succeeded_immediate_connect_0006780c[14];
        uStack_81c._3_1_ = s_Succeeded_immediate_connect_0006780c[15];
        local_818._0_1_ = s_Succeeded_immediate_connect_0006780c[16];
        local_818._1_1_ = s_Succeeded_immediate_connect_0006780c[17];
        local_818._2_1_ = s_Succeeded_immediate_connect_0006780c[18];
        local_818._3_1_ = s_Succeeded_immediate_connect_0006780c[19];
        uStack_814._0_1_ = s_Succeeded_immediate_connect_0006780c[20];
        uStack_814._1_1_ = s_Succeeded_immediate_connect_0006780c[21];
        uStack_814._2_1_ = s_Succeeded_immediate_connect_0006780c[22];
        uStack_814._3_1_ = s_Succeeded_immediate_connect_0006780c[23];
        local_810._0_1_ = s_Succeeded_immediate_connect_0006780c[24];
        local_810._1_1_ = s_Succeeded_immediate_connect_0006780c[25];
        local_810._2_1_ = s_Succeeded_immediate_connect_0006780c[26];
        local_810._3_1_ = s_Succeeded_immediate_connect_0006780c[27];
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
        local_a2c = (undefined  [4])CONCAT13(local_a2c[3],0x105);
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
           (((uint)local_a2c >> 0x10 & 0xff) == (local_828 & 0xff))) {
          __s = *(char **)(param_1 + 600);
          local_a2c = (undefined  [4])0x3000105;
          sVar10 = strlen(__s);
          if (0xfe < (int)sVar10) {
            sVar10 = 0xff;
          }
          local_a28 = (undefined)sVar10;
          _cg_memcpy(auStack_a27,__s,sVar10,"util.c",DAT_00049298,0xac1);
          lVar11 = strtol(*(char **)(param_1 + 0x248),(char **)0x0,10);
          auStack_a27[sVar10 + 1] = (char)lVar11;
          auStack_a27[sVar10] = (char)((uint)lVar11 >> 8);
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
                  uVar9 = _cgcalloc(0x2000,1,"util.c",DAT_00049294,0xbe4);
                  *(undefined4 *)(param_1 + 0x250) = uVar9;
                  *(undefined4 *)(param_1 + 0x254) = 0x2000;
                }
                *(uint *)(param_1 + 0x24c) = uVar3;
                local_a2c = (undefined  [4])0x2d;
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
        s_Failed_socket_000677ac[0] = (char)s_Failed_socket_000677ac._0_4_;
        s_Failed_socket_000677ac[1] = SUB41(s_Failed_socket_000677ac._0_4_,1);
        s_Failed_socket_000677ac[2] = SUB41(s_Failed_socket_000677ac._0_4_,2);
        s_Failed_socket_000677ac[3] = SUB41(s_Failed_socket_000677ac._0_4_,3);
        s_Failed_socket_000677ac[4] = (char)s_Failed_socket_000677ac._4_4_;
        s_Failed_socket_000677ac[5] = SUB41(s_Failed_socket_000677ac._4_4_,1);
        s_Failed_socket_000677ac[6] = SUB41(s_Failed_socket_000677ac._4_4_,2);
        s_Failed_socket_000677ac[7] = SUB41(s_Failed_socket_000677ac._4_4_,3);
        s_Failed_socket_000677ac[8] = (char)s_Failed_socket_000677ac._8_4_;
        s_Failed_socket_000677ac[9] = SUB41(s_Failed_socket_000677ac._8_4_,1);
        s_Failed_socket_000677ac[10] = SUB41(s_Failed_socket_000677ac._8_4_,2);
        s_Failed_socket_000677ac[11] = SUB41(s_Failed_socket_000677ac._8_4_,3);
        s_Failed_sock_connect_000677bc[0] = (char)s_Failed_sock_connect_000677bc._0_4_;
        s_Failed_sock_connect_000677bc[1] = SUB41(s_Failed_sock_connect_000677bc._0_4_,1);
        s_Failed_sock_connect_000677bc[2] = SUB41(s_Failed_sock_connect_000677bc._0_4_,2);
        s_Failed_sock_connect_000677bc[3] = SUB41(s_Failed_sock_connect_000677bc._0_4_,3);
        s_Failed_sock_connect_000677bc[4] = (char)s_Failed_sock_connect_000677bc._4_4_;
        s_Failed_sock_connect_000677bc[5] = SUB41(s_Failed_sock_connect_000677bc._4_4_,1);
        s_Failed_sock_connect_000677bc[6] = SUB41(s_Failed_sock_connect_000677bc._4_4_,2);
        s_Failed_sock_connect_000677bc[7] = SUB41(s_Failed_sock_connect_000677bc._4_4_,3);
        s_Failed_sock_connect_000677bc[8] = (char)s_Failed_sock_connect_000677bc._8_4_;
        s_Failed_sock_connect_000677bc[9] = SUB41(s_Failed_sock_connect_000677bc._8_4_,1);
        s_Failed_sock_connect_000677bc[10] = SUB41(s_Failed_sock_connect_000677bc._8_4_,2);
        s_Failed_sock_connect_000677bc[11] = SUB41(s_Failed_sock_connect_000677bc._8_4_,3);
        s_Failed_sock_connect_000677bc[12] = (char)s_Failed_sock_connect_000677bc._12_4_;
        s_Failed_sock_connect_000677bc[13] = SUB41(s_Failed_sock_connect_000677bc._12_4_,1);
        s_Failed_sock_connect_000677bc[14] = SUB41(s_Failed_sock_connect_000677bc._12_4_,2);
        s_Failed_sock_connect_000677bc[15] = SUB41(s_Failed_sock_connect_000677bc._12_4_,3);
        s_Failed_sock_connect_000677bc[16] = (char)s_Failed_sock_connect_000677bc._16_4_;
        s_Failed_sock_connect_000677bc[17] = SUB41(s_Failed_sock_connect_000677bc._16_4_,1);
        s_Failed_sock_connect_000677bc[18] = SUB41(s_Failed_sock_connect_000677bc._16_4_,2);
        s_Failed_sock_connect_000677bc[19] = SUB41(s_Failed_sock_connect_000677bc._16_4_,3);
        s_Succeeded_delayed_connect_000677d0[0] = (char)s_Succeeded_delayed_connect_000677d0._0_4_;
        s_Succeeded_delayed_connect_000677d0[1] =
             SUB41(s_Succeeded_delayed_connect_000677d0._0_4_,1);
        s_Succeeded_delayed_connect_000677d0[2] =
             SUB41(s_Succeeded_delayed_connect_000677d0._0_4_,2);
        s_Succeeded_delayed_connect_000677d0[3] =
             SUB41(s_Succeeded_delayed_connect_000677d0._0_4_,3);
        s_Succeeded_delayed_connect_000677d0[4] = (char)s_Succeeded_delayed_connect_000677d0._4_4_;
        s_Succeeded_delayed_connect_000677d0[5] =
             SUB41(s_Succeeded_delayed_connect_000677d0._4_4_,1);
        s_Succeeded_delayed_connect_000677d0[6] =
             SUB41(s_Succeeded_delayed_connect_000677d0._4_4_,2);
        s_Succeeded_delayed_connect_000677d0[7] =
             SUB41(s_Succeeded_delayed_connect_000677d0._4_4_,3);
        s_Succeeded_delayed_connect_000677d0[8] = (char)s_Succeeded_delayed_connect_000677d0._8_4_;
        s_Succeeded_delayed_connect_000677d0[9] =
             SUB41(s_Succeeded_delayed_connect_000677d0._8_4_,1);
        s_Succeeded_delayed_connect_000677d0[10] =
             SUB41(s_Succeeded_delayed_connect_000677d0._8_4_,2);
        s_Succeeded_delayed_connect_000677d0[11] =
             SUB41(s_Succeeded_delayed_connect_000677d0._8_4_,3);
        s_Succeeded_delayed_connect_000677d0[12] = (char)s_Succeeded_delayed_connect_000677d0._12_4_
        ;
        s_Succeeded_delayed_connect_000677d0[13] =
             SUB41(s_Succeeded_delayed_connect_000677d0._12_4_,1);
        s_Succeeded_delayed_connect_000677d0[14] =
             SUB41(s_Succeeded_delayed_connect_000677d0._12_4_,2);
        s_Succeeded_delayed_connect_000677d0[15] =
             SUB41(s_Succeeded_delayed_connect_000677d0._12_4_,3);
        s_Succeeded_delayed_connect_000677d0[16] = (char)s_Succeeded_delayed_connect_000677d0._16_4_
        ;
        s_Succeeded_delayed_connect_000677d0[17] =
             SUB41(s_Succeeded_delayed_connect_000677d0._16_4_,1);
        s_Succeeded_delayed_connect_000677d0[18] =
             SUB41(s_Succeeded_delayed_connect_000677d0._16_4_,2);
        s_Succeeded_delayed_connect_000677d0[19] =
             SUB41(s_Succeeded_delayed_connect_000677d0._16_4_,3);
        s_Succeeded_delayed_connect_000677d0[20] = (char)s_Succeeded_delayed_connect_000677d0._20_4_
        ;
        s_Succeeded_delayed_connect_000677d0[21] =
             SUB41(s_Succeeded_delayed_connect_000677d0._20_4_,1);
        s_Succeeded_delayed_connect_000677d0[22] =
             SUB41(s_Succeeded_delayed_connect_000677d0._20_4_,2);
        s_Succeeded_delayed_connect_000677d0[23] =
             SUB41(s_Succeeded_delayed_connect_000677d0._20_4_,3);
        s_Select_timeout_failed_connect_000677ec[0] =
             (char)s_Select_timeout_failed_connect_000677ec._0_4_;
        s_Select_timeout_failed_connect_000677ec[1] =
             SUB41(s_Select_timeout_failed_connect_000677ec._0_4_,1);
        s_Select_timeout_failed_connect_000677ec[2] =
             SUB41(s_Select_timeout_failed_connect_000677ec._0_4_,2);
        s_Select_timeout_failed_connect_000677ec[3] =
             SUB41(s_Select_timeout_failed_connect_000677ec._0_4_,3);
        s_Select_timeout_failed_connect_000677ec[4] =
             (char)s_Select_timeout_failed_connect_000677ec._4_4_;
        s_Select_timeout_failed_connect_000677ec[5] =
             SUB41(s_Select_timeout_failed_connect_000677ec._4_4_,1);
        s_Select_timeout_failed_connect_000677ec[6] =
             SUB41(s_Select_timeout_failed_connect_000677ec._4_4_,2);
        s_Select_timeout_failed_connect_000677ec[7] =
             SUB41(s_Select_timeout_failed_connect_000677ec._4_4_,3);
        s_Select_timeout_failed_connect_000677ec[8] =
             (char)s_Select_timeout_failed_connect_000677ec._8_4_;
        s_Select_timeout_failed_connect_000677ec[9] =
             SUB41(s_Select_timeout_failed_connect_000677ec._8_4_,1);
        s_Select_timeout_failed_connect_000677ec[10] =
             SUB41(s_Select_timeout_failed_connect_000677ec._8_4_,2);
        s_Select_timeout_failed_connect_000677ec[11] =
             SUB41(s_Select_timeout_failed_connect_000677ec._8_4_,3);
        s_Select_timeout_failed_connect_000677ec[12] =
             (char)s_Select_timeout_failed_connect_000677ec._12_4_;
        s_Select_timeout_failed_connect_000677ec[13] =
             SUB41(s_Select_timeout_failed_connect_000677ec._12_4_,1);
        s_Select_timeout_failed_connect_000677ec[14] =
             SUB41(s_Select_timeout_failed_connect_000677ec._12_4_,2);
        s_Select_timeout_failed_connect_000677ec[15] =
             SUB41(s_Select_timeout_failed_connect_000677ec._12_4_,3);
        s_Select_timeout_failed_connect_000677ec[16] =
             (char)s_Select_timeout_failed_connect_000677ec._16_4_;
        s_Select_timeout_failed_connect_000677ec[17] =
             SUB41(s_Select_timeout_failed_connect_000677ec._16_4_,1);
        s_Select_timeout_failed_connect_000677ec[18] =
             SUB41(s_Select_timeout_failed_connect_000677ec._16_4_,2);
        s_Select_timeout_failed_connect_000677ec[19] =
             SUB41(s_Select_timeout_failed_connect_000677ec._16_4_,3);
        s_Select_timeout_failed_connect_000677ec[20] =
             (char)s_Select_timeout_failed_connect_000677ec._20_4_;
        s_Select_timeout_failed_connect_000677ec[21] =
             SUB41(s_Select_timeout_failed_connect_000677ec._20_4_,1);
        s_Select_timeout_failed_connect_000677ec[22] =
             SUB41(s_Select_timeout_failed_connect_000677ec._20_4_,2);
        s_Select_timeout_failed_connect_000677ec[23] =
             SUB41(s_Select_timeout_failed_connect_000677ec._20_4_,3);
        s_Select_timeout_failed_connect_000677ec[24] =
             (char)s_Select_timeout_failed_connect_000677ec._24_4_;
        s_Select_timeout_failed_connect_000677ec[25] =
             SUB41(s_Select_timeout_failed_connect_000677ec._24_4_,1);
        s_Select_timeout_failed_connect_000677ec[26] =
             SUB41(s_Select_timeout_failed_connect_000677ec._24_4_,2);
        s_Select_timeout_failed_connect_000677ec[27] =
             SUB41(s_Select_timeout_failed_connect_000677ec._24_4_,3);
        s_Succeeded_immediate_connect_0006780c[0] =
             (char)s_Succeeded_immediate_connect_0006780c._0_4_;
        s_Succeeded_immediate_connect_0006780c[1] =
             SUB41(s_Succeeded_immediate_connect_0006780c._0_4_,1);
        s_Succeeded_immediate_connect_0006780c[2] =
             SUB41(s_Succeeded_immediate_connect_0006780c._0_4_,2);
        s_Succeeded_immediate_connect_0006780c[3] =
             SUB41(s_Succeeded_immediate_connect_0006780c._0_4_,3);
        s_Succeeded_immediate_connect_0006780c[4] =
             (char)s_Succeeded_immediate_connect_0006780c._4_4_;
        s_Succeeded_immediate_connect_0006780c[5] =
             SUB41(s_Succeeded_immediate_connect_0006780c._4_4_,1);
        s_Succeeded_immediate_connect_0006780c[6] =
             SUB41(s_Succeeded_immediate_connect_0006780c._4_4_,2);
        s_Succeeded_immediate_connect_0006780c[7] =
             SUB41(s_Succeeded_immediate_connect_0006780c._4_4_,3);
        s_Succeeded_immediate_connect_0006780c[8] =
             (char)s_Succeeded_immediate_connect_0006780c._8_4_;
        s_Succeeded_immediate_connect_0006780c[9] =
             SUB41(s_Succeeded_immediate_connect_0006780c._8_4_,1);
        s_Succeeded_immediate_connect_0006780c[10] =
             SUB41(s_Succeeded_immediate_connect_0006780c._8_4_,2);
        s_Succeeded_immediate_connect_0006780c[11] =
             SUB41(s_Succeeded_immediate_connect_0006780c._8_4_,3);
        s_Succeeded_immediate_connect_0006780c[12] =
             (char)s_Succeeded_immediate_connect_0006780c._12_4_;
        s_Succeeded_immediate_connect_0006780c[13] =
             SUB41(s_Succeeded_immediate_connect_0006780c._12_4_,1);
        s_Succeeded_immediate_connect_0006780c[14] =
             SUB41(s_Succeeded_immediate_connect_0006780c._12_4_,2);
        s_Succeeded_immediate_connect_0006780c[15] =
             SUB41(s_Succeeded_immediate_connect_0006780c._12_4_,3);
        s_Succeeded_immediate_connect_0006780c[16] =
             (char)s_Succeeded_immediate_connect_0006780c._16_4_;
        s_Succeeded_immediate_connect_0006780c[17] =
             SUB41(s_Succeeded_immediate_connect_0006780c._16_4_,1);
        s_Succeeded_immediate_connect_0006780c[18] =
             SUB41(s_Succeeded_immediate_connect_0006780c._16_4_,2);
        s_Succeeded_immediate_connect_0006780c[19] =
             SUB41(s_Succeeded_immediate_connect_0006780c._16_4_,3);
        s_Succeeded_immediate_connect_0006780c[20] =
             (char)s_Succeeded_immediate_connect_0006780c._20_4_;
        s_Succeeded_immediate_connect_0006780c[21] =
             SUB41(s_Succeeded_immediate_connect_0006780c._20_4_,1);
        s_Succeeded_immediate_connect_0006780c[22] =
             SUB41(s_Succeeded_immediate_connect_0006780c._20_4_,2);
        s_Succeeded_immediate_connect_0006780c[23] =
             SUB41(s_Succeeded_immediate_connect_0006780c._20_4_,3);
        s_Succeeded_immediate_connect_0006780c[24] =
             (char)s_Succeeded_immediate_connect_0006780c._24_4_;
        s_Succeeded_immediate_connect_0006780c[25] =
             SUB41(s_Succeeded_immediate_connect_0006780c._24_4_,1);
        s_Succeeded_immediate_connect_0006780c[26] =
             SUB41(s_Succeeded_immediate_connect_0006780c._24_4_,2);
        s_Succeeded_immediate_connect_0006780c[27] =
             SUB41(s_Succeeded_immediate_connect_0006780c._24_4_,3);
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
        } while ((addrinfo **)auStack_9b0 != ppaVar12);
        ((fd_set *)local_a2c)->fds_bits[iVar2] = ((fd_set *)local_a2c)->fds_bits[iVar2] | uVar4;
        iVar6 = select(uVar3 + 1,(fd_set *)0x0,(fd_set *)local_a2c,(fd_set *)0x0,&local_a54);
        if (0 < iVar6) break;
        if ((iVar6 == 0) || (*puVar5 != 4)) goto LAB_00048c50;
      }
      if ((uVar4 & ((fd_set *)local_a2c)->fds_bits[iVar2]) != 0) {
        local_a5c = 4;
        iVar2 = getsockopt(uVar3,1,4,&local_a58,&local_a5c);
        if ((iVar2 == 0) && (local_a58 == 0)) {
          if ((opt_debug != '\0') &&
             (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
            local_828._0_1_ = s_Succeeded_delayed_connect_000677d0[0];
            local_828._1_1_ = s_Succeeded_delayed_connect_000677d0[1];
            local_828._2_1_ = s_Succeeded_delayed_connect_000677d0[2];
            local_828._3_1_ = s_Succeeded_delayed_connect_000677d0[3];
            uStack_824._0_1_ = s_Succeeded_delayed_connect_000677d0[4];
            uStack_824._1_1_ = s_Succeeded_delayed_connect_000677d0[5];
            uStack_824._2_1_ = s_Succeeded_delayed_connect_000677d0[6];
            uStack_824._3_1_ = s_Succeeded_delayed_connect_000677d0[7];
            uStack_820._0_1_ = s_Succeeded_delayed_connect_000677d0[8];
            uStack_820._1_1_ = s_Succeeded_delayed_connect_000677d0[9];
            uStack_820._2_1_ = s_Succeeded_delayed_connect_000677d0[10];
            uStack_820._3_1_ = s_Succeeded_delayed_connect_000677d0[11];
            uStack_81c._0_1_ = s_Succeeded_delayed_connect_000677d0[12];
            uStack_81c._1_1_ = s_Succeeded_delayed_connect_000677d0[13];
            uStack_81c._2_1_ = s_Succeeded_delayed_connect_000677d0[14];
            uStack_81c._3_1_ = s_Succeeded_delayed_connect_000677d0[15];
            local_818._0_1_ = s_Succeeded_delayed_connect_000677d0[16];
            local_818._1_1_ = s_Succeeded_delayed_connect_000677d0[17];
            local_818._2_1_ = s_Succeeded_delayed_connect_000677d0[18];
            local_818._3_1_ = s_Succeeded_delayed_connect_000677d0[19];
            uStack_814._0_1_ = s_Succeeded_delayed_connect_000677d0[20];
            uStack_814._1_1_ = s_Succeeded_delayed_connect_000677d0[21];
            uStack_814._2_1_ = s_Succeeded_delayed_connect_000677d0[22];
            uStack_814._3_1_ = s_Succeeded_delayed_connect_000677d0[23];
            local_810._0_2_ = (short)ram0x000677e8;
            _applog(7,&local_828,0);
          }
          goto LAB_00048d12;
        }
      }
LAB_00048c50:
      close(uVar3);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        local_828._0_1_ = s_Select_timeout_failed_connect_000677ec[0];
        local_828._1_1_ = s_Select_timeout_failed_connect_000677ec[1];
        local_828._2_1_ = s_Select_timeout_failed_connect_000677ec[2];
        local_828._3_1_ = s_Select_timeout_failed_connect_000677ec[3];
        uStack_824._0_1_ = s_Select_timeout_failed_connect_000677ec[4];
        uStack_824._1_1_ = s_Select_timeout_failed_connect_000677ec[5];
        uStack_824._2_1_ = s_Select_timeout_failed_connect_000677ec[6];
        uStack_824._3_1_ = s_Select_timeout_failed_connect_000677ec[7];
        uStack_820._0_1_ = s_Select_timeout_failed_connect_000677ec[8];
        uStack_820._1_1_ = s_Select_timeout_failed_connect_000677ec[9];
        uStack_820._2_1_ = s_Select_timeout_failed_connect_000677ec[10];
        uStack_820._3_1_ = s_Select_timeout_failed_connect_000677ec[11];
        uStack_81c._0_1_ = s_Select_timeout_failed_connect_000677ec[12];
        uStack_81c._1_1_ = s_Select_timeout_failed_connect_000677ec[13];
        uStack_81c._2_1_ = s_Select_timeout_failed_connect_000677ec[14];
        uStack_81c._3_1_ = s_Select_timeout_failed_connect_000677ec[15];
        puVar5 = &local_818;
        uVar3 = s_Select_timeout_failed_connect_000677ec._16_4_;
        uVar4 = s_Select_timeout_failed_connect_000677ec._20_4_;
        uVar13 = s_Select_timeout_failed_connect_000677ec._24_4_;
        uVar9 = ram0x00067808;
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
      local_828._0_1_ = s_Failed_sock_connect_000677bc[0];
      local_828._1_1_ = s_Failed_sock_connect_000677bc[1];
      local_828._2_1_ = s_Failed_sock_connect_000677bc[2];
      local_828._3_1_ = s_Failed_sock_connect_000677bc[3];
      uStack_824._0_1_ = s_Failed_sock_connect_000677bc[4];
      uStack_824._1_1_ = s_Failed_sock_connect_000677bc[5];
      uStack_824._2_1_ = s_Failed_sock_connect_000677bc[6];
      uStack_824._3_1_ = s_Failed_sock_connect_000677bc[7];
      uStack_820._0_1_ = s_Failed_sock_connect_000677bc[8];
      uStack_820._1_1_ = s_Failed_sock_connect_000677bc[9];
      uStack_820._2_1_ = s_Failed_sock_connect_000677bc[10];
      uStack_820._3_1_ = s_Failed_sock_connect_000677bc[11];
      uStack_81c._0_1_ = s_Failed_sock_connect_000677bc[12];
      uStack_81c._1_1_ = s_Failed_sock_connect_000677bc[13];
      uStack_81c._2_1_ = s_Failed_sock_connect_000677bc[14];
      uStack_81c._3_1_ = s_Failed_sock_connect_000677bc[15];
      local_818._0_1_ = s_Failed_sock_connect_000677bc[16];
      local_818._1_1_ = s_Failed_sock_connect_000677bc[17];
      local_818._2_1_ = s_Failed_sock_connect_000677bc[18];
      local_818._3_1_ = s_Failed_sock_connect_000677bc[19];
      _applog(7,&local_828,0);
      paVar1 = paVar1->ai_next;
    }
  } while( true );
}

