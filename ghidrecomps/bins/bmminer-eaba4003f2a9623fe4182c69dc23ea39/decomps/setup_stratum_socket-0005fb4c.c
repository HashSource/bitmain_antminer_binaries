
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool setup_stratum_socket(pool *pool)

{
  _Bool _Var1;
  int iVar2;
  char *pcVar3;
  pool *pool_local;
  fd_set rw;
  char tmp42 [2048];
  int err;
  socklen_t len;
  timeval tv_timeout;
  addrinfo hints;
  addrinfo *servinfo;
  int n;
  int selret;
  fd_set *__arr;
  uint __i;
  int sockd;
  char *sockaddr_port;
  char *sockaddr_url;
  addrinfo *p;
  
  _mutex_lock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xae1);
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  _mutex_unlock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xae6);
  memset(&hints,0,0x20);
  hints.ai_family = 0;
  hints.ai_socktype = 1;
  if ((pool->rpc_proxy == (char *)0x0) && (opt_socks_proxy != (char *)0x0)) {
    pool->rpc_proxy = opt_socks_proxy;
    extract_sockaddr(pool->rpc_proxy,&pool->sockaddr_proxy_url,&pool->sockaddr_proxy_port);
    pool->rpc_proxytype = 3;
  }
  if (pool->rpc_proxy == (char *)0x0) {
    sockaddr_url = pool->sockaddr_url;
    sockaddr_port = pool->stratum_port;
  }
  else {
    sockaddr_url = pool->sockaddr_proxy_url;
    sockaddr_port = pool->sockaddr_proxy_port;
  }
  iVar2 = getaddrinfo(sockaddr_url,sockaddr_port,(addrinfo *)&hints,(addrinfo **)&servinfo);
  if (iVar2 == 0) {
    for (p = servinfo; p != (addrinfo *)0x0; p = p->ai_next) {
      sockd = socket(p->ai_family,p->ai_socktype,p->ai_protocol);
      if (sockd == -1) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Failed_socket_0007bd14[0];
          tmp42[1] = s_Failed_socket_0007bd14[1];
          tmp42[2] = s_Failed_socket_0007bd14[2];
          tmp42[3] = s_Failed_socket_0007bd14[3];
          tmp42[4] = s_Failed_socket_0007bd14[4];
          tmp42[5] = s_Failed_socket_0007bd14[5];
          tmp42[6] = s_Failed_socket_0007bd14[6];
          tmp42[7] = s_Failed_socket_0007bd14[7];
          tmp42[8] = s_Failed_socket_0007bd14[8];
          tmp42[9] = s_Failed_socket_0007bd14[9];
          tmp42[10] = s_Failed_socket_0007bd14[10];
          tmp42[11] = s_Failed_socket_0007bd14[11];
          tmp42[12] = (char)(short)ram0x0007bd20;
          tmp42[13] = (char)((ushort)(short)ram0x0007bd20 >> 8);
          _applog(7,tmp42,false);
        }
      }
      else {
        noblock_socket(sockd);
        iVar2 = connect(sockd,(sockaddr *)p->ai_addr,p->ai_addrlen);
        if (iVar2 != -1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            tmp42[0] = s_Succeeded_immediate_connect_0007bd74[0];
            tmp42[1] = s_Succeeded_immediate_connect_0007bd74[1];
            tmp42[2] = s_Succeeded_immediate_connect_0007bd74[2];
            tmp42[3] = s_Succeeded_immediate_connect_0007bd74[3];
            tmp42[4] = s_Succeeded_immediate_connect_0007bd74[4];
            tmp42[5] = s_Succeeded_immediate_connect_0007bd74[5];
            tmp42[6] = s_Succeeded_immediate_connect_0007bd74[6];
            tmp42[7] = s_Succeeded_immediate_connect_0007bd74[7];
            tmp42[8] = s_Succeeded_immediate_connect_0007bd74[8];
            tmp42[9] = s_Succeeded_immediate_connect_0007bd74[9];
            tmp42[10] = s_Succeeded_immediate_connect_0007bd74[10];
            tmp42[11] = s_Succeeded_immediate_connect_0007bd74[11];
            tmp42[12] = s_Succeeded_immediate_connect_0007bd74[12];
            tmp42[13] = s_Succeeded_immediate_connect_0007bd74[13];
            tmp42[14] = s_Succeeded_immediate_connect_0007bd74[14];
            tmp42[15] = s_Succeeded_immediate_connect_0007bd74[15];
            tmp42[16] = s_Succeeded_immediate_connect_0007bd74[16];
            tmp42[17] = s_Succeeded_immediate_connect_0007bd74[17];
            tmp42[18] = s_Succeeded_immediate_connect_0007bd74[18];
            tmp42[19] = s_Succeeded_immediate_connect_0007bd74[19];
            tmp42[20] = s_Succeeded_immediate_connect_0007bd74[20];
            tmp42[21] = s_Succeeded_immediate_connect_0007bd74[21];
            tmp42[22] = s_Succeeded_immediate_connect_0007bd74[22];
            tmp42[23] = s_Succeeded_immediate_connect_0007bd74[23];
            tmp42[24] = s_Succeeded_immediate_connect_0007bd74[24];
            tmp42[25] = s_Succeeded_immediate_connect_0007bd74[25];
            tmp42[26] = s_Succeeded_immediate_connect_0007bd74[26];
            tmp42[27] = s_Succeeded_immediate_connect_0007bd74[27];
            _applog(4,tmp42,false);
          }
          block_socket(sockd);
          break;
        }
        tv_timeout.tv_sec = 1;
        tv_timeout.tv_usec = 0;
        _Var1 = sock_connecting();
        if (_Var1) {
          do {
            __arr = &rw;
            for (__i = 0; __i < 0x20; __i = __i + 1) {
              rw.fds_bits[__i] = 0;
            }
            iVar2 = sockd;
            if (sockd < 0) {
              iVar2 = sockd + 0x1f;
            }
            rw.fds_bits[iVar2 >> 5] = rw.fds_bits[iVar2 >> 5] | 1 << (sockd % 0x20 & 0xffU);
            selret = select(sockd + 1,(fd_set *)0x0,(fd_set *)&rw,(fd_set *)0x0,
                            (timeval *)&tv_timeout);
            if (0 < selret) {
              iVar2 = sockd;
              if (sockd < 0) {
                iVar2 = sockd + 0x1f;
              }
              if ((rw.fds_bits[iVar2 >> 5] >> (sockd % 0x20 & 0xffU) & 1U) != 0) {
                len = 4;
                n = getsockopt(sockd,1,4,&err,&len);
                if ((n == 0) && (err == 0)) {
                  if ((opt_debug != false) &&
                     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level))))
                  {
                    tmp42[0] = s_Succeeded_delayed_connect_0007bd38[0];
                    tmp42[1] = s_Succeeded_delayed_connect_0007bd38[1];
                    tmp42[2] = s_Succeeded_delayed_connect_0007bd38[2];
                    tmp42[3] = s_Succeeded_delayed_connect_0007bd38[3];
                    tmp42[4] = s_Succeeded_delayed_connect_0007bd38[4];
                    tmp42[5] = s_Succeeded_delayed_connect_0007bd38[5];
                    tmp42[6] = s_Succeeded_delayed_connect_0007bd38[6];
                    tmp42[7] = s_Succeeded_delayed_connect_0007bd38[7];
                    tmp42[8] = s_Succeeded_delayed_connect_0007bd38[8];
                    tmp42[9] = s_Succeeded_delayed_connect_0007bd38[9];
                    tmp42[10] = s_Succeeded_delayed_connect_0007bd38[10];
                    tmp42[11] = s_Succeeded_delayed_connect_0007bd38[11];
                    tmp42[12] = s_Succeeded_delayed_connect_0007bd38[12];
                    tmp42[13] = s_Succeeded_delayed_connect_0007bd38[13];
                    tmp42[14] = s_Succeeded_delayed_connect_0007bd38[14];
                    tmp42[15] = s_Succeeded_delayed_connect_0007bd38[15];
                    tmp42[16] = s_Succeeded_delayed_connect_0007bd38[16];
                    tmp42[17] = s_Succeeded_delayed_connect_0007bd38[17];
                    tmp42[18] = s_Succeeded_delayed_connect_0007bd38[18];
                    tmp42[19] = s_Succeeded_delayed_connect_0007bd38[19];
                    tmp42[20] = s_Succeeded_delayed_connect_0007bd38[20];
                    tmp42[21] = s_Succeeded_delayed_connect_0007bd38[21];
                    tmp42[22] = s_Succeeded_delayed_connect_0007bd38[22];
                    tmp42[23] = s_Succeeded_delayed_connect_0007bd38[23];
                    tmp42[24] = (char)(short)ram0x0007bd50;
                    tmp42[25] = (char)((ushort)(short)ram0x0007bd50 >> 8);
                    _applog(7,tmp42,false);
                  }
                  block_socket(sockd);
                  goto LAB_0006010c;
                }
              }
            }
          } while ((selret < 0) && (_Var1 = interrupted(), _Var1));
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_Select_timeout_failed_connect_0007bd54[0];
            tmp42[1] = s_Select_timeout_failed_connect_0007bd54[1];
            tmp42[2] = s_Select_timeout_failed_connect_0007bd54[2];
            tmp42[3] = s_Select_timeout_failed_connect_0007bd54[3];
            tmp42[4] = s_Select_timeout_failed_connect_0007bd54[4];
            tmp42[5] = s_Select_timeout_failed_connect_0007bd54[5];
            tmp42[6] = s_Select_timeout_failed_connect_0007bd54[6];
            tmp42[7] = s_Select_timeout_failed_connect_0007bd54[7];
            tmp42[8] = s_Select_timeout_failed_connect_0007bd54[8];
            tmp42[9] = s_Select_timeout_failed_connect_0007bd54[9];
            tmp42[10] = s_Select_timeout_failed_connect_0007bd54[10];
            tmp42[11] = s_Select_timeout_failed_connect_0007bd54[11];
            tmp42[12] = s_Select_timeout_failed_connect_0007bd54[12];
            tmp42[13] = s_Select_timeout_failed_connect_0007bd54[13];
            tmp42[14] = s_Select_timeout_failed_connect_0007bd54[14];
            tmp42[15] = s_Select_timeout_failed_connect_0007bd54[15];
            tmp42[16] = s_Select_timeout_failed_connect_0007bd54[16];
            tmp42[17] = s_Select_timeout_failed_connect_0007bd54[17];
            tmp42[18] = s_Select_timeout_failed_connect_0007bd54[18];
            tmp42[19] = s_Select_timeout_failed_connect_0007bd54[19];
            tmp42[20] = s_Select_timeout_failed_connect_0007bd54[20];
            tmp42[21] = s_Select_timeout_failed_connect_0007bd54[21];
            tmp42[22] = s_Select_timeout_failed_connect_0007bd54[22];
            tmp42[23] = s_Select_timeout_failed_connect_0007bd54[23];
            tmp42[24] = s_Select_timeout_failed_connect_0007bd54[24];
            tmp42[25] = s_Select_timeout_failed_connect_0007bd54[25];
            tmp42[26] = s_Select_timeout_failed_connect_0007bd54[26];
            tmp42[27] = s_Select_timeout_failed_connect_0007bd54[27];
            tmp42._28_2_ = (undefined2)ram0x0007bd70;
            _applog(7,tmp42,false);
          }
        }
        else {
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_Failed_sock_connect_0007bd24[0];
            tmp42[1] = s_Failed_sock_connect_0007bd24[1];
            tmp42[2] = s_Failed_sock_connect_0007bd24[2];
            tmp42[3] = s_Failed_sock_connect_0007bd24[3];
            tmp42[4] = s_Failed_sock_connect_0007bd24[4];
            tmp42[5] = s_Failed_sock_connect_0007bd24[5];
            tmp42[6] = s_Failed_sock_connect_0007bd24[6];
            tmp42[7] = s_Failed_sock_connect_0007bd24[7];
            tmp42[8] = s_Failed_sock_connect_0007bd24[8];
            tmp42[9] = s_Failed_sock_connect_0007bd24[9];
            tmp42[10] = s_Failed_sock_connect_0007bd24[10];
            tmp42[11] = s_Failed_sock_connect_0007bd24[11];
            tmp42[12] = s_Failed_sock_connect_0007bd24[12];
            tmp42[13] = s_Failed_sock_connect_0007bd24[13];
            tmp42[14] = s_Failed_sock_connect_0007bd24[14];
            tmp42[15] = s_Failed_sock_connect_0007bd24[15];
            tmp42[16] = s_Failed_sock_connect_0007bd24[16];
            tmp42[17] = s_Failed_sock_connect_0007bd24[17];
            tmp42[18] = s_Failed_sock_connect_0007bd24[18];
            tmp42[19] = s_Failed_sock_connect_0007bd24[19];
            _applog(7,tmp42,false);
          }
        }
      }
    }
