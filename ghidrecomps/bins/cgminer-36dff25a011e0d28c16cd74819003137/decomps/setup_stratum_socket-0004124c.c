
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
  
  _mutex_lock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xb9a);
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  _mutex_unlock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xb9f);
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
          tmp42[0] = s_Failed_socket_0009ff38[0];
          tmp42[1] = s_Failed_socket_0009ff38[1];
          tmp42[2] = s_Failed_socket_0009ff38[2];
          tmp42[3] = s_Failed_socket_0009ff38[3];
          tmp42[4] = s_Failed_socket_0009ff38[4];
          tmp42[5] = s_Failed_socket_0009ff38[5];
          tmp42[6] = s_Failed_socket_0009ff38[6];
          tmp42[7] = s_Failed_socket_0009ff38[7];
          tmp42[8] = s_Failed_socket_0009ff38[8];
          tmp42[9] = s_Failed_socket_0009ff38[9];
          tmp42[10] = s_Failed_socket_0009ff38[10];
          tmp42[11] = s_Failed_socket_0009ff38[11];
          tmp42[12] = (char)(short)ram0x0009ff44;
          tmp42[13] = (char)((ushort)(short)ram0x0009ff44 >> 8);
          _applog(7,tmp42,false);
        }
      }
      else {
        noblock_socket(sockd);
        iVar2 = connect(sockd,(sockaddr *)p->ai_addr,p->ai_addrlen);
        if (iVar2 != -1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            tmp42[0] = s_Succeeded_immediate_connect_0009ff98[0];
            tmp42[1] = s_Succeeded_immediate_connect_0009ff98[1];
            tmp42[2] = s_Succeeded_immediate_connect_0009ff98[2];
            tmp42[3] = s_Succeeded_immediate_connect_0009ff98[3];
            tmp42[4] = s_Succeeded_immediate_connect_0009ff98[4];
            tmp42[5] = s_Succeeded_immediate_connect_0009ff98[5];
            tmp42[6] = s_Succeeded_immediate_connect_0009ff98[6];
            tmp42[7] = s_Succeeded_immediate_connect_0009ff98[7];
            tmp42[8] = s_Succeeded_immediate_connect_0009ff98[8];
            tmp42[9] = s_Succeeded_immediate_connect_0009ff98[9];
            tmp42[10] = s_Succeeded_immediate_connect_0009ff98[10];
            tmp42[11] = s_Succeeded_immediate_connect_0009ff98[11];
            tmp42[12] = s_Succeeded_immediate_connect_0009ff98[12];
            tmp42[13] = s_Succeeded_immediate_connect_0009ff98[13];
            tmp42[14] = s_Succeeded_immediate_connect_0009ff98[14];
            tmp42[15] = s_Succeeded_immediate_connect_0009ff98[15];
            tmp42[16] = s_Succeeded_immediate_connect_0009ff98[16];
            tmp42[17] = s_Succeeded_immediate_connect_0009ff98[17];
            tmp42[18] = s_Succeeded_immediate_connect_0009ff98[18];
            tmp42[19] = s_Succeeded_immediate_connect_0009ff98[19];
            tmp42[20] = s_Succeeded_immediate_connect_0009ff98[20];
            tmp42[21] = s_Succeeded_immediate_connect_0009ff98[21];
            tmp42[22] = s_Succeeded_immediate_connect_0009ff98[22];
            tmp42[23] = s_Succeeded_immediate_connect_0009ff98[23];
            tmp42[24] = s_Succeeded_immediate_connect_0009ff98[24];
            tmp42[25] = s_Succeeded_immediate_connect_0009ff98[25];
            tmp42[26] = s_Succeeded_immediate_connect_0009ff98[26];
            tmp42[27] = s_Succeeded_immediate_connect_0009ff98[27];
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
                    tmp42[0] = s_Succeeded_delayed_connect_0009ff5c[0];
                    tmp42[1] = s_Succeeded_delayed_connect_0009ff5c[1];
                    tmp42[2] = s_Succeeded_delayed_connect_0009ff5c[2];
                    tmp42[3] = s_Succeeded_delayed_connect_0009ff5c[3];
                    tmp42[4] = s_Succeeded_delayed_connect_0009ff5c[4];
                    tmp42[5] = s_Succeeded_delayed_connect_0009ff5c[5];
                    tmp42[6] = s_Succeeded_delayed_connect_0009ff5c[6];
                    tmp42[7] = s_Succeeded_delayed_connect_0009ff5c[7];
                    tmp42[8] = s_Succeeded_delayed_connect_0009ff5c[8];
                    tmp42[9] = s_Succeeded_delayed_connect_0009ff5c[9];
                    tmp42[10] = s_Succeeded_delayed_connect_0009ff5c[10];
                    tmp42[11] = s_Succeeded_delayed_connect_0009ff5c[11];
                    tmp42[12] = s_Succeeded_delayed_connect_0009ff5c[12];
                    tmp42[13] = s_Succeeded_delayed_connect_0009ff5c[13];
                    tmp42[14] = s_Succeeded_delayed_connect_0009ff5c[14];
                    tmp42[15] = s_Succeeded_delayed_connect_0009ff5c[15];
                    tmp42[16] = s_Succeeded_delayed_connect_0009ff5c[16];
                    tmp42[17] = s_Succeeded_delayed_connect_0009ff5c[17];
                    tmp42[18] = s_Succeeded_delayed_connect_0009ff5c[18];
                    tmp42[19] = s_Succeeded_delayed_connect_0009ff5c[19];
                    tmp42[20] = s_Succeeded_delayed_connect_0009ff5c[20];
                    tmp42[21] = s_Succeeded_delayed_connect_0009ff5c[21];
                    tmp42[22] = s_Succeeded_delayed_connect_0009ff5c[22];
                    tmp42[23] = s_Succeeded_delayed_connect_0009ff5c[23];
                    tmp42[24] = (char)(short)ram0x0009ff74;
                    tmp42[25] = (char)((ushort)(short)ram0x0009ff74 >> 8);
                    _applog(7,tmp42,false);
                  }
                  block_socket(sockd);
                  goto LAB_00041a68;
                }
              }
            }
          } while ((selret < 0) && (_Var1 = interrupted(), _Var1));
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_Select_timeout_failed_connect_0009ff78[0];
            tmp42[1] = s_Select_timeout_failed_connect_0009ff78[1];
            tmp42[2] = s_Select_timeout_failed_connect_0009ff78[2];
            tmp42[3] = s_Select_timeout_failed_connect_0009ff78[3];
            tmp42[4] = s_Select_timeout_failed_connect_0009ff78[4];
            tmp42[5] = s_Select_timeout_failed_connect_0009ff78[5];
            tmp42[6] = s_Select_timeout_failed_connect_0009ff78[6];
            tmp42[7] = s_Select_timeout_failed_connect_0009ff78[7];
            tmp42[8] = s_Select_timeout_failed_connect_0009ff78[8];
            tmp42[9] = s_Select_timeout_failed_connect_0009ff78[9];
            tmp42[10] = s_Select_timeout_failed_connect_0009ff78[10];
            tmp42[11] = s_Select_timeout_failed_connect_0009ff78[11];
            tmp42[12] = s_Select_timeout_failed_connect_0009ff78[12];
            tmp42[13] = s_Select_timeout_failed_connect_0009ff78[13];
            tmp42[14] = s_Select_timeout_failed_connect_0009ff78[14];
            tmp42[15] = s_Select_timeout_failed_connect_0009ff78[15];
            tmp42[16] = s_Select_timeout_failed_connect_0009ff78[16];
            tmp42[17] = s_Select_timeout_failed_connect_0009ff78[17];
            tmp42[18] = s_Select_timeout_failed_connect_0009ff78[18];
            tmp42[19] = s_Select_timeout_failed_connect_0009ff78[19];
            tmp42[20] = s_Select_timeout_failed_connect_0009ff78[20];
            tmp42[21] = s_Select_timeout_failed_connect_0009ff78[21];
            tmp42[22] = s_Select_timeout_failed_connect_0009ff78[22];
            tmp42[23] = s_Select_timeout_failed_connect_0009ff78[23];
            tmp42[24] = s_Select_timeout_failed_connect_0009ff78[24];
            tmp42[25] = s_Select_timeout_failed_connect_0009ff78[25];
            tmp42[26] = s_Select_timeout_failed_connect_0009ff78[26];
            tmp42[27] = s_Select_timeout_failed_connect_0009ff78[27];
            tmp42._28_2_ = (undefined2)ram0x0009ff94;
            _applog(7,tmp42,false);
          }
        }
        else {
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            tmp42[0] = s_Failed_sock_connect_0009ff48[0];
            tmp42[1] = s_Failed_sock_connect_0009ff48[1];
            tmp42[2] = s_Failed_sock_connect_0009ff48[2];
            tmp42[3] = s_Failed_sock_connect_0009ff48[3];
            tmp42[4] = s_Failed_sock_connect_0009ff48[4];
            tmp42[5] = s_Failed_sock_connect_0009ff48[5];
            tmp42[6] = s_Failed_sock_connect_0009ff48[6];
            tmp42[7] = s_Failed_sock_connect_0009ff48[7];
            tmp42[8] = s_Failed_sock_connect_0009ff48[8];
            tmp42[9] = s_Failed_sock_connect_0009ff48[9];
            tmp42[10] = s_Failed_sock_connect_0009ff48[10];
            tmp42[11] = s_Failed_sock_connect_0009ff48[11];
            tmp42[12] = s_Failed_sock_connect_0009ff48[12];
            tmp42[13] = s_Failed_sock_connect_0009ff48[13];
            tmp42[14] = s_Failed_sock_connect_0009ff48[14];
            tmp42[15] = s_Failed_sock_connect_0009ff48[15];
            tmp42[16] = s_Failed_sock_connect_0009ff48[16];
            tmp42[17] = s_Failed_sock_connect_0009ff48[17];
            tmp42[18] = s_Failed_sock_connect_0009ff48[18];
            tmp42[19] = s_Failed_sock_connect_0009ff48[19];
            _applog(7,tmp42,false);
          }
        }
      }
    }
LAB_00041a68:
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
        pcVar3 = (char *)_cgcalloc(0x2000,1,"util.c","setup_stratum_socket",0xc28);
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

