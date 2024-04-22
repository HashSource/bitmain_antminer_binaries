
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool setup_stratum_socket(pool *pool)

{
  _Bool _Var1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
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
  
  _mutex_lock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xb9b);
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  _mutex_unlock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xba0);
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
          tmp42[0] = s_Failed_socket_00088964[0];
          tmp42[1] = s_Failed_socket_00088964[1];
          tmp42[2] = s_Failed_socket_00088964[2];
          tmp42[3] = s_Failed_socket_00088964[3];
          tmp42[4] = s_Failed_socket_00088964[4];
          tmp42[5] = s_Failed_socket_00088964[5];
          tmp42[6] = s_Failed_socket_00088964[6];
          tmp42[7] = s_Failed_socket_00088964[7];
          tmp42[8] = s_Failed_socket_00088964[8];
          tmp42[9] = s_Failed_socket_00088964[9];
          tmp42[10] = s_Failed_socket_00088964[10];
          tmp42[11] = s_Failed_socket_00088964[11];
          tmp42[12] = (char)(short)ram0x00088970;
          tmp42[13] = (char)((ushort)(short)ram0x00088970 >> 8);
          _applog(7,tmp42,false);
        }
      }
      else {
        noblock_socket(sockd);
        iVar2 = connect(sockd,(sockaddr *)p->ai_addr,p->ai_addrlen);
        if (iVar2 != -1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            tmp42[0] = s_Succeeded_immediate_connect_000889c4[0];
            tmp42[1] = s_Succeeded_immediate_connect_000889c4[1];
            tmp42[2] = s_Succeeded_immediate_connect_000889c4[2];
            tmp42[3] = s_Succeeded_immediate_connect_000889c4[3];
            tmp42[4] = s_Succeeded_immediate_connect_000889c4[4];
            tmp42[5] = s_Succeeded_immediate_connect_000889c4[5];
            tmp42[6] = s_Succeeded_immediate_connect_000889c4[6];
            tmp42[7] = s_Succeeded_immediate_connect_000889c4[7];
            tmp42[8] = s_Succeeded_immediate_connect_000889c4[8];
            tmp42[9] = s_Succeeded_immediate_connect_000889c4[9];
            tmp42[10] = s_Succeeded_immediate_connect_000889c4[10];
            tmp42[11] = s_Succeeded_immediate_connect_000889c4[11];
            tmp42[12] = s_Succeeded_immediate_connect_000889c4[12];
            tmp42[13] = s_Succeeded_immediate_connect_000889c4[13];
            tmp42[14] = s_Succeeded_immediate_connect_000889c4[14];
            tmp42[15] = s_Succeeded_immediate_connect_000889c4[15];
            tmp42[16] = s_Succeeded_immediate_connect_000889c4[16];
            tmp42[17] = s_Succeeded_immediate_connect_000889c4[17];
            tmp42[18] = s_Succeeded_immediate_connect_000889c4[18];
            tmp42[19] = s_Succeeded_immediate_connect_000889c4[19];
            tmp42[20] = s_Succeeded_immediate_connect_000889c4[20];
            tmp42[21] = s_Succeeded_immediate_connect_000889c4[21];
            tmp42[22] = s_Succeeded_immediate_connect_000889c4[22];
            tmp42[23] = s_Succeeded_immediate_connect_000889c4[23];
            tmp42[24] = s_Succeeded_immediate_connect_000889c4[24];
            tmp42[25] = s_Succeeded_immediate_connect_000889c4[25];
            tmp42[26] = s_Succeeded_immediate_connect_000889c4[26];
            tmp42[27] = s_Succeeded_immediate_connect_000889c4[27];
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
            iVar2 = sockd + 0x1f;
            if (-1 < sockd) {
              iVar2 = sockd;
            }
            uVar4 = sockd & 0x1f;
            if (sockd < 1) {
              uVar4 = -(-sockd & 0x1fU);
            }
            rw.fds_bits[iVar2 >> 5] = rw.fds_bits[iVar2 >> 5] | 1 << (uVar4 & 0xff);
            selret = select(sockd + 1,(fd_set *)0x0,(fd_set *)&rw,(fd_set *)0x0,
                            (timeval *)&tv_timeout);
            if (0 < selret) {
              iVar2 = sockd + 0x1f;
              if (-1 < sockd) {
                iVar2 = sockd;
              }
              uVar4 = sockd & 0x1f;
              if (sockd < 1) {
                uVar4 = -(-sockd & 0x1fU);
              }
              if ((1 << (uVar4 & 0xff) & rw.fds_bits[iVar2 >> 5]) != 0) {
                len = 4;
                n = getsockopt(sockd,1,4,&err,&len);
                if ((n == 0) && (err == 0)) {
                  if ((opt_debug != false) &&
                     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level))))
                  {
                    tmp42[0] = s_Succeeded_delayed_connect_00088988[0];
                    tmp42[1] = s_Succeeded_delayed_connect_00088988[1];
                    tmp42[2] = s_Succeeded_delayed_connect_00088988[2];
                    tmp42[3] = s_Succeeded_delayed_connect_00088988[3];
                    tmp42[4] = s_Succeeded_delayed_connect_00088988[4];
                    tmp42[5] = s_Succeeded_delayed_connect_00088988[5];
                    tmp42[6] = s_Succeeded_delayed_connect_00088988[6];
                    tmp42[7] = s_Succeeded_delayed_connect_00088988[7];
                    tmp42[8] = s_Succeeded_delayed_connect_00088988[8];
                    tmp42[9] = s_Succeeded_delayed_connect_00088988[9];
                    tmp42[10] = s_Succeeded_delayed_connect_00088988[10];
                    tmp42[11] = s_Succeeded_delayed_connect_00088988[11];
                    tmp42[12] = s_Succeeded_delayed_connect_00088988[12];
                    tmp42[13] = s_Succeeded_delayed_connect_00088988[13];
                    tmp42[14] = s_Succeeded_delayed_connect_00088988[14];
                    tmp42[15] = s_Succeeded_delayed_connect_00088988[15];
                    tmp42[16] = s_Succeeded_delayed_connect_00088988[16];
                    tmp42[17] = s_Succeeded_delayed_connect_00088988[17];
                    tmp42[18] = s_Succeeded_delayed_connect_00088988[18];
                    tmp42[19] = s_Succeeded_delayed_connect_00088988[19];
                    tmp42[20] = s_Succeeded_delayed_connect_00088988[20];
                    tmp42[21] = s_Succeeded_delayed_connect_00088988[21];
                    tmp42[22] = s_Succeeded_delayed_connect_00088988[22];
                    tmp42[23] = s_Succeeded_delayed_connect_00088988[23];
                    tmp42[24] = (char)(short)ram0x000889a0;
                    tmp42[25] = (char)((ushort)(short)ram0x000889a0 >> 8);
                    _applog(7,tmp42,false);
                  }
                  block_socket(sockd);
                  goto LAB_00043baa;
                }
              }
            }
          } while ((selret < 0) && (_Var1 = interrupted(), _Var1));
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_Select_timeout_failed_connect_000889a4[0];
            tmp42[1] = s_Select_timeout_failed_connect_000889a4[1];
            tmp42[2] = s_Select_timeout_failed_connect_000889a4[2];
            tmp42[3] = s_Select_timeout_failed_connect_000889a4[3];
            tmp42[4] = s_Select_timeout_failed_connect_000889a4[4];
            tmp42[5] = s_Select_timeout_failed_connect_000889a4[5];
            tmp42[6] = s_Select_timeout_failed_connect_000889a4[6];
            tmp42[7] = s_Select_timeout_failed_connect_000889a4[7];
            tmp42[8] = s_Select_timeout_failed_connect_000889a4[8];
            tmp42[9] = s_Select_timeout_failed_connect_000889a4[9];
            tmp42[10] = s_Select_timeout_failed_connect_000889a4[10];
            tmp42[11] = s_Select_timeout_failed_connect_000889a4[11];
            tmp42[12] = s_Select_timeout_failed_connect_000889a4[12];
            tmp42[13] = s_Select_timeout_failed_connect_000889a4[13];
            tmp42[14] = s_Select_timeout_failed_connect_000889a4[14];
            tmp42[15] = s_Select_timeout_failed_connect_000889a4[15];
            tmp42[16] = s_Select_timeout_failed_connect_000889a4[16];
            tmp42[17] = s_Select_timeout_failed_connect_000889a4[17];
            tmp42[18] = s_Select_timeout_failed_connect_000889a4[18];
            tmp42[19] = s_Select_timeout_failed_connect_000889a4[19];
            tmp42[20] = s_Select_timeout_failed_connect_000889a4[20];
            tmp42[21] = s_Select_timeout_failed_connect_000889a4[21];
            tmp42[22] = s_Select_timeout_failed_connect_000889a4[22];
            tmp42[23] = s_Select_timeout_failed_connect_000889a4[23];
            tmp42[24] = s_Select_timeout_failed_connect_000889a4[24];
            tmp42[25] = s_Select_timeout_failed_connect_000889a4[25];
            tmp42[26] = s_Select_timeout_failed_connect_000889a4[26];
            tmp42[27] = s_Select_timeout_failed_connect_000889a4[27];
            tmp42._28_2_ = (undefined2)ram0x000889c0;
            _applog(7,tmp42,false);
          }
        }
        else {
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_Failed_sock_connect_00088974[0];
            tmp42[1] = s_Failed_sock_connect_00088974[1];
            tmp42[2] = s_Failed_sock_connect_00088974[2];
            tmp42[3] = s_Failed_sock_connect_00088974[3];
            tmp42[4] = s_Failed_sock_connect_00088974[4];
            tmp42[5] = s_Failed_sock_connect_00088974[5];
            tmp42[6] = s_Failed_sock_connect_00088974[6];
            tmp42[7] = s_Failed_sock_connect_00088974[7];
            tmp42[8] = s_Failed_sock_connect_00088974[8];
            tmp42[9] = s_Failed_sock_connect_00088974[9];
            tmp42[10] = s_Failed_sock_connect_00088974[10];
            tmp42[11] = s_Failed_sock_connect_00088974[11];
            tmp42[12] = s_Failed_sock_connect_00088974[12];
            tmp42[13] = s_Failed_sock_connect_00088974[13];
            tmp42[14] = s_Failed_sock_connect_00088974[14];
            tmp42[15] = s_Failed_sock_connect_00088974[15];
            tmp42[16] = s_Failed_sock_connect_00088974[16];
            tmp42[17] = s_Failed_sock_connect_00088974[17];
            tmp42[18] = s_Failed_sock_connect_00088974[18];
            tmp42[19] = s_Failed_sock_connect_00088974[19];
            _applog(7,tmp42,false);
          }
        }
      }
    }
LAB_00043baa:
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
        pcVar3 = (char *)_cgcalloc(0x2000,1,"util.c","setup_stratum_socket",0xc29);
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