LAB_0006010c:
    if (p == (addrinfo *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"Failed to connect to stratum on %s:%s",sockaddr_url,sockaddr_port);
        _applog(6,tmp42,false);
      }
      freeaddrinfo((addrinfo *)servinfo);
      _Var1 = false;
    }
    else {
      freeaddrinfo((addrinfo *)servinfo);
      if (pool->rpc_proxy != (char *)0x0) {
        switch(pool->rpc_proxytype) {
        case 0:
          _Var1 = http_negotiate(pool,sockd,false);
          if (!_Var1) {
            return false;
          }
          break;
        case 1:
          _Var1 = http_negotiate(pool,sockd,true);
          if (!_Var1) {
            return false;
          }
          break;
        case 2:
          _Var1 = socks4_negotiate(pool,sockd,false);
          if (!_Var1) {
            return false;
          }
          break;
        case 3:
        case 5:
          _Var1 = socks5_negotiate(pool,sockd);
          if (!_Var1) {
            return false;
          }
          break;
        case 4:
          _Var1 = socks4_negotiate(pool,sockd,true);
          if (!_Var1) {
            return false;
          }
          break;
        default:
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Unsupported proxy type for %s:%s",pool->sockaddr_proxy_url,
                     pool->sockaddr_proxy_port);
            _applog(4,tmp42,false);
          }
          return false;
        }
      }
      if (pool->sockbuf == (char *)0x0) {
        pcVar3 = (char *)_cgcalloc(0x2000,1,"util.c","setup_stratum_socket",0xb6f);
        pool->sockbuf = pcVar3;
        pool->sockbuf_size = 0x2000;
      }
      pool->sock = sockd;
      keep_sockalive(sockd);
      _Var1 = true;
    }
  }
  else {
    if (pool->probed == true) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"Failed to getaddrinfo for %s:%s",sockaddr_url,sockaddr_port);
        _applog(6,tmp42,false);
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Failed to resolve (?wrong URL) %s:%s",sockaddr_url,sockaddr_port);
        _applog(4,tmp42,false);
      }
      pool->probed = true;
    }
    _Var1 = false;
  }
  return _Var1;
}

